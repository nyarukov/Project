import os
from tkinter import Tk, Label, Entry, Button, filedialog


def generate_directory_docs(folder_path):
    markdown_content = "```plaintext\n"
    for root, dirs, files in os.walk(folder_path):
        level = root.replace(folder_path, "").count(os.sep)
        indent = "│   " * (level - 1)
        if level > 0:
            markdown_content += f"{indent}├─{os.path.basename(root)}\n"
        subindent = "│   " * level
        for file in files:
            file_path = os.path.join(root, file)
            description = extract_description(file_path)
            markdown_content += f"{subindent}│   │   {file}  // {description}\n"
    markdown_content += "```"
    return markdown_content

def extract_description(file_path):
    description = ""
    try:
        with open(file_path, 'r', encoding='gb2312', errors='ignore') as file:  # 添加 errors='ignore'
            for line in file:
                if '描述:' in line:
                    # 处理中文描述，忽略无法解码的字符
                    description = line.strip().split(':')[-1].strip().encode('gb2312', 'ignore').decode('gb2312')
                    break
    except FileNotFoundError:
        print(f"文件 '{file_path}' 不存在！")
    return description



def select_input_folder():
    folder_path = filedialog.askdirectory()
    entry_folder.delete(0, 'end')
    entry_folder.insert(0, folder_path)

def select_output_folder():
    output_folder = filedialog.askdirectory()
    entry_output_folder.delete(0, 'end')
    entry_output_folder.insert(0, output_folder)

def generate_docs():
    folder_path = entry_folder.get()
    markdown_content = generate_directory_docs(folder_path)
    output_folder = entry_output_folder.get()
    output_file = os.path.join(output_folder, "directory_docs.md")
    with open(output_file, 'w', encoding='utf-8') as f:
        f.write(markdown_content)
    root.quit()

# 创建 Tkinter 窗口
root = Tk()
root.title("生成目录文档")

# 添加标签和输入框
Label(root, text="文件夹路径:").grid(row=0, column=0, sticky="w")
entry_folder = Entry(root, width=50)
entry_folder.grid(row=0, column=1)
Button(root, text="选择文件夹", command=select_input_folder).grid(row=0, column=2)

Label(root, text="输出目录路径:").grid(row=1, column=0, sticky="w")
entry_output_folder = Entry(root, width=50)
entry_output_folder.grid(row=1, column=1)
Button(root, text="选择输出目录", command=select_output_folder).grid(row=1, column=2)

# 添加确认生成按钮
Button(root, text="确认生成", command=generate_docs).grid(row=2, column=1)

# 运行窗口
root.mainloop()

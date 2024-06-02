import os
from tkinter import Tk, Label, Entry, Button, Text, filedialog
from datetime import datetime

folder_path = None

def create_files(filename, folder_path, Author, Version, description):
    if folder_path:
        # 创建头文件和对应的 C 文件
        headers = [filename + '.h', filename + '.c']

        now = datetime.now().strftime('%Y-%m-%d %H:%M:%S')

        for header in headers:
            # 创建文件并添加注释
            with open(os.path.join(folder_path, header), 'w') as file:
                file.write('/*\n')
                file.write(' * 项目名称: {}\n'.format(filename))
                file.write(' * 版本:{}\n'.format(Version))
                file.write(' * 作者: {}\n'.format(Author))
                file.write(' * 创建日期: {}\n'.format(now))
                file.write(' * 最后修改日期: {}\n'.format(now))
                file.write(' * 描述: {}\n'.format(description))
                file.write(' */\n\n')
                if header.endswith('.h'):
                    file.write('#ifndef __{}_H\n'.format(filename.upper().replace('.', '_')))  # 更改宏定义
                    file.write('#define __{}_H\n\n'.format(filename.upper().replace('.', '_')))  # 更改宏定义
                    file.write('// 头文件内容...\n\n')
                    file.write('#endif\n')
                else:
                    file.write('#include "{}"\n\n'.format(filename + '.h'))  # 在 .c 文件中包含对应的 .h 文件
                    file.write('// C 文件内容...\n')
    else:
        print("请选择文件夹！")

def on_submit(filename, description):
    global folder_path
    Author = "Yusaka"  # 设置默认作者
    Version = "1.0"  # 设置默认版本号
    create_files(filename, folder_path, Author, Version, description)

def choose_folder():
    global folder_path
    folder_path = filedialog.askdirectory(initialdir=os.getcwd())  # 设置默认的文件夹为当前目录
    label_folder.config(text=folder_path)  # 更新标签文本为用户选择的文件夹路径

# 创建 Tkinter 窗口
root = Tk()
root.title("创建项目文件")

# 添加标签和输入框
Label(root, text="请输入文件名（不含扩展名）：").pack()
entry_filename = Entry(root)
entry_filename.pack()

Label(root, text="请输入项目描述：").pack()
text_description = Text(root, height=5)
text_description.pack()

# 添加选择文件夹按钮和标签
Button(root, text="选择文件夹", command=choose_folder).pack()
label_folder = Label(root, text="选择文件夹路径将显示在这里")
label_folder.pack()

# 添加确认生成按钮
Button(root, text="确认生成", command=lambda: on_submit(entry_filename.get(), text_description.get("1.0", "end-1c"))).pack()

# 添加退出按钮
Button(root, text="退出", command=root.quit).pack()

# 运行窗口
root.mainloop()

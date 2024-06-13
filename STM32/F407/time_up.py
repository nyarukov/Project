# -*- coding: utf-8 -*-
import os
from datetime import datetime
from tkinter import Tk, filedialog

def update_last_modified_in_directory(directory):
    for root, _, files in os.walk(directory):
        for filename in files:
            try:
                filepath = os.path.join(root, filename)
                last_modified_timestamp = os.path.getmtime(filepath)
                last_modified_datetime = datetime.fromtimestamp(last_modified_timestamp)
                formatted_last_modified = last_modified_datetime.strftime('%Y-%m-%d %H:%M:%S')

                with open(filepath, 'r', encoding='gb2312') as file:
                    lines = file.readlines()

                modified = False
                for i, line in enumerate(lines):
                    if '最后修改日期:' in line:
                        lines[i] = ' * 最后修改日期: {}\n'.format(formatted_last_modified)
                        modified = True
                        break

                if modified:
                    with open(filepath, 'w', encoding='gb2312') as file:
                        file.writelines(lines)

                    print("文件 '{}' 的最后修改日期已更新为: {}".format(filepath, formatted_last_modified))
            except FileNotFoundError:
                print("文件 '{}' 不存在！".format(filepath))
            except UnicodeDecodeError:
                print("文件 '{}' 无法解码为 GB2312 编码！".format(filepath))

def choose_directory():
    root = Tk()
    root.withdraw()
    directory = filedialog.askdirectory()
    if directory:
        update_last_modified_in_directory(directory)
    root.destroy()

# 测试示例
choose_directory()

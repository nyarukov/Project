import os
from datetime import datetime

def create_project_structure(project_name, Author, Version):
    # 创建文件夹
    folders = ['docs', 'src', 
               'src/protocol','src/config', 'src/peripherals', 'src/drivers', 'src/utils',
               'libs/Stm32_lib','libs/assembly', 
               'tests', 'build', 'scripts', 'project',
               'project/keil', 'project/make', 'project/cmake', 'project/eide']
    
    for folder in folders:
        os.makedirs(os.path.join(project_name, folder), exist_ok=True)
    # 打印文件目录
    print("文件目录：")
    for root, dirs, files in os.walk(project_name):
        level = root.replace(project_name, "").count(os.sep)
        indent = " " * 4 * (level)
        print("{}{}/".format(indent, os.path.basename(root)))
        subindent = " " * 4 * (level + 1)
        for file in files:
            print("{}{}".format(subindent, file))

# 指定项目名称
project_name = "Project"  # 您可以将项目名称更改为您想要的名称
Author = "Yusaka"
Version = "1.0"

# 创建项目文件结构
create_project_structure(project_name, Author, Version)


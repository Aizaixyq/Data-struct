# 22年c(c++)语言数据结构实验

## 普通配置
- 使用vscode打开某次实验的文件夹 然后将config中的.vscode文件夹移动至要运行的某次实验文件夹下
 - 注：launch.json和tasks.json中的编译器路径需要修改成本机路径

## or 使用xmake构建系统构建：
1. 安装xmake：https://github.com/xmake-io/xmake
2. 在工程根目录下用终端输入xmake即可构建所有源文件，可运行文件会保存在out文件夹中
3. 再输入xmake run [可运行文件名]运行，或者找到.out文件夹运行里面文件即可
# cpp_dataStructure
思得学园的兼职工作，为报考情报科大学院的考生复习CS专业的数据结构与算法知识

使用方法:
2017/10/16更新:
各个知识点的函数不再被main.cpp调用,删除main和所有h文件,
array.cpp list.cpp等所有cpp文件都不依赖任何其他文件,可以单独编译并运行.
./tsukuba文件夹下时筑波历年考题的代码实现,也可以单独编译并运行

编译方法:
舍弃了makefile,直接用g++编译单个文件,为了方便,g++写入了we脚本,使用时:
./we file_name.cpp 即可编译+运行
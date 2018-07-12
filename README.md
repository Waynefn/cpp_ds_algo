# cpp_ds_algo

使用方法:
各个知识点的函数不再被main.cpp调用,删除main和所有h文件,
array.cpp list.cpp等所有cpp文件都不依赖任何其他文件,可以单独编译并运行.
各文件夹下历年考题的代码实现,也可以单独编译并运行

编译方法:
舍弃了makefile,直接用g++编译单个文件,为了方便,g++写入了we脚本,使用时:
./we file_name.cpp 即可编译+运行

Log：
utils.h中，DEBUG_LOG的宏定义取消注释后，会输出更多算法过程中的log信息
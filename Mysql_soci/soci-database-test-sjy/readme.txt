安装soci的库过程很简单，直接输入命令：

pacman -S mingw-w64-x86_64-soci

创建项目工程也非常简单，直接从chatGPT复制一段代码就可以，简要代码见main.cpp

主要配置头文件搜索路径的时候稍微有一点点麻烦，因为在头文件：

F:\msys2\mingw64\include\soci\mysql\soci-mysql.h

中，有一个代码是：

#include <mysql.h> // MySQL Client

但是编译器会提示找不到这个mysql.h的头文件。

查了一下，在msys2下面，实际上有这个头文件（有好几个地方）
比较靠谱的是这里：

F:\msys2\mingw64\include\mysql

但是这个是一个绝对路径，需要改成相对路径，好在Code::Blocks自带有宏可以实现这个：

于是就在搜索路径里面，填入如下内容：

$(TARGET_COMPILER_DIR)include\mysql

大功告成，试验了一下，没啥问题！

依赖关系看了一下，也很正常，见本文件夹的截图：soci-dependencies.png


/mingw64/include/mysql/mysql.h  这个文件是由libmariadbclient项目提供的，相当于模拟实现了mysql的函数接口

具体项目有哪些文件提供，可以看网页：
Package: mingw-w64-x86_64-libmariadbclient - MSYS2 Packages — https://packages.msys2.org/package/mingw-w64-x86_64-libmariadbclient

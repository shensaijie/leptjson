power by 叶劲峰（Milo Yip)

# json

我们要实现的 JSON 库，主要是完成 3 个需求：
>[!faq] JSON库目标
>把 JSON 文本解析为一个树状数据结构（parse）。
>
>提供接口访问该数据结构（access）。
>
>把数据结构转换成 JSON 文本（stringify）。

# 代码文件

1. leptjson.h：leptjson 的头文件（header file），含有对外的类型和 API 函数声明。
2. leptjson.c：leptjson 的实现文件（implementation file），含有内部的类型声明和函数实现。此文件会编译成库。
3. test.c：我们使用测试驱动开发（test driven development, TDD）。此文件包含测试程序，需要链接 leptjson 库。

# 使用CMake
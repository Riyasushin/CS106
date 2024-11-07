#ifndef MACROS_H
#define MACROS_H

class macros
{
public:
    macros();

    ///## include guard
    /// 防止多次引入后处理成两个报错
    #ifndef MyStruct_Included
    #define MyStruct_Included

    struct MyStruct {
        int a, b, c;
    };
    #endif
};

#endif // MACROS_H

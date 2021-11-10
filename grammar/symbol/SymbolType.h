#ifndef _SYMBOLTYPE_H_
#define _SYMBOLTYPE_H_

#include<string>

namespace SMB {
    static std::string symbol_str[] = {
        "none",
        "int",
        "ptr",
        "bool",
        "void",
        "literal",
        "func",
        "array",
        "struct"
    };

    enum SymbolType {
        none = 0,
        integer = 1,
        pointer = 2,
        boolean = 3,
        void_type = 4,
        literal = 5,
        function = 6,
        array = 7,
        struct_type = 8
    };
}
#endif
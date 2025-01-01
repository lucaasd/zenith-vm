#pragma once

namespace ZenithVM::Assembly {
    enum class Type {
        BYTE,
        SHORT,
        INT,
        LONG,
        FLOAT,
        DOUBLE,
        CHAR,
        BOOLEAN,
        POINTER,
        REFERENCE
    };

    enum class TypeSize {
        BYTE = 1,
        SHORT = 2,
        INT = 4,
        LONG = 8,
        FLOAT = 4,
        DOUBLE = 8,
        CHAR = 1,
        BOOLEAN = 1,
        POINTER = 8,
        REFERENCE = 8
    };
}
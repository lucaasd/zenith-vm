#pragma once

namespace ZenithVM::Assembly {

    enum class Instruction {
        ADD,
        SUB,
        MUL,
        DIV,
        MOV,
        GOTO,
        JMP,
        RET,
        PUSH,
        POP,
        NOP,
        INVOKE,
        WRITE
    };
}
#pragma once
#include "BytecodePart.hpp"
#include "Instruction.hpp"
#include <vector>

namespace ZenithVM::Assembly {

    struct Operation : private BytecodePart {
        Instruction instruction;
        std::vector<std::byte> operands;
        Operation(Instruction instruction, std::vector<std::byte> operands) : instruction(instruction), operands(operands) {}
    };
}
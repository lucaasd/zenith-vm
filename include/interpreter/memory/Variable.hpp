#pragma once
#include "assembly/Type.hpp"
#include <array>
#include <string>

using ZenithVM::Assembly::Type;

namespace ZenithVM::Memory {

    struct Variable {
        int index;
        std::array<std::byte, 8> value;
        Type type;
    };
}
#pragma once
#include <stack>

namespace ZenithVM::Interpreter::Runtime {

    class Frame {
      public:
        std::stack<std::byte> stack;
        int maxStackSize;
    };
}
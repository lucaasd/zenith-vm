#pragma once
#include "assembly/Code.hpp"
#include "events/EventEmitter.hpp"
#include "interpreter/runtime/Frame.hpp"
#include <memory>

using ZenithVM::Assembly::Code;
using ZenithVM::Assembly::Instruction;
using ZenithVM::Assembly::Operation;
using ZenithVM::Events::EventEmitter;
using ZenithVM::Interpreter::Runtime::Frame;

namespace ZenithVM::Interpreter {
    class VM {
      public:
        std::vector<Code> codes;
        VM(std::unique_ptr<std::stringstream> &&logStream);
        ~VM();
        void run(unsigned int program);
        void runCode(Code code);
        void loadCode(Code program);
        void execute(Operation operation);
        void stop();
        void log(std::string message);
        std::unique_ptr<std::stringstream> logStream;
        std::unique_ptr<EventEmitter> logEvents;

      private:
        Frame currentFrame;
        Frame mainFrame;
        int programCounter = 0;
    };

    static void push_multiple_bytes(std::stack<std::byte> &stack, std::vector<std::byte> bytes);
}
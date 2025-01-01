#include "interpreter/VM.hpp"
#include "assembly/Code.hpp"
#include <format>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <unistd.h>

using ZenithVM::Assembly::Code;
using ZenithVM::Events::EventEmitter;

namespace ZenithVM::Interpreter {

    void VM::run(unsigned int program) {
        log("Starting VM");
        runCode(codes[program]);
    }

    void VM::runCode(Code code) {
        programCounter = 0;
        while (programCounter < code.size()) {
            execute(code[programCounter]);
        }
    }

    void VM::loadCode(Code code) { codes.push_back(code); }

    void VM::execute(Operation operation) {
        if (operation.instruction == Instruction::PUSH) {
            push_multiple_bytes(currentFrame.stack, operation.operands);
            programCounter++;
        } else if (operation.instruction == Instruction::ADD) {
            std::byte value;
            for (auto byte : operation.operands) {
                value = static_cast<std::byte>(static_cast<uint8_t>(value) + static_cast<uint8_t>(byte));
            }
            currentFrame.stack.push(value);
            programCounter++;
        } else if (operation.instruction == Instruction::WRITE) {
            std::vector<u_int8_t> bytes;
            while (!currentFrame.stack.empty()) {
                bytes.push_back(static_cast<uint8_t>(currentFrame.stack.top()));
                currentFrame.stack.pop();
            }
            log(std::string(bytes.begin(), bytes.end()));
            programCounter++;
        }
    }

    void VM::stop() { log("Stopping VM"); }

    VM::VM(std::unique_ptr<std::stringstream> &&logStream) {
        this->logStream = std::move(logStream);
        this->logEvents = std::make_unique<EventEmitter>();
        this->currentFrame = Frame();
    }

    VM::~VM() {
        // This is where the magic ends
    }

    void VM::log(std::string message) {
        logStream->write(message.c_str(), message.size());
        logEvents->emit("log");
    }

    static void push_multiple_bytes(std::stack<std::byte> &stack, std::vector<std::byte> bytes) {
        for (auto &byte : bytes) {
            stack.push(byte);
        }
    }
}

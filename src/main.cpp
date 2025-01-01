#include "assembly/Operation.hpp"
#include "interpreter/VM.hpp"
#include <iostream>
#include <memory>
#include <sstream>

using ZenithVM::Assembly::Instruction;
using ZenithVM::Assembly::Operation;
using namespace ZenithVM::Interpreter;

std::vector<std::byte> stringToBytes(std::string str) {
    std::deque<std::byte> bytes;
    for (char c : str) {
        bytes.push_front(static_cast<std::byte>(c));
    }
    return std::vector<std::byte>(bytes.begin(), bytes.end());
}

void setupVM() {
    std::string message = "Hello World!";
    std::vector<std::byte> bytes = stringToBytes(message);

    auto program = std::vector<Operation>{
        {Instruction::PUSH, {bytes}},
        {Instruction::WRITE, {}},
    };

    std::unique_ptr<std::stringstream> logStream = std::make_unique<std::stringstream>();

    VM vm(std::move(logStream));

    auto logCallback = [&vm]() -> void {
        std::cout << vm.logStream->str() << std::endl;
        vm.logStream->str("");
        vm.logStream->clear();
    };

    vm.logEvents->on("log", logCallback);

    vm.loadCode(program);

    vm.run(0);
}

int main() {
    setupVM();
    return 0;
}
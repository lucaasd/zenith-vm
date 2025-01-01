#pragma once
#include <functional>
#include <string>

namespace ZenithVM::Events {
    struct EventHandleInfo {
        std::string event;
        std::function<void()> callback;
    };
}
#pragma once
#include "EventHandleInfo.hpp"
#include <functional>
#include <string>

namespace ZenithVM::Events {
    class EventEmitter {
      public:
        EventEmitter();
        virtual ~EventEmitter();

        virtual void on(std::string event, std::function<void()> callback);
        virtual void emit(std::string event);

      private:
        std::vector<EventHandleInfo> eventInfos;
    };

}
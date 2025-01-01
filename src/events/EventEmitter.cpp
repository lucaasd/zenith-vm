#include "events/EventEmitter.hpp"

namespace ZenithVM::Events {
    void EventEmitter::on(std::string event, std::function<void()> callback) { eventInfos.push_back(EventHandleInfo{event, callback}); }

    void EventEmitter::emit(std::string event) {
        for (auto &eventInfo : eventInfos) {
            if (eventInfo.event == event) {
                eventInfo.callback();
            }
        }
    }

    EventEmitter::EventEmitter() {}
    EventEmitter::~EventEmitter() {}
}
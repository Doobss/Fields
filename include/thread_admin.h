#pragma once
#include <iostream>
#include <thread>

namespace Thread_Admin_class {

class Thread_Admin {
  typedef std::thread *thread_type;

 public:
  thread_type thread;
  Thread_Admin() {
    thread = nullptr;
  }
  ~Thread_Admin() {
    if (thread != nullptr) {
      if (thread->joinable()) {
        thread->join();
        delete thread;
      }
    }
  };
  bool handle(thread_type new_thread) {
    if (thread == nullptr) {
      thread = new_thread;
      return true;
    }
    if (thread->joinable()) {
      thread->join();
      delete thread;
      thread = new_thread;
      return true;
    }
    return false;
  };

  thread_type request() {
    if (thread == nullptr) {
      return new std::thread;
    }
    if (thread->joinable()) {
      thread->join();
      delete thread;
      return new std::thread;
    }
    return nullptr;
  }

  Thread_Admin(Thread_Admin const &) = delete;
  Thread_Admin &operator=(Thread_Admin const &) = delete;
};

};  // namespace Thread_Admin_class
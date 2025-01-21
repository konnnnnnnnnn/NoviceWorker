#include "thread.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

Thread::Thread(ThreadCallBack &&cb) : 
_thread_id(0), 
_is_running(false), 
_cb(std::move(cb))  //注册一个函数
{
}

void Thread::start()
{
    int ret = pthread_create(&_thread_id, nullptr, threadFunc, this);
    if (ret)
    {
        fprintf(stderr, "Cannot create thread: %s\n", strerror(ret));
        return;
    }

    _is_running = true;
}

void Thread::stop()
{
    if (!_is_running)
        return;

    int ret = pthread_join(_thread_id, nullptr);
    if (ret)
    {
        fprintf(stderr, "pthread_join faulted! %s\n", strerror(ret));
        return;
    }
}

void *Thread::threadFunc(void *arg)
{
    Thread *pth = static_cast<Thread *>(arg);
    if (pth == nullptr)
        std::cout << "threadFunc(arg == nullptr)\n";
    pth->_cb();

    pthread_exit(nullptr);
}

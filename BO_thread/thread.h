#ifndef __THREAD_H__
#define __THREAD_H__

#include <pthread.h>
#include <functional>

using std::function;

class Thread
{
    using ThreadCallBack = function<void()>;

public:
    Thread(ThreadCallBack &&cb);
    ~Thread() {}

    void start();
    void stop();

private:
    static void *threadFunc(void *arg);

private:
    pthread_t _thread_id;
    bool _is_running;
    ThreadCallBack _cb;
};

#endif
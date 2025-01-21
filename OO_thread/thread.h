#ifndef __THREAD_H__
#define __THREAD_H__

#include <pthread.h>

class Thread
{
public:
    Thread();
    virtual ~Thread() {}

    void start();
    void stop();

private:
    static void* threadFunc(void* arg);
    virtual void run() = 0;
private:
    pthread_t _thread_id;
    bool _is_running;
};

#endif
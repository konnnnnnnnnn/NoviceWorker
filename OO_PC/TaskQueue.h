#ifndef __TASKQUEUE_H__
#define __TASHQUEUE_H__

#include <queue>
#include "MutexLock.h"
#include "Condition.h"

using std::queue;
using std::size_t;

class TaskQueue
{
public:
    TaskQueue(size_t queSize);
    ~TaskQueue() {};

    void push(const int value);
    int pop();
    bool isFull() const;
    bool isEmpty() const;

private:
    size_t _queSize;
    queue<int> _que;
    MutexLock _mutex;
    Condition _notFull;
    Condition _notEmpty;
};

class MutexLockGuard
{
public:
    MutexLockGuard(MutexLock &mutex) : _mutex(mutex) { _mutex.lock(); }
    ~MutexLockGuard() { _mutex.unlock(); }

private:
    MutexLock &_mutex;
};

#endif
#include "TaskQueue.h"

TaskQueue::TaskQueue(size_t queSize) : _queSize(queSize), _que(), _mutex(), _notFull(_mutex), _notEmpty(_mutex)
{
}

void TaskQueue::push(const int value)
{
    MutexLockGuard autoLock(_mutex);

    while (isFull())
    {
        _notFull.wait();
    }
    _que.push(value);
    _notEmpty.notify();
}

int TaskQueue::pop()
{
    int num = 0;
    {
        MutexLockGuard autoLock(_mutex);
        while (isEmpty())
        {
            _notEmpty.wait();
        }

        num = _que.front();
        _que.pop();
        _notFull.notify();

        // 块中代码运行完毕后自动调用 MutexLockGuard 析构函数解锁
    }

    return num;
}

bool TaskQueue::isFull() const
{
    return _queSize == _que.size();
}

bool TaskQueue::isEmpty() const
{
    return 0 == _queSize;
}

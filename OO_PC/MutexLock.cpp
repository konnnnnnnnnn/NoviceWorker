#include "MutexLock.h"
#include <stdio.h>

MutexLock::MutexLock()
{
    int ret = pthread_mutex_init(&_mutex, nullptr);
    if (ret)
    {
        perror("pthread_mutex_init error!\n");
        return;
    }
}

MutexLock::~MutexLock()
{
    int ret = pthread_mutex_destroy(&_mutex);
    if (ret)
    {
        perror("pthread_mutex_destroy error!\n");
        return;
    }
}

void MutexLock::lock()
{
    int ret = pthread_mutex_lock(&_mutex);
    if (ret)
    {
        perror("pthread_mutex_destroy lock!\n");
        return;
    }
}

void MutexLock::tryLock()
{
    int ret = pthread_mutex_trylock(&_mutex);
    if (ret)
    {
        perror("pthread_mutex_destroy trylock!\n");
        return;
    }
}

void MutexLock::unlock()
{
    int ret = pthread_mutex_unlock(&_mutex);
    if (ret)
    {
        perror("pthread_mutex_destroy unlock!\n");
        return;
    }
}

pthread_mutex_t *MutexLock::getMutexLockPtr()
{
    return &_mutex;
}

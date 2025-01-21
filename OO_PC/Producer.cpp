#include "Producer.h"
#include "TaskQueue.h"
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

Producer::Producer(TaskQueue &taskQue) : _taskQue(taskQue)
{
}

void Producer::run()
{
    // C++ 中 C 语言的函数都在一个匿名空间中
    // 加上 :: 作用域限定符表明这是 C 语言中的函数
    ::srand(::clock());
    int cnt = 20;
    while (--cnt)
    {
        int number = ::rand() % 100;
        _taskQue.push(number);
        sleep(1);
    }
}

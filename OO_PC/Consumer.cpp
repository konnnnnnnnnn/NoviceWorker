#include "Consumer.h"
#include "TaskQueue.h"
#include <stdlib.h>
#include <iostream>
#include <unistd.h>

Consumer::Consumer(TaskQueue &taskQue) : _taskQue(taskQue)
{
}

void Consumer::run()
{
    // C++ 中 C 语言的函数都在一个匿名空间中
    // 加上 :: 作用域限定符表明这是 C 语言中的函数
    int cnt = 20;
    while (--cnt)
    {
        int number = _taskQue.pop();
        std::cout << "Consumer number: " << number << std::endl;
        sleep(1);
    }
}

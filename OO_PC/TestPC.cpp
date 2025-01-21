#include <iostream>
#include "Producer.h"
#include "Consumer.h"
#include <memory>
#include "thread.h"
#include "TaskQueue.h"

using namespace std;

void test()
{
    TaskQueue taskQue(10);
    unique_ptr<Thread> pro(new Producer(taskQue));
    unique_ptr<Thread> con(new Consumer(taskQue));

    pro->start();
    con->start();

    pro->stop();
    con->stop();
}

int main()
{
    test();

    return 0;
}
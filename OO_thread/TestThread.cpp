#include <iostream>
#include "thread.h"

class MyThread : public Thread
{
    void run() override;
};

void MyThread::run()
{
    // do something......
    std::cout << "MyThread is running......\n";
}

int main()
{
    MyThread mth;
    mth.start();
    mth.stop();

    return 0;
}
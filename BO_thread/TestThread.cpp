#include <iostream>
#include "thread.h"
#include <memory>

using std::bind;
using std::string;
using std::unique_ptr;

class MyTack
{
public:
    void run(int x);
};

void MyTack::run(int x)
{
    // do something......
    std::cout << "MyTack is running......\nx = " << x << std::endl;
}

void test0()
{
    MyTack task;
    // using ThreadCallBack = function<void()>;
    // 本来应该传一个无参数无返回值的函数，但用上 bind 就可以传递有任意参数的函数了
    function<void()> f = bind(&MyTack::run, &task, 10);
    Thread mth(std::move(f));
    mth.start();
    mth.stop();
}

void test1()
{
    MyTack task;
    unique_ptr<Thread> up(new Thread(bind(&MyTack::run, &task, 20)));
    up->start();
    up->stop();
}

void test3(string &str)
{
    std::cout << str << std::endl;
}

void test2()
{
    string str = "\thello world";
    function<void()> f = bind(test3, str);
    unique_ptr<Thread> up(new Thread(std::move(f)));
    up->start();
    up->stop();
}

int main()
{
    test0();
    test1();
    test2();

    return 0;
}

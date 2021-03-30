
#include <iostream>
/*
默认情况下，对于一个值被拷贝的变量，lambda不会改变其值，
如果我们希望能改变一个被捕获变量的值，就必须在参数列表尾加上关键字mutable.
*/
int main()
{
  int x = 0; int y = 42;
  auto qqq = [x, &y]()mutable{
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    //x按值传递，副本改变但原始值不变:x=0;y按引用传递，改变原始值:y=43
    ++y; ++x;
  };
  qqq();
  auto qqq1 = [=]()mutable {
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    //x、y等按值传递，副本改变但原始值不变:x=0,y=43
    ++y; ++x;
  };
  qqq1();
  auto qqq2 = [&] {

    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    //x、y等按引用传递，原始值改变，x=1，y=44
    ++y; ++x;
  };
  qqq2();
  auto qqq3 = [&, x]()mutable {
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    //y等按引用传递，原始值改变，y=45;x按值传递，副本改变但原始值不变，x=1;
    ++y; ++x;
  };
  qqq3();
  auto qqq4 = [=, &x]()mutable {
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    //x按引用传递，原始值改变，x=2;//y等按值传递，副本改变但原始值不变，y=45
    ++y; ++x;
  };
  qqq4();
  auto qqq5 = [=, &x]() mutable {  // qqq5 = [=, &x] () mutable
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    //x按引用传递，原始值改变，x=3;y等按值传递，副本改变但原始值不变，y=45
    ++y;  ++x;
  };
  qqq5();
  std::cout << "x: " << x << std::endl;
  std::cout << "y: " << y << std::endl;
}

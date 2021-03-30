
#include <iostream>
/*
Ĭ������£�����һ��ֵ�������ı�����lambda����ı���ֵ��
�������ϣ���ܸı�һ�������������ֵ���ͱ����ڲ����б�β���Ϲؼ���mutable.
*/
int main()
{
  int x = 0; int y = 42;
  auto qqq = [x, &y]()mutable{
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    //x��ֵ���ݣ������ı䵫ԭʼֵ����:x=0;y�����ô��ݣ��ı�ԭʼֵ:y=43
    ++y; ++x;
  };
  qqq();
  auto qqq1 = [=]()mutable {
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    //x��y�Ȱ�ֵ���ݣ������ı䵫ԭʼֵ����:x=0,y=43
    ++y; ++x;
  };
  qqq1();
  auto qqq2 = [&] {

    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    //x��y�Ȱ����ô��ݣ�ԭʼֵ�ı䣬x=1��y=44
    ++y; ++x;
  };
  qqq2();
  auto qqq3 = [&, x]()mutable {
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    //y�Ȱ����ô��ݣ�ԭʼֵ�ı䣬y=45;x��ֵ���ݣ������ı䵫ԭʼֵ���䣬x=1;
    ++y; ++x;
  };
  qqq3();
  auto qqq4 = [=, &x]()mutable {
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    //x�����ô��ݣ�ԭʼֵ�ı䣬x=2;//y�Ȱ�ֵ���ݣ������ı䵫ԭʼֵ���䣬y=45
    ++y; ++x;
  };
  qqq4();
  auto qqq5 = [=, &x]() mutable {  // qqq5 = [=, &x] () mutable
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    //x�����ô��ݣ�ԭʼֵ�ı䣬x=3;y�Ȱ�ֵ���ݣ������ı䵫ԭʼֵ���䣬y=45
    ++y;  ++x;
  };
  qqq5();
  std::cout << "x: " << x << std::endl;
  std::cout << "y: " << y << std::endl;
}

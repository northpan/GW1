#include<iostream>
/*
三阶函数:计算三个数的平均数
*/
using namespace std;

auto num1 = 1.0;
auto num2 = 2.0;
auto num3 = 4.3;


auto AddThree = [=]() {
    auto sum = num1+num2+num3;
    return [sum](auto aveCompu){
        aveCompu(sum);
    };
};
int main(){
    AddThree()([](auto summ){
              auto  ave = summ/3;
              return [ave](auto state){
                  state(ave);}([](auto aver){
                cout<<"这些数的平均数为: "<<aver<<endl;});
              });
    return 0;
}


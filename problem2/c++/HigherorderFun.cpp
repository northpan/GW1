#include<iostream>
/*
���׺���:������������ƽ����
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
                cout<<"��Щ����ƽ����Ϊ: "<<aver<<endl;});
              });
    return 0;
}


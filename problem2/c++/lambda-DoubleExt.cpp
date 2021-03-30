#include<iostream>

using namespace std;

int main(){
    int num = 10;
    auto ByValue = [num](){return num+1;};
    auto ByIndex = [&num](){return num+1;};
    auto ByValueMut = [num]()mutable{return num++;};
    auto ByIndexMut = [&num](){return num++;};
    //值捕获，真实num不变，为10
    cout<<"ByValue-num: "<<ByValue()<<endl;
    //按引用捕获，可操作真实num，但仍然为10
    cout<<"ByIndex-num: "<<ByIndex()<<endl;
    //值捕获，真实num不变,为10，加入mutable，捕获值上可变化，捕获num最终为11
    cout<<"ByValueMut-num: "<<ByValueMut()<<endl;
    //按引用捕获，真实num最终变为11
    cout<<"ByIndexMut-num: "<<ByIndexMut()<<endl;
    cout<<"num: "<<num<<endl;

    num+=3;
    //值捕获，真实num不变，为14
    cout<<"ByValue-num: "<<ByValue()<<endl;
    //按引用捕获，可操作真实num，但仍然为14
    cout<<"ByIndex-num: "<<ByIndex()<<endl;
    //值捕获，真实num不变，为14,加入mutable,捕获num最终为12
    cout<<"ByValueMut-num: "<<ByValueMut()<<endl;
    //按引用捕获，真实num最终变为15
    cout<<"ByIndexMut-num: "<<ByIndexMut()<<endl;
    cout<<"num: "<<num<<endl;
    return 0;
}

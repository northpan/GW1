#include<iostream>

using namespace std;

int main(){
    int num = 10;
    auto ByValue = [num](){return num+1;};
    auto ByIndex = [&num](){return num+1;};
    auto ByValueMut = [num]()mutable{return num++;};
    auto ByIndexMut = [&num](){return num++;};
    //ֵ������ʵnum���䣬Ϊ10
    cout<<"ByValue-num: "<<ByValue()<<endl;
    //�����ò��񣬿ɲ�����ʵnum������ȻΪ10
    cout<<"ByIndex-num: "<<ByIndex()<<endl;
    //ֵ������ʵnum����,Ϊ10������mutable������ֵ�Ͽɱ仯������num����Ϊ11
    cout<<"ByValueMut-num: "<<ByValueMut()<<endl;
    //�����ò�����ʵnum���ձ�Ϊ11
    cout<<"ByIndexMut-num: "<<ByIndexMut()<<endl;
    cout<<"num: "<<num<<endl;

    num+=3;
    //ֵ������ʵnum���䣬Ϊ14
    cout<<"ByValue-num: "<<ByValue()<<endl;
    //�����ò��񣬿ɲ�����ʵnum������ȻΪ14
    cout<<"ByIndex-num: "<<ByIndex()<<endl;
    //ֵ������ʵnum���䣬Ϊ14,����mutable,����num����Ϊ12
    cout<<"ByValueMut-num: "<<ByValueMut()<<endl;
    //�����ò�����ʵnum���ձ�Ϊ15
    cout<<"ByIndexMut-num: "<<ByIndexMut()<<endl;
    cout<<"num: "<<num<<endl;
    return 0;
}

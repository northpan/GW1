#include <iostream>
//¶þ½×º¯Êý:´òÕÐºô
using namespace std;

auto hail = [](auto name){
    auto words = "Hello!  " + name;
    return [=](auto say){
        say(words);
    };
};


int main()
{
    hail(string("Wu"))([](auto sentence){
        cout << sentence;
    });
    return 0;
}

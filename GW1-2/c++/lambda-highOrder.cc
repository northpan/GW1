#include <iostream>
using namespace std;

int main(){
    // Higher-Order Function in C++ lambda of page 7 of B1fundamentals-6in1.pdf
    auto f0 = [](int y){return y + 1;};
    auto f1 = [](int x, int f0(int)){
        return f0(f0(x));
    };
    cout << "x = 1; f returns: " << f1(1, f0) << endl; 
    // Higher-Order Function in C++ lambda of page 26 of B1fundamentals-6in1.pdf
    // Modified to (λx.p)((λy.y)z)
    int p = 4;
    int z = 1;
    auto fy = [](int a)-> int {return a;};
    auto fx = [p](int){return p;};
    cout << "z = 1, p = 4; f returns: " << fx(fy(z)) << endl; 

    return 0;
}

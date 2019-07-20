#include <iostream>
using namespace std;

class Base {
public:
    int k;
    Base(int n):k(n) { }
    Base(){}
};

class Big  {
public:
    int v; Base b;
// 在此处补充你的代码
    Big(int v_){
        v = v_;
        b = Base(v);
    }
    
    Big(const Big &b_){
        v = b_.v;
        b = b_.b;
    }

};
int main()  {
    Big a1(5);    Big a2 = a1;
    cout << a1.v << "," << a1.b.k << endl;
    cout << a2.v << "," << a2.b.k << endl;
    return 0;
}

#include<iostream>
using namespace std;
class Number {
public:
    int num;
    Number(int n=0): num(n) {}
// 在此处补充你的代码
    Number operator* (const Number &b){
        this->num = num * b.num;
        return *this;
    }
    operator int() const{
        return  this->num;
    }
};

int main() {
    Number n1(10), n2(20);
    Number n3;n3 = n1*n2;
    cout << int(n3) << endl;
    return 0;
}
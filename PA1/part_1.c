#include <iostream>
using namespace std;
class A {
public:
    int val;
// 在此处补充你的代码
    int& GetObj() {
        return val;
    }
    A(const A &a) {
        val = a.val;
    }
    A() {
        val = 0;
    }
};
int main()  {
    A a;
    cout << a.val << endl;
    a.GetObj() = 5;
    cout << a.val << endl;
    return 0;
}

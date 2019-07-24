#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
// 在此处补充你的代码
   void operator=(const char* cpxstr) {
        string cpxvalue(cpxstr);
        string delimiter = "+";
        r = atoi(cpxvalue.substr(0, cpxvalue.find(delimiter)).c_str());
        cpxvalue.erase(0, cpxvalue.find(delimiter) + delimiter.length());
        i = atoi(cpxvalue.substr(0, cpxvalue.find("i")).c_str());
    }
};

int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}

#include <iostream>
#include <cstring>
using namespace std;
// 在此处补充你的代码

class Array2{
private:
    int *p;   
    int column;
    int row;
    int size;
public:
    Array2(const int a, const int b):size(a * b), column(b), row(a){
        p = new int[size];
    }
    
    Array2(){
        column = 0;
        row = 0;
        size = 0;
    }

    Array2(const Array2 &a1) {
        if(a1.p){
            column = a1.column; 
            row = a1.row;
            size = a1.size;
            memcpy(p, a1.p, a1.size);
        }
        column = 0;
        row = 0;
        size = 0;
    }

    int *operator[](int index);

    int operator()(const int a, const int b) {
        return p[a * column + b];
    }
};


int* Array2::operator[](int index) {
    return &p[index * column];
        
}

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}

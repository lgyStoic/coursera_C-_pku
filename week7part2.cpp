#include <iostream>

using namespace std;
int main(){
    double val;
    cin >> val;
    cout.precision(5);
    cout << fixed << val << endl;
    cout.precision(7);
    cout << scientific << val << endl;
}
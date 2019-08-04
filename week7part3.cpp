#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
    int val;
    cin >> val;
    cout << hex << val << endl;
    cout << dec << setw(10) << setfill('0') << val << endl;
    return 0;
}
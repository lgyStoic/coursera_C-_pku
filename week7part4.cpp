#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main(int argc, char const *argv[])
{
    int commandNum;
    cin >> commandNum;
    cin.ignore();
    string *strValue = new string[commandNum];
    for (int i = 0; i < commandNum; ++i)
    {
        getline(cin, strValue[commandNum]);
    }
    string cmdstr;
    vector<string> v;
    while(cmdstr.compare("over") != 0){
        getline(cin, cmdstr);
        stringstream ss(cmdstr);
        vector<string> substrs;
        string substr;
        while()

    }
    return 0;
}
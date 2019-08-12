#include <iostream>
#include <string>
#include <list>
#include <sstream>
using namespace std;


static string opstr[] = {"", };

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
    while(cmdstr.compare("over") != 0){
        getline(cin, cmdstr);
        stringstream ss(cmdstr);
        list<string> substrslist;
        string substr;
        while(ss >> substr){
            substrslist.push_back(substr);
        }
        list<string>::reverse_iterator riter = substrslist.rbegin();
        while (riter != substrslist.rend())
        {
            cout << 1 << endl;
            if ((*riter).compare("printall") == 0)
            {
                for (size_t i = 0; i < commandNum; i++)
                {
                    cout << strValue[i] << endl;
                }
                
            }
            
        }
        
    }
    return 0;
}
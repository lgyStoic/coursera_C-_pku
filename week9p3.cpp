#include <iostream>
#include <set>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;

int stringtoint(const string &s){
    stringstream ss(s);
    int ids;
    ss >> ids;
    return ids;
}

int main(int argc, char const *argv[])
{
    int num;
    cin >> num;
    cin.ignore();
    multiset<int> mls;
    set <int> hasAdd;
    while (num--)
    {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<string> substrslist;
        string substr;
        while(ss >> substr){
            substrslist.push_back(substr);
        }
        if (substrslist[0].compare("add") == 0)
        {
            mls.insert(stringtoint(substrslist[1]));
            int valuecount = mls.count(stringtoint(substrslist[1]));
            hasAdd.insert(stringtoint(substrslist[1]));
            cout << valuecount << endl;
        } else if (substrslist[0].compare("del") == 0){
            int valuecount = mls.count(stringtoint(substrslist[1]));
            mls.erase(stringtoint(substrslist[1]));
            cout << valuecount << endl;
        } else if(substrslist[0].compare("ask") == 0){
            int valuecount = mls.count(stringtoint(substrslist[1]));
            bool valuebeenadd = (hasAdd.find(stringtoint(substrslist[1])) != hasAdd.end());
            if(valuebeenadd != 0){
                cout << 1 << " " << valuecount << endl;
            } else {
                cout << 0 << " " << 0 << endl; 
            }
        }
    }
    
    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <cstdlib>
#include <algorithm>
using namespace std;

bool is_number_inrange(string nodevalue){
    if (nodevalue.length() > 5)
    {
        return false;
    }
    
    for (string::iterator it = nodevalue.begin(); it != nodevalue.end(); it++)
    {
        if ((*it) < '0' || (*it) > '9')
        {
            return false;
        }   
    }
    return true;
}

// void showres(vector<string> strvec){
//     for (auto it = strvec.begin(); it < strvec.end(); it++)
//     {
//         cout << *it << endl;
//     }
// }

int main(int argc, char const *argv[])
{
    int commandNum;
    cin >> commandNum;
    cin.ignore();
    string *strValue = new string[commandNum];
    
    for (int i = 0; i < commandNum; ++i)
    {
        getline(cin, strValue[i]);
    }
    string cmdstr;
    streambuf* oldCoutStreamBuf = cout.rdbuf();
    ostringstream strCout;
    cout.rdbuf( strCout.rdbuf());
    while(cmdstr.compare("over") != 0){
        getline(cin, cmdstr);
        stringstream ss(cmdstr);
        vector<string> substrslist;
        string substr;
        while(ss >> substr){
            substrslist.push_back(substr);
        }
        reverse(substrslist.begin(), substrslist.end());
        
        
        vector<string>::iterator iter = substrslist.begin();
        while (iter != substrslist.end())
        {
            if ((*iter).compare("printall") == 0)
            {
                for (size_t i = 0; i < commandNum; i++)
                {
                    cout << strValue[i] << endl;
                }
                break;   
            }
            if ((*iter).compare("insert") == 0)
            {
                // get threee item to compute
                string snode = *(iter - 1);
                string nnode = *(iter - 2);
                string xnode = *(iter - 3);
                string svalue = snode;
                int nvalue = atoi(nnode.c_str()) - 1;
                int xvalue = atoi(xnode.c_str());
                strValue[nvalue] = strValue[nvalue].insert(xvalue, svalue);
                *iter = strValue[nvalue];
                substrslist.erase(iter - 1);
                substrslist.erase(iter - 2);
                substrslist.erase(iter - 3); 
                iter -= 3;
                // showres(substrslist);
            }
            if ((*iter).compare("find") == 0)
            {
                // get two item to compute
                string snode = *(iter - 1);
                string nnode = *(iter - 2);
                int nvalue = atoi(nnode.c_str()) - 1;
                string svalue = snode;
                size_t found = strValue[nvalue].find(svalue);
                if(found == string::npos){
                    found = snode.length();
                }
                ostringstream oss;
                oss << found;
                *iter = oss.str();
                substrslist.erase(iter - 1);
                substrslist.erase(iter - 2);
                iter -= 2;
                // showres(substrslist);
            }
            if((*iter).compare("rfind") == 0){
                // get two item to compute
                string snode = *(iter - 1);
                string nnode = *(iter - 2);
                
                int nvalue = atoi(nnode.c_str()) - 1;
                string svalue = snode;
                size_t found = strValue[nvalue].rfind(svalue);
                if(found == string::npos){
                    found = snode.length();
                }
                ostringstream oss;
                oss << found;
                *iter = oss.str();
                substrslist.erase(iter - 1);
                substrslist.erase(iter - 2);
                iter -= 2;
            }
            if((*iter).compare("reset") == 0){
                string snode = *(iter - 1);
                string nnode = *(iter - 2);
                int nvalue = atoi(nnode.c_str()) - 1;
                string svalue = snode;
                strValue[nvalue] = svalue;
                substrslist.erase(iter - 1);
                substrslist.erase(iter - 2);
                iter -= 2;
            }
            if((*iter).compare("copy") == 0){
                string nnode = *(iter - 1);
                string xnode = *(iter - 2);
                string lnode = *(iter - 3);
                
                int nvalue = atoi(nnode.c_str()) - 1;
                int xvalue = atoi(xnode.c_str());
                int lvalue = atoi(lnode.c_str());
                
                string currentNode = strValue[nvalue].substr(xvalue, lvalue);
                *iter = currentNode;
                substrslist.erase(iter - 1);
                substrslist.erase(iter - 2);
                substrslist.erase(iter - 3);
                iter -= 3;
                // showres(substrslist); 
            }
            if((*iter).compare("add") == 0){
                string s1node = *(iter - 1);
                string s2node = *(iter - 2);
                
                bool isnumber_s1 = is_number_inrange(s1node);
                bool isnumber_s2 = is_number_inrange(s2node);
                if (isnumber_s1 && isnumber_s2)
                {
                    int res =  atoi(s1node.c_str()) + atoi(s2node.c_str());
                    ostringstream oss;
                    oss << res;
                    *iter = oss.str();
                } else {
                    string res = s1node + s2node;
                    *iter = res;
                }
                substrslist.erase(iter - 1);
                substrslist.erase(iter - 2);
                iter -= 2;
            }
            if((*iter).compare("print") == 0){
                string indexstr = *(iter - 1);
                int indexNum =  atoi(indexstr.c_str()) - 1;
                cout << strValue[indexNum] << endl;
            }
            iter++;
        }
        
    }
    cout.rdbuf( oldCoutStreamBuf );
    cout << strCout.str();
    return 0;
}
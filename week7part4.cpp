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
            if ((*riter).compare("printall") == 0)
            {
                for (size_t i = 0; i < commandNum; i++)
                {
                    cout << strValue[i] << endl;
                }
                break;   
            }
            if ((*riter).compare("insert") == 0)
            {
                // get threee item to compute
                string snode = *(riter + 1);
                string nnode = *(riter + 2);
                string xnode = *(riter + 3);
                string svalue = snode;
                int nvalue = atoi(nnode.c_str());
                int xvalue = atoi(xnode.c_str());
                strValue[nvalue] = strValue[nvalue].insert(xvalue, svalue);
                *riter = strValue[nvalue];
            }
            if ((*riter).compare("find") == 0)
            {
                // get two item to compute
                string snode = *(riter + 1);
                string nnode = *(riter + 2);
                int nvalue = atoi(nnode.c_str());
                string svalue = snode;
                size_t found = strValue[nvalue].find(svalue);
                if(found == string::npos){
                    found = svalue.length;
                }
                *riter = found;
            }
            if((*riter).compare("rfind") == 0){
                // get two item to compute
                string snode = *(riter + 1);
                string nnode = *(riter + 2);
                int nvalue = atoi(nnode.c_str());
                string svalue = snode;
                size_t found = strValue[nvalue].rfind(svalue);
                if(found == string::npos){
                    found = svalue.length;
                }
                *riter = found; 
            }
            if((*riter).compare("reset") == 0){
                string snode = *(riter + 1);
                string nnode = *(riter + 2);
                int nvalue = atoi(nnode.c_str());
                string svalue = snode;
                strValue[nvalue] = svalue;
            }
            if((*riter).compare("copy") == 0){
                string snode = *();
            }
            if((*riter).compare("add") == 0){
                
            }
            if((*riter).compare("print") == 0){
                string indexstr = *(riter + 1);
                int indexNum =  atoi(indexstr.c_str());
                cout << strValue[indexNum] << endl;
            }
            riter--;
        }
        
    }
    return 0;
}
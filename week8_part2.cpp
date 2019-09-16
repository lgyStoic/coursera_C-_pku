#include <list>
#include <iostream>
#include <sstream>
#include <map>
#include <set>

using namespace std;

int string_to_int(const string &s){
    stringstream ids(s);
    int idint;
    ids >> idint;
    return idint;
}

int getsequeID(list<string> &l){
    string idvalue = l.front();
    l.pop_front();
    return string_to_int(idvalue);
}

int main(int argc, char const *argv[])
{
    int count;
    cin >> count;
    map<int, multiset<int> > valueMap;
    cin.ignore();
    while (count--)
    {  
        string s;
        getline(cin, s);
        stringstream ss(s);
        string subss;
        list<string> valuel;
        while (ss >> subss){
            valuel.push_back(subss);
        }
        string cmdstr = valuel.front();
        valuel.pop_front();
        if (cmdstr.compare("new") == 0){
            int idint = getsequeID(valuel);
            multiset<int> v;
            pair<int, multiset<int> > p(idint, v);
            valueMap.insert(p);
        } else if(cmdstr.compare("add") == 0){
            int idint = getsequeID(valuel);
            int numstr = getsequeID(valuel);
            multiset<int> l = valueMap[idint];
            l.insert(numstr);
            valueMap[idint] = l;
        } else if(cmdstr.compare("out") == 0){
            int idint = getsequeID(valuel);
            multiset<int> l = valueMap[idint];
            multiset<int>::iterator lit = l.begin();
            while (lit != l.end())
            {
                cout << *lit << " ";
                lit++;
            }
            cout << endl;
            valueMap[idint] = l;
        } else if(cmdstr.compare("merge") == 0){
            int id1int = getsequeID(valuel);
            int id2int = getsequeID(valuel);
            if (id1int == id2int)
            {
                continue;
            }
            multiset<int>  l1 = valueMap[id1int];
            multiset<int>  l2 = valueMap[id2int];
            multiset<int>::iterator lit = l2.begin();
            while (lit != l2.end())
            {
                l1.insert(*lit);
            }
            valueMap[id1int] = l1;
            valueMap.erase(id2int);
        } else if(cmdstr.compare("unique") == 0){
            set<int> s;
            int idint = getsequeID(valuel);
            multiset<int> l = valueMap[idint];
            multiset<int>::iterator mbegin = l.begin();
            multiset<int>::iterator mend = l.end();
            for (mbegin; mbegin != mend; mbegin++)
            {
                s.insert(*mbegin);
            }
            set<int>::iterator sbegin = s.begin();
            multiset<int> ln;
            for (sbegin; sbegin != s.end(); sbegin++)
            {
                ln.insert(*sbegin);
            }
            valueMap[idint] = ln;
        }
    }
    
    
    return 0;
}

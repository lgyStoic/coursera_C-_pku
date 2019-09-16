#include <iostream> 
#include <iterator> 
#include <set> 

using namespace std;
int main() { 
    int a[] = {8,7,8,9,6,2,1}; 
// 在此处补充你的代码
    int vsize = sizeof(a)/sizeof(int);
    set<int> v;
    for (size_t i = 0; i < vsize; i++)
    {
        v.insert(a[i]);
    }
        
    ostream_iterator<int> o(cout," ");
    copy( v.begin(),v.end(),o); 
    return 0;
}
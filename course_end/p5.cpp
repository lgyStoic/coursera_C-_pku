#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 在此处补充你的代码
class CMy_add{
    int &sum;
public:
    CMy_add(int &n): sum(n){
       
    }
    void operator()(int v){
        v = v % 8;
        sum +=v;    
    }
};

int main(int argc, char* argv[]) {
        int v, my_sum=0;
        vector<int> vec;
        cin>>v;
        while ( v ) {
                vec.push_back(v);
                cin>>v;
        }
        for_each(vec.begin(), vec.end(), CMy_add(my_sum));
        cout<<my_sum<<endl;
        return 0;
}
#include <iostream>
using namespace std;
// 在此处补充你的代码
class CType{
private:
    int n;
    int ns;
public:
    void setvalue(int v){
       n = v; 
       ns = 0;
    }
    CType& operator++(int){
        
        return *this;
    }

    friend ostream& operator<<(ostream &os, CType &t){
        if (t.ns == 0)
        {
            os << t.n;
            t.ns = t.n * t.n;
        } else {
            os << t.ns;
        }
        
        return os;
    }

};
int main(int argc, char* argv[]) {
        CType obj;
        int n;
        cin>>n;
        while ( n ) {
                obj.setvalue(n);
                cout<<obj++<<" "<<obj<<endl;
                cin>>n;
        }
        return 0;
}
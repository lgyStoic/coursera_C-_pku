#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
// 在此处补充你的代码
class MyString :public string{

public:
    MyString() :string(){};                       //构造函数，针对 s2 初始化的默认
    MyString(const char* str) :string(str){};     //构造函数，char*是数据类型，而string是类 http://www.cnblogs.com/GODYCA/archive/2013/01/08/2851923.html
    MyString(MyString &str) :string(str){};       //复制构造函数
    MyString(const string &str) :string(str){};   //类型转换构造函数，把string类转换为MyString类

    MyString operator()(int startPos, int strLengh){
        return this->substr(startPos, strLengh);
    }

};

// class MyString{
//     char *str;
// public:
//     MyString(char *s): str(s){
        
//     }
//     MyString(){
//         str = NULL;
//     }
    
//     int size(){
//         return strlen(str) + 1;
//     }
//     MyString & operator+( MyString &b){
//         int lengths = this->size() + b.size();
//         char *ns = (char*)malloc(sizeof(lengths) - 1);
//         memcpy(ns, str, strlen(str));
//         memcpy(ns + strlen(str) + 1, b.str, b.size());
//         str = ns;
//         return *this;
//     }

//     MyString &operator+=(char *s){
//         MyString ms(s);
//         return this->operator+(ms);
//     }

//     friend ostream& operator<<(ostream &os, const MyString s) {
//         if (s.str)
//         {
//             os << s.str;
//         }
        
        
//         return os;
//     }

//     char& operator[](int i){
//         return str[i];
//     }

//     friend MyString & operator+(MyString &a, char *b){
//         MyString bs(b);
//         return a + bs;
//     }
//     friend MyString & operator+(char *a, MyString &b){
//         MyString as(a);
//         return as + b;
//     }

//     const char * operator()(int start, int end){
//         char *s = (char *)malloc(sizeof(end - start));
//         int ni = 0;
//         for (size_t i = start; i < end; i++)
//         {
//             s[ni++] = str[i];
//         }
//         return s;
//     }

//     friend bool operator==(const MyString &a, const MyString &b){
//         return (strcmp(a.str, b.str) == 0);
//     }

//     friend bool operator>(const MyString &a, const MyString &b){
//         return (strcmp(a.str, b.str) > 0);
//     }

//     friend bool operator<(const MyString &a, const MyString &b){
//         return (strcmp(a.str, b.str) < 0);
//     }
// };

int CompareString( const void * e1, const void * e2)
{
        MyString * s1 = (MyString * ) e1;
        MyString * s2 = (MyString * ) e2;
        if( * s1 < *s2 )
                 return -1;
        else if( *s1 == *s2)
                 return 0;
        else if( *s1 > *s2 )
                 return 1;
}

int main()
{
        MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
        MyString SArray[4] = {"big","me","about","take"};
        cout << "1. " << s1 << s2 << s3<< s4<< endl;
        s4 = s3;
        s3 = s1 + s3;
        cout << "2. " << s1 << endl;
        cout << "3. " << s2 << endl;
        cout << "4. " << s3 << endl;
        cout << "5. " << s4 << endl;
        cout << "6. " << s1[2] << endl;
        s2 = s1;
        s1 = "ijkl-";
        // s1[2] = 'A' ;
        cout << "7. " << s2 << endl;
        cout << "8. " << s1 << endl;
        s1 += "mnop";
        cout << "9. " << s1 << endl;
        s4 = "qrst-" + s2;
        cout << "10. " << s4 << endl;
        s1 = s2 + s4 + " uvw " + "xyz";
        cout << "11. " << s1 << endl;
        qsort(SArray,4,sizeof(MyString),CompareString);
        for( int i = 0;i < 4;i ++ )
        cout << SArray[i] << endl;
        //s1的从下标0开始长度为4的子串
        cout << s1(0,4) << endl;
        //s1的从下标5开始长度为10的子串
        cout << s1(5,10) << endl;
        return 0;
}
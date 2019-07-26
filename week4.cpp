#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

class BigData
{
private:
    /* data */
    char *p;
    int size;
public:
    BigData(const string &datastr);
    ~BigData();
    BigData(const int size_):size(size_){
        p = new char[size];
    }
    BigData & operator+(const BigData &b);
    BigData & operator-(const BigData &b);
    BigData & operator*(const BigData &b);
    BigData & operator/(const BigData &b);
    char operator[](int index);
    
    friend ostream& operator<<(ostream &os, const BigData &a);
};


ostream& operator<<(ostream &os, const BigData &a){
    os << (const char *)a.p;
    return os;
}

char BigData::operator[](int index){
    return p[index];
}

BigData & BigData::operator+(const BigData &b){
    int addOne = false;
    BigData *c = new BigData(size > b.size ? size:b.size);
    int i = size - 1;
    int j = b.size - 1;
    int k = c->size - 1;
    while(i>= 0 && j >= 0)
    {
        char m = p[i];
        char n = b.p[j];
        int sum = m - '0' + n - '0' + addOne;
        addOne = sum / 10;
        sum = sum % 10;
        c->p[k] = sum + '0';
        --i;
        --j;
        --k;
    }
    char m;
    if (i >= 0)
    {
        m = p[i];
    } else {
        i = j;
        m = b.p[i];
    }
    
    while (i >= 0)
    {
        char m = p[i];
        int sum = atoi(&m) + addOne;
        addOne = sum / 10;
        sum = sum % 10;
        c->p[k] = sum + '0';
        i--;k--;
    }
    if (addOne)
    {
        BigData *d = new BigData(c->size + 1);
        for (size_t i = d->size - 1; i >= 1; i--)
        {
            d->p[i] = c->p[i -1];
        }
        d->p[0] = '1';
        return *d;
    } else {
        return *c;
    }
    
}

BigData & BigData::operator-(const BigData &b){

}

BigData & BigData::operator*(const BigData &b){

}

BigData & BigData::operator/(const BigData &b){
    
}

BigData::BigData(const string &datastr):size(datastr.length())
{
    p = new char[size];
    strcpy(p, datastr.c_str());
}

BigData::~BigData()
{
    delete [] p;
}


int main(int argc, char const *argv[])
{
    string a,b;
    char symbol;
    cin >> a;
    cin >> symbol;
    cin >> b;
    BigData abigdata(a);
    BigData bbigdata(b);
    BigData c = abigdata + bbigdata;
    cout << c << endl;
    return 0;
}

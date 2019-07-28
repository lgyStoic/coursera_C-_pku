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
    bool isNagative;
public:
    BigData(const string &datastr);
    BigData(){

    }
    ~BigData();
    BigData(const int size_):size(size_){
        p = new char[size];
        isNagative = false;
    }
    BigData & operator+(const BigData &b);
    BigData & operator-(const BigData &b);
    BigData & operator*(const BigData &b);
    BigData & operator/(const BigData &b);

    BigData(const BigData &b){
        size = b.size;
        p = new char[size];
        isNagative = b.isNagative;
        strcpy(p, b.p);
    }
    static const BigData &reformatBigData(const BigData &b);
    char operator[](int index);
    friend bool operator>(const BigData &a, const BigData &b);
    friend ostream& operator<<(ostream &os, const BigData &a);
};

const BigData & BigData::reformatBigData(const BigData &b){
    int coutZero = 0;
    for (int i = 0; i < b.size; ++i)
    {
        if (b.p[i] == '0')
        {
            coutZero++;
        } else {
            break;
        }
    }
    if (coutZero == 0)
    {
        return b;
    }
    BigData *formatB = new BigData(b.size - coutZero);
    for (int i = 0; i < formatB->size; ++i)
    {
        formatB->p[i] = b.p[i + coutZero];
    }
    return *formatB;
}

bool operator>(const BigData &a, const BigData &b) {
    BigData aformat = BigData::reformatBigData(a);
    BigData bformat = BigData::reformatBigData(b);
    if (aformat.size > bformat.size)
    {
        return true;
    }
    if (aformat.size < bformat.size)
    {
        return false;
    }

    for (int i = 0; i < aformat.size; ++i)
    {
        if (aformat.p[i] < bformat.p[i])
        {
            return false;
        }
        if (aformat.p[i] > bformat.p[i])
        {
            return true;
        }
    }
    return true;
}


ostream& operator<<(ostream &os, const BigData &a){
    if (a.isNagative)
    {
        os << "-";
    }

    bool continueEqualZero = true;
    for (int i = 0; i < a.size; ++i)
    {
        if (continueEqualZero && (a.p[i] == (0 + '0')))
        {
            continue;
        }
        else {
            continueEqualZero = false;
        }
        os << a.p[i];
    }
    if (continueEqualZero == true)
    {
        os << "0";
    }
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
    
    
    while (i >= 0)
    {
        int sum = p[i] - '0' + addOne;
        addOne = sum / 10;
        sum = sum % 10;
        c->p[k] = sum + '0';
        i--;k--;;
    }
    while (j >= 0)
    {
        int sum = b.p[j] - '0' + addOne;
        addOne = sum / 10;
        sum = sum % 10;
        c->p[k] = sum + '0';
        j--;k--;;
    }
    if (addOne)
    {
        BigData *d = new BigData(c->size + 1);
        for (size_t i = d->size - 1; i >= 1; i--)
        {
            d->p[i] = c->p[i -1];
        }
        d->p[0] = '1';
        delete c;
        return *d;
    } else {
        return *c;
    }
    
}

BigData & BigData::operator-(const BigData &b){
    BigData *c = new BigData(size > b.size ? size : b.size);
    BigData *greater;
    BigData *smaller;
    if (*this > b)
    {
        greater = new BigData(*this);
        smaller = new BigData(b);
    } else{
        greater = new BigData(b);
        smaller = new BigData(*this);
        c->isNagative = true;
    }
    int i = greater->size - 1;
    int j = smaller->size - 1;
    int k = c->size - 1;
    bool needOne = false;
    while(i >= 0 && j >= 0){
        int minusValue = (*greater)[i] - needOne - (*smaller)[j];
        
        if (minusValue < 0)
        {
            needOne = true;
            minusValue += 10;
        } else {
            needOne = false;
        }
        c->p[k] = minusValue + '0';
        i--;j--;k--;
    }

    while(i >= 0){
        int minusValue = (*greater)[i] - needOne - '0';
        if (minusValue < 0)
        {
            needOne = true;
            minusValue += 10;
        } else {
            needOne = false;
        }
        c->p[k] = minusValue + '0';
        i--;k--;
    }

    return *c;

}

BigData & BigData::operator*(const BigData &b){
    BigData *bdPoint[b.size - 1];
    for (int i = b.size - 1; i >=0; --i)
    {
        BigData *temp = new BigData(size + 1);
        int addVal = 0;
        int k = temp->size - 1;
        for (int j = size - 1; j >= 0; --j)
        {
            int product = (p[j] - '0') * (b.p[i] - '0') + addVal;
            addVal = product / 10;
            int remain = product % 10;
            temp->p[k--] = remain + '0';
        }
        temp->p[k] = addVal + '0';
        bdPoint[b.size - i - 1] = temp;
    }

    int shift = 0;
    BigData *result = new BigData("0");
    for (int i = 0; i < b.size; ++i)
    {
        BigData *current = bdPoint[i];
        
        if (shift)
        {
            BigData *currentShift = new BigData(current->size + shift);
            for (int j = 0; j < current->size; ++j)
            {
                currentShift->p[j] = current->p[j];
            }
            for (int j = current->size; j < currentShift->size; ++j)
            {
                currentShift->p[j] = '0';
            }
            current = currentShift;
        }
        shift++;
        *result = (*result) + (*current);
        
    }
    return *result;
}

BigData & BigData::operator/(const BigData &b){
    if (b > (*this))
    {
        BigData *result = new BigData("0");
        return *result;
    }
    BigData *result = new BigData("0");
    BigData *addOne = new BigData("1");
    while((*this) > b){
        *this = *this - b;
        *result = (*result) + (*addOne);
        *this = BigData::reformatBigData(*this);
        cout << *this << endl;
    }
    return *result;
}

BigData::BigData(const string &datastr):size(datastr.length())
{
    p = new char[size];
    strcpy(p, datastr.c_str());
    isNagative = false;
}

BigData::~BigData()
{
    delete [] p;
}


int main(int argc, char const *argv[])
{
    string a,b;
    string symbol;
    cin >> a;
    cin >> symbol;
    cin >> b;
    BigData abigdata(a);
    BigData bbigdata(b);
    if (symbol.compare("+") == 0)
    {
        BigData c = abigdata + bbigdata;
        cout << c << endl;
    }

    if (symbol.compare("-") == 0)
    {
        BigData c = abigdata - bbigdata;
        cout << c << endl;
    }
    if (symbol.compare("*") == 0)
    {
        BigData c = abigdata * bbigdata;
        cout << c << endl;
    }
    if (symbol.compare("/") == 0)
    {
        BigData c = abigdata / bbigdata;
        cout << c << endl;
    }

    return 0;
}

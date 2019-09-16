#include <iostream>
using namespace std;
// 在此处补充你的代码
template <class T>
class CArray3D
{
public:
    template <class T1>
    class CArray2D
    {
    private:
        T1 *data;
        int column;
        int row;
    public:
        CArray2D<T1>(){

        }
        void setValue(int row_, int column_){
            row = row_;
            column = column_;
            data = new T[row * column];
        }
        T1* operator[](int index){
            return data + index * column;
        }
        ~CArray2D<T1>(){
            if (data)
            {
                delete [] data;
            }
        }
    };
private:
    CArray2D <T>* array3D;
    
public:
    CArray3D<T>(int dimension, int row, int column){
        array3D = new CArray2D<T>[dimension];
        for (size_t i = 0; i < dimension; i++)
        {
            array3D[i].setValue(row, column);
        }
    }
    CArray2D<T>& operator [] (int index){
        return array3D[index];
    }
    ~CArray3D<T>(){
        delete [] array3D;
    }
};

int main()
{
    CArray3D<int> a(3,4,5);
    int No = 0;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                a[i][j][k] = No ++;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                cout << a[i][j][k] << ",";
    return 0;
}
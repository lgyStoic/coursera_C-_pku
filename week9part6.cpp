#include <iostream>
#include <queue>
#include <math.h>
#include <set>

using namespace std;

int primeFactors(int n) 
{ 
    // Print the number of 2s that divide n 
    set <int> s;    
    int v = n;
    while (n%2 == 0) 
    { 
        n = n/2;
        s.insert(2);
    } 
  
    // n must be odd at this point.  So we can skip  
    // one element (Note i = i +2) 
    for (int i = 3; i <= sqrt(n); i = i+2) 
    { 
        // While i divides n, print i and divide n 
        while (n%i == 0) 
        { 
            s.insert(i);
            n = n/i; 
        } 
    }   
    // This condition is to handle the case when n  
    // is a prime number greater than 2 
    if (n > 2 && n != v) 
        s.insert(n);
    return s.size();
} 

struct  numOrder{
    bool operator() (int &a, int &b) const{
        int ap = primeFactors(a);
        int bp = primeFactors(b);
        if (ap == bp)
        {
            return a < b;
        } else {
            return ap < bp;
        }
    }
};


int main(int argc, char const *argv[])
{
    int num;
    cin >> num;
    priority_queue<int, vector<int>, numOrder> pq;
    while (num--)
    {
        int t = 10;    
        while(t--){
            int n;
            cin >> n;
            pq.push(n);  
        }
        
        int countq = 0;
        priority_queue<int, vector<int>, numOrder> pq2;
        while (!pq.empty())
        {
            if (countq == 0 || pq.size() == 1)
            {
                cout << pq.top() << " ";
            } else {
                pq2.push(pq.top());       
            }
            countq++;
            pq.pop();
        }
        pq = pq2;
        cout << endl;     
    }

    
    
    
    return 0;
}

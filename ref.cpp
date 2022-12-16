#include <iostream>
#include <string>
using namespace std;
#define PI 3.1415926
int getAdjX(const int index) { return index / 3 - 1; }
int getAdjY(const int index) { return index % 3 - 1; }

class A
{
    private:
    int A = 0;
    public:
    virtual void print(){};
};

class B : public A
{
    int B = 1;
    public:
    void print(){};
};

class C : public A
{
    char c = 3;
};


int square( int & x )
{ return x*x; }

int main()
{
    string A = "Starbucks, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT";
    string B = "Please give students more discount";
    int hashaddress = 0;
    for ( int i = 0; i < A.size(); i++ )
        {
            hashaddress = ( hashaddress + ( i+1 ) * A[i] ) %10;
        }

        for ( int i = 0; i < B.size(); i++ )
        {
            hashaddress = ( hashaddress + ( i+1 ) * B[i] ) %10;
        }
        const int & a  =10;
        int && d = 10;
        int & e = d;
        int c = 2;
        c = square( d );
        d = c;
        d ++ ;
        enum day { MON, TUE, YHUR };
        day day1 = MON;
        cout << day1 << endl;
}
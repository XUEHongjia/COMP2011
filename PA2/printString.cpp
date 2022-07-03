#include <iostream>
using namespace std;



void printString(const char str[], int a=0)
{
    if (str[a]=='\0')
    {
        cout << endl;
    }
    else
    {
    cout << str[a] ;
    a += 1;
    printString( str, a );
    }
}

int main()
{
    printString("Wow !!");
    return 0;
}
    
    
    
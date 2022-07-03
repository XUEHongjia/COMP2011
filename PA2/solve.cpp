#include <iostream>
using namespace std;


bool plusminus(const char str[], int current)
{
    if ( str[current] == '+' )
    {
        return true;
    }
    else if ( str[current] == '-' )
    {
        return true;
    }
    else 
    {
        return false;
    }
}

int findnext(const char str[], int m, int diff=0)
{
    if ( (plusminus(str, m)) || ( str[m] == '\0' ) )
    {
        return diff;
    }
    else 
    {
        return findnext( str, m + 1, diff+1);
    }
}

int getIntValue(const char str[], int start, int end)  //Done
{
    int a;
    switch (str[end])
    {
        case '0' : a = 0; break;
        case '1' : a = 1; break;
        case '2' : a = 2; break;
        case '3' : a = 3; break;
        case '4' : a = 4; break;
        case '5' : a = 5; break;
        case '6' : a = 6; break;
        case '7' : a = 7; break;
        case '8' : a = 8; break;
        case '9' : a = 9; break;
    }
    if ( start == end )
    {
       return a; 
    }
    else
    {
        return 10*getIntValue( str, start, end-1 ) + a;
    } 
     //change this line if you want
}

int evaluate ( const char str[], int sum, int pos )
{
    if ( str[pos] == '\0' )
    {
        return sum;
    }
    else if ( str[pos] == '+' )
    {
        int diff;
        int num;
        diff = findnext(str, pos+1);
        num = getIntValue (str, pos+1, pos+diff);
        return evaluate ( str, sum + num, pos + diff + 1 ) ;
    }
    else if ( str[pos] == '-' )
    {
        int diff;
        int num;
        diff = findnext(str, pos+1);
        num = getIntValue (str, pos+1, pos+diff);
        return evaluate ( str, sum - num, pos + diff + 1 ) ;
    }
    else
    {
        int diff;
        int num;
        diff = findnext(str, pos);
        num = getIntValue (str, pos, pos+diff-1);
        return evaluate ( str, sum + num, pos + diff ) ;
    }
}

int main()
{
    int rand;
    rand = evaluate("-172+150", 0, 0);
    cout << rand;
    return 0;
}
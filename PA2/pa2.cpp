#include <iostream>
using namespace std;
//you are NOT allowed to include any additional library
const int ARRAY_MAX_SIZE = 12;

//given; do NOT modify; please refer to the webpage description
void printArray(int array[], int arraySize, int currentPosition)
{
    cout << array[currentPosition];
    if(currentPosition < arraySize-1)
    {
        if(array[currentPosition+1] > 0)
            cout << "+";
        printArray(array, arraySize, currentPosition+1);
    }
    else
        cout << endl;
}

//given; do NOT modify; please refer to the webpage description
void printArray(int array[], int arraySize)
{
     printArray(array, arraySize, 0);
}

//***** Only write your code below this line, remember that NO loop is allowed! ***** 
int arraySum(int array[], int arraySize)  // Done
{
    if (arraySize == 0)
    {
        return 0;  //change this line if you want
    }
    else 
    {
        return ( arraySum(array,arraySize-1) + array[arraySize-1] );
    }

}

bool solve(int input[], int size, int target, int result[], int& resultSize, int inputpos, int resultpos)  
{
    if ( inputpos == size)
    {
        int sum = arraySum(result,resultSize);
        if ( sum == target )
      {
        return true;
      }
      else 
      {
          return false;
      }
    }

    else
    {
        result [resultpos] = input [inputpos];
        resultSize += 1;
        bool a = solve( input,  size, target, result,  resultSize, inputpos+1 , resultpos+1);
        if (a)
        {
            return a;
        }
        resultSize -= 1;

        result [resultpos] = -1 * input [inputpos];
        resultSize += 1;
        bool b = solve( input,  size, target, result,  resultSize, inputpos+1, resultpos+1);
        if (b)
        {
            return b;
        }
        resultSize -= 1;

        bool c = solve ( input,  size, target, result,  resultSize, inputpos+1, resultpos);
        if (c)
        {
            return c;
        }

        return a || b || c ;
    } 
}

bool solve(int input[], int size, int target, int result[], int& resultSize)  //Done with overloading
{
    solve(input, size,  target, result, resultSize, 0 , 0 );//change this line if you want
}


void printString(const char str[], int a)  
{
    if (str[a]=='\0')
    {
        cout << endl;
    }
    else
    {
    cout << str[a] ;
    printString( str, a+1 );
    }
}

void printString(const char str[] )  //Done with overloading
{
    printString( str, 0);
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
    if ( ( plusminus(str, m)) || ( str[m] == '\0' ) )
    {
        return diff;
    }
    else 
    {
        return findnext( str, m + 1, diff+1);
    }
}

int evaluate ( const char str[], int sum, int pos )
{if ( str[pos] == '\0' )
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

int evaluate(const char str[])
{
    evaluate ( str, 0, 0 );  //change this line if you want
}
//***** Only write your code above this line, remember that NO loop is allowed! *****


int main()
{
    int testCase;
    cout << "Hi, recursion master! Which test case do you want to run?" << endl;
    cin >> testCase;

    cout << endl << "Test case " << testCase << " output:" << endl;
    cout << "===================================" << endl;

    if(testCase == 0) //this test case is used to show you how printArray works; it is NOT used to grade your work and it is NOT on ZINC; no mark is allocated to this; try it on your own computer if you want
    {
        int array1[] = {1, 2, 3};
        printArray(array1, 3);
        int array2[] = {1, 2, 3, -4};
        printArray(array2, 4);
        int array3[] = {-8, 2, 1, -4};
        printArray(array3, 4);
        int array4[] = {99};
        printArray(array4, 1);
        int array5[] = {-1199};
        printArray(array5, 1);
    }
    
    else if(testCase == 1) //test arraySum
    {
        int array[] = {1, 2, 3};
        cout << arraySum(array, 3) << endl;
    }
    else if(testCase == 2) //test arraySum
    {
        int array[] = {-1, -234, 33, 5};
        cout << arraySum(array, 4) << endl;
    }

    else if(testCase == 3) //test solve
    {
        int input[] = {1, 2, 3, 4};
        int size = 4;
        int target = 2;
        int result[ARRAY_MAX_SIZE] = {}; //filled with '\0'
        int resultSize = 0;
        if(solve(input, size, target, result, resultSize))
        {
            cout << "solved: ";
            printArray(result, resultSize);
        }
        else
            cout << "no solution!" << endl;
    }
    else if(testCase == 4) //test solve
    {
        int input[] = {1, 2, 3, 4};
        int size = 4;
        int target = -2;
        int result[ARRAY_MAX_SIZE] = {}; //filled with '\0'
        int resultSize = 0;
        if(solve(input, size, target, result, resultSize))
        {
            cout << "solved: ";
            printArray(result, resultSize);
        }
        else
            cout << "no solution!" << endl;
    }
    else if(testCase == 5) //test solve
    {
        int input[] = {1, 2, 3, 4};
        int size = 4;
        int target = -9;
        int result[ARRAY_MAX_SIZE] = {}; //filled with '\0'
        int resultSize = 0;
        if(solve(input, size, target, result, resultSize))
        {
            cout << "solved: ";
            printArray(result, resultSize);
        }
        else
            cout << "no solution!" << endl;
    }
    else if(testCase == 6) //test solve
    {
        int input[] = {8, 13, 1, 3, 5, 9};
        int size = 6;
        int target = 9;
        int result[ARRAY_MAX_SIZE] = {}; //filled with '\0'
        int resultSize = 0;
        if(solve(input, size, target, result, resultSize))
        {
            cout << "solved: ";
            printArray(result, resultSize);
        }
        else
            cout << "no solution!" << endl;
    }
    else if(testCase == 7) //test solve
    {
        int input[] = {88, 13, 1, 3, 5, 9};
        int size = 6;
        int target = 9;
        int result[ARRAY_MAX_SIZE] = {}; //filled with '\0'
        int resultSize = 0;
        if(solve(input, size, target, result, resultSize))
        {
            cout << "solved: ";
            printArray(result, resultSize);
        }
        else
            cout << "no solution!" << endl;
    }
    else if(testCase == 8) //test solve
    {
        int input[] = {888, 13333, 20000, 1, 99, 3, 5, 9, 33, 44, 55, 100};
        int size = 12;
        int target = -165;
        int result[ARRAY_MAX_SIZE] = {}; //filled with '\0'
        int resultSize = 0;
        if(solve(input, size, target, result, resultSize))
        {
            cout << "solved: ";
            printArray(result, resultSize);
        }
        else
            cout << "no solution!" << endl;
    }

    else if(testCase == 9) //test printString
    {
        printString("1+1-2+1234");
    }
    else if(testCase == 10) //test printString
    {
        printString("Wow this assignment is so much fun!!!");
    }

    else if(testCase == 11) //test getIntValue
    {
        char str[] = "567";
        cout << getIntValue(str, 0, 2) << endl;
    }
    else if(testCase == 12) //test getIntValue
    {
        char str[] = "567";
        cout << getIntValue(str, 0, 1) << endl;
    }
    else if(testCase == 13) //test getIntValue
    {
        char str[] = "567";
        cout << getIntValue(str, 0, 0) << endl;
    }
    else if(testCase == 14) //test getIntValue
    {
        char str[] = "abc567abc";
        cout << getIntValue(str, 4, 5) << endl;
    }
    
    else if(testCase == 15) //test evaluate
    {
        int input[] = {1, 2};
            int size = 2;
            int target = 0;
            int result[ARRAY_MAX_SIZE] = {}; //filled with '\0'
            int resultSize = 0;
            if(solve(input, size, target, result, resultSize))
            {
                cout << "solved: ";
                printArray(result, resultSize);
            }
            else
                cout << "no solution!" << endl;
    }
    else if(testCase == 16) //test evaluate
    {
        cout << evaluate("3+2") << endl;
    }
    else if(testCase == 17) //test evaluate
    {
        cout << evaluate("1+2-4") << endl;
    }
    else if(testCase == 18) //test evaluate
    {
        cout << evaluate("11+21-43") << endl;
    }
    else if(testCase == 19) //test evaluate
    {
        cout << evaluate("11+21-43+888") << endl;
    }
    else if(testCase == 20) //test evaluate
    {
        cout << evaluate("-21") << endl;
    }
   
    cout << "===================================" << endl;

    return 0;
}



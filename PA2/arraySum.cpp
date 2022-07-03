#include <iostream>
using namespace std;

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

int arraySum(int array[], int arraySize)
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

int main()
{
    int input[4] = {5,2,3,1};
    int size = 4;
        int target = 5;
        int result[12] = {}; //filled with '\0'
        int resultSize = 0;
        if(solve(input, size, target, result, resultSize))
        {
            cout << "solved: ";
            printArray(result, resultSize);
        }
        else
            cout << "no solution!" << endl;
    
    return 0;
}
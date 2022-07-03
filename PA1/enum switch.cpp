#include <iostream>
#include <cstring>
using namespace std;



int main()
{
int num = 1;
cout << &num << endl;

cout << num++ << endl;
cout << &num << endl;

num = 1;
cout << &num << endl;

cout << ++num << endl;

cout << &num << endl;
return 0;
}
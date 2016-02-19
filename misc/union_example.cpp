// Example program from instructor's website.
#include <iostream>
using namespace std;

union FloatValue
{
   int intView;
   float floatView;
};

int main( )
{
   FloatValue num;
   
   cout << "Enter a float value: ";
   cin >> num.floatView;
   cout << "You entered " << num.floatView << endl;
   cout << "If the bit pattern used to represent this value is interpreted"
        << " as an integer, \nthe value is "
        << num.intView << endl;   
    
   return 0;
}

#include <iostream>
#include <cstdlib>


using namespace std;
#define VEC_LEN 5

unsigned long dotprod(int a[VEC_LEN], int b[VEC_LEN])
{
    unsigned long retval = 0;
    for (int i = 0; i < VEC_LEN; ++i)
    {
        retval += a[i] * b[i];
    }
}

/* summation function */
unsigned long summation(unsigned long input)
{
    unsigned long sum = 0;
    for(unsigned long i = input; i > 0; i--)
    {
        sum += i;
    }
    return sum;
}

int main(void)
{
    int val = 0;
    int output = 0;

    /*************/

    cout << "I will multiply two vectors!" << endl;
    int a[VEC_LEN] = {1, 2, 3, 4, 5};
    int b[VEC_LEN] = {1, 1, 1, 1, 1};
    output = dotprod(a, b);

    cout << "The value is " << output << "!!" << endl;


    /*************/

    cout << "Please enter a value, and I will compute the sum of all natural numbers up to that value!" << endl;
    cin >> val;
    output = summation(val);
    cout << "The value is " << output << "" << endl;

    return 0;
}

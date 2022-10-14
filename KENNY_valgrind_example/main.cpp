#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

#define ARR_SIZE 5


class CoolArray {
    private:
        int * values;

    public:
        CoolArray(int * arr) {
            // Do a shallow copy
            values = arr;
        }

        ~CoolArray()
        {
            //free(values);
        }

        int operator[] (int idx) {
            return values[idx];
        }
};


/**************************/
/**************************/
/**************************/
/**************************/
/**************************/

void TestCoolArray() {
    int *arr1 = (int*) malloc(ARR_SIZE*sizeof(int));
    
    for (int i = 0; i < ARR_SIZE; ++i) {
        arr1[i] = i;
    }

    CoolArray arr2(arr1);

    for (int i = 0; i < ARR_SIZE; ++i) {
        cout << arr2[i] << endl;
    }
    
    //free(arr1);
}

int main(void)
{
    cout << "Starting test now!" << endl;
    TestCoolArray();
    cout << "Test done." << endl;

    return 0;
}

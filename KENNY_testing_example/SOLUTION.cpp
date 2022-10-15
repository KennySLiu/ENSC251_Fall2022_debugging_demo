#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <climits>
#define KENNY_DEBUGGING (0)

using namespace std;

/*************/
/*************/
/*************/
/*************/

bool isPalindrome_nostringconvert(int input) {
    bool retval = true;
    int left_digit = 0;
    int right_digit = 0;
    int max_divider = 1;

    if (input < 0) {
        return false;
    }

    // NOTE: using <= 10, and then doing max_divider /= 10 after the loop, fails 
    // if the input is too big.
    while (max_divider < INT_MAX) {
        if (input/max_divider < 10) {
            break;
        }
        max_divider *= 10;
    }

    #if KENNY_DEBUGGING// DEBUGGING:
    cout << "input = " << input << ". max_divider = " << max_divider << endl;
    #endif
    
    // Divider helps us sweep through all the digits in the input.
    for (   int RDivider = 1, ctr = 0; 
            RDivider < max_divider;
            RDivider *= 10, ctr++)
    {
        int LDivider = (max_divider / RDivider);
        right_digit = input/RDivider;         // grab all digits to the left of RDivider
        right_digit = right_digit%10;    // Keep only the rightmost digit (to the left of RDivider)

        left_digit = input/LDivider;
        left_digit = left_digit%10;

        #if KENNY_DEBUGGING// DEBUGGING:
        cout << "ctr = " << ctr << ": (LDivider, RDivider) = (" << LDivider << ", " << RDivider << ")" << endl;
        cout << "ctr = " << ctr << ": (ldigit, rdigit) = (" << left_digit << ", " << right_digit << ")" << endl;
        #endif

        if (left_digit != right_digit) {
            retval = false;
        }
    }
    return retval;
}

/*************/

bool isPalindrome_stringconvert(int input) {
    stringstream ss;
    ss << input;
    string input_str = ss.str();
    int len = input_str.length() - 1;
    
    // NOTE: using < instead of <= will fail when the input is 2 digits
    for (int i = 0; i <= len/2; ++i)
    {
        if (input_str.at(i) != input_str.at(len-i))
        {
            return false;
        }
    }

    return true;
}

/*************/

int main() {
    const int num_valid_tests = 10;
    int valid_palindromes[num_valid_tests] = {
        12321,
        92500529,
        235532,
        999999999,
        11,
        1,
        5,
        2000000002,
        55555
    };
    const int num_fail_tests = 8;
    int non_palindromes[num_fail_tests] = {
        12,
        1412,
        83885,
        123432,
        59599,
        2000000003,
        -1,
        -151
    };

    // Testing valid palindromes:
    for (int i = 0; i < num_valid_tests; ++i) {
        if (isPalindrome_stringconvert(valid_palindromes[i]) == 0) {
            cout << "STRINGCONVERT VALID TEST FAILED on test " << i << endl;
        }
        if (isPalindrome_nostringconvert(valid_palindromes[i]) == 0) {
            cout << "NOSTRINGCONVERT VALID TEST FAILED on test " << i << endl;
        }
    }
    // Testing NON palindromes:
    for (int i = 0; i < num_fail_tests; ++i) {
        if (isPalindrome_stringconvert(non_palindromes[i]) == 1) {
            cout << "STRINGCONVERT INVALID TEST FAILED on test " << i << endl;
        }
        if (isPalindrome_nostringconvert(non_palindromes[i]) == 1) {
            cout << "NOSTRINGCONVERT INVALID TEST FAILED on test " << i << endl;
        }
    }
}

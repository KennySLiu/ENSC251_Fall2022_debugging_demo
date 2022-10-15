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
    return false;
}

/*************/

bool isPalindrome_stringconvert(int input) {
    stringstream ss;
    ss << input;
    string input_str = ss.str();


    return false;
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

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <climits>
#include <gtest/gtest.h>
#define KENNY_DEBUGGING (0)

using namespace std;



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
/*************/
/*************/
/*************/

TEST(stringconvert, VALID_stringconvert_normal) {
	const int num_tests = 4;
	int valid_palindromes[num_tests] = {
		12321,
        92500529,
        235532,
        11
	};
    for (int i = 0; i < num_tests; ++i)
    {
        EXPECT_EQ(isPalindrome_stringconvert(valid_palindromes[i]), true);
    }
}
TEST(stringconvert, VALID_stringconvert_edgecases) {
	const int num_tests = 4;
	int valid_palindromes[num_tests] = {
		1,
        2,
        3,
        2147007412
	};
    for (int i = 0; i < num_tests; ++i)
    {
        EXPECT_EQ(isPalindrome_stringconvert(valid_palindromes[i]), true);
    }
}
TEST(stringconvert, INVALID_stringconvert_normal) {
	const int num_tests = 5;
	int valid_palindromes[num_tests] = {
        123,
        58767,
        2343,
        95911,
        102300
	};
    for (int i = 0; i < num_tests; ++i)
    {
        EXPECT_EQ(isPalindrome_stringconvert(valid_palindromes[i]), false);
    }
}
TEST(stringconvert, INVALID_stringconvert_edgecases) {
	const int num_tests = 5;
	int valid_palindromes[num_tests] = {
        -1,
        -2,
        -12321,
        INT_MAX,
        INT_MIN
	};
    for (int i = 0; i < num_tests; ++i)
    {
        EXPECT_EQ(isPalindrome_stringconvert(valid_palindromes[i]), false);
    }
}

/*************/
/*************/
/*************/
/*************/

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, no_leading_characters) {
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, long_repeating_leading_characters) {
	Password my_password;
	int actual = my_password.count_leading_characters("AAAAAAAAAAadmin");
	ASSERT_EQ(10, actual);
}

//checks if the password starts with "_"
TEST(PasswordTest, underscore_first) {
	Password my_password;
	int actual = my_password.count_leading_characters("_mememe");
	ASSERT_EQ(1, actual);
}

//checks if the password starts with "'"
TEST(PasswordTest, upostrophe_first) {
	Password my_password;
	int actual = my_password.count_leading_characters("' OR '1'='1");
	ASSERT_EQ(1, actual);
}

//checks if password starts with a space  
TEST(PasswordTest, space_first) {
	Password my_password;
	int actual = my_password.count_leading_characters(" password");
	ASSERT_EQ(1, actual);
}

//checks min length pass  
TEST(PasswordTest, min_case) {
	Password my_password;
	bool actual = my_password.has_mixed_case("Aa");
	ASSERT_TRUE(actual);
}

//checks a pass with mixed case within 
TEST(PasswordTest, middle_case) {
	Password my_password;
	bool actual = my_password.has_mixed_case("passWord");
	ASSERT_TRUE(actual);
}

//all caps 
TEST(PasswordTest, all_upper) {
	Password my_password;
	bool actual = my_password.has_mixed_case("HEY");
	ASSERT_FALSE(actual);
}

//all lower 
TEST(PasswordTest, all_lower) {
	Password my_password;
	bool actual = my_password.has_mixed_case("hey");
	ASSERT_FALSE(actual);
}

//mixed symbols
TEST(PasswordTest, all_symbols) {
	Password my_password;
	bool actual = my_password.has_mixed_case("123!");
	ASSERT_FALSE(actual);
}


//empty pass
TEST(PasswordTest, empty_only) {
	Password my_password;
	bool actual = my_password.has_mixed_case("");
	ASSERT_FALSE(actual);
}

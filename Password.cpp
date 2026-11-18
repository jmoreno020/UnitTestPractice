#include "Password.h"
#include <string>
#include <cctype>

using std::string;
using namespace std;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  //checks for an empty input ""
  if (phrase.empty()) {
    return 0;
  }
  int repetition = 1;
  int index = 0;
  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}

/*
  receives a string and returns whether it has both at least one upper-case
  letter and at least one lower-case letter
*/
bool Password::has_mixed_case(string pass){
  //checks for empty input ""
  if (pass.empty()) {
    return 0;
  }
  //bool for lower case
  //bool for upper case
  bool lower = false;
  bool upper = false;
  //only pass if both are true

  //iterate through chars, break early if both found
  for (size_t index = 0; index < pass.length(); index++) {
     //reassign teh current char
     unsigned char current = static_cast<unsigned char>(pass[index]);
     //check for lower
     if (islower(current)) {
       lower = true;
     //check for upper
     } else if (isupper(current)) {
       upper = true;
     }

     if (upper && lower) {
       return true;
     }
  }
        //didnt find both, return fals
	return false;
}

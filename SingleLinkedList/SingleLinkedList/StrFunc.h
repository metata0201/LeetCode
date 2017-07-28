#pragma once
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;
/*500. Keyboard Row
*Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard
*like the image below.
*
*Example 1:
*Input : ["Hello", "Alaska", "Dad", "Peace"]
*Output: ["Alaska", "Dad"]
*Note :
*    You may use one character in the keyboard more than once.
*    You may assume the input string will only contain letters of alphabet.
*/
vector<string> findWords(vector<string>& words);
vector<string> findWords_Special(vector<string>& words);
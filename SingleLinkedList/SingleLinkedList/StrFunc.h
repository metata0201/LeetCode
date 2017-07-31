#pragma once
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <algorithm>

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

/*557. Reverse Words in a String III
*Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
*
*Example 1:
*Input : "Let's take LeetCode contest"
*Output: "s'teL ekat edoCteeL tsetnoc"
*Note  : In the string, each word is separated by single space and there will not be any extra space in the string.
*/
string reverseWords(string s);
string reverseWords_Special(string s);
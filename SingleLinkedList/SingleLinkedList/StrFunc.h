#pragma once
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <algorithm>
#include <sstream>

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

/*344. Reverse String
*Write a function that takes a string as input and returns the string reversed.
*
*Example:
*Given s = "hello", return "olleh".
*/
string reverseString_Basic(string s);
string reverseString_Library(string s);

/*412. Fizz Buzz
*Write a program that outputs the string representation of numbers from 1 to n.
*
*But for multiples of three it should output ¡°Fizz¡± instead of the number and for the multiples of five output ¡°Buzz¡±.
*For numbers which are multiples of both three and five output ¡°FizzBuzz¡±.
*
*Example:n = 15,
*Return :["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
*/
vector<string> fizzBuzz(int n);
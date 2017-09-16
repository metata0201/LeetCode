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

/*537. Complex Number Multiplication
*Given two strings representing two complex numbers.
*
*You need to return a string representing their multiplication.Note i2 = -1 according to the definition.
*
*Example 1:
*Input : "1+1i", "1+1i";    Output: "0+2i"
*Explanation : (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0 + 2i.
*
*Example 2 :
*Input : "1+-1i", "1+-1i";   Output : "0+-2i"
*Explanation : (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0 + -2i.
*Note :
*    The input strings will not have extra blank.
*    The input strings will be given in the form of a + bi, where the integer a and b will both belong to
*    the range of[-100, 100].And the output should be also in this form.
*/
string complexNumberMultiply(string a, string b);
string complexNumberMultiply_Special(string a, string b);

/*521. Longest Uncommon Subsequence I
Given a group of two strings, you need to find the longest uncommon subsequence of this group of two strings.The longest uncommon subsequence
is defined as the longest subsequence of one of these strings and this subsequence should not be any subsequence of the other strings.

A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements.
Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.

The input will be two strings, and the output needs to be the length of the longest uncommon subsequence.If the longest uncommon subsequence doesn't exist, return -1.

Example 1:
Input : "aba", "cdc"
Output: 3
Explanation : The longest uncommon subsequence is "aba" (or "cdc"),
because "aba" is a subsequence of "aba",
but not a subsequence of any other strings in the group of two strings.
Note :
Both strings' lengths will not exceed 100.
Only letters from a ~z will appear in input strings.
*/
int findLUSlength(string a, string b);

/*67. Add Binary
Given two binary strings, return their sum(also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/
string addBinary(string a, string b);
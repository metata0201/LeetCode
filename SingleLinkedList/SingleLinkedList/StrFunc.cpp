#include "StrFunc.h"

vector<string> findWords(vector<string>& words)
{
    unordered_map<char, int> KeyboardTable = { { 'Q', 1 }, { 'W', 1 }, { 'E', 1 }, { 'R', 1 }, { 'T', 1 }, { 'Y', 1 }, { 'U', 1 }, { 'I', 1 }, { 'O', 1 }, { 'P', 1 },
                                               { 'q', 1 }, { 'w', 1 }, { 'e', 1 }, { 'r', 1 }, { 't', 1 }, { 'y', 1 }, { 'u', 1 }, { 'i', 1 }, { 'o', 1 }, { 'p', 1 },
                                               { 'A', 2 }, { 'S', 2 }, { 'D', 2 }, { 'F', 2 }, { 'G', 2 }, { 'H', 2 }, { 'J', 2 }, { 'K', 2 }, { 'L', 2 },
                                               { 'a', 2 }, { 's', 2 }, { 'd', 2 }, { 'f', 2 }, { 'g', 2 }, { 'h', 2 }, { 'j', 2 }, { 'k', 2 }, { 'l', 2 },
                                               { 'Z', 3 }, { 'X', 3 }, { 'C', 3 }, { 'V', 3 }, { 'B', 3 }, { 'N', 3 }, { 'M', 3 },
                                               { 'z', 3 }, { 'x', 3 }, { 'c', 3 }, { 'v', 3 }, { 'b', 3 }, { 'n', 3 }, { 'm', 3 } };
    vector<string> ret;
    int i, j;
    for (i = 0; i < words.size(); i++)
    {
        for (j = 1; j < words[i].size(); j++)
        {
            if (KeyboardTable[words[i][j]] != KeyboardTable[words[i][0]])
                break;
        }
        if (j == words[i].size())
        {
            ret.push_back(words[i]);
        }
    }
    return ret;
}

vector<string> findWords_Special(vector<string>& words)
{
    vector<string> ret;
    int r1, r2, r3;
    for (int i = 0; i < words.size(); i++)
    {
        r1 = words[i].find_first_of("QWERTYUIOPqwertyuiop") == string::npos ? 0 : 1;
        r2 = words[i].find_first_of("ASDFGHJKLasdfghjkl") == string::npos ? 0 : 1;
        r3 = words[i].find_first_of("ZXCVBNMzxcvbnm") == string::npos ? 0 : 1;
        if (r1+r2+r3 == 1)  // Ex:r1=1,r2=0,r3=0 meet the condition, it means the word don't contain any character in both "ASDFGHJKLasdfghjkl" and "ZXCVBNMzxcvbnm",so it must only contain character from "QWERTYUIOPqwertyuiop".
        {
            ret.push_back(words[i]);
        }
    }
    return ret;
}

string reverseWords(string s)
{
    string ret, word;
    stack<char> S;

    // Push each characters into the stack
    for (int i = 0; i < s.size(); i++)
    {
        S.push(s[i]);
    }

    while (!S.empty())
    {
        if (S.top() != ' ') { word.push_back(S.top()); }    // compose every reversed word
        else
        {
            word.insert(word.begin(), ' ');
            ret.insert(0, word);
            word.clear();
        }
        S.pop();
    }
    ret.insert(0, word);    // Insert the last word

    return ret;
}

string reverseWords_Special(string s)
{
    int i, j;
    for (i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')
        {
            j = i;
            while (j < s.size() && s[j] != ' ') { j++; }
            // 'i' is the start of a word, j is the index of space character the following the last character of the word.
            reverse(s.begin() + i, s.begin() + j);
            i = j;
        }
    }
    return s;
}

string reverseString_Basic(string s)
{
    for (int i = 0, j=s.size()-1; i < j; i++, j--)
    {
        swap(s[i], s[j]);
    }
    return s;
}

string reverseString_Library(string s)
{
    reverse(s.begin(), s.end());
    return s;
}

vector<string> fizzBuzz(int n)
{
    vector<string> ret;
    for (int i = 1; i <= n; i++)
    {
        if (i % 15 == 0)
        {
            ret.push_back("FizzBuzz");
        }
        else if (i % 5 == 0)
        {
            ret.push_back("Buzz");
        }
        else if (i % 3 == 0)
        {
            ret.push_back("Fizz");
        }
        else
        {
            ret.push_back(to_string(i));
        }
    }
    return ret;
}

string complexNumberMultiply(string a, string b)
{
    int realA, realB, imagA, imagB, index;

    index = a.find('+');
    realA = stoi(a.substr(0, index), nullptr, 10);
    imagA = stoi(a.substr(index + 1, a.size() - index - 2), nullptr, 10);

    index = b.find('+');
    realB = stoi(b.substr(0, index), nullptr, 10);
    imagB = stoi(b.substr(index + 1, b.size() - index - 2), nullptr, 10);

    return to_string(realA*realB - imagA*imagB) + "+" + to_string(realA*imagB + realB*imagA) + "i";
}

string complexNumberMultiply_Special(string a, string b)
{
    int ra, ia, rb, ib;
    char c;
    stringstream streamA(a), streamB(b), streamC;
    streamA >> ra >> c >> ia >> c;  // if a = 1+-1i,then ra=1, c='+', ia=-1, c='i'
    streamB >> rb >> c >> ib >> c;
    streamC << ra*rb - ia*ib << "+" << ra*ib + rb*ia << "i";
    return streamC.str();
}

int findLUSlength(string a, string b)
{
    if (a.compare(b) != 0)
    {
        return max(a.length(), b.length());
    }
    else
    {
        return -1;  // string a and b are equal
    }
}

string addBinary(string a, string b)
{
    string res;
    // Add binary string from end to start
    int carry = 0, i = a.size() - 1, j = b.size() - 1;
    for (; i >= 0 || j >= 0; i--,j--)
    {
        int valA = (i >= 0) ? (a[i] - '0') : 0;
        int valB = (j >= 0) ? (b[j] - '0') : 0;
        res.insert(0, 1, (valA + valB + carry) % 2 + '0');
        carry = (valA + valB + carry) / 2;
    }
    if (carry > 0)
    {
        res.insert(0, 1, '1');
    }

    return res;
}

string countAndSay(int n)
{
    string res = "1";
    for (int i = 2; i <= n; i++)
    {
        string cur = "";
        for (int j = 0; j < res.size(); j++)
        {
            int count = 1;
            while (j + 1 < res.size() && res[j] == res[j + 1])
            {
                count++;
                j++;
            }
            cur = cur + to_string(count) + res[j];
        }
        res = cur;
    }

    return res;
}

int countSegments(string s)
{
    if (s.empty())
        return 0;

    int segments = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ' && (s[i + 1] == ' ' || s[i + 1] == '\0'))
        {
            segments++;
        }
    }
    return segments;
}

bool detectCapitalUse(string word)
{
    bool firstUpper = false;    // Mark the first letter is uppercase or not
    int nUppers = 0;            // The number of uppercase letters
    for (int i = 0; i < word.size(); i++)
    {
        if (word[i]>='A' && word[i]<='Z')
        {
            if (i == 0)
            {
                firstUpper = true;
            }
            nUppers++;
        }
    }

    return (nUppers == word.size()) || (nUppers == 0) || (firstUpper&&nUppers == 1);
}

bool checkRecord(string s)
{
    int countA = 0, maxL = 0, countL = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'A')
        {
            countA++;
        }

        if (s[i] == 'L')
        {
            countL++;
            if (maxL < countL)
            {
                maxL = countL;
            }
        }
        else
        {
            countL = 0;
        }
    }

    return (countA <= 1) && (maxL <= 2);
}

bool checkRecord_Special(string s)
{
    int a = 0, l = 0;
    for (int i = 0; i<s.size(); i++)
    {
        if (s[i] == 'A') a++;
        if (s[i] == 'L') l++;
        else l = 0;
        if (a >= 2 || l>2) return false;
    }
    return true;
}
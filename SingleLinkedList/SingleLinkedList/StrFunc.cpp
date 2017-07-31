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
            reverse(s.begin() + i, s.begin() + j);
            i = j;
        }
    }
    return s;
}
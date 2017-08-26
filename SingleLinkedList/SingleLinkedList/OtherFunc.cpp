#include "OtherFunc.h"
#include <iostream>

using namespace std;

int hammingDistance(int x, int y)
{
    int cnt = 0, tmp = x ^ y;
    while (tmp)
    {
        tmp = tmp & (tmp - 1);  // Remove the least significant '1' bit.
        cnt++;
    }
    return cnt;
}

int findComplement(int num)
{
    int cnt = 0, ret = 0;
    while (num)
    {
        ret += ((num & 0x1) ^ 0x1) << cnt;
        num = num >> 1;
        cnt++;
    }
    return ret;
}

int findComplement_Special(int num)
{
    // ((unsigned)~0) >> 1 == 01111111111111111111111111111111
    //             ~0 >> 1 == 11111111111111111111111111111111
    unsigned int mask = ~0;
    while (num & mask)
    {
        mask = mask << 1;
    }
    return (~num) & (~mask);
}

bool judgeSquareSum(int c)
{
    double b;
    for (long a = 0; a*a <= c; a++) // 'a' must be long data type,otherwise when a*a is larger than 2147483646,it will be a dead 'for loop'.
    {
        b = sqrt(c - a*a);
        if (b == (int)b)    // Judge whether 'sqrt(c - a*a)' is a real integer.
            return true;
    }
    return false;
}

// Dynamic Programming:i&(i-1) drops the lowest '1' bit. For example: i = 14, its binary representation is 1110, so i-1 is 1101, i&(i-1) = 1100,
// the number of "1" in its binary representation decrease one, so ret[i] = ret[i&(i-1)] + 1.
vector<int> countBits(int num)
{
    if (num < 0)
    {
        cout << "The input number can not be a negative integer!" << endl;
    }

    vector<int> ret(num + 1, 0);
    for (int i = 1; i <= num; i++)
    {
        ret[i] = ret[i & (i - 1)] + 1;
    }
    return ret;
}
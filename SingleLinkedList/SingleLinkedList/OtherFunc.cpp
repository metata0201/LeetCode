#include "OtherFunc.h"

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
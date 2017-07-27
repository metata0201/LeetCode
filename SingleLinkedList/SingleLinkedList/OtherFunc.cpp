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
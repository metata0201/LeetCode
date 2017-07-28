#include "ArrayFunc.h"

int maximumGap(vector<int>& nums)
{
    if (nums.size() < 2) { return 0; }

    queue<int> radix[16];
    int i, j, k, maxDiff = 0;
    for (k = 0; k < 8; k++)
    {
        // Put elements into their corresponding buckets
        for (i = 0; i < nums.size(); i++)
        {
            j = (nums[i] >> (4 * k)) & 0xF;
            radix[j].push(nums[i]);
        }

        // Collect elements from buckets
        i = 0;
        for (j = 0; j < 16; j++)
        {
            while (!radix[j].empty())
            {
                nums[i++] = radix[j].front();
                radix[j].pop();
            }
        }
    }

    // Find the max difference between the successive elements in its sorted form
    for (i = 1; i < nums.size(); i++)
    {
        if (maxDiff < nums[i] - nums[i - 1])
            maxDiff = nums[i] - nums[i - 1];
    }
}

int arrayPairSum(vector<int>& nums)
{
    int i, sum = 0;
    if (!nums.empty())
    {
        sort(nums.begin(), nums.end());
    }

    // Sequentially,every two number make a pair, sum up the first number of every pair will make out the result.
    for (i = 0; i < nums.size(); i += 2)
    {
        sum += nums[i];
    }
    return sum;
}

// Using bucket sort since we know the range of the integers are from -10000 - 10000
int arrayPairSum_Special(vector<int>& nums)
{
    // Bucket sort
    vector<int> buckets(20001, 0);
    for (int i = 0; i < nums.size(); i++)
    {
        buckets[nums[i] + 10000]++; // The number of times 'nums[i]' occur
    }

    int k = 0, cnt = 0, sum = 0;
    while (cnt < nums.size())
    {
        if (buckets[k] == 0) { k++; }
        else
        {
            if ((cnt & 0x1) == 0)  // 'cnt' must be a even number
            {
                sum += k - 10000;
            }
            buckets[k]--;
            cnt++;
        }
    }

    return sum;
}
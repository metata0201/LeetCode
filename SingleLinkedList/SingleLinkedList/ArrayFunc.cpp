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

vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c)
{
    int i, j, k = 0, cnt = 0;

    // calculate the number of elements in the two-dimensional array.
    for (i = 0; i < nums.size(); i++) { cnt += nums[i].size(); }

    if (cnt != r*c) { return nums; }

    // Initialization
    vector<vector<int>> ret(r);

    // Reshape the matrix
    cnt = 0;
    for (i = 0; i < nums.size(); i++)
    {
        for (j = 0; j < nums[i].size(); j++)
        {
            ret[k].push_back(nums[i][j]);
            if (++cnt % c == 0) { k++; }
        }
    }
    return ret;
}

vector<vector<int>> matrixReshape_Special(vector<vector<int>>& nums, int r, int c)
{
    int m = nums.size(), n = nums[0].size();
    if (r*c != m*n) { return nums; }

    // Initialization
    vector<vector<int>> ret(r, vector<int>(c, 0));

    // Reshape
    for (int i = 0; i < m*n; i++)
    {
        ret[i/c][i%c] = nums[i/n][i%n]; // Row index = i / Columns, column index = i % Columns
    }
    return ret;
}

int distributeCandies(vector<int>& candies)
{
    vector<int> buckets(200001, 0);
    for (int i = 0; i < candies.size(); i++)
    {
        buckets[candies[i] + 100000]++;
    }

    // Count how many kinds of candies
    int kinds = 0;
    for (int i = 0; i < buckets.size(); i++)
    {
        if (buckets[i] > 0) { kinds++; }
    }

    if ((candies.size() >> 1) <= kinds)
        return candies.size() >> 1;
    else
        return kinds;
}

int distributeCandies_Special(vector<int>& candies)
{
    unordered_set<int> kinds(candies.begin(), candies.end()); // unordered_set range constructor
    return min(kinds.size(), candies.size() / 2);   // Distribute these candies equally
}

int countBattleships(vector<vector<char>>& board)
{
    int row = board.size(), col = board[0].size(), cnt = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (board[i][j] == 'X')
            {
                // Count the item whose up neighbor and left neighbor are '.' as valid battleships
                if ((i == 0 || board[i - 1][j] == '.') && (j == 0 || board[i][j - 1] == '.'))
                    cnt++;
            }
        }
    }
    return cnt;
}

// Bitwise operation
int singleNumber(vector<int>& nums)
{
    int single = nums.front();
    for (int i = 1; i < nums.size(); i++)
    {
        single ^= nums[i];  // XOR trick:A XOR A = 0
    }
    return single;
}

int findMaxConsecutiveOnes(vector<int>& nums)
{
    int maxCount = 0, cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            cnt = 0;    // cnt represent the number of consecutive 1s
        }
        else
        {
            cnt++;      // increase
            maxCount = max(maxCount, cnt);
        }
    }
    return maxCount;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    if (nums1.empty() && nums2.empty())
        return 0;

    vector<int> nums(nums1.size() + nums2.size(), 0);
    int i = 0, j = 0, index = 0;
    // Merge the two sorted array
    while (i<nums1.size() && j<nums2.size())
    {
        if (nums1[i] <= nums2[j])
        {
            nums[index++] = nums1[i++];
        }
        else
        {
            nums[index++] = nums2[j++];
        }
    }
    while (i < nums1.size())    // Copy the left elements in nums1
    {
        nums[index++] = nums1[i++];
    }
    while (j < nums2.size())    // Copy the left elements in nums2
    {
        nums[index++] = nums2[j++];
    }

    index = (nums.size() - 1) / 2;
    if (nums.size() % 2 != 0)
        return nums[index];
    else
        return (double)(nums[index] + nums[index + 1]) / 2;
}

vector<int> findDisappearedNumbers(vector<int>& nums)
{
    vector<int> res, table(nums.size(), 0);

    // Mark the appeared numbers
    for (int i = 0; i<nums.size(); i++)
    {
        table[nums[i] - 1]++;
    }

    // Find disappeared numbers
    for (int i = 0; i<table.size(); i++)
    {
        if (table[i] == 0)
        {
            res.push_back(i + 1);
        }
    }

    return res;
}

vector<int> findDisappearedNumbers_Special(vector<int>& nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int index = abs(nums[i]) - 1;   // The appeared integer's corresponding index
        if (nums[index] > 0)    // Using -nums[index] to mark integer(index+1) as appeared
        {
            nums[index] = -nums[index];
        }
    }

    vector<int> res;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)        // nums[i]>0 means integer(i+1) disappeared
        {
            res.push_back(i + 1);
        }
    }

    return res;
}
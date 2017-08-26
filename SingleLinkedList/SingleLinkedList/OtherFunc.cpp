#include "OtherFunc.h"
#include <iostream>
#include <stack>
#include <unordered_map>

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

bool judgeCircle(string moves)
{
    // Original position
    int x = 0, y = 0;

    // Calculate the robot's position by the move sequence
    for (int i = 0; i < moves.size(); i++)
    {
        switch (moves[i])
        {
        case 'R': x++; break;
        case 'L': x--; break;
        case 'U': y++; break;
        case 'D': y--; break;
        default:
            cout << "Invalid move character!" << endl;
            break;
        }
    }

    return (x == 0 && y == 0);
}

int islandPerimeter(vector<vector<int>>& grid)
{
    int row = grid.size(), col = grid[0].size(), perimeter = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            // Land cell whose up,down,left,right edge connected with water cell are counted for perimeter
            if (grid[i][j] == 1)
            {
                if (i == 0 || grid[i - 1][j] == 0)          // Up
                    perimeter++;
                if (i == row - 1 || grid[i + 1][j] == 0)    // Down
                    perimeter++;
                if (j == 0 || grid[i][j - 1] == 0)          // Left
                    perimeter++;
                if (j == col - 1 || grid[i][j + 1] == 0)    // Right
                    perimeter++;
            }
        }
    }

    return perimeter;
}

vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums)
{
    vector<int> ret(findNums.size(), -1);
    unordered_map<int, int> hashTable;
    int i, index;

    // Initialize the hash table
    for (i = 0; i < nums.size(); i++)
    {
        hashTable[nums[i]] = i;
    }

    // Find findNums' elements in the corresponding places of nums,then scan from the place to find the fist greater number in nums
    for (i = 0; i < findNums.size(); i++)
    {
        index = hashTable[findNums[i]];
        while (index < nums.size())
        {
            if (nums[index] > findNums[i])
            {
                ret[i] = nums[index];
                break;
            }
            index++;
        }
    }

    return ret;
}

vector<int> nextGreaterElement_Special(vector<int>& findNums, vector<int>& nums)
{
    stack<int> s;
    unordered_map<int, int> table;
    // Key:element in nums, Mapped value:element's first greater number in nums
    for (int n : nums)
    {
        while (s.size() && s.top() < n)
        {
            table[s.top()] = n;
            s.pop();
        }
        s.push(n);
    }

    vector<int> ans;
    for (int n : findNums)
    {
        ans.push_back(table.count(n) ? table[n] : -1);
    }
    return ans;
}
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
/*164. Maximum Gap
*Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
*
*Try to solve it in linear time / space.
*Return 0 if the array contains less than 2 elements.
*You may assume all elements in the array are non - negative integers and fit in the 32 - bit signed integer range.
*/
int maximumGap(vector<int>& nums);

/*561. Array Partition I
*Given an array of 2n integers, your task is to group these integers into n pairs of integer, say(a1, b1),
*(a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.
*Example 1:
*Input : [1, 4, 3, 2]
*Output: 4
*Explanation : n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).
*Note :
*      n is a positive integer, which is in the range of[1, 10000].
*      All the integers in the array will be in the range of[-10000, 10000].
*/
int arrayPairSum(vector<int>& nums);
int arrayPairSum_Special(vector<int>& nums);
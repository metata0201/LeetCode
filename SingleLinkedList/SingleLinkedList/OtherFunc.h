#include <cmath>
#include <vector>

using namespace std;
/*461. Hamming Distance
*The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
*
*Given two integers x and y, calculate the Hamming distance.
*Note:
*0 ¡Ü x, y < 2^31.
*Example :
*    Input : x = 1, y = 4
*    Output: 2
*    Explanation:        1   (0 0 0 1)
*                        4   (0 1 0 0)
*                               ?   ?
*    The above arrows point to positions where the corresponding bits are different.
*/
int hammingDistance(int x, int y);

/*476. Number Complement
*Given a positive integer, output its complement number.The complement strategy is to flip the bits of its binary representation.
*
*Note:
*The given integer is guaranteed to fit within the range of a 32 - bit signed integer.
*You could assume no leading zero bit in the integer¡¯s binary representation.
*Example 1 :
*Input : 5 (101)
*Output: 2 (010)
*
*Example 2 :
*Input : 1 (1)
*Output: 0 (0)
*/
int findComplement(int num);
int findComplement_Special(int num);

/*633. Sum of Square Numbers
Given a non - negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.

Example 1:
    Input : 5
    Output: True
    Explanation : 1 * 1 + 2 * 2 = 5
Example 2 :
    Input : 3
    Output : False
*/
bool judgeSquareSum(int c);

/*338. Counting Bits
Given a non negative integer number num.For every numbers i in the range 0 ¡Ü i ¡Ü num calculate the number of 1's in their binary representation and return them as an array.

Example:For num = 5 you should return[0, 1, 1, 2, 1, 2].

Follow up :
    It is very easy to come up with a solution with run time O(n*sizeof(integer)).But can you do it in linear time O(n) / possibly in a single pass ?
    Space complexity should be O(n).
    Can you do it like a boss ? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
*/
vector<int> countBits(int num);

/*657. Judge Route Circle
Initially, there is a Robot at position(0, 0).Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to the original place.

The move sequence is represented by a string.And each move is represent by a character.The valid robot moves are R(Right), L(Left), U(Up) and D(down).
The output should be true or false representing whether the robot makes a circle.

Example 1:
    Input : "UD"
    Output : true
Example 2 :
    Input : "LL"
    Output : false
*/
bool judgeCircle(string moves);

/*463. Island Perimeter
You are given a map in form of a two - dimensional integer grid where 1 represents land and 0 represents water.Grid cells are connected horizontally / vertically(not diagonally).
The grid is completely surrounded by water, and there is exactly one island(i.e., one or more connected land cells).The island doesn't have "lakes" (water inside that isn't connected to the water around the island).
One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example:
    [[0, 1, 0, 0],
    [1, 1, 1, 0],
    [0, 1, 0, 0],
    [1, 1, 0, 0]]
Answer : 16
*/
int islandPerimeter(vector<vector<int>>& grid);

/*496. Next Greater Element I
You are given two arrays(without duplicates) nums1 and nums2 where nums1¡¯s elements are subset of nums2.Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2.If it does not exist, output - 1 for this number.

Example 1:
    Input : nums1 = [4, 1, 2], nums2 = [1, 3, 4, 2].
    Output : [-1, 3, -1]
Explanation :
    For number 4 in the first array, you cannot find the next greater number for it in the second array, so output - 1.
    For number 1 in the first array, the next greater number for it in the second array is 3.
    For number 2 in the first array, there is no next greater number for it in the second array, so output - 1.
Example 2 :
    Input : nums1 = [2, 4], nums2 = [1, 2, 3, 4].
    Output : [3, -1]
Explanation :
    For number 2 in the first array, the next greater number for it in the second array is 3.
    For number 4 in the first array, there is no next greater number for it in the second array, so output - 1.
Note :
    All elements in nums1 and nums2 are unique.
    The length of both nums1 and nums2 would not exceed 1000.
*/
vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums);
vector<int> nextGreaterElement_Special(vector<int>& findNums, vector<int>& nums);

/*292. Nim Game
You are playing the following Nim Game with your friend: There is a heap of stones on the table, each time one of you take turns to remove 1 to 3 stones.
The one who removes the last stone will be the winner.You will take the first turn to remove the stones.

Both of you are very clever and have optimal strategies for the game.Write a function to determine whether you can win the game given the number of stones in the heap.

For example, if there are 4 stones in the heap, then you will never win the game : no matter 1, 2, or 3 stones you remove, the last stone will always be removed by your friend.
*/
bool canWinNim(int n);
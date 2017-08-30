#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>

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

/*566. Reshape the Matrix
*In MATLAB, there is a very useful function called 'reshape', which can reshape a matrix into a new one with different size but keep its original data.
*You're given a matrix represented by a two-dimensional array, and two positive integers r and c representing the row number and column number of
*the wanted reshaped matrix, respectively.
*The reshaped matrix need to be filled with all the elements of the original matrix in the same row - traversing order as they were.
*If the 'reshape' operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.
*Example 1:
*Input :nums = [[1, 2], [3, 4]], r = 1, c = 4
*Output:[[1, 2, 3, 4]]
*Explanation : The row - traversing of nums is[1, 2, 3, 4].The new reshaped matrix is a 1 * 4 matrix, fill it row by row by using the previous list.
*
*Example 2 :
*Input :nums = [[1, 2], [3, 4]], r = 2, c = 4
*Output:[[1, 2], [3, 4]]
*Explanation : There is no way to reshape a 2 * 2 matrix to a 2 * 4 matrix.So output the original matrix.
*Note :
*      The height and width of the given matrix is in range[1, 100].
*      The given r and c are all positive.
*/
vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c);
vector<vector<int>> matrixReshape_Special(vector<vector<int>>& nums, int r, int c);

/*575. Distribute Candies
*Given an integer array with even length, where different numbers in this array represent different kinds of candies.Each number means one candy
*of the corresponding kind.You need to distribute these candies equally in number to brother and sister.Return the maximum number of kinds of
*candies the sister could gain.
*Example 1:
*Input : candies = [1, 1, 2, 2, 3, 3]
*Output: 3
*Explanation: There are three different kinds of candies(1, 2 and 3), and two candies for each kind.
*             Optimal distribution : The sister has candies[1, 2, 3] and the brother has candies[1, 2, 3], too.
*             The sister has three different kinds of candies.
*Example 2 :
*Input : candies = [1, 1, 2, 3]
*Output: 2
*Explanation : For example, the sister has candies[2, 3] and the brother has candies[1, 1].
*              The sister has two different kinds of candies, the brother has only one kind of candies.
*Note :
*      The length of the given array is in range[2, 10, 000], and will be even.
*      The number in given array is in range[-100, 000, 100, 000].
*/
int distributeCandies(vector<int>& candies);
int distributeCandies_Special(vector<int>& candies);

/*419. Battleships in a Board
Given an 2D board, count how many battleships are in it.The battleships are represented with 'X's, empty slots are represented with '.'s.You may assume the following rules :
    You receive a valid board, made of only battleships or empty slots.
    Battleships can only be placed horizontally or vertically.In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1(N rows, 1 column), where N can be of any size.
    At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.
Example :
        X..X
        ...X
        ...X
In the above board there are 2 battleships.
Invalid Example :
        ...X
        XXXX
        ...X
This is an invalid board that you will not receive - as battleships will always have a cell separating between them.
Follow up :
    Could you do it in one - pass, using only O(1) extra memory and without modifying the value of the board ?
*/
int countBattleships(vector<vector<char>>& board);

/*136. Single Number
 Given an array of integers, every element appears twice except for one.Find that single one.

 Note:
 Your algorithm should have a linear runtime complexity.Could you implement it without using extra memory ?
 */
 int singleNumber(vector<int>& nums);

/*485. Max Consecutive Ones
Given a binary array, find the maximum number of consecutive 1s in this array.
Example 1:
    Input : [1, 1, 0, 1, 1, 1]
    Output: 3
Explanation:
    The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
Note:
    The input array will only contain 0 and 1.
    The length of input array is a positive integer and will not exceed 10, 000
*/
int findMaxConsecutiveOnes(vector<int>& nums);
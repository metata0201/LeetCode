#include <cmath>

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
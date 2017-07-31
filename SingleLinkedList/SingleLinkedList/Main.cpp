#include "SingleLinkedList.h"
#include "ListFunc.h"
#include "ArrayFunc.h"
#include "Heap.h"
#include "OtherFunc.h"
#include "StrFunc.h"
#include <iostream>
#include <thread>

using namespace std;

void main()
{
    string input("Let's take LeetCode contest");
    string output = reverseWords_Special(input);
    cout << output << endl;
    system("pause");
}
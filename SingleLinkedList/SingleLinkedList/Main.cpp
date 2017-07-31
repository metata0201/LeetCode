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
    vector<int> candies = { 1, 1, 2, 2, 3, 3 , 4, 5};
    int maxKinds = distributeCandies_Special(candies);
}
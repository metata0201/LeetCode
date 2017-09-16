#include "SingleLinkedList.h"
#include "ListFunc.h"
#include "ArrayFunc.h"
#include "Heap.h"
#include "OtherFunc.h"
#include "StrFunc.h"
#include <iostream>
#include <thread>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <locale>

using namespace std;


void main()
{
    vector<int> nums({ 4, 3, 2, 7, 8, 2, 3, 1 });
    vector<int> res = findDisappearedNumbers_Special(nums);
}
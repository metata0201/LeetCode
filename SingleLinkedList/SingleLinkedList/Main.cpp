#include "SingleLinkedList.h"
#include "ListFunc.h"
#include "ArrayFunc.h"
#include "Heap.h"
#include "OtherFunc.h"
#include "StrFunc.h"
#include <iostream>
#include <thread>
#include <unordered_map>

using namespace std;

void main()
{
    vector<int> nums1({ 4, 1, 2 }), nums2({ 1, 3, 4, 2 });
    vector<int> res = nextGreaterElement_Special(nums1, nums2);
}
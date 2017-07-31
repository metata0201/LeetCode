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
    vector<vector<int>> a = { { 1, 2 }, { 3, 4 } };
    vector<vector<int>> b = matrixReshape_Special(a, 1, 4);
}
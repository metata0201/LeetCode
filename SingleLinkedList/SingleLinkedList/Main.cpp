#include "SingleLinkedList.h"
#include "ListFunc.h"
#include "ArrayFunc.h"
#include "Heap.h"
#include "OtherFunc.h"
#include <iostream>

using namespace std;

void main()
{
    int x = 1, y = 4;
    int cnt = hammingDistance(x, y);
    cout << "Hamming distance between " << x << " and " << y << " is " << cnt << endl;
}
#include "SingleLinkedList.h"
#include "ListFunc.h"
#include "ArrayFunc.h"
#include "Heap.h"
#include <iostream>

using namespace std;

void main()
{
    int arr[10] = { 35, 33, 42, 10, 14, 19, 27, 44, 26, 31 };

    //MinHeap minHeap(arr, 10);
    //minHeap.print();
    //
    //cout << "The smallest item:" << minHeap.deleteMin() << endl;
    //minHeap.print();

    MaxHeap maxHeap(arr, 10);
    maxHeap.print();

    cout << "The largest item:" << maxHeap.deleteMax() << endl;
    maxHeap.print();
}
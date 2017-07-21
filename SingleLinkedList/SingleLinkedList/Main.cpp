#include "SingleLinkedList.h"
#include "ListFunc.h"
#include "ArrayFunc.h"
#include "Heap.h"
#include <iostream>

using namespace std;

void main()
{
    int arr[10] = { 35, 33, 42, 10, 14, 19, 27, 44, 26, 31 };

    // Heap sort
    MinHeap minHeap(arr, 10);
    minHeap.print();

    cout << "Heap sort:";
    for (int i = 0; i < 10; i++)
    {
        arr[i] = minHeap.deleteMin();
        cout << arr[i] << ' ';
    }
    cout << endl;
}
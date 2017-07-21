#include "Heap.h"
#include <iostream>

using namespace std;

MinHeap::MinHeap(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        insert(arr[i]);
    }
}

void MinHeap::insert(int val)
{
    heap.push_back(val);

    int i, j = heap.size() - 1;
    while (j > 0)
    {
        i = (j - 1) >> 1;
        if (val >= heap[i])
            break;
        heap[j] = heap[i];
        j = i;  // 'j' represent the inserted location of 'val'
    }
    heap[j] = val;
}

int MinHeap::deleteMin()
{
    if (heap.empty())
    {
        cout << "Empty heap can not be deleted!" << endl;
        return -1;
    }

    // Root node has the smallest value
    int ret = heap.front(), val = heap.back();
    heap.pop_back();

    // Maintain the min heap property
    if (!heap.empty())
    {
        int i = 0, j;
        for (j = 2 * i + 1; j < heap.size();)
        {
            if (j + 1 < heap.size())
            {
                if (heap[j] > heap[j + 1])
                    j++;
            }

            // 'j' points to the smaller child
            if (val <= heap[j]) { break; }

            heap[i] = heap[j];
            i = j;
            j = 2 * i + 1;
        }
        heap[i] = val;
    }

    return ret;
}

int MinHeap::getMin()
{
    if (heap.empty())
    {
        cout << "Min heap is empty!" << endl;
        return -1;
    }
    return heap.front();
}

void MinHeap::print()
{
    for (int i = 0; i < heap.size(); i++)
    {
        cout << heap[i] << ' ';
    }
    cout << endl;
}

MaxHeap::MaxHeap(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        insert(arr[i]);
    }
}

void MaxHeap::insert(int val)
{
    heap.push_back(val);

    int i, j = heap.size() - 1;
    while (j > 0)
    {
        i = (j - 1) >> 1;
        if (val <= heap[i])
            break;
        heap[j] = heap[i];
        j = i;
    }
    heap[j] = val;
}

int MaxHeap::deleteMax()
{
    if (heap.empty())
    {
        cout << "Empty max heap can not be deleted!" << endl;
        return -1;
    }

    // Root node has the largest value
    int ret = heap.front(), val = heap.back();
    heap.pop_back();

    // Maintain the max heap property
    if (!heap.empty())
    {
        int i = 0, j;
        for (j = (i << 1) + 1; j < heap.size();)
        {
            if (j + 1 < heap.size())
            {
                if (heap[j] < heap[j + 1])
                    j++;    // 'j' point to the larger chid
            }
            if (val >= heap[j]) { break; }

            heap[i] = heap[j];
            i = j;
            j = (i << 1) + 1;
        }
        heap[i] = val;
    }

    return ret;
}

int MaxHeap::getMax()
{
    if (heap.empty())
    {
        cout << "Max heap is empty!" << endl;
        return -1;
    }
    return heap.front();
}

void MaxHeap::print()
{
    for (int i = 0; i < heap.size(); i++)
    {
        cout << heap[i] << ' ';
    }
    cout << endl;
}
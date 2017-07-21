#pragma once

#include <vector>

using namespace std;

class MinHeap
{
public:
    MinHeap(int arr[], int size);
    void insert(int val);
    int deleteMin();
    int getMin();
    void print();

private:
    vector<int> heap;
};

class MaxHeap
{
public:
    MaxHeap(int arr[], int size);
    void insert(int val);
    int deleteMax();
    int getMax();
    void print();

private:
    vector<int> heap;
};
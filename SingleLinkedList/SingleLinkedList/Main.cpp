#include "SingleLinkedList.h"
#include "ListFunc.h"
#include "ArrayFunc.h"
#include <iostream>

using namespace std;

void main()
{
    int a[] = { 1, 5, 9, 12, 20 }, b[] = { 3, 6, 8 };
    vector<int> vectorA(20, 0), vectorB(b, b+3);
    int i, j;
    for (i = 0; i < 5; i++)
    {
        vectorA[i] = a[i];
    }

    cout << "vector A:";
    for (i = 0; i < 20; i++)
    {
        cout << vectorA[i] << " ";
    }
    cout << endl;

    cout << "vector B:";
    for (i = 0; i < 3; i++)
    {
        cout << vectorB[i] << " ";
    }
    cout << endl;

    merge(vectorA, 5, vectorB, 3);

    cout << "merged vector A:";
    for (i = 0; i < 20; i++)
    {
        cout << vectorA[i] << " ";
    }
    cout << endl;
}
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
    vector<vector<char>> board(2, vector<char>(2));
    board[0] = { '.', '.' };
    board[1] = { 'X', 'X' };
    int cnt = countBattleships(board);
}
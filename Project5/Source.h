#pragma once

#include <vector>
using namespace std;
void calc_next_tick(int m, int n, vector<vector<int>>& board);
void prepare_board(int m, int n, vector<pair<int, int>>live_cords, vector<vector<int>>& board);
void restore_board(int m, int n, vector<vector<int>>& board);
void print(vector<vector<int>>& board);
int getNeighbors(vector<vector<int>>& board, int i, int j);
int main();

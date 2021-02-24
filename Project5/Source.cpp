#include <iostream>
#include <map>
#include <vector>
#include "Source.h"
using namespace std;
void calc_next_tick(int m, int n, vector<vector<int>>& board)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int sum = getNeighbors(board, i, j);
			if (board[i][j] == 1)
			{
				if (sum<2)
				{
					board[i][j] = -1; //case 1
				}
				else if (sum>3)
				{
					board[i][j] = -1; //case 3
				}
			}
			else if (board[i][j] == 0)
			{
				if (sum == 3)
					board[i][j] = 2; //case 4
			}
		}
	}
}

void prepare_board(int m, int n, vector<pair<int, int>> live_cords, vector<vector<int>>& board)
{

	for (auto i : live_cords)
	{
		board[i.first][i.second] = 1;
	}
}

void restore_board(int m, int n, vector<vector<int>>& board)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == -1) board[i][j] = 0;
			if (board[i][j] == 2) board[i][j] = 1;
		}
	}
}

void print(vector<vector<int>>& board)
{
	for (auto &row : board)
	{
		for (auto &col : row)
			cout << col << " ";
		cout << endl;
	}
}

int getNeighbors(vector<vector<int>> &board,int i,int j)
{
	int sum = 0;

	/*for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {*/
			//sum = 0;
	if (i - 1 >= 0)
	{
		if (j - 1 >= 0)
			sum += (abs(board.at(i - 1).at(j - 1)) == 1 ? 1 : 0);
		sum += (abs(board.at(i - 1).at(j)) == 1 ? 1 : 0);
		if (j + 1 < board[i].size())
			sum += (abs(board.at(i - 1).at(j + 1)) == 1 ? 1 : 0);
	}
	if ((j - 1) >= 0)
		sum += (abs(board.at(i).at(j - 1)) == 1 ? 1 : 0);
	if (j + 1 < board[i].size())
		sum += (abs(board.at(i).at(j + 1)) == 1 ? 1 : 0);
	if (i + 1 < board.size())
	{
		if (j - 1 >= 0)
			sum += (abs(board.at(i + 1).at(j - 1)) == 1 ? 1 : 0);
		sum += (abs(board.at(i + 1).at(j)) == 1 ? 1 : 0);
		if (j + 1 < board[i].size())
			sum += (abs(board.at(i + 1).at(j + 1)) == 1 ? 1 : 0);
	}
	return sum;
}
int main()
{
	//cout << "Rishabh narula";
	char c;
	do {

		int m, n, test;
		vector<pair<int, int>> live_cords;
		vector<pair<int, int>> ans;
		cout << "Enter the size of matrix\n";
		cin >> m >> n;
		cout << "No of entries which are live\n";
		cin >> test;
		cout << "Enter the cords of live cell\n";
		vector<vector<int>> board(m, vector<int>(n, 0));
		for (int i = 0; i < test; i++)
		{
			int a, b;
			cin >> a >> b;
			live_cords.push_back(make_pair(a, b));
		}
		prepare_board(m, n, live_cords, board);
		//Calculate next tick
		calc_next_tick(m, n, board);
		//Update back Values for inplace
		restore_board(m, n, board);
		//print board
		//Uncomment this method to print the matrix

		//print(board);

		//Prepare vector of live cords of next tick
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				if (board[i][j] == 1)
					ans.push_back(make_pair(i, j));
		}
		//Print the ans vector of live values cords of next tick
		cout << "\nOUTPUT----\n";
		for (auto &row : ans)
		{
			cout << row.first << "," << row.second;
			cout << "\n";
		}
		cout << "\nPress y/Y for continuation";
		cin >> c;
	} while (c == 'y' || c == 'Y');
	return 0;
}


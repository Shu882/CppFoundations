//
// Created by Ethan Shu on 6/19/23.
//
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;
using std::abs;
using std::sort;

enum class State {kEmpty, kObstacle, kClosed, kPath,  kStart, kFinish};
// directional deltas
const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

vector<State> ParseLine(string line) {
	istringstream sline(line);
	int n;
	char c;
	vector<State> row;
	while (sline >> n >> c && c == ',') {
		if (n == 0) {
			row.push_back(State::kEmpty);
		} else {
			row.push_back(State::kObstacle);
		}
	}
	return row;
}

vector<vector<State> > ReadBoardFile(string path) {
	ifstream myfile (path);
	vector<vector<State> > board {};
	if (myfile) {
		string line;
		while (getline(myfile, line)) {
			vector<State> row = ParseLine(line);
			board.push_back(row);
		}
	}
	return board;
}
bool Compare(const vector<int> node1, const vector<int> node2){
	// compare two nodes to determine which has smaller f value
	return node1[2] + node1[3] > node2[2] + node2[3] ;
}

void CellSort(vector<vector<int>> *v){
	sort(v->begin(), v->end(), Compare);
}

int Heuristic(int x1, int y1, int x2, int y2){
	// computes the Manhattan distance to the goal
	return abs(x1-x2) + abs(y1-y2);
}

bool CheckValidCell(int x, int y, vector<vector<State> > &board){
	//ensures that the potential neighbor coordinates are on the grid and that the cell is open
	int r = board.size();
	int c = board[0].size();
	if (0 <= x && x < r && 0 <= y && y < c)
		return board[x][y] == State::kEmpty;
	return false;
}

void AddToOpen(int x, int y, int g, int h, vector<vector<int> > &open, vector<vector<State> > &board){
	// add nodes to the open vector and mark them as visited in the grid
	vector<int> node = {x, y, g, h};
	open.push_back(node);
	board[x][y] = State::kClosed;
}

void ExpandNeighbors(vector<int> &current, int goal[2], vector<vector<int>> &open, vector<vector<State> > &board){
	// loops through the current node's neighbors and calls appropriate functions to add neighbors to the open list
	int x = current[0];
	int y = current[1];
	int g = current[2];
	int potentialNeighbors[4][2] = {{x+1, y},{x-1, y},{x, y+1},{x, y-1}};
	int x2, y2, g2, h2;
	for (auto neighbor:potentialNeighbors){
		x2 = neighbor[0];
		y2 = neighbor[1];
		if (CheckValidCell(x2, y2, board)){
			g2 = g + 1;
			h2 = Heuristic(x2, y2, goal[0], goal[1]);
			AddToOpen(x2, y2, g2, h2, open, board);
		}
	}
}

std::vector<vector<State> > Search(std::vector<vector<State>> &board, int init[2], int goal[2]){
	// A* search function
	vector<vector<int> > open {};
	int x = init[0];
	int y = init[1];
	int g = 0;
	int h = Heuristic(x, y, goal[0], goal[1]);
	AddToOpen(x, y, g, h, open,board);
	while(!open.empty()){
		CellSort(&open);
		vector<int> current_node=open.back();
		open.pop_back();// why do we need to keep this one element but delete others?
		board[current_node[0]][current_node[1]] = State::kPath;

		//reached the goal
		if (current_node[0] == goal[0] && current_node[1] == goal[1]) {
			board[0][0] = State::kStart;
			board[goal[0]][goal[1]] = State::kFinish;
			return board;
		} else {
			//Expand Neighbors
			ExpandNeighbors(current_node, goal, open, board);
		}
	}
	// We've run out of new nodes to explore and haven't found a path.
	std::vector<vector<State> > solution{};
	cout << "No path found!" << endl;
	return solution;
}


string CellString(State cell) {
	switch(cell) {
		case State::kObstacle: return "⛰️   ";
		case State::kPath: return "🚗   ";
		case State::kStart: return "🚦   ";
		case State::kFinish: return "🏁   ";
		default: return "0   ";
	}
}

void PrintBoard(const vector<vector<State> > board) {
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			cout << CellString(board[i][j]);
		}
		cout << "\n";
	}
}

//#include "test.cpp"

int main() {
	int init[2]{0, 0};
	int goal[2]{4, 5};

	// get the initial board
	vector<vector<State>> board = ReadBoardFile("../board");
	cout << "Initial board:\n";
	PrintBoard(board);

	// find and print the solution
	auto solution = Search(board, init, goal);
	cout << "\nSolution board:\n";
	PrintBoard(solution);

	// Tests
//	TestHeuristic();
//	TestAddToOpen();
//	TestCompare();
//	TestSearch();
//	TestCheckValidCell();
//	TestExpandNeighbors();

	return 0;
}













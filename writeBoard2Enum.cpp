//
// Created by Ethan Shu on 6/17/23.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

enum class State {kEmpty, kObstacle};

vector<State> ParseLine(string line) {
	istringstream sline(line);
	int n;
	char c;
	vector<State> row;
	while (sline >> n >> c && c == ',') {
		if (n==0) row.push_back(State::kEmpty);
		else if (n==1) row.push_back(State::kObstacle);
	}
	return row;
}

vector<vector<State>> ReadBoardFile(string path) {
	ifstream myfile (path);
	vector<vector<State>> board{};
	if (myfile) {
		string line;
		while (getline(myfile, line)) {
			vector<State> row = ParseLine(line);
			board.push_back(row);
		}
	}
	return board;
}

// TODO: Create the CellString function here,
// using the following return strings:
// "⛰️   "
// "0   "

string CellString(State state){
	switch (state) {
		case State::kEmpty: return "0   ";
		case State::kObstacle: return "⛰️   ";
	}
}

void PrintBoard(const vector<vector<State>> board) {
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			cout << CellString(board[i][j]);
		}
		cout << "\n";
	}
}

int main() {
	auto board = ReadBoardFile("board");
	PrintBoard(board);
}
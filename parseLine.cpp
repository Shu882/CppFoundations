//
// Created by Ethan Shu on 6/17/23.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;
using std::istringstream;


void ParseLine(string &line, vector<int> &boardNums){
	istringstream strm(line);
	int n;
	char c;
	while (strm>>n>>c){
		boardNums.push_back(n);
	}
}

int main(){
	//read the file into an fstream
	ifstream file("board", ifstream::in);
	string line;
	vector<int> boardNums;

	if (file.is_open()) {
		while (std::getline(file,line)){
			ParseLine(line,boardNums);
		}
		file.close();
	}

	for (auto i:boardNums){
		cout << i << " ";
	}
	cout << endl;
	return 0;
}
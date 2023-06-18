//
// Created by Ethan Shu on 6/16/23.
//

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main(){

	vector<vector<int>> board = {{0, 1, 0, 0, 0, 0},
	                             {0, 1, 0, 0, 0, 0},
	                             {0, 1, 0, 0, 0, 0},
	                             {0, 1, 0, 0, 0, 0},
	                             {0, 0, 0, 0, 1, 0}};
	for (auto item:board){
		for (auto i:item){
			cout << i;
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}
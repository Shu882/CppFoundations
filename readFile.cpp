//
// Created by Ethan Shu on 6/17/23.
//

#include <fstream>
#include <iostream>
#include <string>

using std::endl;
using std::cout;
using std::string;
using std::ifstream;
//using ifstream::in;

void readPrintFile(ifstream &file){
	string s;
	while (file >> s){
		cout << s << " ";
	}
	cout << endl << "Read&Print done!" << endl;
}

int main(){
	ifstream file("readfile.txt", ifstream::in);

	if (file.is_open()) {
		readPrintFile(file);
		file.close();
	}
	return 0;
}
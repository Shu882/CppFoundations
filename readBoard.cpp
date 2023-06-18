//
// Created by Ethan Shu on 6/17/23.
//

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
//	while (file >> s){
//		cout << s << " ";
//	}

	// use getline function to read the file stream
	cout << "I'm gonna print the content now: \n";
	while (std::getline(file,s)){
		cout << s << endl;
	}
	cout << endl << "Read&Print done!" << endl;
}

int main(){
	ifstream file("board", ifstream::in);

	if (file.is_open()) {
		readPrintFile(file);
		file.close();
	}
	return 0;
}
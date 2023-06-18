//
// Created by Ethan Shu on 6/17/23.
//
#include <iostream>
#include <sstream>
#include <string>

using std::istringstream;
using std::string;
using std::cout;

int main ()
{
	string a("1 2 3");

	istringstream my_stream(a);

	int n;
	while(my_stream >> n){
		cout << n << "\n";
	}
	return 0;
}
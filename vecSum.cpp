//
// Created by Ethan Shu on 6/16/23.
//

#include <iostream>
#include <vector>

using std::cout;
using std:: vector;
using std::endl;

int vecSum(const vector<int> &v){
	int sum = 0;
	for(auto i:v){
		sum += i;
	}
	return sum;
}

int main(){
	vector v = {1, 2, 3, 4, 5, 6};
	cout << vecSum(v) << endl;
	return 0;
}
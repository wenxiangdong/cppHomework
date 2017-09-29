#include <iostream>
using namespace std;

int main(){

	int n;
	cin >> n;

	int order;
	for (order = 1; order*(order + 1) / 2 < n; order++){}
	//left--;
	//cout << order << endl;

	int gap = n - (order - 1)*order / 2;

	int left, right;
	
	if ((order & 1) == 0){
		left = gap;
		right = order + 1 - gap;
	}else{
		right = gap;
		left = order + 1 - gap;
	}

	cout << left << "/" << right;

	getchar();
	getchar();
	return 0;
}
#include <iostream>
using namespace std;

int main(){
	int x, y;
	long long result = 1;
	cin >> x >> y;


	if (x == 0){
		cout << 0;
	}
	else if (y == 0){
		cout << 1;
	}
	else if (y < 0){
		y = -y;
		for (int i = 0; i < y; i++){
			result *= x;
		}

		double result_2 = 1.0 / result;
		cout << result_2;
	}
	else{
		for (int i = 0; i < y; i++){
			result *= x;
		}
		cout << result;
	}
	return 0;
}


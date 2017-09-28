#include <iostream>
using namespace std;

int main(){
	int n;
	long long result;
	cin >> n;

	if (n == 0) result = 0;
	else if (n == 1) result = 1;
	else{
		long long f0 = 0;
		long long f1 = 1;
		for (int i = 1; i < n; i++){
			result = f0 + f1;
			f0 = f1;
			f1 = result;
		}
	}

	cout << result;
}
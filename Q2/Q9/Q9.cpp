#include <iostream>
using namespace std;

bool isPrime(int n){
	if (n == 1) return false;
	if (n == 2) return true;

	for (int i = 2; i*i <= n; i++){
		if (n%i == 0) return false;
	}

	return true;
}

int main(){

	int n, m;
	cin >> n >> m;
	long long sum = 0;

	for (; n <= m; n++){
		if (isPrime(n)){
			sum += n;
		}
	}

	cout << sum;
	//getchar();
	//getchar();

	return 0;
}
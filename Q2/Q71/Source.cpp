#include <iostream>
using namespace std;

int main(){
	
	long long n=INT_MAX;
	long long rN=0;
	
	int bit;
	cin >> n;

	if (n == 0) {
		cout << 0;
		return 0;
	}
	//cout << n << endl;
	while (n){
		bit = n %10;
		rN = rN * 10 + bit;
		n /= 10;
	}
	
	cout << rN;
	return 0;
}
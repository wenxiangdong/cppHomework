#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	long long int sum = 0;

	for (int i = 0; i < n; i++){
		long long int temp=0;
		scanf_s("%lld", &temp);
		while (temp >= 8){ temp >>= 1; }
		sum += temp;
	}
	cout << sum;
	return 0;
}
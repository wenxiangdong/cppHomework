#include <iostream>
using namespace std;

int main(){

	int n;
	cin >> n;

	int left, right;//�ֱ�Ϊ���ӷ�ĸ
	for (left = 1; left*(left + 1) / 2 <= n; left++){}
	left--;



	return 0;
}
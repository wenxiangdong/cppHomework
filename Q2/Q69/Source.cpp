#include <iostream>
using namespace std;

inline int max(int a, int b){ return a > b ? a : b; }

int longest(char *str, int len){ 
	int longestLength = 0;
	for (int i = 0; i < len; i++){
		int pre = i - 1;
		int next = i + 1;
		int lengthOdd = 1;
		int lengthEven = 0;
		int length = 0;
		if (str[i] == str[next]){//ż�����Ĵ�
			lengthEven = 2;
			next++;
			while (pre >= 0 && next < len)
			{
				if (str[pre--] == str[next++]) lengthEven += 2;
				else break;
			}
		}

		//�������Ĵ�
		pre = i - 1;
		next = i + 1;
		while (pre >= 0 && next < len)
		{
			if (str[pre--] == str[next++]) lengthOdd += 2;
			else break;
		}
		
		length = max(lengthEven, lengthOdd);
		longestLength = max(longestLength, length);
	}

	return longestLength;
}

char str[100];

int main(){
	int n;
	cin >> n >> str;
	if (n == 0) cout << 0;
	else if (n == 1) cout << 1;
	else{
		cout << longest(str, n);
	}
	return 0;
}
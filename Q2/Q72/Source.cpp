#include <iostream>
#include <string>
using namespace std;

int nums[1000];

int main(){
	string s;
	cin >> s;
	int len = s.size();
	for (int i = 0; i < len; i++){
		switch (s[i])
		{
		case 'I':
			nums[i] = 1;
			break;
		case 'X':
			nums[i] = 10;
			break;
		case 'C':
			nums[i] = 100;
			break;
		case 'M':
			nums[i] = 1000;
			break;
		case 'V':
			nums[i] = 5;
			break;
		case 'L':
			nums[i] = 50;
			break;
		case 'D':
			nums[i] = 500;
			break;
		}//switch end
	}//for end

	int sum = 0;
	for (int i = 0; i < len; i++){
		switch (nums[i])
		{
		case 1:
		case 10:
		case 100:
			if (i + 1 < len && nums[i] < nums[i + 1]) nums[i] = -nums[i];
			break;
		}
		sum += nums[i];
	}

	cout << sum;
	return 0;
}



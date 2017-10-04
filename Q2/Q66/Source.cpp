#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;

const int max = 101;
char groups[7][max];
char origin[max];


bool isPowOf2(int n){
	return !(n&(n - 1));
}

int main(){
	string s;

	cin >> s;

	stringstream ss;
	ss << s;
	char c = '#';
	int len = 1;
	while ((ss>>c))
	{
		for (; isPowOf2(len); len++){//2的幂次位上要放的是海明码
			origin[len] = '#';
		}
		origin[len] = c;
		len++;
	}

	for (int i = 1; i < len; i++){
		if (!isPowOf2(i)){
			int t = i;
			int haming = 0;
			while (t){//在这个循环内把当前位置不停地右移
				if ((t & 1) == 1){//二进制表示的某个位置上有  ‘1’
					int power = (int)pow(2, haming);
					if (origin[power] == '#'){
						origin[power] = origin[i];
					}
					else{
						origin[power] = ((origin[power] - '0') ^ (origin[i] - '0')) + '0';
					}
				}
				t >>= 1;
				haming++;
			}
		}
	}


	for (int i = 1; i < len; i++){
		putchar(origin[i]);
	}


	return 0;
}
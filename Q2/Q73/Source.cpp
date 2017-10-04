#include <iostream>
#include <string>
using namespace std;

char table[10][4] = { { 0 }, { 0 },{ 'a', 'b', 'c' }, { 'd', 'e', 'f' }, { 'g', 'h', 'i' }, { 'j', 'k', 'l' },
{'m', 'n', 'o'}, { 'p', 'q', 'r', 's' }, { 't', 'u', 'v' }, { 'w', 'x', 'y', 'z' } };
int len[10] = { 0, 0, 3, 3, 3, 3, 3, 4, 3, 4 };//这里用来记录上面的表每一项的长度，因为二维数组的第二维长度是根据最长的来确定的，例如上面的4

void re(string s, int index, string result){
	if (index == s.size()){
		cout << result << endl;
		return;
	}
	for (int i = 0; i < len[s[index]-'0']; i++){
		re(s, index + 1, result + table[s[index] - '0'][i]);
	}
}

int main(){

	string s;
	cin >> s;
	re(s, 0, "");

	return 0;
}

#include <iostream>
#include <string>
using namespace std;

char table[10][4] = { { 0 }, { 0 },{ 'a', 'b', 'c' }, { 'd', 'e', 'f' }, { 'g', 'h', 'i' }, { 'j', 'k', 'l' },
{'m', 'n', 'o'}, { 'p', 'q', 'r', 's' }, { 't', 'u', 'v' }, { 'w', 'x', 'y', 'z' } };
int len[10] = { 0, 0, 3, 3, 3, 3, 3, 4, 3, 4 };//����������¼����ı�ÿһ��ĳ��ȣ���Ϊ��ά����ĵڶ�ά�����Ǹ��������ȷ���ģ����������4

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

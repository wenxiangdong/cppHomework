#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//created by 文向东


const string add = "add";
const string sub = "sub";
const string mul = "mul";

int toInt(string a);
string to13(int n);

int main(){
	
	string cmd, a, b;

	cin >> cmd >> a >> b;
	if (cmd == add){
		cout << to13(toInt(a) + toInt(b));
	}
	else if (cmd==sub)
	{
		cout << to13(toInt(a) - toInt(b));
	}
	else if (cmd == mul)
	{
		cout << to13(toInt(a)*toInt(b));
	}
	return 0;
}

int toInt(string a){
	bool positive = true;
	if (a[0] == '-') positive = false;
	int result = 0;
	int bit = 0;
	int i = positive ? 0 : 1;
	for (; i < a.size(); i++){
		bit = (a[i] >= 'A') ? (a[i] - 'A' + 10) : (a[i] - '0');
		result = result * 13 + bit;
	}
	return positive?result:(-result);
}
string to13(int n){
	string result;
	bool positive = true;
	if (n == 0) return "0";
	else if (n < 0) {
		n = -n;
		positive = false;
	}
	while (n)
	{
		int bit = n % 13;
		result+=(bit>=10)?(bit-10+'A'):(bit+'0');
		n /= 13;
	}

	result+= (positive?"":"-");

	reverse(result.begin(), result.end());

	return result;	
}
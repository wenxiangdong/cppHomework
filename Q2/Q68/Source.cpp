#include <iostream>
#include <string>
using namespace std;

int main(){

	string s, cmd, param, param2;
	int numOfCmd = 0;
	cin >> numOfCmd;
	for (int i = 0; i < numOfCmd; i++){
		cin >> cmd;
		if (cmd == "append"){
			cin >> param;
			s += param;
		}
		else if (cmd == "reverse"){
			reverse(s.begin(), s.end());
		}
		else if (cmd == "replace"){
			cin >> param>>param2;
			int index = s.find(param[0]);
			s.replace(index, param.size(),param2);
		}
		else if (cmd == "changecase"){
			cin >> param;
			int gap = 0;
			char left = 'a';
			char right = 'z';
			if (param == "low"){
				gap = 32;
				left = 'A';
				right = 'Z';
			}
			else{
				gap = -32;
				
			}
			for (int i = 0; i < s.size(); i++){
				if (s[i] >= left && s[i] <= right){ s[i] += gap; }
			}
		}
		else if (cmd == "length"){
			cout << s.size()<<endl;
		}
		else if (cmd == "print"){
			cout << s<<endl;
		}
	}
	return 0;
}
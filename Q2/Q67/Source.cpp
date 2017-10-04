#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	getline(cin, s);

	int space = s.find_last_of(" ");
	if (space != -1){
		cout << s.size() - space-1;
	}
	else{
		cout<<s.size();
	}
	return 0;
}
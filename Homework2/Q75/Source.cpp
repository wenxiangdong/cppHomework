#include <iostream>
#include <string>
#include <sstream>
using namespace std;


string data[100000];
int len = 1;

void getInput();
void inOrder();
void inOrder(int i);

int main(){

	getInput();
	inOrder();

	return 0;
}


void getInput(){
	string s;
	getline(cin,s);

	stringstream ss(s);

	while (ss >> data[len])
	{
		++len;
	}

}

void inOrder(){
	inOrder(1);
}

void inOrder(int index){
	if (index >= len || data[index] == "null") return;
	else{
		inOrder(index * 2);
		cout << data[index] << " ";
		inOrder(index * 2 + 1);
	}
}


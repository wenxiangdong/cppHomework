#include <iostream>
#include <string>
using namespace std;


string nodes[10000];
int max = 0;

int main(){
	int index = 0;
	while (cin >> nodes[index++]){ max++; }


}

void inOrder(int n){
	if (n>=max || nodes[n] == "null") return;
	else{
		cout << nodes[n] << " ";
		inOrder(n * 2);
		inOrder(n * 2 + 1);
	}
}
#include <iostream>
#include <string>
#include <map>
using namespace std;
 

map<string,int> tree;
int len;
int dis = -1;


void func(int min, int max, int step);

int main(){
	cin >> len;

	for (int i = 1; i <= len; i++){
		string s;
		cin >> s;
		tree.insert(pair<string, int>(s, i));
	}

	string node1, node2;
	cin >> node1 >> node2;
	int index1 = tree[node1];
	int index2 = tree[node2];
	if (index1 == index2) dis = 0;
	else{
		//找出在上层的结点和在下层
		int min = index1 < index2 ? index1 : index2;
		int max = min == index1 ? index2 : index1;
		func(min, max, 0);
	}

	cout << dis;
	return 0;
}

//一个dfs
void func(int min, int max, int step){
	if (min == max) {
		dis = step;
		return;
	}
	else if (min > max) return;
	else{
		func(min * 2, max, step + 1);
		func(min * 2 + 1, max, step + 1);
	}
}
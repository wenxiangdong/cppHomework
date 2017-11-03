#include <iostream>
using namespace std;

int table[1000][1000];
int moves[2][2] = { { -1, 0 }, { -1, -1 } };
int n;
int min = INT_MAX;

//用dfs会超时
void dfs(int x, int y, int step,int sum){
	sum += table[x][y];
	if (step == n){
		if (sum < min) min = sum;
		return;
	}
	else{
		for (int i = 0; i < 2; i++){
			int xx = x + moves[i][0];
			int yy = y + moves[i][1];
			if (xx<1 || xx>step+1 || yy<1 || yy>step+1) return;
			else dfs(xx, yy, step + 1, sum);
		}
	}
}

int main(){

	//用贪心才不会超时
	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= i; j++){
			scanf_s("%d", &table[i][j]);
			if (i > 1){
				//从第二行开始，不停地累加
				int temp[2];
				for (int k = 0; k < 2; k++){
					int x = i + moves[k][0];
					int y = j + moves[k][1];
					if (x < 1 || x >= i || y < 1 || y >= i) temp[k] = INT_MAX;//将越界的累加值设为最大
					else temp[k] = table[i][j] + table[x][y];
				}
				table[i][j] = temp[0] < temp[1] ? temp[0] : temp[1];
			}
		}
	}

	for (int i = 1; i <= n; i++){
		if (table[n][i] < min) min = table[n][i];
	}

	cout << min;
	return 0;
}
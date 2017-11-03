#include <iostream>
using namespace std;

int a[1000][1000];
int b[1000][1000];

int step[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };//前进变换量
int gap[4] = { 1, 1,- 1, - 1 };//边界的变换量
int border[4];//边界


int main(){
	int m, n;
	scanf_s("%d%d", &m, &n);
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			scanf_s("%d", &a[i][j]);
		}
	}
	border[0] = 0;
	border[1] = 0;
	border[2] = n-1;
	border[3] = m-1;

	int index;
	scanf_s("%d", &index);
	int x = 0, y = 0, dir = 0;
	int xx = x, yy = y;
	int t = 0;
	while (index>0){
		xx = x;
		yy = y;
		while (index>0)
		{
			xx += step[dir][0];
			yy += step[dir][1];
			if (xx < border[1] || xx > border[3] || yy < border[0] || yy > border[2] ) break;
			x = xx;
			y = yy;
			index--;
		}
		dir = (dir + 1) % 4;
		border[dir] += gap[dir];
	}

	printf_s("%d", a[x][y]);

	return 0;
}
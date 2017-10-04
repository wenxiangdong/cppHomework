#include <iostream>
#include <string>
using namespace std;


struct Student
{
	string name;
	string id;
	string course;
	int score;
} students[100];

int main(){
	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++){
		cin >> students[i].name >> students[i].id >> students[i].course >> students[i].score;
	}
	int m = 0;
	cin >> m;
	string cmd, param;
	for (int i = 0; i < m; i++){
		cin >> cmd >> param;
		double average = 0;
		int sum = 0;
		int count = 0;
		if (cmd == "course"){
			for (int j = 0; j < n; j++){
				if (students[j].course == param){
					sum += students[j].score;
					count++;
				}
			}
		}
		else if (cmd == "student")
		{
			for (int j = 0; j < n; j++){
				if (students[j].name == param){
					sum += students[j].score;
					count++;
				}
			}
		}
		average = sum*1.0 / count;
		cout << param;
		printf(" %.2f\n", average);
	}
	return 0;
}

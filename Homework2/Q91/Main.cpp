#include <iostream>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

struct Student
{
	string id;
	map<string, int> grade;
	double average;
};

map<string, struct Student> students;
set<string> cources;

bool cmp(Student s1, Student s2){
	if (s1.average == s2.average){
		return s1.id > s2.id;
	}
	else return s1.average > s2.average;
}

int main(){
	int n;
	string name;
	string id;
	string course;
	int score;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> name >> id >> course >> score;
		cources.insert(course);
		if (!students.count(id)){
			Student s;
			s.id = id;
			s.grade[course] = score;
			students[id] = s;
		}
		else{
			students[id].grade[course] = score;
		}
	}

	int size = cources.size();
	int sum = 0;
	for (map<string, struct Student>::iterator itor = students.begin();
		itor != students.end();++itor){
		int temp = 0;
		for (map<string, int>::iterator it = itor->second.grade.begin();
			it != itor->second.grade.end(); ++it){
			temp += it->second;
		}
		itor->second.average = temp*1.0 / size;
		sum += temp;
	}

	size *= students.size();
	double average = sum*1.0 / size;

	Student low[100];
	int num = 0;
	for (map<string, struct Student>::iterator it = students.begin();
		it != students.end();++it){
		if (it->second.average < average) low[num++] = it->second;
	}

	sort(low, low + num, cmp);

	for (int i = 0; i < num; i++){
		cout << low[i].id << endl;
	}

	return 0;
}
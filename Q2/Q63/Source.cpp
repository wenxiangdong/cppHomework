#include <iostream>
#include <string>
#include <cmath>
using namespace std;


const string add = "add";
const string sub = "sub";
const string mul = "mul";
const string powCmd = "pow";
const string sqa = "sqa";
const string print = "print";

long long sqaFunc(long long a[], int len);
void addFunc(long long a[], int len,int n);
void subFunc(long long a[], int len,int n);
void mulFunc(long long a[], int len,int n);
void powFunc(long long a[], int len,int n);

long long a[100];

int main(){
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	string cmd;
	int numOfCmd = 0;
	int num;//²Ù×÷Êý
	cin >> numOfCmd;
	for (int i = 0; i < numOfCmd; i++)
	{
		cin >> cmd;
		if (cmd == sqa){
			cout << sqaFunc(a,n)<<endl;
		}
		else if (cmd == add){
			cin >> num;
			addFunc(a, n, num);
		}
		else if (cmd == sub)
		{
			cin >> num;
			subFunc(a, n, num);
		}
		else if (cmd == mul)
		{
			cin >> num;
			mulFunc(a, n, num);
		}
		else if (cmd == powCmd)
		{
			cin >> num;
			powFunc(a, n, num);
		}
		else if (cmd ==print)
		{
			for (int i = 0; i < n; i++){
				cout << a[i] ;
				if (i < n - 1) cout << " ";
			}
			cout << endl;
			
		}
	}
}

long long sqaFunc(long long a[], int len){
	long long result = 0;
	for (int i = 0; i < len; i++){
		result += a[i] * a[i];
	}
	return result;
}

void addFunc(long long a[], int len, int num){
	for (int i = 0; i < len; i++)
	{
		a[i] += num;
	}
}

void subFunc(long long a[], int len, int num){
	for (int i = 0; i < len; i++)
	{
		a[i] -= num;
	}
}

void mulFunc(long long a[], int len, int num){
	for (int i = 0; i < len; i++)
	{
		a[i] *= num;
	}
}

void powFunc(long long a[], int len, int num){
	for (int i = 0; i < len; i++)
	{
		a[i] = pow(a[i],num);
	}
}


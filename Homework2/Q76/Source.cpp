#include <iostream>
#include <string>
using namespace std;

struct node{
	int data;
	struct node *next;
};


struct node *a=nullptr;
struct node *b=nullptr;
struct node *res=nullptr;

node *getInput(node *list);

void add();

void printResult();


int main(){
	a=getInput(a);
	b=getInput(b);
	add();
	printResult();
	return 0;
}


node *getInput(node *list){
	string s;
	cin >> s;
	for (string::iterator it = s.begin(); it != s.end(); ++it){
		switch (*it)
		{
		case 'n':
			return list;
		case '>':
			break;
		default:
			node *p = (node *)(malloc(sizeof(struct node)));
			p->data = (*it) - '0';
			p->next = list;
			list = p;
			break;
		}
	}
	return list;
}

void add(){
	int carry = 0;
	while (a != nullptr && b != nullptr){
		node *p = (node *)(malloc(sizeof(struct node)));
		int sum = a->data + b->data + carry;
		p->data = sum % 10;
		carry = sum / 10;
		p->next = res;
		res = p;

		a = a->next;
		b = b->next;
	}
	//处理长短不一的问题
	while (a!=nullptr)
	{
		node *p = (node *)(malloc(sizeof(struct node)));
		int sum = carry + a->data;
		p->data = sum%10;
		carry = sum / 10;
		p->next = res;
		res = p;

		a = a->next;
	}

	while (b != nullptr)
	{
		node *p = (node *)(malloc(sizeof(struct node)));
		int sum = carry + b->data;
		p->data = sum % 10;
		carry = sum / 10;
		p->next = res;
		res = p;

		b = b->next;
	}
	//处理最高进位
	if (carry){
		node *p = (node *)(malloc(sizeof(struct node)));
		p->data = carry;
		p->next = res;
		res = p;
	}

}

void printResult(){
	//去掉前面的0
	while (res->data == 0) res = res->next;
	while (res != nullptr)
	{
		cout << res->data << ">";
		res = res->next;
	}
	cout << "null";
}
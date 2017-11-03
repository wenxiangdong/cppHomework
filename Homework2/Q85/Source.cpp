#include <iostream>
#include <string>
using namespace std;

struct node
{
	int data;
	node *next;
	node *pre;
};


node *head = nullptr;
node *tail = nullptr;
int len = 0;


int main(){

	node *p;

	int n;
	cin >> n;
	len = n;
	for (int i = 0; i < n; i++){
		if (head == nullptr){
			head = (node *)(malloc(sizeof(node)));
			cin >> head->data;
			tail = head;
		}
		else{
			p = (node *)(malloc(sizeof(node)));
			cin >> p->data;
			tail->next = p;
			p->pre = tail;
			tail = p;
		}
	}
	
	tail->next = head;
	head->pre = tail;//构成循环
	

	cin >> n;
	int int_p1, int_p2;
	string cmd, param;
	
	for (int i = 0; i < n; i++){
		cin >> cmd;
		if (cmd == "print"){
			p = head;
			while (p != tail)
			{
				cout << p->data << " ";
				p = p->next;
			}
			cout << tail->data << endl;
		}
		else if (cmd == "replace"){
			cin >> int_p1 >> int_p2;
			p = head;
			while (p != tail)
			{
				if (p->data == int_p1) p->data = int_p2;
				p = p->next;
			}
			if (tail->data == int_p1) tail->data = int_p2;
		}
		else if(cmd == "move"){
			cin >> param >> int_p1;
			int count = 0;
			p = head;
			//先删除
			while (p != tail){
				if (p->data == int_p1){
					count++;
					p->pre->next = p->next;
					p->next->pre = p->pre;
				}
				p = p->next;
			}
			if (p->data == int_p1){
				count++;
				p->pre->next = p->next;
				p->next->pre = p->pre;
			}

			//再增加
			if (param == "head"){
				for (int i = 0; i < count; i++){
					p = (node *)(malloc(sizeof(node)));
					p->data = int_p1;
					p->next = head;
					head->pre = p;
					head = p;
				}
				head->pre = tail;
				tail->next = head;
			}
			else{
				for (int i = 0; i < count; i++){
					p = (node *)(malloc(sizeof(node)));
					p->data = int_p1;
					p->pre = tail;
					tail->next = p;
					tail = p;
				}
				tail->next = head;
				head->pre = tail;
			}
		}
		else if (cmd == "translate"){
			cin >> param >> int_p1;
			
			if (param == "head"){
				for (int i = 0; i < int_p1%len; i++){
					head = head->next;
					tail = tail->next;
				}
			}
			else{
				for (int i = 0; i < int_p1%len; i++){
					tail = tail->pre;
					head = head->pre;
				}
			}		
		}
	}

	return 0;
}
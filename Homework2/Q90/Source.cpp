#include <iostream>
#include <string>
using namespace std;


struct Node
{
	int data;
	Node *next;
};

class List
{
public:
	List(){
		head = (node_ptr)(malloc(sizeof(Node)));
		head->data = INT_MIN;
		tail = head;
		len = 0;
	}


	int getSize(){ return len; }

	bool isEmpty(){ return len == 0; }

	void insert(int data){
		tail->next = (node_ptr)(malloc(sizeof(Node)));
		tail = tail->next;
		tail->data = data;
		tail->next = nullptr;
		last[data] = tail;
		len++;
	}

	void delAll(int data){
		while (remove(data));
	}

	void removeRepeat(int data){
		while (true){
			node_ptr p = find(data);
			if (p->next == nullptr) return;
			if (p->next != nullptr){
				if (p->next == last[data]) return;
				else {
					remove(p);
				}
			}
		}
	}

	void print(){
		if (isEmpty()) {
			cout << "NULL" << endl;
			return;
		}
		else{
			node_ptr p = head->next;
			while (p != nullptr)
			{
				cout << p->data << " ";
				p = p->next;
			}
			cout << endl;
		}
		
	}

	void reserve(){
		if (isEmpty()) return;
		node_ptr pre = nullptr;
		node_ptr p = head->next;
		node_ptr temp;
		while (p!=nullptr)
		{
			temp = p->next;
			p->next = pre;
			pre = p;
			p = temp;
		}
		head->next = pre;
	}

private:
	typedef Node *node_ptr;
	node_ptr head;
	node_ptr tail;
	int len;
	node_ptr last[100000];


	void remove(Node *p){
		if (p->next == tail) tail = p;
		p->next = p->next->next;
		len--;
	}

	Node *find(int data){
		node_ptr p = head;
		while (p->next != nullptr)
		{
			if (p->next->data == data) break;
			p = p->next;
		}
		return p;
	}

	bool remove(int data){
		node_ptr p = find(data);
		if (p->next == nullptr) return false;
		else{
			remove(p);
			return true;
		}
	}
};


int main(){
	List list;
	int n;
	cin >> n;
	string cmd;
	int param;

	for (int i = 0; i < n; i++){
		cin >> cmd;
		if (cmd == "ADD"){
			cin >> param;
			list.insert(param);
		}
		else if (cmd == "REVERSE"){
			list.reserve();
		}
		else if (cmd == "REMOVEREPEAT"){
			cin >> param;
			list.removeRepeat(param);
		}
		else if (cmd == "DEL"){
			cin >> param;
			list.delAll(param);
		}
		else if (cmd == "PRINT"){
			list.print();
		}
		else if (cmd == "SIZE"){
			cout << list.getSize() << endl;
		}
	}

	return 0;

}
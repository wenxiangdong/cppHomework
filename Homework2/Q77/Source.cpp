#include <iostream>
#include <stack>
#include <string>
#include <fstream>
using namespace std;


stack<string> st;

int main(){
	char name[10] = { 0 };
	char itor;
	bool isStart = true;


tag: while ((itor = getchar()) != EOF){
	switch (itor)
	{
	case '<':
		char c = getchar();
		if (c == '!'){//ע��
			//��ͷ���淶
			if (!((c = getchar()) == '-' && (c = getchar()) == '-')){
				cout << "False"; return 0;
			}
				char temp[10000];
				int index = 0;
				while ((c = getchar()))
				{
					if (c == '>'){
						if (temp[index-1] == '-' && temp[index-2] == '-'){
							goto tag;
						}
					}
					temp[index] = c;
					index++;
				}
				//ע�Ͳ���������
				cout << "False"; return 0;
			}
			else if (c == '/'){//������ǩ
				//ջ�մ�
				if (st.empty()) {
					cout << "False"; return 0;
				}
				//��ʼƥ��
				string top = st.top();
				st.pop();
				for (int i = 0; i < top.size(); i++){
					c = getchar();
					if (c != top[i]) {
						cout << "False"; return 0;
					}
				}
			}
			else{//��ʼ��ǩ
				int len = 0;
				while (c != '>'){
					if (len > 9) {//���Ƴ��ȴ���9����
						cout << "False"; return 0;
					}
					else if (!(c >= 'A'&& c <= 'Z')){//�淶��
						cout << "False"; return 0;
					}
					else{
						name[len] = c;
						len++;
						c = getchar();
					}
				}
				if (len < 1){
					cout << "False"; return 0;
				}
				//��ջ
				name[++len] = 0;
				string s(name);
				st.push(s);
				//����name
				for (int i = 0; i < 10; i++) name[i] = 0;
			}
			break;
		}
	}
	 if (!st.empty()){
		 cout << "False"; 
		 return 0;
	 }
	cout << "True";
	return 0;
}
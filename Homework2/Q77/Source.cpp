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
		if (c == '!'){//注释
			//开头不规范
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
				//注释不结束，错
				cout << "False"; return 0;
			}
			else if (c == '/'){//结束标签
				//栈空错
				if (st.empty()) {
					cout << "False"; return 0;
				}
				//开始匹配
				string top = st.top();
				st.pop();
				for (int i = 0; i < top.size(); i++){
					c = getchar();
					if (c != top[i]) {
						cout << "False"; return 0;
					}
				}
			}
			else{//开始标签
				int len = 0;
				while (c != '>'){
					if (len > 9) {//名称长度大于9，错
						cout << "False"; return 0;
					}
					else if (!(c >= 'A'&& c <= 'Z')){//规范？
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
				//入栈
				name[++len] = 0;
				string s(name);
				st.push(s);
				//重置name
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
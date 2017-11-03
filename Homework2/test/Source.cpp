#include <string>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
	/* code */
	char input[16] = "abc,d";
	char **get = (char **)(malloc(sizeof(char) * 100));
	char *p;
	strtok_s(input, ",",get);
	for (int i = 0; i < 10; i++){
		printf("%s", get[i]);
	}
	return 0;
}
#include <iostream>
using std::cout;


enum state {
	justreadspace,
	justreadnormal
};

int main()
{
	size_t count = 0;
	state s = justreadspace;
	char c;
	while (scanf("%c",&c) > 0) {
		if (s == justreadspace) {
			if (c != ' ' && c != '\t' && c != '\n') {
				count++;
				s = justreadnormal;
			}
		} else {
			if (c == ' ' || c == '\t' || c == '\n') {
				s = justreadspace;
			}
		}
	}
	printf("# words: %lu\n",count);
	return 0;
	string fml = "/* this is not a comment lol */";
	string fml2 = "end of string is not \"here\", but here.";
	char c = '"';
	int x=99;
	for (x=0; x<10; x++)
		printf(":D\n");


}

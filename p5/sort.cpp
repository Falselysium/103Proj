/*
 * CSc103 Project 5: Sorting with lists
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References: Twitch.tv/professor_wes
 *
 *
 * Finally, please indicate approximately how many hours you spent on this:
 * #hours: 10
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <getopt.h> // to parse long arguments.
#include <string>
using std::string;

/* doubly linked list node: */
struct node {
	string data;
	node* prev;
	node* next;
	node(string s="", node* p=NULL, node* n=NULL) : data(s),prev(p),next(n) {}
};


int main(int argc, char *argv[]) {
	/* define long options */
	static int unique=0, reverse=0;

	static struct option long_opts[] = {
		{"unique",   no_argument,       &unique,   'u'},
		{"reverse",  no_argument,       &reverse,  'r'},
		{0,0,0,0} // this denotes the end of our options.
	};
	/* process options */
	char c; /* holds an option */
	int opt_index = 0;
	while ((c = getopt_long(argc, argv, "ur", long_opts, &opt_index)) != -1) {
		switch (c) {
			case 'u':
				unique = 1;
				break;
			case 'r':
				reverse = 1;
				break;
			case '?': /* this will catch unknown options. */
				return 1;
		}

	}
	/* NOTE: at this point, variables
	 * 'reverse' and 'unique' have been set
	 * according to the command line.  */
	/* TO
	 * DO: finish writing this.  Maybe use while(getline(cin,line)) or
	 * similar to read all the lines from stdin. */
	string line;
	getline(cin , line);
	node* l = new node(line, NULL, NULL);
	node* p = l;
	node* m = l;

	while(getline(cin, line)){
		p = new node(line, NULL , NULL);
		while(m){
			if(p -> data < m -> data){
				if(m-> prev == NULL){
					m -> prev = p;
					p -> next = m;
					l = p;
					break;
				}
				else{
					m -> prev -> next = p;
					p -> prev = m -> prev;
					p -> next = m;
					m -> prev = p;
					break;
				}
			}
			else if(p -> data >= m-> data && m-> next == NULL){
				m -> next = p;
				p -> prev = m;
				break;
			}
			m = m-> next;
		}
		m = l;
	}
	p = m -> next;

	if(reverse && unique){
		while(m){
			if(m->next != NULL)
				m = m->next;
			else
				break;
		}
		p = m->prev;

		while(m){
			if(m -> data != p -> data){
				cout << m-> data <<endl;
				m = m -> prev;
				if(p->prev == NULL){
					cout << m->data <<endl;
					break;}
				else
				p = p -> prev;
			}

			else{
				m = m -> prev;
				if(p->prev ==NULL){
					cout << m->data <<endl;
					break;}
				else
				p = p -> prev;
			}
		}
	}

	else if(unique){
		while(m){
			if(m -> data != p -> data){
				cout << m-> data <<endl;
				m = m -> next;
				if(p->next == NULL){
					cout << m->data <<endl;
					break;}
				else
				p = p -> next;
			}

			else{
				m = m -> next;
				if(p->next ==NULL){
					cout << m->data <<endl;
					break;}
				else
				p = p -> next;
			}
		}
	}

	else if(reverse){
		while(m){
			if(m->next != NULL)
				m = m->next;
			else
				break;
		}
		while(m){
		cout << m->data <<endl;
			m = m->prev;
		}
	}

	else{
		while(m){
			cout << m->data <<endl;
			m = m-> next;
		}
	}
	return 0;
}
























/*
 * CSc103 Project 1: (hello_world++)
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References:
 *Compiling Source: geeksforgeeks.org/compiling-with-g-plus-plus/
 * String Source: https://www.tutorialspoint.com/cplusplus/cpp_strings.htm
*/

/*#include <iostream>
#include <string>

using namespace std;

int main(){
  string name = "";
  string relative = "";

  cout << "Enter your name:" << endl;
  cin >> name;
  cout << "Enter a relative:" << endl;
  cin >> relative;

  cout << "Hello. My name is " << name << ". You killed my " << relative << ". Prepare to die." << endl;

 return 0;

}*/

#include <iostream>
using std::cin;
using std::cout;
#include <string>
using std::string;

int main()
{

 std::string name;
 std::string relative;

 cout<< "Enter Your Name: \n";
 getline(cin,name);
 cout<< "Enter a relative: \n";
 getline(cin,relative);
 cout << "Hello. My name is " << name << ". You killed my " << relative << ". Prepare to die.\n";
 return 0;

}




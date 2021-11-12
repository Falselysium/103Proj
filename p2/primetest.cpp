/*
 * CSc103 Project 2: prime numbers.
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References:
 *
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <cmath>

int main()
{
 unsigned n;
 int i;

 while (cin >> n) {
 bool numberIsPrime = true;

if (n == 0 || n==1){
  numberIsPrime = false;
  }
for (i = 2; i <= sqrt(n); ++i) {
    if (n % i == 0) {
     numberIsPrime = false;
     break;
    }
   }
cout << numberIsPrime <<  endl;
  }

  return 0;
}




/*
#include <iostream>
#include <string>
#include <cmath>
using namespace std;


int main() {
  int num;
  bool status = true;
  while(cin.good()){
    cin >> num;
    status = true;
  while(status)//true until false
  {
    if (num == 0 || num == 1)//Both Not Prime[First Step]
    {
      //cout<< "This is not a Prime 1\n";
      status = false;
    }
    for (int x = 2; x <= sqrt(num); x++)//Second Step Cycles through all values from 2 to num/2
    {
      if (num%x == 0){
        //cout<< "This not is a Prime 2\n";
        status = false;
        break;//breaks the for loop and returns status as false(0)
      }
    }
    break;// breaks the nested while loop and returns status
    }
  cout << status << endl;
}
  return 0;
}



#include <iostream>
using namespace std;
 int main () {
    int i, n;
    bool isPrime = true;

   //while(cin.good()){
   // cin >> n;
   //isPrime = true;
   while(true){
     cin >>n;
    // 0 and 1 are not prime numbers
    if (n == 0 || n == 1){
      isPrime = false;
        }
    else{
       for(i = 2; i <= n/2; ++i){
          if (n%i ==0){
            isPrime = false;
            break;
          }
       }
    }

      if (isPrime){
        cout << "1\n" ;
        cout << cin.good();
        isPrime = true;
        //break;
       }
      else{
        cout << "0\n" ;
        cout << cin.good();
        isPrime = true;
        //break;
    }
      }

    //}
        return 0;
}
*/
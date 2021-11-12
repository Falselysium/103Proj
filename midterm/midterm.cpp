/* Name: [Andy Zheng] */

/* ~~~~~~~~~~~ Answer to #1 ~~~~~~~~~~~ */
#include <iostream>
#include <string>
using namespace std;

int main(){
size_t lines=0, editlines=0;
int chars=0, totalchars=0;
string all;

string line;
while(getline(cin,line)){
  lines++;
  totalchars+=line.length();
  if(line.length() < 20){
    editlines++;
    for(int x=0;x< line.length();x++){
      chars++;
    }
  }
  else
    all+= line +'\n';
}

cout<< all;
for(int y = 0; y < chars; y++){
  cout<<"~";
}
cout<<endl;
cout <<editlines << " lines filtered ("<< ((double)editlines/lines)*100  <<"%)"<<endl;
cout <<chars<< " chars filtered ("<< ((double)chars/totalchars)*100  <<"%)"<<endl;
}

/* ~~~~~~~~~~~ Answer to #2 ~~~~~~~~~~~ */

int nums(vector<int> r,vector<int> m){
bool status = true;
size_t value;
int mproduct=1;
for(int x=0; x<m.size();x++){
mproduct*=m[x];
}
for(value = 0; value < mproduct; value++){
status = true;
  for(int vec=0;vec < r.size(); vec++){
    if(value%m[vec] == r[vec]){
      status = true;
    }
    else{
      status = false;
      break;
    }
  }
  if(status){
    return value;
  }
}
return -1;
}

/* ~~~~~~~~~~~ Answer to #3 ~~~~~~~~~~~ */

void shift(vector<int>& V);

int prg(vector<int>& R,const vector<int>& T, int m){
int sum=0;
int total =0;
for(int start=0; start <T.size()-1;start ++){
  for(size_t x=0; x<T.size();x++){
  sum+=R[T[x]];
  }
R[R.size()-1] = sum%m;
shift(R);
total += R[0];
}
return total;
}

/* ~~~~~~~~~~~ Answer to #4 ~~~~~~~~~~~ */

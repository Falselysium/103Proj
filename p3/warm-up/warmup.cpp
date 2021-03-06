#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::endl;


vector<vector<bool> > world = {
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

int neighbor(int p, int q,vector<vector<bool> >  w){
  int count = 0;
  for (int r = -1; r < 2; r++){
    for(int c = -1; c < 2; c++){
      if (w[(r + p + w.size()) % w.size()][(c + q + w[p].size()) % w[p].size()] == true){
        count++;
      }
    }
  }
  return count - w[p][q];
}

int main(int argc, char *argv[]){

	vector<vector<bool>> future(world); /* make future a copy of world. */
	/* NOTE: the vector 'world' above corresponds to the contents
	 * of ../res/tests/0.  TODO: apply the rules to the vector,
	 * write the result to standard output, and compare with the
	 * contents of ../tests/1. */
	unsigned int r=0, c=0, num;
	int epoint = atoi(argv[1]);

	for (int start = 1; start <= epoint; start++){
		//cout << start << " argc: " << epoint << endl;
		for (r = 0; r < world.size(); r++){
			for (c = 0; c < world[r].size(); c++){
				num = neighbor(r, c, world);
				if (num == 3){
					future[r][c] = true;
				}
				else if (num < 2 || num > 3){
					future[r][c] = false;
				}
			}
		}
		world = future;
	}

	for (r = 0; r < world.size(); r++){
		for (c = 0; c < world[r].size(); c++){
			if (future[r][c] == false){
			cout << ".";
			}
			else
				cout << "O";
		}
		cout<<"\n";
	}
	return 0;
}

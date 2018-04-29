#include<string>
#include<cmath>
#include<iostream>

using namespace std;

class AB {
	public:
string createString(int N, int K) {
/** convert to math
 *  x+y = N
 *  max(x*y) = ?
 *  1. x+y = N
 *  2. x*y = K
 *  res:
 *  Y = sqrt(N^2/4-K) + N/2
 *  X = N/2 - sqrt(N^2/4-K)
 *  X,Y > 0
 *  Y = N/2, x*y == max == N^2/4
 *  T = O(n) 
 */
 if (K < 0 || K > pow(N,2)/4 || N < 2 || N > 50) {
	return "";
 }

 char dest_str[N+1];
 dest_str[0] = 'A';
 for (int i = 1; i <= N-1; i++) {
	dest_str[i] = 'B';
 }
 dest_str[N] = 0;
 int pairs = N -1;
 int complements = 1;
 int retrieve = 1;
 int count = 1;
 while(pairs != K) {
	if (pairs > K) {
             dest_str[N-1-pairs] = 'B';
	     pairs--;
	     dest_str[N-1-pairs] = 'A';
	     continue;
	}
	pairs++;
	if (  pairs == (N-retrieve)*retrieve+1) {
		dest_str[N-1-retrieve-1] = 'A';
		count =1;
		retrieve++;
	} else {
		dest_str[N-1-retrieve-count+1] = 'B';
		dest_str[N-1-retrieve-count] = 'A';
		count++;
        }
 }
 return dest_str;
}
};

int main(int argc, char** args) {
	AB* ab = new AB;
	//test
	//3,2
	cout << "3,2" << endl;
	cout << ab->createString(3,2) << endl;
	//2,0
	cout << "2,0" << endl;
	cout << ab->createString(2,0) << endl;
	//5,8
	cout << "5,8" << endl;
	cout << ab->createString(5,8) << endl;
	//10,12
	cout << "10,12" << endl;
	cout << ab->createString(10,12) << endl;
	//10,15
	cout << "10,15" << endl;
	cout << ab->createString(10,15) << endl;
	cout << "10,20" << endl;
	cout << ab->createString(10,20) << endl;
	//10,25
	cout << "10,25" << endl;
	cout << ab->createString(10,25) << endl;
	//12,20
	cout << "12,20" << endl;
	cout << ab->createString(12,20) << endl;
	return 0;
}


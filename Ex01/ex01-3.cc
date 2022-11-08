/* s1240211 関　翔太*/

#include <iostream>
#include <string>

using namespace std;

int main(){
  int A[15]={2,4,-1,3,0,6,-1,8,9,-5,1,-4,2,6,-8};
  int sum = 0;

  for(int i: A){
    sum += i;
  }

  cout << "sum of the array = " << sum;
  cout << endl;
  return 0;
}

/*(出力結果)

bash-4.4$ g++ ex01-3.cc -std=c++11
bash-4.4$ ./a.out
sum of the array = 22

*/

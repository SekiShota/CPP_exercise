/* s1240211 関 翔太 */

#include <iostream>
using namespace std;

class Test{
public:
/* [Complete Here!!] */
  int x1;
  int x2;

  double center(){
    return (x1+x2)*0.5; //クラスにふくまれる関数は引数なし
  }
};

int main(){
 /* [Complete Here!!] */
  Test a,b;

  cin >> a.x1 >> a.x2;

  cout << "a: " << a.center() << endl;
  cout << "b: " << b.center() << endl;

  return 0;
}

//doubleで値を返しているが出力は整数となる場合があるが問題はない

/*
(出力結果)
$ ./a.out
4 8
a: 6
b: 1.35163e+08

$ ./a.out
0 3
a: 1.5
b: 1.35163e+08

*/

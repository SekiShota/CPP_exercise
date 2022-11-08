/* s1240211 関 翔太 */

#include <iostream>
using namespace std;

class Test{
private:
 int x1,x2;

public:
 double center(){
   return (x1+x2)*0.5;
 }

public:
  int get_x1(){
    return x1;
  }

  void set_x1(int a1){
    x1 = a1;
  }

  int get_x2(){
    return x2;
  }

  void set_x2(int a2){
    x2 = a2;
  }

};

int main(){
  Test a,b;
  int p,q;

  cin >> p;
  a.set_x1(p);

  cin >> q;
  a.set_x2(q); //a.x1やa.x2はクラスの外からは参照できない

  cout << "a: " << a.center() << endl; //a.center()はクラスの外からは参照できない
  cout << "b: " << b.center() << endl; //b.center()はクラスの外からは参照できない
  return 0;
}

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

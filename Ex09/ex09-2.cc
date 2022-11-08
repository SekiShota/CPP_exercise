/* s1240211 関　翔太　*/

#include <iostream>
#include <string>

using namespace std;

class Frac{
private:
  int numerator;
  int denominator;
public:
  Frac();
  Frac(int,int);
  void set_frac(int,int);
  void show_frac(void);
  void multfrac(Frac);
};

int main(){
  //Frac f1;      //引数なしコンストラクタ
  Frac f2(2,3); //引数２つのコンストラクタ
  Frac f3;      //引数なしコンストラクタ
  int d_in,n_in;

  //f1.show_frac(); // 1/1が出る

  cout << "Input denominatior(y) and numerator(y) -> x/y" << endl;
  cin >> d_in >> n_in;
  f3.set_frac(n_in,d_in); //f3がn_in/d_inになる

  try{
    f2.multfrac(f3);//分数f2と引数に渡された分数f3の積をf2に格納
  }

  catch(const char *e){
    cout << e << endl;
  }

  f2.show_frac(); // 2/3が出る

  //f2.show_frac();// 8/15が出る
  //f2.multfrac(f2); //自分の2乗
  //f2.show_frac();// 64/225が出る

  return 0;
}

Frac::Frac() : numerator(1),denominator(1){

}

Frac::Frac(int n,int d){
  numerator = n;
  denominator = d;
}

void Frac::set_frac(int n,int d){
  numerator = n;
  denominator = d;
}

void Frac::show_frac(void){
  cout << numerator << "/" << denominator << endl;
}

void Frac::multfrac(Frac f){
  try{
    if(denominator == 0 ||f.denominator == 0) throw "Error:Division by zero";
  }
  catch(const char *e){
    throw;
  }
  numerator = f.numerator * numerator;
  denominator = f.denominator * denominator;
}
/* 出力結果
$ ./a.out
Input denominatior(y) and numerator(y) -> x/y
0 4
Error:Division by zero
2/3
*/

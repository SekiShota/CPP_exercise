/* s1240211 関 翔太 */

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


/* [Complete Here!!] (template関数のプロトタイプ宣言)*/

template <class T> T Add(T,T); //同じ型の加法
template <class T> T Mult(T,T); //同じ型の乗法
template <class T,class U> T Add2(T,U); //異なる型の加法

int main(){
  int ix[3]={6,-1,0};
  float fx[3]={3.75,1.25 , 0.0};
  double dx[3]={3.14159265358979,6.85840734641021,0.0};
  string sx[3]={"Divide and ","Conquer", ""};
  char cx[3] = {'A','!'};
  bool bx[3] = {true,false};

  ix[2]=Add(ix[0],ix[1]);
  fx[2]=Add(fx[0],fx[1]);
  dx[2]=Add(dx[0],dx[1]);
  sx[2]=Add(sx[0],sx[1]);
  cx[2]=Add(cx[0],cx[1]);
  bx[2]=Add(bx[0],bx[1]);

  cout << fixed;
  cout << "[Results of template Add function]" << endl;
  cout << "int + int : " << ix[2] << endl;
  cout << "float + float : "  << fx[2] << endl;
  cout << "double + double : " << dx[2] << endl;
  cout << "string + string : " << sx[2] << endl;
  cout << "char + char : " << cx[2] << endl; // man ascii
  cout << "bool + bool : " << bx[2] << endl;

  cout << endl;

  cout << "[Results of template Mult function]" << endl;
  cout << "int * int : " << Mult(ix[0],ix[1]) << endl;
  cout << "float * float : " << Mult(fx[0],fx[1]) << endl;
  cout << "double * double : " << Mult(dx[0],dx[1]) << endl;
  //cout << "string * string : " << Mult(sx[0],sx[1]) << endl; *コンパイラエラー発生*
  cout << "char * char: " << Mult(cx[0],cx[1]) << endl;
  cout << "bool * bool: " << Mult(bx[0],bx[1]) << endl;

  cout << endl;

  cout << "[Results of template Add2 function]" << endl;
  cout << "int + int: " << Add2(ix[0],ix[1]) << endl;
  cout << "double +  int : " << Add2(dx[0],ix[0]) << endl;
  cout << "int + double : " << Add2(ix[0],dx[0]) << endl;
  //cout << "string + int : " << Add2(sx[0],ix[0]) << endl; *コンパイラエラー発生*
  cout << "char + int : " << Add2(cx[0],ix[0]) << endl;
  cout << "int + char : " << Add2(cx[0],ix[0]) << endl;
  cout << "string + char : " << Add2(sx[2],cx[1]) << endl;
  cout << "int + bool: " << Add2(ix[1],bx[0]) << endl;

  return 0;
}




/* [Complate Here !!] (template関数を作成) */
template <class T> T Add(T a,T b){
  return a + b;
}

template <class T> T Mult(T a,T b){
  return a * b;
}

template <class T,class U> T Add2(T a,U b){
  return a + b;
}

/*

(出力結果)

[Results of template Add function]
int + int : 5
float + float : 5.000000
double + double : 10.000000
string + string : Divide and Conquer
char + char : b
bool + bool : 1

[Results of template Mult function]
int * int : -6
float * float : 4.687500
double * double : 21.546322
char * char: a
bool * bool: 0

[Results of template Add2 function]
int + int: 5
double +  int : 9.141593
int + double : 9
char + int : G
int + char : G
string + char : Divide and Conquer!
int + bool: 0

*/

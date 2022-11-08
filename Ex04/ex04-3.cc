/* s1240211 関　翔太　*/

#include <iostream>
/* [Complete Here!!] */
#include <map>
#include <vector>
#define NUM 100

using namespace std;

int main(){
  int n, mod;
  /* [Complete Here!!] */
  vector<int> vec;
  map<int,vector<int> > integers; //キーを int, 値を int型のvectorコンテナとするmap "integers"を宣言

  cout << "Input modulus ->";
  cin >> n;

  for(int i=0;i<NUM;i++){
     /* [Complete Here!!] */
     integers[i%n].push_back(i);      //値 i を、 n で割った余りごとに map "integers"に振り分ける
  }

  cout << "Input display class ->";
  cin >> mod; //ｍの値を入力する

  cout << "Members in <" << mod << ">" << endl; //余りがｍになる整数たちを列挙する
   /* [Complete Here!!] */
  vector<int>::iterator itr;   //そのために、値を順に出力するためのイテレータを宣言
  for(itr=integers[mod].begin();itr!=integers[mod].end();itr++){ //イテレータが、データの先頭から末尾に向かう間ループする
    cout << *itr << endl; // itr が指す値（整数）を出力
  }

  return 0;
}

/*

(出力結果)

$./a.out
Input modulus ->11
Input display class ->9
Members in <9>
9
20
31
42
53
64
75
86
97

*/

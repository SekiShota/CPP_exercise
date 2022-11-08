/* s1240211 関　翔太　*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

template <typename Input, typename Output>
Output my_copy(Input,Input,Output);
int front,back;

int main(){

  #ifndef STRING
  int val;
  vector<int> vec,v;

  cout << "Input  " << endl;
  while(cin >> val){
    vec.push_back(val);
  }
  cin.clear();

  cout << "< Input copy index >" << endl;
  cout << "front of copy range->" ;
  cin >> front;
  cout << "back of copy range->" ;
  cin >> back;

  vector<int>::iterator itr1,it1;
  vector<int>::iterator itr2,it2;
  #else
  string vec, v;
  cout << "Input " << endl;
  cin >> vec;
  cout << "< Input copy index >" << endl;
  cout << "front of copy range->" ;
  cin >> front;
  cout << "back of copy range->" ;
  cin >> back;
  if(front > back) cout << "It cannot copy" << endl;

  string::iterator itr1,it1;
  string::iterator itr2,it2;
  #endif
   /*
　　これより上で、変数の定義を行う。
　　コンパイル時に、引数に渡る変数型に応じてジェネリック関数の引数の型が自動で対応する。
　　*/

  itr1 = std::copy(vec.begin()+front, vec.begin()+back, vec.begin()+front);      //オリジナルのSTL関数
  itr2 = my_copy(vec.begin()+front, vec.begin()+back, vec.begin()+front);   //自作ジェネリック関数

  /* [vec.begin()+front, vec.begin()+back) の範囲をコピーする */

  //STLの結果
  cout << "[STL] copy = ";
  for(it1=vec.begin()+front; it1!=itr1; it1++){
    cout << *it1;
  }
  cout << endl;

   //自作関数の結果
  cout << "[MY TEMPLATE] my_copy = " ;
  for(it2=vec.begin()+front; it2!=itr2; it2++){
    cout << *it2;
  }
  cout << endl;
  return 0;
}


/*
自作ジェネリック関数 my_copy
コピー元の値を持つ変数の先頭、末尾のイテレータと、
コピー先の変数の値の入った先頭のイテレータを引数に渡す （戻り値：末尾のイテレータ）
*/

template <typename Input,typename Output>
Output my_copy(Input b1,Input e1,Output b2){

  while(b1 != e1){
    *b2 = *b1;
    b1++;
    b2++;
  }

  return b2;
}

/*
(出力結果)
＜数字の場合＞
$ ./a.out
Input
1
2
3
4
5
6
7
8
9
< Input copy index >
front of copy range->3
back of copy range->6
[STL] copy = 456
[MY TEMPLATE] my_copy = 456

＜文字列の場合＞
$ ./a.out
Input
decoration
< Input  copy index >
front of copy range->4
back of copy range->8
[STL] copy = rati
[MY TEMPLATE] my_copy = rati

*/

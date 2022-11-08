/* s1240211 関 翔太 */

#include <iostream>
#include <list>            // listを使う
#include <string>

using namespace std;

typedef struct{
  string word;
  int count;
}WordCount;

bool sort_word(const WordCount&, const WordCount&);

void Listprint(list<WordCount>);  // listの内容を全部表示する
list<WordCount>::iterator Finditem(string,list<WordCount> &); // listから、指定の１つの値を存在するか調べる

int main(){
  string input;
  list<WordCount> ls; //int型の要素を持つlist
  list<WordCount>::iterator itr; // listを参照するためのイテレータ
  WordCount n;

  while(cin >> input){
    itr = Finditem(input,ls); //入力データがlistにあるか探す

    if(itr == ls.end()){
      n.word = input;
      n.count = 1;
      ls.push_back(n);
    }

    else{
      (*itr).count++;
    }
  }

  ls.sort(sort_word);

  Listprint(ls);

  return 0;
}

bool sort_word(const WordCount& x,const WordCount& y){
  return x.word < y.word;
}

void Listprint(list<WordCount> listdata){

  list<WordCount>::iterator itr; //イテレータでアクセスする
  for(itr=listdata.begin();itr!=listdata.end();itr++){
    if(itr!=listdata.end())
      cout << (*itr).word << " " << (*itr).count << endl;// *itr でイテレータが指す内容を参照できる
  }
}

list<WordCount>::iterator Finditem(string name,list<WordCount> &listdata){

  list<WordCount>::iterator itr;

  for(itr=listdata.begin();itr!=listdata.end();itr++){
    if((*itr).word == name) break;
  }
  return itr; //見つけた場所を返す
}

/*(出力結果)

appl 1
apple 4
banana 3
cherry 1
kiwi 1
lemon 1
melon 2
orange 1

*/

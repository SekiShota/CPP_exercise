/* s1240211 関　翔太　*/

#include <iostream>
/* [Complete Here!!] */
#include <map>
#include <string>
using namespace std;

int main(){
  string name;
  /* [Complete Here!!] */
  //int count=1;
  map<string,int> candidate;

  while(cin >> name){ //投票（入力）された候補者の名前をキーにして、対応するmap"candidate"の要素をカウントアップ
    /* [Complete Here!!] */
    candidate[name]++;
  }

  cout << "[Voting Result]" << endl;
  /* [Complete Here!!] */
  map<string,int>::iterator itr; //mapを巡回するためのイテレータを宣言
  for(itr = candidate.begin(); itr != candidate.end();itr++){
       cout << "Name:" <<
       /* [Complete Here!!] */  itr->first          // itr を利用して、mapのキーを出力
     << "            Number of votes obtained:" <<
     /* [Complete Here!!] */  itr->second         // itr を利用して、mapの値を出力
     << endl;
  }
  return 0;
}

/*

(出力結果)
$./a.out < voting.txt
[Voting Result]
Name:arai            Number of votes obtained:22
Name:hirasawa            Number of votes obtained:31
Name:kazawa            Number of votes obtained:24
Name:makiguchi            Number of votes obtained:26
Name:takahashi            Number of votes obtained:29
Name:yabe            Number of votes obtained:31
Name:yoshida            Number of votes obtained:37

*/

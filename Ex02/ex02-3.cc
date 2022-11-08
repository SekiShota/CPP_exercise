/* s1240211 関　翔太 */

#include <iostream>
#include <random>  //c++用乱数
#include <algorithm>
#include <vector>


using namespace std;

int main(){
  random_device rnd;   // c++用の乱数。とりあえず無視してよい
  vector<int> vec;
  vector<int> p[4];
  int a,n;
  int count = 0;
  int flag = 0;

  cin >> n;

  for(int i=0;i<n;i++){
   a = rnd()%13+1;  //乱数0～13生成
   vec.push_back(a);
  }

  //使っているvectorはvector<int>なので、vector<int>に対するイテレータを宣言
  vector<int>::iterator it,it2;

  for(it=vec.begin(); it!=vec.end(); it++){ // .begin()は先頭アドレス、 .end()は末端アドレス
    p[count].push_back(*it);     //イテレータはポインタと同等なもの。実体を得るためには*をつける
    count=count+1;

    if(count==4) count=0;
  }


//イテレータを引数とするライブラリ関数（vector自体とは関係ない）
  //sort(vec.begin(),vec.end());  // 第1引数で示されたイテレータから、第2引数で示されたイテレータの直前までをソート
  for(count=0; count<4; count++){
    sort(p[count].begin(),p[count].end());
  }

  cout << "[Player1] ";
  for(it=p[0].begin();it!=p[0].end();it++){
    it2 = it+1;
    if(*it==*it2){
      p[0].erase(it,it2);
      it--;
      it2--;
    }
  }

  for(it=p[0].begin();it!=p[0].end();it++){
    cout << *it << " ";
  }
  cout << endl;

  cout << "[Player2] ";
  for(it=p[1].begin();it!=p[1].end();it++){
    it2 = it+1;
    if(*it==*it2){
      p[1].erase(it,it2);
      it--;
      it2--;
    }
  }

  for(it=p[1].begin();it!=p[1].end();it++){
    cout << *it << " ";
  }
  cout << endl;

  cout << "[Player3] ";
  for(it=p[2].begin();it!=p[2].end();it++){
    it2 = it+1;
    if(*it==*it2){
      p[2].erase(it,it2);
      it--;
      it2--;
    }
  }

  for(it=p[2].begin();it!=p[2].end();it++){
    cout << *it << " ";
  }
  cout << endl;

  cout << "[Player4] ";
  for(it=p[3].begin();it!=p[3].end();it++){
    it2 = it+1;
    if(*it==*it2){
      p[3].erase(it,it2);
      it--;
      it2--;
    }
  }

  for(it=p[3].begin();it!=p[3].end();it++){
    cout << *it << " ";
  }
  cout << endl;

  return 0;
}

/*出力結果(1)
$ ./a.out
52
[Player1] 1 2 3 5 6 7 8 9 10
[Player2] 2 4 5 6 7 10 11
[Player3] 1 5 6 7 8 9 10 11
[Player4] 2 3 6 7 10
 */

/*出力結果(2)
$ ./a.out
22
[Player1] 1 8 10 11
[Player2] 1 2
[Player3] 1 2 3 4 12
[Player4] 3 4 5
*/

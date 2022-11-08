/* s1240211 関 翔太 */

#include <iostream>
#include <vector> //vector利用時には、ヘッダーが必要


using namespace std;

int main(){
  vector<double> weight_1; //int型のvectorコンテナ（≒int型の伸縮自在な配列）
  vector<double> weight_2;
  double u,v;
  double sum=0.0;
  double avg, median;

  cout << "Input u" << endl;

  while(cin >> u){
    weight_1.push_back(u);  // vectorに入力値 u を末尾に挿入
  }

  cin.clear();

  cout << "Input v" << endl;
  while(cin >> v){
    weight_2.push_back(v);  // vectorに入力値 v を末尾に挿入
  }

  if(weight_1.size()==weight_2.size()){
    for(int i=0; i<weight_1.size(); i++){ // vectorの入力された個数分ループする
      sum += weight_1[i]*weight_2[i]; //合計値計算（vectorの各要素へは配列と同じようにしてランダムアクセスが行える）
    }
  }

  cout << "Result: u*v = " << sum << endl;

  return 0;
}

/* 出力結果１
$ ./a.out
Input u
1.0
2.0
3.0
4.0
Input v
1.5
0.0
1.0
2.0
Result: u*v = 12.5

*/

/* 出力結果２
$ ./a.out
Input u
2.5
3.3
1.8
1.4
1.2
1.1
-0.5
2.5
1.9
4.0
Input v
1.2
1.6
-1.2
13.0
4.5
-2.9
3.1
1.8
0.45
-2.25
Result: u*v = 21.335

*/

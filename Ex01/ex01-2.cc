/* s1240211 関 翔太 */

#include <iostream>
#include <string>

using namespace std;


int main(){
  string name;
  string ID;
  string str(25, '-');
  int count;

  for(count=0; count<12; count++){

    cin >> ID;
    cin >> name;
    cout << count+1 << ')' << "Hello, " << name << '(' << ID << ')' << '!' << endl;

    if(count%5 == 4) cout << str << endl;
  }

  return 0;
}

/* 出力結果

1)Hello, Akira(s1990023)!
2)Hello, Mamoru(s1990154)!
3)Hello, Takashi(s1990166)!
4)Hello, Ai(s1990242)!
5)Hello, Minori(s1990174)!
--------------------
6)Hello, Takumi(s1990111)!
7)Hello, Takeshi(s1990056)!
8)Hello, Kohei(s1990114)!
9)Hello, Kenyu(s1990185)!
10)Hello, Nobu(s1990143)!
--------------------
11)Hello, Makiko(s1990118)!
12)Hello, Yuta(s1990006)!

*/

/* s1240211 関 翔太 */

#include <iostream>
#include <fstream>

using namespace std;

int add(int, int);
int sub(int, int);
int mul(int, int);
int div(int, int);
int mod(int, int);

int main(){
  int num_of_eval;//評価する式の個数（入力ファイルの先頭にある）
  //data[0] 演算する整数の第１引数、 data[1] 演算する整数の第２引数、 data[2] 演算番号（0から4まで。順に+-*/%）
  int *data[3];
  int answer;//関数の戻り値（計算結果）

  //int ***(int, int);の関数のアドレスを持つポインタ配列（2項演算を行う関数名を配列式に登録する）
  int (*functions[])(int, int) = {/* [Complete Here!!] */ add,sub,mul,div,mod };


/*ファイルオープン（オープン失敗時のエラー処理も行うこと）*/
/* [Complete Here!!] */
  ifstream infile("ex10-1_in.txt");

  if(!infile.is_open()){
    cerr << "File open failed." << endl;
    return -1;
  }


/*
先に評価式の個数をファイルストリームから読み取る（ファイルから１つ分読み取る）。
続けて、その個数分だけ*data[0],*data[1],*data[2]の領域を動的に確保する
*/

/* [Complete Here!!] */
  infile >> num_of_eval;
  data[0] = new int[num_of_eval];
  data[1] = new int[num_of_eval];
  data[2] = new int[num_of_eval];


/*領域確保後、ファイルから３つ組の整数を順に読み取って、data[][]に代入する*/
/* [Complete Here!!] */
  for(int i=0; i<num_of_eval; i++){
    infile >> data[0][i];
    infile >> data[1][i];
    infile >> data[2][i];
  }


/*開いたファイルハンドルを閉じる*/
/* [Complete Here!!] */
    infile.close();

/*
読み取ったデータを元に計算する（完成済み）
関数ポインタによる、関数コール（※）も含む
*/
  cout << "Start Calculations." << endl;
  for(int i=0; i< num_of_eval;i++){
    int op = data[2][i];

    try{//おかしい（未定義の）演算を受け取ったら例外を投げて飛ばす
     if(op>=5 || op<=-1){
      throw "An invalid operation is ignored.";
     }

    //※関数ポインタによる呼び出し（配列の添字op ＝演算を示す整数値に対応する関数が呼び出せる）
    answer = functions[op](data[0][i],data[1][i]);
    cout << "[" << i+1 << "th result] " << data[0][i] << " " << data[1][i] << " " <<  answer << endl;
    }
    catch(const char* e){
      cout << e << endl;
    }
  }
  cout << "Finished. bye!" << endl;


/* 最後に、メモリ領域を動的確保した *data[0],[1],[2] を開放する*/
/* [Complete Here!!] */
  delete []data[0];
  delete []data[1];
  delete []data[2];

  return 0;
}



int add(int a, int b){
  return a+b;
}

int sub(int a, int b){
  return a-b;
}

int mul(int a, int b){
  return a*b;
}

int div(int a, int b){
  return a/b;
}

int mod(int a, int b){
  return a%b;
}

/*
(出力結果)

$ ./a.out
Start Calculations.
[1th result] 4 5 9
[2th result] 3 1 2
[3th result] 2 9 18
[4th result] 7 6 1
[5th result] 10 8 2
[6th result] 81 19 100
[7th result] 16 5 11
[8th result] 12 0 0
[9th result] 110 7 15
[10th result] 15 2 1
An invalid operation is ignored.
[12th result] 32 25 57
[13th result] 64 49 15
[14th result] 32 32 1024
[15th result] 256 8 32
[16th result] 655 32 15
[17th result] -26 -11 -37
[18th result] -9 -35 26
[19th result] 100 100 10000
[20th result] -30 -6 5
An invalid operation is ignored.
[22th result] 2147483647 6 1
Finished. bye!

*/

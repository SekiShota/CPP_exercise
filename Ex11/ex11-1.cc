/* s1240211 関 翔太 */

#include <iostream>
#include <memory> //メモリ管理に関するheader

using namespace std;

int main(){

  int *data;              //データを格納する動的配列の先頭アドレス
  int *lim;             //動的配列の末端（厳密には、最終要素の１つ後ろ）のアドレス
  allocator<int> alloc;   //メモリの動的確保・解放に関するクラスのオブジェクトallocを生成
  int size;               //確保するデータサイズ


  //確保するメモリサイズを入力
  cout << "Input how much memory you will allocate." << endl;
  cin >> size;



  /* メモリ領域の動的確保 */

  data = alloc.allocate(size);       //[1]入力されたサイズの分だけメモリを確保
  lim = data + size;                 //[2]動的配列の末端のアドレスを指定
  uninitialized_fill(data,lim,0);    //[3]未初期化領域を初期化しつつ範囲の要素全て０で埋める

  /* 確保ここまで */




  //確保した領域に値を代入、出力するテスト
  for(int i=0; i<size;i++) data[i]=i;
  for(int i=0; i<size;i++) cout << data[i]*2 <<endl;




  /* 動的に確保したメモリ領域の解放 */

  if(data){                            //[4]（このif文の意味は…）確保したメモリが存在する場合の処理
    int *itr = lim;                    //[5]動的配列の末端のアドレスを示すイテレータを作る
    while(itr != data){                //[6]イテレータitrが動的配列の先頭のアドレスに当たるまで破棄
      alloc.destroy(--itr);
    }
    alloc.deallocate(data, lim-data); //[7]
  }

  /* 解放ここまで */


  return 0;
}

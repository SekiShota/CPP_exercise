#include <stdio.h>
//#include <conio.h>
#include <list>
using namespace std;

typedef struct{
  int n;
  int val;
} STR;
  STR  tbl[]= {{1, 10}, {2,3}, {4,5}, {5,1}, {6,9}, {7,8} , {8,7}, {3,6} };

  list  lst;
  list::iterator p;

  void  print(){
    for(p=lst.begin(); p!=lst.end(); p++)
    printf("%d  val=%d\n", p->n,p->val);
    printf("\n");
  }

  int main(){
    int i;

    for(i=0; i<7; i++)  lst.push_back(tbl[i]);
    print();

    //３番を追加
    p=lst.begin();
    p++;
    p++;           //３番目に設定
    lst.insert(p,tbl[7]);
    print();


    //２番を削除
    p=lst.begin();
    p++;                //２番目に設定
    q= p;               //２番目を保存
    p--;                //リンクを保つためにバック
    lst.erase(q);
    print();

    getch();
    return 0;
  }

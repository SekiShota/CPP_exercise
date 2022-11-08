#include <iostream>
/* [Complete Here!!] */  // STLコンテナ「map」を使用する
#include <map>
#include <string>
using namespace std;

int main(){
  string mt_name;
  int mt_height;
  /* [Complete Here!!] */
  map <string,int> mountain;  //mapを定義

  //山の名前をキー、高さを値としてmapに随時登録する
  while(cin >> mt_name >> mt_height){
     /* [Complete Here!!] */
     mountain[mt_name] = mt_height;
  }
  cin.clear();

  cout << "Input the name of mountain."<< endl;
  cin >> mt_name; //山の名前（mapを探索するためのキー）を入力する

  //山の名前をキーにしてmapを探索し、それが登録されていればその山の高さを返す。
  if(mountain.find(mt_name) != mountain.end()){
   cout << mt_name << " is a mountain whose height is "
        <<  /* [Complete Here!!] */mountain[mt_name]  << "m." << endl;
  }
  else{//登録されていなかった
    cout << "Sorry, " << mt_name << " is not registered here." << endl;
  }
  return 0;
}

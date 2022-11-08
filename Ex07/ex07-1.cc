/* s1240211 関　翔太 */

#include <iostream>
#include <string>
#include <cstdlib>      //乱数用 （犬系のチャレンジ判定用）

using namespace std;

class Animal{//Animalクラス
protected:
  string name;              //動物の名前
  int age;                  //年齢
  int hungry;               //満腹度
public:
  Animal();                 //デフォルトコンストラクタ
  void eat(int);            //引数に与えられた量のエサを食べる
  void show_status(void);   //動物の調子を見る（出力するだけ）≠ゲッター（アクセス関数）
  void set_name(string);    //動物の名前をセットする（セッター）
  void set_age(int);        //動物の年齢をセットする（セッター）
};

class Dog : public Animal  //Dogクラス（Animalから継承）
{
protected:
  int ability;        //芸を行うための能力値
public:
  Dog();
  int frisbee(void);  //フリスビーを投げて、この動物に取らせる
  void bark(void);    //この動物を吠えさせる
};

class BullDog : public Dog  //BullDogクラス（Dogから継承）
{
private:
  int reward;       //番犬の役目を果せたらもらえる報酬
public:
  BullDog();
  int guard(void);  //番犬として働く
};

class Cat : public Animal  //Catクラス（Animalから継承）
{
protected:
  int nikukyu;           //肉球の柔らかさ
public:
  Cat();
  void nekojarashi();    //ねこじゃらしで遊ぶ
  void kotatsu();        //コタツで丸くなる
  void cry();            //鳴かせる
};

class Lion : public Cat  //Lionクラス（Catから継承）
{
protected:
  int fang_strength;       //牙の強さ
  string target;           //狙う獲物
public:
  Lion();
  void set_target(string); //獲物を見定める
  void hunt();             //獲物を狩る
};

//(Q3) オリジナル　Tigerクラス
class Tiger : public Lion
{
private:
  int speed;
  int bodylength;
  int weight;
  string rival;
  string hometown;
public:
  Tiger();
  void set_speed(int);
  void set_bodylength(int);
  void set_weight(int);
  void show_theme();
  void set_rival(string);
  void set_hometown(string);
  void color();
};

int main(){
//各オブジェクトを1個ずつ生成
  Animal ani_A;
  Dog ani_B;
  BullDog ani_C;
  Cat ani_D;
  Lion ani_E;

  Tiger ani_F;

  srand( time(NULL) );


/* インターフェース呼び出し */
  ani_A.show_status();
  ani_A.eat(10);
  ani_B.frisbee(); //Animalクラスに存在しない --> Dog
  ani_D.cry(); //Animalクラスに存在しない --> Cat
  ani_E.hunt(); //Animalクラスに存在しない --> Lion
  cout << endl;
//（Q１）親クラスは自分が持っているメンバー関数しか実行できないので子クラスしか持っていないメンバー関数は実行することができない

  ani_B.set_name("Mike");
  ani_B.set_age(11);
  ani_B.show_status();
  ani_B.bark();
  ani_C.guard(); //Dogクラスに存在しない --> BullDog
  ani_D.nekojarashi(); //Dogクラスに存在しない --> Cat
  ani_B.eat(5);
  cout << endl;
//（Q１）継承してないクラスのメンバー関数を子クラスで実行することはできない

  ani_C.set_name("Ben");
  ani_C.set_age(10);
  ani_C.show_status();
  ani_C.frisbee();
  ani_C.bark();
  ani_C.guard();
  ani_D.kotatsu(); //BullDogクラスに存在しない --> Cat
  ani_C.eat(15);
  cout << endl;
//（Q１）継承してないクラスのメンバー関数を子クラスで実行することはできない

  ani_D.set_name("Yoko");
  ani_D.set_age(3);
  ani_D.show_status();
  ani_D.cry();
  ani_D.kotatsu();
  ani_D.nekojarashi();
  ani_E.hunt(); //Catクラスに存在しない --> Lion
  ani_D.eat(20);
  cout << endl;
//（Q１）継承してないクラスのメンバー関数を子クラスで実行することはできない

  ani_E.set_name("Jun");
  ani_E.set_age(7);
  ani_E.show_status();
  ani_E.eat(30);
  ani_E.cry();
  ani_E.kotatsu();
  ani_E.nekojarashi();
  ani_E.set_target("Elephant");
  ani_E.hunt();
  ani_B.frisbee(); //Lionクラスに存在しない --> Dog
  cout << endl;
//（Q１）継承してないクラスのメンバー関数を子クラスで実行することはできない

  cout << "[ex07-1.cc Q3]-------------------------" << endl;
  ani_F.set_name("Hanshin");
  ani_F.set_age(19);
  ani_F.show_status();
  ani_F.eat(100);
  ani_F.set_target("Orange Rabbit");
  ani_F.hunt();
  ani_F.set_speed(65);
  ani_F.set_bodylength(120);
  ani_F.set_weight(200);
  ani_F.show_theme();
  ani_F.set_rival("Giants");
  ani_F.set_hometown("Nishinomiya");
  ani_F.color();
  cout << endl;

  return 0;
}


Animal::Animal(){
  name = "Ken";
  age = 5;
  hungry = 10;
}
void Animal::eat(int val){
  cout << "[EAT] " << name << " got a feed. (" << hungry << " -> ";
  hungry += val;
  cout << hungry << ")" << endl;
}
void Animal::show_status(void){
  //
  cout << "Name: " << name << "  Age: " << age << "  Hungry: " << hungry <<endl;
}
void Animal::set_name(string val){
  name = val;
}
void Animal::set_age(int val){
  age = val;
}



Dog::Dog(){
  ability = 50;
}
int Dog::frisbee(void){
  //この犬の能力値を元に、確率的にフリスビーを取れるか取れないか判断する
  cout << "[Frisbee] You threw a frisbee." << endl;
  if(rand()%100 <= ability){
    cout << name << " caught the frisbee! (Success)" << endl;
    return 1;
  }
  else{
    cout << name << " failed to catch the frisbee! (Fail)" << endl;
    return 0;
  }
}
void Dog::bark(void){
  cout << name << " barks.  Bow!! BoW!!" <<endl;
}



BullDog::BullDog(){
  reward = 0;
}
int BullDog::guard(void){
  //この犬の能力値を元に、確率的に番犬が成功するか失敗するか判断する
  cout << "[Guard] A strange man is appeared in your house!" << endl;
  if(rand()%100 <= ability){
    cout << "The strange man was dismissed by" << name <<"! (Success)" << endl;
    reward += 1000;
    cout << name << " got 1000 yen. (Total prize: " << reward << " yen)" << endl;
    return 1;
  }
  else{
    cout << "The strange man could enter into the house. (Fail)" << endl;
    return 0;
  }
}


Cat::Cat(){
  nikukyu = 30;
}
void Cat::nekojarashi(void){
  cout << "[Nekojarashi] " << name << " jumped to the nekojarashi." << endl;
}
void Cat::kotatsu(void){
  cout << name << " get rounded in kotatsu." << endl;
}
void Cat::cry(void){
  cout << name << " cries.   Nyaan! Nyaaaan!" << endl;
}


Lion::Lion(){
  fang_strength = 100;
  target = -1;
}
void Lion::set_target(string val){
  target = val;
  cout << "Target set (" << name << "): " << target << endl;
}
void Lion::hunt(void){
  cout << name <<" hunted " << target << "." << endl;
}

//(Q3) オリジナル　Tigerクラス
Tiger::Tiger(){
  speed = 0;
  bodylength = 0;
  weight = 0;
  rival = -1;
  hometown = -1;
}
void Tiger::set_speed(int val){
  speed = val;
  cout << "Speed : " << speed << "km/h" << "." << endl;
}
void Tiger::set_bodylength(int val){
  bodylength = val;
  cout << "Body Length : " << bodylength << "cm" << "." << endl;
}
void Tiger::set_weight(int val){
  weight = val;
  cout << "Weight : " << weight << "kg" << "." << endl;
}
void Tiger::show_theme(void){
  cout << "Shining our name, "<< name << " Tigers!" << endl;
}
void Tiger::set_rival(string val){
  rival = val;
  cout << "Our rival is " << rival << "." << " by "
  << name << endl;
}
void Tiger::set_hometown(string val){
  hometown = val;
  cout << "Our hometown is " << hometown << ".(Koshien Baseball Stadium)"
  << endl;
}
void Tiger::color(void){
  cout << "Color --> Yellow & Black" << endl;
}
/*(Q2)
セッターの部分を削除したとき継承元であるAnimalクラスのデフォルトコンストラクタで定義せれているname(Ken),age(5),hungry(10)が実行される。

(出力結果)
Name: Ken  Age: 5  Hungry: 10
[Frisbee] You threw a frisbee.
Ken caught the frisbee! (Success)
Ken cries.   Nyaan! Nyaaaan!
Ken hunted �.

Name: Ken  Age: 5  Hungry: 10
Ken barks.  Bow!! BoW!!
[Guard] A strange man is appeared in your house!
The strange man could enter into the house. (Fail)
[Nekojarashi] Ken jumped to the nekojarashi.

Name: Ken  Age: 5  Hungry: 10
[Frisbee] You threw a frisbee.
Ken caught the frisbee! (Success)
Ken barks.  Bow!! BoW!!
[Guard] A strange man is appeared in your house!
The strange man was dismissed byKen! (Success)
Ken got 1000 yen. (Total prize: 1000 yen)
Ken get rounded in kotatsu.

Name: Ken  Age: 5  Hungry: 10
Ken cries.   Nyaan! Nyaaaan!
Ken get rounded in kotatsu.
[Nekojarashi] Ken jumped to the nekojarashi.
Ken hunted �.

Name: Ken  Age: 5  Hungry: 10
Ken cries.   Nyaan! Nyaaaan!
Ken get rounded in kotatsu.
[Nekojarashi] Ken jumped to the nekojarashi.
Ken hunted �.
[Frisbee] You threw a frisbee.
Ken failed to catch the frisbee! (Fail)

*/

/*(Q3)
(出力結果)
[ex07-1.cc Q3]-------------------------
Name: Hanshin  Age: 19  Hungry: 10
[EAT] Hanshin got a feed. (10 -> 110)
Target set (Hanshin): Orange Rabbit
Hanshin hunted Orange Rabbit.
Speed : 65km/h.
Body Length : 120cm.
Weight : 200kg.
Shining our name, Hanshin Tigers!
Our rival is Giants. by Hanshin
Our hometown is Nishinomiya.(Koshien Baseball Stadium)
Color --> Yellow & Black

*/

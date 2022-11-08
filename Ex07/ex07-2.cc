/* s1240211 関　翔太　*/

#include <iostream>
#include <string>
#include <random>

using namespace std;

class CurryRoux{
protected: //継承されるprivateはprotected指定に
  string chef1,chef2;
  string meal;
  string secret;
  int level;
  int calorie_roux;
  string vegetable1,vegetable2,vegetable3;

public:
    CurryRoux();
    void set_chef(string,string);
    void set_meal(string);
    void set_secret(string);
    int get_calorie_roux(void);
    void set_cutting(string,string,string);
    void stew(void);
};


class Rice{
protected: //継承されるprivateはprotected指定に
 string charge1,charge2;
 string origin_place;
 int quantity;
 string meigara;
 int calorie_rice;

public:
    Rice();
    void set_charge_person(string,string);
    void set_origin_place(string);
    void set_quantity(int);
    void set_meigara(string);
    int get_calorie_rice(void);
    void steam(void);
};


class CurryRice : public CurryRoux,public Rice{
private:
  string review;
  int star;
  string restaurant;
  int calorie_total;

public:
    CurryRice();
    string get_review(void);
    int get_star(void);
    void set_restaurant(string);
    int calculate_calorie(int,int);
};

int main(){
  CurryRice cr;
  int calorie_a,calorie_b;

  cout << endl << "[ Welcome to my restaurant ]"<< endl;

  cout << "Let's cook CurryRoux!" << endl;
  cr.set_chef("Chiemi","withB");
  cr.set_meal("Beaf");
  cr.set_secret("wine");
  calorie_a = cr.get_calorie_roux();
  cout << "CurryRoux Calorie : " << calorie_a << endl;
  cr.set_cutting("onion","potato","carrot");
  cr.stew();
  cout << "----------------------------------------------" << endl;

  cout << "Next,let's cook Rice!" << endl;
  cr.set_charge_person("Tadokoro","Sekimachi");
  cr.set_origin_place("Akita");
  cr.set_quantity(1);
  cr.set_meigara("Akitakomachi");
  calorie_b = cr.get_calorie_rice();
  cout << "Rice Calorie : " << calorie_b << endl;
  cr.steam();
  cout << "----------------------------------------------" << endl;

  cout << "Finally, let's cook Curry and Rice!" << endl;
  cout << "customer's review : " << cr.get_review() << endl;
  cout << "This curry and rice is...  " << "Star " << cr.get_star() << "!!" << endl;
  cr.set_restaurant("Indian Curry shop");
  cout << "Curry and Rice calorie : "
  << cr.calculate_calorie(calorie_a,calorie_b) << endl;

  cout << "Thank you very match!" << endl << endl;

  return 0;
}

//CurryRouxメソッド
CurryRoux::CurryRoux(){
  string chef1 = " ",chef2 = " ";
  string meal = " ";
  string secret = " ";
  int calorie_roux = 0;
  string vegetable1 = " ",vegetable2 = " ",vegetable3 = " ";
}
void CurryRoux::set_chef(string val1,string val2){
  chef1 = val1;
  chef2 = val2;
  cout << "Charge in person of CurryRoux is " << chef1 << " " << chef2 << "!" << endl;
}
void CurryRoux::set_meal(string val){
  meal = val;
  cout << "using meal : " << meal << endl;
}
void CurryRoux::set_secret(string val){
  secret = val;
  cout << "secret ingredient : " << secret << endl;
}
int CurryRoux::get_calorie_roux(void){
  random_device rnd;
  calorie_roux = rnd()%500+200;
  return calorie_roux;
}
void CurryRoux::set_cutting(string val1,string val2,string val3){
  vegetable1 = val1;
  vegetable2 = val2;
  vegetable3 = val3;

  cout << "Vegetables : " << vegetable1 << "|" << vegetable2 << "|"
  << vegetable3 << endl;
}
void CurryRoux::stew(void){
  cout << " Jikkuri koto koto " << endl;
}

//Riceメソッド
Rice::Rice(){
  string charge1 = " ",charge2 = " ";
  string origin_place = " ";
  int quantity = 0;
  string meigara = " ";
  int calorie_rice = 0;
}
void Rice::set_charge_person(string val1,string val2){
  charge1 = val1;
  charge2 = val2;
  cout << "Charge in person Rice is " << charge1 << " & " << charge2 << endl;
}
void Rice::set_origin_place(string val){
  origin_place = val;
  cout << " Rice | origin place : " << origin_place << endl;
}
void Rice::set_quantity(int val){
  quantity = val;
  cout << "Rice quantity : " << quantity << "kg" << endl;
}
void Rice::set_meigara(string val){
  meigara = val;
  cout << "Name : " << meigara << endl;
}
int Rice::get_calorie_rice(void){
  random_device rnd;
  calorie_rice = rnd()%300+100;
  return calorie_rice;
}
void Rice::steam(void){
  cout << "Tasuketekureeeeeeei !!" << endl;
}
//CurryRiceメソッド
CurryRice::CurryRice(){
  string review = " ";
  int star = 0;
  string restaurant = " ";
  int calorie_total = 0;
}
string CurryRice::get_review(void){
  review = "It's so good!";
  return review;
}
int CurryRice::get_star(void){
  random_device rnd;
  star = rnd()%5+1;
  return star;
}
void CurryRice::set_restaurant(string val){
  restaurant = val;
  cout << "Restaurant : " << restaurant << endl;
}
int CurryRice::calculate_calorie(int val1,int val2){
  calorie_total = val1 + val2;
  return calorie_total;
}

/*
(実行結果)
$ ./a.out

[ Welcome to my restaurant ]
Let's cook CurryRoux!
Charge in person of CurryRoux is Chiemi withB!
using meal : Beaf
secret ingredient : wine
CurryRoux Calorie : 629
Vegetables : onion|potato|carrot
 Jikkuri koto koto
----------------------------------------------
Next,let's cook Rice!
Charge in person Rice is Tadokoro & Sekimachi
 Rice | origin place : Akita
Rice quantity : 1kg
Name : Akitakomachi
Rice Calorie : 206
Tasuketekureeeeeeei !!
----------------------------------------------
Finally, let's cook Curry and Rice!
customer's review : It's so good!
This curry and rice is...  Star 1!!
Restaurant : Indian Curry shop
Curry and Rice calorie : 835
Thank you very match!

*/

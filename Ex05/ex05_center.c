#include <stdio.h>

double center(int,int);

typedef struct{
 int x1;
 int x2;
}Test;

int main(){
  Test a,b;

  scanf("%d",&a.x1);
  scanf("%d",&a.x2);

  printf("a: %f\n",center(a.x1,a.x2));
  printf("b: %f\n",center(b.x1,b.x2));

  return 0;
}

double center(int x1,int x2){
  return (x1+x2)*0.5;
}

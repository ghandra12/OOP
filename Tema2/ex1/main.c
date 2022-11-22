#include <stdio.h>
#include <stdlib.h>
void f(int *a, int *b){
int aux;
aux=*a;
*a=*b;
*b=aux;

}
int main()
{
  int a,b;
  scanf("%d%d",&a,&b);
  printf("%d %d\n", a,b);
  f(&a,&b);
  printf("%d %d", a,b);
  return 0;
}

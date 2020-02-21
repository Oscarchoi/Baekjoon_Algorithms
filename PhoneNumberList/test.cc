#include<cstdio>
#include<cstring>

int main(){
  char a[11] = "918";
  char b[11] = "918664648";
  int res = strcmp(a,b);
  printf("%d",res);
  return 0;
}
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main(){

  char c[9];  
  scanf("%s",c);

  int len = strlen(c);
  
  // Bubble sort
  for(int i=0; i<len-1; ++i){
    for(int j=0; j<len-i-1; ++j){
      if(c[j]<c[j+1]) swap(c[j],c[j+1]);      
    }
  }
  
  printf("%s\n",c);
  return 0;
}

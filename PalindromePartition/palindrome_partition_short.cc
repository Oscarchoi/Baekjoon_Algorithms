#include<stdio.h>
int input, dp[501] = {1,2,};

int get(int n){
  if(dp[n]) return dp[n];
  dp[n] = get(n-1)+get(n/2);
  return dp[n];
}

int main(){
  int N;
  scanf("%d",&N);
  while(N--){
    scanf("%d",&input);
    printf("%d\n",get(input/2));
  }
  return 0;
}

#include<iostream>
using namespace std;

int N;
int input, dp[501] = {1,2,};

int get(int n){
  if(dp[n]) return dp[n];
  dp[n] = get(n-1)+get(n/2);
  return dp[n];
}

int main(){
  cin>>N;
  for(int i=0; i<N; ++i) {
    cin>>input; 
    cout<<get(input/2)<<"\n";
  }  
  return 0;
}

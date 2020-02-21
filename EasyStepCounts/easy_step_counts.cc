#include<iostream>
using namespace std;

int dp[5] = {1,2,2,2,2}, temp[5];
int N, mod = 1e9;

int main(){
  cin>>N;
  while(--N){
    temp[0] = dp[1];    
    temp[1] = (dp[0]+dp[2])%mod;
    temp[2] = (dp[1]+dp[3])%mod;
    temp[3] = (dp[2]+dp[4])%mod;
    temp[4] = (dp[3]+dp[4])%mod;
    for(int i=0;i<5; ++i) dp[i] = temp[i];
  }

  int total=0;
  for(int i=0;i<5; ++i) {
    total = (total + dp[i])%mod;    
  }
  cout<<total%mod<<"\n";
  return 0;
}
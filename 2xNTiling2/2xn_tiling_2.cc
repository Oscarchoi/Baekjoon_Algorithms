#include<iostream>
using namespace std;

int num,dp[1001];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin>>num;
  dp[1] = 1;
  dp[2] = 3;
  
  for(int i=3; i<=num; ++i) dp[i] = (2*dp[i-2] + dp[i-1])%10007;   
  cout<<dp[num]<<"\n";
  return 0;
}

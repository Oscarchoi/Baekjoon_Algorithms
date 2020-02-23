#include<iostream>
using namespace std;

int N,K,dp[10001];
bool hasOne=false;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin>>N>>K;  
  int tmp;    
  for(int i=0; i<N; ++i){
    cin>>tmp;    
    if(tmp==1) {
      hasOne=true;
      continue;
    }
    for(int r=K/tmp, f=1; r>0; f<<=1){
      if(r<f) f=r;
      int rv = tmp*f;
      for(int j=K-rv; j>0; --j){
        if(dp[j]) {
          dp[j+rv] = dp[j+rv] ? min(dp[j]+f, dp[j+rv]) : dp[j]+f;
          //cout<<"rv: "<<rv<<", dp["<<j+rv<<"] "<<dp[j+rv]<<endl;
        }
      }
      dp[rv] = dp[rv] ? min(dp[rv],f) : f;
      //cout<<"dp["<<rv<<"] "<<dp[rv]<<endl;
      r -= f;      
    }
  }  

  if(hasOne){    
    dp[1]=1;
    for(int i=1; i<K; ++i){
      if(dp[i]) dp[K] = dp[K] ? min(dp[i]+K-i,dp[K]) : dp[i]+K-i;
    }    
  }
  if(dp[K]) cout<<dp[K]<<"\n";  
  else cout<<"-1\n";  
  return 0;
}
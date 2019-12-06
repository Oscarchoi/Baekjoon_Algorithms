#include<iostream>
using namespace std;

int N,n;
int dp[1000] = {1,1,2,};

int getDp(int a){
  if(dp[a]) return dp[a];
  return getDp(a-1)+getDp(a-2)+getDp(a-3);
}

int main(){
  ios::sync_with_stdio(false); 
  cin.tie(NULL);
 
  cin>>N;
  for(int i=0; i<N; ++i){
    cin>>n;
    cout<<getDp(n)<<"\n";
  }
  return 0;
}

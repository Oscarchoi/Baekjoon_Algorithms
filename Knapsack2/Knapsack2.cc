#include<iostream>
using namespace std;

int N,K,Max=0;
int chart[10001]={};

int main(){
  ios::sync_with_stdio(false); 
  cin.tie(NULL);

  cin>>N>>K;
  int w,v,n,rw,rv;  
  for(int i=0; i<N; ++i){
    cin>>w>>v>>n;
    for(int exp=1; n>0; exp<<=1){
      int factor = min(exp,n);
      rw = w*factor;
      rv = v*factor;
      n -= exp;
      for(int j=K-rw; j>=0; --j){
        if( chart[j]==0 && j ) continue;
	chart[j+rw] = max(chart[j+rw],chart[j]+rv);
      }
    }
  }
  for(int i=1; i<=K; ++i) if(chart[i]>Max) Max = chart[i];
  cout<<Max<<"\n";
  return 0;
}
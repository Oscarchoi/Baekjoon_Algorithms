#include<iostream>
using namespace std;

int N;
int wine[10000];
int fc[10000], nc[10000];

int main(){

  cin>>N;
  for(int i=0;i<N;++i) cin>>wine[i];
  fc[0]=wine[0];
  nc[1]=fc[0];
  fc[1]=fc[0]+wine[1];
  
  for(int i=2; i<N; ++i){
    nc[i] = max(nc[i-1],fc[i-1]);
    fc[i] = nc[i-2]+wine[i-1]+wine[i];

  }



  return 0;
}

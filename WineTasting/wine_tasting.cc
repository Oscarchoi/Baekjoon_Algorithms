#include<iostream>
using namespace std;

int N;
int wine[10001], fc[10001], nc[10001];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>N;
  for(int i=1;i<N+1;++i) cin>>wine[i];
  fc[1]=wine[1];
  
  for(int i=2; i<N+1; ++i){
    nc[i] = max(max(nc[i-1],fc[i-1]),nc[i-2]+wine[i-1]);
    fc[i] = nc[i-2]+wine[i-1]+wine[i];
  }
  int result = max(max(fc[N],nc[N]),nc[N-1]+wine[N]);
  cout<<result<<"\n";
  return 0;
}

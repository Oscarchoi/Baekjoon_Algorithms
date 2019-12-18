#include<iostream>
using namespace std;
const int INT_MAX = 10000001;
int G[101][101];
int N,E,a,b,c,i,j;

int main(){
  ios::sync_with_stdio(false); 
  cin.tie(NULL);
  cin>>N>>E;
  for(i=0; i<N; ++i) for(j=0; j<N; ++j) G[i][j] = INT_MAX;
  for(i=0; i<N; ++i) G[i][i] = 0;
  while(E--) {
    cin>>a>>b>>c;
    if(G[a-1][b-1]>c) G[a-1][b-1]=c;
  }
  
  for(int k=0; k<N; ++k)
    for(i=0; i<N; ++i) for(j=0; j<N; ++j)
      if(i!=j && G[i][j] > G[i][k]+G[k][j])
	G[i][j] = G[i][k]+G[k][j];    
    
  for(i=0; i<N; ++i){
    for(j=0; j<N; ++j)
      cout<<(G[i][j]==INT_MAX?0:G[i][j])<<" ";
    cout<<"\n";
  }
  return 0;
}

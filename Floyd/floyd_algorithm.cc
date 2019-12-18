#include<iostream>
using namespace std;

const int INT_MAX = 10000001;
int G[100][100];
int N,E,a,b,c;

int main(){
  cin>>N>>E;
  for(int i=0; i<100; ++i)
    for(int j=0; j<100; ++j)
      G[i][j] = i==j ? 0 : INT_MAX;

  while(E--) {
    cin>>a>>b>>c;
    if(G[a-1][b-1]>c) G[a-1][b-1]=c;
  }
  
  for(int k=0; k<N; ++k)
    for(int i=0; i<N; ++i)
      for(int j=0; j<N; ++j)
	G[i][j] = min(G[i][j],G[i][k]+G[k][j]);    
    
  for(int i=0; i<N; ++i){
    for(int j=0; j<N; ++j)
      cout<<(G[i][j]==INT_MAX?0:G[i][j])<<" ";
    cout<<"\n";
  }
  return 0;
}

#include<iostream>

using namespace std;

int* forest, *chart;
int N;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int queryLife(int x, int y){
  int& life = chart[x*N+y];
  if(life) return life; 
  
  int longerLife=0;
  for(int i=0; i<4; ++i){
    if( x==0 || x==N-1 || y==0 || y==N-1 ) continue;
    int X=x+dx[i], Y=y+dy[i];
    if( forest[X*N+Y] > forest[x*N+y])
      longerLife = queryLife(X,Y) < longerLife ? longerLife : queryLife(X,Y);
  }
  return (life=++longerLife);
}

int main(){
  int result=1;
  cin>>N;
 
  forest = new int[N*N]{};
  chart = new int[N*N]{};
  
  for(int i=0; i<N; ++i)
    for(int j=0; j<N; ++j)
      cin>>forest[i*N+j];
  
  for(int i=0; i<N; ++i)
    for(int j=0; j<N; ++j){
      if(chart[i*N+j]) continue;
      if(queryLife(i,j)>result) result=queryLife(i,j);
    }

  cout<<result;
  return 0;
}

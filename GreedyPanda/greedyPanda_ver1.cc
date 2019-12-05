#include<iostream>
using namespace std;

int *forest, *chart;
int N;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int queryLife(int x, int y){
  int& life = chart[x*N+y];
  if(life) return life; 
  int cur = forest[x*N+y];

  for(int i=0; i<4; ++i){
    int X=x+dx[i], Y=y+dy[i];
    if( X<0 || X==N || Y<0 || Y==N ) continue;   
    if( forest[X*N+Y] > cur && queryLife(X,Y) > life)
      life = queryLife(X,Y);
  }
  return ++life;
}

int main(){
  int result=1;

  cin>>N;
  int total = N*N; 
  forest = new int[total];
  chart = new int[total];

  for(int i=0; i<total; ++i) cin>>forest[i];
  
  for(int i=0; i<N; ++i) for(int j=0; j<N; ++j)
    if( !chart[i*N+j] && queryLife(i,j)>result )
      result=queryLife(i,j);  

  cout<<result<<endl;
  return 0;
}

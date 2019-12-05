#include<iostream>
using namespace std;

int forest[500][500], chart[500][500];
int N, Max=1;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void queryLife(int x, int y){ 
  int& life = chart[x][y];
  for(int i=0; i<4; ++i){
    int X=x+dx[i], Y=y+dy[i];
    if( X<0 || X==N || Y<0 || Y==N ) continue;   
    if( forest[X][Y] > forest[x][y] ){
      if( chart[X][Y]==0 ) queryLife(X,Y);
      life = max(chart[X][Y],life);
    }
  }  
  Max = max(Max, ++life);
  return;
}

int main(){
  ios::sync_with_stdio(false); 
  cin.tie(NULL);
  cin>>N;
  for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) cin>>forest[i][j];  
  for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) if(not chart[i][j]) queryLife(i,j);
  cout<<Max<<"\n";
  return 0;
}

#include<iostream>
#include<queue>
using namespace std;

int M,N,Day;
int dX[4] = {1,0,-1,0}, dY[4] = {0,-1,0,1}; 
int G[1000][1000];
queue<pair<int,int>> Queue;
pair<int,int> pos;
int q;

void bfs(pair<int,int>& pos,int dir){
  int& value = G[pos.first+dX[dir]][pos.second+dY[dir]];
  if(value == 0 ) {
    value = G[pos.first][pos.second]+1;
    Queue.push({pos.first+dX[dir],pos.second+dY[dir]});
//    for(int i=0; i<N; ++i) { for(int j=0; j<M; ++j) cout<<G[i][j]<<" "; cout << "\n"; }
//      cout<<"\n";
  }
  return;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>M>>N;

  for(int i=0; i<N; ++i) for(int j=0; j<M; ++j){
    cin>>G[i][j];
    if(G[i][j]==1) Queue.push({i,j});
  }

  while(not Queue.empty()){
    pos=Queue.front();
    Queue.pop();
    for(int k=0; k<4; ++k){
      if(pos.first<N-1) bfs(pos,0);
      if(pos.second>0) bfs(pos,1);
      if(pos.first>0) bfs(pos,2);
      if(pos.second<M-1) bfs(pos,3);
    }   
  }

  for(int i=0; i<N; ++i) {
    for(int j=0; j<M; ++j){
      if(G[i][j] == 0) { cout<<-1<<"\n"; return 0;}
      Day = max(Day, G[i][j]);
    }
  }
  cout<<Day-1<<"\n";

  return 0;
}

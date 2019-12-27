#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int INF = 10000;
int N,count;
int blackrupee[125][125], map[125][125];

int delta[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

struct block {
  int x,y,rp;
};
bool operator< (const block& lhs, const block& rhs) {
    return lhs.rp > rhs.rp;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  while(1){
    cin>>N;
    if(N==0) return 0;
    for(int i=0; i<N; ++i) for (int j=0; j<N; ++j) {
      map[i][j] = INF;
      cin>>blackrupee[i][j];
    }
    map[0][0] = blackrupee[0][0];

    priority_queue<block> pq;
    pq.push(block{0,0,map[0][0]});
    

    while(not pq.empty()){
      block now = pq.top();
      pq.pop();
      //cout<<"now["<<now.x<<","<<now.y<<"] = "<<now.rp<<"\n";

      int nx=now.x, ny=now.y, nr=now.rp;
      int cost = map[nx][ny];
      
      if(now.rp > cost) continue;
      if(nx==N-1 && ny==N-1) break; 
      if( nx > 0 && map[nx-1][ny] > cost + blackrupee[nx-1][ny]){
        map[nx-1][ny] = cost + blackrupee[nx-1][ny];
        pq.push(block{nx-1,ny,map[nx-1][ny]});
      }
      if( nx < N-1 && map[nx+1][ny] > cost + blackrupee[nx+1][ny]){
        map[nx+1][ny] = cost + blackrupee[nx+1][ny];
        pq.push(block{nx+1,ny,map[nx+1][ny]});
      }
      if( ny > 0 && map[nx][ny-1] > cost + blackrupee[nx][ny-1]){
        map[nx][ny-1] = cost + blackrupee[nx][ny-1];
        pq.push(block{nx,ny-1,map[nx][ny-1]});
      }
      if( ny < N-1 && map[nx][ny+1] > cost + blackrupee[nx][ny+1]){
        map[nx][ny+1] = cost + blackrupee[nx][ny+1];
        pq.push(block{nx,ny+1,map[nx][ny+1]});
      }
    }
    cout<<"Problem "<<++count<<": "<<map[N-1][N-1]<<"\n"; 
  }
  return 0;
}
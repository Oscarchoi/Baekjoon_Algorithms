#include<iostream>
using namespace std;

int order[301][301];

int main(){  
  int N, M, K, Ans=0;
  cin>>N>>M>>K;

  int tm, tk, x, y;
  while(N--){
    cin>>tm>>tk;
    for(x=M-tm; x>0; --x)
      for(y=K-tk;y>0; --y){
	if(!order[x][y]) continue;
	int& tmp =order[x+tm][y+tk];
	if(order[x][y]+1>tmp) tmp = order[x][y]+1;
	if(tmp>Ans) Ans=tmp;
    }
  }
  cout<<Ans<<"\n";
  return 0;
}

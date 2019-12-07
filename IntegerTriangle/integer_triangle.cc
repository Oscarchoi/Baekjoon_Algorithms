#include<iostream>
using namespace std;

int tri[500][500]; 
int N;

int main(){
  ios::sync_with_stdio(false); 
  cin.tie(NULL);
  cin>>N;
  for(int i=0;i<N;++i)
    for(int j=0;j<=i;++j)
      cin>>tri[i][j]; 

  for(int i=N-2;i>=0;--i){
    for(int j=0;j<=i;++j){
      tri[i][j]+=max(tri[i+1][j],tri[i+1][j+1]);
    }
  }

  cout<<tri[0][0]<<"\n";
  return 0;
}




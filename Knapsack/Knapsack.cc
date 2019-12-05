#include<iostream>
using namespace std;

int N,K,Max=0;
int item[200];
int chart[100001]={};

int main(){
  ios::sync_with_stdio(false); 
  cin.tie(NULL);

  cin>>N>>K;
  for(int i=0; i<N; ++i) cin>>item[2*i]>>item[2*i+1];
  for(int i=0; i<N; ++i){
    for(int j=K-item[2*i]; j>0; --j){
      if( j<0 || chart[j]==0) continue;
      chart[j+item[2*i]]  = max(chart[j+item[2*i]],chart[j]+item[2*i+1]);
      //    cout<<"chart["<<j+item[2*i]<<"] = "<< chart[j+item[2*i]]<<endl; 
    }
    chart[item[2*i]]=max(chart[item[2*i]],item[2*i+1]);
  }

  for(int i=1; i<=K; ++i) if(chart[i]>Max) Max = chart[i];
  cout<<Max<<"\n";
  return 0;
}

#include<iostream>
using namespace std;

int N,total[11];
short h;
short bd[1000];

int main(int argc, char** argv){
  for(int test_case=1; test_case <= 10; ++test_case){
    cin>>N;
    for(int i=0; i<N; ++i){
      cin>>h;
      bd[i]=h;
    }
    
    int rhm, lhm;
    for(int i=2; i<N-2; ++i){    
      lhm = max(bd[i-1],bd[i-2]);
      if(bd[i] <= lhm) continue;
      rhm = max(bd[i+1], bd[i+2]);
      if(bd[i] <= rhm ) continue;

      total[test_case] += bd[i] - max(lhm, rhm);
    }
    
  }
  for(int i=1; i<=10; ++i){
    cout<<"#"<<i<<" "<<total[i]<<"\n"; 
  }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
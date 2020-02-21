#include<iostream>
using namespace std;

int num;

int calc(int i){   
  return i<2 ? 0 : min(calc(i/2)+i%2,calc(i/3)+i%3)+1;  
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>num;
  cout<<calc(num)<<"\n";
  return 0;
}

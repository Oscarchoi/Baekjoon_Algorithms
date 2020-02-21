#include<iostream>

int N, bottom, top, sum, temp, total, min=-1001;

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin>>N;
  while(N--){
    std::cin>>temp;
    if(temp<=0 && min < temp) min = temp;    
    sum += temp;
    if(sum < bottom){
      top = bottom = sum;
    } else if(sum > top){
      top = sum;
      if(total < top-bottom) total = top-bottom;      
    }
  }  
  std::cout<<(total>0 ?total :min)<<"\n";
  return 0;
}
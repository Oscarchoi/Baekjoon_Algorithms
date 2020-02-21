#include<cstdio>
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int num;
struct House {
  int r,g,b;
} res;

void solve(const House& temp, House prev){
  res.r = temp.r + MIN(prev.g,prev.b);
  res.g = temp.g + MIN(prev.r,prev.b);
  res.b = temp.b + MIN(prev.r,prev.g);  
}

int main(){
  scanf("%d",&num);  
  
  House temp;
  for(int i=1; i<num+1; ++i){
    scanf("%d %d %d",&temp.r,&temp.g,&temp.b);    
    solve(temp,res);
  }   
  printf("%d\n",MIN(res.r,MIN(res.g,res.b)));
  return 0;
}
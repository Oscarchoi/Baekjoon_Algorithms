#include<cstdio>
#include<cstring>
#include<string>

bool check=true;
int T,N;

struct Number{
  char n[11];
  int l,r;
} nums[10001];

bool push(int nb,int ob){  
  int res = strcmp(nums[nb].n,nums[ob].n);
  if(res>10 || res<-10) return false;
  else if(res>0) {
    if(nums[ob].r>0) return push(nb,nums[ob].r);
    else nums[ob].r = nb;
  } else {  
    if(nums[ob].l>0) return push(nb,nums[ob].l);
    else nums[ob].l = nb;    
  }  
  return true;
}


int main(){
  scanf("%d",&T);
  while(T--){
    check = true;
    scanf("%d",&N);    
    for(int i=0; i<N; ++i) {
      nums[i].l = nums[i].r = -1;
      scanf("%s",nums[i].n);
    }
    for(int i=1; i<N; ++i){
      if(!push(i,0)) {
        check = false;
        break;
        //printf("Found dupl at %d\n",i);        
      }
    }
    if(check) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}
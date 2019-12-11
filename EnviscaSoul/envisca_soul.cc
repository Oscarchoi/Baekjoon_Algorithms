#include<iostream>
using namespace std;

int n,a,b,m;

int main(){
  cin>>n>>a>>b;
  if(a++<b++) swap(a,b);
  
  int an = n/a, ar = n%a;
  int bn = ar/b, br = ar%b;
  int p = a/b, q = a%b;

  if( br==0 ) {
    cout<<an+bn<<"\n";
  } else if ( q==0 || p + q - b >= 0 ){
    cout<<an+bn+br<<"\n";
  } else {
    m = br;
    for(int i=1; i<=an; ++i)
      m = min(m,(p-1)*i + (br+i*q)/b + (br+i*q)%b);
    cout<<an+bn+m<<"\n";
  }

  return 0;
}

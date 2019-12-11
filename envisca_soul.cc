#include<iostream>
using namespace std;

int n,a,b;

int main(){
  cin>>n>>a>>b;
  if(a++<b++) swap(a,b);
  
  int an = n/a, ar = n%a;
  int bn = ar/b, br = ar%b;
  cout<<an<<", "<<ar<<", "<<bn<<", "<<br<<endl;

  if( br == 0 ) {
    cout<<an+bn<<"a\n";
    return 0;
  }

  int p=a/b, q=a%b;
  if( q==0 ||  p + q - b >= 0 ){
    cout<<an+bn+br<<" b"<<p+q-b<<"\n";
    return 0;
  }
  
  int m = br;
  for(int i=1; i<=an; ++i){
    m = min(m,(p-1)*i + (br+i*q)/b + (br+i*q)%b);
  }

  cout<<an+bn+n<<"\n";
  
  return 0;
}

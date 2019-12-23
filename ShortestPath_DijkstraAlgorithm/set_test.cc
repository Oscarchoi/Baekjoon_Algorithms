#include <iostream>
#include <set>
using namespace std;

int main(){


  // Normal set
  set<pair<int,int>> s;
  s.emplace(make_pair(1,3));
  s.emplace(make_pair(1,2));
  s.emplace(make_pair(2,2));
  for(auto e : s) cout<<"("<<e.first<<", "<<e.second<<")"<<endl;
  cout<<endl;

  // Custom set
  struct cmp{
    bool operator()(pair<int,int> lhs, pair<int,int> rhs){
      return lhs.second < rhs.second ? true : lhs.first < rhs.first ? true : false ;
    }
  };
  set<pair<int,int>,cmp> sq;

  sq.emplace(make_pair(1,2));
  sq.emplace(make_pair(1,3));
  sq.emplace(make_pair(2,3));
  for(auto e : sq) cout<<"("<<e.first<<", "<<e.second<<")"<<endl;



  return 0;
}

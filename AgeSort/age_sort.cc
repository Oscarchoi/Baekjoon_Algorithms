#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int N;
struct Person {
  int age, order;
  string name;
};

bool operator<(const Person& lhs, const Person& rhs){
  return lhs.age != rhs.age ? lhs.age < rhs.age : lhs.order < rhs.order;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  cin>>N;
  Person people[N];
  
  for(int i=0; i<N; ++i){
    people[i].order = i;
    cin>>people[i].age>>people[i].name;    
  }

  std::sort(people, people+N);

  for(int i=0; i<N; ++i)
    cout<<people[i].age<<" "<<people[i].name<<"\n";

  return 0;
}
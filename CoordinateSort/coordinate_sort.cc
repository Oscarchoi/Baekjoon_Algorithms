#include <stdio.h>
#include <algorithm>

int N;
struct Point{
  int x,y;
};
bool operator<(const Point& lhs, const Point& rhs){
  return lhs.x != rhs.x ? lhs.x < rhs.x : lhs.y < rhs.y;
}

Point points[100000];

int main(){
  scanf("%d",&N);
  for(int i=0; i<N; ++i){
    scanf("%d %d",&points[i].x,&points[i].y);
  }

  std::sort(points,points+N);

  for(int i=0; i<N; ++i)
    printf("%d %d\n",points[i].x,points[i].y);

  return 0;
}
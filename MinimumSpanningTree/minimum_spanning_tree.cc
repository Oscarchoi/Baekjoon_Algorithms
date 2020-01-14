#include<iostream>
#include<vector>
using namespace std;

struct Node {
  int root,cost,height;
};
vector<Node> disjoint_set;

void merge(Node& lhs, Node& rhs){
  // already in same set
  if(lhs.root == rhs.root) return; 
    
  // put lower height tree into higher one
  if(lhs.height > rhs.height) {
    rhs.root = lhs.root;
    lhs.height += rhs.height;
    rhs.height = 1;
  } else {
    lhs.root = rhs.root;
    rhs.height += lhs.height;
    lhs.height = 1;
  }
};

int find(int index){
  int root = disjoint_set[index].root;    
  // path compression if node is not root
  return root == index ? index : disjoint_set[index].root = find(root);  
};

int main(){


  return 0;
}
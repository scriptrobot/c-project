#include "binarySearch.h"
#include <vector>

using namespace std;


int main(){
    vector<int> vec = {1,2,3,4,5,6};
    int k;
    while(cin>>k){
        cout<<binarySearch(vec.begin(),vec.end(),k)<<endl; 
    }
}


/*
struct Node{
    int a;
    Node(){};
    Node(int t):a(t){}
    bool operator==(const Node& node){
        return node.a == a; 
    }
};
bool operator<(const Node& node1,const Node& node2){
    if(node1.a < node2.a){
        return true; 
    }
    return false;
}

int main(){
   Node a[11];
   for(int i = 0;i < 11;i++){
       a[i].a = i; 
   }
   int k;
   while(cin>>k){
        cout<<binarySearch(begin(a),end(a),Node(k))<<endl; 
   }
}
*/

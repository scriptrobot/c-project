#include "quickSort.h"
#include <vector>

using namespace std;

/*
int main(){
    vector<int> vec = {1,2,3,2,3,2,1,3,4,5,32};
    quickSort(vec.begin(),vec.end(),less<int>());
    for(auto v: vec){
        cout<<v<<" "; 
    }
    return 0;
}
*/
struct Node{
    int a;
    Node(int t):a(t){}
};
/*
bool operator<(const Node&a,const Node&b){
    if(a.a < b.a){
        return true;
    }
    return false;
}
*/
struct cmp{
    bool operator()(const Node& a,const Node& b){
        if(a.a < b.a){
            return true; 
        } 
        else{
            return false; 
        }
    }
};

int main(){
    vector<Node> vec;
    random_device rd;
    for(int i = 0;i < 10;++i){
        vec.push_back(Node(rd()%100)); 
    }
    quickSort(vec.begin(),vec.end(),cmp());
    for(int i = 0;i < 10;++i){
        cout<<vec[i].a<<" "; 
    }
}

#include "maxSubArray.h"
#include <vector>

using namespace std;

int main(){
    vector<int> vec = {1,2,3,-1,2,-3,-4};
    double a[] = {-1.1,-2.0,2.0,1.3,-1.0,2.1};
    int b[] = {-1,-2,-3,-4,-5};

    cout<<get<0>(maxSubArray_index(vec.begin(),vec.end()))<<endl;
    cout<<get<1>(maxSubArray_index(vec.begin(),vec.end()))<<endl;
    cout<<get<2>(maxSubArray_index(vec.begin(),vec.end()))<<endl;
    cout<<maxSubArray(vec.begin(),vec.end())<<endl;
    cout<<get<1>(maxSubArray_index(begin(a),end(a)))<<endl;
    cout<<get<1>(maxSubArray_index(begin(b),end(b)))<<endl;
}

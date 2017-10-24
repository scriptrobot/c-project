#include "longestCommonSubsequence.h"

using namespace std;

int main(){
    string str1 = "BDCAB";
    string str2 = "BBDCABB";
    auto vec = longestCommonSubsequence(str1.begin(),str1.end(),str2.begin(),str2.end());
    for(auto v : vec){
        cout<<v<<" "; 
    }
}

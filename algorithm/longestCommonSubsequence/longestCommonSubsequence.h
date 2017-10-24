#include <iostream>
#include <vector>
#include <algorithm>

//implete longest-common-subsequence algorithm
//return the length of common subsequence
//make sure the length of first array is shorter
template <typename InputIterator>
int longestCommonSubsequence_n(InputIterator fFirst,InputIterator fLast,
        InputIterator sFirst,InputIterator sLast){
    if(fFirst == fLast || sFirst == sLast){
        return 0; 
    } 
    //using ValueType = typename std::iterator_traits<InputIterator>::value_type;
    int fLen = 0;
    InputIterator it = fFirst;
    while(it != fLast){
        fLen++;
        it++;
    }
    std::vector<int> vec(fLen+1,0);
    InputIterator outerIt,innerIt;
    int i;
    for(outerIt = sFirst;outerIt != sLast;++outerIt){
        for(i = 1,innerIt = fFirst;innerIt != fLast;++innerIt,++i){
            if(*innerIt == *outerIt){
                vec[i] = vec[i-1]+1;
            } 
            else{
                vec[i] = std::max(vec[i-1],vec[i]); 
            }
        } 
    }
    return vec[fLen];
}

template <typename InputIterator>
std::vector<typename std::iterator_traits<InputIterator>::value_type>
longestCommonSubsequence(InputIterator fFirst,InputIterator fLast,
        InputIterator sFirst,InputIterator sLast){
    using ValueType = typename std::iterator_traits<InputIterator>::value_type;
    std::vector<ValueType> resultVec;
    if(fFirst == fLast || sFirst == sLast){
        return resultVec;
    }
    int fLen = 0,sLen = 0;
    InputIterator it = fFirst;
    while(it != fLast){
        ++fLen;
        ++it;
    }
    it = sFirst;
    while(it != sLast){
        ++sLen;
        ++it;
    }
    std::vector<std::vector<std::pair<int,char>>> vec(sLen+1,
            std::vector<std::pair<int,char>>(fLen+1,std::make_pair(0,' ')));

    InputIterator outerIt,innerIt;
    int i,j;
    for(i = 1,outerIt = sFirst;outerIt != sLast;++i,++outerIt){
        for(j = 1,innerIt = fFirst;innerIt != fLast;++j,++innerIt){
            if(*innerIt == *outerIt){
                vec[i][j].first = vec[i-1][j-1].first+1;
                vec[i][j].second = 'p';
            } 
            else{
                if(vec[i-1][j].first >= vec[i][j-1].first){
                    vec[i][j].first = vec[i-1][j].first;
                    vec[i][j].second = 'u';
                } 
                else{
                    vec[i][j].first = vec[i][j-1].first;
                    vec[i][j].second = 'l';
                }
            }
        }
    }
    int rLen = vec[sLen][fLen].first;
    resultVec.resize(rLen);
    std::vector<ValueType> firstVec(fFirst,fLast);
    while(sLen != 0 && fLen != 0){
        if(vec[sLen][fLen].second == 'p'){
            resultVec[--rLen] = firstVec[fLen-1]; 
            --fLen;
            --sLen;
        } 
        else{
            if(vec[sLen][fLen].second == 'l'){
                fLen--; 
            } 
            else{
                sLen--; 
            }
        }
    }
    return resultVec;
}

#include <iostream>
#include <tuple>

//maxSubArray_index function
//find the contiguous subarray which has the largest sum
//return a tuple type,first value is leftindex,second value if rightindex,last value is sum
//if the given array is empty,leftindex = rightindex = -1,sum = 0;
template <typename InputIterator>
std::tuple<int,int,typename std::iterator_traits<InputIterator>::value_type>
maxSubArray_index(InputIterator first,InputIterator last){
    int leftIndex = -1;
    int rightIndex = -1;
    if(first == last){
        return std::make_tuple(leftIndex,rightIndex,
               static_cast<typename std::iterator_traits<InputIterator>::value_type>(0)); 
    }
    auto maxSum = *first;
    auto curSum = *first;
    auto it = first;
    auto zero = static_cast<typename std::iterator_traits<InputIterator>::value_type>(0);
    int i,curL;
    i = curL = leftIndex = rightIndex = 0;
    while(++it != last){
        ++i;
        if(curSum < zero || (curSum+*it) < zero){
            curSum = *it;
            curL = i;
        } 
        else{
            curSum += *it; 
        }
        if(maxSum < curSum){
            maxSum = curSum;
            leftIndex = curL;
            rightIndex = i;
        }
    }
    return std::make_tuple(leftIndex,rightIndex,maxSum);
}

//maxSubArray function
//find the contiguous subarray which has the largest sum
//return the sum
//if the given array is empty,the sum is 0
template <typename InputIterator>
typename std::iterator_traits<InputIterator>::value_type
maxSubArray(InputIterator first,InputIterator last){
    return std::get<2>(maxSubArray_index(first,last));
    /*
    if(first == last){
        return static_cast<typename std::iterator_traits<InputIterator>::value_type>(0);
    }
    auto maxSum = *first;
    auto curSum = *first;
    auto it = first;
    auto zero = static_cast<typename std::iterator_traits<InputIterator>::value_type>(0);
    while(++it != last){
        if(curSum < zero || (curSum+*it) < zero){
            curSum = *it;
        }
        else{
            curSum += *it; 
        }
        if(maxSum < curSum){
            maxSum = curSum; 
        }
    }
    return maxSum;
    */
}

#include <iostream>
#include <functional>

//binarySearch function
//return the index of value
//the index of head node is 0
//return -1 if the value is not contained
template <typename RandomAccessIterator,typename T,typename Compare>
int binarySearch(const RandomAccessIterator &head,RandomAccessIterator first,
        RandomAccessIterator last,const T& value,Compare cmp){
    if(first == last || first+1 == last){
        if(first >= last || !(*first == value)){
            return -1;
        } 
        return first-head;
    }
    RandomAccessIterator mid = first+(last-first-1)/2;
    if(*mid == value){
        return mid-head;
    }
    if(cmp(*mid,value)){
        return binarySearch(head,mid+1,last,value,cmp); 
    }
    else{
        return binarySearch(head,first,mid,value,cmp); 
    }
}

//bianrySearch function
//for custom compare method
template <typename RandomAccessIterator,typename T,typename Compare>
int binarySearch(RandomAccessIterator first,
        RandomAccessIterator last,const T& value,Compare cmp){
    return binarySearch(first,first,last,value,cmp);     
}

//binarySearch function
//for default compare methood
template <typename RandomAccessIterator,typename T>
int binarySearch(RandomAccessIterator first,RandomAccessIterator last,const T& value){
    return binarySearch(first,first,last,value,std::less<T>());
}

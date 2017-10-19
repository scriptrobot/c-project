#include <iostream>
#include <random>
#include <functional>

//partition function
//using random funtion to find the position
//swap the value of this node with the first node
//the first iterator as the compare node
template<typename RandomAccessIterator,typename Compare>
RandomAccessIterator
partition(RandomAccessIterator first,RandomAccessIterator last,Compare com){
    std::random_device rd;
    RandomAccessIterator randomIte = first+(rd()%(last-first));
    if(first != randomIte){
        std::swap(*first,*randomIte);
    }
    RandomAccessIterator iIte = first;
    RandomAccessIterator jIte = first;
    while(++iIte != last){
        if(com(*iIte,*first)){
            jIte++;
            if(iIte != jIte){
                std::swap(*iIte,*jIte); 
            }
        } 
    }
    if(first != jIte){
        std::swap(*first,*jIte);
    }
    return jIte;
}

//quickSort function
//user's compare function
template<typename RandomAccessIterator,typename Compare>
void quickSort(RandomAccessIterator first,RandomAccessIterator last,Compare com){
  if(first == last || (first+1) >= last){
      return;
  }  
  RandomAccessIterator mid = partition(first,last,com);
  quickSort(first,mid,com);
  quickSort(mid+1,last,com);
}

//quickSort function
//default compare function less<value_type>()
template<typename RandomAccessIterator>
void quickSort(RandomAccessIterator first,RandomAccessIterator last){
    quickSort(first,last,std::less<typename std::iterator_traits<RandomAccessIterator>::value_type>());
}

/*
Majority Element 
Given an array of size n, find the majority element. 
The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/

/*
O(n): hasmap
O(nlg(n)): sort
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution_hasMap {
public:
    int majorityElement(vector<int> &num) {
        unordered_map<int, int> myMap; //<num, count>
        
        int i=0;
        while(i<num.size()){
            myMap[num[i]]++;
            if(myMap[num[i]]>(num.size()/2))
                return num[i];

            i++;
        }
        return num[0];
    }
};

class Solution_sort {
public:
    int majorityElement(vector<int> &num) {
        sort(num.begin(),num.end());
        int size=num.size();
        int i=0;
        while(i<(size/2)+1){
            if(num[i]==num[i+(size/2)])
                return num[i];
            i++;
        }
        
        return num[0];
    }
};

int main(){

    return 0;
}
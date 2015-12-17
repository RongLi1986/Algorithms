/*
H-Index My Submissions Question
Total Accepted: 19140 Total Submissions: 70495 Difficulty: Medium
Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, his h-index is 3.

Note: If there are several possible values for h, the maximum one is taken as the h-index.

H-Index II
Total Accepted: 13919 Total Submissions: 43910 Difficulty: Medium
Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?

it needs O(logn)
*/

//use binary search



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty()) return 0;
        int count=0;
        //sort(citations.begin(),citations.end()); //it has already ascending order

        //O(n)
        for(int i=citations.size()-1;i>=0;i--){
            int next=citations.size()-i;
            if(next<=citations[i])
                count++;
        }
        
        return count;
    }

    //o(lg(n))
    int hIndex(vector<int>& citations) {
        if(citations.empty()) return 0;
        
        int left=0;
        int right=citations.size()-1;
        int mid;
        int next;
        
        while(left<=right){
            mid=(left+right)/2;
            next=citations.size()-mid;
            if(next<=citations[mid])
                right=mid-1;
            else
                left=mid+1;   
        }
        
        //mid is last one index corner case [0] or [1]
        return next-(int)(next>citations[mid]);
    }
};

int main(){

    return 0;
}
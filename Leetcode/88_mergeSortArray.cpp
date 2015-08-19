//Merge Sorted Array
/*
Given two sorted integer arrays A and B,
merge B into A as one sorted array.

Note:
You may assume that A has enough space 
(size that is greater or equal to m + n) to 
hold additional elements from B. The number of elements 
initialized in A and B are m and n respectively.
*/

/*
just merge this two vectors
*/

#include <iostream>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(nums1.empty()||nums2.empty()) return;
        
        vector<int> res;
        
        int j=0;
        int k=0;
        while(1){
            if(j==m && k<n){
                res.push_back(nums2[k]);
                k++;
            }else if(k==n && j<m){
                res.push_back(nums1[j]);
                j++;
            }else if(k<n && j<m){
                if(nums1[j]<nums2[k]){
                    res.push_back(nums1[j]);
                    j++;
                }else if(nums1[j]>nums2[k]){
                    res.push_back(nums2[k]);
                    k++;
                }else{ //they are equal
                    res.push_back(nums1[j]);
                    j++;
                    res.push_back(nums2[k]);
                    k++;
                }
            }else{
                break;
            }
            
        }
        
        nums1=res;
        return;
    }
};


class Solution_old {
public:
    void merge(int A[], int m, int B[], int n) {
       	//A and B should be vaild

        int i=0;
        int j=0;
        int k=0;
        int* temp=new int[m+n];

        while(i<m&&j<n){
        	if(A[i]<B[j]){
        		temp[k]=A[i];
        		i++;
        		k++;
        	}else{
        		temp[k]=B[j];
        		j++;
        		k++;
        	}
        }

        while(i<m){
        	temp[k]=A[i];
        	i++;
        	k++;
        }

        while(j<n){
        	temp[k]=B[j];
        	j++;
        	k++;
        }

        for(int a=0;a<m+n;a++){
        	A[a]=temp[a];
        }
    }
};


int main(){
	int A[]={1,3,5,7,9,0,0,0,0,0};
	int B[]={2,4,6,8,10};

	Solution s;
	s.merge(A,5,B,5);

	for(int i=0;i<10;i++)
		cout<<A[i]<<" ";
	cout<<endl;

	return 0;

}
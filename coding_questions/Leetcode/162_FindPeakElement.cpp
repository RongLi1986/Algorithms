/*
Find Peak Element 
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
*/
#include <iostream>
#include <vector>
using namespace std;

/*
O(n) and O(lgn)
*/
class Solution {
    public int findPeakElement(int[] num) {

        int length = num.length;
        int left = 0;
        int right = length-1;

        int a=0;
        while(left<=right){   //左右开工找peak，直到两个element重合为止
            if(left==right){
               a = left;
               break;
            } 

            int mid = (left+right)/2;

            if(num[mid]<num[mid+1]){
                left = mid+1;
            }else{
                right = mid;
            }

        }

        return a;
    }
};

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int size=num.size();
        
        if(num.size()==1)
            return 0;
        
        int outIndex=-1;
        int i=0;
        while(i<size){
            if(i==0){ //first one
                if(num[i+1]<num[i])
                    outIndex=i;
                
            }else if(i==size-1){ //last one
                if(num[i]>num[i-1])
                    outIndex=i;
                
            }else{
                if(num[i]>num[i-1]&&num[i+1]<num[i])
                    outIndex=i;
            }
            i++;
        }
        
        return outIndex;
    }
};

class Solution_old {
public:
    int findPeakElement(const vector<int> &num) {
        int size=num.size();
        
        if(size==1){
            return 0;
        }
        
        int outIndex=-1;
        int i=1;
        for(i;i<size-1;i++){
            if(num[i]>num[i-1]&&num[i+1]<num[i])
                outIndex=i;
        }
        
        if(outIndex==-1){
            if(num[0]>num[size-1])
                outIndex=0;
            else
                outIndex=size-1;
        }
        
        
        return outIndex;
        
    }
};

int main(){
	vector<int> a={1};
	vector<int> b={1,2,1};
	vector<int> c={1,2,3};
	vector<int> d={3,2,1};
	vector<int> e={1,2,3,4,5};
	vector<int> f={1,2,3,2,2};
	vector<int> g={2,3,1,8,7};

	Solution s;
	cout<<s.findPeakElement(a)<<endl; //0
	cout<<s.findPeakElement(b)<<endl; //1
	cout<<s.findPeakElement(c)<<endl; //2
	cout<<s.findPeakElement(d)<<endl; //0	
	cout<<s.findPeakElement(e)<<endl; //4
	cout<<s.findPeakElement(f)<<endl; //2
	cout<<s.findPeakElement(g)<<endl; //3


	return 0;
}
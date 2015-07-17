/*
Remove Element 

Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

/*
vector has erase function
*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement_old(int A[], int n, int elem) {
        if(A==NULL) return 0;
        if(n==0) return 0;
        
        int i=n-1;
        //cout<<i<<endl;
        int j=0;
        while(j<=i){
        	if(A[j]==elem){
        		int temp=A[i];
        		A[i]=A[j];
        		A[j]=temp;
        		i--;
                //cout<<i<<endl;
        	
        	}else{
        		j++;
        	}

        }
        
        /*
        if(A[i]==elem){
            return i;
        }else{
            return i+1;
        }
        */
        return i+1;
    }

    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()) return 0;
        int i=0;
        while(i<nums.size()){
            if(nums[i]==val){
                //cout<<"aa"<<endl;
                nums.erase(nums.begin()+i);
                if(nums.empty()) return 0;
            }else{
                i++;
            }
        }

        return i;
    }
};


int main(){
    Solution s;
    int A[]={4,5};  
    int B[]={1};    
    int C[]={1,2,3};    
    int D[]={1,2,3,4,8,8};
    int E[]={1,1,1,1,1,1};
    /*
    cout<<s.removeElement(A,2,4)<<endl;  //1
    cout<<s.removeElement(B,1,1)<<endl;     //0
    cout<<s.removeElement(B,1,2)<<endl;     //1
    cout<<s.removeElement(C,3,3)<<endl;     //2
    cout<<s.removeElement(D,6,8)<<endl;     //4
    cout<<s.removeElement(E,6,1)<<endl;     //0
    */

    vector<int> v={2};

    cout<<s.removeElement(v,3)<<endl;
    //cout<<v.empty()<<endl;
    return 0;
}
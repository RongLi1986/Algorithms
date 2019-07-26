/*
Contains Duplicate III 
Given an array of integers, find out whether there are two distinct indices i and j in the array 
such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is 
at most k.
*/


#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

/*
这里我们使用map数据结构来解,用来记录数字和其下标之间的映射。 这里需要两个指针i和j，刚开始i和j都指向0，
然后i开始向右走遍历数组，如果i和j之差大于k，且m中有nums[j]，则删除并j加一。这样保证了m中所有的数的下标之差都不大于k，
然后我们用map数据结构的lower_bound()函数来找一个特定范围，就是大于或等于nums[i] - t的地方，
所有小于这个阈值的数和nums[i]的差的绝对值会大于t (可自行带数检验)。然后检测后面的所有的数字，
如果数的差的绝对值小于等于t，则返回true。最后遍历完整个数组返回false


only map has lower_bound() in c++
*/


class Solution {
public:
	//bruteforce TLE
	/*
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.empty()) return false;
        int i=0;
        while(i<nums.size()){
            int tmp=i+k;
            if(tmp>=nums.size()) tmp=nums.size(); 
            for(int j=i+1;j<tmp;j++){
                if(abs(nums[j]-nums[i])<=t)
                    return true;
            }
            i++;
        }
        
        return false;  
    }
    */


    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    	if(nums.size()<2) return false;
    	map<long, int> m;
    	map<long,int>::iterator itlow;
    	itlow=m.begin();
    	int j=0;
    	
    	
    	for(int i=0;i<nums.size();i++){
    		if(m.find(nums[j])!=m.end()){
    			if(i-j>k){
	    			m.erase(nums[j]);
	    			j++;
    			}
    		}
    		itlow=m.lower_bound (nums[i]-t);
			if(itlow!=m.end() && (abs(itlow->first - nums[i]) <= t)) {  //abs value
				//cout<<itlow->first << " "<<nums[i]<<" "<<t<<endl;
				return true;
    		}	
    		m[nums[i]]=i;
    	}

    	return false;
    }

};

int main(){
	vector<int> nums={-3,3};
	Solution s;
	cout<<s.containsNearbyAlmostDuplicate(nums,2,4)<<endl;
	return 0;
}
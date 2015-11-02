/*
Majority Element II Total Accepted: 1029 Total Submissions: 4757 My Submissions Question Solution 
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. 
The algorithm should run in linear time and in O(1) space.
*/

/*
1.use hash map to keep all numbers's count
and return whose count is more than n/3 times

2.only two numbers in array could more than 1/3 times.
then loop array and find them. check whether their times 
are more than n/3

*/


//space O(k)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mymap;  //value, count
        vector<int> out;
        for(int i=0;i<nums.size();i++){
            if(mymap.find(nums[i])!=mymap.end()){
                mymap[nums[i]]++;
                if(mymap[nums[i]]>(nums.size()/3)){
                    out.push_back(nums[i]);
                    mymap.erase(nums[i]);    
                }
            }else{
                mymap.insert({nums[i],1});
            }
        }
        
        
        for(int i=0;i<nums.size();i++){
            if(mymap[nums[i]]>(nums.size()/3)){
                out.push_back(nums[i]);
                mymap.erase(nums[i]);
            }else{
                
            }
        }
        
        
        return out;
    }
};

//only two numbers in array could more than 1/3 times
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
 
        int n1=INT_MAX, n2=INT_MAX;
        int c1=0, c2=0;
     
        for(int i: nums){
            if(n1!=INT_MAX && i==n1){
                c1++;
            }else if(n2!=INT_MAX && i==n2){
                c2++;
            }else if(c1==0){
                c1=1;
                n1=i;
            }else if(c2==0){
                c2=1;
                n2=i;
            }else{
                c1--;
                c2--;
            }
        }
     
        c1=c2=0;
     
        for(int i: nums){
            if(i==n1){
                c1++;
            }else if(i==n2){
                c2++;
            }
        }
     
        if(c1>nums.size()/3)
            result.push_back(n1);
        if(c2>nums.size()/3)
            result.push_back(n2);
     
        return result;
    }
};


int main(){

	return 0;
}
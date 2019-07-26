/*
Summary Ranges
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;     //output result
        if(nums.empty()) return res; 
        string tmp;
        int startIndex=-1;      //each start nums
        int endIndex=-1;        //each end nums
        for(int i=0;i<nums.size();i++){
            if(startIndex==-1){
                startIndex=i;
                tmp=to_string(nums[startIndex]);
            }
            
            if(i-1>=0){
                //overflow
                long long num1=nums[i];
                long long num2=nums[i-1];
                if(num1-num2>1){
                    endIndex=i-1;
                    if(startIndex!=endIndex){
                        tmp+="->"+to_string(nums[endIndex]);
                    }
                    
                    res.push_back(tmp);
                    tmp.clear();
                    startIndex=i;
                    tmp=to_string(nums[startIndex]);
                    endIndex=-1;
                }else{
                    
                }
            }
         }
         
         if(endIndex==-1){
             if(startIndex==nums.size()-1)
                res.push_back(tmp);
             else{
                tmp+="->"+to_string(nums[nums.size()-1]);
                res.push_back(tmp);
             }
         }
        
        return res;
    }
};



class Solution_old {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> out;
        if(nums.empty()) return out;
        string tmp;
        ostringstream convert;
        convert << nums[0]; 
        tmp+=convert.str();
        
        for(int i=1;i<nums.size();i++){
            /*
            there should has a bug
            [-2147483648,-2147483647,2147483647]
            but 2147483647 is last one, so it fix this bug
            */
            if(nums[i]-nums[i-1]==1){  

                if(i==nums.size()-1) {
                    tmp+="->";
                    ostringstream convert1;
                    convert1 << nums[i]; 
                    tmp+=convert1.str();
                    out.push_back(tmp);
                    tmp.clear();
                } 
            }else{
                
                ostringstream convert2;
                convert2 << nums[i-1]; 
                if(tmp!=convert2.str()){  //for testcase {1,3}: avoiding this error "1->1"
                    tmp+="->";
                    tmp+=convert2.str();
                    
                }
                
                out.push_back(tmp);
                tmp.clear();
                ostringstream convert3;
                convert3 << nums[i]; 
                tmp+=convert3.str();
                
                if(i==nums.size()-1) {
                    out.push_back(tmp);
                    tmp.clear();
                }        
            }
        }
        
        if(!tmp.empty()) {
            out.push_back(tmp);
            tmp.clear();
        }
        
        return out;
    }
};

int main(){

    return 0;
}
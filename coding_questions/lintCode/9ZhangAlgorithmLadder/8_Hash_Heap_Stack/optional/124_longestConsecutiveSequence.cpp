/*
Longest Consecutive Sequence

Given an unsorted array of integers, find the length of the longest consecutive 
elements sequence.

Clarification
Your algorithm should run in O(n) complexity.

Example
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Tags 
*/

class Solution {
private:
    unordered_map<int, int> visitMap; 
    int max;
public:
    /**
     * @param nums: A list of integers
     * @return an integer
     */
    int longestConsecutive(vector<int> &num) {
        // write you code here
        max = INT_MIN;
        
        for(int i = 0; i < num.size(); i++){
           visitMap[num[i]] = 0;
        }
        
        for(int i=0;i<num.size();i++){
            int tmp = longestConsecutiveHelper(num[i], 0);
            if(tmp>max)
                max=tmp;
            
        }
        
        return max;
    }
    
    int longestConsecutiveHelper(int number, int tmp){
        if(visitMap.find(number)==visitMap.end()){  //no this number
            return tmp;
        }else if(visitMap[number]==0){  //don't have visited this number
            visitMap[number] = tmp;
            tmp = longestConsecutiveHelper(number-1, tmp+1);   
            visitMap[number] = tmp;
        }else{
            visitMap[number]=visitMap[number]+tmp;
            tmp = visitMap[number];
        }
        
        return tmp;
    }
};
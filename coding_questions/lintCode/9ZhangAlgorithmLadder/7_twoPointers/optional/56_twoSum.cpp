/*
Two Sum

Given an array of integers, find two numbers such that they add up to a specific 
target number.

The function twoSum should return indices of the two numbers such that they add up 
to the target, where index1 must be less than index2. Please note that your 
returned answers (both index1 and index2) are NOT zero-based.

 Notice

You may assume that each input would have exactly one solution

Have you met this question in a real interview? Yes
Example
numbers=[2, 7, 11, 15], target=9

return [1, 2]

*/

class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &numbers, int target){
        vector<int> output;  //output vector
        unordered_map<int,int> myMap;  //<key, value>: keep value and index
        int findValue;

        for(int i=0;i<numbers.size();i++){
            findValue=target-(numbers[i]);   
            if(myMap.find(findValue)==myMap.end()){  //not find 
                myMap[numbers[i]]=i;                 //put in hashmap
            }else{
                output.push_back(myMap[findValue]+1); //save in output vector
                output.push_back(i+1);                              
            }
        }

        return output;
    }
};
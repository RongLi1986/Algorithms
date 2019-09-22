/*******************************************************
twoSum
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, 
where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
********************************************************/


/*
解题思路：
use a hashmap, number value is key and number index is map's value
scan array if we cannot find key in hasmap(for now no number can match sum with it), 
insert it. Otherwise, put its index and item's value in hashmap in output array

running time:O(N)
space: O(N)
*/ 

class Solution
{
public:
	vector<int> twoSum(vector<int> &numbers, int target){
		vector<int> output;  //output vector
		unordered_map<int,int> myMap;  //<key, value>: keep value and index
		int findValue;

		for(int i=0;i<numbers.size();i++){
			findValue=target-(numbers[i]);   
			if(myMap.find(findValue)==myMap.end()){  //not find 
				myMap[numbers[i]]=i;      		     //put in hashmap
			}else{
				output.push_back(myMap[findValue]+1); //save in output vector
				output.push_back(i+1);								
			}
		}

		return output;
	}
};


/*
解题思路：
sort array, then use two pointer to find answer

running time:O(NlogN)
space: O(1)
*/

class Solution
{
public:
	vector<int> twoSum(vector<int> &numbers, int target){
		vector<int> output;  //output vector
		sort(numbers.begin(), numbers.end());

		int left = 0;
        int right = numbers.size() - 1;
        while(left < right){
            if(numbers[left] + numbers[right] == target ){
                output.push_back(left);
                output.push_back(right);
                break;
            }else if(numbers[left] + numbers[right] > target){
                right--;
            }else{
                left++;
            }
        }

		return output;
	}
};
/*
2 Sum

27% Accepted
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are NOT zero-based.

Have you met this question in a real interview? Yes
Example
numbers=[2, 7, 11, 15], target=9

return [1, 2]

Note
You may assume that each input would have exactly one solution

Challenge
Either of the following solutions are acceptable:

O(1) Space, O(nlogn) Time
O(n) Space, O(n) Time
*/

#include <iostream>
#include <vector>
#include <map>
//#include <algorithm>

using namespace std;

/*
keep a hashmap, number value as key and number index as its value
travese array if we cannot find key in hasmap(for now no number can match sum with it), 
insert it.
otherwise, put its index and item's value in hashmap in output array

running time:O(n). O(n) space
*/ 

class Solution
{
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
				myMap[numbers[i]]=i;      		     //put in hashmap
			}else{
				output.push_back(myMap[findValue]+1); //save in output vector
				output.push_back(i+1);								
			}
		}

		return output;
	}
};



int main(){
	vector<int> numbers;

	numbers.push_back(3);
	numbers.push_back(2);
	numbers.push_back(4);
	

	int target=6;

	Solution s;
	s.twoSum(numbers,target);

	return 0;
}
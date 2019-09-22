/*

*/



/*

*/ 

class Solution
{
public:
	int twoSumII(vector<int> &numbers, int target){
		int ans = 0;  
		sort(numbers.begin(), numbers.end());

		int left = 0;
        int right = numbers.size() - 1;
        while(left < right){
            if(numbers[left] + numbers[right] > target ){
                ans =  ans + right - left;
                right--;
            }else{
                left++;
            }
        }

		return ans;
	}
};
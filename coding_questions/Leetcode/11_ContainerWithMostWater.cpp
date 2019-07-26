/*
Container With Most Water  
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/

/*
Two-pointer scan. And always move with shorter board index.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxArea(vector<int> &height) {
        int maxArea=0;
        int left=0;
        int right=height.size()-1;
        while(left<right){
            maxArea=max(maxArea,min(height[left],height[right])*(right-left));
            if(height[left]<height[right])
                left++;
            else
                right--;
        }

    	return maxArea;
    }
};


int main(){
	vector<int> v={1,2,3,4,5,6};  //9
	Solution s;
	cout<<s.maxArea(v)<<endl;
	return 0;
}
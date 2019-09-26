/*
42. Trapping Rain Water
DescriptionHintsSubmissionsDiscussSolution
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/

class Solution {
    public int trap(int[] height) {
        int[] l = new int[height.length];
        int[] r = new int[height.length];
        
        int left = 0;
        for(int i=0;i<height.length;i++){
            if(height[i]>left){
                left = height[i];
            }
            
            l[i] = left - height[i];
        }
        
        int right = 0;
        for(int i=height.length-1;i>=0;i--){
            if(height[i]>right){
                right = height[i];
            }
            
            r[i] = right - height[i];
        }
        
        int ret = 0;
        for(int i=0;i<height.length;i++){
            ret += Math.min(l[i], r[i]);
        }
        
        return ret;
    }
}
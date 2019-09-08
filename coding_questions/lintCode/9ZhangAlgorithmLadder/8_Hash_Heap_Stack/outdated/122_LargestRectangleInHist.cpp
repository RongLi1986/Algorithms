/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

histogram

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

histogram

The largest rectangle is shown in the shaded area, which has area = 10 unit.

Have you met this question in a real interview? Yes
Example
Given height = [2,1,5,6,2,3],
return 10.
*/


/*
solution 1:
    O(n^2) two loop find all area, maintain max one (TLE)

solution 2:
    O(n) 
    use one stack,
    looping all item in hist, 
    
    if current item's height larger than stack top one (or stk is empty), push it into stack.
    
    if its smaller than stack top one, pop out stack until stack's top one smaller than current one.
    During pop out, caculating each area and maintain max one. (two situation)

    we push a 0 into hist, it will make all item in stk pop out finally. 

    return max area
*/

class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea_tle(vector<int> &height) {
        // write your code here
        int maxArea=0;
        for(int i=0;i<height.size();i++){
            int minHeight = height[i];
            for(int j=i;j<height.size();j++){
                if(height[j]<minHeight)
                    minHeight = height[j];
                int area = minHeight *(j - i + 1);
                
                if(area > maxArea)
                    maxArea = area;
            }
        }
        
        return maxArea;
    }
    
    //O(n)
    int largestRectangleArea(vector<int> &height) {
        // write your code here
        height.push_back(0);
        
        stack<int> stk;
        int maxArea=0;
        for(int i=0;i<height.size();i++){
            if(stk.empty())
                stk.push(i);
            else if(height[stk.top()]<=height[i]){
                stk.push(i);
            }else{
                int area=0;
                while(height[stk.top()]>height[i]){
                    //cout<<"kk"<<endl;
                    int index=stk.top();
                    stk.pop();
                    if(stk.empty()){
                        area = (i) * height[index];
                        
                        if(area>maxArea)
                            maxArea=area;
                        
                        break;
                    }else{
                        //i -stk.top()-1 ???? why not index
                        //cout<<i-stk.top()-1<<" "<<i - index<<endl;
                        area = (i -stk.top()-1) * height[index];
                        if(area>maxArea)
                            maxArea=area;
                
                    }
                }
                stk.push(i);
            }
        }
        
        return maxArea;
    }
};

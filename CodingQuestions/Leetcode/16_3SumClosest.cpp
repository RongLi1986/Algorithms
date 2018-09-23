/*
3Sum Closest 
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/


/*
caculate each difference with target and keep smallest's sum
*/

class Solution {
private:
    int min_out;
    int out;
public:
    //brute force
    int threeSumClosest(vector<int> &num, int target) {
        int size=num.size();
        int min=INT_MAX;
        int out=0;
        for(int i=0;i<size-2;i++)
            for(int j=i+1;j<size-1;j++)
                for(int k=j+1;k<size;k++){
                    int sum=num[i]+num[j]+num[k];
                    if(abs(sum-target)==0)
                        return target;
                    else if(abs(sum-target)<min){
                        out=sum;
                        min=abs(sum-target);
                    }
                }
                
        return out;
    }

    //use way in 3sum
    int threeSumClosest(vector<int> &num, int target) {
        min_out=INT_MAX;
        out=0;
        sort(num.begin(),num.end());
        int size=num.size();
        int chooseNum;
        for(int i=0;i<size;i++){
            if(i == 0 || num[i] > num[i - 1]){   //no repeats
                if(twoSumCheck_new(num,num[i], target,i,size)==1)
                    return target;
            }
        }
        return out;
    }

    bool twoSumCheck_new(vector<int> &numbers,int first, int target, int block, int vectorLength){
        int left=block+1;
        int right=vectorLength-1;

        while(left<right){
            if(numbers[left]+numbers[right]+ first==target){
                return true;
            }else{
                if(abs(target-numbers[left]-numbers[right]-first)<=min_out){
                    min_out=abs(target-numbers[left]-numbers[right]-first);
                    out=numbers[left]+numbers[right]+first;
                }
                if(numbers[left]+numbers[right]+first<target){
                    left++;
                }else{
                    right--;
                }
            }
        }
        
        return false;
    }
};
/*
3Sum
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/

/*
1. using hashmap like two sum. and need handle repeat numbers(using hashmap's value as flag, -1 means used)
2. use two index left and right, and move them by compare nums[left]+nums[right] with target
nums[left]+nums[right] < target, move left
nums[left]+nums[right] > target, move right
also handle repeat case
*/


#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <chrono>

using namespace std;

class Solution {
private:
    vector<vector<int> > out;
    set<vector<int> > tmp;
public:
	//first way
    vector<vector<int> > threeSum1(vector<int> &num) {
        sort(num.begin(),num.end());
        int size=num.size();
        int chooseNum;
        for(int i=0;i<size;i++){
            if(i == 0 || num[i] > num[i - 1]){
                chooseNum=num[i];
                twoSumCheck(num,chooseNum,i);
            }
        }
        return out;
    }

    void twoSumCheck(vector<int> &numbers, int target,int start){
        vector<int> output;
        unordered_map<int,int> myMap;  //<key, value>: keep value and index
        int findValue;

        for(int i=start+1;i<numbers.size();i++){
            findValue=-target-(numbers[i]);   
            if(myMap.find(findValue)==myMap.end()){  //not find 
                if(myMap.find(numbers[i])==myMap.end()){
                    myMap[numbers[i]]=1;                 //put in hashmap
                }
            }else{
                if(myMap[findValue]!=-1){
                    output.push_back(target);
                    output.push_back(findValue); //save in output vector
                    output.push_back(numbers[i]);   
                    out.push_back(output);
                    output.clear();
                    myMap[findValue]=-1;
                }
                //myMap.erase(findValue);                         
            }
        }
    }

    //second way; faster and no hashmap used
    vector<vector<int> > threeSum2(vector<int> &num) {
        sort(num.begin(),num.end());
        int size=num.size();
        int chooseNum;
        for(int i=0;i<size;i++){
            if(i == 0 || num[i] > num[i - 1]){   //no repeats
                chooseNum=-num[i];
                twoSumCheck_new(num,chooseNum,i,size);
            }
        }
        return out;
    }

    void twoSumCheck_new(vector<int> &numbers, int target, int block, int vectorLength){
        vector<int> output;

        int findValue;
        int left=block+1;
        int right=vectorLength-1;

        while(left<right){
            if(numbers[left]+numbers[right]==target){
                output.push_back(-target);
                output.push_back(numbers[left]);
                output.push_back(numbers[right]);
                
                out.push_back(output);
                output.clear();
                int old_right=right;
                int old_left=left;

                while(numbers[old_left]==numbers[left]&& left<vectorLength){  //no repeat
                    left++;
                }

                while(numbers[old_right]==numbers[right]&& right>0){   //no repeat
                    right--;
                }

            }else if(numbers[left]+numbers[right]<target){
                left++;
            }else{
                right--;
            }
        }
    }

};


int main(){
    
    Solution s;
    vector<int> num={-1, 0, 1, 2, -1, -4};
    vector<int> num2={0,0,0,0,0,0};
    vector<int> num1={7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
    

    using namespace std::chrono;
    milliseconds ms1 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
    vector<vector<int> >v=s.threeSum(num1);
    milliseconds ms2 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());

    int size=v.size();
    int sizeRow=v[0].size();
    
    int count=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<sizeRow;j++){
            cout<<v[i][j]<<" ";
            
        }
        count++;
        cout<<endl;
    }

    cout<<count<<endl;
    
    cout<<"time cost is "<<ms2.count()-ms1.count()<<endl;
    return 0;
}
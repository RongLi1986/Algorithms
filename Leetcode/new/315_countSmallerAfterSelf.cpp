/*
315. Count of Smaller Numbers After Self   My Submissions QuestionEditorial Solution
Total Accepted: 9058 Total Submissions: 30125 Difficulty: Hard
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Return the array [2, 1, 1, 0].

*/

/*
sol1: Binary Index Tree

sol2: Binary Search and insert 

*/


#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

//sol1: burte force (TLE)
class Solution1 {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            int count=0;
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]<nums[i])
                    count++;
            }
            res.push_back(count);
        }
        
        return res;
    }
};

//sol2: Binary Index Tree
class BinaryIndexTree {
private:
    vector<int> BIT;
    int n;
    inline int lowbit(int x){
        return x & -x;
    }
public:
    BinaryIndexTree(int n): n(n), BIT(n+1,0) {

    }

    void update(int x, int val){
        while(x<=n){
            BIT[x]+=val;
            x+=lowbit(x);
        }
    }

    int sum(int x){
        int res=0;
        while(x>0){
            res+=BIT[x];
            x-=lowbit(x);
        }

        return res;
    }

    void printBIT(){
        for(int i=0;i<n+1;i++){
            cout<<BIT[i]<<" ";
        }
        cout<<endl;
    }

};

class Solution2 {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> temp_num = nums;
        sort(temp_num.begin(), temp_num.end());
        unordered_map<int,int> dic;
        
        for (int i = 0; i < temp_num.size(); i++) 
            dic[temp_num[i]] = i + 1;

        BinaryIndexTree tree(nums.size());
        vector<int> ans(nums.size(),0);
        for (int i = nums.size() - 1; i >= 0; i--) {
            ans[i] = tree.sum(dic[nums[i]] - 1);
            tree.update(dic[nums[i]],1);

        }

        return ans;
    }
};

//sol3   binary insert and serch
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> t, res(nums.size());
        for (int i = nums.size() - 1; i >= 0; --i) {
            int left = 0, right = t.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (t[mid] >= nums[i]) right = mid;
                else left = mid + 1;
            }
            res[i] = right;
            t.insert(t.begin() + right, nums[i]);
        }
        return res;
    }
};

int main(){

    return 0;
}
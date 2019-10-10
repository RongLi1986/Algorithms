/*
Numbers keep coming, return the median of numbers at every time a new number added.

Example 1

Input: [1,2,3,4,5]
Output: [1,1,2,2,3]
Explanation:
The medium of [1] and [1,2] is 1.
The medium of [1,2,3] and [1,2,3,4] is 2.
The medium of [1,2,3,4,5] is 3.

Example 2

Input: [4,5,1,3,2,6,0]
Output: [4,4,4,3,3,3,3]
Explanation:
The medium of [4], [4,5], [4,5,1] is 4.
The medium of [4,5,1,3], [4,5,1,3,2], [4,5,1,3,2,6] and [4,5,1,3,2,6,0] is 3.
Challenge
Total run time in O(nlogn).
*/

class MedianFinder {
private:
    priority_queue<int> firstQ; // max_heap for the first half
    priority_queue<int, std::vector<int>, std::greater<int> > secQ; // min_heap for the second half
public:
    // Adds a number into the data structure.
    void addNum(int num) {
        if(firstQ.empty() || (firstQ.top()>num)) firstQ.push(num); // if it belongs to the smaller half
        else secQ.push(num); 
        
        // rebalance the two halfs to make sure the length difference is no larger than 1
        if(firstQ.size() > (secQ.size()+1))
        {
            secQ.push(firstQ.top());
            firstQ.pop();
        }
        else if(firstQ.size()+1<secQ.size())
        {
            firstQ.push(secQ.top());
            secQ.pop();
        }
    }

    // Returns the median of current data stream
    int findMedian() {
        if(firstQ.size() == secQ.size()) return firstQ.empty()? 0 : firstQ.top();
        else return (firstQ.size() > secQ.size())? firstQ.top():secQ.top(); 
    }
};

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: the median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        // write your code here
        MedianFinder* mf = new MedianFinder();
        vector<int> retval;
        for(int i=0;i<nums.size();i++){
            mf->addNum(nums[i]);
            retval.push_back(mf->findMedian());
        }
        
        return retval;
    }
};
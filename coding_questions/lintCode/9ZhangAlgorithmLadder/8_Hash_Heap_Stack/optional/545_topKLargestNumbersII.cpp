/*
Implement a data structure, provide two interfaces:

add(number). Add a new number in the data structure.
topk(). Return the top k largest numbers in this data structure. k is given when we create the data structure.
Have you met this question in a real interview? Yes

Example
s = new Solution(3);
>> create a new data structure.
s.add(3)
s.add(10)
s.topk()
>> return [10, 3]
s.add(1000)
s.add(-99)
s.topk()
>> return [1000, 10, 3]
s.add(4)
s.topk()
>> return [1000, 10, 4]
s.add(100)
s.topk()
>> return [1000, 100, 10]
*/
 
class Solution {
private:
    int count;
    priority_queue<int> pq;
public:
    Solution(int k) {
        // initialize your data structure here.
        count = k;
    }

    void add(int num) {
        // Write your code here
        pq.push(num);
    }

    vector<int> topk() {
        // Write your code here
        vector<int> res;
        priority_queue<int> pq_copy=pq;
        if(count<=pq_copy.size()){ //count;
            for(int i=0;i<count;i++){
                res.push_back(pq_copy.top());
                pq_copy.pop();
            }
        }else{ //all pq
            while(!pq_copy.empty()){
                res.push_back(pq_copy.top());
                pq_copy.pop();
            }
        }
        
        return res;
    }
};
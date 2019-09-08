/*
Two Sum - Data structure design

Design and implement a TwoSum class. It should support the following operations: 
add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

Have you met this question in a real interview? Yes
Example
add(1); add(3); add(5);
find(4) // return true
find(7) // return false
*/

/*
merge
*/

// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);

class TwoSum {
private:
    unordered_map<int, int> map;
    vector<int> nums;
public:
    // Add the number to an internal data structure.
    void add(int number) {
        if(map.find(number)==map.end()){
            map[number]=1;
        }else{
            map[number]++;
        }
        nums.push_back(number);
        return;
    }

    // Find if there exists any pair of numbers which sum is equal to the value.
    bool find(int value) {
        for(int i=0;i<nums.size();i++){
            int target = value - nums[i];
            if(map.find(target)!=map.end()){
                if(target==nums[i]){
                    if(map[target]>=2){
                        return true;
                    }
                }else{
                    return true;
                }
            }
        }
        
        return false;
    }
};

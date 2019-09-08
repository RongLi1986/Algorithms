/*
High Five

There are two properties in the node student id and scores, to ensure that each 
student will have at least 5 points, find the average of 5 highest scores for each 
person.

Have you met this question in a real interview? Yes
Example
Given results = [[1,91],[1,92],[2,93],[2,99],[2,98],[2,97],[1,60],[1,58],[2,100],
[1,61]]

Return 
*/


/*

*/

/**
 * Definition for a Record
 * class Record {
 * public:
 *   int id, score;
 *   Record(int id, int score) {
 *     this->id = id;
 *     this->score = score;
 *   }
 * };
 */
class Solution {
public:
    /**
     * @param results a list of <student_id, score>
     * @return find the average of 5 highest scores for each person
     * map<int, double> (student_id, average_score)
     */
    map<int, double> highFive(vector<Record>& results) {
        // Write your code here
        unordered_map<int, priority_queue<int, vector<int>, std::less<int>> > hashMap;
        
        map<int, double> ans;
        
        for(int i=0;i<results.size();i++){
            hashMap[results[i].id].push(results[i].score);
        }
        
        auto it = hashMap.begin();
        
        while(it!=hashMap.end()){
            double sum = 0;
            int i = 0;
            //cout<<(it->first)<<endl;
            while(i<5){
                //cout<<(it->second).top()<<" ";
                sum+=(it->second).top();
                (it->second).pop();
                i++;
            }
            //cout<<endl;
            
            double avg = sum/5;
            
            ans[(it->first)] = avg;   

            it++;
        }
        
        return ans;
    }
};
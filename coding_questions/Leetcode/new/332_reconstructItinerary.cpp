/*
332. Reconstruct Itinerary   My Submissions QuestionEditorial Solution
Total Accepted: 8424 Total Submissions: 35350 Difficulty: Medium
Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:
If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
Example 1:
tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Return ["JFK", "MUC", "LHR", "SFO", "SJC"].
Example 2:
tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order.

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.
*/

/*
dfs
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
private:
    vector<string> res;
    int count;
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string,map<string,int> > map;
        
        for(int i=0;i<tickets.size();i++){
            map[tickets[i].first][tickets[i].second]+=1;
        }
        
        const string start="JFK";
        res.push_back(start);
        bool a=dfs(start,map,tickets.size()+1);
        //cout<<a<<endl;
        return res;
    }
    
    bool dfs(const string &start, unordered_map<string,map<string,int> > &m, int count){
        if(res.size()==count){
            //cout<<count<<endl;
            return true;
        }
        
        for (auto ticket = m[start].begin(); ticket != m[start].end(); ticket++) { //map<string, int>::iterator
            if (ticket->second != 0) {
                ticket->second--;
                res.push_back(ticket->first);
                if (dfs(ticket->first,m,count)) 
                    return true;
                res.pop_back();
                ticket->second++;
            }
        }
        
        return false;
        
    }
    
};

int main(){

    return 0;
}
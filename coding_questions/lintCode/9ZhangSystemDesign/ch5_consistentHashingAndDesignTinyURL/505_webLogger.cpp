/*
Implement a web logger, which provide two methods:

hit(timestamp), record a hit at given timestamp.
get_hit_count_in_last_5_minutes(timestamp), get hit count in last 5 minutes.
the two methods will be called with non-descending timestamp (in sec).
*/

/*
use vector save time event, and find a range by binary search.
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class WebLogger {
private:
    vector<int> hitEventLine;    
public:
    WebLogger() {
        // initialize your data structure here.
        hitEventLine.clear();
    }

    /**
     * @param timestamp an integer
     * @return void
     */
    void hit(int timestamp) {
        // Write your code here
        hitEventLine.push_back(timestamp);
    }

    /**
     * @param timestamp an integer
     * @return an integer
     */
    int get_hit_count_in_last_5_minutes(int timestamp) {
        // Write your code here
        int start =timestamp-300>0?timestamp-300:0;
        int end = timestamp;
        
        int sum = 0;
        
        //O(n)
        /*
        for(int i=0;i<hitEventLine.size();i++){
            if(hitEventLine[i]>start && hitEventLine[i]<=end){
                sum++;
            }
        }
        
        return sum;
        */
        
        //O(lgn)
        int left=binarySearchLeft(start);
        int right=binarySearchRight(end);
        
        //cout<<left<<" "<<right<<endl;
        
        if(right == -1 || left == -1){ //not in range
            return 0;
        }else{
            return right - left +1;
        }
        
    }
    
    
    //search start 
    //return index which first number larger than val;
    int binarySearchLeft(int val){ 
        if(hitEventLine.empty()) return -1;
        
        if(hitEventLine[hitEventLine.size()-1]<=val) return -1;
        if(hitEventLine[0]>val) return 0;
        
        int left =0;
        int right = hitEventLine.size()-1;
        
        while(left+1<right){
            int mid = (left+right)/2;
                if(hitEventLine[mid]>val){
                    right=mid;
                }else{
                    left=mid;
                }
        }
            
        return right;
    }
    
    //search end
    //return index which first number smaller or == val
    int binarySearchRight(int val){ 
        if(hitEventLine.empty()) return -1;
        
        if(hitEventLine[0]>val) return -1;
        if(hitEventLine[hitEventLine.size()-1]<=val) return hitEventLine.size()-1;
        
        int left =0;
        int right = hitEventLine.size()-1;
        
        while(left+1<right){
            int mid = (left+right)/2;
                if(hitEventLine[mid]>=val){
                    right=mid;
                }else{
                    left=mid;
                }
        }
            
        return right;
    }
};


int main(){
    
    return 0;
}
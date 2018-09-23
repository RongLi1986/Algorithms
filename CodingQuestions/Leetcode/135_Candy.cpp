/*
Candy 
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
*/

/*
it needs two scan: first from left to right, second from right to left. 
Using a vector to keep each children's candies number. 
for each scan, update candies numbers by comparing two children's rating.
higher rating one will equal to another's candies number plus one, and keep max value.  
finally, caculate sum from candies vector.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(),1);
        
        //left scan 
        for(int i=0;i<ratings.size()-1;i++){
            if(ratings[i]>ratings[i+1])
                candies[i]=candies[i+1]+1;
            else if(ratings[i]<ratings[i+1])
                candies[i+1]=candies[i]+1;
        }
        
        //right scan
        for(int i=ratings.size()-1;i>0;i--){
            if(ratings[i]>ratings[i-1])
                candies[i]=max(candies[i],candies[i-1]+1);
            else if(ratings[i]<ratings[i-1])
                candies[i-1]=max(candies[i-1],candies[i]+1);
        }
        
        int sum=0;
        for(int i=0;i<candies.size();i++){
            sum+=candies[i];
        }
        
        return sum;
    }
};


class Solution_old {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size()==0) return 0;
        vector<int> candies_left(ratings.size(),1);
        vector<int> candies_right(ratings.size(),1);
        
        for(int i=1;i<candies_left.size();i++){
            if(ratings[i]>ratings[i-1]){
                candies_left[i]=candies_left[i-1]+1;
            }
        }
        
        for(int i=candies_right.size()-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                candies_right[i]=candies_right[i+1]+1;
            }
        }
        int count=0;
        
        for(int i=0;i<ratings.size();i++){
            count+=max(candies_left[i],candies_right[i]);
        }
        
        
        return count;
    }
};

int main(){


    return 0;
}


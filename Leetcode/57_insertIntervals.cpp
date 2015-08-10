/*
Insert Interval Total Accepted: 32738 Total Submissions: 153194 My Submissions Question Solution 
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

Show Tags
*/

/*
follow the question 56, push newInterval into intervals
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Definition for an interval.
 */
struct Interval {
   int start;
   int end;
   Interval() : start(0), end(0) {}
   Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(Interval a, Interval b){
  return a.start<b.start;
}

class Solution {
private:
    vector<Interval> out;
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);    
    }

    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.empty()) return out;
        if(intervals.size()==1) return intervals;

        //we need input data sort
        sort(intervals.begin(),intervals.end(),cmp);
        
        int i=1; //for intervals traversal, start from 1 since we push first element in out;
        int j=0;  //for out travals
        out.push_back(intervals[0]);
        while(i<intervals.size()){
            if(out[j].end>=intervals[i].start){
               if(out[j].end>=intervals[i].end){
                  //out.push_back(intervals[i]);
                  //i++;
               }else{
                  
                  /*
                  Interval s(out[j].start,intervals[i].end);
                  out.pop_back();
                  out.push_back(s);
                  */
                  //we don't need to pop and push
                  //since we can directly change the Interval in out vector
                  out[j].end=intervals[i].end;

                  //j++;
               }
            }else{
               out.push_back(intervals[i]);
               j++;
            }
            i++;
        }

        return out;
    }
};

int main(void)
{
   Interval a(1,6);
   Interval b(3,7);
   Interval c(4,10);

   vector<Interval> intervals;
   intervals.push_back(a);
   intervals.push_back(b);
   intervals.push_back(c);

   Solution s;
   vector<Interval> out=s.merge(intervals);

   for(int i=0;i<out.size();i++){
      cout<<"["<<out[i].start<<","<<out[i].end<<"]";
   }
   cout<<endl;


}
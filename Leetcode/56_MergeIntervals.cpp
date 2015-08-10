/*
Merge Intervals Total Accepted: 35236 Total Submissions: 157717 My Submissions Question Solution 
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

Show Tags
*/

/*
just traversal intervals' vector.
put first interval into result vector.
they are three case:
1. if first interval end larger than second interval's end: do not need to put 
second one in res vector.
2. if first interval end larget than second interval's first and smaller than
second one's end: pop_back first one and push a new interval with right first
and end value into result vector.
3. if first interval end smaller than second interval's first: push second one
into result vector.
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
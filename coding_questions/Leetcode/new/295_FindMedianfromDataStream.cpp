/*
295. Find Median from Data Stream My Submissions Question
Total Accepted: 10661 Total Submissions: 50077 Difficulty: Hard
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

Examples: 
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
For example:

add(1)
add(2)
findMedian() -> 1.5
add(3) 
findMedian() -> 2
*/


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class MedianFinder {
private:
    std::priority_queue<int> smallValQue; //small half (large one is on top)
    std::priority_queue<int, std::vector<int>, std::greater<int> > largeValQue; //large half (small is on top)
    double medianNum;
public:
    // Adds a number into the data structure.
    void addNum(int num) {
        if(smallValQue.empty()&&largeValQue.empty()){  //first number
            smallValQue.push(num);
            medianNum=(double)num;
        }else{
            if(num>medianNum){  //insert large que
                if(largeValQue.size()==smallValQue.size()){  //
                    largeValQue.push(num);    
                }else if(largeValQue.size()>smallValQue.size()){
                    smallValQue.push(largeValQue.top());
                    largeValQue.pop();
                    largeValQue.push(num);
                }else{ //second one
                    largeValQue.push(num);     
                }

                if(largeValQue.size()==smallValQue.size())
                    medianNum=(double) (largeValQue.top()+smallValQue.top())/2;
                else
                    medianNum=(double)largeValQue.top();

            }else if(num<medianNum){ //insert small que
                //smallValQue.push(num);
                if(largeValQue.size()==smallValQue.size()){  // try 40 12 16
                    if(smallValQue.top()<=num){
                        largeValQue.push(num);
                    }else{
                        largeValQue.push(smallValQue.top());
                        smallValQue.pop();
                        smallValQue.push(num);    
                    }     
                }else if(largeValQue.size()>smallValQue.size()){
                    smallValQue.push(num);
                }else{ //second one
                    largeValQue.push(smallValQue.top());
                    smallValQue.pop();
                    smallValQue.push(num);     
                }

                if(largeValQue.size()==smallValQue.size())
                    medianNum=(double)(largeValQue.top()+smallValQue.top())/2;
                else
                    medianNum=(double)largeValQue.top();
            }else{ //== median
                if(largeValQue.size()<smallValQue.size()){
                    largeValQue.push(num);
                }else{
                    smallValQue.push(num);
                }
            }    
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        return medianNum;
    }
};


int main(){
    MedianFinder mf;
    mf.addNum(40);
    cout<<mf.findMedian()<<endl;
    mf.addNum(12);
    cout<<mf.findMedian()<<endl;
    mf.addNum(16);
    cout<<mf.findMedian()<<endl;
    
    /*
    mf.addNum(1);
    cout<<mf.findMedian()<<endl;
    mf.addNum(90);
    cout<<mf.findMedian()<<endl;
    */



    return 0;
}
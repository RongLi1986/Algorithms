/*
319. Bulb Switcher My Submissions Question
Total Accepted: 1806 Total Submissions: 4769 Difficulty: Medium
There are n bulbs that are initially off. You first turn on all the bulbs. Then, you turn off every second bulb. On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the nth round, you only toggle the last bulb. Find how many bulbs are on after n rounds.

Example:

Given n = 3. 

At first, the three bulbs are [off, off, off].
After first round, the three bulbs are [on, on, on].
After second round, the three bulbs are [on, off, on].
After third round, the three bulbs are [on, off, off]. 

So you should return 1, because there is only one bulb is on.
*/

/*
0=0
1 2 3 4 5 = 


*/


#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        int num=n+1;
        int i=0;
        while(num>0){
            num=num-1-2*i;
            i++;
        }
        
        return i-1;
    }
};

int main(){

    return 0;
}
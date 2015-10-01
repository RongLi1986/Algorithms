/*
Reverse Bits Total Accepted: 3523 Total Submissions: 12929 My Submissions Question Solution 
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?
*/

/*
get each bit from n (AND with 1) , then do OR operation with out, 
then out shift left, and n shift right.
Until out get all bits from n
*/


#include <iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t out=0;
        int count=1;
        while(count<=32){
            uint32_t tmp=n&1;
            
            
            out=out|tmp;
            

            if(count!=32)
            out=out<<1;
            

            n=n>>1;
            //cout<<n<<endl;
            count++;
        }
        
        return out;
    }
};

int main(){
	Solution s;
	cout<<s.reverseBits(0x00000001)<<endl;

	return 0;
}
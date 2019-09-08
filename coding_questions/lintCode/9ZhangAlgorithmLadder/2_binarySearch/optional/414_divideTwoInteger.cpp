/*
Divide Two Integers

Divide two integers without using multiplication, division and mod operator.

If it is overflow, return 2147483647

Have you met this question in a real interview? Yes
Example
Given dividend = 100 and divisor = 9, return 11.
*/

class Solution {
public:
int divide(int dividend_short, int divisor_short) {
      long long dividend= dividend_short;
      long long divisor= divisor_short;

        if(divisor==0) return INT_MAX;
        if(divisor==1) return dividend;
        
        if(divisor==-1){
          //cout<<"kk"<<endl;
          if(dividend==INT_MIN)
            return ~(dividend);
          return  ~(dividend)+1;
        }

        int sign=0;
        int count=1;
        if((divisor<0&&dividend>0)||(divisor>0&&dividend<0))
          sign=1;
        

        //if(dividend<0) dividend=~(dividend)+1;
        //if(divisor<0) divisor=~(divisor)+1;


        if(dividend<0) dividend=0-(dividend);
        if(divisor<0) divisor=0-(divisor);

        long long origDivsor=divisor;
        int res=0;
        while(dividend>=origDivsor){
            //dividend=dividend>>1;
            //divisor=divisor>>1;
          dividend=dividend-divisor;
          res+=count;
          if(dividend>=(divisor<<1)){
            divisor<<=1; //*2
            count<<=1;  //*2
          }else{
            divisor=origDivsor;
            count=1;
          }
          
        }
        
        if(sign==1){
          //dividend=~(dividend)+1;
          res=~res+1;
        }
        return res;
    }
};
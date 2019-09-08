/*
Sqrt(x) II

Implement double sqrt(double x) and x >= 0.

Compute and return the square root of x.

 Notice

You do not care about the accuracy of the result, we will help you to output results.

Have you met this question in a real interview? Yes
Example
Given n = 2 return 1.41421356

*/

class Solution {
public:
    /**
     * @param x a double
     * @return the square root of x
     */
    double sqrt(double x) {
        // Write your code here
        int flag =0;
        if(x<1){
            flag = 1;
            x=1/x;
        }
            
        double left = 0;
        double right = x;
        double delta = 0.000000001;
        while(right-left >delta){
            double mid =(right+left)/2;
            if(abs(mid*mid-x)<delta){
                if(flag==1)
                    return 1/mid;
                return mid;
            }else{
                if(mid*mid>x){
                        right = mid;
                    
                }else{
                    //if(x>1)
                        left = mid;
                    }
            }
        }
        
        if(flag==1)
                return 2/(left+right);
        return (left+right)/2;
    }
};
/*
Number of Ways to Represent N Cents

Given an infinite number of quarters (25 cents), dimes (10 cents), 
nickels (5 cents) and pennies (1 cent), write code to calculate the number 
of ways of representing n cents.

Example
n = 11

11 = 1 + 1 + 1... + 1
   = 1 + 1 + 1 + 1 + 1 + 1 + 5
   = 1 + 5 + 5
   = 1 + 10
return 4
*/

#include <iostream>
using namespace std;

/*
*/

class Solution {
public:
    /**
     * @param n an integer
     * @return an integer
     */
    int waysNCents(int n) {
        // Write your code here
        vector<int> s = {1,5, 10,25};
        
        
        return count(s, 4, n);
    }
    
    int count(vector<int>& S, int m, int n )
    {
        int i, j, x, y;
     
        // We need n+1 rows as the table is consturcted in bottom up manner using 
        // the base case 0 value case (n = 0)
        int table[n+1][m];
        
        // Fill the enteries for 0 value case (n = 0)
        for (i=0; i<m; i++)
            table[0][i] = 1;
     
        // Fill rest of the table enteries in bottom up manner  
        for (i = 1; i < n+1; i++)
        {
            for (j = 0; j < m; j++)
            {
                // Count of solutions including S[j]
                x = (i-S[j] >= 0)? table[i - S[j]][j]: 0;
     
                // Count of solutions excluding S[j]
                y = (j >= 1)? table[i][j-1]: 0;
     
                // total count
                table[i][j] = x + y;
            }
        }
        return table[n][m-1];
    }

};

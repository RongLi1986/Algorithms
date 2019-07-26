/*
Count Primes 
Description:

Count the number of prime numbers less than a non-negative number, n
*/

/*
solution: check Sieve of Eratosthenes
Input: an integer n > 1
 
Let A be an array of Boolean values, indexed by integers 2 to n,
initially all set to true.
 
 for i = 2, 3, 4, ..., not exceeding √n:
  if A[i] is true:
    for j = i^2, i^2+i, i^2+2i, i^2+3i, ..., not exceeding n :
      A[j] := false
 
Output: all i such that A[i] is true.
*/

#include <iostream>
#include <cmath>
using namespace std;

class Solution_slow {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;

		bool num[n];

		for(int i=0;i<n;i++){
			num[i]=true;
		}

        int i=2;
        
        while(i*i<n){
            int j=i*i;
            int k=0;
            while(j+k*i<n){
                if(num[j+k*i]==true){
                   num[j+k*i]=0; 
                }
                
                k++;
            }
            i++;
        }
        
        int count=0;
        for(int i=0;i<num.size();i++){
            if(num[i]==true)
                count++;
        }
        
        return count-2;  //-2: remove count 1 and 2
        
    }
};

//build-in array and library function is fast running time
class Solution_fast {
public:
    int countPrimes(int n) {
		if(n<2) return 0;
		
		bool A[n];

		for(int i=0;i<n;i++){
			A[i]=true;
		}
		int limit=sqrt(n);

		for(int i=2;i<=sqrt(n);i++){
			//cout<<"ll"<<endl;
			if(A[i]==true){
				for(int j=pow(i,2);j<n;j+=i)
					A[j]=false;
			}
		}        

		int result=0;
		for(int i=2;i<n;i++){
			result+=static_cast<int>(A[i]);
			//cout<<A[i]<<endl;
		}

		return result;
    }
};


int main(){
	Solution s;
	cout<<s.countPrimes(3)<<endl;


	return 0;
}
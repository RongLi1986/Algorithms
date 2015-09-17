/*
Find Minimum in Rotated Sorted Array II 
Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.
*/

class Solution {
public:
	//nlog(n)
    int findMin(vector<int> &num) {
        sort(num.begin(),num.end());
        return num[0];
    }

    //O(n)
    int findMin(vector<int> &num) {
        int size=num.size();
        int min=num[0];
        int i=0;
        while(i<size){
        	if(num[i]<min){
        		min=num[i];
        		break;
        	}
        	i++;
        }
        return min;
    }
};


int main(){

	return 0;
}
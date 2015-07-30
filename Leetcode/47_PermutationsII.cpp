/*
Permutations II 
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/

//next permutation's way
class Solution {
private:
	vector<vector<int> > out;
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(),num.end());
        out.push_back(num);
        int size=num.size();
        int i=0;
        while(i!=-1){
        	i=nextPermutation(num, size);
        }

        return out;
    }

    int nextPermutation(vector<int> &num, int size) {
        int changeIndex=-1;
        
        for(int i=size-1;i>0;i--){
            if(num[i]>num[i-1]){
                changeIndex=i-1;
                for(int j=size-1;j>changeIndex;j--){
                	if(num[j]>num[changeIndex]){
                		swap(num, j, changeIndex);
                		sort(num.begin()+changeIndex+1, num.end());
                		out.push_back(num);
                		return changeIndex;
                	}
                }
            }
        }
        
        if(changeIndex==-1){  //no larger number
        	//out.push_back(num);
            //sort(num.begin(),num.end());
            return changeIndex;

        }
    }
    
    void swap(vector<int> &num,int origIndex, int changeIndex){
    	//cout<<"num"<<endl;
    	//cout<<origIndex<<" "<<changeIndex<<endl;
        int tmp=num[changeIndex];
        num[changeIndex]=num[origIndex];
        num[origIndex]=tmp;
    }
};


/*
backtracking
need a map for keeping used number
need sort and use a loop to avoid repeated number
*/

class Solution {
private:
    vector<vector<int> > out;
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> tmp;
        recursiveTrack(candidates,0,target,tmp);
        return out;
    }
    
    void recursiveTrack(vector<int>& candidates, int start, int target, vector<int> tmp){
        if(target==0){
            out.push_back(tmp);
            return;
        }
        
        for(int i=start;i<candidates.size();i++){
            int left=target-candidates[i];
            if(left>=0){
                tmp.push_back(candidates[i]);
                recursiveTrack(candidates,i+1,left,tmp);
                tmp.pop_back();

            }else
                return;
        }
        
        return;
    }
};
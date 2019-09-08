/*
Find the Missing Number II

Giving a string with number from 1-n in random order, but miss 1 number.
Find that number.

 Notice

n <= 30

Have you met this question in a real interview? Yes
Example
Given n = 20, str = 19201234567891011121314151618

return 17
*/

class Solution {
private:
    vector<vector<int> > res;
    int count;
public:
    /**
     * @param n an integer
     * @param str a string with number from 1-n in 
     *            random order and miss one number
     * @return an integer
     */
    int findMissing2(int n, string& str) {
        // Write your code here
        count = n;
        vector<int> tmp;
        
        //cout<<"ll"<<endl;
        findComboFromStringHelper(str, tmp, 0);
        //cout<<"en"<<endl;
        
        
        /*
        for(int i=0;i<res.size();i++){
            sort(res[i].begin(), res[i].end());
            for(int j=0;j<res[i].size();j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
        */
        
        
        
        for(int i=0;i<res.size();i++){
            sort(res[i].begin(), res[i].end());
            int missNumber =-1;
            bool missNumberFlag = false;
            int val = 1;
            int j=0;
            while(j<res[i].size()){
                if(res[i][j] - val >1){
                    missNumberFlag = false;
                    missNumber = 0;
                    break;
                }
                
                if(res[i][j] - val < 0){
                    missNumberFlag = false;
                    missNumber = 0;
                    break;
                }
                
                
                if(res[i][j]-val != 0 && !missNumberFlag){
                    missNumber = val;
                    missNumberFlag = true;
                    val++;
                }else if(res[i][j]-val != 0 && missNumberFlag){
                    missNumberFlag = false;
                    missNumber = 0;
                    break;
                }else{
                    val++;
                    j++;
                }
                
                //cout<<res[i][j]<<" ";
            }
            
            if(missNumberFlag==true)
                return missNumber;
            
            
            if(missNumber==-1 && missNumberFlag == false)
                return j+1;
            
            //cout<<endl;   
        }
        
        return -1;
    }
    
    void findComboFromStringHelper(string& s,  vector<int>& tmp, int start){
        if(start==s.size()){
            if(tmp.size()==count-1){
                res.push_back(tmp);
            }
            
            return;
        }
        
        //for(int i=start;i<s.size();i++){
        std::string::size_type sz;   // alias of size_t
        string str = s.substr(start,1);
        
        int number = std::stoi (str,&sz);
        //cout<<number<<endl;
        if(number == 0)
            return;
        
        tmp.push_back(number);
        findComboFromStringHelper(s, tmp, start+1);
        tmp.pop_back();
            
        if(start!=s.size()-1 && s[start]!= '0'){
            str = s.substr(start,2);
            //cout<<str<<endl;
            number = std::stoi(str,&sz);
            if(number<=30){
                tmp.push_back(number);
                findComboFromStringHelper(s, tmp, start+2);
                tmp.pop_back();
            }
        }
        
        return;
    }
};
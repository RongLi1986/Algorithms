/*
Restore IP Addresses 
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)*/

/*
backtracking + discard invaild case
invaild case:
1.if dot is more than 3 (part is more than 4) and index is not in s' end.
2.if dot is smaller than 3(part is small than 4) and index is reach s' end.
*/


#include <iostream>
#include <vector>
using namespace std;

//backtracking
class Solution {
private:
    vector<string> out;
public:
    vector<string> restoreIpAddresses(string s) {
        if(s.size()<4||s.size()>12) return out;
        
        string tmp;
        int partCount=0; //numbers of dot
        
        //backtracking
        backtrackingRecursive(s,0,tmp,partCount);

        return out;     

    }

    void backtrackingRecursive(string& s, int startIndex, string tmp,int partCount){
        if(startIndex>=s.size()){
            
            //if part is 4 
            if(partCount==4)
                out.push_back(tmp);
            
            return;
        }
        
        //part is 4 but index is not in s' end
        if(partCount==4)
            return;
        
        for(int i=startIndex;i<startIndex+3;i++){ //ip address is max 255,len is 3
            //avoid i over s'size
            if(i>=s.size()) break;
            
            //ip string
            string ip(s,startIndex,i-startIndex+1);
            
            //check whether ip is vaild
            if(checkIpString(ip)){
                if(tmp.size()==0){ //first part
                    string tmp_next=tmp+ip;
                    backtrackingRecursive(s,i+1,tmp_next,partCount+1);
                }else{
                    string tmp_next=tmp+"."+ip;
                    backtrackingRecursive(s,i+1,tmp_next,partCount+1);    
                }
            }
        }

        return;
    }

    //check ip is vaild or not
    bool checkIpString(string part){
        //first is 0' case, such as 010 is invaild.
        if(part[0]=='0'&& part.size()>1) return false;

        int integer = atoi(part.c_str());
        
        //invaild ip case        
        if(integer>255 || integer <0)
            return false;
        
        return true;
    }
};


class Solution_old {
private:
    vector<string> out;
public:
    vector<string> restoreIpAddresses(string s) {
        string tmp;
        if(s.size()<4||s.size()>12) return out;
        partString(s,0,tmp,0,out);

        return out;     
    }

    void partString(string &s, int startIndex, string tmp, int count, vector<string> &out){
        if(startIndex>s.size()-1) return;
        
        if(tmp.size()!=0) {
            if(count<3){
                tmp+="."; //first put "." in tmp, except first time
                //cout<<tmp<<endl;
                count++;  //count "." number
            }
        }

        /*
        if(startIndex==s.size()-1) {  //reach last index in string s
            tmp+=s[startIndex];
            out.push_back(tmp);
            //cout<<tmp<<endl;
            return;
        }
        */
        
        if(count<3){
            string part(s,startIndex,1);
            if(checkTmpString(part)==false) return;
            tmp+=s[startIndex];
            partString(s,startIndex+1,tmp,count,out);
            
            if(s.size()-1>=startIndex+1){
                //cout<<"a "<<startIndex+1<<endl;
                string part(s,startIndex,2);
                if(checkTmpString(part)==false) return;
                tmp+=s[startIndex+1];
                partString(s,startIndex+2,tmp,count,out);
            }

            if(s.size()-1>=startIndex+2){
                //cout<<"b "<<startIndex+2<<endl;
                string part(s,startIndex,3);
                if(checkTmpString(part)==false) return;
                tmp+=s[startIndex+2];
                partString(s,startIndex+3,tmp,count,out);
            }
        }else{
            string part(s,startIndex,s.size()-startIndex);
            //cout<<part<<endl;
            //cout<<part<<" "<<checkTmpString(part)<<endl;
            if(checkTmpString(part)==false) return;
            
            tmp+=part;
            //cout<<tmp<<endl;
            out.push_back(tmp);
            return;
        }

        return;

    }

    bool checkTmpString(string &part){
        if(part.size()==0) return false;
        if(part[0]=='0'&& part.size()>1) return false;

        int integer = atoi(part.c_str());
        if(integer>255 || integer <0)
            return false;
        return true;
    }
};


int main(){
	string ss="25525511135";
    //string part(ss,3,1);
    //cout<<part<<endl;
    Solution s;
    vector<string> out=s.restoreIpAddresses(ss);

    
    for(int i=0;i<out.size();i++){
        cout<<out[i]<<endl;
    }
    cout<<endl;
    
	return 0;
}
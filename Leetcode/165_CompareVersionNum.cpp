/*
Compare Version Numbers Total Accepted: 7972 Total Submissions: 53932 My Submissions Question Solution 
Compare two version numbers version1 and version1.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
*/

/*
first split string into vector by '.'
then compare two vector.
*/

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        //first generate two lists
        vector<int> list1=generateList(version1);
        vector<int> list2=generateList(version2);
        
        int i=0;
        int j=0;
        
        //compare two list's items
        while(i<list1.size()&&j<list2.size()){
            if(list1[i]>list2[j]){
                return 1;
            }else if(list1[i]<list2[j]){
                return -1;
            }else{
                i++;
                j++;
            }
        }
        
        while(i<list1.size()){
            if(list1[i]!=0)  //for 1.0 and 1 case
                return 1;
            else
                i++;
        }
        
        while(j<list2.size()){
            if(list2[j]!=0)
                return -1;
            else
                j++;
        }
        
        return 0;
    }
    
    //split string and put number into vector
    vector<int> generateList(string s){
        vector<int> list;
        int start=0;
        int end=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='.'){
                end=i;
                int length=end-start;
                
                if(length!=0){
                    int num=stoi(s.substr(start,length));
                    list.push_back(num);
                }
                
                start=i+1;
            }
        }
        
        //handle last one
        if(start<s.size()){
            int num=stoi(s.substr(start,s.size()-start));
            list.push_back(num);
        }
        
        return list;
    }
};



class Solution_old {
public:
    int compareVersion(string version1, string version2) {
        int find1=version1.find(".");
        int find2=version2.find(".");
        int num1,num2;
        int start1=0;
        int start2=0;
        while(find1!=string::npos&&find2!=string::npos){
            string a1(version1.begin()+start1,version1.begin()+find1);
            string a2(version2.begin()+start2,version2.begin()+find2);
            num1=atoi(a1.c_str());
            num2=atoi(a2.c_str());
            if(num1>num2)
            	return 1;
        	else if(num2>num1)
            	return -1;

            start1=find1+1;
            start2=find2+1;

            find1=version1.find(".",find1+1);
        	find2=version2.find(".",find2+1);
        }
        
        if(find1!=string::npos&&find2==string::npos){
            string a1(version1.begin()+start1,version1.begin()+find1);
            string a2(version2.begin()+start2,version2.end());
            num1=atoi(a1.c_str());
            num2=atoi(a2.c_str());
            
            
            if(num1>num2)
            	return 1;
        	else if(num2>num1)
            	return -1;
            
            start1=find1+1;
            
            find1=version1.find(".",find1+1);
            while(find1!=string::npos){
                string a1(version1.begin()+start1,version1.begin()+find1);
                num1=atoi(a1.c_str());
                if(num1>0)
                    return 1;
                start1=find1+1;
                find1=version1.find(".",find1+1);
            }
            
            if(find1==string::npos){
                string a1(version1.begin()+start1,version1.end());
                num1=atoi(a1.c_str());
                 if(num1>0)
                    return 1;
                 else
                    return 0;
            }
            
            return 0;
        }
        else if(find1==string::npos&&find2!=string::npos){
            string a1(version1.begin()+start1,version1.end());
            string a2(version2.begin()+start2,version2.begin()+find2);
            num1=atoi(a1.c_str());
            num2=atoi(a2.c_str());
            if(num2>num1)
            	return -1;
        	else if(num2<num1)
            	return 1;
            	
            start2=find2+1;

        	find2=version2.find(".",find2+1);
        	while(find2!=string::npos){
                string a2(version2.begin()+start2,version2.begin()+find2);
                num2=atoi(a2.c_str());
                if(num2>0)
                    return -1;
                start2=find2+1;
                find2=version2.find(".",find2+1);
            }
            
            if(find2==string::npos){
                string a2(version2.begin()+start2,version2.end());
                num2=atoi(a2.c_str());
                 if(num2>0)
                    return -1;
                 else
                    return 0;
            }
            
            return 0;
            
        }else{
        	string a1(version1.begin()+start1,version1.end());
            string a2(version2.begin()+start2,version2.end());
            num1=atoi(a1.c_str());
            num2=atoi(a2.c_str());
            if(num1>num2)
            	return 1;
        	else if(num2>num1)
            	return -1;
            else 
            	return 0;

        } 
    }
};

int main(){
	string v1="2.2";
	string v2;"3.7";
	Solution s;
	cout<<s.compareVersion(v1,v2)<<endl;

	return 0;
}
/*
tinyUrl II 
As a follow up for Tiny URL, 
we are going to support custom tiny url, so that user can create their own tiny url.

createCustom("http://www.lintcode.com/", "lccode")
>> http://tiny.url/lccode
createCustom("http://www.lintcode.com/", "lc")
>> error
longToShort("http://www.lintcode.com/problem/")
>> http://tiny.url/1Ab38c   // this is just an example, you can have you own 6 characters.
shortToLong("http://tiny.url/lccode")
>> http://www.lintcode.com/
shortToLong("http://tiny.url/1Ab38c")
>> http://www.lintcode.com/problem/
shortToLong("http://tiny.url/1Ab38d")
>> null
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class TinyUrl2 {
private:
    vector<string> longUrlList;  //index is ID
    unordered_map<string, long long> hashMap;   // long, id
    unordered_map<string, string> cHashMapl2s;  //long, short
    unordered_map<string, string> cHashMaps2l;  //short long
public:
    /**
     * @param long_url a long url
     * @param a short key
     * @return a short url starts with http://tiny.url/
     */
    string createCustom(string& long_url, string& short_key) {
        if(shortURLtoID(short_key)<longUrlList.size())
            return "error";
            
        if(hashMap.find(long_url)!=hashMap.end()){
            if(cHashMaps2l[short_key]==long_url)
                return "http://tiny.url/" + short_key;
            else
                return "error";
        }
            
        // Write your code here
        if(cHashMaps2l.find(short_key)==cHashMaps2l.end()){
            cHashMaps2l[short_key]=long_url;
            cHashMapl2s[long_url] = short_key;
            hashMap[long_url]=shortURLtoID(short_key);
            
            //cout<<"11 "<<shortURLtoID(short_key)<<endl;
            
            return "http://tiny.url/" + short_key;
        }else{
            if(cHashMaps2l[short_key]==long_url)
                return "http://tiny.url/" + short_key;
            else
                return "error";
        }
        
    }

    long long shortURLtoID(string shortUrl){
        
        long long id = 0;
        for(int i=0;i<shortUrl.size();i++){
            id= id*62 + toBase62(shortUrl[i]);
        }
        
        return id;
    } 
     
    string idToShortURL(long id){
        string chars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string shortUrl="";
        
        while(id>0){
            shortUrl=chars[id%62] +shortUrl;
            id=id/62;
        }
        
        
        while(shortUrl.size()<6){
            shortUrl = "0" + shortUrl;
        }
        
        
        return shortUrl;
    } 
    
    long long toBase62(char c){
        string chars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        for(int i = 0; i < chars.size(); i++){
            if(chars[i] == c)
                return i;
        }
        
        return 0;
    }
    
     string longToShort(string url) {
         if(cHashMapl2s.find(url)!=cHashMapl2s.end())
            return "http://tiny.url/" + cHashMapl2s[url];
            
        // Write your code here
        if(hashMap.find(url)==hashMap.end()){
            string shortUrl = idToShortURL(longUrlList.size());
            while(cHashMaps2l.find(shortUrl)!=cHashMaps2l.end()){
                longUrlList.push_back(cHashMaps2l[shortUrl]);
                shortUrl = idToShortURL(longUrlList.size());
            }
            longUrlList.push_back(url);
            hashMap[url] = longUrlList.size()-1;
            //cout<<longUrlList.size()-1<<endl;
            return "http://tiny.url/" + shortUrl;
        }else{
            //cout<<"222 http://tiny.url/" + idToShortURL(hashMap[url])<<endl;
            return "http://tiny.url/" + idToShortURL(hashMap[url]);
        }
    }

    /**
     * @param url a short url starts with http://tiny.url/
     * @return a long url
     */
    string shortToLong(string url) {
        // Write your code here
        string shortUrl="";
        for(int i=url.size()-1;url[i]!='/';i--){
            shortUrl = url[i] + shortUrl;
        }
        //cout<<shortUrl<<endl;
        long long id = shortURLtoID(shortUrl);
        
        if(id<longUrlList.size())
            return longUrlList[id];
        else{
            if(cHashMaps2l.find(shortUrl)!=cHashMaps2l.end()){
                return cHashMaps2l[shortUrl];
            }else{
                string s;
                return s;  //should not be here
            }
        }
            
    }
};


int main(){
    TinyUrl2 s;

    s.createCustom("http://www.lintcode.com/", "lccode");
    s.longToShort("http://www.lintcode.com/");
    return 0;
}
/*
Given a long url, make it shorter. To make it simpler, let's ignore the domain name.

You should implement two methods:

s.longToShort(url). Convert a long url to a short url.
cout<<s.shortToLong(url). Convert a short url to a long url starts with http://tiny.url/.
You can design any shorten algorithm, the judge only cares about two things:

The short key's length should equal to 6 (without domain and slash). And the acceptable characters are [a-zA-Z0-9]. For example: abcD9E
No two long urls mapping to the same short url and no two short urls mapping to the same long url.

Example
Given url = http://www.lintcode.com/faq/?id=10, run the following code (or something similar):

short_url = s.longToShort(url) // may return http://tiny.url/abcD9E
long_url = cout<<s.shortToLong(short_url) // return http://www.lintcode.com/faq/?id=10
The short_url you return should be unique short url and start with http://tiny.url/ and 6 acceptable characters. For example "http://tiny.url/abcD9E" or something else.

The long_url should be http://www.lintcode.com/faq/?id=10 in this case.
*/

/*
base62 algorithm
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class TinyUrl {
private:
    vector<string> longUrlList;
    unordered_map<string, int> hashMap;
public:
    /**
     * @param url a long url
     * @return a short url starts with http://tiny.url/
     */
    int shortURLtoID(string shortUrl){
        
        int id = 0;
        for(int i=0;i<shortUrl.size();i++){
            id= id*62 + toBase62(shortUrl[i]);
        }
        
        return id;
    } 
     
    string idToShortURL(int id){
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
    
    int toBase62(char c){
        string chars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        for(int i = 0; i < chars.size(); i++){
            if(chars[i] == c)
                return i;
        }
        
        return 0;
    }
    
    string longToShort(string url) {
        // Write your code here
        if(hashMap.find(url)==hashMap.end()){
            longUrlList.push_back(url);
            hashMap[url] = longUrlList.size()-1;
            //cout<<longUrlList.size()-1<<endl;
            return "http://tiny.url/" + idToShortURL(longUrlList.size()-1);
        }else{
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
        for(int i=url.size()-1;i>url.size()-1 -6 ;i--){
            shortUrl = url[i] + shortUrl;
        }
        //cout<<shortUrl<<endl;
        int id = shortURLtoID(shortUrl);
        return longUrlList[id];
    }
};

int main(){

    TinyUrl s;

    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/30"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/68"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/19"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/13"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/15"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/0"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/53"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/42"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/42"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/33"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/28"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/61"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/29"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/29"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/45"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/27"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/43"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/70"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/33"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/15"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/50"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/31"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/58"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/35"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/18"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/53"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/65"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/15"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/10"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/66"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/59"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/0"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/44"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/2"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/58"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/5"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/40"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/29"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/55"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/37"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/29"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/55"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/38"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/14"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/27"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/51"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/7"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/70"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/56"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/51"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/4"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/45"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/47"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/21"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/64"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/31"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/56"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/20"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/62"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/24"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/60"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/61"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/19"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/5"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/10"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/47"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/5"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/39"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/44"))<<endl;
    cout<<s.shortToLong(s.longToShort("http://www.lintcode.com/en/question/33"))<<endl;
    
    return 0;
}
/*
GFS Client 
Implement a simple client for GFS (Google File System, a distributed file system), it provides the following methods:

read(filename). Read the file with given filename from GFS.
write(filename, content). Write a file with given filename & content to GFS.
There are two private methods that already implemented in the base class:

readChunk(filename, chunkIndex). Read a chunk from GFS.
writeChunk(filename, chunkIndex, chunkData). Write a chunk to GFS.
To simplify this question, we can assume that the chunk size is chunkSize bytes. (In a real world system, it is 64M). The GFS Client's job is splitting a file into multiple chunks (if need) and save to the remote GFS server. chunkSize will be given in the constructor. You need to call these two private methods to implement read & write methods.

Have you met this question in a real interview? Yes
Example
GFSClient(5)
read("a.txt")
>> null
write("a.txt", "World")
>> You don't need to return anything, but you need to call writeChunk("a.txt", 0, "World") to write a 5 bytes chunk to GFS.
read("a.txt")
>> "World"
write("b.txt", "111112222233")
>> You need to save "11111" at chink 0, "22222" at chunk 1, "33" at chunk 2.
write("b.txt", "aaaaabbbbb")
read("b.txt")
>> "aaaaabbbbb"
*/


#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

/* Definition of BaseGFSClient
 * class BaseGFSClient {
 * private: map<string, string> chunk_list;
 * public:
 *     string readChunk(string& filename, int chunkIndex) {
 *         // Read a chunk from GFS
 *     }
 *     void writeChunk(string& filename, int chunkIndex,
 *                     string& content) {
 *         // Write a chunk to GFS     
 *     }
 *  };
 */

class GFSClient : public BaseGFSClient {
private:
    unordered_map<string, vector<int> > map;
    int mChunkSize;
public:
    GFSClient(int chunkSize) {
        // initialize your data structure here
        map.clear();
        mChunkSize = chunkSize;
    }

    // @param filename a file name
    // @return conetent of the file given from GFS
    string read(string& filename) {
        // Write your code here
        string ans;
        if(map.find(filename) == map.end()) return ans;
        int chunks = map[filename][0];
        int left = map[filename][1];
        
        for(int i = 0;i<chunks;i++){
            string contentPart = readChunk(filename, i); 
            //cout<< contentPart <<endl;
            ans += contentPart;
        }
        
        if(left!=0){
            string contentPart = readChunk(filename, chunks); 
            ans += contentPart;
        }
        
        return ans;
    }

    // @param filename a file name
    // @param content a string
    // @return void
    void write(string& filename, string& content) {
        // Write your code here
        int bytes = content.size();
        int chunks = bytes/mChunkSize;
        int left = bytes%mChunkSize;
        
        if(left != 0){
            int i = 0;
            for(i = 0;i<chunks;i++){
                string contentPart = content.substr(i*mChunkSize, mChunkSize);
                writeChunk(filename, i, contentPart); 
            }
            
            //push last part
            string contentPart = content.substr(i*mChunkSize, left);
            writeChunk(filename, i, contentPart);
        }else{
            for(int i = 0;i<chunks;i++){
                string contentPart = content.substr(i*mChunkSize, mChunkSize);
                writeChunk(filename, i, contentPart); 
            }
        }
        
        vector<int> node;
        node.push_back(chunks);
        node.push_back(left);
        
        map[filename] = node;
        
        return;
    }
};
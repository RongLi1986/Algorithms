/*
Mini Cassandra
Cassandra is a NoSQL storage. The structure has two-level keys.

Level 1: raw_key. The same as hash_key or shard_key.
Level 2: column_key.
Level 3: column_value
raw_key is used to hash and can not support range query. let's simplify this to a string.
column_key is sorted and support range query. let's simplify this to integer.
column_value is a string. you can serialize any data into a string and store it in column value.

implement the following methods:

insert(raw_key, column_key, column_value)
query(raw_key, column_start, column_end) // return a list of entries


insert("google", 1, "haha")
query("google", 0, 1)
>> [（1, "haha")]
*/

#include <map>
#include <string>

/**
 * Definition of Column:
 * class Column {
 * public:
 *     int key;
 *     String value;
 *     Column(int key, string value) {
 *         this->key = key;
 *         this->value = value;
 *    }
 * }
 */
class MiniCassandra {
private:
    unordered_map<string, map<int, string> > cassandra ; 
public:
    MiniCassandra() {
        // initialize your data structure here.
        cassandra.clear();
    }
    
    /**
     * @param raw_key a string
     * @param column_start an integer
     * @param column_end an integer
     * @return void
     */
    void insert(string raw_key, int column_key, string column_value) {
        // Write your code here
        cassandra[raw_key][column_key]=column_value;
    }

    /**
     * @param raw_key a string
     * @param column_start an integer
     * @param column_end an integer
     * @return a list of Columns
     */
    vector<Column> query(string raw_key, int column_start, int column_end) {
        // Write your code here
        vector<Column> res;
        if(cassandra.find(raw_key) == cassandra.end()){
            return res;
        }else{
            map<int,string>::iterator itLow=cassandra[raw_key].lower_bound(column_start);
            map<int,string>::iterator itHigh=cassandra[raw_key].upper_bound(column_end);
            
            for(map<int,string>::iterator it=itLow; it!=itHigh; ++it){
                Column column(it->first,it->second);
                res.push_back(column);
            }
        }
        
        return res;
    }
};

int main(){

	return 0;
}
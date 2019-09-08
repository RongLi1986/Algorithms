/*
Find top k frequent words with map reduce framework.

The mapper's key is the document id, value is the content of the document, words in a document are split by spaces.

For reducer, the output should be at most k key-value pairs, which are the top k words and their frequencies in this reducer. The judge will take care about how to merge different reducers' results to get the global top k frequent words, so you don't need to care about that part.

The k is given in the constructor of TopK class.
*/
/**
 * Definition of Input:
 * template<class T>
 * class Input {
 * public:
 *     bool done(); 
 *         // Returns true if the iteration has elements or false.
 *     void next();
 *         // Move to the next element in the iteration
 *         // Runtime error if the iteration has no more elements
 *     T value();
 *        // Get the current element, Runtime error if
 *        // the iteration has no more elements
 * }
 * Definition of Document:
 * class Document {
 * public:
 *     int id; // document id
 *     string content; // document content
 * }
 */
 
class mycomparison
{
public:
  mycomparison(){
      
  }
  bool operator() (const pair<string, int>& lhs, const  pair<string, int>& rhs) const
  {
    if(lhs.second == rhs.second){
        int i=0;
        while((lhs.first)[i] == (rhs.first)[i]){
            i++;
        }
        return (lhs.first)[i] > (rhs.first)[i];
    }
    return (lhs.second < rhs.second);
  }
}; 
 
class TopKFrequentWordsMapper: public Mapper {
public:
    void Map(Input<Document>* input) {
        // Write your code here
        // Please directly use func 'output' to 
        // output the results into output buffer.
        // void output(string &key, int value);
        while(!input->done()){
            Document s = input->value();
            vector<string> words = findWords(s.content);
            //vector<string> words = split(s, " ");
            
            for(int i=0;i<words.size();i++){
                //cout<<words[i]<<endl;
                output(words[i], 1);
            }
            input->next();
        }
        //cout<<"map"<<endl;
        return;
    }
    
    vector<string> findWords(string& s){
        s+=" ";
        std::size_t found = s.find(" ");
        std::size_t current = 0;
        vector<string> res;
        
        while(found!=std::string::npos){
            string word = s.substr(current, found - current);
            if(word.size()!=0)
                res.push_back(word);
            current =found+1;
            found = s.find(" ", current);
        }
        
        return res;
    }
};


class TopKFrequentWordsReducer: public Reducer {
private:
    priority_queue<pair<string,int>, vector<pair<string,int> >, mycomparison > pQueue;
    int count;
public:
    void setUp(int k) {
        // initialize your data structure here
        //cout<<"ss"<<endl;
        count = k;
    }

    void Reduce(string &key, Input<int>* input) {
        // Write your code here
        int sum = 0;
        while (!input->done()) {
            sum += input->value();
            input->next();
        }
        
        pair<string, int> p;
        p=make_pair(key,sum);
        
        pQueue.push(p);
        //cout<<"re"<<endl;
    }

    void cleanUp() {
        // Please directly use func 'output' to output 
        // the top k pairs <word, times> into output buffer.
        // void output(string &key, int &value);
        
        for(int i=0;i<count;i++){
            pair<string,int> p;
            p = pQueue.top();
            //cout<<p.first<<" "<< p.second <<endl;
            output(p.first,p.second);
            pQueue.pop();
        }
        //cout<<"cc"<<endl;
        return;
    }
};
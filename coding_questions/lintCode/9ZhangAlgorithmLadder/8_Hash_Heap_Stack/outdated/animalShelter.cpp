/*
An animal shelter holds only dogs and cats, and operates on a strictly "first in, first out" basis. People must adopt either the "oldest" (based on arrival time) of all animals at the shelter, or they can select whether they would prefer a dog or a cat (and will receive the oldest animal of that type). They cannot select which specific animal they would like. Create the data structures to maintain this system and implement operations such as enqueue, dequeueAny, dequeueDog and dequeueCat.

Have you met this question in a real interview? Yes
Example
int CAT = 0
int DOG = 1

enqueue("james", DOG);
enqueue("tom", DOG);
enqueue("mimi", CAT);
dequeueAny();  // should return "james"
dequeueCat();  // should return "mimi"
dequeueDog();  // should return "tom"
*/
 
class node{
public:
    string name;
    int type;
    node(string s, int t){
        name = s;
        type = t;
    }
};

class AnimalShelter {
private:
    vector<node*> queue; 
public:
    AnimalShelter() {
        // do initialization if necessary
    }

    /**
     * @param name a string
     * @param type an integer, 1 if Animal is dog or 0
     * @return void
     */
    void enqueue(string &name, int type) {
        // Write your code here
        node* ptr=new node(name, type);
        queue.push_back(ptr);
        return;
    }

    string dequeueAny() {
        // Write your code here
        string res=queue[0]->name;
        queue.erase(queue.begin());
        
        return res;
    }

    string dequeueDog() {
        // Write your code here
        string res;
        int i;
        for(i=0;i<queue.size();i++){
            if(queue[i]->type==1){
                res=queue[i]->name;
                queue.erase(queue.begin()+i);
                break;
            }
        }
    
        return res;
    }
    
    string dequeueCat() {
        // Write your code here
        string res;
        int i;
        for(i=0;i<queue.size();i++){
            if(queue[i]->type==0){
                res=queue[i]->name;
                queue.erase(queue.begin()+i);
                break;
            }
        }
    
        return res;
    }
};
/*
LRU Cache 
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, 
it should invalidate the least recently used item before inserting a new item.
*/

#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;

struct pageNode
{
    int key;
    int val;
    pageNode* pre;
    pageNode* next;
    pageNode(int k,int x) : key(k),val(x), pre(NULL),next(NULL) {}
};

class CacheQueue{
private:
    pageNode* head;
    int nodeCount;
public:
    CacheQueue(){
        head=NULL;
        nodeCount=0;
    }

    int checkNodeNums(){
        return nodeCount;
    }

    //maybe uesless
    void insertNodeFromEnd(pageNode* inNode){
        if(head==NULL){ //head is NULL
            head=inNode;
        }else{
            pageNode* ptr=head;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=inNode;
            inNode->pre=ptr;
        }

        nodeCount++;
    }

    void insertNodeFromBegin(pageNode* inNode){
        if(head==NULL){
            head=inNode;
        }else{
            inNode->next=head;
            head->pre=inNode;
            head=inNode;
        }
        nodeCount++;
    }

    void popNode(pageNode* inNode){
        //make sure no corner case
        if(inNode==head){
            pageNode* p=head;
            head=p->next;
            p->next=NULL;
        }else{
            pageNode* p=inNode->pre;
            pageNode* n=inNode->next;

            p->next=n;
            
            if(n!=NULL) //for last node case
                n->pre=p;

            inNode->pre=NULL;
            inNode->next=NULL;
        }
        nodeCount--;
    }

    int popNodeBack(){
        //make sure no corner case
        if(head->next==NULL) { //for only head case
            int key =head->key;
            head=NULL; 
            return key;
        }
        pageNode* ptr=head;
        while(ptr->next!=NULL){
            
            ptr=ptr->next;
        }
        int key =ptr->key;
        
        pageNode* tmp=ptr->pre;
        ptr=NULL;
        
        if(tmp!=NULL) 
            tmp->next=NULL;
        //delete ptr;
        nodeCount--;

        return key;
    }

    void printNode(){
        pageNode* ptr=head;
        while(ptr!=NULL){
            cout<<ptr->val<<"->";
            ptr=ptr->next;
        }
        cout<<endl;
    }

};


class LRUCache{
private:
    unordered_map<int, pageNode* > mymap;  //key and node address
    CacheQueue queue; 
    int max;
public:
    LRUCache(int capacity) {
        max=capacity;
    }
    
    int get(int key) {
        unordered_map<int,pageNode* >::const_iterator got = mymap.find(key);
        if(got==mymap.end()){
            return -1;
        }else{
            pageNode* ptr=got->second;
            queue.popNode(ptr);
            queue.insertNodeFromBegin(ptr);
            //queue.printNode();
            return  ptr->val;
        }
    }
    
    void set(int key, int value) {
        unordered_map<int,pageNode* >::const_iterator got = mymap.find(key);
        if(got==mymap.end()){
            pageNode* ptr=new pageNode(key,value);
            if(queue.checkNodeNums()<max){
                queue.insertNodeFromBegin(ptr);
            }else{
                int key=queue.popNodeBack();
                mymap.erase(key);
                queue.insertNodeFromBegin(ptr);
            }

            mymap[key]=ptr;
        }else{
            pageNode* ptr=got->second;
            queue.popNode(ptr);
            queue.insertNodeFromBegin(ptr);
            ptr->val=value;
        }

        return;
    }
};

int main(){
    //test cacheQueue finished
    /*
    pageNode* head=new pageNode(0,0);
    pageNode* a=new pageNode(1,1);
    pageNode* b=new pageNode(2,2);
    pageNode* c=new pageNode(3,3);
    pageNode* d=new pageNode(4,4);
    pageNode* e=new pageNode(5,5);

    CacheQueue queue; 
    queue.printNode();
    
    queue.insertNodeFromBegin(head);
    queue.insertNodeFromBegin(a);
    queue.insertNodeFromBegin(b);
    //queue.insertNodeFromBegin(c);
    //queue.insertNodeFromBegin(d);
    queue.printNode();
    
    queue.popNodeBack();
    queue.printNode();

    //queue.popNode(d);
    //queue.popNode(a);
    queue.printNode();
    */

    //test LRU Cache
    LRUCache lr(2);

    //lr.set(2,1);
    lr.set(2,2);


    cout<<lr.get(2)<<endl;


    lr.set(1,1);
    lr.set(4,1);

    cout<<lr.get(2)<<endl;

	return 0;
}
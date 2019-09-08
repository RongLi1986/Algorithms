/*
Factory is a design pattern in common usage. 
Please implement a ToyFactory which can generate proper toy based on the given type.

Have you met this question in a real interview? Yes
Example
ToyFactory tf = ToyFactory();
Toy toy = tf.getToy('Dog');
toy.talk(); 
>> Wow

toy = tf.getToy('Cat');
toy.talk();
>> Meow
*/

#include <iostream>

/**
 * Your object will be instantiated and called as such:
 * ToyFactory* tf = new ToyFactory();
 * Toy* toy = tf->getToy(type);
 * toy->talk();
 */
class Toy {
public:
    virtual void talk() const=0;
};

class Dog: public Toy {
    // Write your code here
    void talk() const{
        cout<<"Wow"<<endl;
    }
};

class Cat: public Toy {
    // Write your code here
    void talk() const{
        cout<<"Meow"<<endl;
    }
};

class ToyFactory {
public:
    /**
     * @param type a string
     * @return Get object of the type
     */
    ToyFactory(){
        
    } 
    
    Toy* getToy(string& type) {
        // Write your code here
        if(type == "Dog"){
            Dog* dog = new Dog();
            return dog;
        }else if(type == "Cat"){
            Cat* cat = new Cat();
            return cat;
        }else{
            //error
        }
    }
};

int main(){

    return 0;
}
/*
Factory is a design pattern in common usage. Implement a ShapeFactory that can generate correct shape.

You can assume that we have only tree different shapes: Triangle, Square and Rectangle.

ShapeFactory sf = new ShapeFactory();
Shape shape = sf.getShape("Square");
shape.draw();
>>  ----
>> |    |
>> |    |
>>  ----

shape = sf.getShape("Triangle");
shape.draw();
>>   /\
>>  /  \
>> /____\

shape = sf.getShape("Rectangle");
shape.draw();
>>  ----
>> |    |
>>  ----

*/

#include <iostream>

/**
 * Your object will be instantiated and called as such:
 * ShapeFactory* sf = new ShapeFactory();
 * Shape* shape = sf->getShape(shapeType);
 * shape->draw();
 */
class Shape {
public:
    virtual void draw() const=0;
};

class Square: public Shape {
    // Write your code here
    void draw() const{
        cout<<" ---- "<<endl;
        cout<<"|    |"<<endl;
        cout<<"|    |"<<endl;
        cout<<" ---- "<<endl;
    }
};

class Triangle: public Shape {
    // Write your code here
    void draw() const{
        cout<<"  /\\  "<<endl;
        cout<<" /  \\ "<<endl;
        cout<<"/____\\"<<endl;
        
    }
};

class Rectangle: public Shape {
    // Write your code here
    void draw() const{
        cout<<" ---- "<<endl;
        cout<<"|    |"<<endl;
        cout<<" ---- "<<endl;
    }
};

class ShapeFactory {
public:
    /**
     * @param shapeType a string
     * @return Get object of type Shape
     */
    Shape* getShape(string& shapeType) {
        // Write your code here
        if(shapeType == "Square"){
            Square* s = new Square();
            return s;
        }else if(shapeType == "Triangle"){
            Triangle* s = new Triangle();
            return s;
        }else if(shapeType == "Rectangle"){
            Rectangle* s = new Rectangle();
            return s;
        }else{
            
        }
    }
};

int main(){

    return 0;
}
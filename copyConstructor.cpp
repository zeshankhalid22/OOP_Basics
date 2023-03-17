//  *** Suppose object obj1 has called some constructor and values are set for object.
//      Now i want to create other object obj2, but i wanna suse obj1's Values.
//      Copy constructor will exactly copy obj1's values into obj2 without calling constructor for obj2 separately. ***

#include "iostream"
using namespace std;

class Point{
    int p1,p2;
public:
    Point(int x1,int x2){ // Normal constructor
        p1=x1;
        p2=x2;
    }

    Point(const Point &t){  // Copy Constructor called
        p1=t.p1;
        p2=t.p2;
    }

    void print(){ // print p1,p2 values
        cout<<"p1 is: "<<p1<<"\np2 is: "<<p2<<endl;
    }

};
int main(){
    Point obj1(5,10);   // Normal Constructor called
    obj1.print();               // Printing values

    Point obj2(obj1);           // Copy Constructor called
    obj1.print();               // Printing values

}

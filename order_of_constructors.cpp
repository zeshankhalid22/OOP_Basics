#include "iostream"
using namespace std;

/*  Derived Class -> Base Class
    Der1           -> Base1
    Der2           -> Base2
    Final           -> Der1, Der2
 */

/*  Order of Constructor Calling >
    Base1 > Der1 > Base 1 > Der2 > Final
    Destructor will follow reverse order
 */

class Base1{
    int a;
public:
    Base1(int a1){
        a=a1;
        cout<<"Base 1 called.\n";
    }
    void printBase1(){
        cout<<" Base1 printed: "<<a<<endl;
    }
    ~Base1(){
        cout<<"Base1 Destroyed\n";
    }
};

class Der1: public Base1{
    int b;
public:
    //  b2 will be given to Base1 Constructor
    Der1(int b1,int b2): Base1(b2){
        b=b1;
        cout<<"Der 1 called.\n";
    }
    void printDer1(){
        cout<<" Der1 printed: "<<b<<endl;
    }
    ~Der1(){
        cout<<"Der1 Destroyed\n";
    }
};
class Der2:  public Base1{
    int c;
public:
    // c2 will be given to Base1 Constructor
    Der2(int c1,int c2): Base1(c2){
        c=c1;
        cout<<"Der 2 called.\n";
    }
    void printFinal(){
        cout<<" Der2 printed: "<<c<<endl;
    }
    ~Der2(){
        cout<<"Der2 Destroyed\n";
    }
};

class Final: public Der1,public Der2{
    int x;
public:
    // Der1 and Der2 both inherited by `Base` Class. so 2 Copies of Base Class members will be created.
    // I am passing different values to 2 Derived Classes from Base class. they will print different values.
    // `11` in case of `Der1`, `22` in case of `Der2`

    Final(int D1, int D2, int B1, int f3): Der1(D1, 11), Der2(D2, 22){
        // Final Constructor takes 4 values
        // D1 and 11 are passed to Der1 constructor. D2 and 22 are passed to Der2 constructor.
        x=f3;
        cout<<"Final called.\n";
    }
   void printFinal(){
        cout<<" Final printed: "<<x<<endl<<endl;
    }
    ~Final(){
        cout<<"Final Destroyed\n";
    }
};
int main(){

    Final obj1(1, 2, 3, 4);
    cout<<endl;
    obj1.printDer1();   // Value inside `Der1` class be printed
    obj1.printFinal();   // Value inside `Der2` class be printed

    // obj1.printBase1(); it will give error cuz can't pick decide from two copies of PrintB() function
    // we will solve it by Ambiguity resolution operator

    obj1.Der1::printBase1();  // Calling `printBase1()` function that is defined in `Base1` class and is copied into `Der1`.
    obj1.Der2::printBase1();

    obj1.printFinal();    // Final class Function
}

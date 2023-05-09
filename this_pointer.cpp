/*  *Important Points
 return this*;    , will return back the Object's Address for further use, we can also print it
 [Method chaining]   , by return Address(reference) of X object, the same  object can
      chain(again call another fun where previous left). eg X.setVal(4).print().setval(8)
 [State Modification] updating State/values/members of an Object in Real time. Performed in Rectangle Class
*/

#include "iostream"
using namespace std;

class Marks{
    int TotalMarks;
public:
    Marks(){
        this->TotalMarks = 0;
    }


    Marks &Add(int value){

        this->TotalMarks +=value; // TotalMarks function will be updates automatically, whenever we Add,subtract value form it
        return *this;               // return the address of Object (mean Object itself)
    }

    Marks &Subtract(int value){

        this->TotalMarks -=value;
        return *this;
    }


    Marks &showUpdatedMarks(){
        cout << "Value is: " << TotalMarks << endl;
        return *this;
    }
    Marks* returnAddress(){ // Marks*(return type of object). will return pointer to the type of object of [Marks] class
        return this;       // [this] point to the current object
    }

};
class Rectangle{
    int length,width;
    int Area;

    void updateArea(){  // Update Object's Area when function called with values
        this->Area = this->length * this->width;
    }
public:
    Rectangle &setLength(int length){
        this->length = length;
        updateArea();       // [State Modification] real time Update of Area

    }
    Rectangle &setWidth(int width){
        this->width = width;
        updateArea();       // [State Modification] real time Update of Area
    }

    Rectangle &printArea(){
        cout<<"Area: "<<Area<<endl;
    }
};
int main(){
                            // [Marks Object demonstration]
    Marks myObj;
    /* myObj.add(5);
      myObj.Add(7);
      myObj.print(); */

    // instead of these 3 lines, we can do it in one line using [Method Chaining]
    myObj.Add(5).Add(7).showUpdatedMarks();   // Calling Add(5) will return Object itself,
                                                    // then it will be Calling another function Add(7), which also return object itself . . .
                                                    // myObj.Add(5) will ->(return)(becomes) myObj after 1st function Call and so on . . .

    myObj.Subtract(6).Subtract(7).showUpdatedMarks();   //Again  Method chaining and saving space

    cout<<"Object Address: "<<myObj.returnAddress()<<endl;
    cout<<endl;
    // -    -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -
                            // [Rectangle Object demonstration]
     Rectangle obj1;
    // Method chaining
    obj1.setLength(5).setWidth(8).printArea(); // print 40

    // only change 1 Value and area will be updated automatically
    obj1.setWidth(2).printArea();      // print 10

}

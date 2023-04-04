#include "iostream"
using namespace std;

class Student{
    string name;
    string rollNo;
    char grade;
public:
    void setData(string n,string r,char g){
        name = n;
        rollNo = r;
        grade = g;
    }
    void printData(){
        cout<<"Name: "<<name<<", rollNO: "<<rollNo<<", grade: "<<grade<<endl;
    }
};
int main(){

    int size;
    cout<<"Enter size of Students: ";
    cin>>size;

    Student *ptr = new Student[size];   // Creating a dynamic array of Student Objects with inputted size
    Student *tempPtr = ptr;         // Temporary pointer to store Base address when ptr gone out of range.

    for(int i=0;i<size;i++){        // Getting Student input
        cout<<"Enter Data of Student (Name, rollNo, grade): "<<i+1<<endl;
        string S;string R;char C;
        cin>>S>>R>>C;
        // (*ptr).setData() 
        // ptr[i].setData(S,R,C);  same as . . .
        ptr->setData(S,R,C);
        ptr++;                      // ptr will go out of range from Base Address
    }

    ptr = tempPtr;          // restoring Base Address into ptr from temporary variable
    cout<<"\t\t- - - Printing Value - - -";
    for(int j=0;j<size;j++){
        cout<<"\nStudent Number "<<j+1<<endl;
        ptr->printData();
    }

}

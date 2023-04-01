#include "iostream"
using namespace std;

// Virtual classes are primarily used during multiple inheritance. To avoid
// multiple instances of the same class being taken to the same class which later
// causes ambiguity, virtual classes are used.
// Person -> Teacher
// Person -> Student
// TA -> Teacher
// TA -> Student
class Person{
protected:
    string Name;
public:
    Person(string n){
        Name = n;
    }
    void printPerson(){
        cout << "Name is: " << Name << endl;
    }
};

// Teacher is a derived class of Person, virtually inheriting from Person
class Teacher: public virtual Person{
protected:
    int Salary;
public:
    // Constructor with initialization list for Name and Salary
    Teacher(string name, int salary) : Person(name),Salary(salary){}
    // Function to print teacher's salary
    void printTeacher(){
        cout<<"Salary: "<<Salary<<endl;
    }
};

// Student is a derived class of Person, virtually inheriting from Person
class Student: public virtual Person{
protected:
    char Grade;
public:
    // Constructor with initialization list for Name and Grade
    Student(string name, char grade):Person(name),Grade(grade){}
    
    // Function to print student's grade
    void printStudent(){
        cout<<"Grade is: "<<Grade<<endl;
    }
};

// TA is a derived class of Teacher and Student, with virtual inheritance from both
class TA: public Teacher, public Student{
    string Email;
protected:
    string CourseName;
    int semester;

public:
    // Constructor with initialization list for all the inherited members and Email and CourseName
    TA(string name, char grade, int salary, string coursename): Person(name), Teacher(name,salary),
                                                                Student(name,grade), CourseName(coursename){}
                                                                

    // Function to print TA's information
    void printTA(){
        printPerson();      // Call Person's print function to print TA's name
        printTeacher();     // Call Teacher's print function to print TA's salary
        printStudent();     // Call Student's print function to print TA's grade
        cout<<"Course Name is: "<<CourseName<<endl; // Print TA's course name
    }
};

int main(){
   
    TA t1("Zeshan",'A',1200,"OOP");
    t1.printTA();   // Print TA's information
}

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
    string Department;
protected:
    int Salary;
public:
    // Constructor with initialization list for Name and Salary
    Teacher(string name, int salary) : Person(name),Salary(salary){}
    
    // Setter and getter for Department
    void setDepartment(string department) {
        Department = department;
    }
    string getDepartment(){
        return Department;
    }
    // Function to print teacher's salary
    void printTeacher(){
        cout<<"Salary: "<<Salary<<endl;
    }
};

// Student is a derived class of Person, virtually inheriting from Person
class Student: public virtual Person{
    string rollNum;
protected:
    char Grade;
public:
    // Constructor with initialization list for Name and Grade
    Student(string name, char grade):Person(name),Grade(grade){}
    
    // Setter and getter for rollNum
    void setRollNum(string roll){
        rollNum = roll;
    }
    string getRollNum(){return rollNum;}

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

    // Setter and getter for Email
    void setEmail(string email){Email=email;}
    string getEmail(){return Email;}

    // Function to print TA's information
    void printTA(){
        printPerson();      // Call Person's print function to print TA's name
        printTeacher();     // Call Teacher's print function to print TA's salary
        printStudent();     // Call Student's print function to print TA's grade
        cout<<"Course Name is: "<<CourseName<<endl; // Print TA's course name
    }
};

int main(){
    // Create an object of TA with name "Zeshan", grade "A", salary 1200, and course name "OOP"
    TA t1("Zeshan",'A',1200,"OOP");
    t1.setEmail("imzeshankhalid@gmail.com");  // Set TA's email to "imzeshankhalid@gmail.com"
    t1.printTA();   // Print TA's information
}

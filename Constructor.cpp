#include "iostream"
using namespace std;

class StudentFlex{

    int Attendance;
    int test_marks[5];
    float course_marks;

public:
    string Name;
    // Default Constructor, when I will pass no value
    StudentFlex() {
        Name = "Unknown person";
        Attendance = 0;
        for (int i = 0; i < 5; i++) {
            test_marks[i] = 0;
        }
        course_marks=0;
    }

    // Parameterized Constructor to assign values
    StudentFlex(string name,int att,int testMarks[5]){
        Name = name;
        Attendance = att;
        for(int i=0;i<5;i++){
            test_marks[i]=testMarks[i];
        }
        course_marks = calc_course_marks();
    }

    float calc_course_marks(){
        // Function to Calculate total marks based on test marks
        float total = 0;
        for(int i=0;i<5;i++){
            total += test_marks[i];
        }
        return total*2;
    }

    void printData(){
        // Print Data memebers
        cout<<"name is: "<<Name
            <<"\nAttendance: "<<Attendance
            <<"%\nCourse Marks: "<<course_marks<<endl;
    }


};
int main(){
        // constructor with arguments
        int arr[5]={5,5,5,5,5};
        StudentFlex std("Zeshan khalid",82,arr);
        std.printData();

        // constructor without any argument
        // i did'nt assign any value, it will print default construct values
        StudentFlex s1;
        cout<<endl;
        s1.printData();



}

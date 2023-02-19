#include "iostream"
using namespace std;
class Student{
    // Private members
    int my_key;
    string phone_number;

    string ENCRYPT(string Message){
        // This function gets a string,Encrypted according to my_key, return;
        string encrypt = Message;
        for(int i=0;i<Message.length();i++){
            encrypt[i]= Message[i] ^ my_key;
        }
        return encrypt;
    }

    string DECRYPT(string message) {
        // it Decrypts the Encrypted string
        string decrypted = message;
        for (int i = 0; i < message.length(); i++) {
            decrypted[i] = message[i] ^ my_key;
        }
        return decrypted;
    }

public:
    string my_name;
    int my_roll_no;

        // * Setters
    void set_data(string name, int rollNo, string phoneNumber){
        // Assign values to Data members
            my_name=name;
            my_roll_no=rollNo;
        phone_number = phoneNumber;
    }

    string encrypt_message(string message, int key){
        // encrypt message by calling the 'private ENCRYPT function according to given key
            my_key=key;
            string encrypted = ENCRYPT(message);
            return encrypted;
    }
        // * Getters

        void print_data(){
            // Function to print data members os class
            cout << "Student's Name is: " << my_name
                 << "\nroll No: " << my_roll_no
                <<"\nPhone_Number: "<<phone_number<<endl;
        }

    string decrypt_(string message, int key){
        // it calls the private decrypt function to decrypt the message
        // If the key is correct, return the decrypted message, otherwise " "
        if((key ^ my_key) != 0)
            return "";
        else
            return DECRYPT(message);
    }




};
int main(){

    Student std[5]; // Multiple Objects Created

    std[0].set_data("Zeshan khalid", 9230, "03177680092");

    // passing message along with key to encrypt
    string encrypted = std[0].encrypt_message("Artix Linux", 25);

    std[0].print_data();
    cout<<endl<<"Encrypted Message is "<<encrypted<<endl;

    // encrypted message along with key passed to 'decrypt_ function, if key is true we will get answar
    string decrypted= std[0].decrypt_(encrypted, 25);
    if(decrypted=="")
        cout<<"Wrong input key.\n";
    else
        cout<<"Decrypted Message is "<<decrypted<<endl;

}

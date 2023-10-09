/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>

using namespace std;

class Target{
    public:
        virtual void request(string o) = 0;
        // virtual void changeMessage(int) = 0;
        virtual void displayMessage() = 0;
};

class Adaptee{
    public:
        Adaptee(string msg) : message(msg) {};
        string getMessage(){return message;};
        void setMessage(string msg){
            // cout << s << endl;
            if(msg == "SELECT * FROM tbl"){
                message = "FROM tbl SELECT *";
            }

            if(msg == "SELECT * FROM tbl WHERE id = 1"){
                message = "FROM tbl SELECT * WHERE id = 1";
            }

            if(msg == "SELECT * FROM tbl WHERE id = 1 AND name = 'John'"){
                message = "FROM tbl SELECT * WHERE id = 1 AND name = 'John'";
            }
        };
    private:
        string message;
};

class Adapter : public Target{
    public:
        Adapter(){
            adapt = new Adaptee(string(""));
        };
        virtual void request(string o){
            adapt->setMessage(o);
        };
        // virtual void changeMessage(int);
        virtual void displayMessage(){
            cout << "In the Required Format: " << adapt->getMessage() << endl;
        };
    private:
        Adaptee* adapt;
};


int main()
{
    string sentence;

    cout << "Enter your SQL Statement: ";
    getline(cin, sentence);

    Adapter obj;
    
    cout << "Original message: " << sentence << endl;
    
    obj.request(sentence);
    obj.displayMessage();
}

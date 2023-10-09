#include <iostream>
#include "Handler.h"
using namespace std;


int main(){
    client* currClient = new client();
    Handler* currHandler = new nonceHandler();

    string input;

    cout << "Would you like to request a nonce?(Y/N)" << endl;
    cin >> input;

    if(input == "Y"){
        currHandler->handle(currClient);
    }else{
        return 0;
    }

    cout << "Attempting to validate nonce..." << endl;
   
    currHandler->handle(currClient);

    cout << "Attempting to validate token..." << endl;

    currHandler->handle(currClient);

    return 0;
}
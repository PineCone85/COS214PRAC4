#include "Handler.h"
#include <iostream>

using namespace std;

void nonceHandler::handle(client* client){
    if(client->getNonce() == 0){
        this->setNextHandler(new ValidateSignInHandler());
        client->setNonce(5);  
        cout<< "There has been a nonce code generated for you!" << endl;
    }
    else{
        handleNext(client);
    }
}

void ValidateSignInHandler::handle(client* client){
    if(!client->getValid()){
        client->setValid();
        client->setToken(5);
        cout << "You have succesfully validated your nonce and have been given a token!" << endl;
    }else{
        cout<< "Nonce has already been validated and you have a token." << endl;
        this->setNextHandler(new tokenHandler());
        handleNext(client);
    }
}

void tokenHandler::handle(client* client){
    if(client->getToken() != 0){
        cout << "Token is valid passing to next handler..." << endl;
        this->setNextHandler(new AuthHandler());
        handleNext(client);
    }else{
        cout << "Invalid token!";
    }
}

void AuthHandler::handle(client* client){
    cout<< "You have been successfully validated." << endl << "Printing result..." << "[Result]";
}

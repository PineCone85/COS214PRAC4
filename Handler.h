using namespace std;

class client{
    private:
        int nonce;
        int token;
        bool valid;
    public:

        client(){
            nonce = 0;
            token = 0;
            valid = false;
        }

        int getNonce(){
            return nonce;
        }

        int getToken(){
            return token;
        }

        void setNonce(int val){
            nonce = val;
        }

        void setToken(int val){
            token = val;
        }

        bool getValid(){
            return token;
        }

        void setValid(){
            valid = true;
        }
};

class Handler
{
private:
    Handler* next;
public:
    Handler(){};
    ~Handler(){};

    Handler* setNextHandler(Handler* next1){
            next = next1;
            return next;
        }

    virtual void handle(client* client) = 0;

    void handleNext(client* client){
        if(next == 0){
            return;
        }
            return next->handle(client);
        }
};

class nonceHandler: public Handler{
    public:
        void handle(client* client);
};

class ValidateSignInHandler: public Handler{
    public:
        void handle(client* client);
};

class tokenHandler: public Handler{
    public:
        void handle(client* client);
};

class AuthHandler: public Handler{
    public:
        void handle(client* client);
};
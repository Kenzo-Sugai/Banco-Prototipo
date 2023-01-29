#include <iostream>

class Usuario {

    public:

        Usuario(std::string username, std::string password){

            this->username = username;
            this->password = password;

            this->balance = "0";

        }

        void setUsername(std::string username);
        void setPassword(std::string password);
        void setBalance(std::string money);
        std::string getPassword();
        std::string getBalance();
    
    private:

        std::string username;
        std::string password;
        std::string balance;

    void setUsername(std::string username){

        this->username = username;

    }

    void setPassword(std::string password){

        this->password = password;

    }

    void setBalance(std::string money){

        this->balance = money;

    }

    std::string getUsername(){

        return this->username;

    }

    std::string getPassword(){

        return this->password;

    }

    std::string getBalance(){

        return this->balance;

    }

};
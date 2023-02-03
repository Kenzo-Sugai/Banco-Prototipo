#include <iostream>
#include <fstream>
#include <string>

class Usuario {

    public:

        Usuario(std::string username);
        void setUsername(std::string username);
        void setPassword(std::string password);
        void setBalance(std::string money, char operation);
        std::string getUsername();
        std::string getPassword();
        std::string getBalance();
        void transfer(std::string username, std::string money);
        void parserMoney(std::string money);
    
    private:

        std::string username;
        std::string password;
        std::string balance;
        int cash;
        int cents;
        int auxCash;
        int auxCents;

        void saveFile();

};

Usuario::Usuario(std::string username){

    this->username = username;

    std::fstream file;

    std::string userPath = "./accounts/" + username + ".txt"; 

    file.open(userPath, std::ios::in);

    if(file.is_open()){

        std::string line;

        int i = 1;

        while(getline(file, line)){

            switch(i){
                case 1:

                    this->password = line;

                    break;

                case 2:

                    parserMoney(line);

                    this->cash = this->auxCash;
                    this->cents = this->auxCents;

                    this->balance = std::to_string(this->cash) + '.' + std::to_string(this->cents);

                    break;
            }

            i++;

        }

    }

}

void Usuario::parserMoney(std::string money){

    int j = 0;
    std::string aux = "";

    for(; money[j] != '.' && money[j] != ','; j++){

        aux += money[j];

    }

    this->auxCash = stoi(aux);

    aux = "";

    j++;

    for(; j < money.size(); j++){

        aux += money[j];

    }

    this->auxCents = stoi(aux);

}

void Usuario::setUsername(std::string username){

    this->username = username;

}

void Usuario::setPassword(std::string password){

    this->password = password;

}

void Usuario::setBalance(std::string money, char operation){
    // TODO_soma e sub

    parserMoney(money);

    if(operation == '+'){

        int sobra = (this->cents + this->auxCents) / 100;

        this->cash += this->auxCash + sobra;

        this->cents = (this->cents + this->auxCents) % 100;

    }

    if(operation == '-'){

        this->cash -= this->auxCash;

        this->cents -= this->auxCents;

        if(this->cents < 0){

            this->cash--;
            this->cents += 100;

        }

    }

    std::string centsFormat = std::to_string(this->cents);

    int size = centsFormat.size();

    centsFormat = std::string(std::min(2, size), '0').append(centsFormat);

    this->balance = std::to_string(this->cash) + '.' + centsFormat;

    saveFile();

}

std::string Usuario::getUsername(){

    return this->username;

}

std::string Usuario::getPassword(){

    return this->password;

}

std::string Usuario::getBalance(){

    return this->balance;

}

void Usuario::transfer(std::string username, std::string money){
    
    Usuario *user = new Usuario(username);

    user->setBalance(money, '+');

    delete user;

    setBalance(money, '-');

}

void Usuario::saveFile(){

    std::fstream file;

    std::string userPath = "./accounts/" + username + ".txt"; 

    file.open(userPath, std::ios::out);

    if(file.is_open()){

        file << this->password + '\n';
        file << this->balance + '\n';

    }

    file.close();

}

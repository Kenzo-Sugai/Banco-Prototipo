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
        std::string real = "00";
        std::string centavos = "00";

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

                    this->balance = this->real + '.' + this->centavos;

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

    this->real = std::to_string(stoi(this->real) + stoi(aux));

    aux = "";

    j++;

    for(; j < money.size(); j++){

        aux += money[j];

    }

    this->centavos = std::to_string(stoi(this->centavos) + stoi(aux));

}

void Usuario::setUsername(std::string username){

    this->username = username;

}

void Usuario::setPassword(std::string password){

    this->password = password;

}

void Usuario::setBalance(std::string money, char operation){
    // TODO_soma e sub
    if(operation == '+'){

        parserMoney(money);

        int sobra = stoi(this->centavos) / 100;

        this->real = std::to_string(stoi(this->real) + sobra);

        this->centavos = std::to_string(stoi(this->centavos) % 100);

        if(this->centavos.size() == 1) this->centavos = '0' + this->centavos; 

    }

    if(operation == '-'){

        int sobra = stoi(this->centavos) - stoi(this->real);
        if(sobra < 0){

            this->real = std::to_string(stoi(this->real) - 1);
            this->centavos = std::to_string(100 - sobra);

        }
        else{

            this->centavos = std::to_string(sobra);
            this->real = std::to_string();

        }

    }

    this->balance = this->real + '.' + this->centavos;

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

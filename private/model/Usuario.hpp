#include <iostream>
#include <fstream>
#include <string>

class Usuario {

    public:

        Usuario(std::string username){

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

                            this->real = "";
                            this->centavos = "";

                            int j = 0;

                            for(; line[j] != '.'; j++){

                                this->real += line[j];

                            }

                            j++;

                            for(; j < line.size(); j++){

                                this->centavos += line[j];

                            }

                            break;
                    }

                    i++;

                }

            }

            std::cout << "REAL: " << this->real << std::endl;
            std::cout << "CENTS: " << this->centavos << std::endl;

        }

        void setUsername(std::string username){

            this->username = username;

        }

        void setPassword(std::string password){

            this->password = password;

        }

        void setBalance(std::string money){

            std::string r = "", c = "";

            int j = 0;

            for(; money[j] != '.' && money[j] != ','; j++){

                r += money[j];

            }

            j++;

            for(; j < money.size(); j++){

                c += money[j];

            }

            int sobra = (stoi(c) + stoi(this->centavos)) / 100;

            this->real = std::to_string(stoi(this->real) + sobra + stoi(r));

            this->centavos = std::to_string((stoi(c) + stoi(this->centavos)) % 100);

            if(this->centavos.size() == 1) this->centavos = '0' + this->centavos; 

            this->balance = this->real;
            this->balance += '.';
            this->balance += this->centavos;

            std::cout << this->balance << std::endl;

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
    
    private:

        std::string username;
        std::string password;
        std::string balance;
        std::string real;
        std::string centavos;

};
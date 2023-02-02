#include <iostream>
#include <fstream>
#include "./Usuario.hpp"

class SignUp {

    public:

        SignUp(std::string username, std::string password){

            Usuario user = new Usuario(username, password);

            std::fstream file;

            file.open("./accounts/users.txt", std::ios::app);

            if(file.is_open()){

                file << user.getUsername() + '\n';
                file << user.getPassword() + '\n';

                users[username] = password;

            }

             file.close();

        }

};
#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>

std::unordered_map<std::string, std::string> users;

bool save_user(std::string username, std::string password){

    std::fstream file;

    file.open("./accounts/users.txt", std::ios::app);

    if(file.is_open()){

        file << username + '\n';
        file << password + '\n';

        users[username] = password;

    }

    file.close();

    return true;

}

void setHash(){

    std::fstream file;

    file.open("./accounts/users.txt", std::ios::in);

    if(file.is_open()){

        std::string line, username, password;
        int i = 0;

        while(getline(file, line)){

            if(i % 2 == 0){

                username = line;

            }
            else{

                password = line;

                users[username] = password;

            }

            i++;

        }

    }

    file.close();

}

bool check_valid_user(std::string username){

    return users[username].size() != 0 ? false : true;

}

bool check_login(std::string username, std::string password){

    std::cout << users[username] << " " << password << std::endl;

    return users[username] == password ? true : false;

}
#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>

bool save_user(std::string username, std::string password){

    std::fstream file;

    std::string userPath = "./accounts/" + username + ".txt"; 

    file.open(userPath, std::ios::app);

    if(file.is_open()){

        file << password + '\n';
        file << "0.0\n";

    }

    file.close();

    return true;

}

bool check_valid_user(std::string username){

    std::fstream file;

    std::string userPath = "./accounts/" + username + ".txt"; 

    file.open(userPath, std::ios::in);

    if(file.is_open()) return false;
    
    return true;

}

bool check_login(std::string username, std::string password){

    std::fstream file;

    std::string userPath =  "./accounts/" + username + ".txt";
    std::string line;

    file.open(userPath, std::ios::in);

    if(file.is_open()){

        while(getline(file, line)){

            if(password == line) return true;

            return false;

        }

    }

    return false;
}
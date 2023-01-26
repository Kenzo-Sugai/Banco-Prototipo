#include <iostream>
#include <algorithm>
#include "./functions/account_verification.hpp"

void sign_up() {

    std::string username, password;

    std::cout << "Username: " << std::endl;
    while(std::cin >> username){

        if(check_valid_user(username)) break;

        std::cout << "This username is already being used!" << std::endl;

    }

    std::cout << "Password: " << std::endl;

    std::cin >> password;

    save_user(username, password);

}

void sign_in() {

    std::string username, password;

    std::cout << "Username: " << std::endl;
    std::cin >> username;
    
    std::cout << "Password: " << std::endl;
    
    while(std::cin >> password){

        if(check_login(username, password)) break;

        std::cout << "Incorrect Password!" << std::endl;

    }

}

void start(){

    int n;

    std::cout << "=----- Banco -----=" << std::endl;
    std::cout << "Escolha uma opcao abaixo: " << std::endl;
    std::cout << "1 - Criar uma conta" << std::endl;
    std::cout << "2 - Entrar em uma conta" << std::endl;

    std::cin >> n;

    switch(n){

        case 1:
            sign_up(); 
            start();
            break;
        case 2:
            sign_in(); break;
        default :
            std::cout << "Escolha uma opcao valida!" << std::endl;
            start();
            break;

    }

}


int main(){

    while(1){

        setHash();
        start();

    }


}
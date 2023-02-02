#include <iostream>
#include <algorithm>
#include "./functions/account_verification.hpp"
#include "./private/model/Usuario.hpp"

void sign_up() {

    std::string username, password;

    std::cout << "Username: " << std::endl;
    while(std::cin >> username){

        if(check_valid_user(username)) break;

        std::cout << "This username is already being used!" << std::endl;
        std::cout << "Try again: " << std::endl;

    }

    std::cout << "Password: " << std::endl;

    std::cin >> password;

    save_user(username, password);

}

std::string sign_in() {

    std::string username, password;

    std::cout << "Username: " << std::endl;
    while(std::cin >> username){

        if(!check_valid_user(username)) break;

        std::cout << "This username not exist" << std::endl;
        std::cout << "Try again: " << std::endl;

    }
    
    std::cout << "Password: " << std::endl;
    
    while(std::cin >> password){

        if(check_login(username, password)) break;

        std::cout << "Incorrect Password!" << std::endl;
        std::cout << "Try again: " << std::endl;

    }

    return username;

}

void menu(std::string username){

    Usuario *user = new Usuario(username);

    while(true){

        std::cout << "Bem vindo " << user->getUsername() << std::endl;
        std::cout << "Saldo: " << user->getBalance() << std::endl;
        std::cout << "Escolha uma opcao abaixo: " << std::endl;
        std::cout << "1 - Depositar" << std::endl;
        std::cout << "2 - Extrair" << std::endl;
        std::cout << "3 - Historico" << std::endl;

        int n;

        std::cin >> n;

        switch(n){

            case 1:

                std::string money;

                std::cout << "Quanto deseja depositar: " << std::endl;
                std::cin >> money;

                user->setBalance(money);

                break;

        }


    }


}

void start(){

    int n;

    std::cout << "=----- Banco -----=" << std::endl;
    std::cout << "Escolha uma opcao abaixo: " << std::endl;
    std::cout << "1 - Criar uma conta" << std::endl;
    std::cout << "2 - Entrar em uma conta" << std::endl;

    std::cin >> n;

    std::string username;

    switch(n){

        case 1:
            sign_up(); 
            start();
            break;
        case 2:
            username = sign_in();
            menu(username);
            break;
        default:
            std::cout << "Escolha uma opcao valida!" << std::endl;
            start();
            break;

    }

}


int main(){

    while(true){

        start();

    }


}
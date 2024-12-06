#include <iostream>
#include "CaesarCipher.hpp"
#include <limits>

std::string CiphersMenu = "CHOOSE A CIPHER YOU WANT TO USE \n"
"(1. CaesarCipher)";



int main(){
    int option {};
    
   
    std::cout<<CiphersMenu<<std::endl;
    while(1){
        std::cout<<"Choose your cipher, press '0' to end"<<std::endl;
        std::cin>>option;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::string file;
        std::string data;
        if (option == 0){
            std::cout<<"Exiting the program"<<std::endl;
        }
        switch(option){
            case 1:
                std::cout<<"You choose Caesar Cipher"<<std::endl;
                std::cout<<"Choose a filename to save your data"<<std::endl;
                std::getline(std::cin, file);
                CaesarCipher x(4,file);
                std::cout<<"Enter your data"<<std::endl;
                std::getline(std::cin, data);
                x.encryptData(data);
                break;
        }
        
    }
    
}
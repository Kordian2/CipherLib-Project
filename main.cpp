#include <iostream>
#include "CaesarCipher.hpp"


std::string CiphersMenu = "CHOOSE A CIPHER YOU WANT TO USE \n"
"(1. CaesarCipher)";



int main(){
    int option {};
    std::cout<<CiphersMenu<<std::endl;
    while(1){
        std::cout<<"Choose your cipher, press '0' to end"<<std::endl;
        std::cin>>option;
        switch(option){
            case 1:
                std::cout<<"You choose Caesar Cipher"<<std::endl;
                std::cout<<"Choose a filename to save your data"<<std::endl;
        }
    }
    
}
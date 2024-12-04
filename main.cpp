#include <iostream>
#include "CaesarCipher.hpp"

int main(){
    CaesarCipher test(2,"haslo");
    test.encryption();
    test.decryptData();
}
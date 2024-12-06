
#include "Cipher.hpp"
class CaesarCipher: public Cipher{
private:
    int m_shift;
    
public:
    CaesarCipher(int shift = 2,std::string file = "encrypted_data.txt"):m_shift(shift){
        
        setFileName(file);
    };
    
    void encryptData(const std::string& data) override  {
        std::string encryptedData;

        for (char c : data) {
            if (std::isalpha(c)) {
                char base = std::islower(c) ? 'a' : 'A';
                encryptedData += (c - base + m_shift) % 26 + base;
            } else {
                encryptedData += c;  
            }
        }

        writeToFile(encryptedData);
    }


    void decryptData(const std::string& data) override {
        std::string decryptedData;

        for (char c : data) {
            if (std::isalpha(c)) {
                char base = std::islower(c) ? 'a' : 'A';
                decryptedData += (c - base - m_shift + 26) % 26 + base;
            } else {
                decryptedData += c;
            }
        }

        readFromFile();
    }
        
    
   /*
    void encryption(void) {
        std::string password;
        std::string data;
        std::cout<<"Enter your password, if you not set it just press enter"<<std::endl;
        std::getline(std::cin, password);
        if(getPassword() == password){
            std::cout<<"Enter your data to encrypt"<<std::endl;
            std::getline(std::cin, data);
            std::string encryptedData = encryptData(data);
            writeToFile(encryptedData);
        }else{
            std::cout<<"Your password is incorrect"<<std::endl;
        }

    }
    std::string decryption(void){
        std::string password;
        std::string data;
        std::cout<<"Enter your password to decrypt your data, if you not set it just press enter"<<std::endl;
        
        std::cout<<"Your decrypted data: "<<std::endl;
    }
    */
};
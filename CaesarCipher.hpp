
#include "Cipher.hpp"
class CaesarCipher: public Cipher{
private:
    int m_shift;
    std::string m_password;
    std::string m_file;
public:
    CaesarCipher(int shift = 2, std::string password = "", std::string file = "encrypted_data.txt"):m_shift(shift), m_password(password),m_file(file){};
    
    std::string encryptData(const std::string& data) const {
        std::string encryptedData;

        for (char c : data) {
            if (std::isalpha(c)) {
                char base = std::islower(c) ? 'a' : 'A';
                encryptedData += (c - base + m_shift) % 26 + base;
            } else {
                encryptedData += c;  
            }
        }

        return encryptedData;
    }


    std::string decryptData(const std::string& data) const {
        std::string decryptedData;

        for (char c : data) {
            if (std::isalpha(c)) {
                char base = std::islower(c) ? 'a' : 'A';
                decryptedData += (c - base - m_shift + 26) % 26 + base;
            } else {
                decryptedData += c;
            }
        }

        return decryptedData;
    }
        
    
    
    void encryption(void) const{
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
    
};
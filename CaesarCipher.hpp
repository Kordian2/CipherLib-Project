#include <iostream>
#include <string>
#include <fstream>

class CaesarCipher{
private:
    std::string m_password;
    int m_shift;
public:
    CaesarCipher(int shift = 2, std::string password = ""):m_shift(shift), m_password(password){};
    void setPassword(const std::string& password){
        m_password = password;
    }
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
    std::string decryptData(){
        std::string decryptedData;
        std::ifstream file("encrypted_data.txt");
    }
    void saveToFile(const std::string& data, const std::string& filename = "encrypted_data.txt") const {
        std::ofstream outFile(filename, std::ios::app);  
        if (outFile) {
            outFile << data << std::endl;
            std::cout << "The data was saved to a file: " << filename << std::endl;
        } else {
            std::cerr << "Error while saving to file!" << std::endl;
        }
    }
    void encryption(void) const{
        std::string password;
        std::string data;
        std::cout<<"Enter your password, if you not set it just press enter"<<std::endl;
        std::getline(std::cin, password);
        if(m_password == password){
            std::cout<<"Enter your data to encrypt"<<std::endl;
            std::getline(std::cin, data);
            std::string encryptedData = encryptData(data);
            saveToFile(encryptedData);
        }

    }
    
};
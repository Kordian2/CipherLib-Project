
#include "Cipher.hpp"
class CaesarCipher: public Cipher{
private:
    int m_shift;
    
public:
    CaesarCipher(int shift = 2,std::string file = "encrypted_data.txt"){
        setFileName(file);
        setShift(shift);
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
    void setShift(int shift){
        m_shift = shift;
    }   
    
   
};
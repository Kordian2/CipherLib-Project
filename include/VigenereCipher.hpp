#include "Cipher.hpp"
namespace kb{
class VigenereCipher: public Cipher{
private:
    std::string m_key;
public:
    VigenereCipher(std::string key = "key",std::string file = "Vigenere_data.txt"){
        setFileName(file);
        setKey(key);
    };

    std::string encryptData(const std::string& data) override {
        std::string encryptedData;
        std::string upperKey = m_key; 

    
        for (char& c : upperKey) {
            c = std::toupper(c);
        }

        size_t keyIndex = 0;
        size_t keyLength = upperKey.length();

        for (char c : data) {
            if (std::isalpha(c)) {
                char base = std::islower(c) ? 'a' : 'A';
                int shift = upperKey[keyIndex] - 'A'; 
                encryptedData += (c - base + shift) % 26 + base;
                keyIndex = (keyIndex + 1) % keyLength; 
            } else {
                encryptedData += c; 
            }
        }

        return encryptedData;
    }
    void setKey(std::string key){
        m_key = key;
    }
};
}
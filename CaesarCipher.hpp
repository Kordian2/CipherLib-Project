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
                encryptedData += c;  // Inne znaki pozostają bez zmian
            }
        }

        return encryptedData;
    }
    void saveToFile(const std::string& data, const std::string& filename = "encrypted_data.txt") const {
        std::ofstream outFile(filename, std::ios::app);  // Otwieramy plik do dopisywania
        if (outFile) {
            outFile << data << std::endl;
            std::cout << "Dane zapisano do pliku: " << filename << std::endl;
        } else {
            std::cerr << "Błąd podczas zapisywania do pliku!" << std::endl;
        }
    }
    
};
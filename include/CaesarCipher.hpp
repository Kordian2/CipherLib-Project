#include "Cipher.hpp"

namespace kb{
class CaesarCipher: public Cipher{
private:
    int m_shift;
    
public:
    CaesarCipher(int shift = 2,std::string file = "Caesar_data.txt"){
        setFileName(file);
        setShift(shift);
    };
    
    std::string encryptData(const std::string& data) override  {
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


    
    void setShift(int shift) {
    if (shift > 0) {
        m_shift = shift;
    } else {
        std::cout<< "Shift value must be greater than zero. Keeping the previous value ("<< m_shift << ")." << std::endl;
    }
}
    
   
};
}
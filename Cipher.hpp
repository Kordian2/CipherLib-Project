#include <iostream>
#include <string>
#include <fstream>


class Cipher{
private:
    std::string m_password;
    std::string m_file;
public:
    void setPassword(std::string password){
        m_password = password;
    }
    
    
    std::string getPassword(void) const{
        return m_password;
    }
    virtual std::string encryptData() = 0;
    
    
    virtual std::string decryptData() = 0;
    
    
    std::string getFileName(void) const{
        return m_file;
    }
    
    
    void setFileName(std::string name) {
        m_file = name;
    }


    void writeToFile(const std::string& data) const {
        std::ofstream outFile(getFileName(), std::ios::app);  
        if (outFile) {
            outFile << data << std::endl;
            std::cout << "The data was saved to a file: " << getFileName() << std::endl;
        } else {
            std::cerr << "Error while saving to file!" << std::endl;
        }
    }
    
    
    std::string readFromFile(void) const {
         std::ifstream file(getFileName());
    if (!file) {
        std::cerr << "Can't open the file" << std::endl;
        
    }

    std::string decryptData;
        while (std::getline(file, decryptData)) {
            std::cout << decryptData << std::endl; 
        }

        file.close();
        return 0;
    }
    

};


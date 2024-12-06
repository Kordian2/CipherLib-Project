#include <iostream>
#include <string>
#include <fstream>


class Cipher{
protected:
    
    std::string m_file;
public:
   
    virtual void encryptData(const std::string& data) = 0;
    
    
    virtual void decryptData(const std::string& data) = 0;
    
    
    std::string getFileName(void) const{
        return m_file;
    }
    
    
    void setFileName(std::string name) {
        if(name != ""){
           m_file = name; 
        }else{
            m_file = "encrypted_data.txt";
        }
        
    }


    void writeToFile(const std::string& data)  {
        
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
        return decryptData;
    }
    

};


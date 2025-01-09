#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

#pragma once

class Cipher{
protected:
    
    std::string m_file;
public:
   
    virtual void encryptData(const std::string& data) = 0;
    
    
    
    
    
    std::string getFileName(void) const{
        return m_file;
    }
    
    
    void setFileName(std::string name) {
        
        if(name != "" && !std::filesystem::exists(name)){                     
           m_file = name; 
        }else{
            std::cout<<"File like this is already exist please enter diffrent filename"<<std::endl;
            std::getline(std::cin, m_file);
        }
        
    }


    void writeToFile(const std::string& data)  {
        
        std::ofstream outFile(getFileName()+".txt", std::ios::app);  
        if (outFile) {
            outFile << data << std::endl;
            std::cout << "The data was saved to a file: " << getFileName() << std::endl;
        } else {
            std::cerr << "Error while saving to file!" << std::endl;
        }
        
    }
    
    
   
    std::string getDataFromUser(void){
        std::string line;
        std::string data;
        while(1){
            std::getline(std::cin, line);
            if(line.empty()){
                break;
            }else{
                data += line + "\n";
            }
        }
        return data;
    }

};
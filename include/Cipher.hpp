#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <regex>
#pragma once
namespace kb{
class Cipher{
protected:
    
    std::string m_file;
public:
   
    virtual std::string encryptData(const std::string& data) = 0;
    
    
    
    
    
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


    void writeToFile(const std::string& data, const std::string& path = "") {
    std::string fileName = path.empty() ? getFileName() + ".txt" : path + "/" + getFileName() + ".txt";

    std::ofstream outFile(fileName, std::ios::app);
    if (outFile) {
        outFile << data << std::endl;
        std::cout << "The data was saved to a file: " << fileName << std::endl;
    } else {
        std::cerr << "Error while saving to file!" << std::endl;
    }
}
    
    
   
std::string getDataFromUser(void) {
    std::string line;
    std::string data;
    std::regex validStringRegex("^[a-zA-Z ]+$"); 
    while (true) {
        std::getline(std::cin, line);
        if (line.empty()) { 
            break;
        } 
        if (std::regex_match(line, validStringRegex)) {
            data += line + "\n";
        } else {
            std::cout<< "You can only write letters and spaces. Please try again"<<std::endl;
        }
    }
    
    return data;
}

};
}
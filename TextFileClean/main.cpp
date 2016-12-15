//
//  main.cpp
//  TextFileClean
//
//  Created by dieter on 12/12/2016.
//  Copyright © 2016 dieter. All rights reserved.
//

#include <iostream>
#include <cassert>
#include <fstream>


int main(int argc, const char * argv[]) {
    
    
    
    std::cout << "Enter file path \n" ;
    std::string filePath;
    std::cin >> filePath;
    
    std::ifstream reader(filePath);
    
    assert(reader.is_open());
    std::string text = "";
    std::string line ;
        while(!reader.eof()){
        
        std::getline(reader,line);
        std::string newLine="";

        for (std::string::iterator c=line.begin(); c!=line.end();c++){
            
        
            if(isalpha(*c)){
                
                std::string letter(1,tolower(*c));
                newLine.append(letter);
                
            }
            
            if (*newLine.end()!=' ' && *c == ' ' ){
                
                newLine.append(" ");
            }
        
            
        }
               if (line.length()!=0) {
                text.append(newLine);
                text.append(" ");
               }
            
        }
    
    reader.close();
    
    std::ofstream writer(filePath);
    assert(writer.is_open());
    writer << text;
    writer.close();
    
    return 0;

}


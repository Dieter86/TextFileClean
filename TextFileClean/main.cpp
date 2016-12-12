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

// There is something wrong. If two subsequent char are non alpha then only the first is deleted
// Problem probably lies is the fact the iterator skips a step because seq got shorter after deleting.

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
        for (std::string::iterator c=line.begin(); c<=line.end();c++){
            
            
            if(isalpha(*c) || *c==' '){
                
                *c=tolower(*c);
                
            }
            else {
                
                line.erase(c);
            }
            
        }
        
        
        text.append(line);
        text.append(" ");
        
        
    }
    
    reader.close();
    
    std::ofstream writer(filePath);
    assert(writer.is_open());
    writer << text;
    
    
    writer.close();

    return 0;
}

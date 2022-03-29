#include <stdlib.h>
#include <iostream>
#include <string>
#include "Direction.hpp"
#include "Notebook.hpp"



using namespace std;
using namespace ariel;
    
    const int one = 32;
    const int two = 126;
    const int maxrow =100;

    unordered_map<int, Page> Notebook::getPages(){
        return _pages;
    }

    void Notebook::write(int page, int line, int col, Direction dir, string const &std){
        if (col < 0 || col >= maxrow ||page < 0 || line <0){
            throw invalid_argument("Invalid numbers");
        }
        if (std == "\n"){
            throw invalid_argument("Invalid string");
        }
        for (unsigned long i = 0; i < std.length(); i++){
		    if (((std.at(i) < one || std.at(i) > two) && std.at(i) != ' ' )|| std.at(i) == '~'){
			     throw invalid_argument("Invalid string");
            }
        }
  
        if (dir == Direction::Horizontal){
            if (std.length() >=maxrow){
                throw invalid_argument("Invalid string");
            }
            if( ((unsigned long)col + std.length()) >= maxrow){
                throw invalid_argument("Invalid string");
            }
            
        }
       
        _pages[page].write(line, col, dir, std);
        
        if(line > Notebook::maxRow){
            maxRow = line;
        }
    }

    string Notebook::read(int page, int line, int col, Direction dir, int numToRead){
        string ans;

        if (col < 0 || col >= maxrow ||page <0 || line <0 || numToRead <0 ){
            throw invalid_argument("Invalid string");
        }

        if(dir == Direction::Horizontal){
          
        
             if ( (col + numToRead) >maxrow ){
            throw invalid_argument("Invalid string");
            }
        }
       
        ans = _pages[page].see(line, col, dir, numToRead);
        return ans; 
    }

    void Notebook::erase(int page, int line, int col, Direction dir, int len){

        if (col < 0 || col >= maxrow ||page <0 || line < 0 || len <0){
            throw invalid_argument("Invalid string");
        }
        if(dir == Direction::Horizontal){
             if ( (col + len) >maxrow ){
            throw invalid_argument("Invalid string");
            }
        }
        _pages[page].del(line, col, dir, len);
    }

    void Notebook::show( int page){
           if (page < 0){
            throw invalid_argument("Invalid page");
        }

        _pages[page].printPage(maxRow);
    }

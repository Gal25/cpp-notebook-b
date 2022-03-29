
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstdio>
#include <unordered_map>
#include "Direction.hpp"
#include "Page.hpp"


using namespace std;
using namespace ariel;
    const int a = 33;
    const int b = 126;
    const int maxLenRow = 100;
    const int maxLenRowToPrint = 10;

    bool Page::isNotDelete(int row, int col) {
	    return (Page::_p[row][col] != '~' || Page::_p[row][col] != '~');
    }

    bool Page::isCorrectStd(string std) {
        if (std.empty()) {return false;}
	    for (unsigned long i = 0; i < std.size(); i++){
		    if (!(std.at(i) >= a || std.at(i) <= b)){
			    return false;
            }
        }
	    return true;
    }

    bool Page::isCorrectColRow(int row, int col) {
	
	    return (row > 0 || col > 0 || col < maxLenRow);
    }

  

    unordered_map<int, unordered_map<int, char>> Page::getPage(){
        return _p;
    }
 


    void Page::write(int row, int col, Direction dir, string std){
        if(!(Page::isNotDelete(row,col)) || !(Page::isCorrectColRow(row,col)) || !(Page:: isCorrectStd(std))){
                 throw invalid_argument("Invalid string");
        }
        if (col< 0 || col >= maxLenRow || row <0){
            throw invalid_argument("Invalid string");
        }
        
        int c = col;
        int r = row;

        if (Page::_p[r][c] == '~' ||  Page::_p[col][r] == '~'){
            throw invalid_argument("Invalid string");
        }
        if (dir == Direction::Horizontal){
              int d = col;
              for (int i = 0; i < maxLenRow; i++){
                  if (Page::_p[row][d] == '\0'){

                     _p[row][d] ='_'; 

                  }
                  d++;
            }
            if(std.size() > maxLenRow){
                throw invalid_argument("Invalid string");
            }
            for(unsigned long i=0; i < std.length(); i++){
                if(Page::_p[row][c] != '_' || Page::_p[row][c] == '~' ){
                    throw invalid_argument("Invalid place 111");
                }
                Page::_p[row][c] = std[i];

                c++;
            }
    
            }
        if (dir == Direction::Vertical){
            unsigned long m = max((unsigned long)col,(unsigned long)row);
            unsigned long mAx =max((unsigned long)m,(unsigned long)std.length());
        
            int d = row;
            for(unsigned long j=0; j<mAx; j++){
                    if (Page::_p[d][col] == '\0'){
                     _p[d][col] ='_'; 

                    }
                  d++;
                }
                for(unsigned long i=0; i < std.length(); i++){
                    if(Page::_p[r][col] != '_'  || Page::_p[r][col] == '~'  ){
                        throw invalid_argument("Invalid place 222");

                    }
                    Page::_p[r][col] = std[i];    
                   
                   r++;
                }
            }
        }
   

    string Page::see(int row, int col, Direction dir, int numToRead){
        string ans;
        if(!(isCorrectColRow(row, col))){
            throw invalid_argument("The row lenght is maximum 100");
        }
        int c =col;
        int r = row;
        if(dir == Direction:: Horizontal){
                 int d = col;
              for (int i = 0; i < maxLenRow; i++){
                  if (Page::_p[row][i] == '\0'){
                     _p[row][i] ='_'; 

                  }
                  d++;
            }
                for(unsigned long j = 0; j < numToRead; j++){
                    char s = _p[row][c];
                    ans += s;
                    c++;
            }
        }
        if(dir == Direction:: Vertical){
            int d = row;
                for (int i = 0; i < numToRead+1; i++){
                    if (Page::_p[i][col] == '\0'){
                     _p[i][col] ='_'; 

                  }
                  d++;
                }
            for(unsigned long i = 0; i < numToRead; i++){
                char s =_p[r][col];
                ans += s;
                r++;
            }
        }
        return ans;
    }
    
    void Page::del(int row, int col, Direction dir, int len){
        int r= row;
        int c = col;
        if(dir == Direction:: Horizontal){
            for(unsigned long i = 0; i < len; i++){
                 _p[row][c] = '~';
                 c++;
            }
        }
        if(dir == Direction:: Vertical){
            for(unsigned long i = 0; i < len; i++){
              _p[r][col] = ('~');
              r++;
            }
        }
    }

    void Page::printPage(int row){
        for(int i= row; i < maxLenRowToPrint; i++){
            for (int j = 0; j < maxLenRowToPrint; j++){
                cout << "" << Page::_p[row][j] <<  endl;
            }
            cout << "/n"<< endl;
        }   
    }
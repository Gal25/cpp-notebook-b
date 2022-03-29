#pragma once

#include <stdlib.h>
#include <iostream>
#include <string>
#include "Direction.hpp"
#include "Page.hpp"
#include <unordered_map>



using namespace std;
namespace ariel{
    class Notebook{
        private:
            unordered_map<int,Page> _pages; // the unordered map of the pages - this is the notebook
            int maxRow;

        public:

            unordered_map<int, Page> getPages();
             
            void write(int page, int line, int col, Direction dir, string const &std); //write on the specific place
            string read( int page, int line, int col, Direction dir, int numToRead); //read on the specific place
            void erase( int page, int line, int col, Direction dir, int len); // delete on the specific place
            void show( int page); // show the page 
    };

}
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
            unordered_map<int,Page> _pages;
            int maxRow;
            Page p; 

        public:
            // void setPages(unordered_map<int,Page> pages);

            unordered_map<int, Page> getPages();
             
            // Notebook();

            void write(int page, int line, int col, Direction dir, string const &std);
            string read( int page, int line, int col, Direction dir, int numToRead);
            void erase( int page, int line, int col, Direction dir, int len);
            void show( int page);
    };

}
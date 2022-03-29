#pragma once

#include <stdlib.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include "Direction.hpp"


using namespace std;
using namespace ariel;

    class Page{
        private:
             unordered_map<int, unordered_map<int, char>> _p;

        public:

            // bool isCorrectCol(int col);         
            bool static isCorrectStd(string std);
            bool isNotDelete(int row, int col);
            bool static isCorrectColRow(int row, int col);


	        // void  setPage(unordered_map<int, unordered_map<int, char>> p);

            unordered_map<int, unordered_map<int, char>>  getPage();

            // Page();

            void write(int row, int col, Direction dir, string std);
            string see(int row, int col, Direction dir, int numToRead);
            void  del(int row, int col, Direction dir, int len);

            void  printPage(int row);

    };


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

            bool static isCorrectStd(string std); //check is the string is with normal chars
            bool isNotDelete(int row, int col); // check if in the specific place we do not delete
            bool static isCorrectColRow(int row, int col); // check if num of the row and col is coreect



            unordered_map<int, unordered_map<int, char>>  getPage();

            void write(int row, int col, Direction dir, string std); //write on the specific place in the page
            string see(int row, int col, Direction dir, int numToRead); //read on the specific place in the page
            void  del(int row, int col, Direction dir, int len); // delete on the specific place in the page

            string  printPage(int row); // print all the page


    };

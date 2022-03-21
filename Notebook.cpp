#include "Notebook.hpp"
#include "row.hpp"
#include "page.hpp"
#include <string>
#include <vector>
using namespace ariel;
using namespace std;
namespace ariel{
    void Notebook::addPage(){
        this->pageCounter++;
        this->pages.push_back(new Page());
    }

    void Notebook::write(int page, int row, int col, ariel::Direction dir, string str){
        if(!isPageExist(page-1)){
            std::__throw_invalid_argument("The page number you entered does not exist.");
        }
        this->pages.at(page-1)->writeToRow(row, col, str, dir);
    }

};
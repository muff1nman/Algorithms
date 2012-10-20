#include "Flowdown.h"


Flowdown::Flowdown(std::string palindrome): initdrome(palindrome)  {
    this->populateTable();
}

std::string Flowdown::getMaximum(){
	return actPalindrome;
}

void Flowdown::calcMaximum(){
	int index;
        int max = 0;
	for ( int i = 0; i < table.size(); ++i ) {
		if ( table[i][table.size() - 1] > max ) {
			max = table[i][table.size() - 1];
			index = i;
		}		
	}

	actPalindrome = initdrome.substr(index,max);
}

void Flowdown::reserveTable(){

    table.resize( initdrome.length());

    for(unsigned int i=0; i < initdrome.length(); ++i){
        table[i].resize(initdrome.length(), 1);
    }

}

void Flowdown::populateTable(){

    this->reserveTable();

    for(unsigned int i = 0; i < table.size(); ++i) {
        for(unsigned int j = i+1; j < table.size(); ++j) {
            std::string temp = initdrome.substr(i,j-i+1);

            if(isPalindrome( temp.c_str(), temp.length() )) {
                this->table[i][j] = temp.length();
            } else {
                this->table[i][j] = table[i][j-1];
            }
        }
    }    
}

void Flowdown::printTable(){
	std::cout << "  ";
	for( unsigned int i = 0; i < table.size(); ++i) {
		std::cout  << initdrome[i] << " ";
	}
std::cout << std::endl;

	
     for(unsigned int i=0; i < table.size(); ++i) {
		std::cout << initdrome[i] << " ";
        for(unsigned int j=0; j < table[i].size(); ++j) {
            std::cout << table[j][i] << " ";
        }
        std::cout << std::endl;
    }
}

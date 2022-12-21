#include<iostream>
#include<sstream>	
#include<fstream>	
#include<string>
#include<stdlib.h> 
//#include "header.h"

using namespace std;

int main(int argc, char* argv[]){

    ifstream file;
    string line;
    file.open("tubelist651.txt");
    if (!file){
		cerr << "File cannot be opened!";
		exit(1);
	}

    //get number of color block in a bottle
    string getColor = "";
    int heightOfBottle = 0;
    do{
        getline(file,line, ' ');
        heightOfBottle++;
 
    }while(line.length() == 2);

    //return to the begining of txt file
    file.clear();
    file.seekg(0);

    //go end of file eof()
    //count every line
    int numberOfBottle = 0;
    while(!file.eof()){
        getline(file,line, '\n');
        numberOfBottle++;
    }
    return 0;
}
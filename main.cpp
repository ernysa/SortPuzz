#include<iostream>
#include<sstream>	
#include<fstream>	
#include<string>
#include<stdlib.h> 
#include "header.h"

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

    //return to the begining of txt file
    file.clear();
    file.seekg(0);

    
    Puzzle game;
    game.numberOfStacks = numberOfBottle;
    game.stackHeight = heightOfBottle;

    //fill every bottle
    for(int i=0 ; i<numberOfBottle ; i++){
        stack<string> bottle;

        //fill every color
        for (int j = 0; j < heightOfBottle-1 ; j++)
        {   
            getline(file,line, ' ');
            bottle.push(line);
        }
            getline(file,line, '\r');
            bottle.push(line);
            getline(file,line, '\n');

            //for empty bottle 
            if(bottle.top() == "_"){
                for (int j = 0; j < heightOfBottle ; j++){
                    bottle.pop();
                }
            }
            //add bottle to grid
            game.addBottle(bottle);       
    }
    return 0;
}
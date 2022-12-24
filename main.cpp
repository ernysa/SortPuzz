#include<iostream>
#include<sstream>	
#include<fstream>	
#include<string>
#include<stdlib.h> 
#include<map>
#include<iterator>
#include "header.h"

using namespace std;

//todo: arrange the cpp files later.
bool Puzzle::isGridValid(){
    int expectedNumberOfBalls = (this->numberOfStacks-2)*(this->stackHeight);
    int numberOfBalls = 0;

    //count the total number of balls
    for(auto i : grid){
        numberOfBalls += i.size();
    }
    if(numberOfBalls != expectedNumberOfBalls){
        cout << "Number of balls isn't what it should be!"<< endl;
        return false;
    }
    //count the number of each different colored ball
    map <string,int> balls;
    vector<stack<string>> newGrid = grid;
    for (auto tube : newGrid){
        while(!tube.empty()){
            string key = tube.top();
            tube.pop();
            balls[key] +=1;
        }
    }
    //checking if the grid has the right amount of ball of each color
    map<string, int>::iterator it = balls.begin();
    while(it != balls.end()){
        if(it->second != stackHeight){
            cout << "There aren't " << stackHeight << " balls of color " << it->first<<endl;
            return false;
        }
        it++;
    }
    return true;
}

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
            getline(file,line, '\n');
            bottle.push(line);
            

            //for empty bottle 
            if(bottle.top() == "_"){
                for (int j = 0; j < heightOfBottle ; j++){
                    bottle.pop();
                }
            }
            //add bottle to grid
            game.addBottle(bottle);       
    }
    game.isGridValid();
    return 0;
}
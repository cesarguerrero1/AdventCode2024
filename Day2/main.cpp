/**
 * Cesar Guerrero
 * Advent of Code 2024 - Day 2
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
//NOTE: We could use 'using namespace std;' but it is not recommended


//Prototype Functions
int solutionOne();
bool isSafeReport(const std::vector<int>& values);
bool satisfyLevelConstraints(int a, int b);

int main(){

    int ans1 = solutionOne();
    std::cout << "The solution to part one is: " << ans1 << std::endl;

    return 0;
}

/**
 * This is the solution to part one
 */
int solutionOne(){
    //Open the file
    std::fstream file("input.txt");
    if(file.fail()){
        std::cerr << "Error opening file\n";
        return -1;
    }

    //Read the file
    int safeReports = 0;
    std::string line;
    while(std::getline(file, line)){

        std::vector<int> values;
        //We tokenize the line
        std::stringstream ss(line);
        int num;

        while(ss >> num){
            values.push_back(num);
        }

        if(isSafeReport(values)){
            safeReports++;
        }
    }

    return safeReports;
}

//Helper function to loop over each vector
bool isSafeReport(const std::vector<int>& values){
    //We know it must be strictly increasing or decreasing so we can immediately guard the first two values
    if(values[0] == values[1]){
        return false;
    }
    bool setDirection = values[0] < values[1];

    for(int i = 0; i < values.size()-1; i++){
        int val1 = values[i];
        int val2 = values[i+1];
        if(val1 == val2){
            //This is not a safe report
            return false;
        }
        bool currentDirection = val1 < val2;
        if(setDirection != currentDirection){
            //This is not a safe report
            return false;
        }
        
        if(!satisfyLevelConstraints(val1, val2)){
            //This is not a safe report
            return false;
        }
    }
    return true;
}

//Helper function to check if the level constraints are satisfied
bool satisfyLevelConstraints(int a, int b){
    int diff = abs(a - b);
    if(diff == 0 || diff > 3){
        return false;
    }
    return true;
}
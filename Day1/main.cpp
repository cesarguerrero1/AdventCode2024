/**
 * Cesar Guerrero
 * Advent of Code 2024 - Day 1
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <queue>
//NOTE: We could use 'using namespace std;' but it is not recommended

//Prototype functions
int solutionOne();
int solutionTwo();

int main() {
    
    int ans1 = solutionOne();
    std::cout << "The solution to part one is: " << ans1 << std::endl;
    int ans2 = solutionTwo();
    std::cout << "The solution to part two is: " << ans2 << std::endl;

    return 0;
}

/**
 * The following function solves part one of the problem
 */
int solutionOne(){
    //Solution one is about finding the differences between values from smallest to largest

    //Create two minHeap variables to store the input values from smallest to largest
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap2;

    //Open the file
    std::fstream file("input.txt");
    if(file.fail()){
        std::cerr << "Error opening file\n";
        return -1;
    }

    //Read the file
    std::string line;
    while(std::getline(file, line)){
        //We tokenize the line
        std::stringstream ss(line);
        int num;
        //We know the format of the input so we can read the values directly
        ss >> num;
        minHeap.push(num);
        ss >> num;
        minHeap2.push(num);
    }

    int differenceSum = 0;
    //Now we find the differences between each smallest value in the heaps
    while(!minHeap.empty()){
        int value1 = minHeap.top();
        int value2 = minHeap2.top();

        differenceSum += abs(value1 - value2);
        //Pop the values
        minHeap.pop();
        minHeap2.pop();
    }

    return differenceSum;
}

/**
 * The following function solves part two of the problem
 * @return int The similarity score
 */
int solutionTwo(){
    //Solution Two is all about frequencies of the numbers
    std::vector<int> list1;
    std::unordered_map<int, int> freqMap;


    //Open the file
    std::fstream file("input.txt");
    if(file.fail()){
        std::cerr << "Error opening file\n";
        return -1;
    }

    //Read the file
    std::string line;
    while(std::getline(file, line)){
        //We tokenize the line
        std::stringstream ss(line);
        int num;
        //We know the format of the input so we can read the values directly
        ss >> num;
        list1.push_back(num);
        ss >> num;
        freqMap[num]++;
    }

    //Now we find the similarity score
    int similarityScore = 0;
    for(int i = 0; i < list1.size(); i++){
        int value = list1[i];
        similarityScore += (value * freqMap[value]);
    }

    return similarityScore;
}
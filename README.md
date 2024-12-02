## Summary 
This repository contains all of the code for each day of the Advent of Code 2024 challenge. I want to keep my C++ skills sharp so all solutions will be done in C++.

To speed up compilation I will be using [CMake](https://cmake.org/) 

## Details
I want to keep a journal of each day so this section will provide an explanation of my solution as well as any comments about the problem itself.
- Day 1
    - Solution 1: Given that we wanted to compare the smallest values against each other in increasing order, I opted for (2) minHeaps. The idea being that I could sort as I read the values. We could also have made (2) vectors and then sorted them afterward.
    - Solution 2: Straightforward problem based on frequencies of numbers. I opted for a hash_map approach but another approach could have been using an array, but that would have required knowing how much space to allocate for the array so that you could update frequencies at the correct index.
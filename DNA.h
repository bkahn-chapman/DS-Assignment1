/*
* Name: Benjamin Kahn
* ID: 2316793
* Class: CPSC-350-01
* Assignment: Programming Assignment 1: C++ Review
* About: DNA.h instansiates the DNA class, the functions, and the global variables.
*/

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

class DNA
{
  public:
    DNA(); //default constructor
    ~DNA(); //destructor
    void ReadFile(string input); //reads through the given file
    void WriteFile(string input); //writes results to the given file
    void Calculate(string input); //calculates summary statistics for the given file
    void WriteHeader(); //writes the header for the file
    void CountLetters(char letter, string s); //counts the letters given a character and a string
    void CountBigrams(string bigram); //counts the bigrams given a string
    void Gaussian(); //solves the gaussian
    void ResetVariables(); //resets all variables when a new file is taken in
    //variables
    int checkBigram;
    float countlines = -1;
    int numinline = 1;
    float sum;
    float mean;
    float variance;
    float stdev;
    float numBigrams;
    float numA;
    float numC;
    float numG;
    float numT;
    float numAA;
    float numAC;
    float numAG;
    float numAT;
    float numCA;
    float numCC;
    float numCG;
    float numCT;
    float numGA;
    float numGC;
    float numGG;
    float numGT;
    float numTA;
    float numTC;
    float numTG;
    float numTT;
    float probA;
    float probC;
    float probG;
    float probT;
};

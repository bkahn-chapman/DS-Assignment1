#include "DNA.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv)
{

  string inputFile = argv[1];
  DNA *dna = new DNA();
  dna -> WriteHeader();
  dna -> ReadFile(inputFile);
  dna -> Calculate(inputFile);
  dna -> WriteFile(inputFile);
  dna -> Gaussian();
  delete dna;
  int another = 1;
  while(another == 1)
  {
    cout << "If you would like to use another input file, please type its name (including .txt) or otherwise type 'quit'." << endl;
    cin >> inputFile;
    for(int i = 0; i < inputFile.size(); ++i)
    {
      inputFile.at(i) = tolower(inputFile.at(i));
    }
    if(inputFile != "quit")
    {
      DNA *dna = new DNA();
      dna -> ResetVariables();
      dna -> ReadFile(inputFile);
      dna -> Calculate(inputFile);
      dna -> WriteFile(inputFile);
      dna -> Gaussian();
      delete dna;
    }
    else
    {
      cout << "Thank you for using my program." << endl;
      another = 0;
    }
  }
  return 0;
}

//three questions:
// 1) how to make a string from two chars A: concatenate
// 2) what to do about non a, c, t, g, \n A: account
// 3) same output file every time? A: append to the same one
// 4) can use count A * count A for AA or no A: count them all
// 5) do we have to randomize the order of bigrams for the output A: only use nucleotides
// 6) if files all end in \n A: yes you can assume that

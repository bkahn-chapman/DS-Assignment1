#include "DNA.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv)
{
  //gets the command prompt input for the first file to be looked at
  string inputFile = argv[1];
  //created a new instance of the DNA class
  DNA *dna = new DNA();
  //writes the header for the file
  dna -> WriteHeader();
  //reads the file and counts the nucleotides and bigrams
  dna -> ReadFile(inputFile);
  //calculates the summary statistics
  dna -> Calculate(inputFile);
  //write the summary statistics to the output file
  dna -> WriteFile(inputFile);
  //does all of the work for the 1000 string DNA set
  dna -> Gaussian();
  //deletes the created class
  delete dna;
  //for if the user wants to continue to check new files
  int another = 1;
  //while the user still wants to check new files
  while(another == 1)
  {
    cout << "If you would like to use another input file, please type its name (including .txt) or otherwise type 'quit'." << endl;
    //gets the user's next input file
    cin >> inputFile;
    //iterates over the entire string
    for(int i = 0; i < inputFile.size(); ++i)
    {
      //makes every character lowercase
      inputFile.at(i) = tolower(inputFile.at(i));
    }
    //if the user does not want to quit the program
    if(inputFile != "quit")
    {
      //creates a new instance of the DNA class
      DNA *dna = new DNA();
      //resets the variables used to their defaultss
      dna -> ResetVariables();
      //reads the file and counts the nucleotides and bigrams
      dna -> ReadFile(inputFile);
      //calculates the summary statistics
      dna -> Calculate(inputFile);
      //writes the summary statistics to the output file
      dna -> WriteFile(inputFile);
      //does all of the work for the 1000 string section
      dna -> Gaussian();
      //deletes the dna class
      delete dna;
    }
    //if the user does not want to continue using the program
    else
    {
      cout << "Thank you for using my program." << endl;
      //exits the loop
      another = 0;
    }
  }
  return 0;
}

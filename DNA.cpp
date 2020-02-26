#include "DNA.h"
#include <iostream>
#include <fstream>
using namespace std;

//constructor
DNA::DNA()
{

}

//destructor
DNA::~DNA()
{
  cout << "The scan of that file has been completed." << endl;
}

//reads the file and counts the nucleotides and bigrams
void DNA::ReadFile(string input)
{
  //opens the file stream
  ifstream inFS;
  inFS.open(input);
  char c; //current character
  char t; //temporary character
  string s; //bigram string

  //if the file cannot be opened
  if(!inFS)
  {
    cout << "The file '" << input << "' could not be found. Please re-run the program and try again." << endl;
    exit(1); //closes the program
  }

  //while the input is not empty
  while(!inFS.eof())
  {
    //each character goes to c
    inFS >> noskipws >> c;
    c = toupper(c);
    //only checks the characters that are part of the DNA strings
    if(c == 'A' || c == 'C' || c == 'G' || c ==  'T' || c == '\n')
    {
      //counts the nucleotides
      CountLetters(c, s);
      //if it is the first nucleotide in the bigram
      if(numinline % 2 == 1)
      {
        //put it in the temporary variable
        t = c;
        //increments the bigram check counter
        checkBigram = checkBigram + 1;
      }
      //if it is the second nucleotide in the bigram
      else if(numinline != 0 && (c == 'A' || c == 'C' || c == 'G' || c == 'T'))
      {
        //add both nucleotides to the string
        s.append(1, t);
        s.append(1, c);
        //counts the bigram
        CountBigrams(s);
        //increments the bigram check counter
        checkBigram = checkBigram + 1;
      }
      //empties the bigram string
      s = "";
      //increments the value in the string counter
      numinline = numinline + 1;
    }
  }
  //closes the file input stream
  inFS.close();
}

//writes the summary statistics to the output file
void DNA::WriteFile(string input)
{
  //opens the file output stream
  ofstream outFS;
  //opens the output file and appends anything to the end of it
  outFS.open("bkahn.out", ios::app);
  outFS << "For the file: " << input << endl;
  outFS << endl;
  outFS << "The Sum of the length of the DNA strings is: " << sum << endl;
  outFS << "The Mean of the length of the DNA strings is: " << mean << endl;
  outFS << "The Variance of the length of the DNA strings is: " << variance << endl;
  outFS << "The Standard Deviation of the length of the DNA strings is: " << stdev << endl;
  outFS << endl;
  outFS << "The relative probability of each nucleotide is :" << endl;
  outFS << "A:   " << probA << endl;
  outFS << "C:   " << probC << endl;
  outFS << "G:   " << probG << endl;
  outFS << "T:   " << probT << endl;
  outFS << endl;
  outFS << "The relative probability of each nucleotide bigram is:" << endl;
  //calculates the probability of all of the bigrams occurring
  outFS << "AA:   " << numAA/numBigrams << endl;
  outFS << "AC:   " << numAC/numBigrams << endl;
  outFS << "AG:   " << numAG/numBigrams << endl;
  outFS << "AT:   " << numAT/numBigrams << endl;
  outFS << "CA:   " << numCA/numBigrams << endl;
  outFS << "CC:   " << numCC/numBigrams << endl;
  outFS << "CG:   " << numCG/numBigrams << endl;
  outFS << "CT:   " << numCT/numBigrams << endl;
  outFS << "GA:   " << numGA/numBigrams << endl;
  outFS << "GC:   " << numGC/numBigrams << endl;
  outFS << "GG:   " << numGG/numBigrams << endl;
  outFS << "GT:   " << numGT/numBigrams << endl;
  outFS << "TA:   " << numTA/numBigrams << endl;
  outFS << "TC:   " << numTC/numBigrams << endl;
  outFS << "TG:   " << numTG/numBigrams << endl;
  outFS << "TT:   " << numTT/numBigrams << endl;
  outFS << endl;
  outFS << "1000 randomly generated DNA strings:" << endl;
}

//calculates the summary statistics
void DNA::Calculate(string input)
{
  //calculates the mean
  mean = sum / countlines;
  //opens the file input stream
  ifstream inFS;
  inFS.open(input);
  //current character
  char c;
  numinline = 0;
  //while the input is not empty
  while(!inFS.eof())
  {
    inFS >> noskipws >> c;
    c = toupper(c);
    //if the character is a nucleotide
    if(c == 'A' || c == 'C' || c == 'G' || c == 'T')
    {
      numinline = numinline + 1;
    }
    //if the character is the end fo a line
    else if(c == '\n')
    {
      //add to the summation part of the variance calculation
      variance += pow((numinline - mean), 2);
      numinline = 0;
      checkBigram = 0;
    }
  }
  //closes the file input streqm
  inFS.close();
  //calculates the rest of the variance calculation
  variance -= pow(mean, 2);
  variance = variance / countlines;
  //calculates the standard deviation
  stdev = sqrt(variance);

  //calculates the nucleotide probabilities
  probA = numA / sum;
  probC = numC / sum;
  probG = numG / sum;
  probT = numT / sum;
}

//writes the header for the file
void DNA::WriteHeader()
{
  //opens the file output stream
  ofstream outFS;
  outFS.open("bkahn.out", ios::app);
  outFS << "Name: Benjamin Kahn" << endl;
  outFS << "ID: 2316793" << endl;
  outFS << endl;
  outFS << "------------------------" << endl;
  outFS << endl;
  //closes the file output stream
  outFS.close();
}

//counts the nucleotides
void DNA::CountLetters(char letter, string s)
{
  //increments each letter if it is taken in and adds to the total nucleotide count
  if(letter == 'A')
  {
    numA = ++numA;
    ++sum;
  }
  else if(letter == 'C')
  {
    numC = ++numC;
    ++sum;
  }
  else if(letter == 'G')
  {
    numG = ++numG;
    ++sum;
  }
  else if(letter == 'T')
  {
    numT = ++numT;
    ++sum;
  }
  //if it is the end of the line
  else if(letter == '\n')
  {
    //adds to the line counter
    countlines = ++countlines;
    //resets the position in the line
    numinline = 0;
    //resets the bigram string
    s = "";
  }
}

//counts the bigrams in the input
void DNA::CountBigrams(string bigram)
{
  //increments the bigram counter if it is the correct bigram
  if(bigram == "AA"){numAA = ++numAA;}
  if(bigram == "AC"){numAC = ++numAC;}
  if(bigram == "AG"){numAG = ++numAG;}
  if(bigram == "AT"){numAT = ++numAT;}
  if(bigram == "CA"){numCA = ++numCA;}
  if(bigram == "CC"){numCC = ++numCC;}
  if(bigram == "CG"){numCG = ++numCG;}
  if(bigram == "CT"){numCT = ++numCT;}
  if(bigram == "GA"){numGA = ++numGA;}
  if(bigram == "GC"){numGC = ++numGC;}
  if(bigram == "GG"){numGG = ++numGG;}
  if(bigram == "GT"){numGT = ++numGT;}
  if(bigram == "TA"){numTA = ++numTA;}
  if(bigram == "TC"){numTC = ++numTC;}
  if(bigram == "TG"){numTG = ++numTG;}
  if(bigram == "TT"){numTT = ++numTT;}
  //increments the bigram counter
  numBigrams = numBigrams + 1;
}

//calculates the gaussian formula, and outputs the 1000 randomized lines of DNA strings
void DNA::Gaussian()
{
  //opens the file output stream
  ofstream outFS;
  outFS.open("bkahn.out", ios::app);
  float c; //corresponds to the C equation from the assignment document
  float d; //corresponds to the D equation from the assignment document
  //three random numbers from 0 to 1
  float random1;
  float random2;
  float random3;
  //for all 1000 strings
  for(int i = 0; i < 1000; ++i)
  {
    //gets the first two random numbers
    random1 = ((float) rand() / RAND_MAX);
    random2 = ((float) rand() / RAND_MAX);
    //solves the C equation from the assignment document
    c = (sqrt(-2 * log(random1))) * (cos(2 * M_PI * random2));
    //solves the D equation from the assignment document
    d = (stdev * c) + mean;
    //for the length of the string found in the D equation
    for(int i = 0; i < (int)d; ++i)
    {
      //random number between 0 and 1 for probability check
      random3 = ((float) rand() / RAND_MAX);
      //decides which nucleotide to print
      if(random3 < probA)
      {
        outFS << "A";
      }
      else if(random3 < (probA + probC))
      {
        outFS << "C";
      }
      else if(random3 < (probA + probC + probG))
      {
        outFS << "G";
      }
      else
      {
        outFS << "T";
      }
    }
    outFS << endl;
  }
  outFS << endl;
  outFS << endl;
  outFS << endl;
}

//resets the variables to their initial states when a new input is about to be read
void DNA::ResetVariables()
{
  checkBigram = 0;
  countlines = -1;
  numinline = 1;
  sum = 0;
  mean = 0;
  variance = 0;
  stdev = 0;
  numA = 0;
  numC = 0;
  numG = 0;
  numT = 0;
  numAA = 0;
  numAC = 0;
  numAG = 0;
  numAT = 0;
  numCA = 0;
  numCC = 0;
  numCG = 0;
  numCT = 0;
  numGA = 0;
  numGC = 0;
  numGG = 0;
  numGT = 0;
  numTA = 0;
  numTC = 0;
  numTG = 0;
  numTT = 0;
  probA = 0;
  probC = 0;
  probG = 0;
  probT = 0;
  numBigrams = 0;
}

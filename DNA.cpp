#include "DNA.h"
#include <iostream>
#include <fstream>
using namespace std;

DNA::DNA()
{

}

DNA::~DNA()
{
  cout << "The scan of that file has been completed." << endl;
}

void DNA::ReadFile(string input)
{
  ifstream inFS;
  inFS.open(input);
  char c;
  char t;
  string s;

  if(!inFS)
  {
    cout << "The file '" << input << "' could not be found. Please re-run the program and try again." << endl;
    exit(1);
  }

  while(!inFS.eof())
  {
    inFS >> noskipws >> c;
    c = toupper(c);
    if(c == 'A' || c == 'C' || c == 'G' || c ==  'T' || c == '\n')
    {
      CountLetters(c, s);
      if(numinline % 2 == 1)
      {
        t = c;
        checkBigram = checkBigram + 1;
      }
      else if(numinline != 0 && (c == 'A' || c == 'C' || c == 'G' || c == 'T'))
      {
        s.append(1, t);
        s.append(1, c);
        CountBigrams(s);
        checkBigram = checkBigram + 1;
      }
      s = "";
      numinline = numinline + 1;
    }
  }
  inFS.close();
}

void DNA::WriteFile(string input)
{
  ofstream outFS;
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

void DNA::Calculate(string input)
{
  mean = sum / countlines;
  ifstream inFS;
  inFS.open(input);
  char c;
  numinline = 0;
  while(!inFS.eof())
  {
    inFS >> noskipws >> c;
    c = toupper(c);
    if(c == 'A' || c == 'C' || c == 'G' || c == 'T')
    {
      numinline = numinline + 1;
    }
    else if(c == '\n')
    {
      variance += pow((numinline - mean), 2);
      numinline = 0;
      checkBigram = 0;
    }
  }
  inFS.close();
  variance -= pow(mean, 2);
  variance = variance / countlines;
  stdev = sqrt(variance);

  probA = numA / sum;
  probC = numC / sum;
  probG = numG / sum;
  probT = numT / sum;
}

void DNA::WriteHeader()
{
  ofstream outFS;
  outFS.open("bkahn.out", ios::app);
  outFS << "Name: Benjamin Kahn" << endl;
  outFS << "ID: 2316793" << endl;
  outFS << endl;
  outFS << "------------------------" << endl;
  outFS << endl;
  outFS.close();
}

void DNA::CountLetters(char letter, string s)
{
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
  else if(letter == '\n')
  {
    countlines = ++countlines;
    numinline = 0;
    s = "";
  }
}

void DNA::CountBigrams(string bigram)
{
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
  numBigrams = numBigrams + 1;
}

void DNA::Gaussian()
{
  ofstream outFS;
  outFS.open("bkahn.out", ios::app);
  float c;
  float d;
  float random1;
  float random2;
  float random3;
  for(int i = 0; i < 10; ++i)
  {
    random1 = ((float) rand() / RAND_MAX);
    random2 = ((float) rand() / RAND_MAX);
    c = (sqrt(-2 * log(random1))) * (cos(2 * M_PI * random2));
    d = (stdev * c) + mean;
    for(int i = 0; i < (int)d; ++i)
    {
      random3 = ((float) rand() / RAND_MAX);
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

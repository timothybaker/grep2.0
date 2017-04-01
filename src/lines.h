// lines.h
//
// Timothy Baker -- grep2.0
//
//
// Class for object "lines"
//
// contains line details for grep2 search

#ifndef LINES_H_INCLUDED
#define LINES_H_INCLUDED

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

     class lines
     {
          private:
               // private lines data
               std::string lineData;
               int lineNumber;
               std::string term1;
               std::string term2;

          public:
               // constructors and destructor
               lines();
               ~lines();
               lines(std::string Data, int Line, std::string Term1);
               lines(std::string Data, int Line, std::string Term1, std::string Term2);
               lines(const lines& old);

               // setter functions
               void setData(std::string Data){lineData=Data;}
               void setLine(int Line){lineNumber=Line;}
               void setTerm1(std::string Term){term1=Term;}
               void setTerm2(std::string Term){term2=Term;}

               // getter functions
               std::string getData(){return lineData;}
               int getLine(){return lineNumber;}
               std::string getTerm1(){return term1;}
               std::string getTerm2(){return term2;}

               // operator overloading
               lines& operator=(const lines& copy);
               bool operator==(const lines& other)const;
               bool operator!=(const lines& other)const;

               // print lines
               void print(std::ostream& out);
               void printData(std::ostream& out);
               void printAll(std::ostream& out);

               // other functions
               bool searchLine(bool optionE,bool optionX, bool twoTerms);
               void finders(string keepers, bool& match, int matchLength, int& index,int i);
               void finders2(int& finali, string keepers, int matchLength, int& index, int& i, string sect1, string sect2, bool& allDone);
               void finders3(int& finali, int& finali2, string keepers, string keepers2, int matchLength, int matchLength2, int& index, int& index2, int i, string sect1, string sect2, bool& allDone);

    };


// inline functions for << and >> operators
inline std::ostream& operator<<(std::ostream& out, lines& printer)
{
     printer.print(out);
     return out;
}

inline std::istream& operator>>(std::istream& in, lines& reciever)
{
     in.ignore(100, '\n');

     return in;
}

#endif //LINES_H_INCLUDED

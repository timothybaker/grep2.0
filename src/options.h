
// options.h
//
//  Timothy Baker -- grep2.0
//
// class for oject "options"
//
// optional commandline options 
// for grep2 command.


#ifndef OPTIONS_H_INCLUDED
#define OPTIONS_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;


     class options
     {
          private:
               // private options data
               bool selection;
               bool multiFile;
               bool twoTerms;
               const static int totalOptions=6;
               vector<char> gOptions;              
     
          public:
               // constructor and destructor funtions
               options();
               ~options();

               // setter functions
               void setSelection(bool Selection){selection=Selection;}
               void setMulti(bool Multi){multiFile=Multi;}
               void setTwoTerms(bool Terms){twoTerms=Terms;}
               void setOptions(int i, char c){gOptions.at(i)=c;}

               // getter functions
               char getOptions(int i){return gOptions.at(i);}
 	       bool getSelection(){return selection;}
               bool getMulti(){return multiFile;}
               bool getTwoTerms(){return twoTerms;}
               int getTotalOptions(){return totalOptions;}

               // operator overloading

               options& operator=(const options& copy);
               bool operator==(const options& other) const;
	       bool operator!=(const options& other) const;

               // print option
               void print(std::ostream& out);

	       // help function
	       void help();

	       // check for valid options
	       bool validOpt(char check);
    }; 


     // inline functions for << and >> operators
     inline std::ostream& operator<<(std::ostream& out, options& printer)  
     {
          printer.print(out);
          return out;
     }
      
     inline std::istream& operator>>(std::istream& in, options& reciever)
      {
          return in;
      }

#endif //OPTIONS_H_INCLUDED


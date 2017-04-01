// grep2.h
//
// Timothy Baker -- grep2.0
//
//
// class for object "grep2"
//
// information for grep2 command instance


#ifndef GREP2_H_INCLUDED
#define GREP2_H_INCLUDED

#include "file.h"
#include "options.h"
#include "lines.h"
#include <vector>


     class grep2
     {
          private:
               // private grep2 data
               string searchTerm1;
               string searchTerm2;
	       file grep2File;
               options grep2Options;
               int mFiles;
               vector<lines> grep2Lines;
               vector<file> multiFile;

	  public:
	       // constructors and destructors
               grep2();
               ~grep2();
               grep2(string Term1, string Term2, file Grep, file Temp, options Opt);
               grep2(const grep2& old);
          
               // setter functions
               void setTerm1(string Term){searchTerm1=Term;}
               void setTerm2(string Term){searchTerm2=Term;}
               void setFile(file File){grep2File=File;}
               void setFileName(string Name){grep2File.setName(Name);}
               void setOptions(options Options){grep2Options=Options;}
               void setMFiles(int Files){mFiles=Files;}

               // getter functions
               string getTerm1(){return searchTerm1;}
               string getTerm2(){return searchTerm2;}
               file getFile(){return grep2File;}
               options getOptions(){return grep2Options;}
               int getMFiles(){return mFiles;}
               file getMultiFile(int i){return multiFile.at(i);}

               // operator overloading
               grep2& operator=(const grep2& copy);
               bool operator==(const grep2& other)const;
	       bool operator!=(const grep2& other)const;

               // print grep2 contents
               void print(std::ostream& out);
               void showFindings();

               // get command line options and variables
	       void getCommand(int arguments, char **argumentsArray, bool& process);
               void optionHunter(int j, char options);

               // validate command before running
	       void validateCommand(bool& process);

	       // run command
               void runCommand();

               // list command format
               void listFormat();
               void listFormat2();
     };

// inline functions for << and >> operators
inline std::ostream& operator<<(std::ostream& out, grep2& printer)
{
     printer.print(out);
     return out;
}

inline std::istream& operator>>(std::istream& in, grep2& reciever)
{
     
     return in;
}
#endif //GREP_2_INCLUDED


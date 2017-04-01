// options.cpp
//
// Timothy Baker -- grep2.0
//
//
// function definitions for options class


#include "options.h"


/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
// constructors and destructor

//////////////////////
// default constructor
options::options()
{
     selection=false;
     multiFile=false;
     twoTerms=false;

     for(int i=0;i<totalOptions;i++)
     {
          gOptions.push_back('!');
     }
}


/////////////
// destructor 
options::~options()
{
     gOptions.clear();
}

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
// operator overloading

//////////////////////
// assignment operator
options& options::operator=(const options& copy)
{
     if(this == &copy)
     {
          return *this;
     }
 
     else
     {
           for(int i=0;i<totalOptions+1;i++)
           {
                this->gOptions.at(i)=copy.gOptions.at(i);
           }
 
           this->selection=copy.selection;
           this->multiFile=copy.multiFile;
           this->twoTerms=copy.twoTerms;
     }
     return *this;
}

////////////////////
// equality operator
bool options::operator==(const options& other)const
{
     for(int i=0;i<totalOptions+1;i++)
     {
          if(this->gOptions.at(i)==other.gOptions.at(i))
          {
                if(i==totalOptions-1)
                {
                     return true;
                }
          }

     }
     return false;
}

//////////////////////
// inequality operator
bool options::operator!=(const options& other)const
{
     return !(*this==other);
}


//////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////// 
// print function

void options::print(std::ostream& out)
{
      for(int i=0;i<totalOptions+1;i++)
      {
           cout<<gOptions.at(i)<<endl;
      }
}


///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
//other functions


///////////////////////////
// validate option function
bool options::validOpt(char check)
{
     char validOptions[this->totalOptions];
     validOptions[0]='e';
     validOptions[1]='l';
     validOptions[2]='o';
     validOptions[3]='c';
     validOptions[4]='x';
     validOptions[5]='n';

     for(int i=0;i<totalOptions+1;i++)
     {
          if(check==validOptions[i])
          {
               return true;
          }
     }
     return false;
}

///////////////////////
// help option function
void options::help()
{
    cout<<"**********************************************************"<<endl;
    cout<<"----------------------------------------------------------"<<endl;
    cout<<"\t   grep2.0: WELCOME TO GREP2.0 HELP"<<endl;
    cout<<"----------------------------------------------------------"<<endl;
    cout<<"\tgrep2.0 is a grep-like command to search a file"<<endl;
    cout<<"\tfor a term or terms.  If a match is "<<endl;
    cout<<"\tfound, the line from the file containing the "<<endl;
    cout<<"\tmatch is printed to the screen."<<endl;
    cout<<"----------------------------------------------------------"<<endl;
    cout<<" COMMAND FORMAT:"<<endl;
    cout<<endl;
    cout<<"\tgrep2 -options [TERM1] [TERM2] [FILENAME]"<<endl;
    cout<<"----------------------------------------------------------"<<endl;
    cout<<" COMMAND OPTIONS:"<<endl;
    cout<<endl;
    cout<<"\t-c  --  Color Search TERMS in output"<<endl;
    cout<<"\t-e  --  Search for lines including TERM1 or TERM2"<<endl;
    cout<<"\t-h  --  Display Help Information"<<endl;
    cout<<"\t-l  --  Also Print Line Number"<<endl;
    cout<<"\t-o  --  Print Lines One at a Time"<<endl;
    cout<<"\t        (Hit ENTER to proceed)"<<endl;
    cout<<"\t-n  --  Null Option.  Useful to search for TERMS"<<endl; 
    cout<<"\t        that begin with a grep2 option command"<<endl;
    cout<<"\t-x  --  Search for lines including TERM1  and"<<endl;
    cout<<"\t        excluding TERM2."<<endl;
    cout<<endl;
    cout<<" With the exception of -h, more than one"<<endl;
    cout<<" option can be entered at a time." <<endl;
    cout<<" Enter more than one option with no spaces."<<endl;
    cout<<" EXAMPLE: grep2 -celo TERM1 TERM2 FILENAME"<<endl;
    cout<<endl;
    cout<<" Option 'x' combined with 'e' produces [TERM1] XOR [TERM2]"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"COMMAND PARAMETERS:"<<endl;
    cout<<endl;
    cout<<"\t[TERM1]     --  First Search Term"<<endl;
    cout<<"\t[TERM2]     --  Second Search Term"<<endl;
    cout<<"\t[FILENAME]  --  Full Relative Path to File"<<endl;
    cout<<endl;
    cout<<" Only One search term has to be specified."<<endl;
    cout<<" If TERM1 and TERM2 are specified, the default search"<<endl;
    cout<<" returns only lines including TERM1 and TERM2."<<endl;
    cout<<endl;
    cout<<" More than one file can be searched at a time."<<endl;
    cout<<" There is no limit to the number of files that"<<endl;
    cout<<" can be searched with one command."<<endl;
    cout<<" EXAMPLE: grep2 TERM1 FILENAME1 FILENAME2 FILENAME3"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"***********************************************************"<<endl;
}


//end of options.cpp
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

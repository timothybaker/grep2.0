
// lines.cppyy
//
// Timothy Baker -- grep2.0
//
//
// function definitions for class "lines"


#include "lines.h"

#define GREEN "\033[32m"
#define NORMAL "\033[0m"
#define CYAN "\033[36m"

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
// constructors and destructor


///////////////
// constructors
lines::lines()
{
     lineData;
     lineNumber=0;
     term1;
     term2;
}

lines::lines(string Data, int Line, string Term1)
{
     lineData=Data;
     lineNumber=Line;
     term1=Term1;
}

lines::lines(string Data, int Line, string Term1, string Term2)
{
     lineData=Data;
     lineNumber=Line;
     term1=Term1;
     term2=Term2;
}

lines::lines(const lines& old)
{
     lineData=old.lineData;
     lineNumber=old.lineNumber;
     term1=old.term1;
     term2=old.term2;
}
/////////////
// destructor
lines::~lines()
{

}


/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
// operator overloading


//////////////////////
// assignment operator
lines& lines::operator=(const lines& copy)
{
     if(this==&copy)
     {
          return *this;
     }

     else
     {
          lineData=copy.lineData;
          lineNumber=copy.lineNumber;
          term1=copy.term1;
          term2=copy.term2;
     }
    
     return *this;
}

////////////////////
// equality operator
bool lines::operator==(const lines&  other)const
{
     if(this->lineData==other.lineData)
     { 
          if(this->lineNumber==other.lineNumber)
          {
                return true;
          }
     }

     return false;
}

//////////////////////
// inequality operator
bool lines::operator!=(const lines& other)const
{
     return !(*this==other);
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// print function
void lines::print(std::ostream& out)
{
     out<<lineNumber<<" "<<lineData<<endl;
}


///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
// other functions


/////////////
// searchLine
bool lines::searchLine(bool optionE,bool optionX, bool twoTerms)
{
     bool match1=false;
     bool match2=false;
     int lengthD=lineData.length();
     int length1=term1.length();
     int length2=term2.length();
     int index=0;

     for(int i=0;i<lengthD-length1-1;i++)
     {
          finders(term1, match1, length1, index, i);
          index=0;
     }

     if(twoTerms==true)
     {    
          for(int i=0; i<lengthD-length2-1;i++)
          {
                finders(term2, match2, length2, index, i);
                index=0;
          }
     }

     if(optionX==true && optionE==true)
     {
           if(match1==true && match2==false)
           {
                return true;
           }

           if(match1==false && match2==true)
           {
                return true;
           }

           return false;
     }

     if(optionX==true)
     {
           if(match1==true && match2==false)
           {
                 return true;
           }
           
           else
           {
                return false;
           }
     }


     if(optionE==true)
     {
          if(match1==true || match2==true)
          {
               return true;
          }
     }

     if(twoTerms==false)
     {
          if(match1==true)
          {
                return true;
          }
     }

     if(twoTerms==true)
     {
           if(match1==true && match2==true)
           {
                return true;
           }
     }
     
     return false;
}



/////////////
// find match
//
// recursive search function to match search terms in search
// string

void lines::finders(string keepers, bool& match, int matchLength, int& index, int i)
{
     if(keepers[index]==lineData[i])
     {
          index++;

          if(index==matchLength)
          {
               match=true;
          }

          i++;
       
          finders(keepers, match, matchLength, index, i);
     }
}

///////////
// finders2
//
// finders function to color output

void lines::finders2(int& finali, string keepers, int matchLength, int& index, int& i, string sect1, string sect2, bool& allDone)
{
     int lineLength=lineData.length();
     
     if(keepers[index]==lineData[i])
     {
           index++;
    
           if(index==matchLength)
           {
                if(finali!=0)
                {
                     finali++;
                }

                for(int n=finali;n<i+1-matchLength;n++)
                {
                    sect1= sect1+ lineData[n];
                }

                for(int n=finali+sect1.length();n<i+1;n++)
                {
                    sect2= sect2+ lineData[n];
                }
       
                cout<<NORMAL<<sect1<<CYAN<<sect2<<NORMAL;
                sect1=sect2="";
                finali=i;
                index=0;
          }
      
          i++;
          sect1=sect2="";
          finders2(finali,keepers, matchLength, index, i, sect1, sect2, allDone);
     }

     if(lineLength-i<matchLength && allDone==false)
     {
           for(int n=finali+1;n<lineLength;n++)
           {
                sect1= sect1+ lineData[n];
           }
   
           cout<<NORMAL<<sect1;
           sect1="";
           finali=0;
           allDone=true;
     }
}

//////////
//finders3
//
// recursive search function for a two term search and coloring option

void lines::finders3(int& finali, int& finali2,string keepers, string keepers2, int matchLength, int matchLength2, int& index, int& index2, int i, string sect1, string sect2, bool& allDone)
{
     int lineLength=lineData.length();

     if(keepers[index]==lineData[i] || keepers2[index2]==lineData[i])
     {
          if(keepers[index]==lineData[i])
          {
                index++;

                if(index==matchLength)
                {
                     if(finali!=0)
                     {
                          finali++;
                     }
                  
                     else{finali=finali;}             
 
                     for(int n=finali;n<i+1-matchLength;n++)
                     {
                         sect1= sect1+ lineData[n];
                     }

                     for(int n=finali+sect1.length();n<i+1;n++)
                     {
                         sect2= sect2+ lineData[n];
                     }

                     cout<<NORMAL<<sect1<<CYAN<<sect2<<NORMAL;
                     sect1=sect2="";
                     finali=i;
                     index=0;
                     index2=0;
               }
          }

          if(keepers2[index2]==lineData[i])
          {
                index2++;

                if(index2==matchLength2)
                {
                     if(finali!=0)
                     {
                          finali++;
                     }
      
                     else{finali=finali;}

                     for(int n=finali;n<i+1-matchLength2;n++)
                     {
                         sect1= sect1+ lineData[n];
                     } 

                     for(int n=finali+sect1.length();n<i+1;n++)
                     {
                         sect2= sect2+ lineData[n];
                     }

                     cout<<NORMAL<<sect1<<GREEN<<sect2<<NORMAL;
                     sect1=sect2="";
                     finali=i;
                     index2=0;
                     index=0;
               }
          }
 
          i++;
          sect1=sect2="";
          finders3(finali,finali2,keepers,keepers2, matchLength, matchLength2,index, index2, i, sect1, sect2, allDone);

     }

     if(allDone==false)
     { 
           int shortest=0;
           if(matchLength>matchLength2){shortest=matchLength2;}
           else{shortest=matchLength;}
 
           if(lineLength-i<shortest)
           {
                for(int n=finali+1;n<lineLength;n++)
                {
                     sect1= sect1+ lineData[n];
                }

                cout<<NORMAL<<sect1;
                sect1="";
                finali=0;
                allDone=true;
           }
     }

}



//end of lines.cpp
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

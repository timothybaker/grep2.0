
// grep2.cpp
//
// Timothy Baker -- grep2.0
//
//
// function definitions for class "grep2"

#include "grep2.h"
#include <fstream>

#define RED "\033[31m"
#define NORMAL "\033[0m"

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
// constructor and destructor functions

//////////////////////
// default constructor
grep2::grep2()
{
     searchTerm1;
     searchTerm2;
     grep2File;
     grep2Options;
     mFiles=0;
}

//////////////
// constructor
grep2::grep2(string Term1, string Term2,file Grep, file Temp,options Options)
{
     searchTerm1=Term1;
     searchTerm2=Term2;
     grep2File=Grep;
     grep2Options=Options;
     mFiles=0;
}

/////////////
// destructor
grep2::~grep2()
{
   grep2Lines.clear();
   multiFile.clear();  
}

///////////////////
// copy constructor
grep2::grep2(const grep2& copy)
{
     searchTerm1=copy.searchTerm1;
     searchTerm2=copy.searchTerm2;
     grep2File=copy.grep2File;
     grep2Options=copy.grep2Options;
     grep2Lines=copy.grep2Lines;
     mFiles=copy.mFiles;
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
// operator overloading functions

//////////////////////
// assignment operator
grep2& grep2::operator=(const grep2& copy)
{
     if (this == &copy)
     {
          return *this;
     }
     else
     {
          searchTerm1=copy.searchTerm1;
          searchTerm2=copy.searchTerm2;
          grep2File=copy.grep2File;
	  grep2Options=copy.grep2Options;
          mFiles=copy.mFiles;
     }
     return *this;
}

////////////////////
// equality operator
bool grep2::operator==(const grep2& other)const
{
     if(this->grep2File==other.grep2File)
     {
          if(this->grep2Options==other.grep2Options)
  	  {
               return true;
          }
     }
     return false;
}

//////////////////////
// inequality operator
bool grep2::operator!=(const grep2& other)const
{
     return !(*this==other);
}

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
// print function

void grep2::print(std::ostream& out)
{
     out<<"grep2File: "<<endl;
     grep2File.print(out);
     out<< "grep2Options:" <<endl;
     grep2Options.print(out);
}


///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
// command functions

//////////////////////
// getCommand function
//
// getCommand will take the raw user input from the command line
// and pass that info into the grep2 objects private data 
// variables.  During the storage process the format of the input
// is validated. I an incorrect input is detected, the command 
// will fail and an erro message will be dispalyed to the user.


///////////////
// optionHunter
void grep2::optionHunter(int j, char options)
{
      if(grep2Options.validOpt(options)==true)
      {
            grep2Options.setOptions(j, options);
      }
}

/////////////
// getCommand
void grep2::getCommand(int arguments, char **argumentsArray, bool& process)
{
     
     if(arguments==1)
     {
          cout<<"grep2.0: grep2 -h for options and help"<<endl;
          process=false;
     }

     if(arguments==2)
     {
          string checkForOpt=argumentsArray[1];

          if(checkForOpt[0]=='-' && checkForOpt[1]=='h')
          {
                this->grep2Options.help();
                process=false;
          }
          else
          {
               this->listFormat();
               process=false;
          }
     }

     if(arguments==3)
     {
         string checkForOpt=argumentsArray[1];
        
         if(checkForOpt[0]=='-')
         {
              if(checkForOpt[1]=='h')
              {
                   this->grep2Options.help();
		   process=false;
              }
         }     
         
         if(process==true)
         {
              this->searchTerm1=argumentsArray[1];
              this->grep2File.setName(argumentsArray[2]);
         }

     }

     if(arguments==4)
     {
          bool noOptions=true;
          string checkForOpt=argumentsArray[1];
          
          if(checkForOpt[0]=='-')
          {
               if(checkForOpt[1]=='h')
               {
                    this->grep2Options.help();
                    process=false;
               }
              


               if(grep2Options.validOpt(checkForOpt[1])==true)
               {
                    noOptions=false;
                                        
                    for(int i=0;i<grep2Options.getTotalOptions();i++)
                    {
                          optionHunter(i,checkForOpt[i+1]);
                    }

                    grep2Options.setTwoTerms(false);
                    this->searchTerm1=argumentsArray[2];
                    this->grep2File.setName(argumentsArray[3]);
               }
          }

          if(process==true && noOptions==true)
          {
              this->searchTerm1=argumentsArray[1];



              bool fileExist=false;
              string path;

 
              grep2File.validateFile(argumentsArray[2], path,argumentsArray[2],fileExist);

              if(fileExist==true)
              {
                   grep2Options.setMulti(true);
                   mFiles=arguments-2;

                   for(int i=0;i<mFiles;i++)
                   {
                        this->multiFile.push_back(grep2File);
                        this->multiFile.at(i).setName(argumentsArray[i+2]);
                   }
              }

              else
              {
                    grep2Options.setTwoTerms(true);
                    this->searchTerm2=argumentsArray[2];
                    grep2File.setName(argumentsArray[3]);
              }
          }
     }

     if(arguments==5)
     {
          string checkForOpt=argumentsArray[1];
          bool optioned=false;

          if(checkForOpt[0]=='-')
          {
               if(checkForOpt[1]=='h')
               {
                    optioned=true;
                    this->grep2Options.help();
                    process=false;
               }
    
               if(grep2Options.validOpt(checkForOpt[1])==true)
               {    
                    optioned=true;
                  
                    for(int i=0;i<grep2Options.getTotalOptions();i++)
                    {
                         optionHunter(i,checkForOpt[i+1]);
                    }
          
                    grep2Options.setTwoTerms(false);
                    this->grep2Options.setSelection(true);
                    this->searchTerm1=argumentsArray[2];


                    bool fileExist=false;
                    string path;

                    grep2File.validateFile(argumentsArray[3], path,argumentsArray[3],fileExist);

                    if(fileExist==true)
                    {
                         mFiles=arguments-3;
                         grep2Options.setMulti(true);

                         for(int i=0;i<mFiles;i++)
                        {
                             this->multiFile.push_back(grep2File);
                             this->multiFile.at(i).setName(argumentsArray[i+3]);
                             this->multiFile.at(i).setDirectory(path);
                        }
                    }

                    else
                    {
                        grep2Options.setTwoTerms(true);
                        this->searchTerm2=argumentsArray[3];
                        grep2File.setName(argumentsArray[4]);
                    }
                 
               }
          }
          

          if(process==true && optioned==false)
          {
              this->searchTerm1=argumentsArray[1];
              bool fileExist=false;
              string path;
              grep2Options.setMulti(true);
              

              grep2File.validateFile(argumentsArray[2], path,argumentsArray[2],fileExist);

              if(fileExist==true)
              {
                   mFiles=arguments-2;

                   for(int i=0;i<mFiles;i++)
                   {
                        this->multiFile.push_back(grep2File);
                        this->multiFile.at(i).setName(argumentsArray[i+2]);
                   }
              }

              else
              {
                   mFiles=arguments-3;
                   grep2Options.setTwoTerms(true);
                   this->searchTerm2=argumentsArray[2];

                   for(int i=0;i<mFiles;i++)
                   {
                       this->multiFile.push_back(grep2File);
                       this->multiFile.at(i).setName(argumentsArray[i+3]);
                   }
              }
          }
     }

     if(arguments>5)
     {
          bool noOptions=true;
          string path;

          grep2Options.setMulti(true);
          
          string checkForOpt=argumentsArray[1];

          if(checkForOpt[0]=='-')

          {
               bool fileExist=false;
               
               if(checkForOpt[1]=='h')
               {
                    this->grep2Options.help();
                    process=false;
               }


               if(grep2Options.validOpt(checkForOpt[1])==true)
               {
                    this->grep2Options.setSelection(true);
                    noOptions=false;

                    for(int i=0;i<grep2Options.getTotalOptions();i++)
                    {
                         optionHunter(i,checkForOpt[i+1]);
                    }

                    grep2Options.setTwoTerms(false);
                    this->searchTerm1=argumentsArray[2];
                        
                    grep2File.validateFile(argumentsArray[3], path, argumentsArray[3], fileExist);

                    if(fileExist==true)
                    {
                          mFiles=arguments-3;
 
                          for(int i=0;i<mFiles;i++)
                          {
                               this->multiFile.push_back(grep2File);
                               this->multiFile.at(i).setName(argumentsArray[i+3]);
                          }
                    } 
                     
                    else
                    {
                        mFiles=arguments-4;
                        this->searchTerm2=argumentsArray[3];                            
                        grep2Options.setTwoTerms(true);
                              
                        for(int i=0;i<mFiles;i++)
                        {
                              this->multiFile.push_back(grep2File);
                              this->multiFile.at(i).setName(argumentsArray[i+4]);
                        }
                    }
               }
          }

          if(process==true && noOptions==true)
          {
              this->searchTerm1=argumentsArray[1];
              bool fileExist=false;
              string path;

              grep2File.validateFile(argumentsArray[2], path,argumentsArray[2],fileExist);
            
              if(fileExist==true)
              {
                   mFiles=arguments-2;    
 
                   for(int i=0;i<mFiles;i++)
                   {
                        this->multiFile.push_back(grep2File);
                        this->multiFile.at(i).setName(argumentsArray[i+2]);
                   } 
              }                      

              else
              {
                   mFiles=arguments-3;
                   grep2Options.setTwoTerms(true);
                   this->searchTerm2=argumentsArray[2];

                   for(int i=0;i<mFiles;i++)
                   {
                       this->multiFile.push_back(grep2File);
                       this->multiFile.at(i).setName(argumentsArray[i+3]);
                   }
              } 
          }
     }
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// validateCommand function


void grep2::validateCommand(bool& process)
{
     bool fileExist=false;
     int length=this->grep2File.getName().length();
     string gFile=this->grep2File.getName();
     string Path="";
     char chars[length];

     for(int i=0;i<length;i++)
     {
          chars[i]=gFile[i];
     }

     char *file=chars;

     this->grep2File.validateFile(gFile, Path, file, fileExist);
     
     if(fileExist==true)
     {
          this->grep2File.setDirectory(Path);
     }

     if(fileExist==false)
     {
          this->listFormat2();
          process=false;
     }          
}


///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
// runCommand function

void grep2::runCommand()
{
     int index=0;
     string Path=this->grep2File.getDirectory();
     char Name[Path.length()];
     bool optionE=false;
     bool optionX=false;
     bool twoTerms=grep2Options.getTwoTerms();

     for(int i=0;i<Path.length();i++)
     {
          Name[i]=Path[i];
     }
 
     if(grep2Options.getMulti()==true)
     {
          grep2Lines.clear();
     }

     ifstream grepFile;
     grepFile.open(Name);


     if(!grepFile)
     {
          cout<<"grep2.0: ERROR OPENING FILE."<<endl;
     }

     vector<lines>* lineCheck= new vector<lines>();

     string lineGrab;
     lines tempLine;
     
     tempLine.setTerm1(this->searchTerm1);
     tempLine.setTerm2(this->searchTerm2);


     while(!grepFile.eof())
     {    
          getline(grepFile,lineGrab);
          tempLine.setLine(index+1);
          tempLine.setData(lineGrab);
          lineCheck->push_back(tempLine);
          index++;
     }

     grepFile.close();
     
     for(int i=0;i<grep2Options.getTotalOptions();i++)
     {
          if(grep2Options.getOptions(i)=='e')
          {
               optionE=true;
          }

          if(grep2Options.getOptions(i)=='x')
          {
               optionX=true;
          }
     }
     
     for(int i=0;i<lineCheck->size();i++)
     {
          if(lineCheck->at(i).searchLine(optionE,optionX,twoTerms)==true)
          {
              grep2Lines.push_back(lineCheck->at(i));
          }
     }

     lineCheck->clear();
}


///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
// print results

///////////////
// showFindings

void grep2::showFindings()
{
     bool optionL=false;
     bool optionO=false;
     bool optionC=false;
     bool optionMulti=false;


     for(int i=0;i<grep2Options.getTotalOptions();i++)
     {
          if(grep2Options.getOptions(i)=='l')
          {
               optionL=true;
          }
  
          if(grep2Options.getOptions(i)=='o')
          {
               optionO=true;
          }

          if(grep2Options.getOptions(i)=='c')
          {
               optionC=true;
          }
     }
    
     if(grep2Options.getMulti()==true)
     {
         optionMulti=true;
     }
     
     if(optionC==false)
     {
         for(int i=0;i<grep2Lines.size();i++)
         {
             if(optionMulti==true){cout<<grep2File.getName()<<":: ";}
             else{cout<<"";}
             if(optionL==true){cout<<grep2Lines.at(i).getLine()<<": ";}
             else {cout<<"";}
             cout<<grep2Lines.at(i).getData();
             if(optionO==true){cin.ignore();}
             else{cout<<endl;}         
          }
      }

      if(optionC==true)
      {       
 
           if(grep2Options.getTwoTerms()==false)
           {
               int index=0;
               int finali=0;
               bool allDone=false;
               string sect1="";  // before match
               string sect2="";  // match -- applying color                

               for(int i=0;i<grep2Lines.size();i++)   
               {     
                     if(optionMulti==true){cout<<RED<<grep2File.getName()<<NORMAL<<":: ";}
                     else{cout<<"";}
                     if(optionL==true){cout<<grep2Lines.at(i).getLine()<<": ";}
                     else{cout<<"";}

                     for(int j=0;j<grep2Lines.at(i).getData().length();j++)
                     {   
                         grep2Lines.at(i).finders2(finali,searchTerm1,searchTerm1.length(),index,j,sect1, sect2,allDone);
                         index=0;
                         sect1=sect2="";
                     }
        
                     allDone=false;
                     if(optionO==true){cin.ignore();}
                     else{cout<<endl;}
                }
           }

           if(grep2Options.getTwoTerms()==true)
           {    
               string sect1="";
               string sect2="";
               int finali=0;
               int finali2=0;
               int index=0;
               int index2=0;
               bool allDone=false;
                
               for(int i=0;i<grep2Lines.size();i++)
               {
                    if(optionMulti==true){cout<<RED<<grep2File.getName()<<NORMAL<<":: ";}
                    else{cout<<"";}
                    if(optionL==true){cout<<grep2Lines.at(i).getLine()<<": ";}
                    else {cout<<"";}

                    for(int j=0;j<grep2Lines.at(i).getData().length();j++)
                    {
                          grep2Lines.at(i).finders3(finali, finali2,searchTerm1, searchTerm2, searchTerm1.length(), searchTerm2.length(), index, index2, j, sect1, sect2, allDone);
                          index=0;
                          index2=0;
                          sect1=sect2="";
                    }
              
                    allDone=false;
                    if(optionO==true){cin.ignore();}
                    else{cout<<endl;}
               }
           }
      }
}


//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
// Error reporting functions

// list command format
void grep2::listFormat()
{
     cout<<"grep2.0: INVALID COMMAND"<<endl;
     cout<<"For options and help:  grep2 -h"<<endl;
}

// list command format2, if file does not exist
void grep2::listFormat2()
{
     cout<<"grep2.0: ERROR OPENING FILE. USE RELATIVE PATH."<<endl;
}

//end of grep2.cpp
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

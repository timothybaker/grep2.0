// file.cpp
//
// Timothy Baker -- grep2.0
//
//
// function definitions for class "file"


#include "file.h"
#include <fstream>

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
// constructor and destructor functions

//////////////////////
// default constructor
file::file()
{
     fileName;
     fileExtension;
     fileDirectory;
     fileSize=0;
}

//////////////
// constructor 
file::file(string Name, string Extension, string Directory, float Size)
{
     fileName=Name;
     fileExtension=Extension;
     fileDirectory=Directory;
     fileSize=Size;
}

/////////////
// destructor
file::~file()
{

}

///////////////////
// copy constructor
file::file(const file& copy)
{
     fileName=copy.fileName;
     fileExtension=copy.fileExtension;
     fileDirectory=copy.fileDirectory;
     fileSize=copy.fileSize;
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// operator overloading functions


//////////////////////
// assignment operator
file& file::operator=(const file& copy)
{
     if (this == &copy)
     {
          return *this;
     }
     else
     {
          fileName=copy.fileName;
          fileExtension=copy.fileExtension;
          fileDirectory=copy.fileDirectory;
          fileSize=copy.fileSize;
     }
     return *this;
}

////////////////////
// equality operator
bool file::operator==(const file& other)const
{
     if(this->fileName==other.fileName)
     {
          if(this->fileExtension==other.fileExtension)
          {
               if(this->fileDirectory==other.fileDirectory)
               {
                    return true;
               }
          }
     }
     return false;
}

//////////////////////
// inequality operator
bool file::operator!=(const file& other)const
{
    return !(*this==other);
}

/////////////////////
// less than operator
bool file::operator<(const file& other)const
{
     //if (this->fileSize<other.fileSize)
     //{
     //     return true;
     //{
     return false;
}

////////////////////////
// greater than operator
bool file::operator>(const file& other)const
{
     if (this->fileSize>other.fileSize)
     {
          return true;
     }
     return false;
}

/////////////////////////////////
// less than or equal to operator
bool file::operator<=(const file& other)const
{
     if (this->fileSize<=other.fileSize)
     {
          return true;
     }
     return false;
}

////////////////////////////////////
// greater than or equal to operator
bool file::operator>=(const file& other)const
{
     if (this->fileSize>=other.fileSize)
     {
          return true;
     }
     return false;
}


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// print function
void file::print(std::ostream& out)
{
     out<<"\tfileName: "<<fileName<<endl;
     out<<"\tfileExtension: "<<fileExtension<<endl;
     out<<"\tfileDirectory: "<<fileDirectory<<endl;
     out<<"\tfileSize: "<<fileSize<<endl;
}


///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
// validate File Exist Function
// 
// This function will determine if the specified file
// exists.  If it does not exist, an error will be
// displayed.  if it does exist, information will be 
// gathered on the file and the grep2 process will
// continue.


void file::validateFile(string Name, string& Path, char *fileName, bool& fileExist)
{
     ifstream grepFile;
     ifstream thorough;
      

     string thoroughly="./"+Name;
     char dotSlash[thoroughly.length()];
      

     for(int i=0;i<thoroughly.length();i++)
     {
          dotSlash[i]=thoroughly[i];
     }

     grepFile.open(fileName);
     thorough.open(dotSlash);

     if(grepFile)
     {
          fileExist=true;
          Path=Name;
     }

      
     if(!grepFile)
     {
          if(thorough)
          {
               fileExist=true;
               Path=thoroughly;
          }
     }
    
     if(!thorough)
     {
          thorough.close();
          string doubleDS="./"+thoroughly;
          char dDS[doubleDS.length()];

          for(int i=0; i<doubleDS.length();i++)
          {
                dDS[i]=doubleDS[i];
          }

          thorough.open(dDS);
          
          if(thorough)
          {
                fileExist=true;
                Path=doubleDS;
          }
     }    

     grepFile.close();
     thorough.close();
}

//end of file.cpp
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

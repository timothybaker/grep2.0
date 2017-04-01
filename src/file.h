// file.h
//
// Timothy Baker -- grep2.0
//
//
// class for object "file" 
//
// stores file information for grep2



#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;


     class file
     {
          private:
	       // private file data
	       string fileName;
	       string fileExtension;
	       string fileDirectory;
               float  fileSize;
	  
	  public:
               // constructors and destructors
               file();
               ~file();
               file(string Name, string Extension, string Directory, float Size);
               file(const file& old);

	       // setter functions
	       void setName(string Name){fileName=Name;}
	       void setExtension(string Extension){fileExtension=Extension;}
	       void setDirectory(string Directory){fileDirectory=Directory;}
	       void setSize(float Size){fileSize=Size;}
	       
	       // getter functions
	       string getName(){return fileName;}
	       string getExtension(){return fileExtension;}
	       string getDirectory(){return fileDirectory;}
	       float getSize(){return fileSize;}
 
	       // operator overloading
	       file& operator=(const file& copy);
               bool operator==(const file& other)const;
               bool operator!=(const file& other)const;
               bool operator>(const file& other)const;
               bool operator<(const file& other)const;
               bool operator>=(const file& other)const;
               bool operator<=(const file& other)const;

	       // print file contents
	       void print(std::ostream& out);

               // validate that the file Exist
               void validateFile(string Name, string& Path, char *fileName, 
                      bool& fileExist);

     };

// inline functions for << and >> operators
inline std::ostream& operator<<(std::ostream& out, file& printer)
{
     printer.print(out);
     return out;
}

inline std::istream& operator>>(std::istream& in, file& reciever)
{
     string Name;
     string Extension;
     string Directory;
     float Size;

     in>>Name;
     in>>Extension;
     in>>Directory;
     in>>Size;
     in.ignore(100,'\n');

     reciever.setName(Name);
     reciever.setExtension(Extension);
     reciever.setDirectory(Directory);
     reciever.setSize(Size);
     
     return in;
}

#endif //FILE_H_INCLUDED


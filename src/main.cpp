// main.cpp
//
// Timothy Baker -- grep2.0
//
// 7/26/2016-
//
//
// This is a program to replicate the basic
// functionality of the unix 'grep' command.


#include "grep2.h"


// grep2 main
int main(int argc, char **argv)
{
     //global variables
     bool process=true;

     // create grep2 object
     grep2 grep2;
     
     // get the command line options and variables
     grep2.getCommand(argc, argv, process);

     // if only one file is to be searched
     if(grep2.getOptions().getMulti()==false)
     {
          if(process==true)
          {
               // validate command
               grep2.validateCommand(process);

               if(process==true)
               {
                    // run the grep2 command
                    grep2.runCommand();
                    grep2.showFindings();
               }
          }
      }

      //if more than one file is to searched
      if(grep2.getOptions().getMulti()==true)
      {
           if(process==true)
           {
                for(int i=0;i<grep2.getMFiles();i++)
                {
                     if(process==true)
                     {
                            // validate command
                            grep2.setFileName(grep2.getMultiFile(i).getName());
                            grep2.validateCommand(process);
                     }
                     
                }    
 
                if(process==true)
                {
                     for(int i=0;i<grep2.getMFiles();i++)
                     { 
                           if(process=true)
                           {  
                                // run the grep2 command
                                grep2.setFileName(grep2.getMultiFile(i).getName());
                                grep2.validateCommand(process); // make sure file is still available, set fileDirectory
                                grep2.runCommand();
                                grep2.showFindings();
                           }
                     }
                }
           }
      }

     return 0;
}


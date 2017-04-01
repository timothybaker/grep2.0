# grep2.0
#
# Timothy Baker -- August 2, 2016



# Basic Instructions


	Grep2.0 was built to imitate the basic functionality of the grep command found on modern linux

systems.  Grep2.0 will search a specified file (or files) for the search pattern provided with the input.

The basic command structure is: grep2 -options TERM FILENAME


	Run the program with grep2 -h to list all options and to diplay Grep2.0 Help. The program can be run 

with no options or with all optoins, and it can search for one or two search terms.  There is no limit

to the number of files that can be searched at one time.

 
	The standard grep2 command will not match search terms with color on the output, however, by including 

option -c in the command the search term or terms will be color matched in each line as many times as 

they appear.  


	In order to differentiate Grep2.0 from grep, some extra functionality was added.  Namely the 

ability to search for two terms at one time, and with options to change how the terms are utilized.

Without any options, Grep2.0 will return lines from the files that contain only both terms in one line.

With options -x included, Grep2.0 will only return lines containing Term1 AND NOT Term2.  With option

-e included, Grep2.0 will return lines containing either TERM1 OR TERM2.  With both options 'x' and 'e'

included, Grep2.0 will return lines containing TERM1 AND NOT Term2 and lines containing TERM2 AND NOT

Term1.



	
# MAKEFILE


	To compile Grep2.0, go to the grep2.0 directory and run the make command.  The make command

will create objects for the .cpp files located in grep2.0/src and store them in grep2.0/obj.  The

object files are then linked to produce the grep2 executable.  The executable is created in grep2.0/bin.  

To install the grep2 command, run the make install command.  This will copy the grep2 binary file to the 

/usr/local/bin folder, allowing the grep2 command to be run from any directory.  The make clean command 

will destroy the object files in grep2.0/obj and will delete the grep2 binary file from grep2.0/bin.

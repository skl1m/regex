#include <iostream>
#include <fstream>
#include <regex>

//using namespace std;

int main(int argc, char** argv)
{
	//Declaration of an input file stream and used to 
	//read information from files
	std::ifstream txtfile;

	//Declaration of a string for storing each line recieved from the file
	//being read into the program
	std::string line; 

	/**
	Declaring and intializing regex named r
	At the end i've included a \s to handle any white spaces
	**/
	std::regex r("\\$\\**(0|[1-9]\\d{0,2}(,\\d{3})*)(\\.\\d{2})?\\s*"); 

	/**
	Open the file stream, which is passed in from the terminal
	This allows for any text file to be passed in and read from
	**/
	txtfile.open(argv[1]);

		//If the file opens then take the next steps
		if (txtfile.is_open())
		{
			//while(txtfile.good())
			while(getline(txtfile, line))
			{
				//cout << regex_match(line,r) << endl;
				/**
				If the line retrieved from the text file matches
				the regular expression r, then output Matched : 
				and the line that was retrieved
				Otherwise output Not Matched : and the line that
				was retrieved that did not match the regeluar 
				expression requirements
				**/
				if(std::regex_match(line, r)){
					std::cout << "Matched: " << line << std::endl;
				}else{
					std::cout << "Not Matched: " << line << std::endl;
				}
			}
		}
		else{ 
			//If there was an issue opening the file
			//then output an error message
			std::cout << "Error: File NOT open!" << std::endl;
			//Calls the system to stop
			exit(1);
		}
	//Closes the input stream
	txtfile.close();
	return 0;
}

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Assn2{
	public static void main(String[] args){
		
		//String representatitve of regex for the assignment
		String regex = "\\$\\**(0|[1-9][0-9]{0,2}(\\,[0-9]{3})*)(\\.[0-9]{1,2})?";
		//String regex = "\\$\\**(0 |([1-9])*([0-9]{0,2})(\\,[0-9]{3})*(\\.[0-9]{2})?)";

		// Compiles a representation of a regular expression
		Pattern patt = Pattern.compile(regex);

		//To handle if the file is not found exception
		try{
			// Creates a File object by passing the name of the file
			File reader = new File (args[0]);
			
			//To obtain input
			Scanner input = new Scanner (reader);

			while(input.hasNext()){
				//Stores the file's text into a string
				String line = input.nextLine();
				//A matcher named match is created that performs
				//operations on the string that's read from the file
				//to the pattern named patt
				Matcher match = patt.matcher(line);

				//If the text from the file matches the requirements of the
				//regular expression then print "Matched: " and the text
				if (line.matches(regex)){
					System.out.println("Matched: " + line); 
				//If the text from the file does not match the requirements
				//of the regular expression then print "Not Matched" and the text
				}else{ 
					System.out.println("Not Matched: " + line);
				}
			}
		}catch (FileNotFoundException e){
			System.out.println("File NOT found!");
		}
	}
}
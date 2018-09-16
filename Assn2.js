
		//Declare my regular expression stored in a variable
		var regexPattern = /^\$\**(0|[1-9]\d{0,2}(,\d{3})*)(\.\d{2})?\s*$/;
		//Variable representative of the outcome of comparing the regular
		//expression to a line from the txt file
		var outcome; 

		//To ensure the filename is retrieved from command line
		if(process.argv.length<3){
			console.log('Usage: node' + process.argv[1] + 'FILENAME');
			process.exit(1);
		}

		//Allows the ability to work with the file system, in our
		//case read files
		var fs = require('fs');
		//readFileSync is used to read files on the computer
		//process.argv[2] is to process the file name passed in from terminal
		//which then is converted to a string that is split into an array
		//at each new line and stored as an array
		var lines = fs.readFileSync(process.argv[2]).toString().split("\n");

		//loops through each element of the array of each line from
		//the text file and is compared to the regular expression
		//declared above. If the regex matches the element in the array
		//then store matched into the variable called outcome. If not, then store
		//not matched into the variable outcome
		lines.forEach(function(element){
			const isMatching = regexPattern.test(element);
			//console.log("Value: " + isMatching);
			if(isMatching){
				outcome = 'Matched: ';
			}else{
				outcome ='Not Matched: ';
			}
			//print the result
			console.log(outcome + element);
		});




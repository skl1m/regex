import sys
import re
#read file from terminal
txtFile = sys.argv[1];

#open file and return a file object
#txtFile is the read in file name
#r means open for reading in text mode
file = open(txtFile, "r");

#regex
pattern = re.compile("[$][*]*(0|[1-9]\\d{0,2}([,]\\d{3})*)([.]\\d{2})?\\s*$");

#read until no more lines
for line in file:
    
    #compares regex pattern with line read
    matched = pattern.match(line)
    
    #if matched = true
    #the comma at the end of the print statement
    #supresses a line feed
    if matched:
        print "Matched: " + line,
    else:
        print "Not Matched: " + line,
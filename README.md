# linux-utility-wordle
implementing something similar to the wordle game [https://www.powerlanguage.co.uk/wordle/]. You will be given a file (fs) containing a list of words and a string (str). Your task is to print all five-letter words in fs that do not have any character in the string str.

## Example Usage
prompt> ./wordle filename string

If the file containing the wordlist is named word-list.txt and the string is hasnot, your program will be executed as follows:

prompt> ./wordle word-list.txt hasnot

The output of your program should be all lines which have exactly 5 characters (excluding the endline \n character) and none of the character in the string hasnot (i.e. does not have any of these characters: h,a,s,n,o,t).

#include <stdio.h>

/*
DOES A BULLSEYE PATTERN FROM THE SEQUENCE OF CHARACTESRS ENETERED (Max 20 char, but can be modded)

ex
Input: Giorno

Output:
ooooooooooo
onnnnnnnnno
onrrrrrrrno
onrooooorno
onroiiiorno
onroiGiorno
onroiiiorno
onrooooorno
onrrrrrrrno
onnnnnnnnno
ooooooooooo

*/

int charCount(char* fName)
{//charCount begins here

	//Counts char in a string
	
	int counter = 0;
	
	while(fName[counter] != '\0')
	{
		
		counter = counter + 1;
		
	}
	
	counter = counter - 2;
	
	return(counter);
	
}//charCount ends here

void patternMaker(int width, int mid, char* fName)
{
	//Does the pattern but needs outer loops to know when and where to stop
	
	//local variables
	int subCounter = 0;//keeps count of how many iterations have happened
	int subCountRule = (width * 2) + 1; //the stop rule to know where to end the loop
	int index = mid;//index of the string
	
	//Local Code
	do//loop makes indices in decreasing order until it needs to ascend
	{
		
		if(index == width)//if loop needs to be done for consecutive characters then it goes here
			{
				do  //here consecutive characters means the same letters that are together
				{
					printf("%c", fName[index]);
					subCounter = subCounter + 1;
					
				}while(subCounter < subCountRule);
			}
			else//decreases the number until consecutive characters are found
			{
				printf("%c", fName[index]);
				
				index = index - 1;
			}
		
	}while(subCounter == 0); //ends loop makes indices in decreasing order until it needs to ascend
	
	while(index < mid)//loop makes indices in increasing order(ascends) to end of the line if needed
	{
			
		index = index + 1;
			
		printf("%c", fName[index]);
			
	}//ends loop makes indices in increasing order(ascends) to end the line if needed

	printf("\n");//makes the next line
	
}//ends function patternMaker

int main()
{//main begins
	
	char name[20];
	
	int mid;
	
	int width;

	printf("\nInput a name please\n");
	
	fgets(name, 20, stdin);
	
	mid = charCount(name); //the mid will always be starting from zero, so its the number of letters - 1

	width = mid;
	
	printf("\n\n");//newline so that the words don't get mixed up with the pattern
	
	//ONLY differnce between both loops is whether or not width is added or subtracted

	if(mid == 0)//incase only 1 letter is entered
	{
		printf("%c", name[0]);
	}
	else//normal situation for pattern
	{
		do//1st loop that does from top line till it hits the center
		{
			
			patternMaker(width, mid, name);//makes the single line pattern
			
			width = width - 1;//decreases the width
			
		}while(width >= 0);//ends 1st loop that does from top line till it hits the center
		
		width = 1;

		do//does lower half of the pattern
		{
			
			patternMaker(width, mid, name); //makes the single line pattern
			
			width = width + 1;// increases the width
			
		}while(width <= mid);//final stop for in the final line
		
	}//else of the normal situation ends here
		
	return(0);
	
}//main ends
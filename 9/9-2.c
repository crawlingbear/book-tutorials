/***********************************************************************
 * Exercise 9-2: Write a function begins(string1, string2) that returns*
 * true if string1 begins string2. Write a program to test the function*
 **********************************************************************/
 #include <stdio.h>
 
 char string1[100];
 char string2[100];

/* gets the length of string 1 to match with length of string1/string2 compare */
int get_string_length(char string[])
{
	int index; 	/*index into the string*/
	for(index = 0; string[index] != '\0'; ++index)
		continue; /*do nothing */
	return (index-1); /* -1 required to get rid of \n at the end of string */
}

/* returns true if string1 begins string2 */
int begins(char string1[], char string2[]){
	int index; /* index into the string */
	
	/* calculates the length of string match */
	for (index = 0; string1[index] == string2[index]; ++index)
		continue; /* do nothing */
	
	return (index);
}

int main(){
	
	while(1){
		printf("Enter the first string to compare:");
		fgets(string1, sizeof(string1), stdin);
		
		/* gives the user an exit */
		if( (string1[0] == 'q') || (string1[0] == 'Q') )
			break;
		
		printf("Enter the second string to compate:");
		fgets(string2, sizeof(string2), stdin);
		
		begins(string1,string2);
		
		//printf("DEBUG: Get_string_length(string1) = %d\n",get_string_length(string1));
		//printf("DEBUG: begins(string1,string2) = %d\n", begins(string1,string2));
		
		/*checks if length of string compare matches length of string */
		if((get_string_length(string1)) == (begins(string1,string2)))
			printf("True\n");
		else
			printf("False\n");
	}
	return(0);
}

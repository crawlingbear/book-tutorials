/***********************************************************************
 * Exercise 9-1 Write a procedure that counts the number of words in a *
 * string. (Your documentation should describe exactly how you define  *
 * a word.) Write a program to test your new procedure.				   *
 * 																	   *
 * NOTE: This program counts spaces between words and will add 1 to	   *
 * 		 account for the last word that will not have a space at the   *
 * 		 end. In its current state it will show an incorrect word	   *
 * 		 count if the user does not use proper spacing 				   *
 **********************************************************************/
 #include <stdio.h>
 #include <string.h>
 
 int	word_qty;
 
 char	user_input[100];
 char	words_to_count[100];
 char	output[100];

int word_counter(char string[])
{
	int	index;	/* index into the string */
	word_qty = 1; /*required for last word*/
	/*
	 * Loop until we reach a space. Then ++wordcounter.
	 */
	for (index = 0; string[index] != '\0'; ++index){
		if(string[index] == ' ')
			++word_qty;
		continue; /* do nothing */
	}
		return (word_qty);
}


int main(){
	
	while(1){
		printf("Enter words to count:");
		fgets(user_input, sizeof(user_input), stdin);
		
		user_input[strlen(user_input)-1] = '\0';
		//strcpy(output, user_input);
		/* quits the loop */
		if( (user_input[0] == 'q') || (user_input[0] == 'Q'))
			break;
		
		printf("There are %d words in, '%s'\n", word_counter(user_input), user_input);
	}
	return (0);
}

/****************************************************
* Ex 8-3: Write a program to average n int-numbers	*
*													*
* Author: crawlingbear								*
*													*
* Usage: user inputs a single number (+/-)			*
* 		 the program returns printout of			*
* 		 user inputs in aritmatic form and			*
* 		 the resulting float_average 				*
* 													*
* Ex form: ( ## + ## - ##) / ##_inputs				*
****************************************************/ 
#include <stdio.h>
#include <string.h>

int		current;				/* current value from user */
int		sum_inputs;				/* sum of user inputs */	
int		qty_inputs;				/* # of inputs */
float 	average;				/* average value calculated */

char 	line[80];				/* number input from keyboard */
char 	log_line[999];			/* running log of user inputs in arithmatic form*/
char 	formula_print[999]; 	/* shows equation for user view */
char 	qty_inputs_char[999];	/*used to convert qty_inputs to char */

int main(){
	strcpy(log_line, "(");
	sum_inputs = 0;
	qty_inputs = 0;

	
	/* Loop forever (or until break reached) */
	while(1){
		if ( qty_inputs > 0){
		//	printf("Debug test line[0]: %c line[1]: %c\n", line[0], line[1]);
		//	printf("Average of %s\n", log_line);
			printf("Average Formula: %s\n", formula_print);
			printf("Result: %f\n", average);
		}
		printf("Enter a number: ");
		
		fgets(line, sizeof(line), stdin);
		sscanf(line, "%d", &current);
		/* trim off last character */
		line[strlen(line)-1] = '\0';
				
		/* creates a log of user inputs */
		if((line[0] == 'q') || (line[0] == 'Q'))
			break;
		/* first input has no preceding +/- value */
		if( qty_inputs == 0 )
			strcat(log_line, " ");
		else {
			/* adds a plus/minus sign to log to show in aritmatic form */
			if ( line[0] >= '0' )  
				strcat(log_line, " + ");
			else {
					/* adds a space between '-' sign to show subtraction versus adding a negative # */
					line[0] = ' ';	 
					strcat(log_line, " -");  
			}
		}
		
		/*adds user input to log*/
		strcat(log_line, line);
				
		/* computes average of entered numbers against eachother */
		sum_inputs = current + sum_inputs;
		++qty_inputs;
		average = (float) sum_inputs / qty_inputs;
		
		/*Constructs formula for printout */

		strcpy(formula_print, log_line);
		strcat(formula_print, " ) / ( ");
		sprintf(qty_inputs_char, "%d", qty_inputs);
		strcat(formula_print, qty_inputs_char);
		strcat(formula_print, " )");
		
	}
	return(0);
}
	

		
	

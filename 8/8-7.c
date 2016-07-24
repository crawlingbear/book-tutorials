/********************************************************************
* Exercise 8 - 6/7	Write a program that converts numbers to words	*
*																	*
* Example: 81 = eighty one, 100 = one hundred						*
********************************************************************/
#include <stdio.h>
#include <string.h>

int		user_value;
int		inputs;

char	user_input[100];
char	short_char[100]; 
char	output[100];		/* print output */

/*Given position in number performs a simple conversions i.e. 1 = one */
/* Note: pos == 1 for ones place, 2 for tens place ... */
int simple_counting(pos)
{	
	switch(user_input[strlen(user_input)- pos]) {
		case '0':
			break;
		case '1':
			strcat(output, "one ");
			break;
		case '2':
			strcat(output, "two ");
			break;
		case '3':
			strcat(output, "three ");
			break;
		case '4':
			strcat(output, "four ");
			break;
		case '5':
			strcat(output, "five ");
			break;
		case '6':
			strcat(output, "six ");
			break;
		case '7':
			strcat(output, "seven ");
			break;
		case '8':
			strcat(output, "eight ");
			break;
		case '9':
			strcat(output, "nine ");
			break;
		default:
			printf("Unknown operator %c\n",user_input[strlen(user_input)-1]);
	}
	return(0);
}

/* counts the teens and values */
int teens_counting(pos)
{	
	switch(user_input[strlen(user_input)- pos]) {
		case '0':
			strcat(output, "ten ");
			break;
		case '1':
			strcat(output, "eleven ");
			break;
		case '2':
			strcat(output, "twelve ");
			break;
		case '3':
			strcat(output, "thirteen ");
			break;
		case '4':
			strcat(output, "fourteen ");
			break;
		case '5':
			strcat(output, "fifteen ");
			break;
		case '6':
			strcat(output, "sixteen ");
			break;
		case '7':
			strcat(output, "seventeen ");
			break;
		case '8':
			strcat(output, "eighteen ");
			break;
		case '9':
			strcat(output, "nineteen ");
			break;
		default:
			printf("Unknown operator %c\n",user_input[strlen(user_input)-1]);
	}
	return(0);
}

int main(){
	user_value = 0;
	inputs = 0;
	
	while(1){
		if (inputs == 0){
			printf("Program converts positive numbers into text form\n");
			printf("Enter q or Q to quit\n\n");
		}
		if (inputs > 0){
			//printf("DEBUG: user_input[0]: %c\n", user_input[0]);
			//printf("DEBUG: strlen(user_input)-2 = %d\n", strlen(user_input)-2);
			//printf("DEBUG: user_input[strlen(user_input)] = %c\n",user_input[strlen(user_input)]);
			//printf("DEBUG: user_input[1] = %c\n",user_input[1]);
			printf("%d =%s\n", user_value, output);
		}
		
		strcpy(output," "); /*resets output each run*/
		printf("Enter number: ");
		
		fgets(user_input, sizeof(user_input), stdin);
		sscanf(user_input, "%d", &user_value);
		/* trim off last character */
		user_input[strlen(user_input)-1] = '\0';
		
		if ((user_input[0] == 'q') || (user_input[0] == 'Q'))
			break;
		
		if (user_value >= 0){
		
			/* For the thousands place */
			if (user_value >= 1000){
				simple_counting(4);
				if(user_input[strlen(user_input) - 4] != '0')
					strcat(output, "thousand ");
			}
			
			/* For the hundreds place */
			if (user_value >= 100){
				simple_counting(3);
				if(user_input[strlen(user_input)- 3] != '0')
					strcat(output, "hundred ");
			}
			
			/* For the tens place - note maybe add hyphen somewhere*/
			if (user_value >= 10){
				switch(user_input[strlen(user_input)-2]) {
					case '0':
						if(user_value%10 !=0)
							strcat(output, "and");
						break;
					case '1':
						if(user_value<20){
							teens_counting(1);
							break;
						}
						strcat(output, "tens are in progress ");
						break;
					case '2':
						strcat(output, "twenty");
						break;
					case '3':
						strcat(output, "thirty");
						break;
					case '4':
						strcat(output, "fourty");
						break;
					case '5':
						strcat(output, "fifty");
						break;
					case '6':
						strcat(output, "sixty");
						break;
					case '7':
						strcat(output, "seventy");
						break;
					case '8':
						strcat(output, "eighty");
						break;
					case '9':
						strcat(output, "ninety");
						break;
					default:
						printf("Unknown operator %c\n",user_input[strlen(user_input)-1]);
				}
				if (user_value > 19){
					if((user_input[strlen(user_input)-1] != '0') && (user_input[strlen(user_input)-2]!='0'))
						strcat(output,"-");
					else
						strcat(output," ");
				}
			}
			
			if ((user_value < 10) || (user_value > 19))
			simple_counting(1);
			
			if (user_value == 0)
				strcat(output, "i'm positive it's zero");
			
			++inputs;
		}
	else {
		printf("Invalid input\n");
		inputs = 0;
	}
	}
	return(0);
}
			
		

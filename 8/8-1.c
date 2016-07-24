/********************************************************************
 *  Program for Exercise 8-1: Print a checker board (8-by-8 grid)	*
 * 																	*
 *  Notes: 	Changed it to print off user input instead of just 8x8	*
 * 			Each rectangle should be 5-by-3 characters.				*
 * 																	*
 *	Example: +-----+-----+											*
 * 			 |     |     |											*
 * 			 |     |     |											*
 * 			 |     |     |											*
 * 			 +-----+-----+											*
 * 																	*
 * 																	*
 *******************************************************************/
 #include<stdio.h>
 
 int	x_boxes;		/* # of horizontal boxes */
 int	y_boxes;		/* # of vertical boxes */
 int	counter_out;	/* outer loop counter */
 int	counter_in;		/* inner loop counter */
 int	counter_in2;	/* 3rd inner loop counter */
 int	x_boxes_input;	/* User input # horizontal boxes */
 int	y_boxes_input;	/* User input # vertical boxes */
 int	i;				/* Used for internal loop counting */
  
 char	line[6];	/* Input from keyboard */
 
 int main()
 {	/* use inputs #boxes in the x and y direction */
	printf("Enter #boxes (horizontal vertical): ");	
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%d %d", &x_boxes_input, &y_boxes_input);
	/*store user values */
	x_boxes = x_boxes_input + 1;
	y_boxes = y_boxes_input + 1;
	
	for (counter_out = 0; counter_out < y_boxes; ++counter_out){
		/* Top:loops # of horizontal box times */
		for (counter_in = 0; counter_in < x_boxes; ++counter_in){
			/* If statement allows top to be closed */
			if(counter_in < (x_boxes - 1))
				printf("+-----");
			else 
				printf("+\n"); /* closes/ends repeating top */
		}
		 
		/* stops vertical segment early for base to be built */
		if (counter_out + 1 < y_boxes ){		
			/* Builds the height of vertical segment */
			for (counter_in = 0; counter_in < 3; ++counter_in){
				/* Builds the row of the vertical segments */
				for (counter_in2 = 0; counter_in2 < x_boxes; ++counter_in2) {
					/* Gets rid of spaces at end of last square */
					if(counter_in2 < (x_boxes - 1))
						printf("|     ");
					else
						printf("|\n");
				}
			}
		}	
	}
	return (0);
}
	

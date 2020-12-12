#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*
--- Day 12: Rain Risk ---

Your ferry made decent progress toward the island, but the storm came in faster than anyone expected. The ferry needs to take evasive actions!

Unfortunately, the ship's navigation computer seems to be malfunctioning; rather than giving a route directly to safety, it produced extremely circuitous instructions. When the captain uses the PA system to ask if anyone can help, you quickly volunteer.

The navigation instructions (your puzzle input) consists of a sequence of single-character actions paired with integer input values. After staring at them for a few minutes, you work out what they probably mean:

    Action N means to move north by the given value.
    Action S means to move south by the given value.
    Action E means to move east by the given value.
    Action W means to move west by the given value.
    Action L means to turn left the given number of degrees.
    Action R means to turn right the given number of degrees.
    Action F means to move forward by the given value in the direction the ship is currently facing.

The ship starts by facing east. Only the L and R actions change the direction the ship is facing. (That is, if the ship is facing east and the next instruction is N10, the ship would move north 10 units, but would still move east if the following action were F.)

For example:

F10
N3
F7
R90
F11

These instructions would be handled as follows:

    F10 would move the ship 10 units east (because the ship starts by facing east) to east 10, north 0.
    N3 would move the ship 3 units north to east 10, north 3.
    F7 would move the ship another 7 units east (because the ship is still facing east) to east 17, north 3.
    R90 would cause the ship to turn right by 90 degrees and face south; it remains at east 17, north 3.
    F11 would move the ship 11 units south to east 17, south 8.

At the end of these instructions, the ship's Manhattan distance (sum of the absolute values of its east/west position and its north/south position) from its starting position is 17 + 8 = 25.

Figure out where the navigation instructions lead. What is the Manhattan distance between that location and the ship's starting position?

*/
#define COLUMN  10
char test[5][COLUMN] = {
"F10",
"N3",
"F7",
"R90",
"F11",
};

char sample[783][COLUMN] = {"L90","F82","R90","F57","L90","F21","W4","S2","L90","W5","R90","F84","E1","R90","S4","F13","E3","N2","W4","F33","W1","F48","E4","F86","R90","S3","F58","S4","F86","R270","N1","L270","S5","R90","E4","L90","F72","S4","W3","S1","F85","N5","R180","F8","S5","R90","N5","F18","R90","S4","F62","W1","F19","E3","L90","E3","F3","R180","E3","N1","F49","E5","N5","L90","E4","F52","N1","W1","N3","F84","W1","W5","F32","S2","E1","L180","W3","F79","N1","W3","F17","S5","E5","F40","N4","F37","N2","R180","N1","E5","F57","E4","F23","N1","W4","L90","F21","N2","R90","S4","R180","W4","N4","R180","W3","N5","L90","F10","F70","S1","F32","R90","F82","W5","W2","L90","F74","L90","F59","S3","L90","N4","L90","E5","F46","E2","F90","W3","L90","E4","R90","W1","F84","L90","W4","N3","E1","L90","W3","F51","L180","F27","R90","S2","W3","L90","N3","L90","S4","F31","W2","F42","R180","F97","E5","S2","W5","L90","E2","L90","E5","S1","F22","L90","F26","W5","R180","F10","N1","F9","R90","W2","W2","N1","F61","R180","W1","N4","L90","W3","S2","E2","L180","F24","L90","E1","L90","N5","F56","R180","W1","S3","F32","L90","F58","E5","R90","F74","N5","R90","S4","F58","L90","F91","S5","R90","F16","N4","R270","F38","W2","R90","W3","R90","F51","E5","F54","N5","F46","R90","W3","R90","W3","F59","R90","N4","F86","N1","E4","N3","W2","N4","E5","R90","F35","L90","E1","S4","W1","S3","F3","L180","E5","F49","N2","F67","L90","S1","R90","E3","F100","L180","E4","N3","F95","L180","N2","E3","N4","L90","N1","L90","F9","L90","F21","N2","F24","L90","W1","F43","W3","F63","N5","R90","S3","F64","R180","R180","N2","F91","W1","S5","E4","R90","F77","W2","N3","F16","S2","F10","N5","F36","R90","S3","F34","R270","R90","F45","N5","R90","F37","S5","R90","W3","S4","F11","S1","R90","W3","R90","S4","W5","N3","F25","S1","N4","W4","R90","N2","L270","F82","N2","F71","E2","F54","L90","S2","F26","E2","F94","S3","F73","R90","S2","F32","N5","F57","E1","R90","W3","S5","E4","L90","S4","W2","R90","E3","R180","F56","N5","F89","F57","F32","E2","S2","F94","N4","L90","F98","R90","S2","L90","L90","N5","L90","F47","W1","L270","F32","N3","N3","W3","F70","S5","W3","F40","S1","E5","L180","E1","N2","E3","R90","F76","S4","W1","R90","F49","S1","F84","W5","F85","L270","R90","E2","R90","E2","W4","R90","W3","L90","F67","R90","N3","W4","R180","F15","S4","R90","F1","L270","S3","E4","R90","L90","N4","E5","F25","W4","W3","N3","L90","N4","L180","W2","N2","F96","R90","E2","N4","R90","W2","F86","F35","W3","S5","L180","W2","L90","W4","N3","L90","W5","F79","W4","R180","F16","W3","S5","W5","N5","F39","S3","F76","S3","F78","W3","F99","N3","F69","S3","E2","S5","R180","F29","R90","F65","N3","E4","F5","R90","E1","F77","N3","W4","F57","E4","L90","N5","R180","S3","W1","R90","S2","F26","S2","L90","S2","F88","S2","R90","S5","N3","L180","F22","E1","F23","L90","R90","N3","W5","R90","W2","F41","L90","F70","F35","R180","F37","E5","R90","E1","S3","F41","L90","E3","F80","S1","F53","R90","N3","R90","F94","N3","R90","F79","R270","F38","L90","E1","L90","E1","F64","N4","F78","S5","E1","N3","L90","E4","S5","E5","L90","S3","F72","L90","F15","L180","E5","S3","L90","S3","E2","L90","F49","N1","L90","W3","N2","F32","R90","F47","E2","S3","E4","F23","L270","E3","R90","S5","F58","E4","S4","F81","R90","E3","R90","F66","W5","F35","S5","E4","R90","F29","W3","F76","E5","S2","F76","N4","F93","L90","E3","R90","F35","L90","F13","R90","S3","R90","N3","L90","F87","E2","N4","F86","R90","N1","L180","E1","S3","F34","E4","F31","E5","F57","S4","L90","W3","L90","S3","R90","F56","S2","W4","S5","F21","S2","L180","W5","S2","L90","F53","S1","N3","E4","R90","E4","L180","S4","E5","L180","S3","F48","S3","F24","S5","L90","E3","F53","N2","F30","L90","E5","F51","S1","L90","S1","E1","L90","F11","N2","R180","F41","N5","F72","L90","F90","N3","F7","W2","R180","E2","L180","E4","S3","F23","R90","F72","W1","L90","N1","E3","F3","E4","R180","L180","N2","F83","W1","L90","W3","N2","F27","W3","N2","R90","N5","E2","F93","L90","F51","N3","W5","S4","W3","R90","F24","R270","N1","R90","F34","R90","W2","F91","S5","L90","S1","F14","R180","S4","W3","N4","R90","N1","W3","F66","R180","S3","E1","L90","F76","N2","W3","S3","F87","E4","L180","N2","L90","N1","E2","S3","F63","W1","F90","S3","L270","E4","F19","R90","E5","L180","S1","R90","F45","R90","S5","L90","F21","R180","F29","N5","E3","R180","F9","R90","E4","F94","S4","F79","E1","L90","N3","F96","E4","F32","E3","R270","N5","R180","E5","F46"};
typedef enum direction_e {
	E = 0,
	N,
	W,
	S,
} direction_e_t;

int positions_sum(char* data, int num_lines)
{
		int units[4] = {0};
		direction_e_t facing = E;
		for (size_t i  = 0; i < num_lines; i++ ) {
			char* line = data;
			char ch = *line; 
			line++;
			int value = atoi(line);
            
			if (ch == 'F') {
				units[facing] +=  value;
			}
			else if(ch == 'R') {
				int dir = value/90;
			    dir = 4- dir;
        		facing =  (facing	+ dir) % 4;	
			}
			else  if(ch == 'L') {
				int dir = value/90;
        		facing =  (facing +  dir) % 4;	
			}
			else if(ch == 'E') {
				units[E] +=  value;
			}
			else if(ch == 'N') {
				units[N] +=  value;
			}
			else if(ch == 'W') {
				units[W] +=  value;
			}
			else if(ch == 'S') {
				units[S] +=  value;
			}
			else {
				printf("Something strange dude\n");
			}
			data = data +  COLUMN;
		}
		printf(" E %u N %u W %u S %u \n", units[E], units[N], units[W], units[S]);
		return (abs(units[E] - units[W]) + abs(units[N] - units[S]));
}

int positions_sum_waypoint_move(char* data, int num_lines)
{
		int units[4] = {0};
		int wayponts[4] = {10, 1, 0, 0};
		direction_e_t facing = E;
		for (size_t i  = 0; i < num_lines; i++ ) {
			char* line = data;
			char ch = *line; 
			line++;
			int value = atoi(line);
            
			if (ch == 'F') {
				for (int j =0 ; j< 4; j++) {
					units[j]  +=  value * wayponts[j] ;
				}
			}
			else if(ch == 'R') {
				int dir = value/90;
				int temp[4]  = {0};
				for (int j =0 ; j< 4; j++) {
					temp[j] = wayponts[j];
				}
				for (int j =0 ; j< 4; j++) {
					wayponts[j] =  temp[(j+ dir) % 4] ;
				}
				
			}
			else  if(ch == 'L') {
				int dir = value/90;
				dir = 4- dir;
				int temp[4]  = {0};
				for (int j  =0 ; j< 4; j++) {
					temp[j] = wayponts[j];
				}
				for (int j =0 ; j< 4; j++) {
					wayponts[j] =  temp[(j+ dir) % 4] ;
				}
			}
			else if(ch == 'E') {
				wayponts[E] +=  value;
			}
			else if(ch == 'N') {
				wayponts[N] +=  value;
			}
			else if(ch == 'W') {
				wayponts[W] +=  value;
			}
			else if(ch == 'S') {
				wayponts[S] +=  value;
			}
			else {
				printf("Something strange dude\n");
			}
			data = data +  COLUMN;
		}
		printf(" E %u N %u W %u S %u \n", units[E], units[N], units[W], units[S]);
		return (abs(units[E] - units[W]) + abs(units[N] - units[S]));
}

int main(void) 
{
	
	printf("Sum %u\n", positions_sum((char*)test, 5));
    printf("Sum %u\n", positions_sum((char*)sample, 783));
	
    printf("Sum %u\n", positions_sum_waypoint_move((char*)test, 5));
	 printf("Sum %u\n", positions_sum_waypoint_move((char*)sample, 783));
	return 0;
}
/*
 * Created on: June 04 2019
 * Created by: Matthew Lourenco
 * This file calculates the solution(s) to the quadratic formula 
 * Ax^2 + Bx + C = 0
 * given Coefficients A, B, and C 
 */

#include <stdio.h>
#include <math.h>

//This function displays a message then recieves the respose
double getRealInput(char *message) {
	double response = 0.0;
	
	printf(message);
	scanf("%lf", &response);
	
	return response;
}

int main(int argc, char **argv)
{
	double A = 0.0, B = 0.0, C = 0.0;
	
	printf("Let the form of the quadratic function be: Ax^2 + Bx + C\n\n");
	
	A = getRealInput("Input A: ");
	B = getRealInput("Input B: ");
	C = getRealInput("Input C: ");
	
	printf("A: %.12lf\nB: %.12lf\nC: %.12lf\n", A, B, C);
	return 0;
}

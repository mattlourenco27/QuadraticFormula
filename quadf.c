/*
 * Created on: June 04 2019
 * Created by: Matthew Lourenco
 * This file calculates the solution(s) to the quadratic formula 
 * Ax^2 + Bx + C = 0
 * given Coefficients A, B, and C 
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

//This function displays a message then recieves the respose
double getRealInput(char *message) {
	double response = 0.0;
	
	printf(message);
	scanf("%lf", &response);
	
	return response;
}

//This function calculates the discriminant given A, B, C
double discriminant(double A, double B, double C) {
	return pow(B,2) - (4 * A * C);
}

//This function calculates the solution to the quadratic formula with two solutions
//'pos' dictates if it uses the plus or minus variant of the formula
double twoSolution(double A, double B, double C, bool pos) {
	if(pos) {
		return (-B + sqrt(discriminant(A, B, C))) / (2 * A);
	} else {
		return (-B - sqrt(discriminant(A, B, C))) / (2 * A);
	}
}

//This function calculates the solution to the quadratic formula with one solution
double oneSolution(double A, double B) {
	return -B / (2 * A);
}

//This function calculates the solution to the quadratic formula with two imaginary solutions
//The pointer '*img' points to the value of the imaginary component
double imaginarySolutions(double A, double B, double C, double *img) {
	*img = sqrt(-discriminant(A, B, C)) / (2 * A);
	return -B / (2 * A); 
}

//This funtion runs the closing procedure
void close(void) {
	printf("Press ENTER key to Continue\n");  
	getchar(); //Existing Enter key from previous inputs
	getchar();
	return;
}

int main(int argc, char **argv) {
	double A = 0.0, B = 0.0, C = 0.0;
	double discr = 0.0;
	
	unsigned const char PLUS_OR_MINUS= 241;
	
	//Switch stout to unbuffered mode to fix scan before inputs
	setvbuf(stdout, 0, _IONBF, 0);

	printf("Let the form of the quadratic function be: Ax^2 + Bx + C\n\n");
	
	A = getRealInput("Input A: ");

	if (A == 0) {
<<<<<<< HEAD
		printf("Error: Function is not quadratic;\n");
		close();
		return 0;
=======
>>>>>>> DivisionByZero
	}

	B = getRealInput("Input B: ");
	C = getRealInput("Input C: ");
	
	//printf("\nA: %.12lf\nB: %.12lf\nC: %.12lf\n", A, B, C);
	
	discr = discriminant(A, B, C);
	//printf("\nThe discriminant is: %.12lf\n", discr);
	
	if (discr > 0) {
		
		double posSol = twoSolution(A, B, C, true);
		double negSol = twoSolution(A, B, C, false);
		
		printf("\nSolution(+): %.12lf\nSolution(-): %.12lf\n", posSol, negSol);
	} else if (discr == 0) {
		
		double sol = oneSolution(A, B);
		
		printf("\nSingle Solution: %.12lf\n", sol);
	} else {
		
		double imgSol = 0.0;
		double realSol = imaginarySolutions(A, B, C, &imgSol);
		
		printf("\nReal Component: %.12lf\nImaginary Component: %.12lf\n\n%.12lf %c i%.12lf\n",
			   realSol, imgSol, realSol, PLUS_OR_MINUS, imgSol);
	}
	
	close();
	return 0;
}

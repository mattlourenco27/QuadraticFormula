/*
 * Created on: June 04 2019
 * Created by: Matthew Lourenco
 * This file calculates the solution(s) to the quadratic formula 
 * Ax^2 + Bx + C = 0
 * given Coefficients A, B, and C
 * 
 * Edited: June 23 2019
 * Changed file to a header file to be implemented in other programs
 *
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

//This function calculates the discriminant given A, B, C
static double discriminant(double A, double B, double C) {
	return pow(B,2) - (4 * A * C);
}

//This function calculates the solution to the quadratic formula with two solutions
//'pos' dictates if it uses the plus or minus variant of the formula
static double twoSolution(double A, double B, double C, bool pos) {
	if(pos) {
		return (-B + sqrt(discriminant(A, B, C))) / (2 * A);
	} else {
		return (-B - sqrt(discriminant(A, B, C))) / (2 * A);
	}
}

//This function calculates the solution to the quadratic formula with one solution
static double oneSolution(double A, double B) {
	return -B / (2 * A);
}

//This function calculates the solution to the quadratic formula with two imaginary solutions
//The pointer '*img' points to the value of the imaginary component
static double imaginarySolutions(double A, double B, double C, double *img) {
	*img = sqrt(-discriminant(A, B, C)) / (2 * A);
	return -B / (2 * A); 
}

//This function calculates and prints the quadratic formula
void quadf(double A, double B, double C) {
	double discr = 0.0;
	
	unsigned const char PLUS_OR_MINUS= 241;
	
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
		
		printf("\n%.12lf +- i%.12lf\n", realSol, imgSol);
	}
}
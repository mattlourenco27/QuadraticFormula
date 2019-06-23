# QuadraticFormula
Header file 'quadf.h' that can be imported
Calculates the solutions to the quadratic formula given the coefficients of a quadratic function as inputs

Define the coefficients Ax^2 + Bx + C

quadf(A, B, C, \*solution1, \*solution2, \*imaginary) calculates the two solutions. If the solutions are real then solution1 and solution2 are the two solutions. Imaginary will be false. If the solutions are imaginary then solution1 is the real component, solution2 is the imaginary component, and imaginary will be true.

pquadf(A, B, C) calculates the real or imaginary solutions and prints them

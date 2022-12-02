/*********************
**  Complex Numbers
**  This file contains a few functions that will be useful when performing computations with complex numbers
**  It is advised that you work on this part first.
**********************/

#include "ComplexNumber.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct ComplexNumber
{
	double real;
	double imaginary;
}ComplexNumber;

//Returns a pointer to a new Complex Number with the given real and imaginary components
ComplexNumber* newComplexNumber(double real_component, double imaginary_component)
{
    //YOUR CODE HERE
    ComplexNumber* complexNumberPointer = malloc(sizeof(ComplexNumber));
    complexNumberPointer -> real = real_component;
    complexNumberPointer -> imaginary = imaginary_component;

	return complexNumberPointer;
}

//Returns a pointer to a new Complex Number equal to a*b
ComplexNumber* ComplexProduct(ComplexNumber* a, ComplexNumber* b)
{
    ComplexNumber* complexNumberPointer = malloc(sizeof(ComplexNumber));
    complexNumberPointer->real = a->real * b->real - a->imaginary * b->imaginary;
    complexNumberPointer->imaginary = a->real * b->imaginary + a->imaginary * b->real;
    return complexNumberPointer;
}

//Returns a pointer to a new Complex Number equal to a+b
ComplexNumber* ComplexSum(ComplexNumber* a, ComplexNumber* b)
{
    ComplexNumber* complexNumberPointer = malloc(sizeof(ComplexNumber));
    complexNumberPointer->real = a->real + b->real;
    complexNumberPointer->imaginary = b->imaginary + b->imaginary;
    return complexNumberPointer;
}

//Returns the absolute value of Complex Number a
double ComplexAbs(ComplexNumber* a)
{
    return sqrt(a->real*a->real + a->imaginary*a->imaginary);
}

void freeComplexNumber(ComplexNumber* a)
{
	free(a);
    //YOUR CODE HERE
}

double Re(ComplexNumber* a)
{
	//YOUR CODE HERE
    return a -> real;
//	return 0;
}
double Im(ComplexNumber* a)
{
    return a -> imaginary;
}


//Contains a few tests.
int test_complex_number()
{
	ComplexNumber* a = newComplexNumber(2.0, 1.0);
	if (a == NULL)
	{
		printf("Creation of complex numbers not implemented\n");
		return 0;
	}
	ComplexNumber* b = ComplexProduct(a, a);
	if (b == NULL)
	{
		printf("Multiplication of complex numbers not implemented\n");
		free(a);
		return 0;
	}
	ComplexNumber* c = ComplexSum(b, b);
	if (c == NULL)
	{
		printf("Addition of complex numbers not implemented\n");
		free(a);
		free(b);
		return 0;
	}
	float d = ComplexAbs(c);
	if (d == 0)
	{
		printf("Absolute Value of complex numbers not implemented\n");
		free(a);
		free(b);
		free(c);
		return 0;
	}
	else if (fabsf(d - 10) < 0.0001)
	{
		printf("Sample tests for complex numbers all passed\n");
	}
	else
	{
		printf("At least one of your functions is incorrect\n");
	}
	free(a);
	free(b);
	free(c);
	return 0;
}

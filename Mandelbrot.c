/*********************
**  Mandelbrot fractal
** clang -Xpreprocessor -fopenmp -lomp -o Mandelbrot Mandelbrot.c
** by Dan Garcia <ddgarcia@cs.berkeley.edu>
** Modified for this class by Justin Yokota and Chenyu Shi
**********************/

#include <stdio.h>
#include <stdlib.h>
#include "ComplexNumber.h"
#include "Mandelbrot.h"
#include <sys/types.h>

/*
This function returns the number of iterations before the initial point >= the threshold.
If the threshold is not exceeded after maxiters, the function returns 0.
*/
u_int64_t MandelbrotIterations(u_int64_t maxiters, ComplexNumber * point, double threshold)
{
//    double real_component = point -> real;
//    double imaginary_component = point -> imaginary;
    ComplexNumber* node = newComplexNumber(0, 0 );
    for(int i = 0; i < maxiters; i++) {
        ComplexNumber* product_node = ComplexProduct(node, node);
        ComplexNumber* sum_node = ComplexSum(product_node, point);
        free(product_node);
        free(sum_node);
        if (ComplexAbs(sum_node) > threshold) {
            free(node);
            return i;
        }
    }
    free(node);
//    free(product_node);
//    free(sum_node);
    return 0;
}

/*
This function calculates the Mandelbrot plot and stores the result in output.
The number of pixels in the image is resolution * 2 + 1 in one row/column. It's a square image.
Scale is the distance between center and the top pixel in one dimension.
*/
void Mandelbrot(double threshold, u_int64_t max_iterations, ComplexNumber* center, double scale, u_int64_t resolution, u_int64_t *output){
    int size = 2 * resolution + 1;
    u_int64_t temp_result;
//    ComplexNumber* point = malloc(sizeof(ComplexNumber));
    for(int i = Re(center) - scale; i <= Re(center) + scale; i += scale/resolution ){
        for (int j = Im(center) - scale; j <= Im(center) + scale; j += scale/resolution ){
            ComplexNumber* point = newComplexNumber(i, j );
            temp_result = MandelbrotIterations(max_iterations, point, threshold);
            output[i*size + j] =  temp_result;
            free(point);
        }
    }

    //YOUR CODE HERE
}



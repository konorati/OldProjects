#ifndef EQUATIONS_H_INCLUDED
#define EQUATIONS_H_INCLUDED
#include<math.h>
#include<stdio.h>
#define PI 3.14159 
#define NUMERATOR 10
#define DENOMINATOR 15
#define LOWER_A 'a'
#define UPPER_A 'A'

double calculate_newtons_2nd_law(double, double);
double calculate_volume_cylinder(double, double);
char character_encoding(char);
double calculate_distance_between_2pts(double, double, double, double);
double calculate_tangent_theta(double);
double calculate_gauss_lens(double, double);
double calculate_general_equation(int, double, double);

#endif
#include "equations.h"

/*************************************************************************
* Date last modified: Jan 30th, 2013
* Description: Calculates the force using Newtons second law
* Input parameters: mass(double) and acceleration(double)
* Returns: force(double)
* Precondition: Must have mass and acceleration
* Postcondition: force is calculated and returned
*************************************************************************/
double calculate_newtons_2nd_law(double mass, double acceleration){
	double force = mass*acceleration;
	return force;
}

/*************************************************************************
* Date last modified: Jan 30th, 2013
* Description: Calculates the volume of a cylinder
* Input parameters: radius(double) and height(double)
* Returns: volume(double)
* Precondition: Must have radius and height, PI must be defined
* Postcondition: volume is calculated and returned
*************************************************************************/
double calculate_volume_cylinder(double radius, double height){
	double volume = PI*radius*radius*height;
	return volume;
}

/*************************************************************************
* Date last modified: Jan 30th, 2013
* Description: Changes a plaintext character into an encoded character
* Input parameters: plaintext character a-z or A-z(char)
* Returns: encoded character(char)
* Precondition: Must have a character
* Postcondition: character is encoded and returned
*************************************************************************/
char character_encoding(char plaintext_character){
	char encoded_character = plaintext_character - LOWER_A + UPPER_A;
	return encoded_character;
}

/*************************************************************************
* Date last modified: Jan 30th, 2013
* Description: Calculates the distance between 2 points
* Input parameters: x value for point 1(double), x value for point 2(double),
				y value for point 1(double), y value for point 2(double)
* Returns: distance(double)
* Precondition: Must have 2 points (x & y values)
* Postcondition: distance is calculated and returned
*************************************************************************/
double calculate_distance_between_2pts(double x1, double x2, double y1, double y2){
	double distance = sqrt((x1 - x2)*(x1-x2)+(y1-y2)*(y1-y2));
	return distance;
}

/*************************************************************************
* Date last modified: Jan 30th, 2013
* Description: Calculates the tangent of an angle
* Input parameters: angle in degrees (double)
* Returns: tangent of angle(double)
* Precondition: Must have an angle in degrees
* Postcondition: tangent is calculated and returned
*************************************************************************/
double calculate_tangent_theta(double theta){
	double tangent = (sin(theta)/cos(theta));
	return tangent;
}

/*************************************************************************
* Date last modified: Jan 30th, 2013
* Description: Calculates the focal length using Gauss lens formula
* Input parameters: object distance(double) and image distance(double)
* Returns: focal length(double)
* Precondition: Must have non-zero object distance and non-zero image distance
* Postcondition: focal length is calculated and returned
*************************************************************************/
double calculate_gauss_lens(double object_distance, double image_distance){
	double focalLength = (1/((1/object_distance)+(1/image_distance)));
	return focalLength;
}

/*************************************************************************
* Date last modified: Jan 30th, 2013
* Description: Calculates the value of an equation
* Input parameters: a(any int), x(double), z(double)
* Returns: y(double)
* Precondition: a must be odd
* Postcondition: y is calculated and returned
*************************************************************************/
double calculate_general_equation(int a, double x, double z){
	double y = ((double)10/15) - x + z * a/(a%2);
	return y;
}
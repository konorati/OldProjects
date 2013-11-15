/*
	Programmer: Kristin Onorati
	Class: CPTS 121, Spring 2013, Lab Section 1
	Programming Assignment: 1
	Date: January 23, 2013
	Description: This program prompts user for input, uses the input to 
	  calculate variables based on scientific and mathematical formulas
	  and displays calculated variables to user. 
*/

#include<stdio.h>
#include<math.h>
#define PI 3.14159 
#define NUMERATOR 10
#define DENOMINATOR 15
#define LOWER_A 'a'
#define UPPER_A 'A'

int main(void)
{
	//Declare variables
	double mass = 0, acceleration = 0, force = 0, height = 0,
		radius = 0, volume = 0, x1 = 0, x2 = 0, y1 = 0, y2 = 0,
		distance = 0, theta = 0, tangent = 0, objectDistance = 0,
		imageDistance = 0, focalLength = 0, x = 0, y = 0, z = 0;
	char plaintext_character = '\0', encoded_character = '\0';
	int a = 0;

	/* Problem 1 */
	//Prompt user to input mass & acceleration
	printf("\nEnter the mass and acceleration of the object for use in Newton's second law: ");
	scanf("%lf%lf", &mass, &acceleration);

	//Calculate force
	force = mass*acceleration;

	//Display force
	printf("Force = mass * acceleration = %.2f * %.2f = %.2f Newtons\n", mass, acceleration, force);

	/* Problem 2 */
	//Prompt user to input radius & height of cylinder
	printf("\nEnter the radius and height of the cylinder to find the volume: ");
	scanf("%lf%lf", &radius, &height);

	//Calculate volume of cylinder
	volume = PI*radius*radius*height;

	//Display volume of cylinder
	printf("Volume = PI * radius^2 * height = %.5f * %.2f^2 * %.2f = %.2f\n", PI, radius, height, volume);

	/* Problem 3 */
	//Prompt user to input plain text character
	printf("\nEnter a character (a-z): ");
	scanf(" %c", &plaintext_character);

	//Convert plain text character to encoded character
	encoded_character = plaintext_character - LOWER_A + UPPER_A;

	//Display new character
	printf("The new encoded character is %c\n", encoded_character);

	/* Problem 4 */
	//Prompt user to input 2 data points
	printf("\nEnter the first data point with a space between\nthe X and Y coordinates(X Y) to find the distance between two points: ");
	scanf("%lf%lf", &x1, &y1);
	printf("\nEnter the second data point with a space between\nthe X and Y coordinates(X Y) to find the distance between two points: ");
	scanf("%lf%lf", &x2, &y2);

	//Calculate the distance between the two points
	distance = sqrt((x1 - x2)*(x1-x2)+(y1-y2)*(y1-y2));

	//Display the distance between the two data points
	printf("\nDistance = sqrt((x1-x2)^2 + (y1-y2)^2) = sqrt((%.2f-%.2f)^2 + (%.2f-%.2f)^2) = %.2f\n", x1, y1, x2, y2, distance);

	/* Problem 5 */
	//Prompt user for theta to calculate the tangent
	printf("\nEnter an angle (in degrees) to calculate the tangent of that angle: ");
	scanf("%lf", &theta);

	//Calculate the tangent of the theta
	tangent = (sin((theta*PI)/180)/cos((theta*PI)/180));

	//Display the tangent of theta
	printf("Tangent = sin((theta * PI)/180) / cos((theta * PI)/180) = sin((%.5f * %.2f)/180) / cos((%.5f * %.2f)/180) =  %.2f\n", theta, PI, theta, PI, tangent);

	/* Problem 6 */
	//Prompt user for the imageDistance and objectDistance
	printf("\nEnter the image distance and object distance (both floating-point values)\n to calculate focal length using the Gauss Lens Formula: ");
	scanf("%lf%lf", &imageDistance, &objectDistance);

	//Calculate the focal length
	focalLength = (1/((1/objectDistance)+(1/imageDistance)));

	//Display focal length of the lens
	printf("Focal length = 1 / ((1 / Object Distance) + (1 / Image Distance))\n\t = 1 / ((1 / %.2f) + (1 / %.2f)) =  %.2f\n", objectDistance, imageDistance, focalLength);

	/* Problem 7 */
	//Prompt user for the variables x, z, and a
	printf("\nEnter two floating point numbers and one integer (in that order): ");
	scanf("%lf%lf%d", &x, &z, &a);

	//Calculate equation
	y = ((double)10/15) - x + (z * a)/(a%2);

	//Display result of equation
	printf("Y = (10/15) - x + (z * a)/(a %% 2) = (10/15) - %.2f + (%.2f * %d)/(%d %% 2) =  %.2f\n", x, z, a, a, y);

	return 0;
}
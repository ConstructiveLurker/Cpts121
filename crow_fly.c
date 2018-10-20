/*
 * Programmer: Tyler Avery
 * Class: Cpts 121, Fall 2018
 * Programming Lab: 05
 * Date: September 21, 2018
 *
 * Description: Find the distance between two coordinates.
*/

#include <stdio.h>
#include <math.h>

#define MINUTES 60
#define SECONDS 3600

double dms_to_radians (double dms[3]);
void polar_to_cartesian (double latitude[3], double longitude[3], double position[3]);
double arc_length (double latitude0[3], double longitude0[3], double latitude1[3], double longitude1[3]);
double crow_fly (double latitude0[3], double longitude0[3], double latitude1[3], double longitude1[3]);

int main (void)
{
	double latitude0[3], longitude0[3];
	double latitude1[3], longitude1[3];

	printf ("From latitude (degrees, minutes, seconds): ");
	scanf ("%lf %lf %lf", &latitude0[0], &latitude0[1], &latitude0[2]);

	printf ("From longitude (degrees, minutes, seconds): ");
	scanf ("%lf %lf %lf", &longitude0[0], &longitude0[1], &longitude0[2]);

	printf ("To latitude (degrees, minutes, seconds): ");
	scanf ("%lf %lf %lf", &latitude1[0], &latitude1[1], &latitude1[2]);

	printf ("To longitude (degrees, minutes, seconds): ");
	scanf ("%lf %lf %lf", &longitude1[0], &longitude1[1], &longitude1[2]);

	printf ("Distance: %.1f kilometers.\n", crow_fly (latitude0, longitude0, latitude1, longitude1));
	
	return 0;
}

// convert degrees, minutes, and seconds into a single double value
double dms_to_radians (double dms[3])
{
        double degree = 0.0, radian = 0.0;

        degree = dms[0] + (dms[1]/MINUTES) + (dms[2]/SECONDS);
        radian = degree * M_PI / 180;

        return radian;
}

// convert latitude and longitude to position
void polar_to_cartesian (double latitude[3], double longitude[3], double position[3])
{
        double theta = 0.0, phi = 0.0;

        theta = dms_to_radians (latitude);
        phi = dms_to_radians (longitude);

        position[0] = cos(theta)*cos(phi);
        position[1] = cos(theta)*sin(phi);
        position[2] = sin(theta);
}

// compute the arc of two points on a sphere
double arc_length (double latitude0[3], double longitude0[3], double latitude1[3], double longitude1[3])
{
        double position0[3], position1[3], cosine = 0.0;
        
	polar_to_cartesian(latitude0, longitude0, position0);
	polar_to_cartesian(latitude1, longitude1, position1);

        cosine = acos(position0[0] * position1[0] + position0[1] * position1[1]  + position0[2] * position1[2]);
        
        return cosine;
}

// computes and returns the distance between two points on earth in kilometers
double crow_fly (double latitude0[3], double longitude0[3], double latitude1[3], double longitude1[3])
{
        double arc = 0.0;
        double kilometers = 0.0;

        arc = arc_length (latitude0, longitude0, latitude1, longitude1);
        kilometers = arc * 6378;

        return kilometers;
}


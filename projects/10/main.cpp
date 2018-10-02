/* 	main.cpp is a driver for an ImageConverter program
 *  using OpenMP to parallelize the image processing
 *  and TSGL to view the processing in near real time.
 *
 * Author: Joel Adams, for CS 112 at Calvin College.
 * Student: Ian Christensen
 * Date: May 2, 2017
 */

#include "ImageConverter.h"

int main() {
	omp_set_num_threads(16);
	ImageConverter iConverter("pics/beads.jpg", 800, 800);
	iConverter.invertImage1();
	iConverter.invertImage2();
	iConverter.invertImage3();
}

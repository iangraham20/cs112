/* 	ImageConverter.cpp declares a class for
 *  various image conversion operations.
 *
 *  Author:  Joel Adams, CS112 @ Calvin College.
 *  Student: Ian Christensen
 *  Date: May 2, 2017
 */

#include "ImageConverter.h"

/* explicit constructor
 *
 * @param imageFileName, a string.
 * @param width, an int.
 * @param height, an int.
 *
 * Precondition: imageFileName contains the name of a valid image file
 *               && width > 0 && height > 0
 * Postcondition: myImageFileName == imageFileName
 *                && myWidth == width && myHeight = height
 *                && width x height Canvas containing the image
 *                    from imageFileName has been displayed on screen.
 */
ImageConverter::ImageConverter(const std::string& imageFileName, int width,
		int height) :
		myCanvas1(0, 0, width, height, imageFileName), myImageFileName(
				imageFileName), myWidth(width), myHeight(height) {
	myCanvas1.start();
	myCanvas1.drawImage(myImageFileName, 0, 0, width, height);
	sleep(1);
}

/* destructor
 *
 * Precondition: this ImageConverter object is going out of scope.
 * Postcondition: myCanvas1 has disappeared from the screen.
 */
ImageConverter::~ImageConverter() {
	myCanvas1.wait();
	cout << "\nImageConverter terminated normally." << endl;
}

/* GrayscaleSequential() converts the image from myImageFileName into black and white.
 *
 * Precondition: myCanvas1 contains a TSGL Image that is to be inverted
 *               && myWidth contains the number of columns in which to display the image
 *               && myHeight contains the number of rows in which to display the image.
 *
 * Postcondition: a myWidth x myHeight Canvas has been displayed
 *                 containing the inverse of the image from myCanvas1
 *                 (which contains the image from myImageFileName).
 */
void ImageConverter::GrayscaleSequential() {
	// record starting time
	double startTime = omp_get_wtime();
	Canvas canvas2(myWidth + 50, 0, myWidth, myHeight,
			myImageFileName + " GrayscaleSequential");
	canvas2.start();
	for (int row = 0; row < myHeight; row++) {
		// slow the processing to simulate a very large image
		canvas2.sleep();
		// loop through the image columns
		for (int col = 0; col < myWidth; col++) {
			// read the pixel at canvas1[row][col]
			ColorInt pixelColor = myCanvas1.getPixel(row, col);
			// compute its conversion
			int conversion = (0.3  *  pixelColor.R) + (0.59 *  pixelColor.G) + (0.11 *  pixelColor.B);
			// draw the conversion at the same spot in canvas2
			canvas2.drawPixel(row, col,
					ColorInt(conversion, conversion, conversion));
		} // inner for
	} // outer for
	// compute and display the time difference
	double totalTime = omp_get_wtime() - startTime;
	cout << "\n\nImage grayscale took " << totalTime << " seconds.\n" << endl;

    //save converted image
    canvas2.takeScreenShot();
	canvas2.wait();
} // GrayscaleSequential

/* GrayscaleParallel() converts the image from myImageFileName into black and white.
 *
 * Precondition: myCanvas1 contains a TSGL Image that is to be inverted
 *               && myWidth contains the number of columns in which to display the image
 *               && myHeight contains the number of rows in which to display the image.
 *
 * Postcondition: a myWidth x myHeight Canvas has been displayed
 *                 containing the inverse of the image from myCanvas1
 *                 (which contains the image from myImageFileName).
 */
void ImageConverter::GrayscaleParallel() {
	// record starting time
	double startTime = omp_get_wtime();
	Canvas canvas3(myWidth + 50, 0, myWidth, myHeight,
			myImageFileName + " Grayscale, Chunk-Size 1");
	canvas3.start();
	// launch additional threads
#pragma omp parallel
	{
		// how many workers do we have?
		unsigned numThreads = omp_get_num_threads();
		// which one am I?
		unsigned id = omp_get_thread_num();
		// loop through the image rows
		for (int row = id; row < myHeight; row += numThreads) {
			// slow the processing to simulate a very large image
			canvas3.sleep();
			// loop through the image columns
			for (int col = 0; col < myWidth; col++) {
				// read the pixel at canvas1[row][col]
				ColorInt pixelColor = myCanvas1.getPixel(row, col);
				// compute its conversion
				int conversion = (0.3  *  pixelColor.R) + (0.59 *  pixelColor.G) + (0.11 *  pixelColor.B);
				// draw the inverse at the same spot in canvas2
				canvas3.drawPixel(row, col,
						ColorInt(conversion, conversion, conversion));
			} // inner for
		} // outer for
	} // #pragma omp parallel
	// compute and display the time difference
	double totalTime = omp_get_wtime() - startTime;
	cout << "\n\nImage grayscale took " << totalTime << " seconds.\n" << endl;

    //save converted image
    canvas3.takeScreenShot();
	canvas3.wait();
} // GrayscaleParallel

/* VerticalSequential() flips the image from myImageFileName vertically.
 *
 * Precondition: myCanvas1 contains a TSGL Image that is to be inverted
 *               && myWidth contains the number of columns in which to display the image
 *               && myHeight contains the number of rows in which to display the image.
 *
 * Postcondition: a myWidth x myHeight Canvas has been displayed
 *                 containing the inverse of the image from myCanvas1
 *                 (which contains the image from myImageFileName).
 */
void ImageConverter::VerticalSequential() {
	// record starting time
	double startTime = omp_get_wtime();
	Canvas canvas4(myWidth + 50, 0, myWidth, myHeight,
			myImageFileName + " VerticalSequential");
	canvas4.start();
	for (int row = 0; row < myHeight; row++) {
		// slow the processing to simulate a very large image
		canvas4.sleep();
		// loop through the image columns
		for (int col = 0; col < myWidth; col++) {
			// read the pixel at canvas1[row][col]
			ColorInt pixelColor = myCanvas1.getPixel(row, col);
			// draw the conversion at the inverted spot in canvas2
			canvas4.drawPixel(myHeight - row, col,
					ColorInt(pixelColor.R, pixelColor.G, pixelColor.B));
		} // inner for
	} // outer for
	// compute and display the time difference
	double totalTime = omp_get_wtime() - startTime;
	cout << "\n\nImage vertical took " << totalTime << " seconds.\n" << endl;

    //save converted image
    canvas4.takeScreenShot();
	canvas4.wait();
} // VerticalSequential

/* VerticalParallel() flips the image from myImageFileName vertically.
 *
 * Precondition: myCanvas1 contains a TSGL Image that is to be inverted
 *               && myWidth contains the number of columns in which to display the image
 *               && myHeight contains the number of rows in which to display the image.
 *
 * Postcondition: a myWidth x myHeight Canvas has been displayed
 *                 containing the inverse of the image from myCanvas1
 *                 (which contains the image from myImageFileName).
 */
void ImageConverter::VerticalParallel() {
	// record starting time
	double startTime = omp_get_wtime();
	Canvas canvas5(myWidth + 50, 0, myWidth, myHeight,
			myImageFileName + " Vertical, Chunk-Size 1");
	canvas5.start();
	// launch additional threads
#pragma omp parallel
	{
		// how many workers do we have?
		unsigned numThreads = omp_get_num_threads();
		// which one am I?
		unsigned id = omp_get_thread_num();
		// loop through the image rows
		for (int row = id; row < myHeight; row += numThreads) {
			// slow the processing to simulate a very large image
			canvas5.sleep();
			// loop through the image columns
			for (int col = 0; col < myWidth; col++) {
				// read the pixel at canvas1[row][col]
				ColorInt pixelColor = myCanvas1.getPixel(row, col);
				// draw the inverse at the same spot in canvas2
				canvas5.drawPixel(myHeight - row, col,
						ColorInt(pixelColor.R, pixelColor.G, pixelColor.B));
			} // inner for
		} // outer for
	} // #pragma omp parallel
	// compute and display the time difference
	double totalTime = omp_get_wtime() - startTime;
	cout << "\n\nImage vertical took " << totalTime << " seconds.\n" << endl;

    //save converted image
    canvas5.takeScreenShot();
	canvas5.wait();
} // VerticalParallel

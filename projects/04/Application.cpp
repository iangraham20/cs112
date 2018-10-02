/* Application.cpp
 * Student Name: Ian Graham Christensen (igc2)
 * Date: March 6, 2017
 */

#include "Application.h"

Application::Application() {
	int menuNum = -1;
	while ( true ) {
		menuNum = -1;
		cout << "\nWelcome to the matrix operation menu!\n"
				"\nPlease enter:\n"
				"1 - Compare Matrix Equality\n"
				"2 - Add Matrices\n"
				"3 - Subtract Matrices\n"
				"4 - Transpose Matrix\n"
				"0 - Quit Application\n"
				"--->\n" << flush;

		cin >> menuNum;

		// Equality and Inequality
		if ( menuNum == 1 ) {
			cout << "Please enter the name of the file" << endl;
			string fileName;
			cin >> fileName;
			Matrix<double> m1;
			m1.readFrom(fileName.c_str() );
			cout << "Your first matrix is shown below:" << endl;
			m1.writeTo(cout);

			cout << "Please enter the name of the second file" << endl;
			cin >> fileName;
			Matrix<double> m2;
			m2.readFrom(fileName.c_str() );
			cout << "Your first matrix is shown below:" << endl;
			m2.writeTo(cout);

			Matrix<double> m3( m1.getRows(), m1.getColumns() );
			if ( m1 == m2 ) {
				cout << "These matrices are equal" << endl;
			}
			if ( m1 != m2 ){
				cout << "These matrices are not equal" << endl;
			}
		}

		// Addition
		else if ( menuNum == 2 ) {
			cout << "Please enter the name of the file" << endl;
			string fileName;
			cin >> fileName;
			Matrix<double> m1;
			m1.readFrom(fileName.c_str() );
			cout << "Your first matrix is shown below:" << endl;
			m1.writeTo(cout);

			cout << "Please enter the name of the second file" << endl;
			cin >> fileName;
			Matrix<double> m2;
			m2.readFrom(fileName.c_str() );
			cout << "Your first matrix is shown below:" << endl;
			m2.writeTo(cout);

			Matrix<double> m3( m1.getRows(), m1.getColumns() );
			m3 = m2 + m1;
			cout << "The summation of your matrices is shown below:" << endl;
			m3.writeTo(cout);
		}

		// Subtraction
		else if ( menuNum == 3 ) {
			cout << "Please enter the name of the file" << endl;
			string fileName;
			cin >> fileName;
			Matrix<double> m1;
			m1.readFrom(fileName.c_str() );
			cout << "Your first matrix is shown below:" << endl;
			m1.writeTo(cout);

			cout << "Please enter the name of the second file" << endl;
			cin >> fileName;
			Matrix<double> m2;
			m2.readFrom(fileName.c_str() );
			cout << "Your first matrix is shown below:" << endl;
			m2.writeTo(cout);

			Matrix<double> m3( m1.getRows(), m1.getColumns() );
			m3 = m2 - m1;
			cout << "The difference of your matrices is shown below:" << endl;
			m3.writeTo(cout);
		}

		// Transpose
		else if ( menuNum == 4 ) {
			cout << "Please enter the name of the file" << endl;
			string fileName;
			cin >> fileName;
			Matrix<double> m1;
			m1.readFrom(fileName.c_str() );
			cout << "Your first matrix is shown below:" << endl;
			m1.writeTo(cout);

			Matrix<double> m2( m1.getColumns(), m1.getRows() );
			m2 = m1.getTranspose();
			cout << "The transposed matrix is shown below:" << endl;
			m2.writeTo(cout);
		}

		else if ( menuNum == 0 ) {
			cout << "Application closed" << flush;
			break;
		}
	}
}

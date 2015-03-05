/*
The MIT License (MIT)

Copyright (c) 2015 John Tramm

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include<complex.h> // C99 only -- must be compiled with -std=c99 or -std=gnu99

double complex FNF( double complex Z )
{
	// Imaginary component is bumped up if less than 10^-6 
	if( cimag(Z) < 1e-6 )
		Z += 1e-6*I;

	// Abrarov Approximation 
	if( cabs(Z) <= 6.0 )
	{
		// Precomputed parts for speeding things up
		// (N = 24, Tm = 12.0)
		double complex prefactor = 8.124330e+01 * I;
		double an[24] = {
			2.758402e-01, 2.245740e-01, 1.594149e-01, 9.866577e-02,
			5.324414e-02, 2.505215e-02, 1.027747e-02, 3.676164e-03,
			1.146494e-03, 3.117570e-04, 7.391433e-05, 1.527949e-05,
			2.753957e-06, 4.327859e-07, 5.930030e-08, 7.084490e-09,
			7.379521e-10, 6.702172e-11, 5.307265e-12, 3.664324e-13,
			2.205895e-14, 1.157827e-15, 5.298711e-17, 2.114291e-18
		};
		double neg_1n[24] = {
			-1.0, 1.0, -1.0, 1.0, -1.0, 1.0, -1.0, 1.0,
			-1.0, 1.0, -1.0, 1.0, -1.0, 1.0, -1.0, 1.0,
			-1.0, 1.0, -1.0, 1.0, -1.0, 1.0, -1.0, 1.0
		};

		double denominator_left[24] = {
			9.869604e+00, 3.947842e+01, 8.882644e+01, 1.579137e+02,
			2.467401e+02, 3.553058e+02, 4.836106e+02, 6.316547e+02,
			7.994380e+02, 9.869604e+02, 1.194222e+03, 1.421223e+03,
			1.667963e+03, 1.934442e+03, 2.220661e+03, 2.526619e+03,
			2.852316e+03, 3.197752e+03, 3.562927e+03, 3.947842e+03,
			4.352496e+03, 4.776889e+03, 5.221021e+03, 5.684892e+03
		};

		double complex W = I * ( 1 - cexp(I*12.*Z) ) / (12. * Z );
		double complex sum = 0;
		for( int n = 0; n < 24; n++ )
		{
			complex double top = neg_1n[n] * cexp(I*12.*Z) - 1.;
			complex double bot = denominator_left[n] - 144.*Z*Z;
			sum += an[n] * (top/bot);
		}
		W += prefactor * Z  * sum;
		return W;
	}

	// Pre-computed parameters
	double a = 0.5124242247547684; double b = 0.2752551286084109;
	double c = 0.0517653587929878; double d = 2.7247448713915890;

	// Three Term Asymptotic Expansion
	double complex W = I * Z * (a/(Z*Z - b) + c/(Z*Z - d));

	return W;
}

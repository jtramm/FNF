+++++++++++++=+==++==========+++??IIIIIIIIIII??+++===========+=++=++++++++++++++
++++++++++++++++=+++=========++??III77777777II??++==========+++=++++++++++++++++
++++++++++++++++++++=+=======++?II777$$$$$777II?++==========++==++++++++++++++++
+++++++++++++++++++++++=+====+?II7$$ZZZOZZZ$$7I??+====+=++++=+++++++++++++++++++
+++++++++++++++++++++++======+?I7$ZOO8DD88OZZ$7I?+===+++++++++++++++++++++++++++
++++++++++++++++++++++++++====+I7$O8DDDDDDD8O$7I+===++++++++++++++++++++++++++++
++++++++++++++++++++++++++++==+I7Z8DDDDDDDDD8Z7?+=++++++++++++++++++++++++++++++
+++++++++++++++++++++++===++++=?7ODDDDDDDDDDDO7+=++====+++++++++++++++++++++++++
+++++++++++++++++++======+++==+=IODDDDDDDDDDDOI=+=++++====++++++++++++++++++++++
++++++++++++++++++++===+?I7$$7?++ODDDDDDDDDDDO++?7$$7I?+====++++++++++++++++++++
+++++++++++++++++++=+==?7Z88888Z+7DDDDDDDDDDDI+Z8888O$I?+==+++++++++++++++++++++
+++++++++++++++++++++==?7O8888888?8DDDDDDDDDDI8888888O7?==++++++++++++++++++++++
+++++++++++++++++++++++=?O88888888ZDDDDDDDDD$88888888O?=++++++++++++++++++++++++
++++++++++++++++++++==+++I88888888ZDDDDDDDDDO88888888I+?+==+++++++++++++++++++++
+++++++++++++++++=+++78DD8I88888888ZDDDDDDD$88888888I8DD8I=+++==++++++++++++++++
+++++++++++++++==++=+$DDDDD$8888888DDDDDDDDD8888888ZDDDDD$+=+=====++++++++++++++
++++++++++++++++=IZ8O?DDDDD8D8888888DDDDDDD8888888D8DDDD8IO8ZI=+++++++++++++++++
+++++++++++++++++I888888DDDDDD888888DDDDDDD888888DDDDDD888888I++++++++++++++++++
+++++++++++++++7Z7$888888D                             8888877ZI=+++++++++++++++
++++++++++==+++8DDDO88888D  ███████╗███╗   ██╗███████╗ 8888ODDD8+++=++++++++++++
++++++++++++Z8O7DDDDD88888  ██╔════╝████╗  ██║██╔════╝ 888DDDDD$O8Z+++++++++++++
+++++++++==+Z8888DDDDD8888  █████╗  ██╔██╗ ██║█████╗   88DDDDD8888$===++++++++++
++++++++=+8DDO8888DDDDD888  ██╔══╝  ██║╚██╗██║██╔══╝   8DDDDD8888Z8DO+++++++++++
++++++=IOO$DDDD8888DDDDD88  ██║     ██║ ╚████║██║      DDDDD8888DDDD78O?++++++++
+++++=??88888DDD8888DDDDD8  ╚═╝     ╚═╝  ╚═══╝╚═╝      DDDD8888DDDD8888??=++++++
+++=+?D888888DDDDD888DDDDD                             DDD888DDDDD888888D++==+++
+++I88ODD88888DDDDD8888DDD8888DDDD888DDDDD888DDDD8888DDDD8888DDDD888DDDDO88?++++
++OD7888DDDD888DDDD8888DDDD888DDDD888DDDDD888DDDD8888DDD8888DDDD888DDDD888IDZ+++
$O7DDD888DDDD888DDDD888DDDD888D8DD888DDDDD888DDDD888DDDD8888DDD888DDDD888DDD78$=
$888DDD888DDDDD88DDDD888DDDD888DDD888DDDDD88DDDD888DDDD888DDDD888DDD8888DDD888$$
DD888DDD888DDDD888DDDD88DDDD888DDDD888DDD888DDDD8888DD888DDDD888DDDD888DDD888DDD
================================================================================
                         Fast Nuclear Faddeeva Function
                                   Version 1
                                   John Tramm
                                      2015
================================================================================
         A fast approximation of the Faddeeva function W(z) for use in
       applications where the imaginary component of z is greater than 0.
       Ideal for SLBW nuclear resonance calculations where high fidelity
                         is not required. Written in C.
================================================================================
Overview
================================================================================
This function combines appromxation methods for two ranges of Complex space:

1) |z| >= 6.0
	In this range, the Faddeeva function is easily approximated by a three
	term asymptotic expansion. This method was first implemented by the
	QUICK_W code in [1], but was also implemented by Josey et al.[2]. 

2) |z| < 6.0 
	In this range, the Faddeeva function requires a more precise appromxation
	method. This function uses an approximation developed by
	Abrarov et al.[3][4].

================================================================================
Usage Assumptions
================================================================================
Use of this function comes with several assumptions:

1) The imaginary component of Z is always greater than zero. This is useful
   for many applications that can meet this assumption, as the Faddeeva
   function is much simplere to compute in positive complex space.

2) Machine precision or high fidelity is not required for the result when
   compared to reference implentations such as the MIT W function[5].
   The estimated accuracy of this function is O(1e-4) for |z| < 6.0, and
   O(1e-6) for |z| > 6.0.
================================================================================
References
================================================================================
[1] H. Henryson II, B. J. Toppel, and C. G. Stenberg. MC2^2: A Code to Calculate Fast Neutron Spectra and Multigroup Cross Sections. Technical Report Argonne-8144, Argonne National Laboratory (1976).
[2] C. Josey, B. Forget, and K. S. Smith, “EFFICIENCY AND ACCURACY EVALUATION OF THE WINDOWED MULTIPOLE DIRECT DOPPLER BROADENING METHO,” presented at the PHYSOR 2014 - The Role of Reactor Physics toward a Sustainable Future, 2014.
[3]	S. M. Abrarov and B. M. Quine, “A rapid and highly accurate approximation for the error function of complex argument,” arXiv.org, vol. math.NA. 14-Aug-2013.
[4]	S. M. Abrarov and B. M. Quine, “Applied Mathematics and Computation,” Applied Mathematics and Computation, vol. 218, no. 5, pp. 1894–1902, Nov. 2011.
[5] S. G. Johnson. “Faddeeva package - abinitio.” URL http://ab-initio.mit.edu/wiki/ index.php/Faddeeva_Package (2013).

Ansi C franctions module
====================================================================
by l.m.

Provides support for rational number arithmetic.

fraction_create( 12981, -231 ) = -12981/231
fraction_fromdouble( -.125 ) = -1/8
fraction_create( 2, -3 ) = 3/2
fraction_parse( "-2/3" ) = -2/3

3/2 + -2/3 = 5/6
3/2 - -2/3 = 13/6
3/2 * -2/3 = -1
3/2 : -2/3 = -9/4
-1/8 + 3/2 + -2/3 = 17/24


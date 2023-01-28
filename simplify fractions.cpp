void Fraction::simplify()
{
// Divide the numerator and denominator by
// the greatest common divisor.
if( numerator == 0)
{
denominator = 1;
return;
}
// Calculating the greatest common divisor
// using an algorithm by Euclid.
long a = (numerator < 0) ? -numerator : numerator,
b = denominator,
help;
while( b != 0)
{
help = a % b; a = b; b = help;
}
// a is the greatest common divisor
numerator /= a;
denominator /= a;
}

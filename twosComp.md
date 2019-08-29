# Two's Compliment

Two's complement is a mathematical operation on binary numbers, and is an example of a radix complement. It is used in computing as a method of signed number representation.

## Potential ambiguities of terminology

The term two's complement can mean either a number format or a mathematical
operator. For example, 0111 represents decimal 7 in two's-complement
notation, but the two's complement of 7 in a 4-bit register is actually the
"1001" bit string (the same as represents 9 = 24 − 7 in unsigned arithmetics)
which is the two's complement representation of −7. The statement "convert x
to two's complement" may be ambiguous, since it could describe either the
process of representing x in two's-complement notation without changing its
value, or the calculation of the two's complement, which is the arithmetic
negative of x if two's complement representation is used.

To get the two's complement of a binary number, the bits are inverted, or
"flipped", by using the bitwise NOT operation; the value of 1 is then added
to the resulting value, ignoring the overflow which occurs when taking the
two's complement of 0.

For example, using 1 byte (=8 bits), the decimal number 5 is represented by

0000 01012

The most significant bit is 0, so the pattern represents a non-negative
value. To convert to −5 in two's-complement notation, first, the bits are
inverted, that is: 0 becomes 1 and 1 becomes 0:

1111 10102

At this point, the representation is the ones' complement of the decimal
value −5. To obtain the two's complement, 1 is added to the result, giving:

1111 10112

The result is a signed binary number representing the decimal value −5 in
two's-complement form. The most significant bit is 1, so the value
represented is negative.

The two's complement of a negative number is the corresponding positive
value. For example, inverting the bits of −5 (above) gives:

0000 01002

And adding one gives the final value:

0000 01012

The two's complement of zero is zero: inverting gives all ones, and adding
one changes the ones back to zeros (since the overflow is ignored).
Furthermore, the two's complement of the most negative number representable
(e.g. a one as the most-significant bit and all other bits zero) is itself.
Hence, there appears to be an 'extra' negative number.

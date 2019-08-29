# Bitwise math

- [Bitwise math](#bitwise-math)
  - [NOT](#not)
  - [AND](#and)
  - [OR](#or)
  - [XOR](#xor)
  - [Bit Shifts](#bit-shifts)
    - [Arithmetic Shift](#arithmetic-shift)
    - [Logical Shift](#logical-shift)
  - [Circular Shift](#circular-shift)
    - [Rotate](#rotate)
    - [Rotate through Carry](#rotate-through-carry)

## NOT

___________

The bitwise NOT, or complement, is a unary operation that performs logical negation on each bit, forming
the ones' complement of the given binary value. Bits that are 0 become 1, and those that are 1 become 0.

```txt
NOT 0111  (decimal 7)
  = 1000  (decimal 8)
```

```txt
NOT 10101011  (decimal 171)
  = 01010100  (decimal 84)
```

## AND

___________

A bitwise AND takes two equal-length binary representations and performs the logical
AND operation on each pair of the corresponding bits, which is equivalent to
multiplying them. Thus, if both bits in the compared position are 1, the bit in the
resulting binary representation is 1 (1 × 1 = 1); otherwise, the result is 0 (1 × 0 = 0 and 0 × 0 = 0).
For example:

```txt
    0101 (decimal 5)
AND 0011 (decimal 3)
  = 0001 (decimal 1)
```

The operation may be used to determine whether a particular bit is set (1) or clear (0). For example,
given a bit pattern 0011 (decimal 3), to determine whether the second bit is set we use a bitwise AND
with a bit pattern containing 1 only in the second bit:

```txt
    0011 (decimal 3)
AND 0010 (decimal 2)
  = 0010 (decimal 2)
```

Because the result 0010 is non-zero, we know the second bit in the original pattern was set. This is
often called bit masking. (By analogy, the use of masking tape covers, or masks, portions that should
not be altered or portions that are not of interest. In this case, the 0 values mask the bits that are
not of interest.)

The bitwise AND may be used to clear selected bits (or flags) of a register in which each bit represents
an individual Boolean state. This technique is an efficient way to store a number of Boolean values
using as little memory as possible.

For example, 0110 (decimal 6) can be considered a set of four flags, where the first and fourth flags
are clear (0), and the second and third flags are set (1). The third flag may be cleared by using a
bitwise AND with the pattern that has a zero only in the third bit:

```txt
    0110 (decimal 6)
AND 1011 (decimal 11)
  = 0010 (decimal 2)
```

Because of this property, it becomes easy to check the parity of a binary number by checking the value
of the lowest valued bit. Using the example above:

```txt
    0110 (decimal 6)
AND 0001 (decimal 1)
  = 0000 (decimal 0)
```

Because 6 AND 1 is zero, 6 is divisible by two and therefore even.

## OR

___________
A bitwise OR takes two bit patterns of equal length and performs the logical inclusive OR operation on
each pair of corresponding bits. The result in each position is 0 if both bits are 0, while otherwise
the result is 1. For example:

```txt
   0101 (decimal 5)
OR 0011 (decimal 3)
 = 0111 (decimal 7)
```

The bitwise OR may be used to set to 1 the selected bits of the register described above. For example,
the fourth bit of 0010 (decimal 2) may be set by performing a bitwise OR with the pattern with only the
fourth bit set:

```txt
   0010 (decimal 2)
OR 1000 (decimal 8)
 = 1010 (decimal 10)
```

## XOR

___________

A bitwise XOR takes two bit patterns of equal length and performs the logical
exclusive OR operation on each pair of corresponding bits. The result in each
position is 1 if only the first bit is 1 or only the second bit is 1, but will be 0
if both are 0 or both are 1. In this we perform the comparison of two bits, being 1if the two bits are
different, and 0 if they are the same. For example:

```txt
    0101 (decimal 5)
XOR 0011 (decimal 3)
  = 0110 (decimal 6)
```

The bitwise XOR may be used to invert selected bits in a register (also called toggle or flip). Any bit
may be toggled by XORing it with 1. For example, given the bit pattern 0010 (decimal 2) the second and
fourth bits may be toggled by a bitwise XOR with a bit pattern containing 1 in the second and fourth
positions:

```txt
    0010 (decimal 2)
XOR 1010 (decimal 10)
  = 1000 (decimal 8)
```

This technique may be used to manipulate bit patterns representing sets of Boolean states.

Assembly language programmers and optimizing compilers sometimes use XOR as a short-cut to setting the
value of a register to zero. Performing XOR on a value against itself always yields zero, and on many
architectures this operation requires fewer clock cycles and memory than loading a zero value and saving
it to the register.

## Bit Shifts

### Arithmetic Shift

Left or right shift either end. The bits shifted out either end are discarded
In a LEFT shift a new zero will be placed on the rightmost position.
In a RIGHT shift the MSB most significant BIT is shifted in on the left, preserving the operand.

### Logical Shift

Similar to arithmetic shift only difference is the logical right shift operation.
inserts a value 0 into the most significant bit insted of copying the sign bit.

## Circular Shift

rotate bits right or left acts as if ends of register are joined

```c
/*
 * Shift operations in C are only defined for shift values which are
 * not negative and smaller than sizeof(value) * CHAR_BIT.
 * The mask, used with bitwise-and (&), prevents undefined behaviour
 * when the shift count is 0 or >= the width of unsigned int.
 */

#include <stdint.h>  // for uint32_t, to get 32-bit-wide rotates, regardless of the size of int.
#include <limits.h>  // for CHAR_BIT

uint32_t rotl32 (uint32_t value, unsigned int count) {
    const unsigned int mask = CHAR_BIT * sizeof(value) - 1;
    count &= mask;
    return (value << count) | (value >> (-count & mask));
}

uint32_t rotr32 (uint32_t value, unsigned int count) {
    const unsigned int mask = CHAR_BIT * sizeof(value) - 1;
    count &= mask;
    return (value >> count) | (value << (-count & mask));
}
```

### Rotate

In this operation, sometimes called rotate no carry, the bits are "rotated" as if the
left and right ends of the register were joined. The value that is shifted into the
right during a left-shift is whatever value was shifted out on the left, and vice
versa for a right-shift operation. This is useful if it is necessary to retain all
the existing bits, and is frequently used in digital cryptography.

### Rotate through Carry

Rotate through carry is a variant of the rotate operation, where the bit that is
shifted in (on either end) is the old value of the carry flag, and the bit that is
shifted out (on the other end) becomes the new value of the carry flag.

A single rotate through carry can simulate a logical or arithmetic shift of one
position by setting up the carry flag beforehand. For example, if the carry flag
if the carry flag contains a copy of the sign bit, then x
RIGHT-ROTATE-THROUGH-CARRY-BY-ONE is an arithmetic right-shift. For this reason, some
microcontrollers such as low end PICs just have rotate and rotate through carry, and
don't bother with arithmetic or logical shift instructions.

Rotate through carry is especially useful when performing shifts on numbers larger
than the processor's native word size, because if a large number is stored in two
registers, the bit that is shifted off one end of the first register must come in at
the other end of the second. With rotate-through-carry, that bit is "saved" in the
carry flag during the first shift, ready to shift in during the second shift without
any extra preparation.

# ENDIANNESS

In computing, endianness refers to the order of bytes (or sometimes bits) within a
binary representation of a number. It can also be used more generally to refer to the
internal ordering of any representation, such as the digits in a numeral system or
the sections of a date.

In its most common usage, endianness indicates the ordering of bytes within a
multi-byte number. A big-endian ordering places the most significant byte first and
the least significant byte last, while a little-endian ordering does the opposite.
For example, consider the unsigned hexadecimal number 0x1234, which requires at least
two bytes to represent. In a big-endian ordering they would be [ 0x12, 0x34 ], while
in a little-endian ordering, the bytes would be arranged [ 0x34, 0x12 ].

Historically, various methods of endianness have been used in computing, including
exotic forms such as middle-endianness. Today, however, big-endianness is the
dominant ordering in networking protocols (IP, TCP, UDP). Conversely,
little-endianness is the dominant ordering for processor architectures (x86, most ARM
implementations) and their associated memory. File formats can use either ordering;
some formats use a mixture of both.

In left-to-right scripts, numbers are written with their digits in big-endian order.
Similarly, programming languages use big-endian digit ordering for numeric literals
as well as big-endian language (“left” and “right”) for bit-shift operations,
regardless of the endianness of the target architecture. This can lead to confusion
when interacting with little-endian numbers.

## BIG endian

Atomic element size 8-bit

Address increment 1-byte (octet)

increasing addresses  →

… |  0Ah  |  0Bh |  0Ch  |  0Dh  | …

The most significant byte (MSB) value, 0Ah, is at the lowest address. The other bytes
follow in decreasing order of significance. This is akin to left-to-right reading in
hexadecimal order.

Atomic element size 16-bit

increasing addresses  →

… |  0A0Bh  |  0C0Dh  | …

The most significant atomic element stores now the value 0A0Bh, followed by 0C0Dh.

## little-endian

Atomic element size 8-bit

Address increment 1-byte (octet)

increasing addresses  →

… |  0Dh  |  0Ch  |  0Bh  |  0Ah  | …

The least significant byte (LSB) value, 0Dh, is at the lowest address. The other
bytes follow in increasing order of significance. This is akin to right-to-left
reading in hexadecimal order.

Atomic element size 16-bit
increasing addresses  →

… |  0C0Dh  |  0A0Bh  | …

The least significant 16-bit unit stores the value 0C0Dh, immediately followed by
0A0Bh. Note that 0C0Dh and 0A0Bh represent integers, not bit layouts.

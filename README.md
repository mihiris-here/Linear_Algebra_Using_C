# Solving Linear Algebra using C

## Matrix Multiplication

### 2x2 Strassen Formula 

Given two 2x2 matrices A and B:

A = | a  b |
    | c  d |

B = | e  f |
    | g  h |

The Strassen algorithm calculates the product C = A * B as follows:

C<sub>11</sub> = (a * e) + (b * g)

C<sub>12</sub> = (a * f) + (b * h)

C<sub>21</sub> = (c * e) + (d * g)

C<sub>22</sub> = (c * f) + (d * h)

Where C11, C12, C21, and C22 are the individual elements of the resulting matrix C:

C = | C11  C12 |
    | C21  C22 |




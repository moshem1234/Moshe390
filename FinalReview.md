# Moshe's Final Review

## Midterm Review

### Old Exams

* [Quizzes](<https://drive.google.com/drive/folders/1WC4z32oGymO6v-sJv2cMaFoiRggWHidV>)
* [Exam 1A Blank](<https://docs.google.com/document/d/1umwmKLYDnm4DaCgpsT2D68uLkWt_qVe7rWSYsJwce_Q>)
* [Exam 1A Solutions](<https://docs.google.com/document/d/1wYjuEsGYzsBaVM9mDqq5bqNiW-ciuDP8MdV6SkuhCXE>)
* [Exam 1M Blank](<https://docs.google.com/document/d/1ErxaA4tB6aZ10cDs-_MHd08bFbRtjXFvn_OKGMbymck>)
* [Exam 1M Solutions](<https://docs.google.com/document/d/1uwf1OmuLrDLl3AFbknhVqvUkwqTRA23l_QduUNiyjyU>)

### 2's Complement (Signed Negative Binary Integers)

* When the first bit of a signed integer is set to 1, that indicates that the number is negative. To convert a negative number from binary to decimal is a 3 step process.

### Masking

*

## Floating Points (C++ prefix float/double)

### <u>Basics</u>

First value: Sign; 1 for negative, 0 for positive (1 bit)  
Exponent: Determines decimal placement; $2^{exponent-127}$ (8 bits)  
Mantissa: Decimal number in the form of $2^{-n}$. (23 bits)

Above values are for a 'float' value. A 'double' value will have 11 bits for the exponent and 52 bits for the mantissa. The same properties apply.

[Useful tool for exploring floating points](<https://www.h-schmidt.net/FloatConverter/IEEE754.html>)

### <u>Roundoff</u>

When a decimal doesn't fit perfectly into the form of $2^{-n}$, the floating point loses it's ability to keep the number perfectly exact. This leads to __roundoff__. This can be best seen by example:

```cc
    for(float x = 0; x <=10; x+=0.1){
        cout << x << " ";
    }  
```

As 0.1 ($\frac{1}{10}$) does not fit the proper characterization for floating points ($2^{-n}$), it needs to be rounded to fit. This leads to an output like this:

```txt
0 0.1 0.2 0.30000001 0.40000001 0.5 0.60000002 0.70000005 0.80000007 0.9000001
1.0000001 1.1000001 1.2000002 1.3000002 1.4000002 1.5000002 1.6000003 1.7000003 1.8000003 1.9000003
2.0000002 2.1000001 2.2 2.3 2.3999999 2.4999998 2.5999997 2.6999996 2.7999995 2.8999994 2.9999993
3.0999992 3.1999991 3.299999 3.3999989 3.4999988 3.5999987 3.6999986 3.7999985 3.8999984 3.9999983
4.0999985 4.1999984 4.2999983 4.3999982 4.4999981 4.599998 4.6999979 4.7999978 4.8999977 4.9999976
5.0999975 5.1999974 5.2999973 5.3999972 5.4999971 5.599997 5.6999969 5.7999969 5.8999968 5.9999967
6.0999966 6.1999965 6.2999964 6.3999963 6.4999962 6.5999961 6.699996 6.7999959 6.8999958 6.9999957
7.0999956 7.1999955 7.2999954 7.3999953 7.4999952 7.5999951 7.699995 7.7999949 7.8999949 7.9999948
8.0999947 8.199995 8.2999954 8.3999958 8.4999962 8.5999966 8.6999969 8.7999973 8.8999977 8.9999981
9.0999985 9.1999989 9.2999992 9.3999996 9.5 9.6000004 9.7000008 9.8000011 9.9000015
 ```

In contrast, this code:

```cc
    for(float x = 0; x <=10; x+=0.125){
        cout << x << " ";
    }  
```

Will avoid that issue because 0.125 is $\frac{1}{8}$ and therefore fits the qualification. This will lead to an output:

```txt
0 0.125 0.25 0.375 0.5 0.625 0.75 0.875 1 1.125 1.25 1.375 1.5 1.625 1.75 1.875
2 2.125 2.25 2.375 2.5 2.625 2.75 2.875 3 3.125 3.25 3.375 3.5 3.625 3.75 3.875
4 4.125 4.25 4.375 4.5 4.625 4.75 4.875 5 5.125 5.25 5.375 5.5 5.625 5.75 5.875
6 6.125 6.25 6.375 6.5 6.625 6.75 6.875 7 7.125 7.25 7.375 7.5 7.625 7.75 7.875
8 8.125 8.25 8.375 8.5 8.625 8.75 8.875 9 9.125 9.25 9.375 9.5 9.625 9.75 9.875 10
```

### <u>inf and nan</u>

A value becomes 'inf' when the operation is impossible and $\displaystyle{\lim_{x \to 0}} = \infty$ .

A value becomes NaN when the equation result is either nonexistant or imaginary.

#### <u>Examples:</u>

$\frac{n>0}{0} = inf$  
$(n>0)*inf = inf$  
$\frac{n<0}{0} = -inf$  
$(n<0)*inf = -inf$  
$inf + inf = inf$  
$inf + (-inf) = nan$  
$\frac{0}{0} = nan$  
$\sqrt{inf} = inf$  
$\sqrt{n<0} = nan$  
$sin(inf)\ |\ cos(inf)\ |\ tan(inf) = nan$  
$sin(-inf)\ |\ cos(-inf)\ |\ tan(-inf) = nan$  
$nan + n\ |\ nan - n\ |\ nan * n\ |\ nan \div n = nan$

## Optimization

$x \*2^n\Longrightarrow x << n$  
$x \div 2^n \Longrightarrow x >> n$  
$i\ \\%\ 2^n \Longrightarrow i\ \\& \ (2^n-1) $  
$c_1\*x\*c_2 \Longrightarrow (c_1\*c_2)\*x$  
$c_1\*\frac{x}{c_2} \Longrightarrow (\frac{c_1}{c_2})\*x$  
$c_1\*x+c_2\*x+c_3\*x\Longrightarrow(c_1+c_2+c_3)\*x$  
$c_1\*x^4+c_2\*x^3+c_3\*x^2+c_4\*x+c_5\Longrightarrow (((c_1\*x+c_2)\*x+c_3)\*x+c_4)\*x+c_5$ (Horner's Form)

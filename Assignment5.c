//a
/******************************************************************************

Write a function palindrobits which returns 1 if the binary representation of
its parameter is a palindrobit, and 0 otherwise. A palindrobit is bit sequence
which can me read equally from left to right and right to left. For example,
5 is a palindrobit (101).

*******************************************************************************/
#include <stdio.h>


int palindrobit(int n){
    if(n&n  == n){
        return 1;
    }else{
        return 0; 
    }
}

int main()
{
    int n; 
    scanf("%i",&n); 
    int x = palindrobit(n); 
    printf("%i",x);

    return 0;
}


//b
/******************************************************************************

Create a complete program with a function that counts how many bits are 1
given some int value.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int n,k; 
    int counter = 0; 
    scanf("%i",&n);
    
    while(n>1){
        k = n%2; 
        if(k == 1){
            counter++; 
        }
        n/=2; 
    }
    if(n==1){
        counter++;
    }
    
    printf("%i",counter);

    return 0;
}


//c

/******************************************************************************

Write a function named cmp_bits that accepts two int arguments a and b, and
compares the number of "on" bits (number of 1s) between them. Return -1 if the
bitwise representation of a has fewer 1s than b; return 1 if a has more 1s than
b; and return zero if both have the same number of 1s. For example, if a is 5
(binary 101) and b is 32 (binary 10000), then cmp_bits returns 1.

*******************************************************************************/
#include <stdio.h>
#include <math.h>

int cmp_bits(){
    int a = 0;
    int b =0;
    scanf("%i",&a);
    scanf("%i",&b);
    int aCounter = 0; 
    int bCounter = 0; 
    int answer = 0; 
    for(int i = 0; i <= 32; i++){
        unsigned int mask = pow(2,i);
        if(a & mask){
            ++aCounter;
        }
    }
    for(int i = 0; i <= 32; i++){
        unsigned int mask = pow(2,i);
        if(b & mask){
            ++bCounter;
        }
    }

    answer = (aCounter<bCounter)? -1:answer; 
    answer = (aCounter>bCounter)? 1:answer; 
    answer = (aCounter == bCounter)? 0:answer; 
    return answer; 
}

int main()
{
    int answer = cmp_bits(); 
    printf("%i",answer);
    return 0; 
}



//d

/******************************************************************************

Write a function invert(x,p,n) that returns x with the n bits that begin at 
position p inverted (i.e., 1 changed into 0 and vice versa), leaving the 
others unchanged. Take into account that p=0 represent the less significant bit.

*******************************************************************************/
#include <stdio.h>
#include <math.h>

int invert(int x,int p,int n){
    unsigned int mask = 0; 

    for (int i = 0; i < x; i++){
        if(i>=p & i< p+n){
                mask = pow(2,i);
                x = x^mask;
        }
    }
    return x; 
}

int main()
{
    int x,p,n;
    scanf("%i",&x);
    scanf("%i",&p);
    scanf("%i",&n);
    int ans = invert(x,p,n);
    printf("%i",ans);
    return 0;
}



//e
/********************************************************************

Create a program that shifts bits to the left in a circular fashion. 
This is, the most significant bit will be now the less significant bit; 
while the less significant bit moves to the second less significant place. 
For example, the result of circularLeftShift(160,28) will result 10. Assume 
that the number to be shifted has 32 bits.

***********************************************************************/
#include <stdio.h>

unsigned int circularLeftShift(unsigned int n, int x){
    long int mask = (1<<31);
    
    for(int i = 1; i <=x; i++){
        unsigned int bits = mask & n;
        n <<= 1;
        bits >>= 31;
        n = n|bits;
    }
    return n;
}

int main()
{
    unsigned int n;
    int x;
    scanf("%i",&n);
    scanf("%i",&x);
    unsigned int ans = circularLeftShift(n,x);
    printf("%i",ans);
    return 0;
}


//f

/******************************************************************************
Create a program that shifts bits to the right in a circular fashion. 
This is, the less significant bit will be now the most significant bit; 
while the most significant bit moves to the second most significant place. 
For example, the result of circularRightShift(10,28) will result 160. Assume 
that the number to be shifted has 32 bits.

*****************************************************************************/
#include <stdio.h>

int circularRightShift(int n,int x){
    unsigned int bits = n>>x; 
    unsigned int swap = n << (32 - x);
    unsigned int ans = bits + swap; 
    //printf("%i",ans);
    return ans; 
}


int main()
{
    int n, x;
    scanf("%i",&n);
    scanf("%i",&x);
    int ans = circularRightShift(n,x);
    printf("%i",ans);
    return 0;
}


//g

/******************************************************************************

Create a function that swaps bits in a given position, for example swapBits(10, 3, 0) 
returns 3 because it swaps bits at position 3 and 0 in the number 1010 returning 0011.

******************************************************************************/
#include <stdio.h>
int swapBits(int n1, int n2, int n3){
    unsigned mask = 1; //last digit 
    unsigned x1 = (n1 >> n2) &mask;
    unsigned x2 = (n1 >> n3) &mask;
    unsigned x3 = x1 ^ x2; 
    unsigned back1 = x3 << n2; 
    unsigned back2 = x3 << n3; 
    unsigned ans = n1 ^ (back1 + back2) ; 
    return ans; 
}
int main()
{
    int n1,n2,n3;
    scanf("%i",&n1);
    scanf("%i",&n2);
    scanf("%i",&n3);
    int ans = swapBits(n1,n2,n3);
    printf("%i",ans);
    return 0;
}


//h

/******************************************************************************

Create a function multipleSwaps(N,a,b) which swaps bits from N starting at index 
a and ending at b. For example, multiple swapping 10011010 from 4 to 0 will return 
10001011, i. e. the bit at position 4 swaps with the bit at position 0, the bit at 
position 3 swaps with the bit at position 1, and the bit at position 2 remains intact.

*******************************************************************************/

#include <stdio.h>

int multipleSwaps(int n,int a,int b){
    int ans = n; 
    for(int i = 1; i<b/2; i++){
        ans = swapBits(ans,i+a -1 ,b-i+1);
        //printf("n = %i,  a = %i,  b = %i  ans = %i\n",ans,i+a,b-i, ans);
    }
    return ans;
}

int swapBits(int n1, int n2, int n3){
    unsigned mask = 1; //last digit 
    unsigned x1 = (n1 >> n2) &mask;
    unsigned x2 = (n1 >> n3) &mask;
    unsigned x3 = x1 ^ x2; 
    unsigned back1 = x3 << n2; 
    unsigned back2 = x3 << n3; 
    unsigned ans = n1 ^ (back1 + back2) ; 
    return ans; 
}

int main()
{
    int n,a,b;
    scanf("%i",&n);
    scanf("%i",&a); 
    scanf("%i",&b);
    int ans = multipleSwaps(n,a,b);
    printf("%i",ans );

    return 0;
}



//i

/******************************************************************************

Implement a program in C with a function named fourIntOne that has four 
parameters (a, b, c, d) which are unsigned integers of 8 bits. The function 
returns an unsigned integer of 32 bits which is the result of concatenating 
the four parameters a, b, c, and d, as follows: the bits 0 to 7 contain a, the 
bits 8 to 15 contain b, the bits 16 to 23 contain c, and the bits 24 to 31 
contain d.

*******************************************************************************/
#include <stdio.h>
int fourIntOne(unsigned a, unsigned b, unsigned c, unsigned d){
    unsigned ans = 0;
    unsigned posA, posB, posC, posD;
    posA = a;
    posB = b<<8;
    posC = c<<16;
    posD = d<<24; 
    ans = posA + posB + posC + posD; 
    return ans;
    
}


int main()
{
    unsigned a,b,c,d; 
    scanf("%u",&a);
    scanf("%u",&b);
    scanf("%u",&c);
    scanf("%u",&d);
    int ans = fourIntOne(a,b,c,d);
    printf("%i",ans);

    return 0;
}

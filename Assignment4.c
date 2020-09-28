// A
#include <stdio.h>

int main()
{
    int n = 0; 
    scanf("%d",&n);
    if (n%2==0){
        printf("even");
    }else{
        printf("odd");
    }
    return 0;
}

//B
#include <stdio.h>

int countFactors(int n){
    int factors = 0;
    
    for(int i = 1; i<=n; i++){
        if(n%i == 0){
            factors += 1; 
        }
    }
    return factors;
}

int main()
{
    int n;
    int factors; 
    scanf("%d", &n);
    factors = countFactors( n);
    printf("%d",factors);
    return 0;
}

//C
#include <stdio.h>

int main()
{
    int n1;
    int n2;
    int n3;
    
    scanf("%d",&n1);
    scanf("%d",&n2);
    scanf("%d",&n3);
    int mid=n1; 
    mid = (n1>=n2 & n1<=n3)? n1: mid;
    mid = (n2>=n1 & n2<=n3)? n2: mid;
    mid = (n3>=n2 & n3<=n1)? n3: mid;
    mid = (n1>=n3 & n1<=n2)? n1: mid;
    mid = (n2>=n3 & n2<=n1)? n2: mid;
    mid = (n3>=n1 & n3<=n2)? n3: mid;
    
    printf("%d",mid);
    return 0;
}

//D
/******************************************************************************

Write a complete program that takes two integers as parameters representing a 
month and day and that prints a label indicating the season for that month and 
day. Assume that months are specified as an integer between 1 and 12 (1 for 
January, 2 for February, and so on) and that the day of the month is a number 
between 1 and 31. If the date falls between 12/16 and 3/15, you should print 
"Winter". If the date falls between 3/16 and 6/15, you should print "Spring". 
If the date falls between 6/16 and 9/15, you should print "Summer". And if the
date falls between 9/16 and 12/15, you should print "Fall".

*******************************************************************************/
#include <stdio.h>
void season(int month, int day){
    
    if(month>=1 & month <=3){
        if(month == 3 & day> 15){
            printf("Spring");
        }
        else{
            printf("Winter");
        }
    }
    
    if(month>=4 & month <=6){
        if(month == 6 & day>15){
            printf("Summer");
        }
        else{
            printf("Spring");
        }
    }
    
    if(month>=7 & month <=9){
        if(month == 9 & day> 15){
            printf("Fall");
        }
        else{
            printf("Summer");
        }
    }
    
    if(month>=10 & month <=12){
        if(month == 12 & day> 15){
            printf("Winter");
        }
        else{
            printf("Fall");
        }
    }
}
int main(void)
{
    int month=0;
    int day=0;
    scanf("%d",&month);
    scanf("%d",&day);
    season(month,day);

    return 0;
}

//E
#include <stdio.h>

void printRange(int n, int m)
{
    if(n<m){
        for (int i = n; i<=m;i++){
            printf("%d ",i);
        }
    }else if (n>m){
        for (int i = n; i>=m;i--){
            printf("%d ",i);
        }
    }else{
        printf("%d",n);
    }
}


int main(void)
{
    int n;
    int m;
    scanf("%d",&n);
    scanf("%d",&m);
    printRange(n,m);
    return 0;
}

//F
/******************************************************************************

Write a program with a function named xo that accepts an integer size as a
parameter and prints a square of size by size characters, where all characters
are "o" except that an "x" pattern of "x" characters has been drawn from the
corners of the square. In other words, on the first line, the first and last
characters are "x"; on the second line, the second and second-from-last
characters are "x"; and so on. If 0 or less is passed for the size, no output
should be produced.
(1,1)(1,2)(1,3)(1,4)(1,5)
(2,1)(2,2)(2,3)(2,4)(2,5)
(3,1)(3,2)(3,3)(4,4)(5,5)
(4,1)(4,2)(4,3)(4,4)(4,5)
(5,1)(5,2)(5,3)(5,4)(5,5)


(1,1)(1,5)(2,2)(2,4)(3,3)(4,2)(4,4)(5.1)(5,5)
n = m (1,1)(2,2)(3,3)(4,4)(5,5)
5+1, 1+5, 4+2, 2+4 = 6 = n + 1
*******************************************************************************/
#include <stdio.h>

void xo(int n){
    if(n<1){
    }else{
        for(int i = 1; i <= n; i++){ // fila
            
            for(int j = 1; j <= n; j++){ // columna 
                if(i == j  || (i+j) == n+1){
                    printf("x");
                }else{
                    printf("o");
                }
            }
            printf("\n");
        }
    }
}

int main(void)
{
    int n;
    scanf("%d",&n);
    xo(n);
    return 0;
}

//G
/******************************************************************************

Write a program with a function called printTriangleType that accepts three
integer arguments representing the lengths of the sides of a triangle and prints
what type of triangle it is. The three types are equilateral, isosceles, and
scalene. An equilateral triangle has all three sides the same length, an isosceles
triangle has two sides the same length, and a scalene triangle has three sides
of different lengths.

*******************************************************************************/
#include <stdio.h>

void printTriangleType ()
{
    int n1;
    int n2;
    int n3;
    scanf("%d",&n1);
    scanf("%d",&n2);
    scanf("%d",&n3);
    if(n1==n2 || n1 == n3 || n2==n3 ){
        if(n1==n2 && n1!=n3 ||n1==n3 && n1!=n2 ||n2==n3 && n2!=n1 ){
             printf("isosceles");
        }
        else{
            printf("equilateral");
        }
    }else{
        printf("scalene");
    }
    
    
}

int main(void)
{
    printTriangleType();

    return 0;
}

//H
/******************************************************************************

Write a complete program with a function called quadrant that takes as
parameters a pair of real numbers representing an (x, y) point and that returns
the quadrant number for that point. Recall that quadrants are numbered as
integers from 1 to 4 with the upper-right quadrant numbered 1 and the subsequent
quadrants numbered in a counter-clockwise fashion:

*******************************************************************************/
#include <stdio.h>

int quadrant(double x,double y){
    int n=0;
    if(x == 0 || y == 0){
        n = 0;
    }else{
        if(x>0){
            n = (y>0)? 1:4;
        }else{
            n = (y>0)? 2:3;
            }
        }
    
    return n;
}

int main()
{
    double x;
    double y;
    scanf("%lf",&x);
    scanf("%lf",&y);
    int n = quadrant(x,y);
    printf("%d",n);

    return 0;
}

//I
/******************************************************************************
A "perfect number" is a positive integer that is the sum of all its proper
factors (that is, factors including 1 but not the number itself). The first
two perfect numbers are 6 and 28, since 1+2+3=6 and 1+2+4+7+14=28. Write a
complete program with a function perfectNumbers that takes an integer max as
an argument and prints out all perfect numbers that are less than or equal to max.

Here is the console output from a call to perfectNumbers(6): Perfect numbers up to 6: 6

*******************************************************************************/
#include <stdio.h>
void perfectNumbers()
{
    int n;
    scanf("%i",&n);    
    printf("Perfect numbers up to %i:",n);
    for(int j =1; j<=n ; j++){
        int sum =0;
        for(int i = 1; i<j; i++) {
    		if(j%i == 0){
    				sum += i;
    		}
    	}
    		if (sum == j) {
    			printf(" %d", j);
    	    }
    }
    
}

int main(void)
{
    perfectNumbers();
    return 0;
}

//J
/******************************************************************************

Write a complete program with a function called zeroDigits that accepts an
integer parameter and returns the number of digits in the number that have the
value 0. For example, the call zeroDigits(5024036) should return 2, and
zeroDigits(743) should return 0. The call zeroDigits(0) should return 1. You may
assume that the integer is non-negative.
*******************************************************************************/
#include <stdio.h>
int zeroDigits(int n){
    int zeros=0;
    if(n== 0){
        return 1;
    }
    while(n>0){
        int last = n%10;
       if (last==0) {
       zeros+= 1;
        }
        n = n/10;
    }
    return zeros;
}

int main()
{
    int n; 
    scanf("%i",&n);
    int zeros = zeroDigits(n);
    printf("%i",zeros);

    return 0;
}

//K
/******************************************************************************

Write a complete program with a function named showTwos that shows the factors
of 2 in a given integer

*******************************************************************************/
#include <stdio.h>

void showTwos(){
    int n;
    scanf("%i",&n);
    printf("%i = ",n);
    while(n%2 == 0){
        printf("%i * ", 2 ); 
        n=n/2; 
    }
    printf("%i",n);
        
    
}

int main(void)
{
    showTwos();
    return 0;
}

//L


//M
/******************************************************************************
Write a complete program with a function named hopscotch that accepts an
integer parameter for a number of "hops" and prints a hopscotch board of that
many hops. A "hop" is defined as the split into two numbers and then back
together again into one.

   1
2     3
   4
5     6
   7
8     9
   10
*******************************************************************************/
#include <stdio.h>
void hopscotch(int n){
    int x=0;
    for(int i=1; i<=n; i++){
        printf("   %i\n",i+x);
        printf("%i     %i\n",i+x+1, i+x+2);
        x = x+2;
    }
    printf("   %i\n",n+x+1);
}



int main(void)
{
    int n;
    scanf("%i",&n);
    hopscotch(n);
    return 0;
}

//N
/******************************************************************************

Write a complete program with a function named hasMidpoint that accepts three
integers as parameters and returns true if one of the integers is the midpoint
between the other two integers; that is, if one integer is exactly halfway
between them. Your method should return false if no such midpoint relationship
exists.The integers could be passed in any order; the midpoint could be the 1st,
2nd, or 3rd. You must check all cases.

*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

bool hasMidpoint(int n1, int n2, int n3){
    if((n1-n2 == n3-n1) || (n2-n1 == n3-n2) ||  (n3-n1 == n2-n3)){
        return true; 
    }else{
        return false;
    }
}

int main()
{
    int n1,n2,n3;
    scanf("%i",&n1);
    scanf("%i",&n2);
    scanf("%i",&n3);
    bool mid = hasMidpoint(n1,n2,n3);
    printf("%s", mid?"true":"false");

    return 0;
}

//O
/******************************************************************************

Write a complete program with a function named digitSum that accepts an 
integer as a parameter and returns the sum of the digits of that number. 
For example, digitSum(29107) returns 2+9+1+0+7 or 19. For negative numbers, 
return the same value that would result if the number were positive. For 
example, digitSum(-456) returns 4+5+6 or 15.

*******************************************************************************/
#include <stdio.h>

int digitSum(int n){
    int sum = 0;
    n = abs(n); //eliminar negativos
    while(n>0){
        sum+= n%10; 
        n = n/10; 
    }
    
    return sum;
}

int main()
{
    int n;
    scanf("%i",&n);
    int sum = digitSum(n);
    printf("%i", sum);

    return 0;
}

//P
/******************************************************************************

Write a complete program with a funtion named digitRange that accepts an
integer as a parameter and returns the range of values of its digits. The
range is defined as 1 more than the difference between the largest and
smallest digit value. For example, the call of digitRange(68437) would return
6 because the largest digit value is 8 and the smallest is 3, so 8 - 3 + 1 = 6.
If the number contains only one digit, return 1. You should solve this problem 
without using a *char.

*******************************************************************************/
#include <stdio.h>

int digitRange(int n){
    n = abs(n);
    int largest= 0; 
    int smallest = 9; 
    while(n>0){
        int x = n%10; 
        largest = (x>largest)? x:largest; 
        smallest = (x<smallest)? x:smallest; 
        n = n/10; 
    }
    int range = largest - smallest +1; 
    return  range; 
}


int main()
{
    int n; 
    scanf("%i",&n);
    int range = digitRange(n);
    printf("%i",range);

    return 0;
}

// A
#include <stdio.h>

int main()
{
    int n = 0; 
    scanf("%d",&n);
    if (n%2==0){
        printf("even");
    }else{
        printf("odd");
    }
    return 0;
}

//B
#include <stdio.h>

int countFactors(int n){
    int factors = 0;
    
    for(int i = 1; i<=n; i++){
        if(n%i == 0){
            factors += 1; 
        }
    }
    return factors;
}

int main()
{
    int n;
    int factors; 
    scanf("%d", &n);
    factors = countFactors( n);
    printf("%d",factors);
    return 0;
}

//C
#include <stdio.h>

int main()
{
    int n1;
    int n2;
    int n3;
    
    scanf("%d",&n1);
    scanf("%d",&n2);
    scanf("%d",&n3);
    int mid=n1; 
    mid = (n1>=n2 & n1<=n3)? n1: mid;
    mid = (n2>=n1 & n2<=n3)? n2: mid;
    mid = (n3>=n2 & n3<=n1)? n3: mid;
    mid = (n1>=n3 & n1<=n2)? n1: mid;
    mid = (n2>=n3 & n2<=n1)? n2: mid;
    mid = (n3>=n1 & n3<=n2)? n3: mid;
    
    printf("%d",mid);
    return 0;
}

//D
/******************************************************************************

Write a complete program that takes two integers as parameters representing a 
month and day and that prints a label indicating the season for that month and 
day. Assume that months are specified as an integer between 1 and 12 (1 for 
January, 2 for February, and so on) and that the day of the month is a number 
between 1 and 31. If the date falls between 12/16 and 3/15, you should print 
"Winter". If the date falls between 3/16 and 6/15, you should print "Spring". 
If the date falls between 6/16 and 9/15, you should print "Summer". And if the
date falls between 9/16 and 12/15, you should print "Fall".

*******************************************************************************/
#include <stdio.h>
void season(int month, int day){
    
    if(month>=1 & month <=3){
        if(month == 3 & day> 15){
            printf("Spring");
        }
        else{
            printf("Winter");
        }
    }
    
    if(month>=4 & month <=6){
        if(month == 6 & day>15){
            printf("Summer");
        }
        else{
            printf("Spring");
        }
    }
    
    if(month>=7 & month <=9){
        if(month == 9 & day> 15){
            printf("Fall");
        }
        else{
            printf("Summer");
        }
    }
    
    if(month>=10 & month <=12){
        if(month == 12 & day> 15){
            printf("Winter");
        }
        else{
            printf("Fall");
        }
    }
}
int main(void)
{
    int month=0;
    int day=0;
    scanf("%d",&month);
    scanf("%d",&day);
    season(month,day);

    return 0;
}

//E
#include <stdio.h>

void printRange(int n, int m)
{
    if(n<m){
        for (int i = n; i<=m;i++){
            printf("%d ",i);
        }
    }else if (n>m){
        for (int i = n; i>=m;i--){
            printf("%d ",i);
        }
    }else{
        printf("%d",n);
    }
}


int main(void)
{
    int n;
    int m;
    scanf("%d",&n);
    scanf("%d",&m);
    printRange(n,m);
    return 0;
}

//F
/******************************************************************************

Write a program with a function named xo that accepts an integer size as a
parameter and prints a square of size by size characters, where all characters
are "o" except that an "x" pattern of "x" characters has been drawn from the
corners of the square. In other words, on the first line, the first and last
characters are "x"; on the second line, the second and second-from-last
characters are "x"; and so on. If 0 or less is passed for the size, no output
should be produced.
(1,1)(1,2)(1,3)(1,4)(1,5)
(2,1)(2,2)(2,3)(2,4)(2,5)
(3,1)(3,2)(3,3)(4,4)(5,5)
(4,1)(4,2)(4,3)(4,4)(4,5)
(5,1)(5,2)(5,3)(5,4)(5,5)


(1,1)(1,5)(2,2)(2,4)(3,3)(4,2)(4,4)(5.1)(5,5)
n = m (1,1)(2,2)(3,3)(4,4)(5,5)
5+1, 1+5, 4+2, 2+4 = 6 = n + 1
*******************************************************************************/
#include <stdio.h>

void xo(int n){
    if(n<1){
    }else{
        for(int i = 1; i <= n; i++){ // fila
            
            for(int j = 1; j <= n; j++){ // columna 
                if(i == j  || (i+j) == n+1){
                    printf("x");
                }else{
                    printf("o");
                }
            }
            printf("\n");
        }
    }
}

int main(void)
{
    int n;
    scanf("%d",&n);
    xo(n);
    return 0;
}

//G
/******************************************************************************

Write a program with a function called printTriangleType that accepts three
integer arguments representing the lengths of the sides of a triangle and prints
what type of triangle it is. The three types are equilateral, isosceles, and
scalene. An equilateral triangle has all three sides the same length, an isosceles
triangle has two sides the same length, and a scalene triangle has three sides
of different lengths.

*******************************************************************************/
#include <stdio.h>

void printTriangleType ()
{
    int n1;
    int n2;
    int n3;
    scanf("%d",&n1);
    scanf("%d",&n2);
    scanf("%d",&n3);
    if(n1==n2 || n1 == n3 || n2==n3 ){
        if(n1==n2 && n1!=n3 ||n1==n3 && n1!=n2 ||n2==n3 && n2!=n1 ){
             printf("isosceles");
        }
        else{
            printf("equilateral");
        }
    }else{
        printf("scalene");
    }
    
    
}

int main(void)
{
    printTriangleType();

    return 0;
}

//H
/******************************************************************************

Write a complete program with a function called quadrant that takes as
parameters a pair of real numbers representing an (x, y) point and that returns
the quadrant number for that point. Recall that quadrants are numbered as
integers from 1 to 4 with the upper-right quadrant numbered 1 and the subsequent
quadrants numbered in a counter-clockwise fashion:

*******************************************************************************/
#include <stdio.h>

int quadrant(double x,double y){
    int n=0;
    if(x == 0 || y == 0){
        n = 0;
    }else{
        if(x>0){
            n = (y>0)? 1:4;
        }else{
            n = (y>0)? 2:3;
            }
        }
    
    return n;
}

int main()
{
    double x;
    double y;
    scanf("%lf",&x);
    scanf("%lf",&y);
    int n = quadrant(x,y);
    printf("%d",n);

    return 0;
}

//I
/******************************************************************************
A "perfect number" is a positive integer that is the sum of all its proper
factors (that is, factors including 1 but not the number itself). The first
two perfect numbers are 6 and 28, since 1+2+3=6 and 1+2+4+7+14=28. Write a
complete program with a function perfectNumbers that takes an integer max as
an argument and prints out all perfect numbers that are less than or equal to max.

Here is the console output from a call to perfectNumbers(6): Perfect numbers up to 6: 6

*******************************************************************************/
#include <stdio.h>
void perfectNumbers()
{
    int n;
    scanf("%i",&n);    
    printf("Perfect numbers up to %i:",n);
    for(int j =1; j<=n ; j++){
        int sum =0;
        for(int i = 1; i<j; i++) {
    		if(j%i == 0){
    				sum += i;
    		}
    	}
    		if (sum == j) {
    			printf(" %d", j);
    	    }
    }
    
}

int main(void)
{
    perfectNumbers();
    return 0;
}

//J
/******************************************************************************

Write a complete program with a function called zeroDigits that accepts an
integer parameter and returns the number of digits in the number that have the
value 0. For example, the call zeroDigits(5024036) should return 2, and
zeroDigits(743) should return 0. The call zeroDigits(0) should return 1. You may
assume that the integer is non-negative.
*******************************************************************************/
#include <stdio.h>
int zeroDigits(int n){
    int zeros=0;
    if(n== 0){
        return 1;
    }
    while(n>0){
        int last = n%10;
       if (last==0) {
       zeros+= 1;
        }
        n = n/10;
    }
    return zeros;
}

int main()
{
    int n; 
    scanf("%i",&n);
    int zeros = zeroDigits(n);
    printf("%i",zeros);

    return 0;
}

//K
/******************************************************************************

Write a complete program with a function named showTwos that shows the factors
of 2 in a given integer

*******************************************************************************/
#include <stdio.h>

void showTwos(){
    int n;
    scanf("%i",&n);
    printf("%i = ",n);
    while(n%2 == 0){
        printf("%i * ", 2 ); 
        n=n/2; 
    }
    printf("%i",n);
        
    
}

int main(void)
{
    showTwos();
    return 0;
}

//L


//M
/******************************************************************************
Write a complete program with a function named hopscotch that accepts an
integer parameter for a number of "hops" and prints a hopscotch board of that
many hops. A "hop" is defined as the split into two numbers and then back
together again into one.

   1
2     3
   4
5     6
   7
8     9
   10
*******************************************************************************/
#include <stdio.h>
void hopscotch(int n){
    int x=0;
    for(int i=1; i<=n; i++){
        printf("   %i\n",i+x);
        printf("%i     %i\n",i+x+1, i+x+2);
        x = x+2;
    }
    printf("   %i\n",n+x+1);
}



int main(void)
{
    int n;
    scanf("%i",&n);
    hopscotch(n);
    return 0;
}

//N
/******************************************************************************

Write a complete program with a function named hasMidpoint that accepts three
integers as parameters and returns true if one of the integers is the midpoint
between the other two integers; that is, if one integer is exactly halfway
between them. Your method should return false if no such midpoint relationship
exists.The integers could be passed in any order; the midpoint could be the 1st,
2nd, or 3rd. You must check all cases.

*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

bool hasMidpoint(int n1, int n2, int n3){
    if((n1-n2 == n3-n1) || (n2-n1 == n3-n2) ||  (n3-n1 == n2-n3)){
        return true; 
    }else{
        return false;
    }
}

int main()
{
    int n1,n2,n3;
    scanf("%i",&n1);
    scanf("%i",&n2);
    scanf("%i",&n3);
    bool mid = hasMidpoint(n1,n2,n3);
    printf("%s", mid?"true":"false");

    return 0;
}

//O
/******************************************************************************

Write a complete program with a function named digitSum that accepts an 
integer as a parameter and returns the sum of the digits of that number. 
For example, digitSum(29107) returns 2+9+1+0+7 or 19. For negative numbers, 
return the same value that would result if the number were positive. For 
example, digitSum(-456) returns 4+5+6 or 15.

*******************************************************************************/
#include <stdio.h>

int digitSum(int n){
    int sum = 0;
    n = abs(n); //eliminar negativos
    while(n>0){
        sum+= n%10; 
        n = n/10; 
    }
    
    return sum;
}

int main()
{
    int n;
    scanf("%i",&n);
    int sum = digitSum(n);
    printf("%i", sum);

    return 0;
}

//P
/******************************************************************************

Write a complete program with a funtion named digitRange that accepts an
integer as a parameter and returns the range of values of its digits. The
range is defined as 1 more than the difference between the largest and
smallest digit value. For example, the call of digitRange(68437) would return
6 because the largest digit value is 8 and the smallest is 3, so 8 - 3 + 1 = 6.
If the number contains only one digit, return 1. You should solve this problem 
without using a *char.

*******************************************************************************/
#include <stdio.h>

int digitRange(int n){
    n = abs(n);
    int largest= 0; 
    int smallest = 9; 
    while(n>0){
        int x = n%10; 
        largest = (x>largest)? x:largest; 
        smallest = (x<smallest)? x:smallest; 
        n = n/10; 
    }
    int range = largest - smallest +1; 
    return  range; 
}


int main()
{
    int n; 
    scanf("%i",&n);
    int range = digitRange(n);
    printf("%i",range);

    return 0;
}


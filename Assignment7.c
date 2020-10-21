//A
/******************************************************************************

Implement a function in C that simplifies a fraction. The function receives 
a constant pointer to a constant struct of type Fraction which contains two 
integer members (numerator and denominator). The function creates and returns 
a new simplified Fraction. For example, if the fraction 4/8 is passed to the 
function SimplifyFraction, the output will be the new fraction ½.

You must create every struct by reserving memory dynamically. Before finishing 
the program, you must ensure that all the memory dynamically allocated is 
released. If you omit any of these elements, your solution will be invalidated.\

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int numerator;
    int denominator;
}Fraction;

Fraction* SimplifyFraction(const Fraction* const notsSimplified){
    int divr = 0;
    for(int i = 1; i <= notsSimplified->denominator; ++i){
        if(notsSimplified -> numerator % i == 0 && notsSimplified -> denominator % i == 0 ){
            divr = i;
        }
    }
    Fraction* simplified = malloc(sizeof(Fraction));
    simplified -> numerator = notsSimplified -> numerator/divr; 
    simplified -> denominator = notsSimplified -> denominator/divr; 
    
    return simplified; 
}

int main(){
    Fraction* notsSimplified = malloc(sizeof(Fraction));
    int num, dem;
    scanf("%i",&num);
    scanf("%i",&dem);
    notsSimplified -> numerator = num; //add values to stucture 
    notsSimplified -> denominator = dem;
    
    Fraction* ans = SimplifyFraction(notsSimplified);
    free(notsSimplified); //releases memory
    
    printf("%i\n%i", ans -> numerator, ans -> denominator);
    free(ans);
    return 0;
}

//B
/******************************************************************************

Implement a function in C that sum up two fractions and returns the (simplified) 
summed fraction. The function receives two constant pointers to constant structs 
of type Fraction each one containing two integer members (numerator and denominator) 
and returns a new simplified summed Fraction. For example, if the fractions 4/8 and 
2/3 are passed to the function SumFraction, the output will be the new fraction 7/6.

You must create every struct by reserving memory dynamically. Before finishing
the program, you must ensure that all the memory dynamically allocated is released. 
If you omit any of these elements, your solution will be invalidated.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int numerator;
    int denominator;
}Fraction;

Fraction* SimplifyFraction(const Fraction* const notsSimplified){
    int divr = 0;
    for(int i = 1; i <= notsSimplified->denominator; ++i){
        if(notsSimplified -> numerator % i == 0 && notsSimplified -> denominator % i == 0 ){
            divr = i;
        }
    }
    Fraction* simplified = malloc(sizeof(Fraction));
    simplified -> numerator = notsSimplified -> numerator/divr; 
    simplified -> denominator = notsSimplified -> denominator/divr; 
    
    return simplified; 
}

Fraction* SumFraction(const Fraction* const firstFraction ,const Fraction* const secondFraction){
    Fraction* sumedFraction = malloc(sizeof(Fraction));
    sumedFraction -> numerator = ((firstFraction -> numerator)*(secondFraction -> denominator)) + ((secondFraction -> numerator)*(firstFraction -> denominator));
    sumedFraction -> denominator = (firstFraction -> denominator)*(secondFraction -> denominator);
    Fraction* sumedAndSimplifiedFraction = SimplifyFraction(sumedFraction);
    free(sumedFraction);
    return sumedAndSimplifiedFraction; 
}

int main(){
    Fraction* firstFraction = malloc(sizeof(Fraction));
    Fraction* secondFraction = malloc(sizeof(Fraction));
    int num1, dem1,num2, dem2;
    scanf("%i",&num1);
    scanf("%i",&dem1);
    scanf("%i",&num2);
    scanf("%i",&dem2);
    firstFraction -> numerator = num1; //add values to stucture 
    firstFraction -> denominator = dem1;
    secondFraction -> numerator = num2; 
    secondFraction -> denominator = dem2;
    
    Fraction* ans = SumFraction(firstFraction,secondFraction);
    free(firstFraction); //releases memory
    free(secondFraction); 
    
    printf("%i\n%i", ans -> numerator, ans -> denominator);
    free(ans);
    return 0;
}


//C
/******************************************************************************

Implement a function in C that computes the Euclidean distance between two 3D-points 
represented by constant pointers to constant structs of type Point3D with integer 
members x, y, and z. The Euclidean distance is computed as the square root of the 
sum of the squared difference between the points component.

You must create every struct by reserving memory dynamically. Before finishing the 
program, you must ensure that all the memory dynamically allocated is released. 
If you omit any of these elements, your solution will be invalidated.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    int x;
    int y;
    int z;
}Point3D;

double computeEuclidean(const Point3D* const firstPoint, const Point3D* const secondPoint){
    double ans = sqrt(sqrt(secondPoint -> x - firstPoint -> x) + sqrt(secondPoint -> y - firstPoint -> y) + sqrt(secondPoint -> z - firstPoint -> z));
    return ans; 
}

int main(){
    Point3D* firstPoint = malloc(sizeof(Point3D));
    Point3D* secondPoint = malloc(sizeof(Point3D));
    int x1, x2,y1,y2,z1,z2;
    scanf("%i",&x1);
    scanf("%i",&y1);
    scanf("%i",&z1);
     scanf("%i",&x2);
    scanf("%i",&y2);
    scanf("%i",&z2);
    firstPoint -> x = x1; //add values to stucture 
    firstPoint -> y = y1;
    firstPoint -> z = z1;
    secondPoint -> x = x2; 
    secondPoint -> y = y2;
    secondPoint -> z = z2;
    
    double ans = computeEuclidean(firstPoint, secondPoint);
    free(firstPoint); //releases memory
    free(secondPoint);
    printf("%.2lf", ans);
    
    return 0;
}

//D
/******************************************************************************

Implement a function in C named quadrant that receives a constant pointer to a 
constant struct Point2D and returns which quadrant of the x/y plane the point 
falls in. Quadrant 1 contains all points whose x and y values are both positive.
Quadrant 2 contains all points with negative x but positive y. Quadrant 3 contains 
all points with negative x and y values. Quadrant 4 contains all points with 
positive x but negative y. If the point lies directly on the x and/or y axis, 
return 0.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x;
    int y;
}Point2D;

int quadrant(const Point2D* const point){
    int ans; 
     if(point -> x == 0 || point -> y == 0){ //Lo copie de mi tarea 4 c: 
        ans = 0;
    }else{
        if(point -> x > 0){
            ans = (point -> y > 0)? 1:4;
        }else{
            ans = (point -> y > 0)? 2:3;
            }
        }
    return ans; 
}

int main(){
    Point2D* point = malloc(sizeof(Point2D));
    
    int x,y;
    scanf("%i",&x);
    scanf("%i",&y);
    
    point -> x = x; //add values to stucture 
    point -> y = y;

    int ans = quadrant(point);
    free(point); //releases memory
    printf("%i", ans);
    
    return 0;
}


//E
/******************************************************************************

Implement a function in C named SwapAndNegate that negates and swaps the x/y 
coordinates of the Point2D struct which is passed to the function using a pointer. 
For example, if the object initially represents the point (5, -3), after a call 
to SwapAndNegate, the object should represent (3, -5). If the object initially 
represents the point (4, 17), after a call to SwapAndNegate, the object should 
represent (-17, -4).

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x;
    int y;
}Point2D;

void SwapAndNegate(Point2D* point){
    int xPoint = point -> x;
    point -> x = -(point -> y);
    point -> y = -(xPoint);
}

int main(){
    Point2D* point = malloc(sizeof(Point2D));
    
    int x,y;
    scanf("%i",&x);
    scanf("%i",&y);
    
    point -> x = x; //add values to stucture 
    point -> y = y;

    SwapAndNegate(point);
    printf("%i\n%i", point -> x, point -> y);
    free(point); //releases memory
    return 0;
}

//F
/******************************************************************************

Implement a function in C named ComputeSlope that returns the slope of the line 
drawn between two Point2D structs which are passed to the function using constant 
pointers to constant data. Use the formula (y2 - y1) / (x2 - x1) to determine the 
slope between two points (x1, y1) and (x2, y2).

You must create every struct by reserving memory dynamically. Before finishing 
the program, you must ensure that all the memory dynamically allocated is 
released. If you omit any of these elements, your solution will be invalidated.
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x;
    int y;
}Point2D;

double ComputeSlope(const Point2D* const firstPoint, const Point2D* const secondPoint){
    double ans = 1.0* (secondPoint -> y - firstPoint -> y) / (secondPoint -> x - firstPoint -> x);
    return ans; 
}

int main(){
    Point2D* firstPoint = malloc(sizeof(Point2D));
    
    int x1,y1; 
    scanf("%i",&x1);
    scanf("%i",&y1);
    firstPoint -> x = x1; //add values to stucture 
    firstPoint -> y = y1;
    int x2,y2;
    
    Point2D* secondPoint = malloc(sizeof(Point2D));
    scanf("%i",&x2);
    scanf("%i",&y2);
    secondPoint -> x = x2;
    secondPoint -> y = y2; 

    double ans = ComputeSlope(firstPoint, secondPoint);
    free(firstPoint); //releases memory
    free(secondPoint);
    printf("%.1lf", ans);
    
    return 0;
}


//G
/******************************************************************************

Implement a function in C named AreCollinear that returns whether three points 
(passed to the function as constant pointers to constant struct Point2D) are 
collinear. Points are collinear if a straight line can be drawn that connects them. 
Two basic examples are three points that have the same x- or y-coordinate. The more
general case can be determined by calculating the slope of the line between each 
pair of points and checking whether this slope is the same for all pairs of points. 
Use the formula (y2 - y1) / (x2 - x1) to determine the slope between two points 
(x1, y1) and (x2, y2). Since C's double type is imprecise, round all slope values 
to a reasonable accuracy such as four digits past the decimal point before you 
compare them.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    int x;
    int y;
}Point2D;

double ComputeSlope(const Point2D* const firstPoint, const Point2D* const secondPoint){
    double ans = 1.0* (secondPoint -> y - firstPoint -> y) / (secondPoint -> x - firstPoint -> x);
    return ans; 
}

int AreCollinear(const Point2D* const firstPoint, const Point2D* const secondPoint,  const Point2D* const thirdPoint)
{
    int ans = 0; 
    if(firstPoint -> x == secondPoint -> x && thirdPoint -> x == secondPoint -> x || firstPoint -> y == secondPoint -> y && thirdPoint -> y == secondPoint -> y ){
        ans = 1;
    }else{
        double slope1 = ComputeSlope(firstPoint, secondPoint);
        double slope2 = ComputeSlope(firstPoint, thirdPoint);
        double slope3 = ComputeSlope(thirdPoint, secondPoint);
        slope1 = (double)((int)(slope1 * 1000))/1000;
        slope2 = (double)((int)(slope2 * 1000))/1000;
        slope3 = (double)((int)(slope3 * 1000))/1000;
        
        ans = (abs(slope1 - slope2) < 0.00001)? 1:0; 
        ans = (abs(slope1 - slope3) < 0.00001)? 1:0; 
        ans = (abs(slope3 - slope2) < 0.00001)? 1:0; 
        
    }
    return ans;
}
 
int main(){
    
    int x1,y1; 
    scanf("%i",&x1);
    scanf("%i",&y1);
    Point2D* firstPoint = malloc(sizeof(Point2D));
    firstPoint -> x = x1; //add values to stucture 
    firstPoint -> y = y1;
    
    int x2,y2;
    scanf("%i",&x2);
    scanf("%i",&y2);
    Point2D* secondPoint = malloc(sizeof(Point2D));
    secondPoint -> x = x2;//add values to stucture 
    secondPoint -> y = y2; 
    
    int x3,y3;
    scanf("%i",&x3);
    scanf("%i",&y3);
    Point2D* thirdPoint = malloc(sizeof(Point2D));
    secondPoint -> x = x3;//add values to stucture 
    secondPoint -> y = y3; 

    int ans = AreCollinear(firstPoint, secondPoint, thirdPoint);
    free(firstPoint); //releases memory
    free(secondPoint);
    free(thirdPoint);
    printf("%i", ans);
    
    return 0;
}



//H
/******************************************************************************

Implement a function in C named RectangleContainsPoint that returns whether a 
point (passed to the function as a constant pointer to constant struct Point2D) 
lies inside the bounds of a rectangle (represented by a constant pointer to a 
constant struct Rectangle where member x represents the horizontal coordinate 
of the left-top corner, member y represents the vertical coordinate of the left
top corner, height represents the height of the rectangle, and width represents 
the width of the rectangle; notice that the origin of the coordinates is in the 
left-top corner of the screen). For example, a rectangle with [x=2,y=5,width=8,
height=10] will return true for any point from (2, 5) through (10, 15) inclusive.

You must create every struct by reserving memory dynamically. Before finishing 
the program, you must ensure that all the memory dynamically allocated is 
released. If you omit any of these elements, your solution will be invalidated.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x;
    int y;
}Point2D; 

typedef struct{
    int x; //horizontal coordinate of the left-top corner.
    int y; //vertical coordinate of the left-top corner. 
    int height; 
    int width; 
}Rectangle; 

int RectangleContainsPoint(const Point2D* const point, const Rectangle* const rectangle){
    int ans = 0;
    int inx = (rectangle -> x <= point -> x && point -> x <= (rectangle -> x + rectangle -> width))? 1:0; 
    int iny = (rectangle -> y <= point -> y && point -> y <= (rectangle -> y + rectangle -> height))? 1:0;
    ans = (inx&&iny)? 1:0;
    return ans; 
}



int main()
{
    int xRec,yRec, height, width; 
    scanf("%i",&xRec);
    scanf("%i",&yRec);
    scanf("%i",&height);
    scanf("%i",&width);
    Rectangle* rectangle = malloc(sizeof(Rectangle));
    rectangle -> x = xRec; //add values to stucture 
    rectangle -> y = yRec;
    rectangle -> height = height;
    rectangle -> width = width;
    
    int xPoint,yPoint; 
    scanf("%i",&xPoint);
    scanf("%i",&yPoint);
    Point2D* point = malloc(sizeof(Point2D));
    point -> x = xPoint; //add values to stucture 
    point -> y = yPoint;

    int ans = RectangleContainsPoint(point, rectangle);
    free(point); //releases memory
    free(rectangle);
    printf("%i", ans);
    return 0;
}



//I
/******************************************************************************

Implement a function in C named UniteRectangles that receives two rectangles 
(represented by constant pointers to constant struct Rectangle where member x 
represents the horizontal coordinate of the left-top corner, member y represents 
he vertical coordinate of the left-top corner, width represents the width of the 
rectangle, and height represents the height of the rectangle; notice that the 
origin of the coordinates is in the left-top corner of the screen) and return 
a new rectangle that represents the area occupied by the tightest bounding box 
that contains both input rectangles. For example, the union of
Rectangle[x=5,y=12,width=4,height=6] and Rectangle[x=6,y=8,width=5,height=7] 
is the Rectangle[x=5,y=8,width=6,height=10].

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x; //horizontal coordinate of the left-top corner.
    int y; //vertical coordinate of the left-top corner. 
    int height; 
    int width; 
}Rectangle; 


Rectangle* UniteRectangles(const Rectangle* const rectangle1, const Rectangle* const rectangle2){
    Rectangle* newRectangle = malloc(sizeof(Rectangle));
    newRectangle -> x = (rectangle1 -> x <= rectangle2 -> x)? rectangle1 -> x: rectangle2 -> x; 
    newRectangle -> y = (rectangle1 -> y <= rectangle2 -> y)? rectangle1 -> y: rectangle2 -> y;
    
    int r1long = rectangle1 -> x + rectangle1 -> width; 
    int r2long = rectangle2 -> x + rectangle2 -> width;
    int newRlong = (r1long >= r2long) ? r1long: r2long;
    newRectangle -> width = newRlong - newRectangle -> x ;
    
    int r1tall = rectangle1 -> y + rectangle1 -> height; 
    int r2tall = rectangle2 -> y + rectangle2 -> height;
    int newRtall = (r1tall >= r2tall) ? r1tall: r2tall;
    newRectangle -> height = newRtall - newRectangle -> y ;

    return newRectangle; 
}

int main()
{
    int xRec,yRec, height, width; 
    scanf("%i",&xRec);
    scanf("%i",&yRec);
    scanf("%i",&width);
    scanf("%i",&height);
   
    Rectangle* rectangle1 = malloc(sizeof(Rectangle));
    rectangle1 -> x = xRec; //add values to stucture 
    rectangle1 -> y = yRec;
    rectangle1 -> width = width;
    rectangle1 -> height = height;
    
    
    int xRec2,yRec2, height2, width2; 
    scanf("%i",&xRec2);
    scanf("%i",&yRec2);
    scanf("%i",&width2);
    scanf("%i",&height2);
   
    Rectangle* rectangle2 = malloc(sizeof(Rectangle));
    rectangle2 -> x = xRec2; //add values to stucture 
    rectangle2 -> y = yRec2;
    rectangle2 -> width = width2;
    rectangle2 -> height = height2;
    
    
    Rectangle* ans = UniteRectangles(rectangle1, rectangle2);
    free(rectangle1);
    free(rectangle2);
    printf("%i\n%i\n%i\n%i\n", ans -> x, ans -> y, ans -> width, ans -> height);
    free(ans);

    return 0;
}



//J
/******************************************************************************

Implement a function in C named IntersectRectangles that receives two rectangles 
(represented by constant pointers to constant struct Rectangle where member x 
represents the horizontal coordinate of the left-top corner, member y represents 
the vertical coordinate of the left-top corner, width represents the width of the 
rectangle, and height represents the height of the rectangle; notice that the 
origin of the coordinates is in the left-top corner of the screen) and returns 
a rectangle that represents the largest rectangular region completely contained 
within both inputted rectangles. For example, the intersection of 
Rectangle[x=5,y=12,width=4,height=6] and Rectangle[x=6,y=8,width=5,height=7] 
is the rectangle Rectangle[x=6,y=12,width=3,height=3].

*******************************************************************************/


#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x; //horizontal coordinate of the left-top corner.
    int y; //vertical coordinate of the left-top corner. 
    int height; 
    int width; 
}Rectangle; 


Rectangle* IntersectRectangles(const Rectangle* const rectangle1, const Rectangle* const rectangle2){
    Rectangle* newRectangle = malloc(sizeof(Rectangle));
    newRectangle -> x = (rectangle1 -> x <= rectangle2 -> x)? rectangle2 -> x: rectangle1 -> x; 
    newRectangle -> y = (rectangle1 -> y <= rectangle2 -> y)? rectangle2 -> y: rectangle1 -> y;
    
    int r1long = rectangle1 -> x + rectangle1 -> width; 
    int r2long = rectangle2 -> x + rectangle2 -> width;
    int newRlong = (r1long >= r2long) ? r2long: r1long;
    newRectangle -> width = newRlong - newRectangle -> x ;
    
    int r1tall = rectangle1 -> y + rectangle1 -> height; 
    int r2tall = rectangle2 -> y + rectangle2 -> height;
    int newRtall = (r1tall >= r2tall) ? r2tall: r1tall;
    newRectangle -> height = newRtall - newRectangle -> y ;

    return newRectangle; 
}

int main()
{
    int xRec,yRec, height, width; 
    scanf("%i",&xRec);
    scanf("%i",&yRec);
    scanf("%i",&width);
    scanf("%i",&height);
   
    Rectangle* rectangle1 = malloc(sizeof(Rectangle));
    rectangle1 -> x = xRec; //add values to stucture 
    rectangle1 -> y = yRec;
    rectangle1 -> width = width;
    rectangle1 -> height = height;
    
    
    int xRec2,yRec2, height2, width2; 
    scanf("%i",&xRec2);
    scanf("%i",&yRec2);
    scanf("%i",&width2);
    scanf("%i",&height2);
   
    Rectangle* rectangle2 = malloc(sizeof(Rectangle));
    rectangle2 -> x = xRec2; //add values to stucture 
    rectangle2 -> y = yRec2;
    rectangle2 -> width = width2;
    rectangle2 -> height = height2;
    
    
    Rectangle* ans = IntersectRectangles(rectangle1, rectangle2);
    free(rectangle1);
    free(rectangle2);
    printf("%i\n%i\n%i\n%i\n", ans -> x, ans -> y, ans -> width, ans -> height);
    free(ans);

    return 0;
}

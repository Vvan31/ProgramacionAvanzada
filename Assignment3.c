// A
#include <stdio.h>

void printer(double x,  double y,double bubble) {
    int z = 5;
  
    printf("x = %.2f and y = %.1f\n",x, y);
    printf("x = %.2f and y = %.4f\n",x, bubble);
    printf("The value from main is: %.4f\n", bubble);
    printf("z = %d",z);
}

int main(void) {

    double bubble = 867.5309;
    double x = 10.01;
    double y = 8.0;
   
    printer(x,y,bubble);
    return 0;
}
// B
#include <stdio.h>
    
void printStrings ( char c[512],int n){
    for(int i=0; i<n; i++){
         printf("%s",c);
    }
}

int main(void)
{
    char c[512];
    int n= 0;
    scanf("%d",&n);
    scanf("%s",&c);
    printStrings(c,n);
}
//C
#include <stdio.h>

double ftoc(double tempf, double tempc) {
    tempc = (tempf - 32) * 5 / 9;
    return tempc;
}

int main() {

double tempf = 98.6;
double tempc = 0.0;
tempc = ftoc(tempf, tempc);
printf("Body temp in C is: %.1f" , tempc);

return 0;
}
//D
#include <stdio.h>

int min(int n1,int n2, int n3){
    int nMin;
    nMin = ( n1 < n2 & n1 < n3) ? n1:nMin;
    nMin = ( n2 < n3 & n2 < n1) ? n2:nMin; 
    nMin = ( n3 < n1 & n3 < n2) ? n3:nMin; 
    printf("%d",nMin);
}

int main()
{
    int n1,n2,n3;
    scanf("%d",&n1);
    scanf("%d",&n2);
    scanf("%d",&n3);
    min(n1,n2,n3);
}
//E
#include <stdio.h>

int min(int n1,int n2, int n3){
    int nMin;
    nMin = ( n1 < n2 & n1 < n3) ? n1:nMin;
    nMin = ( n2 < n3 & n2 < n1) ? n2:nMin; 
    nMin = ( n3 < n1 & n3 < n2) ? n3:nMin; 
    printf("%d",nMin);
}

int main()
{
    int n1,n2,n3;
    scanf("%d",&n1);
    scanf("%d",&n2);
    scanf("%d",&n3);
    min(n1,n2,n3);
}
//F
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d times 2 = %d", n, 2*n);
    return 0;
}
//G
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d times 2 = %d", n, 2*n);
    return 0;
}
//H
#include <stdio.h>

void printNumbers()
{
    int n;
    scanf("%i",&n);
    for(int i=1;i<=n;i++){
        printf("[%i] ",i);
    }
}


int main(void)
{
    printNumbers();
    return 0;
}
//I
#include <stdio.h>
#include <math.h>

void printPowersOf2()
{
    int n;
    scanf("%i",&n);
    for(int i= 0;i<=n;i++){
        printf("%.f ",pow(2,i));
    }
}


int main(void)
{
    printPowersOf2();
    return 0;
}
//J
#include <stdio.h>
#include <math.h>

void printPowersOf2()
{
    int n;
    scanf("%i",&n);
    for(int i= 0;i<=n;i++){
        printf("%.f ",pow(2,i));
    }
}


int main(void)
{
    printPowersOf2();
    return 0;
}
//K
#include <stdio.h>

void printSquare()
{
    int min;
    int max;
    scanf("%i",&min);
    scanf("%i",&max);
    for(int i=min; i <= max; i++){
        for(int j = i; j<= max; j++ ){
            printf("%i", j);
        }
        for(int j = min; j< i; j++ ){
            printf("%i", j);
        }
        printf("\n");
    }
}


int main(void)
{
   printSquare();

    return 0;
}
//L
#include <stdio.h>

void printSquare()
{
    int min;
    int max;
    scanf("%i",&min);
    scanf("%i",&max);
    for(int i=min; i <= max; i++){
        for(int j = i; j<= max; j++ ){
            printf("%i", j);
        }
        for(int j = min; j< i; j++ ){
            printf("%i", j);
        }
        printf("\n");
    }
}


int main(void)
{
   printSquare();

    return 0;
}
//M
#include <stdio.h>

void printSquare()
{
    int min;
    int max;
    scanf("%i",&min);
    scanf("%i",&max);
    for(int i=min; i <= max; i++){
        for(int j = i; j<= max; j++ ){
            printf("%i", j);
        }
        for(int j = min; j< i; j++ ){
            printf("%i", j);
        }
        printf("\n");
    }
}


int main(void)
{
   printSquare();

    return 0;
}

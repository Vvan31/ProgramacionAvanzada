//A
#include "stdio.h"
#define SIZE 10

int main(void) {
  unsigned int h[SIZE] = {0};
  scanf("%u%u%u%u%u%u%u%u%u%u", &h[0], &h[1], &h[2], &h[3], &h[4], &h[5], &h[6], &h[7], &h[8], &h[9]);

    for(int i=0; i<SIZE;i++){
        for(int j = 0; j<h[i];j++){
            printf("%s","b"); 
        }
        printf("\n"); 
    }

  return 0;
}

//B
#include "stdio.h"
#define SIZE 10

int main(void) {
  unsigned int h[SIZE] = {0};
  double avg = 0; 
  scanf("%u%u%u%u%u%u%u%u%u%u", &h[0], &h[1], &h[2], &h[3], &h[4], &h[5], &h[6], &h[7], &h[8], &h[9]);
      for(int i=0; i<SIZE;i++){
        avg += h[i];
      }
    printf("%.1f",avg/10);
  return 0;
}

//C
/******************************************************************************

Create a program to read a variable number of elements, store them in the array 
a, passes a to the function computeMode which computes the mode number over the 
array, and then, the program prints the result of computeMode.
*******************************************************************************/
#include <stdio.h>

void computeMode(int size,int a[]){
    int ans = 0;
    int mode = 0; 
    
    for(int i = 0; i < size; i++){
        int counter = 0; 
        for(int j = 0; j < size; j++){
            if(a[i] == a[j]){
                counter ++; 
            }
        }
        
        if(counter>mode){
            ans = a[i];
            mode = counter; 
        }
    }
    
    printf("%i", ans);
}


int main(void)
{
    int size = 0; 
    scanf("%i",&size);
    int a[size];
    for(int i = 0; i < size; i++){
        int n = 0;
        scanf("%i", &n);
        a[i] = n; 
    }
    
    computeMode(size, a);

    return 0;
}

//D
/******************************************************************************

Create a program to read a variable number of elements, store them in the array a, 
passes a to the function computeMax which computes the maximun number iterating 
over the array, and then, the program prints the result of computeMax.

*******************************************************************************/
#include <stdio.h>

void computeMax(int size, int a[]){
    int max = a[0]; 
    
    for(int i = 0; i < size; i++){
        max = (a[i]>max)?a[i]:max;
    }
    
    printf("%i", max);
}


int main(void)
{
    int size = 0; 
    scanf("%i",&size);
    int a[size];
    for(int i = 0; i < size; i++){
        int n = 0;
        scanf("%i", &n);
        a[i] = n; 
    }
    
    computeMax(size,a);

    return 0;
}

//E
/******************************************************************************

Complete the program to read a variable number of elements, store them in the 
array a, passes a to the function computeMin which computes the minimum number 
iterating over the array, and then, the program prints the result of computeMin.

*******************************************************************************/
#include <stdio.h>

void computeMin(int size, int a[]){
    int min = a[0]; 
    
    for(int i = 0; i < size; i++){
        min = (a[i]<min)?a[i]:min;
    }
    
    printf("%i", min);
}


int main(void)
{
    int size = 0; 
    scanf("%i",&size);
    int a[size];
    for(int i = 0; i < size; i++){
        int n = 0;
        scanf("%i", &n);
        a[i] = n; 
    }
    
    computeMin(size,a);

    return 0;
}


//F
/******************************************************************************

Create a program to read a variable number of elements, store them in the array 
a, passes a to the function computeMedina which sorts the array, and then, 
computes the median.

*******************************************************************************/
#include <stdio.h>

int * bubbleSort (int size, int a[]){
    for(int i = 0; i< size-1; i++){ 
        for(int j = 0; j < size-i-1; j++){ 
            int n1 = a[j];
            int n2 = a[j+1]; 
            if(n1 > n2){
                a[j] = n2;
                a[j+1] = n1;
            } 
        } 
    } 
    return a; 
}


void computeMedina(int size,int a[]){
    float ans = 0;
    int *b;
    b = bubbleSort(size, a); 
    if(size % 2 == 0){
        int mid1 = (size-1)/2;
        int mid2 = mid1+1; 
        int n1 = a[mid1];
        int n2 = a[mid2];
        ans = (float)(n1+n2)/2;
    }else{
        int mid = size/2; 
        ans = (float) a[mid]; 
    }
    printf("%.1f", ans);
}



int main(void)
{
    int size = 0; 
    scanf("%i",&size);
    int a[size];
    for(int i = 0; i < size; i++){
        int n = 0;
        scanf("%i", &n);
        a[i] = n; 
    }
    
    computeMedina(size, a);

    return 0;
}


//G
/******************************************************************************

Create a program to read a variable number of elements, store them in the array 
a, passes a to the function searchValue which sorts the array, performs binary 
search, and returns the index of the closes value.

*******************************************************************************/
#include <stdio.h>

int * bubbleSort (int size, int a[]){
    for(int i = 0; i< size-1; i++){ 
        for(int j = 0; j < size-i-1; j++){ 
            int n1 = a[j];
            int n2 = a[j+1]; 
            if(n1 > n2){
                a[j] = n2;
                a[j+1] = n1;
            } 
        } 
    } 
    /*
    for(int i = 0; i< size; i++){
      printf("%i ",a[i]);
    }*/
    return a; 
}
int binarySearch(int a[], int leftIndex, int rightIndex, int n, int closest){
     if (rightIndex >= leftIndex) { 
        int mid = leftIndex + (rightIndex - leftIndex) / 2; 
     
         if(a[mid]== n){
             //printf(" closest: %i\n", closest);
             return mid;
         }
         else if(a[mid] > n ){
             rightIndex = mid - 1;
             //printf(" closest: %i\n", closest);
             return binarySearch(a, leftIndex, rightIndex, n , mid);
         }
         else{
             leftIndex = mid + 1;
             //printf(" closest: %i\n", closest);
             return binarySearch(a, leftIndex, rightIndex, n , mid);
         }
     }
    return closest; 
}
int searchValue(int size, int value, int a[]){
    int ans = 0; 
    int *b;
    b = bubbleSort(size, a); 
    ans = binarySearch(a,0,size,value,0);
    return ans;
}

int main()
{
    int size = 0; 
    int value = 0;
    scanf("%i",&size);
    scanf("%i",&value);
    int a[size];
    for(int i = 0; i < size; i++){
        int n = 0;
        scanf("%i", &n);
        a[i] = n; 
    }
    int ans = searchValue(size,value, a);
    printf("%i",ans);
    return 0;
}


//H
/******************************************************************************

Create a program to read a variable number of elements, store them in the array a,
passes a to the function bubbleSort which sorts the array, and then, the program 
prints the sorted array.

*******************************************************************************/
#include <stdio.h>

void bubbleSort (int size, int a[]){
    for(int i = 0; i< size-1; i++){ 
        for(int j = 0; j < size-i-1; j++){ 
            int n1 = a[j];
            int n2 = a[j+1]; 
            if(n1 > n2){
                a[j] = n2;
                a[j+1] = n1;
            } 
        } 
    } 
    for(int i = 0; i< size; i++){
      printf("%i \n",a[i]);
    }
}



int main(void)
{
    int size = 0; 
    scanf("%i",&size);
    int a[size];
    for(int i = 0; i < size; i++){
        int n = 0;
        scanf("%i", &n);
        a[i] = n; 
    }
    
    bubbleSort(size, a);

    return 0;
}


//I
/******************************************************************************

Write a static method named range that takes an array of integers as a parameter 
and returns the range of values contained in the array. The range of an array is 
defined to be one more than the difference between its largest and smallest element. 
For example, if the largest element in the array is 15 and the smallest is 4, 
the range is 12. If the largest and smallest values are the same, the range is 1.

*******************************************************************************/
#include <stdio.h>

int * bubbleSort (int size, int a[]){
    for(int i = 0; i< size-1; i++){ 
        for(int j = 0; j < size-i-1; j++){ 
            int n1 = a[j];
            int n2 = a[j+1]; 
            if(n1 > n2){
                a[j] = n2;
                a[j+1] = n1;
            } 
        } 
    } 
    return a; 
}

int range(int size, int a[]){
    int ans = 0; 
    int *b;
    b = bubbleSort(size, a); 
    ans = b[size-1] - b[0] +1;
    return ans;
}

int main()
{
    int size = 0; 
    scanf("%i",&size);
    int a[size];
    for(int i = 0; i < size; i++){
        int n = 0;
        scanf("%i", &n);
        a[i] = n; 
    }
    int ans = range(size, a);
    printf("%i",ans);
    return 0;
}


//J
/******************************************************************************

Write a method called countInRange that accepts an array of integers, a minimum 
value, and a maximum value as parameters and returns the count of how many elements 
from the array fall between the minimum and maximum (inclusive). For example, in 
the array {14, 1, 22, 17, 36, 7, -43, 5}, there are four elements whose values 
fall between 4 and 17. IMPORTANT: Do not sort the array to solve this problem. 
The first value entered in the console corresponds to the minimum value; the 
second, to the maximum; the third, to the array size; and the rest, to the 
elements of the array.

*******************************************************************************/
#include <stdio.h>

int countInRange (int min, int max, int size, int a[]){
    int ans = 0; 
    for(int i = 0; i < size; i++){
        if(a[i]<=max && a[i]>= min){
            ans ++;
        }
    }
    return ans;
}

int main()
{
    int size = 0;
    int min = 0;
    int max = 0; 
    scanf("%i",&min);
    scanf("%i",&max);
    scanf("%i",&size);
    int a[size];
    for(int i = 0; i < size; i++){
        int n = 0;
        scanf("%i", &n);
        a[i] = n; 
    }
    int ans = countInRange(min ,max, size, a);
    printf("%i",ans);
    return 0;
}


//K

/******************************************************************************

Write a method called countInRange that accepts an array of integers bids and 
an integer price as parameters. 
The function returns the element in the bids array that is closest in value 
to price without being larger than price. 
For example, if bids stores the elements {200, 300, 250, 999, 40}, then 
priceIsRight(bids, 280) should return 250, since 250 is the bid closest to 280 
without going over 280. If all bids are larger than price, then your method 
should return -1. 
You may assume there is at least 1 element in the array, and you may assume that 
the price and the values in bids will all be greater than or equal to 1. Do not 
modify the contents of the array passed to your method as a parameter.
Assume that the first element entered in the console is the price, the second 
is the array size, while the rest are the bids.
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int countInRange(int price, int size,int a[]){
    int ans = -1;
    int closestDif = 9999999; 
    for(int i = 0; i<size; i++){
        int n = a[i]; 
        int dif = abs(price - n); 
        if(dif < closestDif && n <= price){
            ans = n; 
            closestDif = dif; 
        }
    }
    return ans;
}


int main(void)
{
    int size = 0; 
    int price = 0;  
    scanf("%i",&price);
    scanf("%i",&size);
    int a[size];
    for(int i = 0; i < size; i++){
        int n = 0;
        scanf("%i", &n);
        a[i] = n; 
    }
    int bid = countInRange(price, size, a);
    printf("%i", bid);
    return 0;
}

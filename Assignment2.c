#include <stdio.h>

int main()
{
    int x=-4;
    for(int i=0; i<6; i++){
        printf("%d\n",x);
        x=x+18;
    }
}



#include <stdio.h>

int main()
{
    for(int i=1; i<5; i++){
        printf("2 times %d  = %d\n",i , 2*i);

    }
}

#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",  n%1000 );
}


#include <stdio.h>

int main()
{
    for(int i=0; i<4; i++){
        printf("%s\n","uuuuu");
        }
}



#include <stdio.h>

int main()
{
    for(int i=0; i<40; i++){
        printf("%s","-");
        }
     printf("\n");
    for(int i=0; i<10; i++){
        printf("%s","_-^-");
        }
    printf("\n");
    for(int i=0; i<2; i++){
        printf("%s","11223344556677889900");
    }
     printf("\n");
    for(int i=0; i<40; i++){
        printf("%s","-");
    }
}


#include <stdio.h>

int main()
{
    for(int i=0; i<3; i++){
        for(int j=0; j< 10; j++){
            for(int z=0; z<3; z++){
                printf("%d",j);
            }
        }
        printf("\n");
    }
}

#include <stdio.h>

int main()
{
        for(int j=0; j<5; j++){
          int n = 2*j+1;
          for(int i = 0; i< 5-j; i++){
              printf("-");
          }
            for(int z=0; z<n; z++){
                printf("%d",n);
            }
            for(int i = 0; i< 5-j; i++){
              printf("-");
          }
            printf("\n");
        }
}


#include <stdio.h>

int main()
{
        for(int j=0; j<6; j++){
          for(int i= 0; i<2*j;i++){ 
            printf("\\");
          }
          for(int i= 0; i<22-4*j; i++){ 
              printf("!");
          }
          for(int i= 0; i<2*j; i++){ 
              printf("/");
          }
            printf("\n");
        }
}

#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
        for(int j=0; j<n; j++){
          for(int i= 0; i<2*j;i++){ 
            printf("\\");
          }
          for(int i= 0; i<(n*3+(n-2))-4*j; i++){ 
              printf("!");
          }
          for(int i= 0; i<2*j; i++){ 
              printf("/");
          }
            printf("\n");
        }
}




#include <stdio.h>

int main()
{
    for(int i=0; i<7; i++){
        for(int j=0; j<2*i; j++){
            printf("*"); 
        }
        for(int j=0; j<7-i; j++){
            printf("$"); 
        }
        for(int j=0; j<14-(2*i); j++){
            printf("*"); 
        }
        for(int j=0; j<7-i; j++){
            printf("$"); 
        }
        for(int j=0; j<2*i; j++){
            printf("*"); 
        }
        printf("\n");
    }
}

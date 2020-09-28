/*
 * main.c
 *
 *  Created on: 14 sep. 2020
 *      Author: Viviana
 */

#include <stdio.h>
#include "main.h"
#include <stdarg.h>

/************************************************************************
 * 
 * Funcion que retorna un entero sin signo de 32 bits. La salida
 * de la función contiene los dos bits menos significativos del 
 * primer parámetro variable, luego el par de bits de las 
 * posiciones 2 y 3 del siguiente parámetro variable y así sucesivamente.
 * 
 ***********************************************************************/
unsigned int codificandoParesBits(unsigned short int bits,...){
	unsigned int answer = 0;
	unsigned int bitOnUse = 0;
	unsigned int mask = 3; // 00011 
	unsigned int bitWithMask = 0;
	va_list vl;
	va_start(vl, bits);

	if(bits > 16){  // ignorar despues de 16 int
		bits = 16;
	}

	for(int i = 0; i< bits;i++){
		bitOnUse = va_arg(vl, unsigned int);//Toma el siguiente parametro. 

		 if(i >= 8 || i>16){ // despues de 8 bits, se tiene que recorrer para seguir llenando la respuesta. 
			 bitOnUse <<= 16; // por cada i hay dos parejas por lo que i=8.... bits en respuesta = 16.
		 }
		 
		bitWithMask = bitOnUse & mask; // cambia a ceros menos la pareja.  
		answer = answer + bitWithMask; // agrega a la respuesta. 
        	mask = mask*4;
	}
	    
	va_end(vl);
	return answer;
}

int prueba_de_0(){
    unsigned int n = codificandoParesBits(0);
    int answer = (n==0)? 1:0;
    return answer;
}

int prueba_de_3(){
    unsigned int n = codificandoParesBits(3,2,8, 32);
    int answer = (n== 42)? 1:0;
    return answer;
}

int prueba_de_18(){
    
    unsigned int n = codificandoParesBits(18, 65535,65535,65535,65535,65535,65535,65535,65535,65535,65535,65535,65535,65535,65535,65535,65535,0,0);
    int answer = (n==4,294,967,295)? 1:0;
    return answer;
}


int main(){
    prueba_de_0();
    prueba_de_3();
    prueba_de_18();
	return 0;
}

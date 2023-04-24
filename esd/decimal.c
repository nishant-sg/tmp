#include <reg51.h>

sbit L = P1^0  ;
sbit M = P1^1 ;	 
sbit A = P1^2  ;
sbit E = P1^3 ;
sbit C = P1^4  ;
sbit D = P1^5 ;
sbit N = P1^6  ;
sbit O = P1^7 ;


void intToBin(int);	   
void delay(int);
void main(){
	int i;
	while(1){
		for (i = 0;i<256;i++){ 	
			intToBin(i);
			delay(5);	 ;
		M = 0;	
		A = 0;
		E = 0;
		C = 0;
		D = 0;
		N = 0;
		O = 0; 
		L = 0;	
		}
		
			delay(20);	 
	}
}

void intToBin(int n){
	int binaryNum[8];
	int i = 0;
	while(n>0){
		binaryNum[i] = n%2;
		n = n/2;
		i++	;
	}
	L = binaryNum[7];
	M = binaryNum[6]; 
	A = binaryNum[5];
	E = binaryNum[4];
	C = binaryNum[3];
	D = binaryNum[2];
	N = binaryNum[1];
	O = binaryNum[0];


}

void delay(int x){
	int i,j;
	for (i=0;i<x;i++){
		for (j = 0;j<10000;j++){
			
		}
	}
}
#include<reg51.h>

#define SegOne   0xfe

sbit led1 = P3^4;
sbit led2 = P3^5;
sbit led3 = P3^6;
sbit led4 = P3^7;
sbit but0 = P1^0;
sbit but1 = P1^1;
sbit but2 = P1^2;
sbit but3 = P1^3;
sbit but4 = P1^4;
sbit but5 = P1^5;
sbit but6 = P1^6;
sbit but7 = P1^7;
sbit screen1 = P3^0;
sbit screen2 = P3^1;
sbit screen3 = P3^2;
sbit screen4 = P3^3;
void DELAY_ms(unsigned int ms_Count) 
{
    unsigned int i, j;
    for (i = 0; i < ms_Count; i++) 
    {
        for (j = 0; j < 100; j++);
    }
}

int main() {
		int c =700;
		int i1=0;
		int i = 0;
		int h=0;
		int l=0;
		int k=0;
		int b1 =0;
		int b2 =0;
		int buff[9] = {0,0,0,0,0,0,0,0,0};
    char hexvalue[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71};
		int current = 0;
		int target = 0;
		P1 = 0;
		P3 = 0;
    P2 = hexvalue[current]; 
		screen1 =1;
		screen2 =1;
		screen3 =1;
		screen4 =0;
		while(1){
		int c =500;
			while(c>0){
				DELAY_ms(10);
				if(but0==1){
					buff[0] = 1;
					DELAY_ms(100);
				}else if(but1==1){
					buff[1] = 1;
					DELAY_ms(100);
				}else if(but2==1){
					buff[2] = 1;
					DELAY_ms(100);
				}else if(but3==1){
					buff[3] = 1;
					DELAY_ms(100);
				}else if(but4==1){
					buff[4] = 1;
					DELAY_ms(100);
				}else if(but5==1){
					buff[5] = 1;
					DELAY_ms(100);
				}else if(but6==1){
					buff[6] = 1;
					DELAY_ms(100);
				}else if(but7==1){
					buff[7] = 1;
					DELAY_ms(100);
				}
					led1= 1;
					led2= 1;
					led3= 1;
					led4= 1;
				c=c-1;
			}
			
			
					led1= 0;
					led2= 0;
					led3= 0;
					led4= 0;
				k=current;
				while(k<8){
					if (buff[k]==1){
						h = k;
					 k = k+8;
					}
					k=k+1;
				}
				k=current;
				while(k>=0){
					if (buff[k]==1){
						l = k;
					 k = k-8;
					}
					k=k-1;
				}
		if((h-current)>(current-l)){
				for(i=current; i<7;i++){
				if(buff[i]==1){
					target = i;
					while (target!=current) 
    { 
				DELAY_ms(2000);
				if (target>current){
					led1= 1;
					led2= 1;
					led3= 1;
					current+=1;
				}else{
					led2= 1;
					led3= 1;
					led4= 1;
					current-=1;
					
				}
				
					
        P2 = hexvalue[current];
					buff[target]=0;
				
        
    }
		led1= 0;
					led2= 1;
					led3= 1;
					led4= 0;
				DELAY_ms(2000);
				}
			}
			}else{
				for(i=current; i>=0;i--){
				if(buff[i]==1){
					target = i;
					while (target!=current) 
    { 
				DELAY_ms(2000);
				if (target>current){
					led1= 1;
					led2= 1;
					led3= 1;
					current+=1;
				}else{
					led2= 1;
					led3= 1;
					led4= 1;
					current-=1;
					
				}
				
					
        P2 = hexvalue[current]; 
					buff[target]=0;
				
        
    }
		led1= 0;
					led2= 1;
					led3= 1;
					led4= 0;
				DELAY_ms(2000);
				}
			}
			}
		}
}
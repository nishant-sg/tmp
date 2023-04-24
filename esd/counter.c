#include<reg51.h>

sbit rs = P1^0;
sbit e = P1^1;
sbit n0 = P3^0;
sbit n1 = P3^1;
sbit n2 = P3^2;
sbit n3 = P3^3;
sbit n4 = P3^4;
sbit n5 = P3^5;
sbit n6 = P3^6;
sbit n7 = P3^7;
sbit n8 = P1^2;
sbit n9 = P1^3;
sbit om = P1^4;
sbit oa = P1^5;
sbit os = P1^6;
sbit oe = P1^7;
sbit led = P3^7;
sbit buz = P3^6;

void delay(int x){
int i,j;
for (i=0; i<x; i++){
for(j=0;j<10000;j++){}
}
}

void write_command(int k){
rs = 0;
P2 = k;
e = 1;
delay(1);
e = 0;
}

void write_data(char x){
rs = 1;
P2 = x;
e = 1;
delay(1);
e = 0;
delay(1);
}

void lcd_init(){
P1 = 0;
P2 = 0;
P3 = 0;
write_command(0x38);
write_command(0x0c);
write_command(0x01);
write_command(0x80);
write_command(0x06);
}

void main(){
char output[5] = {'0','0','0','0','0'};
int oindex = 0;
int k;
int temp=0;
int number1 = 0;
int number2 = 0;
int out = 0;
int o1 = 0;  // add
int o2 = 0; //sub
int o3 = 0; //mul
int o4 = 0;
int c = 1;
int i = 0;
lcd_init();
led = 0;
buz = 0;
while (1){
buz = 0;
i+=1;
if (i%1 == 0){
output[4] = output[4] +1;
if (output[4]=='4'){
output[4] = '0';
led = 1;
c = 1;
o1 = 0;
o2 = 0;
o3 = 0;
o4 = 0;
}
}
write_command(0x01);
write_data(output[0]);
write_data(' ');
write_data(output[1]);
write_data(' ');
write_data(output[2]);
write_data(' ');
write_data(output[3]);
write_data(' ');
write_data(output[4]);
write_data(' ');
delay(20);
if(led == 1){
if (n0==1){
output[0] = output[0] + 2;
buz = 1;
delay(2);
led = 0;
o1  =1 ;
}else if (n1==1){
output[1] = output[1] + 2;
led = 0;
buz = 1;
delay(2);
o2  =1 ;
}else if (n2==1){
output[2] = output[2] + 2;
led = 0;
buz = 1;
delay(2);
o3  =1 ;
}else if (n3==1){
output[3] = output[3] + 2;
led = 0;
buz = 1;
delay(2);
o4  =1 ;
}
}
delay(10);
if(led == 0 && c==1){
if (n0==1 && o1 == 0){
output[0] = output[0] + 1;
led = 0;
c = 0;
}else if (n1==1 && o2 == 0){
output[1] = output[1] + 1;
led = 0;
c = 0;
}else if (n2==1 && o3 == 0){
output[2] = output[2] + 1;
led = 0;
c = 0;
}else if (n3==1 && o4 == 0){
output[3] = output[3] + 1;
led = 0;
c = 0;
}
}

}

}
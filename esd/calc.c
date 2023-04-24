											
#include<reg51.h>

#define display_port P1      //Data pins connected to port 2 on microcontroller

sbit rs = P2^0;  //RS pin connected to pin 2 of port 3
//sbit rw = P2^1;  // RW pin connected to pin 3 of port 3
sbit e =  P2^1;  //E pin connected to pin 4 of port 3
sbit C4 = P3^7;     // Connecting keypad to Port 1
sbit C3 = P3^6;
sbit C2 = P3^5;
sbit C1 = P3^4;
sbit R4 = P3^3;
sbit R3 = P3^2;
sbit R2 = P3^1;
sbit R1 = P3^0;
int val=0,val1,val2 ,val3,reverse,n,remainder,i;
void msdelay(unsigned int time)  // Function for creating delay in milliseconds.
{
    unsigned i,j ;
    for(i=0;i<time;i++)    
    for(j=0;j<1275;j++);
}

void lcd_cmd(unsigned char command)  //Function to send command instruction to LCD
{
    display_port = command;
    rs= 0;
    e=1;
    msdelay(1);
    e=0;
}

void lcd_data(unsigned char disp_data)  //Function to send display data to LCD
{
    display_port = disp_data;
    rs= 1;
    e=1;
    msdelay(1);
    e=0;
}


 void lcd_init()    //Function to prepare the LCD  and get it ready
{
    lcd_cmd(0x38);  // for using 2 lines and 5X7 matrix of LCD
    msdelay(10);
    lcd_cmd(0x0F);  // turn display ON, cursor blinking
    msdelay(10);
    lcd_cmd(0x01);  //clear screen
    msdelay(10);
    lcd_cmd(0x80);  // bring cursor to position 1 of line 1
    msdelay(10);
}
void first(){
char a[13] = "FIRST NUMBER" ;
int i;
for(i=0;i<13;i++){
lcd_data(a[i]);
}
lcd_cmd(0xC0);
}
void second(){

char a[15] = "SECOND NUMBER";
int i;
for(i=0;i<15;i++){
lcd_data(a[i]);
}
lcd_cmd(0xC0);
}



void row_finder1() //Function for finding the row for column 1
{
R1=R2=R3=R4=1;
C1=C2=C3=C4=0;
if(R1==0){
val = val *10 + 7;
lcd_data('7');
}
if(R2==0){
val = val *10 + 4;
lcd_data('4');
}
if(R3==0){
val = val *10 + 1;
lcd_data('1');
}
if(R4==0){
lcd_init();
first();
val=0;

}
}
void row_finder2() //Function for finding the row for column 2
{
R1=R2=R3=R4=1;
C1=C2=C3=C4=0;
if(R1==0){
val = val *10 + 8;
lcd_data('8');
}
if(R2==0){
val = val *10 + 5;
lcd_data('5');
}
if(R3==0){
val = val *10 + 2;
lcd_data('2');
}
if(R4==0){
val = val *10 + 0;
lcd_data('0');
}
}
void row_finder3() //Function for finding the row for column 3
{
R1=R2=R3=R4=1;
C1=C2=C3=C4=0;
if(R1==0){
val = val *10 + 9;
lcd_data('9');
}
if(R2==0){
val = val *10 + 6;
lcd_data('6');
}
if(R3==0){
val = val *10 + 3;
lcd_data('3');
}
if(R4==0){
val2 = val;
if(val3==4)
val=val1/val2;
else if (val3==3)
val=val1*val2;
else if(val3==2)
val = val1-val2;
else
val = val1 + val2;
lcd_data('=');
lcd_init();
if(val<0)
n = 0-val;
else
n=val;

reverse =0;
while (n != 0) {
    remainder = n % 10;
    reverse = reverse * 10 + remainder;
    n /= 10;
  }
 if(val3==4){
 lcd_data('D');
 lcd_data('I');
 lcd_data('V');
 lcd_data('I');
 lcd_data('D');
 lcd_data('E');
 lcd_data(':');
 }
 else if (val3 ==3){
 lcd_data('M');lcd_data('U');lcd_data('L');lcd_data('T');lcd_data('I');lcd_data('P');lcd_data('L');lcd_data('Y');lcd_data(':');}
 else if(val3 == 2){
 lcd_data('S');lcd_data('U');lcd_data('B');lcd_data('T');lcd_data('R');lcd_data('A');lcd_data('C');lcd_data('T');lcd_data(':');}
 else{
 lcd_data('A');lcd_data('D');lcd_data('D');lcd_data(':');}
 lcd_cmd(0xC0);
 if(val<0)
 lcd_data('-');
 while(reverse!=0){
lcd_data('0'+reverse%10);
reverse/=10;
}
n= val;
 while(n%10==0){
  lcd_data('0');
n/=10;
 }
}
}
void row_finder4() //Function for finding the row for column 4

{
R1=R2=R3=R4=1;
C1=C2=C3=C4=0;
val1 = val;
val = 0;
if(R1==0){
val3 = 4;
lcd_data('/');
}
if(R2==0){
val3 =3;
lcd_data('*');
}
if(R3==0){
val3 =2 ;
lcd_data('-');
}
if(R4==0){
val3=1;
lcd_data('+');
}
lcd_init();
second();
}


void main()

{
    lcd_init();
first();
    while(1)
    {    
        msdelay(30);
        C1=C2=C3=C4=1;
          R1=R2=R3=R4=0;
          if(C1==0)
          row_finder1();
          else if(C2==0)
           row_finder2();
           else if(C3==0)
        row_finder3();
        else if(C4==0)
        row_finder4();
    }
}
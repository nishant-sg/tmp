#include<reg51.h>
void lcd_init(void);
void writecmd(int);
void writedata(char);
void delay(int);

sbit RS = P2^0;
sbit E  = P2^1;
sbit led = P2^3;
sbit button = P2^2;

int i=0;
char s[16] = {'N','I','S','H','A','N','T',' ',' ',' ',' ',' ',' ',' ',' ',' '};
char tmp;
void main()
{
//P0 = 0x00;   //not used
P1 = 0x00;   //output port for setting RS and EN
P2 = 0x00;   //used as data output port
//P3 = 0x00;   //not used
led = 0;
lcd_init();

while(1){
writecmd(0x80);    //force cursor to beginning of 1st line
for(i = 0;i<=16;i++){
writedata(s[i]);
delay(200);
}
tmp = s[15];
for (i = 15;i>0;i--){
s[i] = s[i-1];
}
s[0] = tmp;
if (button ==1){
led = 1;
}else{
led = 0;
}
}

delay(5000000);
writecmd(0x01);
}



void lcd_init(void)

{

writecmd(0x38);    //for 8 bit mode
writecmd(0x0C);    //display on, cursor off
writecmd(0x01);    //clear display
writecmd(0x80);    //force cursor to beginning of 1st line

}

void writedata(char t)    //data function
{

  RS = 1;            
  P1= t;                       //Data transfer
E  = 1;            
delay(150);
E  = 0;          
delay(150);
}

void writecmd(int z)     //command function
{
RS = 0;            
  P1= z;                       //Data transfer
E  = 1;            
delay(150);
E  = 0;          
delay(150);
}

void delay(int a)          //Delay function
{
int i;
for(i=0;i<a;i++);  
}
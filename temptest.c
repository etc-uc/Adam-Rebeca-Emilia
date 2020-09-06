#include "math.h"
unsigned int temp;                      //Declarare variabila de salvare valoare intreaga fara semn a portii analogice pentru senzor temperatura
unsigned int calib;                     // Declarare valoare de calibrare
unsigned int comp1;                    //Declarare variabila de salvare valoare intreaga fara semn a valorii scalaate pentru senzor temperatura
unsigned int tempcalc;                 // Declarare variabil intreaga fara semn pentru senzor temperatura in plaja de tensiune de lucru


void main()
{

unsigned int a,b,c,d,e,f,g,h,j;        //Declarare variabile de salvare valoare fractionata a valorii analogice . Variabile folosite pentru afisare


unsigned int seg[]={0xC0,              //Valoare Hex pentru afisare numar 0
                    0xF9,              //Valoare Hex pentru afisare numar 1
                    0xA4,              //Valoare Hex pentru afisare numar 2
                    0xB0,              //Valoare Hex pentru afisare numar 3
                    0x99,              //Valoare Hex pentru afisare numar 4
                    0x92,              //Valoare Hex pentru afisare numar 5
                    0x82,              //Valoare Hex pentru afisare numar 6
                    0xF8,              //Valoare Hex pentru afisare numar 7
                    0x80,              //Valoare Hex pentru afisare numar 8
                    0x90,              //Valoare Hex pentru afisare numar 9
                    0x7F,              //Valoare Hex pentru afisare punct
                    0x9C               //Valoare Hex pentru afisare grade
                   };
unsigned int seg2[]={0x40,             //Valoare Hex pentru afisare numar 0.
                    0x79,              //Valoare Hex pentru afisare numar 1.
                    0x24,              //Valoare Hex pentru afisare numar 2.
                    0x30,              //Valoare Hex pentru afisare numar 3.
                    0x19,              //Valoare Hex pentru afisare numar 4.
                    0x12,              //Valoare Hex pentru afisare numar 5.
                    0x02,              //Valoare Hex pentru afisare numar 6.
                    0x78,              //Valoare Hex pentru afisare numar 7.
                    0x00,              //Valoare Hex pentru afisare numar 8.
                    0x10               //Valoare Hex pentru afisare numar 9.

                   };


ANSEL  = 1;                           //Declarare variabila analogica pentru cea mai mica valoare
ANSELH = 1;                           //Declarare variabila analogica pentru cea mai mare valoare
C1ON_bit = 1;                          //Dezactivare functie comparator
C2ON_bit = 1;                          //Dezactivare functie comparator

ANSELH.ANS0 = 1;                      //Declarare Poarta A0 analogica
TRISA.TRISA0 = 1;                     //Declarare Poarta A0 intrare analogica
ANSELH.ANS1 = 1;                      //Declarare Poarta A1 analogica
TRISA.TRISA1 = 1;                     //Declarare Poarta A1 intrare analogica
ANSELH.ANS2 = 0;                      //Declarare Poarta A2 I/O
TRISA.TRISA2 = 0;                     //Declarare Poarta A2 iesire diditala
TRISA.TRISA5 = 1;                     //Declarare Poarta A5 iesire diditala


//TRISA  = 0xFF;                      //Incrementatre valoare Poarti A cu 0
TRISC=0X00;                           //Declarare Poarti C iesire diditala
PORTC=0X00;                           //Incrementatre valoare Poarti C cu 0
TRISB=0x00;                           //Declarare Poarti B iesire diditala
PORTB=0X00;                           //Incrementatre valoare Poarti B cu 0


while(1)                              //Start functie program
{
temp = ADC_Read(0);                   //Incrementare variabil intreaga fara semn pentru senzor temperatura cu valoarea citita in  timp real a portii analogice A0
tempcalc=((100.0*temp*5.0)/1024);     //Scalare variabil intreaga fara semn pentru senzor temperatura in plaja de tensiune de lucru
calib= 10.0;                          // Declarare valoare de calibrare
comp1= tempcalc*calib;                // Calcul valoare intreaga pentru temperatura


  //Functie de extragere si salvare a celor 4 biti din valoarea variabilei scalata analogica //
a=comp1%10;                           //Dividere si salvare bitul 4
b=comp1/10;
c=b%10;                              //Dividere si salvare bitul 3
d=b/10;
e=d%10;                              //Dividere si salvare bitul 2
f=d/10;
g=f%10;                              //Dividere si salvare bitul 1
h=f/10;
j=11;                                //salvare caracter grade





PORTC=seg[g];                       //Incrementare poarta C cu valoarea segmentului corespunzatoare bitului 1 incepand de la stanga la dreapta a afisajului
PORTB.RB7=1;                        //Aprindere display 1 incepand de la stanga la dreapta si afisarea bitului 4
delay_ms(5);
PORTB.RB7=0;                        //Oprire display 1 incepand de la stanga la dreapta dupa un delay de 5ms


PORTC=seg2[e];                      //Incrementare poarta C cu valoarea segmentului corespunzatoare bitului 2 incepand de la stanga la dreapta a afisajului
PORTB.RB6=1;                        //Aprindere display 2 incepand de la stanga la dreapta si afisarea bitului 3
delay_ms(5);
PORTB.RB6=0;                        //Oprire display 2 incepand de la stanga la dreapta dupa un delay de 5ms


PORTC=seg[c];                        //Incrementare poarta C cu valoarea segmentului corespunzatoare bitului 3 incepand de la stanga la dreapta a afisajului
PORTB.RB5=1;                         //Aprindere display 3 incepand de la stanga la dreapta si afisarea bitului 2
delay_ms(5);
PORTB.RB5=0;                         //Oprire display 3 incepand de la stanga la dreapta dupa un delay de 5ms


PORTC=seg[j];                        //Incrementare poarta C cu valoarea segmentului corespunzatoare bitului grade incepand de la stanga la dreapta a afisajului
PORTB.RB4=1;                         //Aprindere display 4 incepand de la stanga la dreapta si afisarea bitului 1
delay_ms(5);
PORTB.RB4=0;                         //Oprire display 4 incepand de la stanga la dreapta dupa un delay de 5ms

}

}
//Oliver Garcia C.I:32.396.121
//Luis Lira C.I.:31.564.286
#include<stdio.h>
int main(){
int fortuna=0;

do{
printf("\tSeleccione un numero\n");
scanf("%d",&fortuna);
switch(fortuna)
{
case 1:
    printf("su fortuna es aprender a usar switch y case\n");
    break;
    case 2:
    printf("su fortuna es econtrarse 100$ en la calle\n");
    break;
default:
    printf("sea serio ombe pon la vaina como eh!!\n");
    }
}while(fortuna<1||fortuna>7);
return 0;
}

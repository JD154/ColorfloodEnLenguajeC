#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>

#define F 25
#define C 25

// FUNCION GOTOXY
 void gotoxy(int x,int y){  
HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
COORD dwPos;
dwPos.X=x;
dwPos.Y=y;
SetConsoleCursorPosition(hcon, dwPos);
 } 

//FUNCION PARA COLOREAR
void color(int x){
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon,x);
}

//FUNCION QUE CREA LA PANTALLA DE INICIO
void inicio (){
	
for(int x=1;x<=50;x++){ 
	color(19);
	gotoxy(x,1); 
	printf(" "); 
	gotoxy(x,7);
	printf(" "); 

} 

for(int y=1;y<=7;y++){ 
	gotoxy(1,y); 
	printf(" ");
	gotoxy(50,y); 
	printf(" ");
} 
color(14);
gotoxy(21, 3); printf("Saludos"); 
gotoxy(22, 4); printf("Desde"); 
color(3); gotoxy(20, 5); printf("C"); 
color(2); gotoxy(21, 5); printf("O");
color(12); gotoxy(22, 5); printf("L");
color(13); gotoxy(23, 5); printf("O");
color(9); gotoxy(24, 5); printf("R");
color(7); gotoxy(25, 5); printf("F");
color(11); gotoxy(26, 5); printf("L");
color(5); gotoxy(27, 5); printf("O");
color(2); gotoxy(28, 5); printf("O");
color(6); gotoxy(29, 5); printf("D");


color(14); gotoxy(6, 10); printf("UN COLORIDO JUEGO PARA DESAFIAR TU MENTE"); 
color(7);
	
gotoxy(1, 25);	getch();
}

//FUNCION QUE PIDE DIFICULTAD
int dificultad (){
	
	int difil;
	
	do{
		
	system ("cls");
	gotoxy (12,1); printf ("Bienvenido al menu de dificultad");
	gotoxy (3,3); printf ("1.- Aprendiz");
	gotoxy (3,4); printf ("2.- Entendido");
	gotoxy (3,5); printf ("3.- Modo Dios");
	gotoxy (3,7); printf ("Por favor seleccione un nivel de dificultad: ");
	
	scanf ("%d", &difil);
	
	}while (difil<0 && difil>3);
	
	system ("cls");
	
	return difil;

}

//FUNCION QUE GENERA LA MATRIZ ALEATORIA
void generarmapa (int mapa[F][C], int m1, int m2){	

	for(int i=0; i<m1; i++)
		for(int j=0; j<m2; j++)
		mapa[i][j]=rand()%5+1;		
}

//FUNCION PARA COLOREAR LA MATRIZ
void colorear(int mapa[F][C], int m1, int m2){

	int imprimircolor;

	color (7);
	imprimircolor=mapa[0][0];
	mapa[0][0]=0;
	
	if (mapa[0][0]==0){
		
		if (imprimircolor==1){color(14);	printf("%c",219);}
		if (imprimircolor==2){color(2);		printf("%c",219);}
		if (imprimircolor==3){color(12);	printf("%c",219);}
		if (imprimircolor==4){color(5); 	printf("%c",219);}
		if (imprimircolor==5){color(9);		printf("%c",219);}
	}
	
	
	for(int i=0; i<m1; i++){
		for(int j=0; j<m2; j++){

			color(14);
			if(mapa[i][j]==1){printf("%c",219);}
			color(2);
			if(mapa[i][j]==2){printf("%c",219);}
			color(12);
			if(mapa[i][j]==3){printf("%c",219);}
			color(5);   
			if(mapa[i][j]==4){printf("%c",219);}
			color(9);
			if(mapa[i][j]==5){printf("%c",219);} 
		}
		printf("\n");
	}
	
	color (7);
	
 /*VER COMO FUNCIONA CON NUMEROS	
	for(int i=0;i<m1;i++){
		for(int j=0;j<m2;j++){
			printf("%d",mapa[i][j]);
		}
		printf("\n");
	}*/
}

//FUNCION PARA PODER CONTROLAR COLORES Y JUGAR
void jugar (int mapa[F][C], int m1, int m2, int movi){
	
	int num, col, i, j, totalma, bander=0;
	
	do{
		col=0;
		totalma=0;
		
		color(14); gotoxy (1,m2+2); printf ("Te quedan %d movimientos", movi);
		
		do{
		
			color (14); gotoxy(m1+7, 2); printf ("AMARILLO: 1");
			color (2);  gotoxy(m1+7, 3); printf ("VERDE: 2");
			color (12); gotoxy(m1+7, 4); printf ("ROJO: 3");
			color (5); gotoxy(m1+7, 5); printf ("MORADO: 4");
			color (9);  gotoxy(m1+7, 6); printf ("AZUL: 5");
			gotoxy (1, m2+4); color(14); printf ("Color seleccionado: ");
			scanf ("%d", &num);
			color (7);
	
		}while (num>=6);
		
	//variable que permite almacenar el valor del color
	col=num;
	
	color (7);
	
	system("cls");	
		
	for (i=0; i<m1; i++){
		for (j=0; j<m2; j++){
			
			if(mapa[i][j]==0){
				if (mapa[i+1][j]==num)
					mapa[i+1][j]=0;
				if (mapa[i-1][j]==num && i-1>0)
					mapa[i-1][j]=0;		
				if (mapa[i][j+1]==num)
					mapa[i][j+1]=0;
				if (mapa[i][j-1]==num && j-1>0)
					mapa[i][j-1]=0;	
			}
			
			//Permite saber si la matriz está llena de ceros
			totalma=totalma+mapa[i][j];	
		}
	}
	
/* VER COMO FUNCIONA CON NUMEROS	
	for (int i=0; i<m1; i++){
		for (int j=0; j<m1; j++){
			printf("%d",mapa[i][j]);
			}
			printf("\n");	
		}*/
		
	for(int i=0; i<m1; i++){
		for(int j=0; j<m2; j++){
			
			//Según el valor de la variable col, yo le asigno un color a las posiciones [i][j] en 0 (resueltas)
			if (mapa[i][j]==0){
				
				if (col==1){color(14); printf("%c",219);}
				if (col==2){color(2);  printf("%c",219);}
				if (col==3){color(12); printf("%c",219);}
				if (col==4){color(5);  printf("%c",219);}
				if (col==5){color(9);  printf("%c",219);}		
			}
			
			if(mapa[i][j]==1){color(14);	printf("%c",219);}
			if(mapa[i][j]==2){color(2);		printf("%c",219);}
			if(mapa[i][j]==3){color(12);	printf("%c",219);}
			if(mapa[i][j]==4){color(5);		printf("%c",219);}
			if(mapa[i][j]==5){color(9);		printf("%c",219);} 
		}
		
		printf("\n");
	}
	
	//contador de movimientos en resta
	movi--;	
	
	//permite comprobar si se acabaron los movimientos o se completó la matriz
	if (totalma==0)
		bander=1;
	if (movi==0)
		bander=1;
						
	}while(bander<1);
	
	system ("cls");
	
	color(14);
	
	if (totalma==0){
		system ("cls");
		gotoxy (5,1); printf ("Felicitaciones!");
		gotoxy (5,3); printf ("GANASTE LA PARTIDA");
		gotoxy (5,5); printf ("Te desafio a que lo intentes de nuevo");
		gotoxy (5,8); printf ("Presiona cualquier tecla para ir al menu");
	}	
	if (movi==0){
		system ("cls");
		gotoxy (5,1); printf ("Lo siento :(");
		gotoxy (5,2); printf ("Perdiste");
		gotoxy (5,4); printf ("Vuelve a intentarlo!");
		gotoxy (5,7); printf ("Presiona cualquier tecla para ir al menu");
	}	
	
	if (movi==0 && totalma==0){
		system ("cls");
		gotoxy (8,1); printf ("WOW!");
		gotoxy (5,2); printf ("Ganaste por poco");
		gotoxy (5,4); printf ("Mejora tu record");
		gotoxy (5,7); printf ("Presiona cualquier tecla para ir al menu");
	}
	
	color (7);	
}

int main() {
	
	int opc, x, m1, m2, movi;
	int mapa[F][C];
	
	srand(time(NULL));
	
	system ("cls");
	
	inicio();
	
	do{
		
	system ("cls");
	color(14); 
	gotoxy(4,0); printf ("Bienvenido al menu de opciones");
	gotoxy(4,2); printf ("1. Jugar");
	gotoxy(4,3); printf ("2. Ayuda");
	gotoxy(4,4); printf ("3. Creditos");
	gotoxy(4,5); printf ("4. Salir");
	gotoxy(4,7); printf ("Opcion escogida: ");
	scanf ("%d", &opc);
	system ("cls");
		switch(opc){
			case 1:
				system ("cls");
				x=dificultad();
				if (x==1){m1=10; m2=10; movi=18;}
				if (x==2){m1=12; m2=12; movi=22;}
				if (x==3){m1=18; m2=18; movi=27;}
				generarmapa(mapa, m1, m2);
				colorear(mapa, m1, m2);
				jugar(mapa, m1, m2, movi);
				getch();
				break;
			case 2:
				system ("cls");	
				gotoxy(30,0); printf ("Ayuda");
				gotoxy(4,2); printf ("COLORFLOOD ES UN JUEGO DE ROMPECABEZA, EN DONDE DEBES TRANSFORMAR TODOS");
				gotoxy(4,3); printf ("LOS BLOQUES DE COLORES QUE APARECEN EN LA PANTALLA, EN UN SOLO BLOQUE DE");
				gotoxy(4,4); printf ("UN MISMO COLOR. LA META DEL JUEGO ES LLENAR EL TABLERO DE UN SOLO COLOR,");
				gotoxy(4,5); printf ("EMPIEZAS CON EL CUADRO SUPERIOR IZQUIERDO Y DEBES CAMBIAR DE COLORES PARA");
				gotoxy(4,6); printf ("COLOREAR LOS CUADROS ADYACENTES, CONTINUA CAMBIANDO DE COLORES HASTA QUE");
				gotoxy(4,7); printf ("EL TABLERO ESTE COMPLETAMENTE PINTADO DE UN SOLO COLOR.");
				getch();
				break;
			case 3:
				system ("cls");
				gotoxy(15,0); printf ("Creditos");	
				gotoxy(4,2); printf ("Este programa ha sido hecho por:");
				gotoxy(5,4); printf ("Jesus Blanco seccion 09");
				gotoxy(5,6); printf ("Agradecimientos especiales:");
				gotoxy(5,8); printf ("Juan Diego");
				gotoxy(5,9); printf ("Guillermo");
				gotoxy(5,10); printf ("Jonathan");
				gotoxy(4,12); printf ("Universidad Experimental del Tachira 2016");
				getch();
				break;
			case 4: 
				system ("cls");	
				gotoxy(4,2); printf ("Gracias por haber jugado COLORFLOOD");
				gotoxy(4,3); printf ("Espero que te hayas divertido");
				getch();
				break;
			default:
				system ("cls");
				gotoxy(15,2); printf ("Error!");
				gotoxy(4,4); printf ("La opcion ingresada no es correta");
				getch();
				break;
			}	//switch
			
		}while (opc!=4);

	gotoxy (1, 15);
	return 0;
}

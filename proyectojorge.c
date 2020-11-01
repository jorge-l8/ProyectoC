#include <stdio.h>
#include <stdlib.h>


int main(void){
	int op, opeyp, ope, opp;
	/*Interfaz*/
	do{
		/*Imprimir opciones*****/
		switch(op){
			case 1:
				/*Codigo*/
			case 2:
				/*Codigo*/
				do{
					system("CLS");
					printf("MENU EMPRESAS Y PRODUCTOS\n");
					printf("1.-Entrar a Menu Empresas\n");
					printf("2.-Entrar a Menu Productos\n");
					printf("0.-Salir\n");
					scanf("%d",&opeyp);
					switch(opeyp){
						case 1:
							do{
								system("CLS");
								printf("\tMENU EMPRESAS\n")
								printf("1.-Agregar empresa\n");
								printf("2.-Modificar empresa\n");
								printf("3.-Consultar empresa\n");
								printf("4.-Eliminar empresa\n");
								printf("0.-Volver a menu inicial\n");
								scanf("%d",&ope);
								switch(ope){
									case 1:
										/*codigo*/
										break;
									case 2:
										/*codigo*/
										break;
									case 3:
										/*codigo*/
										break;
									case 4:
										/*codigo*/
										break;
									case 0:
										/*codigo*/
										break;
									default:
										/*codigo*/
										break;
								}
							}while(ope!=0);
							break;
						case 2:
							do{
								system("CLS");
								printf("\tMENU PRODUCTOS\n")
								printf("1.-Agregar producto\n");
								printf("2.-Modificar producto\n");
								printf("3.-Consultar producto\n");
								printf("4.-Eliminar producto \n");
								printf("0.-Volver a menu inicial\n");
								scanf("%d",&opp);
								switch(ope){
									case 1:
										/*codigo*/
										break;
									case 2:
										/*codigo*/
										break;
									case 3:
										/*codigo*/
										break;
									case 4:
										/*codigo*/
										break;
									case 0:
										/*codigo*/
										break;
									default:
										/*codigo*/
										break;
								}
							}while(opp!=0);
							break;
						default:
							/*codigo*/
							break;
					}
				}while(opeyp != 0);
			case 3:
				/*Codigo*/
			case 4:
				/*Codigo*/
			default:
				/*Codigo*/
		}
	}while(op!=0);
	return 0;
}

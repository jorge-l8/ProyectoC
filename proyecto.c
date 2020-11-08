#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <unistd.h>

/*AGREGAR ENCABEZADO CON NOMBRES*/

struct Personas /*Registro Personas*/
	{ 
		long ci;
		char na[20],cn[15],dip[40];
		int  fn;
		/*Falta el puntero a la lista de pedidos realizados para la segunda entrega*/
	};
	
struct Empresa /*Registro Empresas*/
	{
		int codigo,tipo;
		char nombre[20],direccion[40],telefono[12];
		struct Producto *p;
	};
	
struct Producto /*Registro Producto*/
	{
		int cod;
		char descripcion[20];
		int ppu;
		int activo;
	};
	
struct Envio  /*Registro Envio*/ 
	{	
		int entregado;
		int persona;
		int numfactura;
		struct Empresa *emp1;	
	};
	
/*Funciones de validacion y auxiliares*/
int validarnumeros(char *p);
void eliminarnl(char s1[]);
int validarstring(char *p);

/* Funciones Personas*/
void AgregarP(struct Personas *pers);
void ValidarP(struct Personas *pers);
void ConsultarP(struct Personas *pers);
void ModificarP(struct Personas *pers);
void EliminarP(struct Personas *pers);
int ValidarPN(struct Personas *pers);

/*Funciones Envios*/
void modificarenvio(struct Envio *p, int persona, int tipoe, int numfactura);
int consultarenvio(struct Envio *p, int num);
void mostrarenvio(struct Envio *p);
void cierreenvio(struct Envio *p);

/*Funciones Productos*/
void agregarproducto(struct Producto *prod, int cod, char descri[20], int ppu);
void mostrarproducto(struct Producto *prod);
void eliminarproducto(struct Producto *prod);


int main()
{
 int op,opp,opep,ope,oppe,opoe,opc,opce,opcp,opcs;
 struct Personas per;
 /*Variables parte empresas*/
 int modificar;
 struct Empresa emp1;
 /*Variables parte envios*/
 int  num, cod, opmeoe;
 struct Envio env1;
 struct Envio *p = NULL;
 /*Variables parte productos*/
 int cprod, ppu, opmepr, cond;
 char desc[20]; 
 struct Producto prod1;
 struct Producto *p1 = NULL;
 

 
 do
 {
/* Menu Principal */
	system("cls");
    printf("\t Sistema %cummy  \n\n",165);
    printf("\t Menu Principal \n\n");
    printf("1. PERSONAS \n");
    printf("2. EMPRESAS \n");
    printf("3. ORDENES DE ENVIO \n");
    printf("4. CONSULTAS \n");
    printf("0. SALIR \n");
   	printf("\n Introduzca una opcion: "); scanf("%d",&op);
   	system("cls");
  
    switch(op)
	{
       
        case 1: /* Menu Personas*/
         do
		 {   system("cls");
             printf("\t Bienvenido al Menu de Personas \n\n");
             printf("Que desea realizar?\n\n");
             printf("1. Agregar Personas \n");
             printf("2. Modificar Persona \n");
             printf("3. Consultar Persona \n");
             printf("4.. Eliminar Persona\n");
             printf("0. Volver al menu\n\n");
             printf("Introduzca una opcion: "); scanf("%d",&opp);
             system("cls");
              switch(opp)
              {
              	case 1: /* Agregar Persona*/
              	  printf("Introduzca los siguientes datos\n para agregar a una persona\n\n");
     	          AgregarP(&per);
		  ValidarPN(&per);	      
     	      
     	          system("cls");
              	break;
              	
              	case 2: /* Modificar Persona*/
              	  	printf("Modifique sus datos a su parecer (la cedula no se modifica)");
     	 	        ModificarP(&per);
              	    break;
               
               case 3: /* Consultar Persona*/
                    printf("Los datos de la persona introducidas son: \n\n");
         	ConsultarP(&per);
          	system("cls");
                    break;
                    
                case 4: /*Eliminar persona*/
                   EliminarP(&per);
           
             system("cls");
                break;
                
               case 0:
               		break;
               		
               default:
               	   printf("Opcion incorrecta debe introducir un numero entre 0 y 4. Intente nuevamente.\n");
               	   system("PAUSE");
               	   break;
			  }
   		 }while(opp!=0);
        break;
        
        case 2: /* Menu Empresas*/
	        do
	        {
	             system("cls");
	 			 printf("\t Bienvenido al Menu de Empresas y Productos \n\n"); printf("%c",168); 
				 printf("Donde desea entrar? \n\n");
				 printf("1. Menu Empresas \n");
				 printf("2. Menu Productos \n");  
				 printf("0. Volver al menu principal\n\n");
				 printf("Introduzca una opcion: ");	 scanf("%d",&opep);
				 system("cls");
				 switch(opep)
				 {
				 	case 1: /* Empresa*/
					do{
		 			   printf("\n\nBienvenido al menu de empresas \n\n"); printf("%c",168);
					   printf("Que desea hacer? \n");
					   printf("1. Agregar empresa \n");
					   printf("2. Modificar empresa \n");
					   printf("3. Consultar empresa \n");
					   printf("4. Eliminar empresa \n");
					   printf("0. Volver al menu \n\n");
					   printf("Introduzca una opcion: "); scanf("%d",&ope);
					   system("cls");
					   switch(ope)
					   {
					   	case 1: /* Agregar Empresa */
				   	struct Empresa emp1;
				   	do{
						printf("\nCodigo de empresa(0-9999): \n");
						scanf("%i",&emp1.codigo);
						system("cls");
						if(emp1.codigo<=0 || emp1.codigo>9999){
							printf("\nIntroduzca un numero entre 1 y 9999.\n\n");
							system("PAUSE");
						}
						system("cls");
					}while(emp1.codigo<=0 || emp1.codigo>9999);	
					do{	
						printf("\nNombre de empresa: \n");
						fflush(stdin);
						fgets(emp1.nombre, 20, stdin);
						system("cls");
						eliminarnl(emp1.nombre);
						if(!(validarstring(emp1.nombre))){
							printf("Validar string retorna: %d\n\n",validarstring(emp1.nombre));
							printf("Introduzca una cadena de caracteres. Intente nuevamente\n\n");
							system("PAUSE");
						}	
						system("cls");
					}while(!validarstring(emp1.nombre));
					do{
					printf("\nTipo de empresa \n");
					printf("\nOpciones: (1)Comida (2)Alimentos (3)General \n");
					scanf("%i",&emp1.tipo);
					if (emp1.tipo != 1 && emp1.tipo != 2 && emp1.tipo != 3){
						printf("\nNo selecciono bien la empresa. Vuelva a intentarlo\n\n");
						system("PAUSE");
					}
					system("cls");
					}while (emp1.tipo != 1 && emp1.tipo != 2 && emp1.tipo != 3);	
					do{
					printf("\nTelefono de la empresa: \n");
					fflush(stdin);
					fgets(emp1.telefono, 12, stdin);
					eliminarnl(emp1.telefono);
					if(!(validarnumeros(emp1.telefono))){
						printf("El telefono debe estar compuesto solo de numeros.\n\n");
						system("PAUSE");
					}					
					system("cls");
					}while(!(validarnumeros(emp1.telefono)));
					printf("\nDireccion de la empresa: \n");
					fflush(stdin);
					fgets(emp1.direccion, 40, stdin);
					system("cls");
				   	
				   	break;
				   	
				   	case 2: /* Modificar Empresa*/
				   	do{
						printf("\t\t%c",168); printf("Que desea modifica?: \n");
						printf("\t1. Codigo de empresa \n");
						printf("\t2. Nombre de empresa \n");
						printf("\t3. Tipo de empresa \n");
						printf("\t4. Telefono de empresa \n");   
						printf("\t5. Direccion de la empresa \n");
						printf("\t0. Volver al menu \n");
						printf("\tIntroduzca una opcion: "); scanf("%d",&modificar);
						system("cls");
						switch(modificar){	
				   			
							case 1: 
				   			struct Empresa emp1;	
								emp1.codigo = 0;
								do{
								printf("\nIntroduzca el nuevo codigo de empresa(0-9999): \n");
								scanf("%i",&emp1.codigo);
								system("cls");
									if(emp1.codigo<=0 || emp1.codigo>9999){
									printf("\nIntroduzca un numero entre 1 y 9999.\n\n");
									system("PAUSE");
									}
								system("cls");
								}while(emp1.codigo<=0 || emp1.codigo>9999);
							break;   		
						   	
						   	case 2:
							memset(emp1.nombre, 0, 20);	
								do{
								printf("\nIntroduzca el nuevo nombre de empresa: \n");
								fflush(stdin);
								fgets(emp1.nombre, 20, stdin);
								system("cls");
									eliminarnl(emp1.nombre);
										if(!(validarstring(emp1.nombre))){
										printf("Validar string retorna: %d\n\n",validarstring(emp1.nombre));
										printf("Introduzca una cadena de caracteres. Intente nuevamente\n\n");
										system("PAUSE");
									}	
									system("cls");
							}while(!validarstring(emp1.nombre));
							break;
					
						case 3:
						emp1.tipo = 0;
						do{
							printf("\nIntroduzca el nuevo tipo de empresa \n");
							printf("\nOpciones: (1)Comida (2)Alimentos (3)General \n");
							scanf("%i",&emp1.tipo);
								if (emp1.tipo != 1 && emp1.tipo != 2 && emp1.tipo != 3){
								printf("\nNo selecciono bien la empresa. Vuelva a intentarlo\n\n");
								system("PAUSE");
						}	
							system("cls");
						}while (emp1.tipo != 1 && emp1.tipo != 2 && emp1.tipo != 3);
						break;	
					
						case 4:
						memset(emp1.telefono, 0, 12);
						do{
							printf("\nIntroduzca el nuevo telefono de la empresa: \n");
							fflush(stdin);
							fgets(emp1.telefono, 12, stdin);
							eliminarnl(emp1.telefono);	
								if(!(validarnumeros(emp1.telefono))){
								printf("\nEl telefono debe estar compuesto solo de numeros.\n\n");
								system("PAUSE");
								}					
							system("cls");
						}while(!(validarnumeros(emp1.telefono)));
						break;
					
						case 5:
							memset(emp1.direccion, 0, 40);
							printf("\nIntroduzca la nueva direccion de la empresa: \n");
							fflush(stdin);
							fgets(emp1.direccion, 40, stdin);
							system("cls");
						break;
						}
				    }while (modificar!=0);
				   	
				   	break;
				   	
				   	case 3: /* Consultar Empresa*/
				   	printf("El codigo de la empresa es: %i",emp1.codigo);
					printf("\nEl nombre de la empresa es: %s",emp1.nombre);
					if (emp1.tipo == 1){
						printf("\nEl tipo de empresa es de Comida");
					}
					else if (emp1.tipo == 2){
						printf("\nEl tipo de empresa es de Alimentos");
					}
					else if (emp1.tipo == 3){
						printf("\nEl tipo de empresa es General");
					}
					printf("\nEl telefono de la empresa es: %s",emp1.telefono);
					printf("\nLa direccion de la empresa es: %s\n\n",emp1.direccion);
				   	system("pause");
				   	system("cls");
					break;
				   	
				   	
				   	case 4: /* Eliminar Empresa*/
				   	
					emp1.codigo = 0;
				   	memset(emp1.direccion, 0, 40);
				   	memset(emp1.nombre, 0, 20);
				   	memset(emp1.telefono, 0, 12);
				   	emp1.tipo = 0;
				   	printf("\tSe ha eliminado la empresa anteriormente agregada\n\n");
				   	
				   	break;
					   	
					   	case 0: /* Vuelve al menu*/
					   	break;
					   	
					   	default:
					   		printf("Opcion introducida incorrecta");
					   	break;
					   	
					   }
			    }while(ope!=0);
			 	break;
				 	
				 	case 2: /* Menu Productos*/
				 		p1 = &prod1;
					 	do
					 	{
					 	   system("cls");
					 	   printf("Bienvenido al Menu de Productos\n\n"); printf("%c",168);
					 	   printf("Que desea hacer? \n\n");
					 	   printf("1. Agregar producto \n");
					 	   printf("2. Modificar producto \n");
					 	   printf("3. Consultar producto \n");
					 	   printf("4. Eliminar producto \n");
					 	   printf("0. Volver al Menu Empresas y Productos\n\n");
					 	   printf("Introduzca una opcion: "); scanf("%d",&oppe);
					 	   
					 	   system("cls");
					 	   switch(oppe)
					 	   {
					 	   	 case 1: /* Agregar producto*/
					 	   	 	do{
									printf("\nIntroduzca el codigo de la empresa a la cual le desea agregar un producto: ");
						 	   		if (scanf("%d", &cprod)!=1 || (cprod<=0) ){
						 	   			cond = 1;
						 	   			printf("El codigo de la empresa debe ser numerico (mayor que 0). Intente nuevamente.\n");
						 	   			system("PAUSE");
										}
									else{
										if(cprod!=emp1.codigo){
											printf("No existe ninguna empresa en el sistema con el codigo '%d' introducido. Vaya al menu de empresas y agreguela.\n\n", cprod);
											system("PAUSE");
											break;
										}
										else{
										emp1.p = &prod1; /*Para segunda entrega debe ser un apuntador a la lista de pedidos realizados y solo se agrega el producto*/
										cond = 0;
										}
									system("PAUSE");
									}
								}while(cond);
								if(cprod!=emp1.codigo)
									break;

					 	   	 	do{
									printf("\n\n\tIntroduzca el codigo del producto: ");
									if (scanf("%d", &cprod)!=1 || cprod<=0){
						 	   	 		cond=1;
						 	   	 		printf("\n\nEl codigo del producto debe ser numerico (mayor que 0). Intente nuevamente.\n");
										system("PAUSE");
										system("CLS"); 
										 }
									else{
										cond = 0;
									}
								}while(cond);
					 	   	 	fflush(stdin);
					 	   	 	system("CLS");
					 	   	 	do{
						 	   	 	printf("\n\n\tIntroduzca una breve descripcion del mismo (no mayor a 20 caracteres): ");
						 	   	 	fgets(desc, 20, stdin);
						 	   	 	eliminarnl(desc);
						 	   		if(!validarstring(desc)){
						 	   			printf("\n\nDebe introducir una cadena que solo contenga caracteres alfabeticos\n");
						 	   			system("PAUSE");
						 	   			system("CLS");
										}
						 	   	}while(!(validarstring(desc)));
						 	   	fflush(stdin);
						 	   	system("CLS");
						 	   	do{
					 	   	 		printf("\n\n\tIntroduzca el precio por unidad: ");
					 	   	 		if(scanf("%d", &ppu)!=1){
					 	   	 				cond=1;
						 	   	 			printf("\n\nEl precio por unidad del producto debe ser numerico(mayor que 0). Intente nuevamente.\n");
											system("PAUSE");
											system("CLS"); 
										 }
									else{
										cond=0;
									}
					 	   	 	}while(cond);
					 	   	 	
								/*Pos validaciones se agregan los productos*/
					 	   	 	agregarproducto(&prod1,cprod,desc,ppu);
					 	   	 	system("\n\nPAUSE");
					 	   	 	system("CLS");
					 	   	    break;
					 	   	 
					 	   	 case 2: /* Modificar producto*/
					 	   	 		printf("\tIntroduzca que parte del producto desea modificar: \n");
							   		printf("\t\t1. Codigo\n");
							   		printf("\t\t2. Descripcion\n");
							   		printf("\t\t3. Precio Por Unidad\n");
							   		printf("\t\t4. Disponibilidad.\n\n");
							   		printf("\t\tOpcion: ");
							   		scanf("%d", &opmepr);
							   		system("CLS");
							   		switch(opmepr){
							   			case 1:
							   					/*modificar codigo*/
							   					printf("\tIntroduzca el nuevo codigo del producto: ");
							   					if (scanf("%d", &cprod)!=1 || cprod<=0){
							   						printf("\n\tEl codigo debe ser numerico (mayor que cero).\n");
												   }
												else{
													prod1.cod = cprod;
												}
							   					system("\n\n\tPAUSE");
							   					break;
							   				
							   			case 2:
							   					/*modificar descripcion*/
							   					printf("\tIntroduzca la nueva descripcion del producto: \n\t");
							   					fflush(stdin);
							   					fgets(desc, 20, stdin);
							   					eliminarnl(desc);
							   					if(!(validarstring(desc))){
							   						printf("\n\tInput invalido. Debe introducir solo letras del alfabeto o espacios en blanco.\n\n");
												   }
												else{
													strcpy(prod1.descripcion,desc);
												}
							   					system("\n\n\tPAUSE");
							   					break;
							   				
							   			case 3:
							   					/*modificar precio por unidad*/
							   					printf("\tIntroduzca el nuevo precio por unidad del producto: \n\t");
							   					if (scanf("%d", &ppu)!=1 || ppu<=0){
							   						printf("\n\tEl precio por unidad debe ser numerico (mayor que cero).\n\n");
												   }
												else{
													prod1.ppu = ppu;
												}
							   					system("\n\n\tPAUSE");
							   					break;
							   			
							   			case 4:
							   					/*modificar disponibilidad*/
							   					printf("\tIntroduzca la nueva disponibilidad del producto: \n");
							   					printf("\t\t0. No disponible.\n");
							   					printf("\t\t1. Disponible.\n\n");
							   					printf("\t\tOpcion: ");
							   					scanf("%d", &prod1.activo);
							   					break;
							   			
							   			default:
							   					printf("Numero invalido, el numero introducido debe estar entre 1 y 4. Intente nuevamente.\n\n");
							   					system("PAUSE");
							   					break;
									   }
							   		system("CLS");
					 	   	    	break;
			
					 	   	 case 3: /* Consultar producto*/
					 	   	 		printf("Introduzca el codigo del producto: ");
					 	   	 		scanf("%d", &cprod);
					 	   	 		if (cprod!=prod1.cod){
										 printf("No existe ningun producto con el codigo '%d' en el sistema.\n\n", cprod);
									}
									else{
										prod1.cod = cprod;
										mostrarproducto(&prod1);
									}
									system("\tPAUSE");
					 	   	  		break;
					 	   	 
					 	   	 case 4: /*Eliminar producto*/
					 	   	 	eliminarproducto(&prod1);
					 	   	    break;
					 	   	    
					 	   	 case 0:
					 	   	 	break;
					 	   	 
					 	   	 default:
					 	   	 	printf("Opcion incorrecta, debe introducir un numero entre 0 y 4. Intente nuevamente.\n\n");
					 	   	 	system("PAUSE");
        						break;
					       }
					    }while(oppe!=0);   
					 	break;
					
					case 0:
						break;
					 }	 
		    }while(opep!=0);
	        break;
        
        case 3: /* Menu Ordenes de envio*/
	        do
	        {
	        	 system("cls");
	             printf("\t Bienvenido al Menu Ordenes de envio \n\n "); printf("%c",168);
	             printf("Qu%c desea hacer? \n\n", 130);
	             printf(" 1. Solicitar env%co \n", 161);
	             printf(" 2. Modificar env%co \n", 161);
	             printf(" 3. Consultar env%co \n", 161);
	             printf(" 4. Cierre de env%co \n", 161);
	             printf(" 5. Eliminar env%co \n", 161);
	             printf(" 0. Volver al Men%c Principal \n\n", 163);
	             printf(" Introduzca una opci%cn: ",162); scanf("%d",&opoe);
	             system("cls");
	             switch(opoe)
	             {
	               case 1: /*Solicitud de envio*/
	               		p = &env1;
	    
	               		/*Registro de la persona*/
	                    do{
				   			printf("\n\tIntroduzca la cedula de identidad de la persona: ");
							scanf("%d",&env1.persona);
							system("CLS");
							if(env1.persona<0 || env1.persona>pow(10,8) || (env1.persona != per.ci)){
								if (env1.persona<0 || env1.persona>pow(10,8)){
									printf("\n\n\tDebe introducir una cedula valida (1-10,000,0000)\n\n");
								}
								else{
									printf("\n\n\tLa cedula de la persona no se encuentra en el sistema, vaya al Menu de Personas y agreguela.\n\n");
									system("PAUSE");
									break;
								}
							}
							else{
								printf("\n\n\tCedula registrada exitosamente!");
								sleep(1);
							}
							system("CLS");
						}while((env1.persona<0 || env1.persona>pow(10,8)) || (env1.persona != per.ci));
						fflush(stdin);
						if (env1.persona != per.ci){
							break;
						}
						fflush(stdin);
						
						/*Registro de la Empresa Involucrada*/
						printf("\n\tIntroduzca el codigo de la empresa involucrada: ");
						scanf("%d",&cod);
						if (cod != emp1.codigo){
							printf("\n\n\tLa empresa no se encuentra registrada en el sistema, vaya al Menu de Empresas y registrela.\n\n");
							system("PAUSE");
							break;
						}
						else
						{
							env1.emp1 = &emp1;
							printf("\n\n\tCodigo de la empresa: %d\n",env1.emp1->codigo);
							printf("\tNombre de la empresa: %s\n", env1.emp1->nombre );
							printf("\tTipo de empresa: %s\n", env1.emp1->tipo);
							printf("\tDireccion de la empresa: %s\n",env1.emp1->direccion );
							printf("\tTelefono de la empresa: %s\n",env1.emp1->telefono);
							sleep(1);
							if(prod1.cod){
								do{								
									printf("\tProductos:\n");
									printf("\t\t%d\t%s\n\n", prod1.cod, prod1.descripcion);
									printf("\tIntroduzca el codigo del producto a ordenar: ");
									scanf("%s", &cod);
									if (cod != prod1.cod){
										printf("\n\n\tEl producto no se encuentra registrado. Intente Nuevamente.\n");
									}
									
								}while(cod != prod1.cod);
				        	}
							else{
								printf("\tLa empresa aun no tiene productos registrados.\n\n");
								system("PAUSE");
								break;
							}
							system("PAUSE");
						}
						do{
							system("CLS");
							printf("\tIntroduzca el numero de factura: ");
							scanf("%d",&env1.numfactura);
							if (scanf("%d",&env1.numfactura)!=1){
								cond=1;
								printf("\n\tIntroduzca un numero de factura valido\n");
							}
							else{
								cond=0;
							}
						}while(cond);
						fflush(stdin);
						printf("\n\nEnvio registrado exitosamente!\n\n");
						system("PAUSE");
				   		break;
				   		
				   
				   case 2: /*modificar envio*/
				   		printf("\tIntroduzca que parte del envio desea modificar: \n");
				   		printf("\t\t1. Persona\n");
				   		printf("\t\t2. Estatus de entrega\n");
				   		printf("\t\t3. Numero de factura\n\n");
				   		printf("\t\tOpcion: ");
				   		scanf("%d", &opmeoe);
				   		system("CLS");
				   		switch(opmeoe){
				   			case 1:
				   				printf("\tIntroduzca la cedula de la persona: ");
				   				scanf("%d",&num);
				   				if(num!=per.ci){
				   					printf("\n\nNo existe ninguna persona con dicha cedula en el sistema intente nuevamente.\n\n");
								   }
								else{
									env1.persona = num;
									printf("\n\nCedula modificada exitosamente.\n\n");
								}
								system("PAUSE");
				   				break;
				   			case 2:
				   				printf("\tIntroduzca el nuevo estatus de entrega: \n\n");
				   				printf("\t\t1.-Entregado\n");
				   				printf("\t\t2.-No Entregado\n\n");
				   				printf("\tOpcion: ");
				   				scanf("%d", &num);
				   				if (num != 1 && num!= 0){
				   					printf("\n\nEl estatus '%d' no es valido. Intente nuevamente.\n\n");
								   }
								else{
									env1.entregado = num;
									printf("\n\nEstatus modificado exitosamente.\n\n");
								}
								system("PAUSE");
				   				break;
				   			case 3:
				   				printf("\tIntroduzca el nuevo numero de factura: ");
				   				scanf("%d",&num);
				   				if (num!=env1.numfactura){
								   printf("\n\n\tNo existe ningun envio con el numero de factura introducido. Intente nuevamente\n");
								}
								else{
									env1.numfactura = num;
									printf("\n\n\tNumero de factura modificado exitosamente.\n");
								}
				   				break;
				   			default:
				   				printf("Opcion no valida.");
				   				break;
						   }
				   	    break;
				   
				   case 3: /* consultar envio*/
				   		printf("Introduzca el numero de factura del envio a consultar: ");
				   		scanf("%d",&num);
				   		if (!(consultarenvio(p,num)))
							printf("El numero de factura no se encuentra en el sistema. Intente nuevamente\n\n");
						else{
							mostrarenvio(p);
						}
						system("PAUSE"); 
				        break;
				   
				   case 4: /* cierre de envio*/
				   		cierreenvio(p);	
				   	    break;
				   
				   case 5: /* eliminar envio*/
				   		modificarenvio(p,0,0,0);
				        break;
				    
				   case 0:
				   		break;
				
				   default:
					 	printf("Opcion incorrecta, debe introducir un numero entre 0 y 4. Intente nuevamente.\n\n");
					 	system("PAUSE");
        				break;
				 }   
	        }while(opoe!=0);
	        break;
        
        case 4: /* Menu Consultas*/
	        do
	        {
	          system("cls");
	          printf("\t Bienvenido al Menu de Consultas \n\n"); printf("%c",168);
	          printf("Que desea consultar? \n\n");
	          printf("1. Empresas\n");
	          printf("2. Personas\n");
	          printf("3. Sistema\n");
	          printf("0. Volver al menu principal\n\n");
	          printf("Introduzca una opcion: "); scanf("%d",&opc);
	          system("cls");
	          switch(opc)
	          {
	          	case 1: /*consulta de empresa*/
		          	do
		          	{
		          	   system("cls");
		          	   printf("Bienvenido al Menu Consulta de Empresas\n\n"); printf("%c",168);
		          	   printf("Que desea ver?\n\n");
		          	   printf("1. Movimiento del sistema\n");
		          	   printf("2. Movimiento de empresa\n");
		          	   printf("3. Movimiento de cliente\n");
		          	   printf("4. Notoriedad en clientes\n");
		          	   printf("5. Notoriedad en empresas\n");
		          	   printf("0. Volver al menu\n\n");
		          	   printf("Introduzca una opcion: "); scanf("%d",&opce);
		          	   system("cls");
		          	   switch(opce)
		          	   {
		          	   	 case 1: /*Movimiento del sistema*/
		          	   	 	break;
		          	   	 
		          	   	 case 2: /*Movimiento de empresa*/
		          	   	    break;
		          	   	 
		          	   	 case 3: /* movimiento del cliente*/
		          	   	    break;
		          	   	 
		          	   	 case 4: /*notoriedad cliente*/
		          	   	    break;
		          	   	 
		          	   	 case 5: /*notoriedad empresa*/
		          	   	    break;
		          	   	    
		          	   	 case 0:
		          	   	 	break;
		          	   	 
		          	   	 default:
		          	   	 	printf("Opcion incorrecta, debe introducir un numero entre 0 y 4. Intente nuevamente.\n\n");
		          	   	 	system("PAUSE");
		          	   	 	break;
					   }
		            }while(opce!=0);
		           	break;
	          	
	          	case 2: /* Consulta de persona*/
		          	do
		          	{
		          	   system("cls");
		          	   printf("Bienvenido al Menu Consulta de Personas\n\n"); printf("%c",168);
		          	   printf("Que desea ver?\n\n");
		          	   printf("1. Persona en general\n");
		          	   printf("2. Persona y empresa\n");
		          	   printf("0. Volver al menu\n\n");
		          	   printf("Introduzca una opcion: "); scanf("%d",&opcp);
		          	   system("cls");
		          	   switch(opcp)
		          	   {
		          	   	case 1: /*Persona general*/
		          	   	  	break;
		          	   	
		          	   	case 2: /*Persona y empresa*/
		          	   	   	break;
		          	    	
		          	    default:
		          	    	printf("Opcion incorrecta, debe introducir un numero entre 0 y 4. Intente nuevamente.\n\n");
		          	    	system("PAUSE");
		          	    	break;
						 }
		            }while(opcp!=0);
		          	break;
          	
	          	case 3: /* consulta de sistema*/
		          	do
		          	{
		              system("cls");
		          	  printf("\t Bienvenido al Menu Consulta del Sistema\n\n"); printf("%c",168);
		          	  printf("Que desea ver?\n\n");
		          	  printf("1. Ingreso por empresa\n");
		          	  printf("2. Producto vendido por empresa\n");
		          	  printf("3. Compra por persona\n");
		          	  printf("4. Producto comprado por persona\n");
		          	  printf("5. Nro de facturas\n");
		          	  printf("0. Volver al menu\n\n");
		          	  printf("Introduzca una opcion: "); scanf("%d",&opcs);
		          	  
		          	  system("cls");
		          	  switch(opcs)
		          	  {
		          	  	case 1: /*ingreso empresa*/
		          	  	  	break;
		          	  	
		          	  	case 2: /* Producto vendido por empresa*/
		          	  	  	break;
		          	  	
		          	  	case 3: /*Compra por persona*/
		          	  	  	break;
		          	  	
		          	  	case 4: /*producto comprado por persona*/
		          	  	  	break;
		          	  	
		          	  	case 5: /*nro de facturas*/
		          	  	  	break;
		          	  		
		          	  	default:
		          	  		printf("Opcion incorrecta, debe introducir un numero entre 0 y 4. Intente nuevamente.\n\n");
		          	  		system("PAUSE");
		          	  		break;
					  }
		          	  
		           }while(opcs!=0);
		          	break;
		        
		        case 0:
		        	break;
		          	
		        default:
		        	printf("Opcion incorrecta, debe introducir un numero entre 0 y 4. Intente nuevamente.\n\n");
		        	system("PAUSE");
		        	break;
				  }
		        }while(opc!=0);
		        break; 
		
		case 0:
			break;   
        
        default:
        	printf("Opcion incorrecta, debe introducir un numero entre 0 y 4. Intente nuevamente.\n\n");
        	system("PAUSE");
        	break;
	}
 } while(op!=0);
   
   system("pause");
   return(0);
   
} //Fin del main


/***************************************************************FUNCIONES PERSONAS***************************************************************************/

void AgregarP(struct Personas *pers)  /*Funcion agregar Persona*/
{
	
	printf("Cedula: ");
	scanf("%d",&pers->ci);
	printf("\nNombre y Apellido: ");
	fflush(stdin);
    gets(pers->na);
    printf("\nFecha de nacimiento (yyyymmdd).  \nEscribir entre: A"); printf("%c",164); printf("o (1900-2100)");
    printf("| Mes(01-12) | Dia(01-31): ");
    scanf("%d",&pers->fn);
    printf("\nCiudad de nacimiento: ");
	fflush(stdin);
	gets(pers->cn);
	printf("\nDireccion: ");
	fflush(stdin);
	gets(pers->dip);
  
} //Fin void agregarP


void ConsultarP(struct Personas *pers)  /*Funcion consultar Persona*/
{
	int cons,ci1;
	char na1[20];
	
	printf("%c",168); printf("Como desea hacer la consulta?\n\n");
	printf("1. Cedula\n");
	printf("2. Nombre\n\n");
	printf("Introduzca opcion: ");
	
	scanf("%d",&cons);
	system("cls");
	
	switch(cons)
	{
		case 1:
		do
		{
		  printf("escriba la cedula correspondiente\n");
		  printf("CI: ");
		  scanf("%d",&ci1);
		  system("cls");
		  
		  if (ci1 == pers->ci)
		  {
		  	printf("\n\nLa persona solicitada por CI: %d",ci1);
		  	printf("\n Cedula: %d",pers->ci);
		  	printf("\nNombre: %s",pers->na);
		  	printf("\nFecha de Nacimiento: %d",pers->fn);
		  	printf("\nCiudad de nacimiento: %s",pers->cn);
		  	printf("\nDireccion: %s",pers->dip);
		  	printf("\n\n");
		  	
		  	system("pause");
		  }
		  else
		  {
		  	printf("\n\nLa cedula introducida no coincide con alguna del sistema");
		  	printf("\nPor favor vuelva a introducirla\n\n");
		  }
	  }while(ci1!=pers->ci);
	 
	  system("pause");
	  break;
	
	case 2:
		do
		{
		  printf("Escriba el nombre correspondiente\n");
		  printf("Nombre: ");
		  fflush(stdin);
		  gets(na1);
		  strcmp(na1,pers->na);
		  system("cls");
		 
		  if (strcmp(na1,pers->na)==0)
		  {
		  	printf("\n\nLa persona solicitada por nombre: %s",na1);
		  	printf("\n Cedula: %d",pers->ci);
		  	printf("\nNombre: %s",pers->na);
		  	printf("\nFecha de Nacimiento: %d",pers->fn);
		  	printf("\nCiudad de nacimiento: %s",pers->cn);
		  	printf("\nDireccion: %s",pers->dip);
		  	printf("\n\n");
		  	break;
		  }
		  else
		  {
		  	printf("\n\nEL nombre introducido no coincide con alguno del sistema");
		  	printf("\nPor favor vuelva a introducirlo\n\n");
		  }
	    }while(na1!=pers->na);
	  
	  system("pause");
    break;
    }
} /*Fin ConsultarP*/


void ModificarP(struct Personas *pers) /*Funcion modificar Persona*/
{
	printf("Introducira los mismos datos de ser requerido y cambiar el que desee\n\n");
	printf("Nombre y apellido: ");
	fflush(stdin);
	gets(pers->na);
	printf("\nFecha de nacimiento (yyyymmdd): ");
	scanf("%d",&pers->fn);
	printf("\nCiudad de nacimiento: ");
	fflush(stdin);
	gets(pers->cn);
	printf("\nDireccion: ");
	fflush(stdin);
	gets(pers->dip);
	
	
} /*Fin modificar Persona*/

void EliminarP(struct Personas *pers) /*Funcion eliminar Persona*/
{
   printf("Se eliminaran los datos de la persona en el sistema");
   pers->ci=' ';
   memset(pers->na,' ',20);
   pers->fn=' ';
   memset(pers->cn,' ',15);
   memset(pers->dip,' ',40);
   printf("Cargando...");
   system("pause");
} /*Fin eliminar Persona*/


/**********************************************************************FUNCIONES PRODUCTOS**********************************************************************/

/*Funcion que guarda los valores que se pasen como parametros en el registro al que este apuntando el puntero*/
void agregarproducto(struct Producto *prod, int cod, char descri[20], int ppu)
{
	prod->cod = cod;
	strcpy(prod->descripcion, descri);
	prod->ppu = ppu;
	prod->activo = 1;
};

/*Funcion que dado un apuntador muestra todos los renglones del producto al que esta apuntando*/
void mostrarproducto(struct Producto *prod)
{
	printf("\tCodigo Producto: %d\n", prod->cod);
	printf("\tDescripcion: %s\n", prod->descripcion);
	printf("\tPrecio Por Unidad: %d\n", prod->ppu);
	if(prod->activo){
		printf("\tDisponibilidad: DISPONIBLE\n\n");
	}
	else{
		printf("\tDisponibilidad: NO DISPONIBLE\n\n");
	}
};

/*Funcion que blanquea la unica estructura de producto existente so far*/
void eliminarproducto(struct Producto *prod)
{
	prod->cod=0;
	strcpy(prod->descripcion, "");
	prod->ppu=0;
	prod->activo=0;
};
   

/**********************************************************************FUNCIONES ORDENES DE ENVIO***************************************************************/

void modificarenvio(struct Envio *p, int persona, int tipoe, int numfactura)
{
	(*p).persona = persona;
	(*p).entregado = 0;
	(*p).numfactura = numfactura;
};

int consultarenvio(struct Envio *p, int num)
{
	if (num == (*p).numfactura) /*Numero de factura se registra manualmente o se  genera*/
		return 1;
	return 0;
};

void mostrarenvio(struct Envio *p)
{
	printf("Numero de envio: %d\n", (*p).numfactura);
	printf("Persona: %s\n", (*p).persona);
	/*printf("Tipo de Empresa: %d\n", (*p).tipoe);
	printf("Empresas involucradas:\n");
	printf("\tEmpresa 1: %s\n", (*p).emp1);
	printf("\tEmpresa 2: %s\n", (*p).emp2);*/
	if ((*p).entregado)
		printf("Estatus de entrega: ENTREGADO\n\n");
	else{
		printf("Estatus de entrega: NO ENTREGADO\n\n");
	}
	
}
void cierreenvio(struct Envio *p)
{
	(*p).entregado = 1;
};


void eliminarenvio()
{
	;
};

/*Funcion que dado un numero, te devuelve el tipo de empresa:
  1.- Comida
  2.- Alimentos
  3.- General
char[] tipoemp(int x)
{
	switch(x){
		case 1:
			return "Comida";
		case 2:
			return "Alimentos";
		case 3:
			return "General";
		default:
			return "Tipo invalido";
	}
};*/

/*******************************************************************FUNCIONES DE VALIDACION*********************************************************************/

int validarnumeros(char *p){
	do{
		if (*p<'0' || *p>'9')
			return 0;
	}while(*++p);
	return 1;
};

/*int validarstring(char *p){
	do{
		char charstr = tolower(*p);
		if(charstr<'a' || charstr>'z' && charstr!=32)
			return 0;
	}while(*++p);
	return 1;
};*/

int validarstring(char *p)
{
	do{
		char charstr = *p;
		if(isalpha(charstr) == 0 && charstr!= 32){
			return 0;
		}	
	}while(*++p);
	return 1;
}

void eliminarnl(char s1[])
{
  if (strlen(s1) >0 && s1[strlen(s1)-1] == '\n')
    s1[strlen(s1)-1] = '\0';
}

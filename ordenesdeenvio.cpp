struct Envio 
	{	
		char[] emp1, emp2, persona;
		int entregado, tipoe, numfactura;	
	};
	
void leerenvio(struct Envio *p, char[] emp1, char[] emp2, char[] persona, int tipoe, int numfactura)
{
	(*p).emp1 = emp1;
	(*p).emp2 = emp2;
	(*p).persona = persona;
	(*p).entregado = 0;
	(*p).tipoe = tipoe;
	(*p).numfactura = numfactura;
};

void modificarenvio(struct Envio *p, char[] emp1, char[] emp2, char[] persona, int tipoe, int numfactura)
{
	(*p).emp1 = emp1;
	(*p).emp2 = emp2;
	(*p).persona = persona;
	(*p).entregado = 0;
	(*p).tipoe = tipoe;
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
	printf("Numero de envio: %d", (*p).numfactura);
	printf("Persona: %s", (*p).persona);
	printf("Tipo de Empresa: %d", (*p).tipoe);
	printf("Empresas involucradas:");
	printf("\tEmpresa 1: %s", (*p).emp1);
	printf("\tEmpresa 2: %s", (*p).emp2);
	if ((*p).entregado)
		printf("Estatus de entrega: ENTREGADO");
	else{
		printf("Estatus de entrega: NO ENTREGADO");
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


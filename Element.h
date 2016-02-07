#ifndef ELEMENT_H
#define ELEMENT_H

#include <conio.h>
#include "entity.h"

#define N_ELEMENTS 10


//lee el modificador de un elemento
float Mod_Elem(int _attackerElement, int _targetElement)
{
	FILE* file = fopen("elements.dat", "rb");
	if(file)
	{
		float buffer;
		fseek(file, sizeof(float) * ((_attackerElement * 10) + _targetElement), 0);
		fread(&buffer, sizeof(float), 1, file);
		fclose(file);
		
		return buffer;
	}
	fclose(file);
	return -1;
}

//establece un nuevo valor para un modificador
int Set_Element(int _attackerElement, int _targetElement, float _value)
{
	FILE* file = fopen("elements.dat", "r+b");
	if(file)
	{
		fseek(file, sizeof(float) * ((_attackerElement * 10) + _targetElement), 0);
		fwrite(&_value, sizeof(float), 1, file);
		fclose(file);
	}
	fclose(file);
	return -1;
}

//crea una nueva tabla de modificadores elementales
int Create_Element_Table()
{
	FILE* file = fopen("elements.dat", "rb");
	if(file)
	{
		fclose(file);
		printf("\n ERROR: La tabla ya existe, debe eliminarse manualmente!\n");
		
		return 0;
	}
	
	file = fopen("elements.dat", "wb");
	if(file)
	{
		printf("\nIngrese los datos de la tabla: \n");
		float buffer = 0;
		for(int i=0; i<N_ELEMENTS; i++)
		{
			printf("  Elemento %d\n", i+1);
			for(int j=0; j<N_ELEMENTS; j++)
			{
				printf("#%d: ", j+1);
				scanf("%f", &buffer);
				buffer /= 100;
				fwrite(&buffer, sizeof(float), 1, file);
				fflush(file);
			}
		}
	}
	fclose(file);
	return 0;
}

//muestra la tabla de los modificadores elementales
int Read_Element_Table()
{
	FILE* file = fopen("elements.dat", "rb");
	if(file)
	{
		printf("\n  Tabla de modificadores elementales:\n\n");
		for(int i=0; i<N_ELEMENTS; i++)
		{
			printf("#%d   ", i);
			for(int j=0; j<N_ELEMENTS; j++)
			{
				float buffer;
				fread(&buffer, sizeof(float), 1, file);
				printf("%.2f  ", buffer);
			}
			printf("\n");
		}
		printf("\n");
	}
	fclose(file);
	return 0;
}


#endif

#ifndef LIB_RANDOM32_H
#define LIB_RANDOM32_H
#include <stdlib.h>

int getInt(int _limit1, int _limit2)
{
	if(_limit1 > _limit2)  //se asegura que el primer operando es mayor que el segundo
	{
		return (rand() % (_limit1 - _limit2 + 1)) + _limit2;
	}
	else
	{
		return (rand() % (_limit2 - _limit1 + 1)) + _limit1;
	}
}


#endif

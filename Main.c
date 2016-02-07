#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Entity.h"
#include "Element.h"
#include "melee_dmg.h"
#include "distance_dmg.h"

int main()
{
	srand(time(NULL));
	Player Daralion, Mabel, Xetfrick;
	/*
	Load_Player("Daralion", &Daralion);
	Load_Player("Mabel", &Mabel);
	Load_Player("Xetfrick", &Xetfrick);
	Load_Player("Hermenegildo",&Herme);
	
	Print_Player(Herme);
	Print_Player(Daralion);
	Print_Player(Mabel);
	Print_Player(Xetfrick);
	*/
	
	printf("\n%.2f\n",Damage_d(&Daralion.stats,&Mabel.stats));
	printf("\nHP = %.2f\n", Mabel.stats.HP);
	/*
	Save_Player("Daralion", &Daralion);
	Save_Player("Mabel", &Mabel);
	Save_Player("Xetfrick", &Xetfrick);
	*/
	system("PAUSE");
}

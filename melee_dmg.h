#include <stdlib.h>
#include <string.h>
#include "random32.h"
#include "entity.h"
#include "Element.h"

//Lo siguiente será para calcular el daño físico.
float Damage_m (Entity* attacker, Entity* target)
{
	float str_mod, dmg_mod, dmg_total,Dmg,Hit,d20a,d15t;
	d20a=getInt(20,1);
	d15t=getInt(15,1);
	
	Hit = (float)attacker->Dex*d20a/20 + (float)attacker->Vel*d20a/20 - (float)target->Dex*d15t/15 - (float)target->Vel*d15t/15;
	//printf("%Hit.1f\n",Hit);
	printf("%.1f, %.1f\n",d20a,d15t);
	if(Hit<=0){printf("Attacker misses.\n");return 0;}
	else if(Hit>0){printf("Attacker hits.\n");}

//compara la fuerza de ambos y lo utiliza como modificador del dmg.
//==========================mod===========================//
	str_mod = attacker->Str - target->Str;
	dmg_mod = attacker->Dmg*str_mod/100;
	dmg_total = attacker->Dmg + dmg_mod;
	if(d20a==20){printf("Attacker does critical dmg!\n");
	dmg_total += dmg_total/4;}
//calcula reducción por armadura física
//==========================red ArmP===========================//
	dmg_total = dmg_total - (float)dmg_total*target->ArmP/100;
//calcula reducción por armadura mágica
//==========================red ArmM===========================//
	dmg_total = dmg_total - (float)dmg_total*target->ArmM/100;
//calcula reducción por elemento
//==========================red elem===============================//
	dmg_total *= Mod_Elem(attacker->Ele,target->Ele);
	
	Damage_Entity(target, dmg_total);
	
	return dmg_total;
}


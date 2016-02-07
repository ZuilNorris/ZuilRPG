#include <stdlib.h>
#include <string.h>
#include "random32.h"
#include "entity.h"
#include "Element.h"

//Lo siguiente será para calcular el daño físico.
float Damage_d (Entity* attacker, Entity* target)
{
	float dex_mod, dmg_mod, dmg_total,Dmg,Hit,d20a,d15t,a3d6;
	
	if (attacker->Class == 1){//Archer tiene una nueva formula
		a3d6=getInt(6,1) + getInt(6,1) + getInt(6,1) + 4;
		d15t=getInt(15,1);
		if (a3d6>20){a3d6 = 20;}
		Hit = (float)attacker->Dex*a3d6/20 + (float)attacker->Vel*a3d6/20 - (float)target->Dex*d15t/15 - (float)target->Vel*d15t/15;
		//compara la fuerza del target y la dex del Attacker y lo utiliza como modificador del dmg.
		printf("%.1f, %.1f\n",a3d6,d15t);
		if(Hit<=0){printf("Attacker misses.\n");return 0;}
		else if(Hit>0){printf("Attacker hits.\n");}
		//==========================mod===========================//
		dex_mod = attacker->Dex - target->Str;
		dmg_mod = attacker->Dex*dex_mod/100;
		dmg_total = attacker->Dmg + dmg_mod;
		if(a3d6>=18){printf("Attacker does critical dmg!\n");
		dmg_total += dmg_total/4;}
	}
	else{
		d20a=getInt(20,1);
		d15t=getInt(15,1);
		
		Hit = (float)attacker->Dex*d20a/20 + (float)attacker->Vel*d20a/20 - (float)target->Dex*d15t/15 - (float)target->Vel*d15t/15;
		//printf("%.1f\n",Hit);
		printf("%.1f, %.1f\n",d20a,d15t);
		if(Hit<=0){printf("Attacker misses.\n");return 0;}
		else if(Hit>0){printf("Attacker hits.\n");}
		//compara la fuerza del target y la dex del Attacker y lo utiliza como modificador del dmg.
		//==========================mod===========================//
		dex_mod = attacker->Dex - target->Str;
		dmg_mod = attacker->Dex*dex_mod/100;
		dmg_total = attacker->Dmg + dmg_mod;
		if(d20a==20){printf("Attacker does critical dmg!\n");
		dmg_total += dmg_total/4;}	
	}
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

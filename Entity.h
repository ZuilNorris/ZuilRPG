#ifndef ENTITY_H
#define ENTITY_H


#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define CL_MOB 0
#define CL_ARCHER 1
#define CL_MAGE 2
#define CL_ASSASSIN 3
#define CL_PALADIN 4
#define CL_PALADIN_D 5
#define CL_MAGE_D 6
#define CL_MINIBOSS 7
#define CL_BOSS 8

#define HP_MOB 0
#define HP_ARCHER 
#define HP_MAGE
#define HP_ASSASSIN
#define HP_PALADIN
#define HP_PALADIN_D
#define HP_MAGE_D
#define HP_MINIBOSS
#define HP_BOSS

#define EL_NEUTRAL 0
#define EL_WATER 1
#define EL_EARTH 2
#define EL_FIRE 3
#define EL_WIND 4
#define EL_POISON 5
#define EL_HOLY 6
#define EL_DARK 7
#define EL_GHOST 8
#define EL_UNDEAD 9


//Estructura para valores de jugadores y monstruos.
struct Entity
{
	float HP;
	float Dmg;
	
	int Str;
	int Dex;
	int Vel;
	int Int;
	int Cons;
	int Ele;
	int ArmP;
	int ArmM;
	
	int Lvl;
	int Class;
};


struct Player
{
	char name[64];
	Entity stats;
};


//=============================Player=====================================//

//cargamos los datos del jugador; la función devuelve un entero, 
//y como parámetros de entrada tenemos dos punteros:
//nombre del jugador y la entidad.
int Load_Player(const char* player_name, Player* player)
{
	//declaramos un vector de longitud de 30 char
	//almacenará "player\\"*
	//escribe 0 en el vector
	char buffer[80];
	memset(buffer, 0, 80);
	strcpy(buffer, "player\\");
	//escribe sobre buffer (mientras haya espacio), lee player_name
	strcat(buffer, player_name);
	FILE* file = fopen(strcat(buffer, ".txt"), "r");
	if (file)
	{
		//"entity" puntero a la variable que vamos a escribir
		//sizeof devuelve un entero (tamaño en bytes de la estructura)
		//cantidad de estructuras a cargar
		//puntero al archivo
		//fread(entity, sizeof(Entity), 1, file);
		
		
		//Leyendo en modo de texto
		memset(buffer, 0, 80); fgets(buffer, 63, file); strcpy(player->name, buffer); fgetc(file);
		fscanf(file, "HP = %f\n", &player->stats.HP);
		fscanf(file, "Dmg = %f\n", &player->stats.Dmg);
		fscanf(file, "Str = %d\n", &player->stats.Str);
		fscanf(file, "Dex = %d\n", &player->stats.Dex);
		fscanf(file, "Vel = %d\n", &player->stats.Vel);
		fscanf(file, "Int = %d\n", &player->stats.Int);
		fscanf(file, "Cons = %d\n", &player->stats.Cons);
		fscanf(file, "Ele = %d\n", &player->stats.Ele);
		fscanf(file, "ArmP = %d\n", &player->stats.ArmP);
		fscanf(file, "ArmM = %d\n", &player->stats.ArmM);
		fscanf(file, "Lvl = %d\n", &player->stats.Lvl);
		fscanf(file, "Class = %d\n", &player->stats.Class);
		
		fclose(file);
		return 1;
	}
	fclose(file);
	return 0;
}
int Save_Player(const char* player_name, Player* player)
{
	char buffer[80];
	memset(buffer, 0, 80);
	strcpy(buffer, "player\\");
	strcat(buffer, player_name);
		
	FILE* file = fopen(strcat(buffer, ".txt"), "w");
	if(file)
	{
		fprintf(file, "%s\n\n", player_name);
		fprintf(file, "HP = %.2f\n", player->stats.HP);
		fprintf(file, "Dmg = %.2f\n", player->stats.Dmg);
		fprintf(file, "Str = %d\n", player->stats.Str);
		fprintf(file, "Dex = %d\n", player->stats.Dex);
		fprintf(file, "Vel = %d\n", player->stats.Vel);
		fprintf(file, "Int = %d\n", player->stats.Int);
		fprintf(file, "Cons = %d\n", player->stats.Cons);
		fprintf(file, "Ele = %d\n", player->stats.Ele);
		fprintf(file, "ArmP = %d\n", player->stats.ArmP);
		fprintf(file, "ArmM = %d\n", player->stats.ArmM);
		fprintf(file, "Lvl = %d\n", player->stats.Lvl);
		fprintf(file, "Class = %d\n", player->stats.Class);
		fclose(file);
		return 1;
	}
	
	fclose(file);
	return 0;
}

//===========================Mob=========================================//

//lo mismo que con el jugador, para el monstruo.
int Load_Monster(const char* mob_name, Entity* entity)
{
	char buffer[80];
	memset(buffer, 0, 80);
	strcpy(buffer, "monster\\");
	strcat(buffer, mob_name);
	FILE* file = fopen(buffer, "r");
	if (file)
	{
		fread(entity, sizeof(Entity), 1, file);
		fclose(file);
		return 1;
	}
	fclose(file);
	return 0;
}
int Save_Monster(const char* mob_name, Entity* entity)
{
	char buffer[80];
	memset(buffer, 0, 80);
	strcpy(buffer, "monster\\");
	strcat(buffer, mob_name);
	FILE* file = fopen(strcat(buffer, ".txt"), "w");
	if (file)
	{
		fprintf(file, "%s\n\n", mob_name);
		fprintf(file, "HP = %.2f\n", entity->HP);
		fprintf(file, "Dmg = %.2f\n", entity->Dmg);
		fprintf(file, "Str = %d\n", entity->Str);
		fprintf(file, "Dex = %d\n", entity->Dex);
		fprintf(file, "Vel = %d\n", entity->Vel);
		fprintf(file, "Int = %d\n", entity->Int);
		fprintf(file, "Cons = %d\n", entity->Cons);
		fprintf(file, "Ele = %d\n", entity->Ele);
		fprintf(file, "ArmP = %d\n", entity->ArmP);
		fprintf(file, "ArmM = %d\n", entity->ArmM);
		fprintf(file, "Lvl = %d\n", entity->Lvl);
		fprintf(file, "Class = %d\n", entity->Class);
		fclose(file);
		return 1;
	}
	fclose(file);
	return 0;
}

//============================print=======================================//

void Print_Entity(Entity entity)
{
	printf("HP = %.2f\n", entity.HP);
	printf("Dmg = %.2f\n", entity.Dmg);
	printf("Class = %d\n", entity.Class);
	printf("Lvl = %d\n", entity.Lvl);
	printf("Str = %d\n", entity.Str);
	printf("Dex = %d\n", entity.Dex);
	printf("Vel = %d\n", entity.Vel);
	printf("Int = %d\n", entity.Int);
	printf("Cons = %d\n", entity.Cons);
	printf("Ele = %d\n", entity.Ele);
	printf("ArmM = %d\n", entity.ArmM);
	printf("ArmP = %d\n\n", entity.ArmP);
}

void Print_Player(Player player)
{
	printf("%s\n", player.name);
	Print_Entity(player.stats);
}

//===========================Damage and Heal===============================//

void Damage_Entity(Entity* entity, float damage)
{
	if(damage > 0)
	{
		entity->HP -= damage;
		if(entity->HP < 0)
		{
			entity->HP = 0;
		}
	}
}

void Heal_Entity(Entity* entity, float hp)
{
	if(hp > 0)
	{
		entity->HP += hp;
		if(entity->HP < 0)
		{
			entity->HP = 0;
		}
	}
}


//150+Class_Mod+(5*)


#endif

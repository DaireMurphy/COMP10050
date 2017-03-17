//Daire Murphy 15441458. This is my half of the project. My partner didn't submit any work so I did my half of the assignment. Unsure of what else to do. :( 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct Profile // Setting up the struct 
	{
	char names[10];
	char types[10];
	char moveattack[10];
	char attackedplayer[10];
	int Intelligence;
	int Strength;
	int Magic;
	int Luck;
	int Dexterity;
	int LifePoints;
	}Profile;
	Profile info[6];

void elf(int x) //function for randomising elf stats
{
	time_t t;
	srand((unsigned) time(&t));
	info[x].Intelligence = (rand() % 31) + 70;
	info[x].Luck = (rand() % 41) + 60;
	info[x].Strength = rand() % 51;
	info[x].Magic = (rand() % 31) + 50;
	info[x].Dexterity = rand() % 101;
	info[x].LifePoints = 100;
	printf("\n%s chose an Elf. Your stats are :\nLife Points = %d\nIntelligence = %d\nStrenght = %d\nMagic = %d\nLuck = %d\nDexterity = %d\n", info[x].names, info[x].LifePoints, info[x].Intelligence, info[x].Strength, info[x].Magic, info[x].Luck, info[x].Dexterity);
   	return;
}

void ogre(int x) //function for randomising ogre stats
{
	time_t t;
	srand((unsigned) time(&t));
	info[x].Intelligence = rand() % 21;
	info[x].Luck = rand() % (51 - info[x].Intelligence);
	info[x].Strength = (rand() % 21) + 80;
	info[x].Magic = 0;
	info[x].Dexterity = (rand() % 21) + 80;
	info[x].LifePoints = 100;
	printf("\n%s chose an Ogre. Your stats are :\nLife Points = %d\nIntelligence = %d\nStrenght = %d\nMagic = %d\nLuck = %d\nDexterity = %d\n", info[x].names, info[x].LifePoints, info[x].Intelligence, info[x].Strength, info[x].Magic, info[x].Luck, info[x].Dexterity);
   	return;
}
void wizard(int x) //function for randomising wizard stats
{
	time_t t;
	srand((unsigned) time(&t));
	info[x].Intelligence = (rand() % 11) + 90;
	info[x].Luck = (rand() % 51) + 50;
	info[x].Strength = rand() % 21;
	info[x].Magic = (rand() % 21) + 80;
	info[x].Dexterity = rand() % 101;
	info[x].LifePoints = 100;
printf("\n%s chose a Wizard. Your stats are :\nLife Points = %d\nIntelligence = %d\nStrenght = %d\nMagic = %d\nLuck = %d\nDexterity = %d\n", info[x].names, info[x].LifePoints, info[x].Intelligence, info[x].Strength, info[x].Magic, info[x].Luck, info[x].Dexterity);
   	return;
}
void human(int x) //function for randomising human stats
{
	int Total = 0;
	time_t t;
	srand((unsigned) time(&t));
	do {
	info[x].Intelligence = rand() % 101;
	info[x].Luck = rand() % 101;
	info[x].Strength = rand() % 101;
	info[x].Magic = rand() % 101;
	info[x].Dexterity = rand() % 101;
	Total = info[x].Intelligence + info[x].Luck + info[x].Strength + info[x].Magic + info[x].Dexterity;}
	while (Total >= 300);
	info[x].LifePoints = 100;
printf("\n%s chose a Human. Your stats are :\nLife Points = %d\nIntelligence = %d\nStrenght = %d\nMagic = %d\nLuck = %d\nDexterity = %d\n", info[x].names, info[x].LifePoints, info[x].Intelligence, info[x].Strength, info[x].Magic, info[x].Luck, info[x].Dexterity);
   	return;
}
void attack(int x) //function for attack other players
{
	int i;
	printf("\nEnter the name of the player you would like to attack.\n");
	scanf("%s", &info[x].attackedplayer);
	for(i = 0; i < 6; i++)
	if(strcmp(info[x].attackedplayer, info[i].names) == 0){
			
	if(info[i].Strength <= 70){
		info[i].LifePoints = info[i].LifePoints - (.5 * info[x].Strength);
		printf("\n%s remaining stats are :\nLife Points = %d\nIntelligence = %d\nStrenght = %d\nMagic = %d\nLuck = %d\nDexterity = %d\n", info[i].names, info[i].LifePoints, info[i].Intelligence, info[i].Strength, info[i].Magic, info[i].Luck, info[i].Dexterity);
	}
	if(info[i].Strength > 70){
		info[x].LifePoints = info[x].LifePoints - (.3 * info[i].Strength);
		printf("\n%s remaining stats are :\nLife Points = %d\nIntelligence = %d\nStrenght = %d\nMagic = %d\nLuck = %d\nDexterity = %d\n", info[x].names, info[x].LifePoints, info[x].Intelligence, info[x].Strength, info[x].Magic, info[x].Luck, info[x].Dexterity);
	}
	if(strcmp(info[x].attackedplayer, info[i].names) != 0){
		printf("\nInvalid player entry, enter again.\n");
		i--;
	}
	}
   	return;
}
void move(int x) //function for moving (Not complete due to partner dropping out.
{
	
	printf("\n%s choose to move. Your stats now are :\nLife Points = %d\nIntelligence = %d\nStrenght = %d\nMagic = %d\nLuck = %d\nDexterity = %d\n", info[x].names, info[x].LifePoints, info[x].Intelligence, info[x].Strength, info[x].Magic, info[x].Luck, info[x].Dexterity);
   	return;
}
	
int main(void)
{
    int i, j, n;
	char moveattack;
	
    printf("How many players are in the game (Please enter a number between 2 and 6): \n");//Asking how many players are playing
    scanf("%d", &n);
	while(n <= 1 || n > 6){
		printf("Please enter a valid number of players.\n");
	scanf("%d", &n);}
	
    printf("Enter the list of names: \n");//Getting the player to input the names and storing them in the struct
    for (i = 0; i < n; i++)
    {
		printf("Player %d:", i + 1);
        scanf("%s", &info[i].names);
    }
	for (i = 0; i < n; i++)//For loop to ask each player what chacacter they would like to play as and storing them in a struct
	{	printf("\n%s, what type of character would you like to play as? (Please enter either 'Elf', 'Human', 'Ogre' or 'Wizard')\n", info[i].names);
	scanf("%s", &info[i].types);
		if(strcmp(info[i].types, "Elf") != 0 && strcmp(info[i].types, "Ogre") != 0 && strcmp(info[i].types, "Wizard") != 0 && strcmp(info[i].types, "Human") != 0){
			printf("\nIncorrect entry. Try again.\n");
			i--;
		}
			if(strcmp(info[i].types, "Elf") == 0){//Checking what chacacter they picked and running the appropriate function
			elf(i);
		}
			if(strcmp(info[i].types, "Ogre") == 0){
			ogre(i);
		}
			if(strcmp(info[i].types, "Wizard") == 0){
			wizard(i);
		}
			if(strcmp(info[i].types, "Human") == 0){
			human(i);
		}
	}
	for (i = 0; i < n; i++)//For loop to ask each player whether they would like to attack or move
	{	printf("\n%s, would you like to move or attack a player? (Please enter either 'Attack' or 'Move'.)\n", info[i].names);
	scanf("%s", &info[i].moveattack);
		if(strcmp(info[i].moveattack, "Attack") != 0 && strcmp(info[i].moveattack, "Move") != 0){
			printf("\nIncorrect entry. Try again.\n");
			i--;
		}
			if(strcmp(info[i].moveattack, "Attack") == 0){//Checking what action they picked and running the appropriate function
			attack(i);
		}
			if(strcmp(info[i].moveattack, "Move") == 0){
			move(i);
		}
	}
	return 0;
}

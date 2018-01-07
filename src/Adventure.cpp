#include <iostream>
#include <string>
#include <random>

using namespace std;

string currentEnemy;

int enemyHealth;
int BATTLETURN = 0;
int rogueTurn = 0;
int wizardTurn;
int warriorTurn = 0;
int bardTurn;

int rogueHealth = 130;
int wizardHealth = 160;
int warriorHealth = 200;
int bardHealth = 250;

int rogueAttack = 90;
int wizardAttack = 60;
int warriorAttack = 75;
int bardAttack = 30;

int goblinHealth = 600;
int undeadHealth = 750;
int giantHealth = 900;

int goblinAttack = 100;
int undeadAttack = 125;
int giantAttack = 150;

bool hasCharged = false;
bool wHasCharged = false;
int rogueSelection;
int powerBoost = 1;

string chosenTarget;
int chosenTargetHealth;
int poisionMultiplier = 1;
bool block = false;

bool rogueAlive = true;
bool warriorAlive = true;
bool wizardAlive = true;
bool bardAlive = true;

void rogueBattle() {
	int daggerStab = 90;
	int sneakAttack = 180;

    cin >> rogueSelection;
	if (rogueTurn == 0) {

		if (rogueSelection == 1)
		{
			cout << "You coat your dagger with a deadly poision." << endl;
			poisionMultiplier = 2;

		}
		if (rogueSelection == 2)
		{
			enemyHealth -= daggerStab*poisionMultiplier;
			cout << "You approach your enemy carefully, before swiping at the " << currentEnemy << " with your dagger." << endl;
			poisionMultiplier = 1;
		}

		if (rogueSelection == 3)
		{
			rogueTurn = 1;
			cout << "The rogue pulls out his dagger and dissapear into the shadows, ready to attack." << endl;
		}

	}
	else
	{
		rogueTurn--;
		if (rogueTurn == 0)
			hasCharged = true;
		
		
	}


	if (hasCharged == true) {
		enemyHealth -= sneakAttack*poisionMultiplier;
		cout << "The rogue rushes the enemy from behind and attacks!" << endl;
		hasCharged = false;
		poisionMultiplier = 1;
	}

}

void warriorBattle()
{
	
	int swordFlurry = 60;
	int swordSmash = 120;


	int warriorSelection;
	cin >> warriorSelection;
	if (warriorTurn == 0) {
		if (warriorSelection == 1)
		{
			block = true;
			cout << "You brace yourself for any incoming attacks." << endl;
		}
		if (warriorSelection == 2)
		{
			enemyHealth -= swordFlurry;
			cout << "The warrior rushes the " << currentEnemy << " and attacks with a flurry of slashes." << endl;
		}
		if (warriorSelection == 3)
		{
			warriorTurn = 1;
			cout << "The warrior raises his sword high into the air." << endl;
		}
	}
	else
	{
		warriorTurn--;
		if (warriorTurn == 0)
			wHasCharged = true;
	}
	if (wHasCharged == true) {
		enemyHealth -= swordSmash;
		cout << "The warrior brings thes word crashing down on the "<< currentEnemy << " ." <<  endl;
		wHasCharged = false;
	}
}

void wizardBattle()
{
	bool flame = false;
	int lifeSteal = 75;
	int fireStorm = 150;
	int wizardSelection;

	int healthStealWizard = 20;

	cin >> wizardSelection;

	if (wizardSelection == 1)
	{

	}
	if (wizardSelection == 2)
	{
		enemyHealth -= lifeSteal;
		cout << "The wizard reaches out with his staff towards the " << currentEnemy << " and drains it of some of its life force." << endl;
		cin.get();
		cout << "The wizard gains " << healthStealWizard << " health back." << endl;
		cin.get();
		wizardHealth += healthStealWizard;
		cout << "Wizard Health: " << wizardHealth << "." <<endl;
	}
	if (wizardSelection == 3)
	{

	}
}

void bardBattle()
{
	int heal = 20;


	int bardSelection;
	cin >> bardSelection;
	if (bardSelection == 1)
	{
		cout << "The bard plays a light melody of healing on his lute." << endl;
		cin.get();
		cout << "The team gains " << heal << " health back." << endl;
		rogueHealth += heal;
		warriorHealth += heal;
		wizardHealth += heal;
		bardHealth += heal;
		cin.get();
		cout << "Rogue Health: " << rogueHealth << ". Warrior Health: " << warriorHealth << ". Wizard Health: " << wizardHealth << ". Bard Health: " << bardHealth << "." << endl;
	}
	if (bardSelection == 2)
	{
		
	}
	if (bardSelection == 3)
	{
		if (rogueAlive == false && warriorAlive == false && wizardAlive == false)
			cout << "You pull out your lute \"wicked\" death metal music." << endl
			<< "The enemy is instantly killed." << endl;
		cout << "The " << currentEnemy << " has " << enemyHealth << " health left." << endl;
			enemyHealth = 0;
	}
}

int enemyRandom()
{
	random_device rd;
	return (rd() % 3);
}

int enemyCharacterRandom()
{
	random_device rd;
	return (rd() % 4);
}

void chosenCharacter()
{
	int x;
	x = enemyCharacterRandom();
	if (x == 0)
	{
		chosenTarget = "Rogue";
		chosenTargetHealth = rogueHealth;
	}
	if (x == 1)
	{
		chosenTarget = "Warrior";
		chosenTargetHealth = warriorHealth;
	}
	if (x == 2)
	{
		chosenTarget = "Wizard";
		chosenTargetHealth = wizardHealth;
	}
	if (x == 3)
	{
		chosenTarget = "Bard";
		chosenTargetHealth = bardHealth;
	}
}

void goblinBattle()
{
	int goblinChoice;
	int scratch = 100;
	int potion = 50;
	int club = 100;

	goblinChoice = enemyRandom();
	chosenCharacter();


	if (goblinChoice == 0)
	{
		cout << "Using its sharp claws, the goblin scratches at the " << chosenTarget << "."<< endl;
		chosenTargetHealth -= scratch;
		if (chosenTarget == "Rogue")
		{
			rogueHealth = chosenTargetHealth;
		}
		if (chosenTarget == "Warrior" && block == false)
		{
			warriorHealth = chosenTargetHealth;
		}
		if (chosenTarget == "Warrior" && block == true)
		{
			cout << "The blow glances of the warriors shield." << endl;
		}
		if (chosenTarget == "Wizard")
		{
			wizardHealth = chosenTargetHealth;
		}
		if (chosenTarget == "Bard")
		{
			bardHealth = chosenTargetHealth;
		}
	}

	if (goblinChoice == 1)
	{
		cout << "Taking a potion from its pouch, the goblin drinks it and restores some health." << endl;
		goblinHealth += potion;
		cout << "The " << currentEnemy << " has " << enemyHealth << " health now." << endl;
	}
	if (goblinChoice == 2)
	{
		cout << "The goblin pulls out a club and whacks the " << chosenTarget << " on the head with it." << endl;
		chosenTargetHealth -= club;
		if (chosenTarget == "Rogue")
		{
			rogueHealth = chosenTargetHealth;
		}
		if (chosenTarget == "Warrior" && block == false)
		{
			warriorHealth = chosenTargetHealth;
		}
		if (chosenTarget == "Warrior" && block == true)
		{
			cout << "The blow glances of the warriors shield." << endl;
		}
		if (chosenTarget == "Wizard")
		{
			wizardHealth = chosenTargetHealth;
		}
		if (chosenTarget == "Bard")
		{
			bardHealth = chosenTargetHealth;
		}
	}
}

bool goblinAliveCheck()
{
	if (goblinHealth <= 0)
		return false;
	else
		return true;
}

int main()
{
	goblinAliveCheck();
	string openingQuestion = "";
	string classChoice;
	string playerClass;
	cout << "This game is best played with the window at full size." << endl;
	cin.get();
	cout << "After travelling for quite some time, you and your companions stumble upon the entrance to a dungeon." << endl;
	cin.get();
		cout << "It looks like there could be great treasures inside. Will you go?" << endl;
	cin >> openingQuestion;
	if (openingQuestion == "no" || openingQuestion == "No")
	{
		cout << "GAME OVER" << endl;
		cin.get();
		exit(0);
	}
	cout << "You decide to go first, being the:" << endl;
	cin.get();
	cout << "1-Rogue: A speedy assassin who lurks in the shadows, has high attack but very low health, this character always goes first in battle." << endl
		<< "2-Wizard: A older man who works from the distance, the wizard has decent attack and low health, but is less likely to be hit by enemy attacks." << endl
		<< "3-Warrior: Your basic sword and shield weilding warrior, has decent health and attack, a balanced class overall." << endl
		<< "4-Bard: The one who keeps health and moral high, the bard has high health and very low attack, but he can heal himself and teamates." << endl;
	cin >> classChoice;
	if (classChoice == "1")
	{
		playerClass = "Rogue";
	}
	if (classChoice == "2")
	{
		playerClass = "Wizard";
	}
	if (classChoice == "3")
	{
		playerClass = "Warrior";
	}
	if (classChoice == "4")
	{
	playerClass = "Bard";
	}


	if (classChoice == "Papyrus")
	{
		playerClass = "Papryus";
	}
	if (classChoice == "Papyrus")
	{
		cout << "You head in to the dungeon full of hope. Only to immediately get pied." << endl;
		cin.get();
		cout << "GAME OVER" << endl;
		exit(0);
	}

	if (classChoice == "Titan")
	{
		playerClass = "Titan";
	}
	if (classChoice == "Titan")
	{
		cout << "You head in to the dungeon full of hope. Only to immediately get pied." << endl;
		cin.get();
		cout << "GAME OVER" << endl;
		exit(0);
	}


	if (classChoice == "1")
	{
		cout << "You head in first, hoping to find great treasures." << endl;
		cin.get();
	}
	if (classChoice == "2")
	{
		cout << "Being the oldest and the wisest, you head into the dungeon first." << endl;
		cin.get();
	}
	if (classChoice == "3")
	{
		cout << "Showing you arent afraid of a simple dungeon, you head in first." << endl;
		cin.get();
	}
	if (classChoice == "4")
	{
		cout << "Being the bard, you go first to try and keep your teams spirit upbeat." << endl;
		cin.get();
	}


	//goblin
	currentEnemy = "Goblin";
	enemyHealth = goblinHealth;
	cin.get();
	cout << "You enter through the doors of the dungeon, and continue down its dark and slightly musty halls." << endl;
	cin.get();
	cout << "The stone walls get increasingly more worn as you walk down." << endl;
	cin.get();
	cout << "The torches on the wall start getting increasingly farther appart, and are placed in an erratic, random pattern." << endl;
	cin.get();
	cout << "It soon gets darker and darker from the space between each torch." << endl;
	cin.get();
	cout << "You soon enter a small room." << endl;
	cin.get();
	cout << "The floor is littered with boxes, chests, small scraps of food, and rubble." << endl;
	cin.get();
	cout << "The walls appear cracked, with many small vines creeping their way up them." << endl;
	cin.get();
	cout << "A low growl sounds out from behind a pile of rubble." << endl;
	cin.get();
	cout << "You near closer and a small goblin wearing some ragged clothes jumps out at you!" << endl;
	cin.get();
	cout << "The " << currentEnemy << " has " << enemyHealth << " health." << endl;
	cin.get();
	cout << "Rogue Health: " << rogueHealth << ". Warrior Health: " << warriorHealth << ". Wizard Health: " << wizardHealth << ". Bard Health: " << bardHealth << "." << endl;
	cin.get();
while (goblinHealth > 0)
{
	BATTLETURN++;
	cout << "BATTLE TURN : " << BATTLETURN << endl;
	cout << "Rogue, choose your move." << endl;
	cout << "1-Poison-Put poison on any of your other attacks. Doubles the damage of your attack for the next turn. 1 turn." << endl
		<< "2-Dagger stab-A basic attack, swipe at the enemy with your dagger. 1 turn. 90 damage." << endl
		<< "3-Sneak attack-A two turn move, dissapear before attacking next turn. 2 turns. 180 damage." << endl;
	//if rougeAlive
	rogueBattle();
	if (goblinAliveCheck() == false)
	{
		break;
	}
	cin.get();
	cout << "The " << currentEnemy << " has " << enemyHealth << " health left." << endl;
	cin.get();
	cout << "Warrior, choose your move." << endl
		<< "1-Block-Block an enemys incoming attack, has a 30% chance of stunning them, leaving them unable to attack for one turn. 1 turn." << endl
		<< "2-Sword flurry - Unleash a small flurry of attacks using your sword. 1 turn. 60 damage." << endl
		<< "3-Sword Smash - Using all your strength you smash the enemy with your sword. 2 turns. 120 damage." << endl;
	//if warriorAlive
	warriorBattle();
	if (goblinAliveCheck() == false)
	{
		break;
	}
	cin.get();
	cout << "The " << currentEnemy << " has " << enemyHealth << " health left." << endl;
	cin.get();
	cout << "Wizard, choose your move." << endl
		<< "1-Flame-Light your enemy on fire to slowly damage them for the rest of the battle. 1 turn." << endl
		<< "2-Life steal-Steal a small bit of your enemies life force to heal yourself. 1 turn. 75 damage." << endl
		<< "3-Fire storm-Gather power before launching a barrage of fireballs at your enemy. 2 turns. 150 damage." << endl;
	wizardBattle();
	if (goblinAliveCheck() == false)
	{
		break;
	}
	cin.get();
	cout << "The " << currentEnemy << " has " << enemyHealth << " health left." << endl;
	cin.get();
	cout << "1-Heal-Using magic you partially heal your teamates health, including yourself. 1 turn." << endl
		<< "2-Power boost-Boost your allies power on the next turn. 1 turn." << endl
		<< "3-Forbidden song-Use your instrument and play the forbidden genre, death metal, to instantly kill your enemy. Can only be used if the rest of the team is incapacitated. 1 turn." << endl;
	bardBattle();
	if (goblinAliveCheck() == false)
	{
		break;
	}
	cin.get();
	goblinBattle();
	if (goblinAliveCheck() == false)
	{
		break;
	}
	cin.get();
	cout << "Rogue Health: " << rogueHealth << ". Warrior Health: " << warriorHealth << ". Wizard Health: " << wizardHealth << ". Bard Health: " << bardHealth << "." << endl;
	
}
cout << "You defeat the goblin and continue onwards, passing through a door way that leads into another long corridor." << endl;

	//undead
	enemyHealth = undeadHealth;



	//giant
	enemyHealth = giantHealth;



	//dungeonmaster
}

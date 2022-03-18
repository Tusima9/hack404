#include <iostream>
#include <ctime>

using namespace std;

void PrintIntroduction(int Difficulty) 
{
	    //Print welcome message to the terminal
	    cout << " \n\nYou are a secret agent breaking into a level "<<Difficulty;
		cout << " Secure server room...\nEnter the correct code to continue...\n\n";

}
bool PlayGame(int Difficulty) 
{       
	    PrintIntroduction(Difficulty);

		//Declare 3 code
		const int CodeA = rand() % Difficulty + Difficulty;
		const int CodeB = rand() % Difficulty + Difficulty;
		const int CodeC = rand() % Difficulty + Difficulty;

		const int CodeSum = CodeA+CodeB+CodeC;
		const int CodeProduct = CodeA*CodeB*CodeC;

		//Print summ and product to the terminal
		cout << "+ There are 3 numbers in the code";
		cout << "\n+ The code add up to: " << CodeSum;
		cout << "\n+ The code multiply to give: " << CodeProduct<<endl;

		//Store player guess
		int GuessA, GuessB, GuessC;
        cin >> GuessA>>GuessB>>GuessC;

		int GuessSum = GuessA + GuessB + GuessC;
		int GuessProduct = GuessA * GuessB * GuessC;

		//Check if the player guess is correct
		if (GuessSum == CodeSum && GuessProduct == CodeProduct)
		{
			cout << "\n*** Well done agent! You have extracted a file! Keep going! ***";
			return true;
		}
		else
		{
			cout << "\n*** You entered the wrong code! Carefull agent! Try again *** ";
			
			return false;
			
		}
		//cout << "You entered: " <<GuessA<<GuessB<<GuessC<< endl;


}

int main()
{   
	srand(time(NULL)); // create new random sequence based on time of day 
	 
    int LevelDifficulty = 1;
	int const MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) // loop game until all the level are completed 
	{
		bool bLevelComplete = PlayGame(LevelDifficulty);
	   cin.clear();// Clear any error;
	   cin.ignore(); // Discards the buffer;

	   if (bLevelComplete) 
	   {
		   //increase level difficulty 
		   ++LevelDifficulty;
	   }
	   

	}
	cout << "\n*** Great work agent! You got all the files! Now let's get out of here!*** \n ";

    return 0;
}
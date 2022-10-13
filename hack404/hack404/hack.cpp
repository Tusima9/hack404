#include <iostream>
#include <ctime>

using namespace std;

void PrintIntroduction(int Difficulty) 
{
	    //Print welcome message to the terminal
	    cout << " \n\nあなたは、レベルに侵入する秘密工作員です "<<Difficulty;
		cout << " セキュリティの高いサーバールーム...\n正しいコードを入力してください...\n\n";

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
		cout << "+ コードには3つの数字があります";
		cout << "\n+ コードの合計は: " << CodeSum;
		cout << "\n+ コードを乗算するなら　その数学は：" << CodeProduct<<endl;

		//Store player guess
		int GuessA, GuessB, GuessC;
        cin >> GuessA>>GuessB>>GuessC;

		int GuessSum = GuessA + GuessB + GuessC;
		int GuessProduct = GuessA * GuessB * GuessC;

		//Check if the player guess is correct
		if (GuessSum == CodeSum && GuessProduct == CodeProduct)
		{
			cout << "\n*** よくやったエージェント! ファイルを抽出しましたね! 続け! ***";
			return true;
		}
		else
		{
			cout << "\n*** コードの入力を間違えました！慎重に扱ってください。再試行 *** ";
			
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
	cout << "\n*** よくやった、エージェント! すべてのファイルを手に入れましたね！さあ、ここから出よう！*** \n ";

    return 0;
}
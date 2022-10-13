#include <iostream>
#include <ctime>

using namespace std;

void PrintIntroduction(int Difficulty) 
{
	    //Print welcome message to the terminal
	    cout << " \n\n���Ȃ��́A���x���ɐN������閧�H����ł� "<<Difficulty;
		cout << " �Z�L�����e�B�̍����T�[�o�[���[��...\n�������R�[�h����͂��Ă�������...\n\n";

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
		cout << "+ �R�[�h�ɂ�3�̐���������܂�";
		cout << "\n+ �R�[�h�̍��v��: " << CodeSum;
		cout << "\n+ �R�[�h����Z����Ȃ�@���̐��w�́F" << CodeProduct<<endl;

		//Store player guess
		int GuessA, GuessB, GuessC;
        cin >> GuessA>>GuessB>>GuessC;

		int GuessSum = GuessA + GuessB + GuessC;
		int GuessProduct = GuessA * GuessB * GuessC;

		//Check if the player guess is correct
		if (GuessSum == CodeSum && GuessProduct == CodeProduct)
		{
			cout << "\n*** �悭������G�[�W�F���g! �t�@�C���𒊏o���܂�����! ����! ***";
			return true;
		}
		else
		{
			cout << "\n*** �R�[�h�̓��͂��ԈႦ�܂����I�T�d�Ɉ����Ă��������B�Ď��s *** ";
			
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
	cout << "\n*** �悭������A�G�[�W�F���g! ���ׂẴt�@�C������ɓ���܂����ˁI�����A��������o�悤�I*** \n ";

    return 0;
}
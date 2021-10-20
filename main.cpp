#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <iomanip>

using namespace std;

void DrawMan(int tries)
{
    cout<<endl<<endl;
    cout<<"     -----"<<endl;
    cout<<"    |     |"<<endl;
    cout<<"    |";
    if(tries<=4)
        cout<<"     O    ";
    cout<<endl;
    cout<<"    |";
    if(tries<=3)
        cout<<"    /|\\   ";
    cout<<endl;
    cout<<"    |";
    if(tries<=1)
        cout<<"    / \\    ";
    cout<<endl;
    cout<<"    |"<<endl;
    cout<<"    |"<<endl;
    cout<<"    |"<<endl;
    cout<<"  __|__"<<endl<<endl;
}

int main()
{

Game:    srand (time(NULL));
    string wordList[5] = {"freedom","love","peace","harmony","success"};
    string word;
    string guessed;

    word = wordList[rand()%5];

    int wordLength = word.length();
    string dispWord (wordLength, '_');

    int found = 0;
    char guess = ' ';
    int tries = word.length();
    int flagFound = 0;

        system("cls");
        cout<< endl<<endl<<endl;
        cout << setw (50); cout<<"*********************"<<endl;
        cout << setw (50); cout<<"*      HANGMAN      *"<<endl;
        cout << setw (50); cout<<"*********************"<<endl<<endl;
        cout << setw (51); cout<<"Press [ENTER] To Start"<<endl<<endl;
        cin.get();

    while(tries>=0)
    {
        system("cls");
        cout<<setw(73) ; cout<<"Tries: "<<tries<<" / "<<word.length()<<endl<<endl<<endl;
        cout<< setw(30);
        for(int i=0; i<wordLength; i++){
        cout<<" "<<dispWord[i]<<" ";}
        cout<<endl<<endl<<endl;
        cout<<" Guessed : "<<guessed<<endl;

        DrawMan(tries);

        if( found == wordLength )
        {

    char repeat = getche();
        system("cls");
        cout<<endl;
        cout << setw (50);
        cout<<"******************"<<endl;
        cout << setw (50);
        cout<<"*     You Win    *"<<endl;
        cout << setw (50);
        cout<<"******************"<<endl<<endl;
        cout << setw (44);
        cout<<"Play Again ?"<<endl;
        cout << setw (37);
        cout<<"Y/N: ";

        cin>>repeat;

        if( repeat == 'Y' || repeat == 'y' )
        {
            goto Game;
        }
        else break;
        }

        if( tries == 0)
            break;

        cout<<" Guess:";
        guess = getche();

        guessed = guessed + " " + guess;

        if( dispWord.find(guess)!=string::npos )
            tries++;

        flagFound = 0;
        for(int i=0; i<wordLength; i++)
        {
            if( word[i]==guess && dispWord[i]=='_' )
            {
                dispWord[i] = guess;
                found++;
                flagFound = 1;
            }
        }

        if( !flagFound )
            tries--;
    }
    if( found != wordLength )
    {    char repeat = getche();
        system("cls");
        cout<<endl;
        cout << setw (50);
        cout<<"******************"<<endl;
        cout << setw (50);
        cout<<"*    You Lose    *"<<endl;
        cout << setw (50);
        cout<<"******************"<<endl<<endl;
        cout << setw (44);
        cout<<"Play Again ?"<<endl;
        cout << setw (37);
        cout<<"Y/N: ";

        cin>>repeat;

        if( repeat == 'Y' || repeat == 'y' )
        {
            goto Game;
        }
        else EXIT_SUCCESS;

    }
    return 0;
}

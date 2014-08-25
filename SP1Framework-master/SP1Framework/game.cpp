// This is the main file for the game logic and function
//
//
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>
#include <istream>
double elapsedTime;
double deltaTime;
bool keyPressed[K_COUNT];
short int loc1,loc2,loc3,loc4;
double rand1,rand2,rand3,rand4;
COORD charLocation, wordLocation1, wordLocation2, wordLocation3, wordLocation4;
COORD consoleSize;
vector<string> words;
string line, userInput;
bool gameStart =false;
void init()
{
	//Putting words from .txt file
	int i =0;
	ifstream myfile ("word.txt");
	if(myfile.is_open())
	{
		while (getline(myfile, line))
		{
			words.push_back(line);
			i++;	
		}
		myfile.close();
	}
	else
	{
		std::cout<<"unable to open file";
	}

    // Set precision for floating point output
    std::cout << std::fixed << std::setprecision(3);

    SetConsoleTitle(L"SP1 Framework");

    // Sets the console size, this is the biggest so far.
    setConsoleSize(79, 28);

    // Get console width and height
    CONSOLE_SCREEN_BUFFER_INFO csbi; /* to get buffer info */     

    /* get the number of character cells in the current buffer */ 
    GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &csbi );
    consoleSize.X = csbi.srWindow.Right + 1;
    consoleSize.Y = csbi.srWindow.Bottom + 1;

    // set the character to be in the center of the screen.
    charLocation.X = consoleSize.X / 2;
    charLocation.Y = consoleSize.Y= 60;

	// set the character to be in the center of the screen.
	loc1 = consoleSize.X/10;
	loc2 = loc1+18;
	loc3 = loc2+18;
	loc4 = loc3+18;
    wordLocation1.X = loc1;
	wordLocation2.X = loc2;
	wordLocation3.X = loc3;
	wordLocation4.X = loc4;
	
	/* initialize random seed: */
    srand (time(NULL));

	//set dropping speed
	rand1=((double)rand()) / ((double)RAND_MAX) * 2.0 + 1.1;
	rand2=((double)rand()) / ((double)RAND_MAX) * 2.0 + 1.1;
	rand3=((double)rand()) / ((double)RAND_MAX) * 2.0 + 1.1;
	rand4=((double)rand()) / ((double)RAND_MAX) * 2.0 + 1.1;

    elapsedTime = 0.0;
}

void shutdown()
{
    // Reset to white text on black background
	colour(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
}

void getInput()
{    
    keyPressed[K_A] = isKeyPressed(0X41);
	keyPressed[K_B] = isKeyPressed(0X42);
	keyPressed[K_C] = isKeyPressed(0X43);
	keyPressed[K_D] = isKeyPressed(0X44);
	keyPressed[K_E] = isKeyPressed(0X45);
	keyPressed[K_F] = isKeyPressed(0X46);
	keyPressed[K_G] = isKeyPressed(0X47);
	keyPressed[K_H] = isKeyPressed(0X48);
	keyPressed[K_I] = isKeyPressed(0X49);
	keyPressed[K_J] = isKeyPressed(0X4A);
	keyPressed[K_K] = isKeyPressed(0X4B);
	keyPressed[K_L] = isKeyPressed(0X4C);
	keyPressed[K_M] = isKeyPressed(0X4D);
	keyPressed[K_N] = isKeyPressed(0X4E);
	keyPressed[K_O] = isKeyPressed(0X4F);
	keyPressed[K_P] = isKeyPressed(0X50);
	keyPressed[K_Q] = isKeyPressed(0X51);
	keyPressed[K_R] = isKeyPressed(0X52);
	keyPressed[K_S] = isKeyPressed(0X53);
	keyPressed[K_T] = isKeyPressed(0X54);
	keyPressed[K_U] = isKeyPressed(0X55);
	keyPressed[K_V] = isKeyPressed(0X56);
	keyPressed[K_W] = isKeyPressed(0X57);
	keyPressed[K_X] = isKeyPressed(0X58);
	keyPressed[K_Y] = isKeyPressed(0x59);
	keyPressed[K_Z] = isKeyPressed(0x5A);
	keyPressed[K_BACKSPACE] = isKeyPressed(VK_BACK);
	keyPressed[K_SPACE] = isKeyPressed(VK_SPACE);
	keyPressed[K_ESCAPE] = isKeyPressed(VK_ESCAPE);


}
void update(double dt)
{
    // get the delta time
    elapsedTime += dt;
    deltaTime = dt;
	if (keyPressed[K_A])
		userInput+="A";
	if (keyPressed[K_B])
		userInput+="B";
	if (keyPressed[K_C])
		userInput+="C";
	if (keyPressed[K_D])
		userInput+="D";
	if (keyPressed[K_E])
		userInput+="E";
	if (keyPressed[K_F])
		userInput+="F";
	if (keyPressed[K_G])
		userInput+="G";
	if (keyPressed[K_H])
		userInput+="H";
	if (keyPressed[K_I])
		userInput+="I";
	if (keyPressed[K_J])
		userInput+="J";
	if (keyPressed[K_K])
		userInput+="K";
	if (keyPressed[K_L])
		userInput+="L";
	if (keyPressed[K_M])
		userInput+="M";
	if (keyPressed[K_N])
		userInput+="N";
	if (keyPressed[K_O])
		userInput+="O";
	if (keyPressed[K_P])
		userInput+="P";
	if (keyPressed[K_Q])
		userInput+="Q";
	if (keyPressed[K_R])
		userInput+="R";
	if (keyPressed[K_S])
		userInput+="S";
	if (keyPressed[K_T])
		userInput+="T";
	if (keyPressed[K_U])
		userInput+="U";
	if (keyPressed[K_V])
		userInput+="V";
	if (keyPressed[K_W])
		userInput+="W";
	if (keyPressed[K_X])
		userInput+="X";
	if (keyPressed[K_Y])
		userInput+="Y";
	if (keyPressed[K_Z])
		userInput+="Z";
	if(keyPressed[K_BACKSPACE])
	{
		if(userInput.size()>0){
		userInput.pop_back();
		}
	}
    // Updating the userInput based on the key press
	
    // quits the game if player hits the escape key
    if (keyPressed[K_ESCAPE])
       g_quitGame = true;
}
void craigtest()
{

}
void render()
{
    //clear previous screen
    //colour(0x0F);
    cls();

	
    //render the game

    //render test screen code (not efficient at all)
    const WORD colors[] =   {
	                        0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
	                        0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
	                        };
	
	/* display WoW
	for (int i = 0; i < 12; ++i)
	{
		gotoXY(3*i,i+1);
		colour(colors[i]);
		std::cout << "WOW";
	}

    // render time taken to calculate this frame
    gotoXY(70, 0);
    colour(0x1A);
    std::cout << 1.0 / deltaTime << "fps" << std::endl;
  
    gotoXY(0, 0);
    colour(0x59);
    std::cout << elapsedTime << "secs" << std::endl;

    */
	// render character
    gotoXY(charLocation);
    std::cout << (string)userInput;
	
	startGame();
}

void startGame()
{
    //render character
    gotoXY(wordLocation1);
    std::cout << words[0];
    gotoXY(wordLocation2);
    std::cout << words[1];
	gotoXY(wordLocation3);
    std::cout << words[2];
	gotoXY(wordLocation4);
    std::cout << words[3];
	moveWords();
}

void moveWords()
{
	if(wordLocation1.Y < 50){
		wordLocation1.Y+=rand1;
	}
	else {
		rand1=((double)rand()) / ((double)RAND_MAX) * 2.0 + 1.1;;
		wordLocation1.Y =0;
	}
	if(wordLocation2.Y < 50){
		wordLocation2.Y+=rand2;
	}
	else {
		wordLocation2.Y =0;
		rand2=((double)rand()) / ((double)RAND_MAX) * 2.0 + 1.1;;
	}

	if(wordLocation3.Y < 50){
		wordLocation3.Y+=rand3;
	}
	else {
		wordLocation3.Y =0;
		rand3=((double)rand()) / ((double)RAND_MAX) * 2.0 + 1.1;;
	}
	if(wordLocation4.Y < 50){
		wordLocation4.Y+=rand4;
	}
	else {
		wordLocation4.Y =0;
		rand4=((double)rand()) / ((double)RAND_MAX) * 2.0 + 1.1;;
	}
}

void matchWords()
{
}
void testSADada();

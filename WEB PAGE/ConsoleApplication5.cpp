

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	fstream x;
	x.open("about.html", ios::out );
	x << "                       About dino          " << endl;
	x << " This code is a simple game written in C++. The game is called DINO RUN \n  and it involves controlling a small dinosaur to jump over obstacles.\n The game is played in the console window. The code uses several \nlibraries including iostream, conio.h, time.h, and wtypes.h. The game is played\n by using the spacebar to jump and the p key to pause the game. The game includes instructions for playing and has a menu for restarting or exiting the game. The code uses various functions to set cursor position, draw the dinosaur and obstacles, and to initialize the game. The code also uses a loop to continuously update the game state and to detect user input. Overall, the code is a simple example of creating a game with basic game mechanics using C++." << endl;
	x << "           About Fluppy bird                 " << endl;
	x << "The C++ Flappy Bird game in the console is an entertaining and addictive implementation of the classic Flappy Bird game in a text-based environment. Using the console graphics, you control a cute bird and guide it through the obstacles to reach the highest score possible. The bird moves along with the beat of the user's keyboard input, making it a thrill to pass through more and more pipes. The game incorporates sounds to create an immersive experience, giving the player an authentic Flappy Bird feel. The game's simple yet challenging gameplay combined with the text-based environment is sure to provide hours of exciting gameplay." << endl;
	x << "The project is done by Madaminjanova Khalima" << endl;
	x << "The course NAME:COSK1560" << endl;
	x << " Professor : ISMAIL AHMAD" << endl;
	x << "Department of Menegement Information technologies" << endl;



}


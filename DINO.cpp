//FINAl PROJECT
// DONE_by_Khalima
// CODE is explained in comments 
// Go to simple web page to get more information about DINO  and another project !
 




#include <iostream> 
#include <conio.h>   //  requiered header files
#include <time.h>
#include <wtypes.h>


#define dinoPos 2  // two constants 
#define hurdlePos 74

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); //possision 
COORD CursorPosition;

int dinoY;//integer for dino 
int speed = 40;// speed control
int gameover = 0;//game over 

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;   // two functions
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // set console position
}

void setcursor(bool visible, DWORD size) {
    if (size == 0) {
        size = 20; // default cursor size Changing to numbers from 1 to 20, decreases cursor width
    }
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;   //positions of the dinosaur and hurdle
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(console, &lpCursor);
}

void init() { //clears the console screen and sets gameover to 0.
    system("cls"); 
    gameover = 0;
    gotoxy(3, 2); cout << "SCORE : "; 
    for (int i = 0; i < 79; i++) { // cycle for movement
        gotoxy(1 + i, 1); cout << "Я";
        gotoxy(1 + i, 25); cout << "Я"; //   two function gotxy  and setcursor  //for moving concsole cursor 
    }
}

void moveDino(int jump = 0) { // movement of dino 
    static int foot = 0;

    if (jump == 0) // foot posision of dino 
        dinoY = 0;
    else if (jump == 2)
        dinoY--;
    else dinoY++;

    gotoxy(dinoPos, 15 - dinoY);cout << "                 ";
    gotoxy(dinoPos, 16 - dinoY);cout << "         ЬЫЯЫЫЫЫЬ";
    gotoxy(dinoPos, 17 - dinoY);cout << "         ЫЫЫЫЫЫЫЫ";
    gotoxy(dinoPos, 18 - dinoY);cout << "         ЫЫЫЫЫЯЯЯ"; //body of dino 
    gotoxy(dinoPos, 19 - dinoY);cout << " Ы      ЬЫЫЫЫЯЯЯ ";
    gotoxy(dinoPos, 20 - dinoY);cout << " ЫЫЬ  ЬЫЫЫЫЫЫЬЬЬ ";
    gotoxy(dinoPos, 21 - dinoY);cout << " ЯЫЫЫЫЫЫЫЫЫЫЫ  Я ";
    gotoxy(dinoPos, 22 - dinoY);cout << "   ЯЫЫЫЫЫЫЫЯ     ";
    gotoxy(dinoPos, 23 - dinoY);
   
  


    if (jump == 1 || jump == 2) {
        cout << "    ЫЫЯ ЯЫ       "; // jumping function  foot of the dino
        gotoxy(2, 24 - dinoY);
        cout << "    ЫЬ   ЫЬ      ";
    }
    else if (foot == 0) {
        cout << "    ЯЫЫЯ  ЯЯЯ    "; // original jump parameter 
        gotoxy(2, 24 - dinoY);
        cout << "      ЫЬ         ";
        foot = !foot;
    }
    else if (foot == 1) {
        cout << "     ЯЫЬ ЯЫ      ";
        gotoxy(2, 24 - dinoY);           // running animation 
        cout << "          ЫЬ     ";
        foot = !foot;
    }

    gotoxy(2, 25 - dinoY);
    if (jump == 0) {
        cout << "ЯЯЯЯЯЯЯЯЯЯЯЯЯЯЯЯЯ";
    }
    else {
        cout << "                ";
    }
    Sleep(speed);
}
void drawHurdle() {  //just some screens for certain actions
    static int plantX = 0;
    static int score = 0;
    if (plantX == 56 && dinoY < 4) {  //end of the game  settings
        score = 0;
        speed = 40;
        gotoxy(36, 8);
        system("cls");
        cout << "" << endl << endl;
        cout << " ------------------------------------------------------------------------- " << endl;
        cout << "|    *****      *     *       * ******       ****  *       ****** ****    |" << endl;
        cout << "|   *          * *    * *   * * *           *    *  *     * *     *   *   |" << endl;
        cout << "|   *  ****   *   *   *  * *  * *****       *    *   *   *  ****  ****    |" << endl;
        cout << "|   *  *  *  *******  *   *   * *           *    *    * *   *     * *     |" << endl;
        cout << "|    *****  *       * *       * ******       ****      *    ***** *   *   |" << endl;
        cout << " ------------------------------------------------------------------------- " << endl;
        cout << "" << endl << endl;
        cout << "                        Y O U R   S C O R E : " << score << endl << endl;
        cout << "" << endl << endl;
        _getch();
        gameover = 1;
    }


    gotoxy(hurdlePos - plantX, 20);cout << "| | ";
    gotoxy(hurdlePos - plantX, 21);cout << "| | ";
    gotoxy(hurdlePos - plantX, 22);cout << "|_| "; //  character at a specific position and moves it towards the dinosaur
    gotoxy(hurdlePos - plantX, 23);cout << " |  ";
    gotoxy(hurdlePos - plantX, 24);cout << " |  ";

    plantX++;

    if (plantX == 73) {
        plantX = 0; // checks if it has hit something
        score++;
        gotoxy(11, 2);cout << "     "; // speed and score 
        gotoxy(11, 2);cout << score;
        if (speed > 20)
            speed--;
    }
}


void play() {  // input, and if the user presses the spacebar, it makes the dinosaur jump. 
    system("cls");
    char ch;
    int i;
    init();
    while (true) {
        while (!_kbhit()) {
            if (gameover == 1) {
                return;
            }
            moveDino();
            drawHurdle();
        }
        ch = _getch();
        if (ch == 32) {
            i = 0;
            while (i < 12) {
                moveDino(1);
                drawHurdle();
                i++;
            }
            while (i > 0) {
                moveDino(2);
                drawHurdle();
                i--;
            }
        }
        else if (ch == 'p' || ch == 'P') //  pausing or quitting the game.
            _getch();
        else if (ch == 27)
            break;
    }
}

void instructions() {  //instructions menu 
    system("cls");
    cout << "Instructions";
    cout << "\n----------------";
    cout << "\n1. Avoid hurdles by jumping";
    cout << "\n2. Press 'Spacebar' to jump ";
    cout << "\n3. Press 'p' to pause game ";
    cout << "\n4. Press 'Escape' to exit from game";
    cout << "\n\nPress any key to go back to menu";
    _getch();
}

int main() { // general menu

    setcursor(0, 0);

    do {
        system("cls");
        gotoxy(10, 5); cout << " -------------------------- ";
        gotoxy(10, 6); cout << " |        DINO RUN        | ";
        gotoxy(10, 7); cout << " -------------------------- ";
        gotoxy(10, 9); cout << "1. Start Game";
        gotoxy(10, 10); cout << "2. Instructions";
        gotoxy(10, 11); cout << "3. Quit";
        gotoxy(10, 13); cout << "Select option: "; //displays a menu for the user to start the game
        char op = _getche();

        if (op == '1') play();
        else if (op == '2') instructions();
        else if (op == '3') exit(0);//calls the respective functions based on user input.


    } while (1);

    return 0;
}



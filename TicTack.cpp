#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

//_______________________ Data Structures ___________________________

int const size = 3;
char board[size][size];
char used[size * size] = {'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'};
int flag = 0;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

//_______________________ Function Prototypes _______________________
void head(void);
char menu(void);
void help(void);
void making_null(void);
void play_game(void);
void taking_inputs(string ply1, string ply2);
void cube(void);
void input_data(char box_no, char symbol);
bool is_box_valid(char box);
bool check_rows(char symbol);
bool check_coloumns(char symbol);
bool check_diagonals(char symbol);
bool isWinner(string ply1, string ply2);
void congragulation(string player, int a);
void developer(void);

//_______________________ Main Function _____________________________
main()
{

    char option;
    while (true)
    {
        option = menu();

        if (option == '1')
        {
            play_game();

            getch();
        }
        else if (option == '2')
        {
            help();
           
        }
        else
        {
            break;
        }
    }
    developer();
}

void head(void)
{
    cout << endl;
    SetConsoleTextAttribute(h, 6);
    cout << " _________________________________________________________________________________________________" << endl;
    cout << "|                                                                                                 |" << endl;
    cout << "|                       ----------------------------------------                                  |" << endl;
    cout << "|           ____________ WELCOME TO GAME :  ***  TIC TAC TOE ***  ____________                    |" << endl;
    cout << "|                       ----------------------------------------                                  |" << endl;
    cout << "|_________________________________________________________________________________________________|" << endl;
    cout << endl;
    SetConsoleTextAttribute(h, 15);
}

char menu(void)
{

    system("cls");

    head();

    cout << endl;
    cout << "   MENU >> " << endl;
    cout << "                                                                                              " << endl;
    cout << "   1. Play Game :)            " << endl;
    cout << "   2. Help !                  " << endl;
    cout << "   3. Exit                    " << endl;

    char option;

    while (true)
    {
        cout << endl;
        cout << "   Your Option...... ";
        cin >> option;

        if (option == '1' || option == '2' || option == '3')
        {
            break;
        }
        SetConsoleTextAttribute(h, 4);
        cout << "\n   Invalid Option ! " << endl;
        cout << "   Please Enter Correct Option..." << endl;
        SetConsoleTextAttribute(h, 15);
    }
}

void making_null(void)
{
    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
        {
            board[x][y] = ' ';
        }
    }
    for (int i = 0; i < size * size; i++)
    {
        used[i] = '\0';
    }
}

void help(void)
{
    system("cls");

    head();
    cout << " Menu >> Help  " << endl;
    cout << endl;
    cout << "                        How to play Game..                                 " << endl;
    cout << "                                      _________________  " << endl;
    cout << "                                     |     |     |     | " << endl;
    cout << "                                     |  1  |  2  |  3  | " << endl;
    cout << "                                     |_____|_____|_____| " << endl;
    cout << "                                     |     |     |     | " << endl;
    cout << "                                     |  4  |  5  |  6  | " << endl;
    cout << "                                     |_____|_____|_____| " << endl;
    cout << "                                     |     |     |     | " << endl;
    cout << "                                     |  7  |  8  |  9  | " << endl;
    cout << "                                     |_____|_____|_____| " << endl;
    cout << endl;
    cout << "   For playing your turn you have to enter the box address as given up...." << endl;
    cout << "\n  EXAMPLE :" << endl;
    cout << "\n  Player 1 Turn Your Symbol is \" X \" ... " << endl;
    cout << "  Enter Box Address : 1" << endl;
    cout << "                                      _________________  " << endl;
    cout << "                                     |     |     |     | " << endl;
    cout << "                                     |  X  |     |     | " << endl;
    cout << "                                     |_____|_____|_____| " << endl;
    cout << "                                     |     |     |     | " << endl;
    cout << "                                     |     |     |     | " << endl;
    cout << "                                     |_____|_____|_____| " << endl;
    cout << "                                     |     |     |     | " << endl;
    cout << "                                     |     |     |     | " << endl;
    cout << "                                     |_____|_____|_____| " << endl;
    cout << "\n Press any key for continue...... " << endl;
    getch();
}

void play_game(void)
{
    string player1, player2;
    system("cls");
    head();

    cout << endl;
    cout << " Let Starts The Game :) .............. " << endl;
    cout << "\n\n";
    cout << " Enter Name of Player 1 ...: ";
    cin >> player1;
    cout << " Your Symbol is  \" X \"  " << endl;
    cout << endl;
    cout << " Enter Name of Player  ...: ";
    cin >> player2;
    cout << " Your Symbol is  \" O \"  " << endl;
    cout << endl;
    cout << "Press any key to Start the Game....." << endl;
    getch();

    taking_inputs(player1, player2);
}

void taking_inputs(string ply1, string ply2)
{

    int draw = 1;

    making_null();

    for (int turn = 1; turn <= size * size + 1; turn++)
    {
        system("cls");

        head();

        SetConsoleTextAttribute(h, 6);
        cout << "|  Playing Game :)                                                                                |" << endl;
        cout << "|_________________________________________________________________________________________________|" << endl;
        cout << "\n";
        SetConsoleTextAttribute(h, 15);

        cout << "                                          PLAYERS   " << endl;
        cout << "                                _____________________________ " << endl;
        cout << "                                     " << endl;
        cout << "                                   Player 1  : " << ply1 << endl;
        cout << "                                   Player 2  : " << ply2 << endl;

        cube();

        if (isWinner(ply1, ply2))
        {
            draw = 0;
            break;
        }

        char box;

        if (turn == 1 || turn == 3 || turn == 5 || turn == 7 || turn == 9)
        {
            cout << " Player 1 Turn Your Symbol is \" X \" ... " << endl;
            while (true)
            {
                cout << " Enter Box Address : ";
                cin >> box;

                if (is_box_valid(box))
                {
                    input_data(box, 'X');
                    break;
                }
                SetConsoleTextAttribute(h, 4);
                cout << " Invalid Input ! " << endl;
                cout << " Again Input " << endl;
                SetConsoleTextAttribute(h, 15);
            }
        }
        else if (turn == 2 || turn == 4 || turn == 6 || turn == 8)
        {
            cout << " Player 2 Turn Your Symbol is \" O \" ... " << endl;
            while (true)
            {
                cout << " Enter Box Address : ";
                cin >> box;

                if (is_box_valid(box))
                {
                    input_data(box, 'O');
                    break;
                }
                SetConsoleTextAttribute(h, 4);
                cout << " Invalid Input ! " << endl;
                cout << " Again Input " << endl;
                SetConsoleTextAttribute(h, 15);
            }
        }
    }

    if (draw == 1)
    {
        SetConsoleTextAttribute(h, 8);
        cout << "                                        ************ " << endl;
        cout << "                                         Match Draw  " << endl;
        cout << "                                        ************ " << endl;
        SetConsoleTextAttribute(h, 15);
    }
}

void cube(void)
{
    cout << "\n";
    cout << "                                                        " << endl;
    cout << "                                      _________________  " << endl;
    cout << "                                     |     |     |     | " << endl;
    cout << "                                     |  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  | " << endl;
    cout << "                                     |_____|_____|_____| " << endl;
    cout << "                                     |     |     |     | " << endl;
    cout << "   BOX KEY                           |  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  | " << endl;
    cout << "    _____                            |_____|_____|_____| " << endl;
    cout << "   |1|2|3|                           |     |     |     | " << endl;
    cout << "   |4|5|6|                           |  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  | " << endl;
    cout << "   |7|8|9|                           |_____|_____|_____| " << endl;
    cout << endl;
}

void input_data(char box_no, char symbol)
{
    if (box_no == '1')
    {
        board[0][0] = symbol;
    }
    else if (box_no == '2')
    {
        board[0][1] = symbol;
    }
    else if (box_no == '3')
    {
        board[0][2] = symbol;
    }
    else if (box_no == '4')
    {
        board[1][0] = symbol;
    }
    else if (box_no == '5')
    {
        board[1][1] = symbol;
    }
    else if (box_no == '6')
    {
        board[1][2] = symbol;
    }
    else if (box_no == '7')
    {
        board[2][0] = symbol;
    }
    else if (box_no == '8')
    {
        board[2][1] = symbol;
    }
    else if (box_no == '9')
    {
        board[2][2] = symbol;
    }

    used[flag] = box_no;
    flag++;
}

bool is_box_valid(char box)
{
    if (box >= '1' && box <= '9')
    {
        for (int i = 0; i < size * size; i++)
        {
            if (used[i] == box)
            {
                SetConsoleTextAttribute(h, 4);
                cout << " Box Already Used ! " << endl;
                SetConsoleTextAttribute(h, 15);
                return false;
            }
        }
        return true;
    }
    return false;
}

bool check_rows(char symbol)
{
    int count = 0;

    for (int row = 0; row < size; row++)
    {
        count = 0;
        for (int col; col < size; col++)
        {
            if (board[row][col] == symbol)
            {
                count++;
            }
        }
        if (count == size)
        {
            return true;
        }
    }
    return false;
}

bool check_coloumns(char symbol)
{
    int count = 0;

    for (int col = 0; col < size; col++)
    {
        count = 0;
        for (int row = 0; row < size; row++)
        {
            if (board[row][col] == symbol)
            {
                count++;
            }
        }
        if (count == size)
        {
            return true;
        }
    }
    return false;
}

bool check_diagonals(char symbol)
{
    int count = 0;
    for (int idx = 0; idx < size; idx++)
    {
        if (board[idx][idx] == symbol)
        {
            count++;
        }
    }
    if (count == size)
    {
        return true;
    }

    count = 0;
    for (int row = 0, col = 2; row < size; row++, col--)
    {
        if (board[row][col] == symbol)
        {
            count++;
        }
    }
    if (count == size)
    {
        return true;
    }
    return false;
}

bool isWinner(string ply1, string ply2)
{
    if (check_rows('X') || check_coloumns('X') || check_diagonals('X'))
    {
        congragulation(ply1, 1);
    }
    else if (check_rows('O') || check_coloumns('O') || check_diagonals('O'))
    {
        congragulation(ply2, 2);
    }
    else
    {
        return false;
    }
}

void congragulation(string player, int a)
{
    SetConsoleTextAttribute(h, 10);
    cout << endl;
    cout << "                                  _______________________" << endl;
    cout << "                                  *** Congragulation *** " << endl;
    cout << "                                      Player " << a << " : " << player << endl;
    cout << "                                   *** WON THE GAME *** " << endl;
    cout << "                                  _______________________" << endl;
    SetConsoleTextAttribute(h, 15);
}

void developer(void)
{
    SetConsoleTextAttribute(h, 6);
    cout << "_________________________________________________________________________________________________" << endl;
    cout << "\n";
    cout << "                               *** GAME : TIC TAC TOE ***  " << endl;
    cout << "                               Developer : *** HAMZA RASHEED *** " << endl;
    cout << "_________________________________________________________________________________________________" << endl;
    SetConsoleTextAttribute(h, 15);
}
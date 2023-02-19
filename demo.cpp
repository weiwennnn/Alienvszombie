// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: T11L
// Names: HEE_KAI_WEN | LEE_WEI_WEN | TAI_JIN_PEI
// IDs: 1211100744 | 1211103858 | 1211101726
// Emails: 1211100744@student.mmu.edu.my | 1211103858@student.mmu.edu.my | 1211101726@student.mmu.edu.my
// Phones: 01133379781 | 0123234903 | 01111553789
// *********************************************************

// TODO: Fill in the missing information above and delete this line.

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

namespace pf
{
    int cls()
    {
#if defined(_WIN32)
        return std::system("cls");
#elif defined(__linux__) || defined(__APPLE__)
        return std::system("clear");
#endif
    }

    int pause()
    {
#if defined(_WIN32)
        return std::system("pause");
#elif defined(__linux__) || defined(__APPLE__)
        return std::system(R"(read -p "Press any key to continue . . . " dummy)");
#endif
    }

    void errormessage1()
    {
        cout << " =========================================================" << endl;
        cout << "  Reminder: Please enter odd number for rows and columns! " << endl;
        cout << " =========================================================" << endl;
    }

    void errormessage2()
    {
        cout << " ==========================================" << endl;
        cout << "  Reminder: Maximum number of zombie is 9! " << endl;
        cout << " ==========================================" << endl
             << endl;
    }

}

// global variable
int dimX_, dimY_;
int x1, y1, ch1; // alien coordiante

// declare function
vector<vector<char>> map_;
void init(int row, int column);
const void display(int row, int column);
void setobject(int col, int row, char object);
void locationA(int row, int col);

void defsetting(int row, int column, int zombie)
{
    char yn;
    pf::cls();

    cout << " Default Game Setting " << endl;
    cout << "----------------------" << endl;
    cout << "Board Rows    : " << row << endl;
    cout << "Board Columns : " << column << endl;
    cout << "Zombie Count  : " << zombie << endl
         << endl;
    cout << "Do you wish to change the game settings? (y/n) => ";
}

int resetSetting(int &row, int &column, int &zombie) // reset dimension of game board
{
    char decision;
    defsetting(row, column, zombie);
    cin >> decision;
    decision = toupper(decision);
    switch (decision)
    {
    case 'Y':
        do
        {
            pf::cls();
            cout << "Board Settings" << endl;
            cout << "--------------" << endl;
            cout << "Enter Rows => ";
            cin >> row;
            cout << "Enter Columns => ";
            cin >> column;
            cout << endl;
            if (row % 2 != 0 && column % 2 != 0)
            {
                init(row, column);

                do
                {
                    cout << "Zombie Settings" << endl;
                    cout << "---------------" << endl;
                    cout << "Enter number of zombies => ";
                    cin >> zombie;
                    cout << endl;

                    if (zombie <= 0 || zombie >= 10)
                    {
                        pf::errormessage2();
                        pf::pause();
                        cout << endl;
                    }
                    else
                    {
                        cout << "Settings Updated." << endl;
                    }
                } while (zombie <= 0 || zombie >= 10);
            }
            else
            {
                pf::errormessage1();
                pf::pause();
            }

        } while (row % 2 == 0 || column % 2 == 0);
        break;

    case 'N':
        cout << "Default Settings Maintaned" << endl;
        row = 9;
        column = 5;
        zombie = 1;
        break;

    default:
        cout << "Invalid input! Please try again." << endl;
        pf::pause();
        pf::cls();
        while (decision != 'Y' && decision != 'N')
        {
            defsetting(row = 9, column = 5, zombie = 1);
        }

        break;
    }

    pf::pause();
    pf::cls();
    init(row, column);

    return row, column, zombie;
}

void init(int row, int column)
{
    int row_, col_; // row_ is the dimension x, col_ is the y dimension for boarding
    row_ = row;
    col_ = column;

    char objects[] = {' ', ' ', ' ', 'r', 'h', 'p', '<', '>', '^', 'v'};
    int noOfObjects = sizeof(objects); // number of objects in the objects array

    // create dynamic 2D array using vector
    map_.resize(col_); // create empty rows
    for (int i = 0; i < col_; ++i)
    {
        map_[i].resize(row_); // resize each row
    }
    // put random characters into the vector array
    for (int i = 0; i < col_; ++i)
    {
        for (int j = 0; j < row_; ++j)
        {
            int objNo = rand() % noOfObjects;
            map_[i][j] = objects[objNo];
        }
    }
}

const void display(int row_, int col_)
{

    for (int i = 0; i < col_; ++i)
    {
        // display upper border of the row
        cout << "  ";
        for (int j = 0; j < row_; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;
        // display row number
        cout << setw(2) << (col_ - i);

        // display cell content and border of each column
        for (int j = 0; j < row_; ++j)
        {
            cout << "|" << map_[i][j];
        }
        cout << "|" << endl;
    }

    // display lower border of the last row
    cout << "  ";
    for (int j = 0; j < row_; ++j)
    {
        cout << "+-";
    }
    cout << "+" << endl;

    // display column number
    cout << "  ";
    for (int j = 0; j < row_; ++j)
    {
        int digit = (j + 1) / 10;
        cout << " ";
        if (digit == 0)
            cout << " ";
        else
            cout << digit;
    }
    cout << endl;
    cout << "  ";
    for (int j = 0; j < row_; ++j)
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl
         << endl;
}

int &getDimX()
{
    return dimX_;
}
int &getDimY()
{
    return dimY_;
}

void setObject(int col, int row, char object)
{
    map_[dimY_ - row][col - 1] = object;
}

// tjp part
void help(string command)
{
    cout << setw(9) << left << "1. up" << setw(21) << left << "- Move up." << endl;
    cout << setw(9) << left << "2. down" << setw(21) << left << "- Move down." << endl;
    cout << setw(9) << left << "3. left" << setw(21) << left << "- Move left." << endl;
    cout << setw(9) << left << "4. right" << setw(21) << left << "- Move right." << endl;
    cout << setw(9) << left << "5. arrow" << setw(21) << left << "- Change the direction of an arrow." << endl;
    cout << setw(9) << left << "6. save" << setw(21) << left << "- Save this Game." << endl;
    cout << setw(9) << left << "7. load" << setw(21) << left << "- Load a Game." << endl;
    cout << setw(9) << left << "8. quit" << setw(21) << left << "- Quit this Game." << endl;
    cout << setw(9) << left << "9. help" << setw(21) << left << "- Display these users' commands. " << endl;
}

void up(string command, int column, int row)
{
    cout << "string transfered: " << command << endl;
    cout << "Testing Kcolumnc in up: " << column << endl;
    y1 = y1 + 1;
    cout << "alien coordiante: " << x1 << "\t" << y1 << endl;
    return;
    pf::pause();
}

void down(string command)
{
    cout << "string transfered: " << command << endl;
}

void left(string command)
{
    cout << "string transfered: " << command << endl;
}

void right(string command)
{
    cout << "string transfered: " << command << endl;
}

void arrow(string command)
{
    cout << "string transfered: " << command << endl;
}

void save(string command)
{
    cout << "string transfered: " << command << endl;
}

void load(string command)
{
    cout << "string transfered: " << command << endl;
}

void quit(string command)
{
    char end;
    cout << "Are You Sure To Quit the game?(y/n) ";
    cin >> end;
    end = toupper(end);
    switch (end)
    {
    case 'Y':
        cout << "string transfered: " << command << endl;
        cout << "Good bye!";
        exit(0);
        break;
    case 'N':
        cout << "Resume the game."<<endl; 
        cout <<"Please enter new command:";
        cin >> command;
    }

    
}

// cmd main body
void cmd()
{
    string command;
    command.clear();
    cout << "\ncommand >";
    cin >> command;

    if (command == "help")
    {
        help(command);
    }

    else if (command == "up")
    {
        up(command, dimX_, dimY_);
    }

    else if (command == "down")
    {
        down(command);
    }

    else if (command == "left")
    {
        left(command);
    }

    else if (command == "right")
    {
        right(command);
    }

    else if (command == "arrow")
    {
        arrow(command);
    }

    else if (command == "save")
    {
        save(command);
    }

    else if (command == "load")
    {
        load(command);
    }

    else if (command == "quit")
    {

        quit(command);
    }

    else
    {
        cout << "Invalid command, type 'help' to get more informations." << endl;
    }
    return;
}

void locationA(int x, int y)
{

    x = getDimX();
    y = getDimY();
    x1 = x / 2 + 1;
    y1 = y / 2 + 1;

    init(dimX_, dimY_);
}

// tjp
void refresh()
{
    cout << "alien coordiante at refesh: " << x1 << "\t" << y1 << endl;
    cout << "alien coordiante at refesh: " << dimX_ << "\t" << dimY_ << endl;
    char ch1 = 'A';

    setObject(x1, y1, ch1);

    display(dimX_, dimY_);
    cmd();
    pf::pause();
    pf::cls();
    return refresh();
}

int main()
{
    srand(1);
    int defRow = 9, defColumn = 5, defZombie = 1; // default value of row and column.

    resetSetting(defRow, defColumn, defZombie);
    getDimX() = defRow;
    getDimY() = defColumn;
    locationA(defRow, defColumn);
    refresh();

    pf::pause();
}
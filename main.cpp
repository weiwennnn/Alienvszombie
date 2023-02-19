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
#include <iomanip> //setw()
#include <string>
#include <algorithm> //transform() function
#include <cctype> //string to lowercase
#include <vector>
#include <cstdlib> //for rand()
#include <ctime> //for time()
#include <stdio.h> //break
#include <fstream>
#include <limits> //get only number

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
    //kw
    //global values:
    int Attack = 0; //= 0 ;
    int Life = 100; // = 100;
    int zombieX,zombieY; //zombie coordinate 
    
    //zombie attack
    int z1atk = (1 + rand() % 5) * 5; int z2atk = (1 + rand() % 5) * 5; int z3atk = (1 + rand() % 5) * 5;
    int z4atk = (1 + rand() % 5) * 5; int z5atk = (1 + rand() % 5) * 5; int z6atk = (1 + rand() % 5) * 5;
    int z7atk = (1 + rand() % 4) * 5; int z8atk = (1 + rand() % 4) * 5; int z9atk = (1 + rand() % 4) * 5;
    int zombieA[9] = {z1atk,z2atk,z3atk,z4atk,z5atk,z6atk,z7atk,z8atk,z9atk};
    
    //zombie life
    int z1life = (2 + rand() % 5) *50; int z2life = (2 + rand() % 5) *50; int z3life = (2 + rand() % 5) *50; 
    int z4life = (2 + rand() % 5) *50; int z5life = (2 + rand() % 5) *50; int z6life = (2 + rand() % 5) *50; 
    int z7life = (2 + rand() % 5) *50; int z8life = (2 + rand() % 5) *50; int z9life = (2 + rand() % 5) *50;
    int zombieL[9] = {z1life,z2life,z3life,z4life,z5life,z6life,z7life,z8life,z9life};

    //zombie attack range;
    int z1range = rand() % 3 + 1;int z2range = rand() % 3 + 1;int z3range = rand() % 3 + 1;
    int z4range = rand() % 3 + 1;int z5range = rand() % 3 + 1;int z6range = rand() % 3 + 1;
    int z7range = rand() % 3 + 1;int z8range = rand() % 3 + 1;int z9range = rand() % 3 + 1;
    int zrange[9] = {z1range,z2range,z3range,z4range,z5range,z6range,z7range,z8range,z9range};

    int xZ[9]; //x-coordinate of zombies
    int yZ[9]; //y-coordinate zombies

class Game {
private:
    vector<vector<char>> map_;
    int r,c,z; //r = row number, c = column number, z = zombie number
    int dimX_, dimY_;
    int row,column,zombie;
    int row_,column_,zombie_;
    int x1, y1, ch1; // alien coordiante
    int objX, objY;
    string command;
    static constexpr int kDefaultRow = 9;
    static constexpr int kDefaultColumn = 5;
    static constexpr int kDefaultZombie = 1;

public:

void defsetting(int row, int column, int zombie)
{
    char yn;
    pf::cls();

    cout << " Default Game Setting " << endl;
    cout << "----------------------" << endl;
    cout << "Board Rows    : " << "9" << endl;
    cout << "Board Columns : " << "5" << endl;
    cout << "Zombie Count  : " << "1" << endl
         << endl;
    cout << "Do you wish to change the game settings? (y/n) => ";
}

int resetSetting(int &row, int &column, int &zombie) // reset dimension of game board
{
    char decision;
    int num;
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
            row = getOnlyNumber(num);
            cout << "Enter Columns => ";
            column = getOnlyNumber(num);

            cout << endl;
            if (row % 2 != 0 && column % 2 != 0)
            {
                init(row, column);

                do
                {
                    cout << "Zombie Settings" << endl;
                    cout << "---------------" << endl;
                    cout << "Enter number of zombies => ";
                    zombie = getOnlyNumber(num);
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
                        pf::pause();
                        pf::cls();
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
        pf::pause();
        pf::cls();
        break;

    default:
        cout << "Invalid input! Please try again." << endl;
        pf::pause();
        pf::cls();
        if (decision = 'Y' && decision != 'N')
        {
            resetSetting(row, column, zombie);
        }
        break;
    }
    init(row, column);
            r = row;
            c = column;
            z = zombie;
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
void title(int x)
{
    for (int i = 0; i < x / 2; ++i)
    {
        cout << " ";
    }
    cout << ".: Alien vs Zombie :." << endl;
    for (int j = 0; j < x / 2; ++j)
    {
        cout << " ";
    }
    cout << "====================" << endl;
}

const void display(int row_, int col_)
{
    title(row_);

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

int getOnlyNumber(int num) //get only number
{
    num = 0;
    while(!(cin >> num)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input (ONLY number accepted). \nPlease try again>\t ";   
    } 
    return num;
}

void turn()
{
    refresh();
    alienturnend();
    zombieturn();
    
    turn();

}
//kw
//Reset to a random game object (except the Trail) after Alien’s turn ends.
void  alienturnend()
{
    string obj;

    for (int i = 0; i < c; ++i)
    {
        for (int j = 0; j < r; ++j)
        {
            if (i < c && j < r)
            {
                char obj = map_[i][j];

            if (obj == '.')
            {
                char rock[] = {'h', 'p', ' ', ' ', '>', '<', 'v','^'};
                int noOfObjects = sizeof(rock);
                int random = rand() % noOfObjects;
                if (rock[random] == 'h')
                {
                    char inside = 'h';
                    map_[i][j] = inside;
                }
                else if (rock[random] == 'p')
                {
                    char inside = 'p';
                    map_[i][j] = inside;
                }
                else if (rock[random] == ' ')
                {
                    char inside = ' ';
                    map_[i][j] = inside;
                }
                else if (rock[random] == '>')
                {
                    char inside = '>';
                    map_[i][j] = inside;
                }
                else if (rock[random] == '<')
                {
                    char inside = '<';
                    map_[i][j] = inside;
                }
                else if (rock[random] == 'v')
                {
                    char inside = 'v';
                    map_[i][j] = inside;
                }
                else
                {
                    char inside = '^';
                    map_[i][j] = inside;
                }
            }
            else
                map_[i][j] = obj;
            }
        }
    }
    alienTurn(Life,Attack);
    cout << "\nAlien's turn ends." << endl; 
    cout << "The trail is reset." << endl << endl;
    pf::pause();
    pf::cls();
    
return;
}

int alienTurn(int l , int a)
{
    int j=0;
    cout << "-> "; cout << "Alien"; cout.width(12) ; cout << ": Life" << setw(5) << l << ", Attack" << setw(5) << getAttack() << endl;
    for(int i = 1; i <= z; i++)
    {
        srand(time(0));
        
        cout << "   "; cout << "Zombie " << i ; cout.width(9); 
        cout << ": Life" << setw(5) << zombieL[j]<< ", Attack" << setw(5) << zombieA[j] << ", Range" << setw(5) << zrange[j] << endl;
        
        j++;
    }  
    return l,a;
}

void zombieMovement(int movetype, int i)
{
    char zombie[] = {'1','2','3','4','5','6','7','8','9'};
    char empty = ' ';
    switch (movetype)
    {
        case 0: //up
        {
            char checkobj = map_[dimY_ - yZ[i] -1][xZ[i] -1 ];
            if (checkobj == 'A'|| checkobj == '1' || checkobj == '2' || checkobj == '3' || checkobj == '4' || checkobj == '5' || checkobj == '6' || checkobj == '7' || checkobj == '8' || checkobj == '9' )
            {  
                zombieMovement(1, i);
            }
            else{
            yZ[i] = yZ[i] + 1;
                
                if(yZ[i] >c)
                {
                    yZ[i] = yZ[i] - 1;
                    setObject(xZ[i], yZ[i], zombie[i]);
                    break;
                }
                else{
                setObject(xZ[i], yZ[i], zombie[i]);
                setObject(xZ[i], yZ[i]-1, empty);}
            }
        }
        break;
        case 1: //down
        {
            char checkobj = map_[dimY_ - yZ[i] +1][xZ[i] - 1 ];
            if (checkobj == 'A'|| checkobj == '1' || checkobj == '2' || checkobj == '3' || checkobj == '4' || checkobj == '5' || checkobj == '6' || checkobj == '7' || checkobj == '8' || checkobj == '9' )
            {  
                zombieMovement(2, i);
            }
            else{
            yZ[i] = yZ[i] - 1;
            
                if(yZ[i] <= 0)
                {
                    yZ[i] = yZ[i] + 1;
                    setObject(xZ[i], yZ[i], zombie[i]);
                    break;
                }
                else{
                setObject(xZ[i], yZ[i], zombie[i]);
                setObject(xZ[i], yZ[i]+1, empty);}}
        }break;
        case 2: //left
        {
            char checkobj = map_[dimY_ - yZ[i] ][xZ[i] - 1 -1];
            if (checkobj == 'A'|| checkobj == '1' || checkobj == '2' || checkobj == '3' || checkobj == '4' || checkobj == '5' || checkobj == '6' || checkobj == '7' || checkobj == '8' || checkobj == '9' )
            {  
                zombieMovement(3, i);
            }
            else{
            xZ[i] = xZ[i] - 1;
                if(xZ[i] <= 0)
                {
                    xZ[i] = xZ[i] + 1;
                    setObject(xZ[i], yZ[i], zombie[i]);
                    break;
                }
                else{
                setObject(xZ[i], yZ[i], zombie[i]);
                setObject(xZ[i]+1, yZ[i], empty);}}
        }break;
        case 3: //right
        {
            char checkobj = map_[dimY_ - yZ[i] ][xZ[i]- 1 +1];
            if (checkobj == 'A'|| checkobj == '1' || checkobj == '2' || checkobj == '3' || checkobj == '4' || checkobj == '5' || checkobj == '6' || checkobj == '7' || checkobj == '8' || checkobj == '9' )
            {  
                zombieMovement(0, i);
            }
            else{
            xZ[i] = xZ[i] + 1;

                if(xZ[i] > r)
                {
                    xZ[i] = xZ[i] - 1;
                    setObject(xZ[i], yZ[i], zombie[i]);
                    break;
                }
                else{
                setObject(xZ[i], yZ[i], zombie[i]);
                setObject(xZ[i]-1, yZ[i], empty);}}
        }
        break;
    }
}

int findrange(int num1, int num2)
{
    int biggest, smallest,distance;
    if (num1 >= num2)
    {
        biggest = num1;
        smallest = num2;
    }
    else
    {
        biggest = num2;
        smallest = num1;
    }
    distance = biggest - smallest ;
    return distance;
}

void zombieAttack(int zombie)
{
    int range, distanceX, distanceY;
    int a,b;
 
    switch (zombie)
    {
        case 1:
        {
            a = xZ[0]; b = yZ[0];
            findrange(x1, a);
            findrange(y1, b);
            
            if ((findrange(x1, a) <= z1range) && (findrange(y1, b) <= z1range))
            {
                Life = Life - z1atk;
                cout << "Zombie 1 attacks Alien." << endl;
                cout << "Alien receives a damge of "<< z1atk << endl;
                if(Life > 0)
                {
                    cout << "Alien is still alive."<< endl<< endl;
                }
                else
                {
                    playagain("lose");
                }
            }
            else
            {
                Life = Life;
                cout << "Zombie 1 is unable to attack Alien." << endl;
                cout << "Alien is too far." << endl << endl;
            }
        }break;
        case 2:
        {
            a = xZ[1]; b = yZ[1];
            findrange(x1, a);
            findrange(y1, b);

            if ((findrange(x1, a) <= z2range) && (findrange(y1, b) <= z2range))
            {
                Life = Life - z2atk;
                cout << "Zombie 2 attacks Alien." << endl;
                cout << "Alien receives a damge of "<< z2atk << endl;
                if(Life > 0)
                {
                    cout << "Alien is still alive."<< endl<< endl;
                }
                else
                {
                    playagain("lose");
                }
            }
            else
            {
                Life = Life;
                cout << "Zombie 2 is unable to attack Alien." << endl;
                cout << "Alien is too far." << endl << endl;
            }
        }break;
        case 3:
        {
            a = xZ[2]; b = yZ[2];
            findrange(x1, a);
            findrange(y1, b);

            if ((findrange(x1, a) <= z3range) && (findrange(y1, b) <= z3range))
            {
                Life = Life - z3atk;
                cout << "Zombie 3 attacks Alien." << endl;
                cout << "Alien receives a damge of "<< z3atk << endl;
                if(Life > 0)
                {
                    cout << "Alien is still alive."<< endl<< endl;
                }
                else
                {
                    playagain("lose");
                }
            }
            else
            {
                Life = Life;
                cout << "Zombie 3 is unable to attack Alien." << endl;
                cout << "Alien is too far." << endl << endl;
            }
        }break;
        case 4:
        {
            a = xZ[3]; b = yZ[3];
            findrange(x1, a);
            findrange(y1, b);

            if ((findrange(x1, a) <= z4range) && (findrange(y1, b) <= z4range))
            {
                Life = Life - z4atk;
                cout << "Zombie 4 attacks Alien." << endl;
                cout << "Alien receives a damge of "<< z4atk << endl;
                if(Life > 0)
                {
                    cout << "Alien is still alive."<< endl<< endl;
                }
                else
                {
                    playagain("lose");
                }
            }
            else
            {
                Life = Life;
                cout << "Zombie 4 is unable to attack Alien." << endl;
                cout << "Alien is too far." << endl << endl;
            }
        }break;
        case 5:
        {
            a = xZ[4]; b = yZ[4];
            findrange(x1, a);
            findrange(y1, b);

            if ((findrange(x1, a) <= z5range) && (findrange(y1, b) <= z5range))
            {
                Life = Life - z5atk;
                cout << "Zombie 5 attacks Alien." << endl;
                cout << "Alien receives a damge of "<< z5atk << endl;
                if(Life > 0)
                {
                    cout << "Alien is still alive."<< endl<< endl;
                }
                else
                {
                    playagain("lose");
                }
            }
            else
            {
                Life = Life;
                cout << "Zombie 5 is unable to attack Alien." << endl;
                cout << "Alien is too far." << endl << endl;
            }
        }break;
        case 6:
        {
            a = xZ[5]; b = yZ[5];
            findrange(x1, a);
            findrange(y1, b);

            if ((findrange(x1, a) <= z6range) && (findrange(y1, b) <= z6range))
            {
                Life = Life - z6atk;
                cout << "Zombie 6 attacks Alien." << endl;
                cout << "Alien receives a damge of "<< z6atk << endl;
                if(Life > 0)
                {
                    cout << "Alien is still alive."<< endl<< endl;
                }
                else
                {
                    playagain("lose");
                }
            }
            else
            {
                Life = Life;
                cout << "Zombie 6 is unable to attack Alien." << endl;
                cout << "Alien is too far." << endl << endl;
            }
        }break;
        case 7:
        {
            a = xZ[6]; b = yZ[6];
            findrange(x1, a);
            findrange(y1, b);

            if ((findrange(x1, a) <= z7range) && (findrange(y1, b) <= z7range))
            {
                Life = Life - z7atk;
                cout << "Zombie 7 attacks Alien." << endl;
                cout << "Alien receives a damge of "<< z7atk << endl;
                if(Life > 0)
                {
                    cout << "Alien is still alive."<< endl<< endl;
                }
                else
                {
                    playagain("lose");
                }
            }
            else
            {
                Life = Life;
                cout << "Zombie 7 is unable to attack Alien." << endl;
                cout << "Alien is too far." << endl << endl;
            }
        }break;
        case 8:
        {
            a = xZ[7]; b = yZ[7];
            findrange(x1, a);
            findrange(y1, b);

            if ((findrange(x1, a) <= z8range) && (findrange(y1, b) <= z8range))
            {
                Life = Life - z8atk;
                cout << "Zombie 8 attacks Alien." << endl;
                cout << "Alien receives a damge of "<< z8atk << endl;
                if(Life > 0)
                {
                    cout << "Alien is still alive."<< endl<< endl;
                }
                else
                {
                    playagain("lose");
                }
            }
            else
            {
                Life = Life;
                cout << "Zombie 8 is unable to attack Alien." << endl;
                cout << "Alien is too far." << endl << endl;
            }
        }break;
        case 9:
        {
            a = xZ[8]; b = yZ[8];
            findrange(x1, a);
            findrange(y1, b);

            if ((findrange(x1, a) <= z9range) && (findrange(y1, b) <= z9range))
            {
                Life = Life - z9atk;
                cout << "Zombie 9 attacks Alien." << endl;
                cout << "Alien receives a damge of "<< z9atk << endl;
                if(Life > 0)
                {
                    cout << "Alien is still alive."<< endl<< endl;
                }
                else
                {
                    playagain("lose");
                }
            }
            else
            {
                Life = Life;
                cout << "Zombie 9 is unable to attack Alien." << endl;
                cout << "Alien is too far." << endl << endl;
            }
        }break;
    }
}

void zombieTurn(int round)
{
    srand(time(0));
    string zMovement[] = {"up", "down", "left", "right"};
    int moveType = rand() % 4;
    switch (round)
    {
    case 1:
    {
            if (getZ1Life() > 0)
            {
                cout << "   "
                     << "Alien";
                cout.width(12);
                cout << ": Life" << setw(5) << Life << ", "
                     << "Attack" << setw(5) << getAttack() << endl;
                for (int i = 1; i <= z; i++)
                {
                    if (i == 1)
                    {
                cout << "-> ";
                cout << "Zombie " << i;
                cout.width(9);
                cout << ": Life" << setw(5) << zombieL[0] << ", "
                     << "Attack" << setw(5) << zombieA[0] << ", "
                     << "Range" << setw(5) << zrange[0] << endl;
                    }
                    else
                    {
                cout << "   ";
                cout << "Zombie " << i;
                cout.width(9);
                cout << ": Life" << setw(5) << zombieL[i - 1] << ", "
                     << "Attack" << setw(5) << zombieA[i - 1] << ", "
                     << "Range" << setw(5) << zrange[i - 1] << endl;
                    }
                }
                cout << "\nZombie 1 moves " << zMovement[moveType] << "." << endl;
                zombieMovement(moveType, 0);
                zombieAttack(1);
            }
            if (getZ1Life() <= 0)
            {
                cout << "Zombie 1 has been defeated. " << endl;
            }
            cout << "Zombie 1's turn ends." << endl
                 << endl;
    }
    break;

    case 2:
    {
            if (getZ2Life() > 0)
            {
                cout << "   "
                     << "Alien";
                cout.width(12);
                cout << ": Life" << setw(5) << Life << ", "
                     << "Attack" << setw(5) << getAttack() << endl;
                for (int i = 1; i <= z; i++)
                {
                    if (i == 2)
                    {
                cout << "-> ";
                cout << "Zombie " << i;
                cout.width(9);
                cout << ": Life" << setw(5) << zombieL[1] << ", "
                     << "Attack" << setw(5) << zombieA[1] << ", "
                     << "Range" << setw(5) << zrange[1] << endl;
                    }
                    else
                    {
                cout << "   ";
                cout << "Zombie " << i;
                cout.width(9);
                cout << ": Life" << setw(5) << zombieL[i - 1] << ", "
                     << "Attack" << setw(5) << zombieA[i - 1] << ", "
                     << "Range" << setw(5) << zrange[i - 1] << endl;
                    }
                }
                cout << "\nZombie 2 moves " << zMovement[moveType] << "." << endl;
                zombieMovement(moveType, 1);
                zombieAttack(2);
            }
            if (getZ2Life() <= 0)
            {
                cout << "Zombie 2 has been defeated. " << endl;
            }

            cout << "Zombie 2's turn ends." << endl
                 << endl;
    }
    break;

    case 3:
    {
            if (getZ3Life() > 0)
            {
                cout << "   "
                     << "Alien";
                cout.width(12);
                cout << ": Life" << setw(5) << Life << ", "
                     << "Attack" << setw(5) << getAttack() << endl;
                for (int i = 1; i <= z; i++)
                {
                    if (i == 3)
                    {
                cout << "-> ";
                cout << "Zombie " << i;
                cout.width(9);
                cout << ": Life" << setw(5) << zombieL[2] << ", "
                     << "Attack" << setw(5) << zombieA[2] << ", "
                     << "Range" << setw(5) << zrange[2] << endl;
                    }
                    else
                    {
                cout << "   ";
                cout << "Zombie " << i;
                cout.width(9);
                cout << ": Life" << setw(5) << zombieL[i - 1] << ", "
                     << "Attack" << setw(5) << zombieA[i - 1] << ", "
                     << "Range" << setw(5) << zrange[i - 1] << endl;
                    }
                }
                cout << "\nZombie 3 moves " << zMovement[moveType] << "." << endl;
                zombieMovement(moveType, 2);
                zombieAttack(3);
            }

            if (getZ3Life() <= 0)
            {
                cout << "Zombie 3 has been defeated. " << endl;
            }

            cout << "Zombie 3's turn ends." << endl
                 << endl;
    }
    break;
    case 4:
    {
            if (getZ4Life() > 0)
            {
                cout << "   "
                     << "Alien";
                cout.width(12);
                cout << ": Life" << setw(5) << Life << ", "
                     << "Attack" << setw(5) << getAttack() << endl;
                for (int i = 1; i <= z; i++)
                {
                    if (i == 4)
                    {
                cout << "-> ";
                cout << "Zombie " << i;
                cout.width(9);
                cout << ": Life" << setw(5) << zombieL[3] << ", "
                     << "Attack" << setw(5) << zombieA[3] << ", "
                     << "Range" << setw(5) << zrange[3] << endl;
                    }
                    else
                    {
                cout << "   ";
                cout << "Zombie " << i;
                cout.width(9);
                cout << ": Life" << setw(5) << zombieL[i - 1] << ", "
                     << "Attack" << setw(5) << zombieA[i - 1] << ", "
                     << "Range" << setw(5) << zrange[i - 1] << endl;
                    }
                }
                cout << "\nZombie 4 moves " << zMovement[moveType] << "." << endl
                     << endl;
                zombieMovement(moveType, 3);
                zombieAttack(4);
            }
            if (getZ4Life() <= 0)
            {
                cout << "Zombie 4 has been defeated. " << endl;
            }
            cout << "Zombie 4's turn ends." << endl;
    }
    break;
    case 5:
    {
            if (getZ5Life() > 0)
            {
                cout << "   "
                     << "Alien";
                cout.width(12);
                cout << ": Life" << setw(5) << Life << ", "
                     << "Attack" << setw(5) << getAttack() << endl;
                for (int i = 1; i <= z; i++)
                {
                    if (i == 5)
                    {
                cout << "-> ";
                cout << "Zombie " << i;
                cout.width(9);
                cout << ": Life" << setw(5) << zombieL[4] << ", "
                     << "Attack" << setw(5) << zombieA[4] << ", "
                     << "Range" << setw(5) << zrange[4] << endl;
                    }
                    else
                    {
                cout << "   ";
                cout << "Zombie " << i;
                cout.width(9);
                cout << ": Life" << setw(5) << zombieL[i - 1] << ", "
                     << "Attack" << setw(5) << zombieA[i - 1] << ", "
                     << "Range" << setw(5) << zrange[i - 1] << endl;
                    }
                }
                cout << "\nZombie 5 moves " << zMovement[moveType] << "." << endl
                     << endl;
                zombieMovement(moveType, 4);
                zombieAttack(5);
            }
            if (getZ5Life() <= 0)
            {
                cout << "Zombie 5 has been defeated. " << endl;
            }
            cout << "Zombie 5's turn ends." << endl;
    }
    break;
    case 6:
    {
            if (getZ6Life() > 0)
            {
                cout << "   "
                     << "Alien";
                cout.width(12);
                cout << ": Life" << setw(5) << Life << ", "
                     << "Attack" << setw(5) << getAttack() << endl;
                for (int i = 1; i <= z; i++)
                {
                    if (i == 6)
                    {
                cout << "-> ";
                cout << "Zombie " << i;
                cout.width(9);
                cout << ": Life" << setw(5) << zombieL[5] << ", "
                     << "Attack" << setw(5) << zombieA[5] << ", "
                     << "Range" << setw(5) << zrange[5] << endl;
                    }
                    else
                    {
                cout << "   ";
                cout << "Zombie " << i;
                cout.width(9);
                cout << ": Life" << setw(5) << zombieL[i - 1] << ", "
                     << "Attack" << setw(5) << zombieA[i - 1] << ", "
                     << "Range" << setw(5) << zrange[i - 1] << endl;
                    }
                }
                cout << "\nZombie 6 moves " << zMovement[moveType] << "." << endl;
                zombieMovement(moveType, 5);
                zombieAttack(6);
            }
            if (getZ6Life() <= 0)
            {
                cout << "Zombie 6 has been defeated. " << endl;
            }
            cout << "Zombie 6's turn ends." << endl
                 << endl;
    }
    break;
    case 7:
    {
            if (getZ7Life() > 0)
            {
                cout << "   "
                     << "Alien";
                cout.width(12);
                cout << ": Life" << setw(5) << Life << ", "
                     << "Attack" << setw(5) << getAttack() << endl;
                for (int i = 1; i <= z; i++)
                {
                    if (i == 7)
                    {
                cout << "-> ";
                cout << "Zombie " << i;
                cout.width(9);
                cout << ": Life" << setw(5) << zombieL[6] << ", "
                     << "Attack" << setw(5) << zombieA[6] << ", "
                     << "Range" << setw(5) << zrange[6] << endl;
                    }
                    else
                    {
                cout << "   ";
                cout << "Zombie " << i;
                cout.width(9);
                cout << ": Life" << setw(5) << zombieL[i - 1] << ", "
                     << "Attack" << setw(5) << zombieA[i - 1] << ", "
                     << "Range" << setw(5) << zrange[i - 1] << endl;
                    }
                }
                cout << "\nZombie 7 moves " << zMovement[moveType] << "." << endl;
                zombieMovement(moveType, 6);
                zombieAttack(7);
            }
            if (getZ7Life() <= 0)
            {
                cout << "Zombie 7 has been defeated. " << endl;
            }
            cout << "Zombie 7's turn ends." << endl
                 << endl;
    }
    break;
    case 8:
    {
            if (getZ8Life() > 0)
            {
                cout << "   "
                     << "Alien";
                cout.width(12);
                cout << ": Life" << setw(5) << Life << ", "
                     << "Attack" << setw(5) << getAttack() << endl;
                for (int i = 1; i <= z; i++)
                {
                    if (i == 8)
                    {
                cout << "-> ";
                cout << "Zombie " << i;
                cout.width(9);
                cout << ": Life" << setw(5) << zombieL[7] << ", "
                     << "Attack" << setw(5) << zombieA[7] << ", "
                     << "Range" << setw(5) << zrange[7] << endl;
                    }
                    else
                    {
                cout << "   ";
                cout << "Zombie " << i;
                cout.width(9);
                cout << ": Life" << setw(5) << zombieL[i - 1] << ", "
                     << "Attack" << setw(5) << zombieA[i - 1] << ", "
                     << "Range" << setw(5) << zrange[i - 1] << endl;
                    }
                }
                cout << "\nZombie 8 moves " << zMovement[moveType] << "." << endl;
                zombieMovement(moveType, 7);
                zombieAttack(8);
            }
            if (getZ8Life() <= 0)
            {
                cout << "Zombie 8 has been defeated. " << endl;
            }
            cout << "Zombie 8's turn ends." << endl
                 << endl;
    }
    break;
    case 9:
    {
            if (getZ9Life() > 0)
            {
                cout << "   "
                     << "Alien";
                cout.width(12);
                cout << ": Life" << setw(5) << Life << ", "
                     << "Attack" << setw(5) << getAttack() << endl;
                for (int i = 1; i <= z; i++)
                {
                    if (i == 9)
                    {
                cout << "-> ";
                cout << "Zombie " << i;
                cout.width(9);
                cout << ": Life" << setw(5) << zombieL[8] << ", "
                     << "Attack" << setw(5) << zombieA[8] << ", "
                     << "Range" << setw(5) << zrange[8] << endl;
                    }
                    else
                    {
                cout << "   ";
                cout << "Zombie " << i;
                cout.width(9);
                cout << ": Life" << setw(5) << zombieL[i - 1] << ", "
                     << "Attack" << setw(5) << zombieA[i - 1] << ", "
                     << "Range" << setw(5) << zrange[i - 1] << endl;
                    }
                }
                cout << "\nZombie 9 moves " << zMovement[moveType] << "." << endl;
                zombieMovement(moveType, 8);
                zombieAttack(9);
            }
            if (getZ9Life() <= 0)
            {
                cout << "Zombie 9 has been defeated. " << endl;
            }
            cout << "Zombie 9's turn ends." << endl
                 << endl;
    }
    break;
    }
}

void dashboard(int &l, int a)
{
    char round;
    do
    {
        alienTurn(l, a);
        cmd();
        pf::pause();
        pf::cls();
        display(dimX_, dimY_);
        alienturnend();

        for (int i = 1; i <= z; i++)
        {
            display(dimX_,dimY_);
            round = i;
            zombieTurn(i);

            pf::pause();
            pf::cls();
        }
        display(dimX_,dimY_);
        getAttack() = 0;
    }while(true);
}
int &getAttack()
{
    return Attack;
}
int &getLife()
{
    return Life;
}
int &getZ1Life()
{
    return z1life, zombieL[0];
}
int &getZ2Life()
{
    return z2life, zombieL[1];
}
int &getZ3Life()
{
    return z3life, zombieL[2];
}
int &getZ4Life()
{
    return z4life, zombieL[3];
}
int &getZ5Life()
{
    return z5life, zombieL[4];
}
int &getZ6Life()
{
    return z6life, zombieL[5];
}
int &getZ7Life()
{
    return z7life, zombieL[6];
}
int &getZ8Life()
{
    return z8life, zombieL[7];
}
int &getZ9Life()
{
    return z9life, zombieL[8];
}

void zombieturn(){
    cout << "zombie turn end" << endl;
    return;
}

const char getobject(int x1,int y1, int objX, int objY)
{
    return map_[dimY_ - y1][x1 - 1];

}

void help(const std::string& command) const 
{
    std::cout << std::setw(9) << std::left << "1. up" << std::setw(21) << std::left << "- Move up." << std::endl;
    std::cout << std::setw(9) << std::left << "2. down" << std::setw(21) << std::left << "- Move down." << std::endl;
    std::cout << std::setw(9) << std::left << "3. left" << std::setw(21) << std::left << "- Move left." << std::endl;
    std::cout << std::setw(9) << std::left << "4. right" << std::setw(21) << std::left << "- Move right." << std::endl;
    std::cout << std::setw(9) << std::left << "5. arrow" << std::setw(21) << std::left << "- Change the direction of an arrow." << std::endl;
    std::cout << std::setw(9) << std::left << "6. save" << std::setw(21) << std::left << "- Save this Game." << std::endl;
    std::cout << std::setw(9) << std::left << "7. load" << std::setw(21) << std::left << "- Load a Game." << std::endl;
    std::cout << std::setw(9) << std::left << "8. quit" << std::setw(21) << std::left << "- Quit this Game." << std::endl;
    std::cout << std::setw(9) << std::left << "9. help" << std::setw(21) << std::left << "- Display these users' commands. " << std::endl;
}

void up(const string &command, int column, int row)
{
    y1 = y1 + 1;

    if(y1 > c)
    {
    	y1 = y1 - 1;
        cout << "Alien hits the border" << x1 << "," << y1 << endl;
    	return;
    }
    else
    {
        //testing
    	// cout << "Next coordinate: " << x1 << "," << y1 << endl;
        objX = 0;
        objY = -1;
        obj_game();
    }
    return;
    pf::pause();
}

void down(const string &command, int column, int row)
{
    y1 = y1 - 1;

    if(y1 <= 0)
    {
    	y1 = y1 + 2;
        cout << "Alien hits the border" << x1 << "," << y1-1 << endl;
        down(command, column, row);
    }

    else
    {
    	cout << "Next coordinate: " << x1 << "," << y1 << endl;
        objX = 0;
        objY = 1;
        obj_game();
    }

    return;
    pf::pause();;
}

void left(const string &command, int column, int row)
{
    x1 = x1 - 1;

    if(x1 <= 0)
    {
    	x1 = x1 + 2;
        cout << "Alien hits the border" << x1 << "," << x1-1 << endl;
        left(command, column, row);
    }

    else
    {
    	cout << "Next coordinate: " << x1 << "," << y1 << endl;
        objX = 1;
        objY = 0;
        obj_game();
    }

    return;
}

void right(const string &command, int column, int row)
{
    x1 = x1 + 1;

    if(x1 > r)
    {
    	x1 = x1 - 1;
        cout << "Alien hits the border" << x1 << "," << y1 << endl;
    	return;
    }
    else
    {
    	cout << "Next coordinate: " << x1 << "," << y1 << endl;
        objX = -1;
        objY = 0;
        obj_game();
    }
    return;
    pf::pause();
}

void arrow(const string &command)
{
    char arrowchanged;
    char obj;

    int num;
    cout << "\nArrow x-coordinate => " ;
    int arrowX =  getOnlyNumber(num);
   
    if (arrowX >0 && arrowX <= r) 
    {
    cout << "Arrow y-coordinate => ";
    int arrowY =  getOnlyNumber(num);
        if (arrowY >0 && arrowY <= c) {
        
        obj = getobject(arrowX, arrowY, objX,objY);
        cout << "Arrow chosen => " << obj << endl;
            if (obj == '^' || obj == 'v'  || obj == '<' || obj == '>'){
                cout << "Change arrow => ";
                cin >> arrowchanged;
                cout<<endl;
                    if (arrowchanged == '^' || arrowchanged == 'v' || arrowchanged == '<' ||arrowchanged == '>'){
                        pf::cls();
                        setObject(arrowX, arrowY, arrowchanged);
                        display(dimX_, dimY_);
                        alienTurn(Life, Attack);
                        cout << "\nThe changes have been made.\t";

                    }
                    else
                        cout << "Please type the correct arrow (^, v, <, >)";
                        //c
                        return;
            }
        }
    }
}


void save(const string &command)
{

    string filename;
    fstream out;
    cout<< "Please enter file name (xxx.txt): ";
    cin >> filename;
    out.open(filename, fstream::out);
    out << c <<" "<< r <<" "<< z << " "
    << z1atk << " " << z2atk << " " << z3atk << " " << z4atk << " " << z5atk << " " << z6atk << " " << z7atk << " " << z8atk << " " << z9atk << " "
    << z1life << " " << z2life << " " << z3life << " " << z4life << " " << z5life << " " << z6life << " " << z7life << " " << z8life << " " << z9life << " "
    << z1range << " " << z2range << " " << z3range << " " << z4range << " " << z5range << " " << z6range << " " << z7range << " " << z8range << " " << z9range << " "
    << endl;
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            out << map_[i][j] << " ";
        }
        out << endl;
    }
    out.close();

}

void load(const string &command)
{
    int size;
    vector<vector<char>> field;
    string filename;
    fstream in;
    fstream out;
    char saved;
    int column_,row_;

    //save current game
    cout<<"Do you want to save the current game? (y/n): ";
    cin >> saved;
    saved = toupper (saved);
    switch (saved)
    {
    case 'Y':
    //save codes from void save()
    cout<< "Please enter file name (xxx.txt): ";
    cin >> filename;
    out.open(filename, fstream::out);
    out << c <<" "<< r <<" "<< z << " "
    << z1atk << " " << z2atk << " " << z3atk << " " << z4atk << " " << z5atk << " " << z6atk << " " << z7atk << " " << z8atk << " " << z9atk << " "
    << z1life << " " << z2life << " " << z3life << " " << z4life << " " << z5life << " " << z6life << " " << z7life << " " << z8life << " " << z9life << " "
    << z1range << " " << z2range << " " << z3range << " " << z4range << " " << z5range << " " << z6range << " " << z7range << " " << z8range << " " << z9range << " "
    << endl;
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            out << map_[i][j] << " ";
        }
        out << endl;
    }
    out.close();

        //load
        cout<< "please enter file name you want to load (xxx.txt): ";
        cin >> filename;

        in.open(filename);
        in >> column_ >> row_ >> z
        >> z1atk >> z2atk >> z3atk >> z4atk >> z5atk >> z6atk >> z7atk >> z8atk >> z9atk
        >> z1life >> z2life >> z3life >> z4life >> z5life >> z6life >> z7life >> z8life >> z9life
        >> z1range >> z2range >> z3range >> z4range >> z5range >> z6range >> z7range >> z8range >> z9range;
        in.get(); 
        cout <<"in get()>\t"<< in.get();
        cout <<"all int get>\t"<< c <<" "<< r <<" "<< z << " "
        << z1atk << " " << z2atk << " " << z3atk << " " << z4atk << " " << z5atk << " " << z6atk << " " << z7atk << " " << z8atk << " " << z9atk << " "
        << z1life << " " << z2life << " " << z3life << " " << z4life << " " << z5life << " " << z6life << " " << z7life << " " << z8life << " " << z9life << " "
        << z1range << " " << z2range << " " << z3range << " " << z4range << " " << z5range << " " << z6range << " " << z7range << " " << z8range << " " << z9range << " "
        << endl;
        pf::cls();
         r = row_;
         c = column_ ;
         row = row_;
         column = column_;
         dimX_ = row_;
         dimY_ = column_;

        init(row,column);
        locationZ(row,column,z);
        
        
        for (int i = 0; i < column; i++) {
            for (int j = 0; j < row; j++) {

                in.get(map_[i][j]);
                in.get();
            }
            in.get();

        }

        //refresh alien position
        for (int i = 0; i < c; ++i)
        {
            for (int j = 0; j < r; ++j)
            {
                if (i < c && j < r)
                {
                    char obj = map_[i][j];

                    if (obj == 'A')
                    {
                        x1 = j+1;
                        y1 = c-i;
                        map_[i][j] = obj;
                    }

                    if (obj == '1')
                    {
                        xZ[0] = j+1;
                        yZ[0] = c-i;
                        map_[i][j] = obj;
                    }
                
                    if (obj == '2')
                    {
                        xZ[1] = j+1;
                        yZ[1] = c-i;
                        map_[i][j] = obj;
                    }

                    if (obj == '3')
                    {
                        xZ[2] = j+1;
                        yZ[2] = c-i;
                        map_[i][j] = obj;
                    }

                    if (obj == '4')
                    {
                        xZ[3] = j+1;
                        yZ[3] = c-i;
                        map_[i][j] = obj;
                    }
                
                    if (obj == '5')
                    {
                        xZ[4] = j+1;
                        yZ[4] = c-i;
                        map_[i][j] = obj;
                    }

                    if (obj == '6')
                    {
                        xZ[5] = j+1;
                        yZ[5] = c-i;
                        map_[i][j] = obj;
                    }
            
                    if (obj == '7')
                    {
                        xZ[6] = j+1;
                        yZ[6] = c-i;
                        map_[i][j] = obj;
                    }
                
                    if (obj == '8')
                    {
                        xZ[7] = j+1;
                        yZ[7] = c-i;
                        map_[i][j] = obj;
                    }

                    if (obj == '9')
                    {
                        xZ[8] = j+1;
                        yZ[8] = c-i;
                        map_[i][j] = obj;
                    }
                else
                        map_[i][j] = obj;
                }

            }
        }

        cout<<"Game loaded:"<<filename<<endl;
        in.close();
        // display(row,column);
        break;

    case 'N':

        cout<< "please enter file name you want to load (xxx.txt): ";
        cin >> filename;

        fstream in;
    
        //load
        in.open(filename);
        in >> column_ >> row_ >> z
        >> z1atk >> z2atk >> z3atk >> z4atk >> z5atk >> z6atk >> z7atk >> z8atk >> z9atk
        >> z1life >> z2life >> z3life >> z4life >> z5life >> z6life >> z7life >> z8life >> z9life
        >> z1range >> z2range >> z3range >> z4range >> z5range >> z6range >> z7range >> z8range >> z9range
        ;
        
        in.get();        
        cout <<"in get()>\t"<< in.get();
        cout <<"all int get>\t"<< c <<" "<< r <<" "<< z << " "
        << z1atk << " " << z2atk << " " << z3atk << " " << z4atk << " " << z5atk << " " << z6atk << " " << z7atk << " " << z8atk << " " << z9atk << " "
        << z1life << " " << z2life << " " << z3life << " " << z4life << " " << z5life << " " << z6life << " " << z7life << " " << z8life << " " << z9life << " "
        << z1range << " " << z2range << " " << z3range << " " << z4range << " " << z5range << " " << z6range << " " << z7range << " " << z8range << " " << z9range << " "
        << endl;
        pf::cls();
        //refresh values
         r = row_;
         c = column_ ;
         row = row_;
         column = column_;
         dimX_ = row_;
         dimY_ = column_;

        init(row,column);
        locationZ(row,column,z);
        
        
        for (int i = 0; i < column; i++) {
            for (int j = 0; j < row; j++) {

                in.get(map_[i][j]);
                in.get();
            }
            in.get();

        }

        //refresh alien position
        for (int i = 0; i < c; ++i)
        {
            for (int j = 0; j < r; ++j)
            {
                if (i < c && j < r)
                {
                    char obj = map_[i][j];

                    if (obj == 'A')
                    {
                        x1 = j+1;
                        y1 = c-i;
                        map_[i][j] = obj;
                    }

                    if (obj == '1')
                    {
                        xZ[0] = j+1;
                        yZ[0] = c-i;
                        map_[i][j] = obj;
                    }
                
                    if (obj == '2')
                    {
                        xZ[1] = j+1;
                        yZ[1] = c-i;
                        map_[i][j] = obj;
                    }

                    if (obj == '3')
                    {
                        xZ[2] = j+1;
                        yZ[2] = c-i;
                        map_[i][j] = obj;
                    }

                    if (obj == '4')
                    {
                        xZ[3] = j+1;
                        yZ[3] = c-i;
                        map_[i][j] = obj;
                    }
                
                    if (obj == '5')
                    {
                        xZ[4] = j+1;
                        yZ[4] = c-i;
                        map_[i][j] = obj;
                    }

                    if (obj == '6')
                    {
                        xZ[5] = j+1;
                        yZ[5] = c-i;
                        map_[i][j] = obj;
                    }
            
                    if (obj == '7')
                    {
                        xZ[6] = j+1;
                        yZ[6] = c-i;
                        map_[i][j] = obj;
                    }
                
                    if (obj == '8')
                    {
                        xZ[7] = j+1;
                        yZ[7] = c-i;
                        map_[i][j] = obj;
                    }

                    if (obj == '9')
                    {
                        xZ[8] = j+1;
                        yZ[8] = c-i;
                        map_[i][j] = obj;
                    }
                else
                        map_[i][j] = obj;
                }

            }
        }

        cout<<"Game loaded:"<<filename<<endl;
        in.close();
        // display(row,column);
        break;
    }
    


}

void quit(const string &command)
{
    char end;
    cout << "Are You Sure To Quit the game?(y/n): ";
    cin >> end;
    end = toupper(end);
    switch (end)
    {
    case 'Y':
        cout << "Good bye!";
        exit(0);
        break;
    case 'N':
        cout << "Resume the game." << endl;
    }
}

//kw
void obj_game() // detect the game obj
{
    char obj;
    char dot = '.';
    char ch1 = 'A';
    obj = getobject(x1, y1, objX,objY); 

    if (obj != 'r')
    {
        if (obj == 'p')
        {
            cout << "\nAlien finds a pod." << endl;

        int distance_[z];
        float distance; char obj;

        for (int i = 0; i< z; ++i)
        {
            distance = ( (x1-xZ[i]) * (x1-xZ[i]) ) + ( (y1-yZ[i]) * (y1-yZ[i]) ); //sqrt(((x1-x)*(x1-x)) + ((y1-y)*(y1-y)))
            distance_[i] = distance;
        }
        int temp = distance_[0];
        for (int j=0 ; j<z ; j++)
        {
            if (temp > distance_[j])
            {
                temp = distance_[j];
            }
        }
        for (int k = 0; k< z; ++k)
        {
            if ( ((x1-xZ[k]) * (x1-xZ[k])) + ((y1-yZ[k]) * (y1-yZ[k])) == temp)
            {
                obj = getobject (xZ[k], yZ[k], objX, objY);
                if (obj == '1')
                {
                    z1life = z1life - 10;
                    getZ1Life() = z1life;
                    cout << "Zombie 1 receives a damge of 10. "<< endl;
                    if (z1life > 0)
                    {
                        cout << "Zombie is still alive." << endl << endl;
                    }
                    else
                    {
                        cout << "Zombie 1 is defeated." << endl << endl;
                    }
                }
                if (obj == '2')
                {
                    z2life = z2life - 10;
                    getZ2Life() = z2life;
                    cout << "Zombie 2 receives a damge of 10. "<< endl;
                    if (z2life > 0)
                    {
                        cout << "Zombie is still alive." << endl << endl;
                    }
                    else
                    {
                        cout << "Zombie 2 is defeated." << endl << endl;
                    }
                }
                if (obj == '3')
                {
                    z3life = z3life - 10;
                    getZ3Life() = z3life;
                    cout << "Zombie 2 receives a damge of 10. "<< endl;
                    if (z3life > 0)
                    {
                        cout << "Zombie is still alive." << endl << endl;
                    }
                    else
                    {
                        cout << "Zombie 3 is defeated." << endl << endl;
                    }
                }
                if (obj == '4')
                {
                    z4life = z4life - 10;
                    getZ4Life() = z4life;
                    cout << "Zombie 4 receives a damge of 10. "<< endl;
                    if (z4life > 0)
                    {
                        cout << "Zombie is still alive." << endl << endl;
                    }
                    else
                    {
                        cout << "Zombie 4 is defeated." << endl << endl;
                    }
                }
                if (obj == '5')
                {
                    z5life = z5life - 10;
                    getZ5Life() = z5life;
                    cout << "Zombie 5 receives a damge of 10. "<< endl;
                    if (z5life > 0)
                    {
                        cout << "Zombie is still alive." << endl << endl;
                    }
                    else
                    {
                        cout << "Zombie 5 is defeated." << endl << endl;
                    }
                }
                if (obj == '6')
                {
                    z6life = z6life - 10;
                    getZ6Life() = z6life;
                    cout << "Zombie 6 receives a damge of 10. "<< endl;
                    if (z6life > 0)
                    {
                        cout << "Zombie is still alive." << endl << endl;
                    }
                    else
                    {
                        cout << "Zombie 6 is defeated." << endl << endl;
                    }
                }
                if (obj == '7')
                {
                    z7life = z7life - 10;
                    getZ7Life() = z7life;
                    cout << "Zombie 7 receives a damge of 10. "<< endl;
                    if (z7life > 0)
                    {
                        cout << "Zombie is still alive." << endl << endl;
                    }
                    else
                    {
                        cout << "Zombie 7 is defeated." << endl << endl;
                    }
                }
                if (obj == '8')
                {
                    z8life = z8life - 10;
                    getZ8Life() = z8life;
                    cout << "Zombie 8 receives a damge of 10. "<< endl;
                    if (z8life > 0)
                    {
                        cout << "Zombie is still alive." << endl << endl;
                    }
                    else
                    {
                        cout << "Zombie 8 is defeated." << endl << endl;
                    }
                }
                if (obj == '9')
                {
                    z9life = z9life - 10;
                    getZ9Life() = z9life;
                    cout << "Zombie 9 receives a damge of 10. "<< endl;
                    if (z9life > 0)
                    {
                        cout << "Zombie is still alive." << endl << endl;
                    }
                    else
                    {
                        cout << "Zombie 9 is defeated." << endl << endl;
                    }
                }
            }
        }
            setObject(x1+objX,y1+objY,dot);
            setObject(x1, y1, ch1);
        }



        if (obj == 'h')
        {
            Life = Life + 20;
            if (Life > 100)
            {
                Life = 100;
            }
            cout << "Alien finds a health pack." << endl;
            cout << "Alien's life is increased by 20." << endl;

            setObject(x1+objX,y1+objY,dot);
            setObject(x1, y1, ch1);

        }
        if (obj == ' ')
        {
            cout << "\nAlien discovers nothing." << endl << endl;
            setObject(x1+objX,y1+objY,dot);
            setObject(x1, y1, ch1);

        }
        if (obj == '^')
        {
            Attack = Attack + 20;
            getAttack() = Attack;
            cout << "\nAlien discovers an UP arrow." << endl;
            cout << "Alien's attack is increased by 20." << endl << endl;
           while (obj != 'r' && obj != '1' && obj != '2' && obj != '3' && obj != '4' && obj != '5' && obj != '6' && obj != '7' && obj != '8' && obj != '9')
            {  
                if (y1 < c)
                {
                setObject(x1+objX,y1+objY,dot);
                setObject(x1, y1, ch1);
                pf::pause();  
                pf::cls();
                display(dimX_, dimY_);
                alienTurn(Life, Attack);

                char checkobj = map_[dimY_ - y1 -1][x1 -1 ];
                if (checkobj == '^' || checkobj == 'v'  || checkobj == '<' || checkobj == '>' ||checkobj == 'r'|| checkobj == '1' || checkobj == '2' || checkobj == '3' || checkobj == '4' || checkobj == '5' || checkobj == '6' || checkobj == '7' || checkobj == '8' || checkobj == '9' )
                {  
                    up(command, x1, y1);
                    break;
                    
                }

            else
                up(command, x1, y1);
                }

                else if (y1 >= c )
                {
                setObject(x1+objX,y1+objY,dot);
                setObject(x1, y1, ch1);
                break;}
            }

        }

        
        if (obj == 'v')
        {
            Attack = Attack+20;
            getAttack() = Attack;
            cout << "\nAlien discovers a DOWN arrow." << endl;
            cout << "Alien's attack is increased by 20." << endl << endl;
        
           while (obj != 'r' && obj != '1' && obj != '2' && obj != '3' && obj != '4' && obj != '5' && obj != '6' && obj != '7' && obj != '8' && obj != '9')
            {  
                if (y1 >1)
                {
                setObject(x1+objX,y1+objY,dot);
                setObject(x1, y1, ch1);
                pf::pause();  
                pf::cls();
                display(dimX_, dimY_);
                alienTurn(Life, Attack);
                
                char checkobj = map_[dimY_ - y1 +1][x1 - 1 ];
                if (checkobj == '^' || checkobj == 'v'  || checkobj == '<' || checkobj == '>' ||checkobj == 'r'|| checkobj == '1' || checkobj == '2' || checkobj == '3' || checkobj == '4' || checkobj == '5' || checkobj == '6' || checkobj == '7' || checkobj == '8' || checkobj == '9' )
                {
                down(command, x1, y1);

                    break;
                    
                }

                else
                down(command, x1, y1);
                }

                else if (y1 <=1 )
                {           
                setObject(x1+objX,y1+objY,dot);
                setObject(x1, y1, ch1);
                break;
                }
            }
        }

        if (obj == '<')
        {
            Attack = Attack+20;
            getAttack() = Attack;
            cout << "\nAlien discovers a LEFT arrow." << endl;
            cout << "Alien's attack is increased by 20." << endl << endl;
            
            while (obj != 'r' && obj != '1' && obj != '2' && obj != '3' && obj != '4' && obj != '5' && obj != '6' && obj != '7' && obj != '8' && obj != '9')
            {  
                if (x1 >1)
                {
                setObject(x1+objX,y1+objY,dot);
                setObject(x1, y1, ch1);
                pf::pause();  
                pf::cls();
                display(dimX_, dimY_);
                alienTurn(Life, Attack);
                
                char checkobj = map_[dimY_ - y1 ][x1 - 1 -1];
                if (checkobj == '^' || checkobj == 'v'  || checkobj == '<' || checkobj == '>' ||checkobj == 'r'|| checkobj == '1' || checkobj == '2' || checkobj == '3' || checkobj == '4' || checkobj == '5' || checkobj == '6' || checkobj == '7' || checkobj == '8' || checkobj == '9')
                {
                    left(command, x1, y1);
                    break;
                }
                else
                left(command, x1, y1);
                }

                else if (x1 <=1 )
                {           
                setObject(x1+objX,y1+objY,dot);
                setObject(x1, y1, ch1);
                break;
                }
            }
        }

        if (obj == '>')
        {
            Attack = Attack + 20;
            getAttack() = Attack;
            cout << "\nAlien discovers a RIGHT arrow." << endl;
            cout << "Alien's attack is increased by 20." << endl << endl;
            while (obj != 'r' && obj != '1' && obj != '2' && obj != '3' && obj != '4' && obj != '5' && obj != '6' && obj != '7' && obj != '8' && obj != '9')
            {  
                if (x1 < r)
                {           
                    setObject(x1+objX,y1+objY,dot);
                    setObject(x1, y1, ch1);
                    pf::pause();  
                    pf::cls();
                    display(dimX_, dimY_);
                    alienTurn(Life, Attack);

                    char checkobj = map_[dimY_ - y1 ][x1 - 1 +1];
                    if (checkobj == '^' || checkobj == 'v'  || checkobj == '<' || checkobj == '>' ||checkobj == 'r'|| checkobj == '1' || checkobj == '2' || checkobj == '3' || checkobj == '4' || checkobj == '5' || checkobj == '6' || checkobj == '7' || checkobj == '8' || checkobj == '9')
                    {   
                        right(command, x1, y1);
                        break;
                    }
                    else if (obj == '.')
                    {
                        cout << "\nAlien discovers nothing." << endl << endl;
                        //cout << "Alien's Life: " << Life << endl;
                        //cout << "Alien's Attack: " << Attack << endl;
                        setObject(x1+objX,y1+objY,dot);
                        setObject(x1, y1, ch1);
                    }
                    else
                    right(command, x1, y1);
                }
                if (x1 >= r )
                {
                    setObject(x1+objX,y1+objY,dot);
                    setObject(x1, y1, ch1);
                    break;
                }
            }
        }
        
        if (obj == '.')
        {
        cout << "\nAlien discovers nothing." << endl;
        setObject(x1+objX,y1+objY,dot);
        setObject(x1, y1, ch1);
        }
//this 
        if (obj == '1')
        {
            z1life = z1life - getAttack();
            getZ1Life() = z1life;
            cout << "Alien attacks Zombie 1." << endl;
            cout << "Zombie 1 receives a damage of " << getAttack() << "." << endl;
            if (getZ1Life() <= 0)
            {
                cout << "Zombie 1 is defeated." << endl<< endl;;
            }
            else
            {
                cout << "Zombie 1 is still alive." << endl << endl;
            return;
            }
        x1 = x1+objX;
        y1 = y1+objY;
        return;
        }

        if (obj == '2')
        {
            z2life = z2life - getAttack();
            getZ2Life() = z2life;
            cout << "Alien attacks Zombie 2." << endl;
            cout << "Zombie 2 receives a damage of " << getAttack() << "."  << endl;
            if (getZ2Life() <= 0)
            {
                cout << "Zombie 2 is defeated." << endl<< endl;;
            }
            else
            {
                cout << "Zombie 2 is still alive." << endl << endl;
            }
        x1 = x1+objX;
        y1 = y1+objY;
        }
        if (obj == '3')
        {
            z3life = z3life - getAttack();
            getZ3Life() = z3life;
            cout << "Alien attacks Zombie 3." << endl;
            cout << "Zombie 3 receives a damage." << endl;
            if (getZ3Life() <= 0)
            {
                cout << "Zombie 3 is defeated." << endl<< endl;;
            }
            else
            {
                cout << "Zombie 3 is still alive." << endl << endl;
            }
        x1 = x1+objX;
        y1 = y1+objY;
        }
        if (obj == '4')
        {
            z4life = z4life - getAttack();
            getZ4Life() = z4life;
            cout << "Alien attacks Zombie 4." << endl;
            cout << "Zombie 4 receives a damage of " << getAttack() << "."  << endl;
            if (getZ4Life() <= 0)
            {
                cout << "Zombie 4 is defeated." << endl<< endl;;
            }
            else
            {
                cout << "Zombie 4 is still alive." << endl << endl;
            }
        x1 = x1+objX;
        y1 = y1+objY;
        }
        if (obj == '5')
        {
            z5life = z5life - getAttack();
            getZ5Life() = z5life;
            cout << "Alien attacks Zombie 5." << endl;
            cout << "Zombie 5 receives a damage of " << getAttack() << "."  << endl;
            if (getZ2Life() <= 0)
            {
                cout << "Zombie 5 is defeated." << endl<< endl;;
            }
            else
            {
                cout << "Zombie 5 is still alive." << endl << endl;
            }
        x1 = x1+objX;
        y1 = y1+objY;
        }
        if (obj == '6')
        {
            z6life = z6life - getAttack();
            getZ6Life() = z6life;
            cout << "Alien attacks Zombie 6." << endl;
            cout << "Zombie 6 receives a damage of " << getAttack() << "."  << endl;
            if (getZ6Life() <= 0)
            {
                cout << "Zombie 6 is defeated." << endl<< endl;;
            }
            else
            {
                cout << "Zombie 6 is still alive." << endl << endl;
            }
        x1 = x1+objX;
        y1 = y1+objY;
        }
        if (obj == '7')
        {
            z7life = z7life - getAttack();
            getZ7Life() = z7life;
            cout << "Alien attacks Zombie 7." << endl;
            cout << "Zombie 7 receives a damage of " << getAttack() << "."  << endl;
            if (getZ7Life() <= 0)
            {
                cout << "Zombie 7 is defeated." << endl<< endl;;
            }
            else
            {
                cout << "Zombie 7 is still alive." << endl << endl;
            }
        x1 = x1+objX;
        y1 = y1+objY;
        }
        if (obj == '8')
        {
            z8life = z8life - getAttack();
            getZ8Life() = z8life;
            cout << "Alien attacks Zombie 8." << endl;
            cout << "Zombie 8 receives a damage of " << getAttack() << "."  << endl;
            if (getZ8Life() <= 0)
            {
                cout << "Zombie 8 is defeated." << endl<< endl;;
            }
            else
            {
                cout << "Zombie 8 is still alive." << endl << endl;
            }
        x1 = x1+objX;
        y1 = y1+objY;
        }
        if (obj == '9')
        {
            z9life = z9life - getAttack();
            getZ9Life() = z9life;
            cout << "Alien attacks Zombie 9." << endl;
            cout << "Zombie 9 receives a damage of " << getAttack() << "."  << endl;
            if (getZ9Life() <= 0)
            {
                cout << "Zombie 9 is defeated." << endl<< endl;;
            }
            else
            {
                cout << "Zombie 9 is still alive." << endl << endl;
            }
        x1 = x1+objX;
        y1 = y1+objY;
        }

     return;
    }

    if (obj == 'r')
        {
            char rock[] = {'h', 'p', ' ', '>', '<', 'v','^'};
            int noOfObjects = sizeof(rock);
            int random = rand() % noOfObjects;
            cout << "Alien stumbles upon a rock." << endl;
            cout << "Alien discovers " << rock[random] << " beneath a rock." << endl;
            
            if (rock[random] == 'h')
            {
                setObject(x1,y1,'h');
            }
            else if (rock[random] == 'p')
            {
                setObject(x1,y1,'p');
            }
            else if (rock[random] == ' ')
            {
                setObject(x1,y1,' ');
            }
            else if (rock[random] == '>')
            {
                setObject(x1,y1,'>');
            }
            else if (rock[random] == '^')
            {
                setObject(x1,y1,'^');
            }
            else if (rock[random] == 'v')
            {
                setObject(x1,y1,'v');
            }
            else{
                setObject(x1,y1,'<');
            }
        x1 = x1+objX;
        y1 = y1+objY;
        return ;
        }
}

// cmd main body
void cmd()
{
    // command[0] = '\0';
    command.clear();
    cout << "\ncommand >";
    cin >> command;
    transform(command.begin(), command.end(), command.begin(), ::tolower);

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
        down(command, dimX_, dimY_);
    }

    else if (command == "left")
    {
        left(command, dimX_, dimY_);
    }

    else if (command == "right")
    {
        right(command, dimX_, dimY_);
    }

    else if (command == "arrow")
    {
        arrow(command);
        cmd();
    }

    else if (command == "save")
    {
        save(command );
        refresh();
    }

    else if (command == "load")
    {
        load(command);
        pf::cls();
        display(row,column);
        refresh();
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

    init(x, y);
    x1 = getDimX() / 2 + 1;
    y1 = getDimY() / 2 + 1;
    ch1 = 'A';
    setObject(x1, y1, ch1);
    //kw
    // display(x, y);
    // healthandlife();
}

//kw
//zombie loaction
bool isRepeated(int arrX[], int arrY[], const int zombie, int elementX, int elementY) //check repeated coordinate
{

    for (int i = 0; i < zombie; i++)
    {
        if ((arrX[i] == elementX) && (arrY[i] == elementY))
        {
        }
    }
    return false;
}

void locationZ(int x, int y, int zombie) // location zombie
{
    int zombieX, zombieY;
    int i;
    const int size = 9;
    char zombies[size] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int Xzombie[zombie];
    int Yzombie[zombie];
    do
    {
        for (int i = 0; i < zombie; i++)
        {
            do
            {
                zombieX = 1 + rand() % getDimX();
                Xzombie[i] = zombieX;
                zombieY = 1 + rand() % getDimY();
                Yzombie[i] = zombieY;
            } while (isRepeated(Xzombie, Yzombie, i, Xzombie[i], Yzombie[i]));

            char obj;
            obj = getobject(zombieX, zombieY, objX, objY);
            if (obj == '1' || obj == '2' || obj == '3' || obj == '4' || obj == '5' || obj == '6' || obj == '7' || obj == '8' || obj == '9' || obj == 'A')
            {
                zombieX = 1 + rand() % getDimX();
                Xzombie[i] = zombieX;
                zombieY = 1 + rand() % getDimY();
                Yzombie[i] = zombieY;
            }
            
            xZ[i] = zombieX; yZ[i] = zombieY;

            setObject(zombieX, zombieY, zombies[i]);

        }
    } while ((zombieX == getDimX() / 2 + 1) && (zombieY == getDimY() / 2 + 1));
    
return;
}

void location_A_Z(int x, int y, int numOfzom)
{
    srand(time(0));
    locationA(x, y);
    locationZ(x, y, numOfzom);
    //locationz display moved here kw
    display(x, y);
}

//till here kw

void refresh()
{
    cout << "Alien's location is at: " << x1 << "," << y1 << endl;
    cmd(); 
    pf::pause();
    pf::cls();
    display(dimX_, dimY_);
    return;
}

  void Run() 
    {
        srand(1);
        int defRow = 9, defColumn = 5, defZombie = 1; // default value of row and column.

        //kw
        resetSetting(defRow, defColumn, defZombie);
        getDimX() = defRow; // dimX and dimY = delRow and defColumn
        getDimY() = defColumn;
        location_A_Z(defRow, defColumn, defZombie);
        dashboard(Life,Attack);
            pf::pause();
    }    
void playagain(string winlose)
{
    char yn;
    if ( winlose == "win")
    {
        cout << "Alien wins." << endl;
    }
    if (winlose == "lose")
    {
        cout << "Alien loses." << endl;
    }

    cout << "Play again? (y/n) => ";
    cin >> yn;
    yn = toupper(yn);

    switch (yn)
    {
        case 'Y':
        {
            Run();
        } break;
        case 'N':
        {
            cout << "\nGood bye!" << endl;
            exit(0);
        }break;
        default:
            cout << "Invalid input! Please try again." << endl;
            pf::pause();
            playagain(winlose);
            break;
    }
}
};

int main() {
    Game game;
    game.Run();
    pf::pause();
}
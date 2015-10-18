/*
Name of the Program     : Tic Tac Toe 2 Players
Made by                 : Rohan Sharma (racy.rohan@gmail.com)
*/

#include <iostream> //for cout & cin
#include <windows.h>    //for gotoxy()
#include <time.h>   //for delay()
#include <stdio.h>  //for gets()

COORD coord={0,0};  //global variable (used for gotoxy)

void gotoxy(int x,int y)    //function for gotoxy
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void delay(unsigned int mseconds)   //function for delay
{
    clock_t goal=mseconds+clock();
    while(goal>clock());
}

using namespace std;

int main()
{
    int draw=0,p1=0,p2=0;   //to count number of wins/draws
    int ar[3][3],x=0,y=0,n,turn=1;  //'ar' is a 3D array, 'x' & 'y' are coordinates, 'n' and 'turn' are for turn status
    int count_turn=0;  //to count number of turns
    int i,j;
    int sq_num;
    char choice;
    char player1[12],player2[12]; //for names of the players
    cout<<"\t\t\t\tTIC TAC TOE";
    cout<<"\n\n\nEnter name of Player 1 : ";
    cin>>player1;
    cout<<"Enter name of Player 2 : ";
    cin>>player2;
    START:
    count_turn=0;
    system("cls");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            ar[i][j]=0;
        }
    }
    cout<<"\t\t\t\tTIC TAC TOE";
    gotoxy(28,9);
    cout<<"   |   |   ";
    gotoxy(28,10);
    cout<<"(1)|(2)|(3)       "<<player1<<"'s Wins (0) : "<<p1;
    gotoxy(28,11);
    cout<<"   |   |   ";
    gotoxy(28,12);
    cout<<"___________";
    gotoxy(28,13);
    cout<<"   |   |   ";
    gotoxy(28,14);
    cout<<"(4)|(5)|(6)       "<<player2<<"'s Wins (X) : "<<p2;
    gotoxy(28,15);
    cout<<"   |   |   ";
    gotoxy(28,16);
    cout<<"___________";
    gotoxy(28,17);
    cout<<"   |   |   ";
    gotoxy(28,18);
    cout<<"(7)|(8)|(9)       Draw : "<<draw;
    gotoxy(28,19);
    cout<<"   |   |   ";
    TURN:
    if(turn%2!=0)   //for turn status
    {
        gotoxy(30,3);
        cout<<player1<<"'s Turn (0)\t\t";
        n=1;
    }
    else
    {
        gotoxy(30,3);
        cout<<player2<<"'s Turn (X)\t\t";
        n=2;
    }
    INPUT:
    gotoxy(1,5);
    cout<<"Enter Square Number :                           \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
    gotoxy(23,5);
    cin>>sq_num;
    if(sq_num==1)
    {
        x=1;
        y=1;
    }
    else if(sq_num==2)
    {
        x=2;
        y=1;
    }
    else if(sq_num==3)
    {
        x=3;
        y=1;
    }
    else if(sq_num==4)
    {
        x=1;
        y=2;
    }
    else if(sq_num==5)
    {
        x=2;
        y=2;
    }
    else if(sq_num==6)
    {
        x=3;
        y=2;
    }
    else if(sq_num==7)
    {
        x=1;
        y=3;
    }
    else if(sq_num==8)
    {
        x=2;
        y=3;
    }
    else if(sq_num==9)
    {
        x=3;
        y=3;
    }
    count_turn++;
    if(sq_num<1 || sq_num>9)
    {
        gotoxy(35,5);
        cout<<"Invalid Input!";
        count_turn--;
        delay(1000);
        goto INPUT;
    }
    if(ar[x-1][y-1]!=0)
    {
        gotoxy(35,5);
        cout<<"Invalid Input!";
        count_turn--;
        delay(1000);
        goto INPUT;
    }
    ar[x-1][y-1]=n;
    gotoxy(29+4*(x-1)-1,10+4*(y-1));   //for placement of '0' or 'X'
    if(n==1)
    {
        cout<<" 0 ";
    }
    else if(n==2)
    {
        cout<<" X ";
    }
    if((ar[0][0]==ar[1][0] && ar[0][0]==ar[2][0] && ar[0][0]!=0) || (ar[0][0]==ar[0][1] && ar[0][0]==ar[0][2] && ar[0][0]!=0) || (ar[0][0]==ar[1][1] && ar[0][0]==ar[2][2] && ar[0][0]!=0) || (ar[0][1]==ar[1][1] && ar[0][1]==ar[2][1] && ar[0][1]!=0) || (ar[2][0]==ar[2][1] && ar[2][0]==ar[2][2] && ar[2][0]!=0) || (ar[2][0]==ar[1][1] && ar[2][0]==ar[0][2] && ar[2][0]!=0) || (ar[0][2]==ar[1][2] && ar[0][2]==ar[2][2] && ar[0][2]!=0))  //for winning status
    {
        if(turn%2!=0)
        {
            gotoxy(27,21);
            cout<<player1<<" Wins (0)\t\t";
            p1++;
        }
        else
        {
            gotoxy(27,21);
            cout<<player2<<" Wins (X)\t\t";
            p2++;
        }
        goto END;
    }
    if(count_turn==9)
    {
        gotoxy(27,21);
        cout<<"It's a DRAW...";
        draw++;
        goto END;
    }
    turn++;
    goto TURN;
    END:
    gotoxy(46,10);
    cout<<player1<<"'s Wins (0) : "<<p1;
    gotoxy(46,14);
    cout<<player2<<"'s Wins (X) : "<<p2;
    gotoxy(46,18);
    cout<<"Draw : "<<draw;
    gotoxy(1,23);
    cout<<"Do you want to play again (y/n) :                          \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
    cin>>choice;
    if(choice=='y' || choice=='Y')
    {
        cout<<"\n\nThe turn order has been swapped\n\n";
        turn++;
        system("pause");
        goto START;
    }
    else if(choice=='n' || choice=='N')
        goto EXIT;
    else
    {
        gotoxy(45,23);
        cout<<"Invalid Choice!";
        delay(1000);
        goto END;
    }
    EXIT:
    return 0;
}

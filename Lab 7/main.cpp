/*
 Carter Fluckiger
 C++ Fall 2019
 Due: December 11,2019
 Lab: For this lab I made a simple battleship game.  For this lab, I used four
 10 x 10 grids (two for the user and two for the computer). The program will begin with
 setup. The program randomly places the computers 5 ships.  None of the ships overlap or are invalid
*/

#include <cassert>
#include <iostream>
#include<iomanip>
#include<time.h>
//standard is the namespace used throughout the program
using namespace std;
//Pre condition- To enter the ship function the stream must be valid to the point in main where void
//ship is called
//Post condition- The ship void function places the ships checking to make sure the point is valid
//it also makes all neccessary checks to make sure its possible and in the rules
void ship(char board[10][10],char board2[10][10],char board3[10][10],char board4[10][10],int& z,bool right,bool left, bool up, bool down);
//Pre condition- To enter the ship function the stream must be valid to the point in main where void
//ship is called.  Also it is called after ships are placed so must place ships legally
//Post Conditions- Outputs to the screen the board
void createboard(char board_[10][10],char board2[10][10],char board3[10][10],char board4[10][10],int& z,bool right,bool left, bool up, bool down);
//Pre condition- To enter the ship function the stream must be valid to the point in main where void
//ship is called
//Post conditions- Outputs to the screen some text
void text();
//Pre condition- To enter the ship function the stream must be valid to the point in main where void
//ship is called
//Post conditions- Void initialization is used to set default values at the beginning of the
//game and at the end if the player want to play another game
void initialization(char board[10][10],char board2[10][10],char board3[10][10],char board4[10][10],int& z,bool right,bool left, bool up, bool down);
//Pre condition- To enter the ship function the stream must be valid to the point in main where void
//ship is called
//Post condition- void game is the function that does the "firing" this function
//does checks to make sure the inputs are valid and does firing for player and computer
//and couts to the screen at end when it calls void createboard
void game(char board[10][10],char board2[10][10],char board3[10][10],char board4[10][10],int& win,int& loss);
//Pre condition- To enter the ship function the stream must be valid to the point in main where void
//ship is called
//Post conditions- The void eship places the enemy ships making sure they are within
//the guidlines
void eship(char board[10][10],char board2[10][10],char board3[10][10],char board4[10][10]);
//Pre condition- To enter the ship function the stream must be valid to the point in main where void
//ship is called
//Post conditions-This statement is used to end the program when the user doesn't input a
//valid number
int quit(int win, int loss);
//Pre condition- To enter the ship function the stream must be valid to the point in main where void
//ship is called
//Post conditions-void playagain is used to ask the player if they want to play again
void playagain(int& win,int& loss,bool& endgame);
//Struct fleet is used to store the information of each of the ships
struct fleet
{
    string name;
    int x_location;
    int y_location;
    int size;
    int health;
};
//fleet enemyship and friendship are arrays with each value being a ship
fleet enemyship[5];
fleet friendship[5];
//void intitialization sets all values to zero for the most part
void initialization(char board[10][10],char board2[10][10],char board3[10][10],char board4[10][10],int& z,bool right,bool left, bool up, bool down)
{
    //Sets names to values on the array
     friendship[0].name = "Destroyer";
     friendship[1].name = "Submarine";
     friendship[2].name = "Cruiser";
     friendship[3].name = "Battleship";
     friendship[4].name = "Carrier";
     //for loop for initializing all ship values
    //includes logic for ships with same size
     for(int z =4 ; z>=0 ;z--)
     {
         if(z == 1 || z == 0)
         {
             friendship[z].x_location='0';
              friendship[z].y_location='0';
              friendship[z].size=z+2;
              friendship[z].health=z+2;
         }
         else
         {
             friendship[z].x_location='0';
             friendship[z].y_location='0';
             friendship[z].size=z+1;
             friendship[z].health=z+1;
         }
     }
     for(int z =4 ; z>=0 ;z--)
       {
           if(z == 1 || z == 0)
           {
               enemyship[z].x_location='0';
                enemyship[z].y_location='0';
                enemyship[z].size=z+2;
                enemyship[z].health=z+2;
           }
           else
           {
               enemyship[z].x_location='0';
               enemyship[z].y_location='0';
               enemyship[z].size=z+1;
               enemyship[z].health=z+1;
           }
       }
    const char water = '~';
    //for loops for setting values on game boards to water
        for(int i=0;i<10;i++)
        {
            for(int j =0 ; j<10;j++)
            {
                board[i][j]= water;
                board2[i][j]= water;
                board3[i][j]= water;
                board4[i][j]= water;
            }
        }
}
//void createboard couts the boards to the screen
void createboard(char board[10][10],char board2[10][10],char board3[10][10],char board4[10][10],int& z,bool right,bool left, bool up, bool down)
{
    cout<<"\t\tYour board\t\t\t\t\t\t Enemy board"<<endl<<"     1 2 3 4 5 6 7 8 9 10 \t\t\t     1 2 3 4 5 6 7 8 9 10"<<endl<<"     ====================  \t\t\t     ====================";
    for(int i=0;i<10;i++)
    {
        //This segment deals with spacing, rows, and columns
        cout<<endl;
        if(i<=9)
        {
            cout<<setw(4)<<i+1;
            cout<<"|";
        }
        //couts to the screen water
        for(int j =0 ; j<10;j++)
        {
            cout<< char(board[i][j]);
            cout<<" ";
        }
        cout<<"\t\t\t";
        if(i<=9)
              {
                  cout<<setw(4)<<i+1;
                  cout<<"|";
              }
       for(int j =0 ; j<10;j++)
       {
        cout<<char(board2[i][j]);
        cout<<" ";
       }
    }
    //this creates a blank board***does not display it
 cout<<"\n";
}
//void playagain used to ask the player if they want to play another game
void playagain(int& win,int& loss,bool& endgame)
{
    int play;
    cout<<"The game has finished.  If you would like to play again enter 1 and enter 2 to finish and display your score:\n";
    cin>>play;
   switch(play)
   {
       case 1:endgame=true;
           break;
       case 2: endgame=false;
           break;
       default:cout<<"This is not a valid input the game will now end\n";
           quit(win, loss);
           break;
   }
}
int main()
{
    //The definitions at the top are for new game bool and endgame wins and losses
    bool endgame;
    int win=0;
    int loss=0;
    do
    {
   //bool values used for placing ships
    bool up=true;
    bool down=true;
    bool right=true;
    bool left=true;
    //srand used for getting random numbers for enemy placements
  srand((unsigned int)time(NULL));
   
    int z;
        // board are the game boards
    char board[10][10];
    char board2[10][10];
    char board3[10][10];
    char board4[10][10];
    //data that is being transfered between the void functions
    
    //intialization sets all values and can reset the boards**
    initialization(board,board2,board3,board4,z,right,left,up,down);
    createboard(board,board2,board3,board4,z,right,left,up,down);
    text();
    ship(board,board2,board3,board4,z,right,left,up,down);
    eship(board,board2,board3,board4);
    //*****DONE PLACING SHIPS*****
    //****************************
    game(board,board2,board3,board4,win,loss);
        playagain(win,loss,endgame);
    }while(endgame);
    quit(win, loss);
    return 0;
}
//void game is the firing in the game to hit ships
void game(char board[10][10],char board2[10][10],char board3[10][10],char board4[10][10],int &win,int &loss)
{
    //bools checking to see that the player or computer fired a legal shot
    bool friendvalid=true;
    bool enemyvalid=true;
    //bools check if player or computer has won the game
    bool playerwin=true;
    bool enemywin=true;
    //randomnumber for computer
    int randomnumber10;
    //int statements are for checking to see if someone has won the game
    int friendlyhits=17;
    int enemyhits=17;
    
 //These statements got rid of errors- they are more for peace of mind
    int z;
    bool up;
    bool down;
    //ints for player inputs of x and y
    int xloc;
    int yloc;
    //do while for checking to see if either player has won
    do
    {
    //do while for players turn
        do
        {
            //sets bool for validity of players turn has happened legally
            friendvalid=true;
        cout<<"\nIt is now your turn to fire at the enemy ships:\nBe sure to put a space between the x and y coordinates";
        cout<<"Enter an x coordinate then a y coordinate or enter the number 0 to quit: ";
            cin>>xloc;
            //checks to see if cin is valid
            assert(cin);
            //ends progam if player chooses to quit the game
            if(xloc==0)
            {
                quit(win, loss);
            }
            cin>>yloc;
             //checks to see if cin is valid
            assert(cin);
        //subtracts one from each of the inputs to match it with the board
            xloc=xloc-1;
            yloc=yloc-1;
            //This if statement checks to see if the inputs are within the limits of the
            //board and makes the player choose again if they are not
        if((xloc>=0 && xloc<10)&&(yloc>=0 && yloc<10))
        {
            //Thesse are the checks for if the inputs are already tried
            if(board2[yloc][xloc]=='M'||board2[yloc][xloc]=='H')
            {
                cout<<"This position has already been fired on.  Please select another location";
                friendvalid=false;
            }
            //Checks to see if it its a hit
            if(board3[yloc][xloc]=='#')
            {
                cout<<"HIT\n";
                board2[yloc][xloc]='H';
                createboard(board,board2,board3,board4,z,right,left,up,down);
                z=-1;
                //calculates a win if limit is hit to end game
                friendlyhits--;
                //Checks to see if game is over with a winner
                if(friendlyhits==0)
                {
                    win++;
                    playerwin=false;
                }
            }
            //if statement for missed shot
            if(board2[yloc][xloc]=='~')
            {
                cout<<"You missed the shot.  You opponent will now fire their shot\n";
                board2[yloc][xloc]='M';
                createboard(board,board2,board3,board4,z,right,left,up,down);
            }
        }
            //checks if game is over and if player legally fired their shot
        else
        {
            friendvalid=false;
        }
        }while(friendvalid==false);
        //sets random number for computer
        randomnumber10=rand()%10+1;
        int enemyxloc;
        int enemyyloc;
    //computer turn
        do
        {
                    enemyvalid=true;
            //sets enemys x and y locations for targets to
            //also makes them different by resetting it
           enemyyloc=randomnumber10;
             randomnumber10=rand()%10+1;
            enemyxloc=randomnumber10;
              //subtracts to make valid
                    enemyxloc=enemyxloc-1;
                    enemyyloc=enemyyloc-1;
            //checks to see if valid
                if((enemyxloc>=0 && enemyxloc<10)&&(enemyyloc>=0 && enemyyloc<10))
                {
                    //Checks for hits, misses, and for hitting the same location twice
                    if(board[enemyyloc][enemyxloc]=='#')
                   {
                       cout<<"HIT BY THE ENEMY\n";
                       board[enemyyloc][enemyxloc]='H';
                       createboard(board,board2,board3,board4,z,right,left,up,down);
                       enemyhits--;
                       if(enemyhits==0)
                                     {
                                         loss++;
                                         enemywin=false;
                                     }
                   }
                    if(board[enemyyloc][enemyxloc]=='M'||board[enemyyloc][enemyxloc]=='H')
                    {
                   
                        enemyvalid=false;
                    }
                    if(board[enemyyloc][enemyxloc]=='~')
                    {
                        cout<<"Your opponent missed the shot.\n";                        board[enemyyloc][enemyxloc]='M';
                        createboard(board,board2,board3,board4,z,right,left,up,down);
                    }
                }
                else
                {
                    enemyvalid=false;
                }
    //checks to see if the enemy successfully fired legally
        }while(enemyvalid==false);
        //checks for  a winner to exit the do while
    }while(playerwin && enemywin);
}
//void eship is for placing enemy ships
void eship(char board[10][10],char board2[10][10],char board3[10][10],char board4[10][10])
{
    //random numbers for computer placing
    int randomnumber10;
    int randomnumber4;
        int direction;
        //placing ships
         for(int z =4 ; z>=0 ;z--)
         {
             randomnumber10=rand()%10+1;
             randomnumber4=rand()%4+1;
             bool right=true;
             bool left=true;
             bool up=true;
             bool down=true;
        
             enemyship[z].x_location=randomnumber10-1;
              randomnumber10=rand()%10+1;
             enemyship[z].y_location=randomnumber10-1;
             //if statement makes sure values are valid and within board limits
             if((enemyship[z].x_location>=0 && enemyship[z].x_location<10)&&(enemyship[z].y_location>=0 && enemyship[z].y_location<10))
             {
                 //if statements checking if each directions are valid
                 if((enemyship[z].x_location+enemyship[z].size<=10))
                 {
                     for(int count=0;enemyship[z].size>=count;count++)
                     {
                         if(board3[enemyship[z].y_location][enemyship[z].x_location+count]!='~')
                         {
                             right=false;
                         }
                     }
                 }
                 else
                 {
                   right=false;
                 }
                 if((enemyship[z].x_location-enemyship[z].size>=-1))
                 {
                     for(int count =0;enemyship[z].size>=count;count++)
                     {
                         if(board3[enemyship[z].y_location][enemyship[z].x_location-count]!='~')
                        {
                            left=false;
                        }
                     }
                 }
                 else
                 {
                   left=false;
                 }
                 if((enemyship[z].y_location+enemyship[z].size<=10))
                 {
                     for(int count =0;enemyship[z].size>=count;count++)
                     {
                         if(board3[enemyship[z].y_location+count][enemyship[z].x_location]!='~')
                        {
                            down=false;
                        }
                     }
                 }
                 else
                 {
                   down=false;
                 }
                 if((enemyship[z].y_location-enemyship[z].size>=-1))
                 {
                     for(int count =0;enemyship[z].size>=count;count++)
                                {
                            if(board3[enemyship[z].y_location-count][enemyship[z].x_location]!='~')
                                        {
                                            up=false;
                                        }
                                }
                 }
                 else
                 {
                   up=false;
                 }
                 cout<<"\n";
                 direction=randomnumber4;
                 randomnumber4=rand()%4+1;
                 //switch statement for the computer to choose a random direction
                 switch (direction)
                 {
                //cases for the computer to choose the direction it wants to go
                     case 1:
                         if(right)
                         {
                             for(int count=1;enemyship[z].size>=count;count++)
                             {
                                 board3[enemyship[z].y_location][enemyship[z].x_location]='#';
                                 enemyship[z].x_location=enemyship[z].x_location+1;
                             }
                         }
                         else
                        {
                        z++;
                        }
                         break;
                     case 2:
                         if(left)
                         {
                             for(int count=1;enemyship[z].size>=count;count++)
                                {
                                board3[enemyship[z].y_location][enemyship[z].x_location]='#';
                                enemyship[z].x_location=enemyship[z].x_location-1;
                                }
                         }
                         else
                        {
                        z++;
                        }
                         break;
                     case 3:
                         if(down)
                         {
                             for(int count=1;enemyship[z].size>=count;count++)
                             {
                              board3[enemyship[z].y_location][enemyship[z].x_location]='#';
                              enemyship[z].y_location=enemyship[z].y_location+1;
                             }
                         }
                         else
                            {
                            //if computer chooses and invalid input it
                                // it does z++ to redo the picks and numbers
                            z++;
                            }
                         break;
                     case 4:
                if(up)
                {
                    for(int count=1;enemyship[z].size>=count;count++)
                        {
                        board3[enemyship[z].y_location][enemyship[z].x_location]='#';
                        enemyship[z].y_location=enemyship[z].y_location-1;
                        }
                }
                         else
                         {
                             z++;
                         }
                         break;
                 }
                      }
             else
             {
                 z++;
             }
             //creates to board to display after the computer chooses its locations
             createboard(board,board2,board3,board4,z,right,left,up,down);
         }
}
//void text was used to get rid of clutter and is just text outputed to the screen
void text()
{
    cout<<"\n\nWelcome to battleship. . . you will now place your battleships\nFormat should be:\n";
    cout <<  " Y (left-side) coords and X (top-row) coords,\n";
    cout << "Example: 7 2    This would place a ship beginning at x:7 y:2 going horizontal right from the point\n\n";
}
//THIS IS FOR PLACING SHIPS
//void ship is for placing player ships
void ship(char board[10][10],char board2[10][10],char board3[10][10],char board4[10][10],int& z,bool right,bool left, bool up, bool down)
{
    int direction;
    //placing ships
    //for statement for all of the different ships
     for(int z =4 ; z>=0 ;z--)
     {
         //setting default bool values
         right=true;
         left=true;
         up=true;
         down=true;
    cout<<"\nFirst you will be placing the "<<friendship[z].name <<". . ."<<friendship[z].name <<" has a length of "<<friendship[z].size <<"\nTake the length into account when placing\n";
         cout<<"Enter facing: X (top-row)  coords then  Y (left-side) coords with a space between the"; cout<<" numbers\n";
          cout << "Example: 7 2    This would place a ship beginning at x:7 y:2 and make sure to put a space between the numbers\n";
         //cin inputs from player
    cin>>friendship[z].x_location>>friendship[z].y_location;
         //assert checks that the input is valid and ends progam if false
         assert(cin);
         //subtracts one from inputs to make board correct
         friendship[z].x_location=friendship[z].x_location - 1;
         friendship[z].y_location= friendship[z].y_location - 1;
         cout<<"Your options and their corresponding numbers are: ";
         //checks to see if inputs work with board values
         if((friendship[z].x_location>=0 && friendship[z].x_location<10)&&(friendship[z].y_location>=0 && friendship[z].y_location<10))
         {
             //if statements that check up,down,left, and right
             if((friendship[z].x_location+friendship[z].size<=10))
             {
                 for(int count=0;friendship[z].size>=count;count++)
                 {
                     if(board[friendship[z].y_location][friendship[z].x_location+count]!='~')
                     {
                         right=false;
                     }
                 }
                  cout<<"Right 1,";
             }
             else
             {
               right=false;
             }
             if((friendship[z].x_location-friendship[z].size>=0))
             {
                 
                 for(int count =0;friendship[z].size>=count;count++)
                 {
                     if(board[friendship[z].y_location][friendship[z].x_location-count]!='~')
                    {
                        left=false;
                    }
                 }
                 cout<<" Left 2,";
             }
             else
             {
               left=false;
             }
             if((friendship[z].y_location+friendship[z].size<=10))
             {
                 
                 for(int count =0;friendship[z].size>=count;count++)
                 {
                     if(board[friendship[z].y_location+count][friendship[z].x_location]!='~')
                    {
                        down=false;
                    }
                 }
                 cout<<" Down 3,";
             }
             else
             {
               down=false;
             }
             if((friendship[z].y_location-friendship[z].size>=-1))
             {
                 for(int count =0;friendship[z].size>=count;count++)
                                 {
                                if(board[friendship[z].y_location-count][friendship[z].x_location]!='~')
                                    {
                                        up=false;
                                    }
                                 }
                 cout<<" Up 4";
             }
             else
             {
               up=false;
             }
             cout<<"\n";
             //gets input from player
             cin>>direction;
             //checks to see input is valid
             assert(cin);
             //switch statement for chooseing the direction to face the ships
             switch (direction)
             {
                     //cases for facing also checks to see if valid
                 case 1:
                     if(right)
                     {
                     for(int count=1;friendship[z].size>=count;count++)
                 {
                     board4[friendship[z].y_location][friendship[z].x_location]='#';
                      board[friendship[z].y_location][friendship[z].x_location]='#';
                     friendship[z].x_location=friendship[z].x_location+1;
                 }
                     }
                     else
                                         {
                                             cout<<"INVALID INPUT";
                                             z++;
                                         }
                     break;
                 case 2:
                     if(left)
                     {
                         for(int count=1;friendship[z].size>=count;count++)
                                {
                                board4[friendship[z].y_location][friendship[z].x_location]='#';
                                board[friendship[z].y_location][friendship[z].x_location]='#';
                                friendship[z].x_location=friendship[z].x_location-1;
                    
                                    
                                }
                     }
                     else
                                         {
                                             cout<<"INVALID INPUT";
                                             z++;
                                         }
                     break;
                 case 3:
                     if(down)
                     {
                         for(int count=1;friendship[z].size>=count;count++)
                         {
                             board4[friendship[z].y_location][friendship[z].x_location]='#';
                          board[friendship[z].y_location][friendship[z].x_location]='#';
                          friendship[z].y_location=friendship[z].y_location+1;
                         }
                     }
                     else
                                         {
                                             cout<<"INVALID INPUT";
                                             z++;
                                         }
                     break;
                 case 4:
                     if(up)
                                         {
                                    for(int count=1;friendship[z].size>=count;count++)
                                        {
                                            board4[friendship[z].y_location][friendship[z].x_location]='#';
                                        board[friendship[z].y_location][friendship[z].x_location]='#';
                                              friendship[z].y_location=friendship[z].y_location-1;
                                        }
                                         }
                     else
                     {
                         //if invalid looks
                         cout<<"INVALID INPUT";
                         z++;
                     }
                     break;
                 
                 default:cout<<"**INVALID INPUT**";
                     z++;
                    break;
             }
             //creates board if valid inputs are used
         createboard(board,board2,board3,board4,z,right,left,up,down);
                  }
         else
         {
             z++;
         }
     }
}
//quit statement used for exiting program when used chooses to leave the program
int quit(int win, int loss)
{
    cout<<"Thank you for playing my battleship game here are your wins and losses\n";
    cout<<"Wins: "<<win<<"\n"<<"Losses: "<<loss<<"\n";
    //exits the program with code 0
    exit(0);
}

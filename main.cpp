//
//  main.cpp
//  Tic Tac Toe
//
//  Created by Naman Kumar on 02/10/16.
//  Copyright © 2016 Naman Kumar. All rights reserved.
//
#include <iostream>
#include <time.h>
using namespace std;

int a[3][3],t,y,done=0;

/*
 a[3][3] is the array. t is the turn player choose, if player goes first t=1 and hence y i.e turn of AI becomes 2. t&y are used to fill data in the array. Done turns to 1 if the AI take a step.
*/
void again();

void print() //Prints the Array.
{
    cout<<"\n";
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            cout<<a[i][j]<<"\t";
        cout<<endl;
    }
}

int check() //Its checks if someone won. First checkes all three rows and columns then both the diagonals.
{
    for(int i=0;i<3;i++)
        if((a[i][0]!=0&&a[i][0]==a[i][1]&&a[i][1]==a[i][2])||(a[0][i]!=0&&a[0][i]==a[1][i]&&a[1][i]==a[2][i]))
            return 1;
    
    if(a[0][0]!=0&&a[0][0]==a[1][1]&&a[1][1]==a[2][2])
        return 1;
    else if(a[0][2]!=0&&a[0][2]==a[1][1]&&a[1][1]==a[2][0])
        return 1;
    else
        return 0;
}

void pin() //Take input from player.
{
    int r=0,c=0;
    cout<<"Player turn: ";
    cin>>r>>c;
    r--;
    c--;
    if(r>2||c>2||r<0||c<0)
    {
        cout<<"Enter correct value."<<endl;
        print();
        pin();
    }
    else if(a[r][c]!=0)
    {
        cout<<"Already filled!\n";
        print();
        pin();
    }
    else
    a[r][c]=t;
}

void checkwin() //Checks if the AI is having a possible winning move. Take the step and wins.
{
    if( (a[0][0]==a[1][1]&&a[1][1]==y&&a[2][2]==0) || (a[1][1]==a[2][2]&&a[2][2]==y&&a[0][0]==0) || (a[0][0]==a[2][2]&&a[2][2]==y&&a[1][1]==0) )
    {
        for(int i=0;i<3;i++)
        {
            if(a[i][i]==0)
            {
                a[i][i]=y;
                cout<<"Computer turn: "<<i+1<<" "<<i+1<<endl;
                done=1;
                break;
            }
        }
    }
    else if( (a[0][2]==a[1][1]&&a[1][1]==y&&a[2][0]==0) || (a[1][1]==a[2][0]&&a[2][0]==y&&a[0][2]==0) || (a[0][2]==a[2][0]&&a[2][0]==y&&a[1][1]==0) )
    {
        for(int i=0;i<3;i++)
        {
            if(a[i][2-i]==0)
            {
                a[i][2-i]=y;
                cout<<"Computer turn: "<<i+1<<" "<<3-i<<endl;
                done=1;
                break;
            }
        }
    }
    else
    {
        for(int i=0;i<3;i++)
        {
            if( (a[i][0]==a[i][1]&&a[i][1]==y&&a[i][2]==0) || (a[i][1]==a[i][2]&&a[i][2]==y&&a[i][0]==0) || (a[i][0]==a[i][2]&&a[i][2]==y&&a[i][1]==0) )
            {
                for(int j=0;j<3;j++)
                {
                    if(a[i][j]==0)
                    {
                        a[i][j]=y;
                        cout<<"Computer turn: "<<i+1<<" "<<j+1<<endl;
                        done=1;
                        break;
                    }
                }
            }
            else if((a[0][i]==a[1][i]&&a[1][i]==y&&a[2][i]==0) || (a[1][i]==a[2][i]&&a[2][i]==y&&a[0][i]==0) || (a[0][i]==a[2][i]&&a[2][i]==y&&a[1][i]==0))
            {
                for(int j=0;j<3;j++)
                {
                    if(a[j][i]==0)
                    {
                        a[j][i]=y;
                        cout<<"Computer turn: "<<j+1<<" "<<i+1<<endl;
                        done=1;
                        break;
                    }
                }
            }
            if(done)
                break;
        }
    }
}

void find() //Checks if the player have a possible winning move, takes a step as to tackle the player.
{
    done =0;
    if( (a[0][0]==a[1][1]&&a[1][1]==t&&a[2][2]==0) || (a[1][1]==a[2][2]&&a[2][2]==t&&a[0][0]==0) || (a[0][0]==a[2][2]&&a[2][2]==t&&a[1][1]==0) )
    {
        for(int i=0;i<3;i++)
        {
            if(a[i][i]==0)
            {
                a[i][i]=y;
                cout<<"Computer turn: "<<i+1<<" "<<i+1<<endl;
                done=1;
                break;
            }
        }
    }
    else if( (a[0][2]==a[1][1]&&a[1][1]==t&&a[2][0]==0) || (a[1][1]==a[2][0]&&a[2][0]==t&&a[0][2]==0) || (a[0][2]==a[2][0]&&a[2][0]==t&&a[1][1]==0) )
    {
        for(int i=0;i<3;i++)
        {
            if(a[i][2-i]==0)
            {
                a[i][2-i]=y;
                cout<<"Computer turn: "<<i+1<<" "<<3-i<<endl;
                done=1;
                break;
            }
        }
    }
    else
    {
        for(int i=0;i<3;i++)
        {
            if( (a[i][0]==a[i][1]&&a[i][1]==t&&a[i][2]==0) || (a[i][1]==a[i][2]&&a[i][2]==t&&a[i][0]==0) || (a[i][0]==a[i][2]&&a[i][2]==t&&a[i][1]==0) )
            {
                for(int j=0;j<3;j++)
                {
                    if(a[i][j]==0)
                    {
                        a[i][j]=y;
                        cout<<"Computer turn: "<<i+1<<" "<<j+1<<endl;
                        done=1;
                        break;
                    }
                }
            }
            else if((a[0][i]==a[1][i]&&a[1][i]==t&&a[2][i]==0) || (a[1][i]==a[2][i]&&a[2][i]==t&&a[0][i]==0) || (a[0][i]==a[2][i]&&a[2][i]==t&&a[1][i]==0))
            {
                for(int j=0;j<3;j++)
                {
                    if(a[j][i]==0)
                    {
                        a[j][i]=y;
                        cout<<"Computer turn: "<<j+1<<" "<<i+1<<endl;
                        done=1;
                        break;
                    }
                }
            }
            if(done)
                break;
        }
    }
}

void win() //Take a step (as to attack) such that it have winning possibilities in future moves.
{
    if(a[0][0]+a[0][2]+a[2][0]+a[2][2]==t||a[0][0]+a[0][2]+a[2][0]+a[2][2]==2*t)
    {
        for(int i=0;i<3;i++)
        {
            if( a[i][0]+a[i][1]+a[i][2]==y && (a[i][0]==y||a[i][1]==y||a[i][2]==y) )
            {
                if(i==1)
                {
                    for(int j=0;j<3;j++)
                    {
                        if(a[i][j]==0)
                        {
                            a[i][j]=y;
                            cout<<"Computer turn: "<<i+1<<" "<<j+1<<endl;
                            done=1;
                            break;
                        }
                    }
                }
                else
                {
                    for(int j=2;j>=0;j--)
                    {
                        if(a[i][j]==0)
                        {
                            a[i][j]=y;
                            cout<<"Computer turn: "<<i+1<<" "<<j+1<<endl;
                            done=1;
                            break;
                        }
                    }
                }
            }
            else if(a[0][i]+a[1][i]+a[2][i]==y && (a[0][i]==y||a[1][i]==y||a[2][i]==y))
            {
                if(i==1)
                {
                    for(int j=0;j<3;j++)
                    {
                        if(a[j][i]==0)
                        {
                            a[j][i]=y;
                            cout<<"Computer turn: "<<j+1<<" "<<i+1<<endl;
                            done=1;
                            break;
                        }
                    }
                }
                else
                {
                    for(int j=2;j>=0;j--)
                    {
                        if(a[j][i]==0)
                        {
                            a[j][i]=y;
                            cout<<"Computer turn: "<<j+1<<" "<<i+1<<endl;
                            done=1;
                            break;
                        }
                    }
                }
            
            }
            if(done)
                break;
        }
    
        if(a[0][0]+a[1][1]+a[2][2]==y && (a[0][0]==y||a[1][1]==y||a[2][2]==y)&&!done)
        {
            for(int i=2;i>=0;i--)
            {
                if((a[i][i]==0)&& ((a[i][0]+a[i][1]+a[i][2]==y&&(a[i][0]==y||a[i][1]==y||a[i][2]==y)) ||( (a[0][i]+a[1][i]+a[2][i]==y)&&(a[0][i]==y||a[1][i]==y||a[2][i]==y))))
                {
                    a[i][i]=y;
                    cout<<"Computer turn: "<<i+1<<" "<<i+1<<endl;
                    done=1;
                    break;
                }
            }
            if(!done)
            {
                for(int i=2;i>=0;i--)
                {
                    if(a[i][i]==0)
                    {
                        if((a[i][0]+a[i][1]+a[i][2]==t&&(a[i][0]==t||a[i][1]==t||a[i][2]==t))&&(a[0][i]+a[1][i]+a[2][i]==t&&(a[0][i]==t||a[1][i]==t||a[2][i]==t)))
                        {
                            a[i][i]=y;
                            cout<<"Computer turn: "<<i+1<<" "<<i+1<<endl;
                            done=1;
                            break;
                        }
                    }
                }
                if(!done)
                {
                    for(int i=2;i>=0;i--)
                    {
                        if(a[i][i]==0)
                        {
                            a[i][i]=y;
                            cout<<"Computer turn: "<<i+1<<" "<<i+1<<endl;
                            done=1;
                            break;
                        }
                    }
                }
            }
        }
        
        else if( a[0][2]+a[1][1]+a[2][0]==y && (a[0][2]==y||a[1][1]==y||a[2][0]==y) &&!done)
        {
            for(int i=2;i>=0;i--)
            {
                if(a[i][2-i]==0&&((a[i][0]+a[i][1]+a[i][2]==y&&(a[i][0]==y||a[i][1]==y||a[i][2]==y))||( (a[0][2-i]+a[1][2-i]+a[2][2-i]==y)&&(a[0][2-i]==y||a[1][2-i]==y||a[2][2-i]==y))))
                {
                    a[i][2-i]=y;
                    cout<<"Computer turn: "<<i+1<<" "<<3-i<<endl;
                    done=1;
                    break;
                }
            }
            if(!done)
            {
                for(int i=2;i>=0;i--)
                {
                    if(a[i][2-i]==0)
                    {
                        if((a[i][0]+a[i][1]+a[i][2]==t&&(a[i][0]==t||a[i][1]==t||a[i][2]==t))&&(a[0][2-i]+a[1][2-i]+a[2][2-i]==t&&(a[0][2-i]==t||a[1][2-i]==t||a[2][2-i]==t)))
                        {
                        a[i][2-i]=y;
                        cout<<"Computer turn: "<<i+1<<" "<<3-i<<endl;
                        done=1;
                        break;
                        }
                    }
                }
                if(!done)
                {
                    for(int i=2;i>=0;i--)
                    {
                        if(a[i][2-i]==0)
                        {
                                a[i][2-i]=y;
                                cout<<"Computer turn: "<<i+1<<" "<<3-i<<endl;
                                done=1;
                                break;
                        }
                    }
                }
            }
        }
    }
    
    else
    {
        if(a[0][0]+a[1][1]+a[2][2]==y && (a[0][0]==y||a[1][1]==y||a[2][2]==y))
        {
            for(int i=2;i>=0;i--)
            {
                if((a[i][i]==0)&& ((a[i][0]+a[i][1]+a[i][2]==y&&(a[i][0]==y||a[i][1]==y||a[i][2]==y)) ||( (a[0][i]+a[1][i]+a[2][i]==y)&&(a[0][i]==y||a[1][i]==y||a[2][i]==y))))
                {
                    a[i][i]=y;
                    cout<<"Computer turn: "<<i+1<<" "<<i+1<<endl;
                    done=1;
                    break;
                }
            }
            if(!done)
            {
                for(int i=2;i>=0;i--)
                {
                    if(a[i][i]==0)
                    {
                        if((a[i][0]+a[i][1]+a[i][2]==t&&(a[i][0]==t||a[i][1]==t||a[i][2]==t))&&(a[0][i]+a[1][i]+a[2][i]==t&&(a[0][i]==t||a[1][i]==t||a[2][i]==t)))
                        {
                            a[i][i]=y;
                            cout<<"Computer turn: "<<i+1<<" "<<i+1<<endl;
                            done=1;
                            break;
                        }
                    }
                }
                if(!done)
                {
                    for(int i=2;i>=0;i--)
                    {
                        if(a[i][i]==0)
                        {
                            a[i][i]=y;
                            cout<<"Computer turn: "<<i+1<<" "<<i+1<<endl;
                            done=1;
                            break;
                        }
                    }
                }
            }
        }
        
        else if( a[0][2]+a[1][1]+a[2][0]==y && (a[0][2]==y||a[1][1]==y||a[2][0]==y))
        {
            for(int i=2;i>=0;i--)
            {
                if(a[i][2-i]==0&&((a[i][0]+a[i][1]+a[i][2]==y&&(a[i][0]==y||a[i][1]==y||a[i][2]==y))||( (a[0][2-i]+a[1][2-i]+a[2][2-i]==y)&&(a[0][2-i]==y||a[1][2-i]==y||a[2][2-i]==y))))
                {
                    a[i][2-i]=y;
                    cout<<"Computer turn: "<<i+1<<" "<<3-i<<endl;
                    done=1;
                    break;
                }
            }
            if(!done)
            {
                for(int i=2;i>=0;i--)
                {
                    if(a[i][2-i]==0)
                    {
                        if((a[i][0]+a[i][1]+a[i][2]==t&&(a[i][0]==t||a[i][1]==t||a[i][2]==t))&&(a[0][2-i]+a[1][2-i]+a[2][2-i]==t&&(a[0][2-i]==t||a[1][2-i]==t||a[2][2-i]==t)))
                        {
                            a[i][2-i]=y;
                            cout<<"Computer turn: "<<i+1<<" "<<3-i<<endl;
                            done=1;
                            break;
                        }
                    }
                }
                if(!done)
                {
                    for(int i=2;i>=0;i--)
                    {
                        if(a[i][2-i]==0)
                        {
                            a[i][2-i]=y;
                            cout<<"Computer turn: "<<i+1<<" "<<3-i<<endl;
                            done=1;
                            break;
                        }
                    }
                }
            }
        }

        else
        {
            for(int i=0;i<3;i++)
            {
                if( a[i][0]+a[i][1]+a[i][2]==y && (a[i][0]==y||a[i][1]==y||a[i][2]==y) )
                {
                    if(i==1)
                    {
                        for(int j=0;j<3;j++)
                        {
                            if(a[i][j]==0)
                            {
                                a[i][j]=y;
                                cout<<"Computer turn: "<<i+1<<" "<<j+1<<endl;
                                done=1;
                                break;
                            }
                        }
                    }
                    else{
                        for(int j=2;j>=0;j--)
                        {
                            if(a[i][j]==0)
                            {
                                a[i][j]=y;
                                cout<<"Computer turn: "<<i+1<<" "<<j+1<<endl;
                                done=1;
                                break;
                            }
                        }
                    }
                }
                else if(a[0][i]+a[1][i]+a[2][i]==y && (a[0][i]==y||a[1][i]==y||a[2][i]==y))
                {
                    if(i==1)
                    {
                        for(int j=0;j<3;j++)
                        {
                            if(a[j][i]==0)
                            {
                                a[j][i]=y;
                                cout<<"Computer turn: "<<j+1<<" "<<i+1<<endl;
                                done=1;
                                break;
                            }
                        }
                    }
                    else
                    {
                        for(int j=2;j>=0;j--)
                        {
                            if(a[j][i]==0)
                            {
                                a[j][i]=y;
                                cout<<"Computer turn: "<<j+1<<" "<<i+1<<endl;
                                done=1;
                                break;
                            }
                        }
                    }
                
                }
                if(done)
                    break;
            }
        }
    }
}

void ai(int b) //controls the moves AI takes.
{
    done=0;
    checkwin();
    if(!done)
    {
        find();
        if(!done)
        {
            if((a[0][0]+a[0][2]+a[2][0]+a[2][2]==t+y||a[0][0]+a[0][2]+a[2][0]+a[2][2]==t+2*y)&&a[1][1]==0)
            {
                for(int i=0;i<3;i+=2)
                {
                    for(int j=0;j<3;j+=2)
                        if(a[i][j]==0)
                        {
                            a[i][j]=y;
                            cout<<"Computer turn: "<<i+1<<" "<<j+1<<endl;
                            goto end;
                        }
                }
                
            }
            else if(b==2&&a[1][1]==0)
            {
                a[1][1]=y;
                cout<<"Computer turn: 2 2\n";
                goto end;
            }
            win();
            if(!done)
            {
                if(b==0)
                {
                    time_t seconds;
                    time(&seconds);
                    srand((unsigned int) seconds);
                    
                    a[(rand()%2)*2][(rand()%2)*2]=y;
                    for(int i=0;i<3;i+=2)
                    {
                        for(int j=0;j<3;j+=2)
                            if(a[i][j]==y)
                                cout<<"Computer turn: "<<i+1<<" "<<j+1<<endl;
                    }
                }
                else if(a[1][1]==0)
                {
                    a[1][1]=y;
                    cout<<"Computer turn: 2 2\n";
                }
                else if(a[0][0]==0||a[0][2]==0||a[2][0]==0||a[2][2]==0)
                {
                    for(int i=0;i<3;i+=2)
                    {
                        for(int j=0;j<3;j+=2)
                            if(a[i][j]==0)
                            {
                                a[i][j]=y;
                                cout<<"Computer turn: "<<i+1<<" "<<j+1<<endl;
                                done=1;
                                break;
                            }
                        if(done)
                            break;
                    }
                }
                else
                {
                    for(int i=0;i<3;i++)
                    {
                        for(int j=0;j<3;j++)
                        {
                            if(a[i][j]==0)
                            {
                                a[i][j]=y;
                                cout<<"Computer turn: "<<i+1<<" "<<j+1<<endl;
                                done=1;
                                break;
                            }
                        }
                        if(done)
                            break;
                    }
                }
            }
        }
    }
    end:
    cout<<endl;
}

int main()
{
    int i,j;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            a[i][j]=0;
    cout<<"Choose your turn 1st or 2nd: ";
    cin>>t;
    if(t!=1&&t!=2)
    {
        cout<<"Enter correct choice.\n";
        main();
    }
    cout<<"\nPlayer Symbol: "<<t<<endl;
    switch(t)
    {
        case 1:
            y=2;
            cout<<"Computer Symbol: "<<y<<endl;
            print();
            for(i=0;i<9;)
            {
                pin();
                print();
                i++;
                if(i>4)
                    if(check())
                    {
                        cout<<"Congratulations, You WON!";
                        again();
                        break;
                    }
                if(i>=8)
                    break;
                ai(i);
                print();
                i++;
                if(i>5)
                    if(check())
                    {
                        cout<<"Computer WON, You LOOSE!";
                        again();
                        break;
                    }
            }
            break;
            
        case 2:
            y=1;
            cout<<"Computer Symbol: "<<y<<endl;
            print();
            for(i=0;i<9;)
            {
                ai(i);
                print();
                i++;
                if(i>4)
                    if(check())
                    {
                        cout<<"Computer WON, You LOOSE!";
                        again();
                        break;
                    }
                if(i>=8)
                    break;
                pin();
                print();
                i++;
                if(i>5)
                    if(check())
                    {
                        cout<<"Congratulations, You WON!";
                        again();
                        break;
                    }
            }

            break;
    }
    if(!check())
        cout<<"TIE!"<<endl;
    again();
        return 0;
}
void again()
{
    char c;
    cout<<endl<<"Want to play again Y/N? ";
    cin>>c;
    if(c=='y'||c=='Y')
        main();
    else
        exit(0);
}
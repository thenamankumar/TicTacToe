//
//  main.cpp
//  Tic Tac Toe
//
//  Created by Naman Kumar on 02/10/16.
//  Copyright © 2016 Naman Kumar. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

int a[3][3],t,y,game=1;
char name[30],str[500];

void print()//print the board
{
    int i,j;
    cout<<"\n";
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(a[i][j]==0)
                cout<<".\t";
            else if(a[i][j]==1)
                cout<<"X\t";
            else
                cout<<"O\t";
        }
        cout<<endl;
    }
}

int check()//checks if anyone is winning.
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

void pin()//takes input from player
{
    int r=0,c=0;
    cout<<"Enter row: ";
    cin>>r;
    cout<<"Enter column: ";
    cin>>c;
    r--;
    c--;
    if(r>2||c>2||r<0||c<0)
    {
        strcpy(str,"Enter correct value ");
        strcat(str,name);
        strcat(str,".\n");
        puts(str);
        pin();
    }
    else if(a[r][c]!=0)
    {
        cout<<"It is already filled.\n";
        pin();
    }
    else
        a[r][c]=t;
}

int defend(int c, int p, int b)
{
    if(b<3)
        return 0;
    else if(a[0][0]+a[1][1]+a[2][2]==2*c&&a[0][0]!=p&&a[1][1]!=p&&a[2][2]!=p)
    {
        for(int i=0;i<3;i++)
        {
            if(a[i][i]==0)
            {
                a[i][i]=y;
                cout<<"Computer turn: "<<i+1<<" "<<i+1<<endl;
                return 1;
            }
        }
    }
    else if(a[0][2]+a[1][1]+a[2][0]==2*c&&a[0][2]!=p&&a[1][1]!=p&&a[2][0]!=p)
    {
        for(int i=0;i<3;i++)
        {
            if(a[i][2-i]==0)
            {
                a[i][2-i]=y;
                cout<<"Computer turn: "<<i+1<<" "<<3-i<<endl;
                return 1;
            }
        }
    }
    else
    {
        int i,j;
        for(i=0;i<3;i++)
        {
            if(a[i][0]+a[i][1]+a[i][2]==2*c&&a[i][0]!=p&&a[i][1]!=p&&a[i][2]!=p)
            {
                for(j=0;j<3;j++)
                {
                    if(a[i][j]==0)
                    {
                        a[i][j]=y;
                        cout<<"Computer turn: "<<i+1<<" "<<j+1<<endl;
                        return 1;                    }
                }
            }
            else if(a[0][i]+a[1][i]+a[2][i]==2*c&&a[0][i]!=p&&a[1][i]!=p&&a[2][i]!=p)
            {
                for(j=0;j<3;j++)
                {
                    if(a[j][i]==0)
                    {
                        a[j][i]=y;
                        cout<<"Computer turn: "<<j+1<<" "<<i+1<<endl;
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int attack()//takes a move as to win in future.
{
    int i,j;
    if(a[0][0]+a[0][2]+a[2][0]+a[2][2]==t||a[0][0]+a[0][2]+a[2][0]+a[2][2]==2*t)
    {
        for(i=0;i<3;i++)
        {
            if( a[i][0]+a[i][1]+a[i][2]==y && (a[i][0]==y||a[i][1]==y||a[i][2]==y) )
            {
                if(i==1)
                {
                    for(j=0;j<3;j++)
                    {
                        if(a[i][j]==0)
                        {
                            a[i][j]=y;
                            cout<<"Computer turn: "<<i+1<<" "<<j+1<<endl;
                            return 1;
                        }
                    }
                }
                else
                {
                    for(j=2;j>=0;j--)
                    {
                        if(a[i][j]==0)
                        {
                            a[i][j]=y;
                            cout<<"Computer turn: "<<i+1<<" "<<j+1<<endl;
                            return 1;
                        }
                    }
                }
            }
            if(a[0][i]+a[1][i]+a[2][i]==y && (a[0][i]==y||a[1][i]==y||a[2][i]==y))
            {
                if(i==1)
                {
                    for(j=0;j<3;j++)
                    {
                        if(a[j][i]==0)
                        {
                            a[j][i]=y;
                            cout<<"Computer turn: "<<j+1<<" "<<i+1<<endl;
                            return 1;
                        }
                    }
                }
                else
                {
                    for(j=2;j>=0;j--)
                    {
                        if(a[j][i]==0)
                        {
                            a[j][i]=y;
                            cout<<"Computer turn: "<<j+1<<" "<<i+1<<endl;
                            return 1;
                        }
                    }
                }
                
            }
        }
        
        if(a[0][0]+a[1][1]+a[2][2]==y && (a[0][0]==y||a[1][1]==y||a[2][2]==y))
        {
            for(i=2;i>=0;i--)
            {
                if((a[i][i]==0)&& ((a[i][0]+a[i][1]+a[i][2]==y&&(a[i][0]==y||a[i][1]==y||a[i][2]==y)) ||( (a[0][i]+a[1][i]+a[2][i]==y)&&(a[0][i]==y||a[1][i]==y||a[2][i]==y))))
                {
                    a[i][i]=y;
                    cout<<"Computer turn: "<<i+1<<" "<<i+1<<endl;
                    return 1;
                }
            }
            for(i=2;i>=0;i--)
            {
                if(a[i][i]==0)
                {
                    if((a[i][0]+a[i][1]+a[i][2]==t&&(a[i][0]==t||a[i][1]==t||a[i][2]==t))&&(a[0][i]+a[1][i]+a[2][i]==t&&(a[0][i]==t||a[1][i]==t||a[2][i]==t)))
                    {
                        a[i][i]=y;
                        cout<<"Computer turn: "<<i+1<<" "<<i+1<<endl;
                        return 1;
                    }
                }
            }
            for(i=2;i>=0;i--)
            {
                if(a[i][i]==0)
                {
                    a[i][i]=y;
                    cout<<"Computer turn: "<<i+1<<" "<<i+1<<endl;
                    return 1;
                }
            }
        }
        else if( a[0][2]+a[1][1]+a[2][0]==y && (a[0][2]==y||a[1][1]==y||a[2][0]==y))
        {
            for(i=2;i>=0;i--)
            {
                if(a[i][2-i]==0&&((a[i][0]+a[i][1]+a[i][2]==y&&(a[i][0]==y||a[i][1]==y||a[i][2]==y))||( (a[0][2-i]+a[1][2-i]+a[2][2-i]==y)&&(a[0][2-i]==y||a[1][2-i]==y||a[2][2-i]==y))))
                {
                    a[i][2-i]=y;
                    cout<<"Computer turn: "<<i+1<<" "<<3-i<<endl;
                    return 1;
                }
            }
            for(i=2;i>=0;i--)
            {
                if(a[i][2-i]==0)
                {
                    if((a[i][0]+a[i][1]+a[i][2]==t&&(a[i][0]==t||a[i][1]==t||a[i][2]==t))&&(a[0][2-i]+a[1][2-i]+a[2][2-i]==t&&(a[0][2-i]==t||a[1][2-i]==t||a[2][2-i]==t)))
                    {
                        a[i][2-i]=y;
                        cout<<"Computer turn: "<<i+1<<" "<<3-i<<endl;
                        return 1;
                    }
                }
            }
            for(i=2;i>=0;i--)
            {
                if(a[i][2-i]==0)
                {
                    a[i][2-i]=y;
                    cout<<"Computer turn: "<<i+1<<" "<<3-i<<endl;
                    return 1;
                }
            }
        }
    }
    else
    {
        if(a[0][0]+a[1][1]+a[2][2]==y && (a[0][0]==y||a[1][1]==y||a[2][2]==y))
        {
            for(i=2;i>=0;i--)
            {
                if((a[i][i]==0)&& ((a[i][0]+a[i][1]+a[i][2]==y&&(a[i][0]==y||a[i][1]==y||a[i][2]==y)) ||( (a[0][i]+a[1][i]+a[2][i]==y)&&(a[0][i]==y||a[1][i]==y||a[2][i]==y))))
                {
                    a[i][i]=y;
                    cout<<"Computer turn: "<<i+1<<" "<<i+1<<endl;
                    return 1;
                }
            }
            for(i=2;i>=0;i--)
            {
                if(a[i][i]==0)
                {
                    if((a[i][0]+a[i][1]+a[i][2]==t&&(a[i][0]==t||a[i][1]==t||a[i][2]==t))&&(a[0][i]+a[1][i]+a[2][i]==t&&(a[0][i]==t||a[1][i]==t||a[2][i]==t)))
                    {
                        a[i][i]=y;
                        cout<<"Computer turn: "<<i+1<<" "<<i+1<<endl;
                        return 1;
                    }
                }
            }
            for(i=2;i>=0;i--)
            {
                if(a[i][i]==0)
                {
                    a[i][i]=y;
                    cout<<"Computer turn: "<<i+1<<" "<<i+1<<endl;
                    return 1;
                }
            }
        }
        
        else if( a[0][2]+a[1][1]+a[2][0]==y && (a[0][2]==y||a[1][1]==y||a[2][0]==y))
        {
            for(i=2;i>=0;i--)
            {
                if(a[i][2-i]==0&&((a[i][0]+a[i][1]+a[i][2]==y&&(a[i][0]==y||a[i][1]==y||a[i][2]==y))||( (a[0][2-i]+a[1][2-i]+a[2][2-i]==y)&&(a[0][2-i]==y||a[1][2-i]==y||a[2][2-i]==y))))
                {
                    a[i][2-i]=y;
                    cout<<"Computer turn: "<<i+1<<" "<<3-i<<endl;
                    return 1;
                }
            }
            for(i=2;i>=0;i--)
            {
                if(a[i][2-i]==0)
                {
                    if((a[i][0]+a[i][1]+a[i][2]==t&&(a[i][0]==t||a[i][1]==t||a[i][2]==t))&&(a[0][2-i]+a[1][2-i]+a[2][2-i]==t&&(a[0][2-i]==t||a[1][2-i]==t||a[2][2-i]==t)))
                    {
                        a[i][2-i]=y;
                        cout<<"Computer turn: "<<i+1<<" "<<3-i<<endl;
                        return 1;
                    }
                }
            }
            
            for(i=2;i>=0;i--)
            {
                if(a[i][2-i]==0)
                {
                    a[i][2-i]=y;
                    cout<<"Computer turn: "<<i+1<<" "<<3-i<<endl;
                    return 1;
                }
            }
        }
        
        else
        {
            for(i=0;i<3;i++)
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
                                return 1;
                            }
                        }
                    }
                    else{
                        for(j=2;j>=0;j--)
                        {
                            if(a[i][j]==0)
                            {
                                a[i][j]=y;
                                cout<<"Computer turn: "<<i+1<<" "<<j+1<<endl;
                                return 1;
                            }
                        }
                    }
                }
                else if(a[0][i]+a[1][i]+a[2][i]==y && (a[0][i]==y||a[1][i]==y||a[2][i]==y))
                {
                    if(i==1)
                    {
                        for(j=0;j<3;j++)
                        {
                            if(a[j][i]==0)
                            {
                                a[j][i]=y;
                                cout<<"Computer turn: "<<j+1<<" "<<i+1<<endl;
                                return 1;
                            }
                        }
                    }
                    else
                    {
                        for(j=2;j>=0;j--)
                        {
                            if(a[j][i]==0)
                            {
                                a[j][i]=y;
                                cout<<"Computer turn: "<<j+1<<" "<<i+1<<endl;
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

void ai(int b)//controls the compter's move
{
    if(!defend(y,t,b))
    {
        if(!defend(t,y,b))
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
            if(!attack())
            {
                if(b==0)
                {
                    time_t seconds;
                    time(&seconds);
                    srand((unsigned int) seconds);
                    int i,j;
                    a[(rand()%2)*2][(rand()%2)*2]=y;
                    for(i=0;i<3;i+=2)
                    {
                        for(j=0;j<3;j+=2)
                            if(a[i][j]==y)
                                cout<<"Computer turn: "<<i+1<<" "<<j+1<<endl;
                    }
                }
                else if(a[1][1]==0)
                {
                    a[1][1]=y;
                    cout<<"Computer turn: 2 2\n";
                }
                else
                {
                    int i,j;
                    for(i=0;i<3;i++)
                    {
                        for(j=0;j<3;j++)
                        {
                            if(a[i][j]==0)
                            {
                                a[i][j]=y;
                                cout<<"Computer turn: "<<i+1<<" "<<j+1<<endl;
                                goto end;
                            }
                        }
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
    if(game==1)
    {
        cout<<"What is your good name? ";
        gets(name);
        strcpy(str,"\nHi ");
        strcat(str, name);
        strcat(str,", so you wanna challenge me in Tic Tac Toe, right?\nLet's see who wins.");
        puts(str);
        
        strcpy(str,"\nChoice is your's ");
        strcat(str,name);
        strcat(str,", wanna go 1st or 2nd?");
        puts(str);
    }
    else
    {
        strcpy(str,"\nOkay so you think you can beat me this time ");
        strcat(str,name);
        strcat(str,".\nLet's see again if you can.");
        puts(str);
        
        strcpy(str,"\nThis time you wanna go 1st or 2nd, ");
        strcat(str,name);
        strcat(str,"?");
        puts(str);
    }
    
input:
    cin>>t;
    switch(t)
    {
        case 1:
            y=2;
            cout<<"\nSo your symbol is X.\nAnd mine is O.\n\nLet's start the game.";
            print();
            for(i=0;i<9;)
            {
                pin();
                print();
                i++;
                if(i>4)
                    if(check())
                    {
                        strcpy(str,"\nOh, you won ");
                        strcat(str,name);
                        strcat(str," .\nCongratulations\nGreat work!\n\nMy algorithm needs to be improved.\nBie.");
                        puts(str);
                        exit(0);
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
                        strcpy(str,"\nIt is impossible to beat me ");
                        strcat(str,name);
                        if(game>1)
                            strcat(str,", you couldn't beat me this time too, I won.");
                        else
                            strcat(str,", I won, you loose.");
                        puts(str);
                        break;
                    }
            }
            break;
            
        case 2:
            y=1;
            cout<<"\nSo your symbol is O.\nAnd mine is X.\n\nLet's start the game.";
            print();
            for(i=0;i<9;)
            {
                ai(i);
                print();
                i++;
                if(i>4)
                    if(check())
                    {
                        strcpy(str,"It is impossible to beat me ");
                        strcat(str,name);
                        if(game>1)
                            strcat(str,", you couldn't beat me this time too, I won.");
                        else
                            strcat(str,", I won, you loose.");
                        puts(str);
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
                        strcpy(str,"\nOh, you won ");
                        strcat(str,name);
                        strcat(str," .\nCongratulations\nGreat work!\n\nMy algorithm needs to be improved.\nBie.");
                        puts(str);
                        exit(0);
                        break;
                    }
            }
            break;
        default:
            strcpy(str,"Hey, ");
            strcat(str,name);
            strcat(str," you need to enter either 1 or 2.");
            puts(str);
            cout<<"\nEnter again: ";
            goto input;
            break;
    }
    if(!check())
    {
        if(game>1)
            cout<<"Well Played!\nBut you couldn't beat me this time too\n";
        else
            cout<<"Well Played!\nIt is a tie.\n";

    }
    char c;
    strcpy(str,"Wanna play again ");
    strcat(str,name);
    strcat(str," y/n?");
    puts(str);
    cin>>c;
    if(c=='y'||c=='Y')
    {
        game++;
        main();
    }
    else
        exit(0);
    return 0;
}

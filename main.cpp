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

int a[3][3],t,y;

void again();

void print()
{
    int i,j;
    cout<<"\n";
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
            cout<<a[i][j]<<"\t";
        cout<<endl;
    }
}

int check()
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

void pin()
{
    int r=0,c=0;
    cout<<"Player turn: ";
    cin>>r>>c;
    r--;
    c--;
    if(r>2||c>2||r<0||c<0)
    {
        cout<<"Enter correct value."<<endl;
        pin();
    }
    else if(a[r][c]!=0)
    {
        cout<<"Already filled!\n";
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

int attack()
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

void ai(int b)
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
                cout<<"not attack";
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
start:
    cout<<"Choose your turn 1st or 2nd: ";
    cin>>t;
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
                        break;
                    }
            }
            break;
        default:
            cout<<"Enter correct choice.\n";
            goto start;
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
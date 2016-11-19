#include<stdio.h>
#include<windows.h>
#include<time.h>
int m;

void delay(unsigned int );
main()
{
    printf("ENTER MATRIX SIZE ");
    scanf("%d",&m);
    char c[m][m],c1[m][m];
    int i,j,move,posi=0,posj=0,p1=0,p2=0;;
    printf("\n\nYOU ARE @.\n# MEANS UNVISITED POINT.\nYOUR GOAL IS TO REACH %d,%d POINT\n\n!!!!GOOD LUCK!!!!",m,m);
    delay(5000);
    system("cls");
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
         {
            c[i][j]='#';
            c1[i][j]='#';
         }
    }
    c[0][0]='@';
    for(i=0;i<m;i++)
    {
        c1[i][rand()%m]='*';
        c1[i][rand()%m]='*';
        c1[i][rand()%m]='*';
        c1[i][rand()%m]='*';
    }
    if(c1[0][0]=='*')
        c1[0][0]='#';
    if(c1[m-1][m-1]=='*')
        c1[m-1][m-1]='#';
    for(i=0;i<m;i++)
    {
        int count=0,count1=0;
        for(j=0;j<m;j++)
        {
            if(c1[i][j]!='*')
                count=1;
            if(c1[j][i]!='*')
                count1=0;
        }
        if(count==0)
            c1[i][i]='#';
        if(count1==0)
            c1[i][j]='#';
    }
    system("COLOR E4");
    do
    {
        p1=posi;
        p2=posj;
    if(posi==(m-1) && posj==(m-1))
    {
        printf("!!!!GAME WON!!!!");
         for(i=0;i<m;i++)
        {
            printf("\n\n\t");
            for(j=0;j<m;j++)
                printf("%c\t",c1[i][j]);
        }
        delay(5000);
        exit(0);
    }
    system("cls");
    if(c1[0][1]=='*' && c1[1][0]=='*' && c1[1][1]=='*')
        c1[1][0]='#';
     for(i=0;i<m;i++)
        {
            printf("\n\n\t");
            for(j=0;j<m;j++)
                printf("%c\t",c[i][j]);
        }
    printf("\n1. UP\n2. DOWN\n3.LEFT\n4.RIGHT\nENTER MOVE ");
    scanf("%d",&move);
    if(move==1 && posi!=0)
    {
        c[posi][posj]=' ';
        posi--;
        if(c1[posi][posj]=='*')
        {
            printf("!!!!GAME LOST!!!!");
             for(i=0;i<m;i++)
            {
            printf("\n\n\t");
            for(j=0;j<m;j++)
                printf("%c\t",c1[i][j]);
            }
            delay(5000);
            exit(0);
        }
        else
        c[posi][posj]='@';
    }
    else if(move==2 && posi!=(m-1))
    {
        c[posi][posj]=' ';
        posi++;
        if(c1[posi][posj]=='*')
        {
            printf("!!!!GAME LOST!!!!");
             for(i=0;i<m;i++)
            {
            printf("\n\n\t");
            for(j=0;j<m;j++)
                printf("%c\t",c1[i][j]);
            }
            delay(5000);
            exit(0);
        }
        else
        c[posi][posj]='@';
    }
    else if(move==3 && posj!=0)
    {
        c[posi][posj]=' ';
        posj--;
        if(c1[posi][posj]=='*')
        {
            printf("!!!!GAME LOST!!!!");
             for(i=0;i<m;i++)
            {
            printf("\n\n\t");
            for(j=0;j<m;j++)
                printf("%c\t",c1[i][j]);
            }
            delay(5000);
            exit(0);
        }
        else
        c[posi][posj]='@';
    }
    else if(move==4 && posj!=(m-1))
    {
        c[posi][posj]=' ';
        posj++;
        if(c1[posi][posj]=='*')
        {
            printf("!!!!GAME LOST!!!!");
            for(i=0;i<m;i++)
            {
            printf("\n\n\t");
            for(j=0;j<m;j++)
                printf("%c\t",c1[i][j]);
            }
            delay(5000);
            exit(0);
        }
        else
        c[posi][posj]='@';
    }
    else
    {
        printf("\n\n!!!INVALID MOVE!!!");
        delay(2000);
        continue;
    }
    for(i=posi-1;i<=posi+1;i++)
    {
        if(i==-1 || i==m)
            continue;
        for(j=posj-1;j<=posj+1;j++)
        {
            if(j==-1 || j==m)
            continue;
            if(c1[i][j]!='*')
                c[i][j]=' ';
        }
    }
    c[posi][posj]='@';
    int count=0;
    for(i=posi-1;i<=posi+1;i++)
    {
        if(i==-1 || i==m)
            continue;
        for(j=posj-1;j<=posj+1;j++)
        {
            if(j==-1 || j==m)
            continue;
            if(c1[i][j]!='*' && i!=p1 && j!=p2)
                {
                    count++;
                    break;
                }
        }
        if(count==1)
            break;
    }
    if(count!=1)
    {
        if(posi==(m-1) || posi==0)
            c1[posi][posj+1]='#';
        else if(posj==(m-1) || posj==0)
            c1[posi+1][posj]='#';

    }
    }while(1);
}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define ll long long
void wait()
{
    for(ll int i = 0; i<100000000; i++) {}
}
int getwinner(char c, char cSelect)
{
    int player = 0, comp = 0;
    if (c == 'r' && cSelect == 'p')
    {
        printf("Computer Wins!!!..Paper wraps the Rock^*^\n");
        comp = 2;
        return comp;

    }
    else if (c == 'p' && cSelect == 's')
    {
        printf("Computer Wins!!!..Scissor cuts the paper^*^\n");
        comp = 2;
        return comp;
    }
    else if (c == 's' && cSelect == 'r')
    {
        printf("Computer Wins!!!..Rock destroy the Scissor^*^\n");
        comp = 2;
        return comp;
    }
    else if (c == 'r' && cSelect == 's')
    {
        printf("You Wins!!!..Rock destroy the Scissor^*^\n");
        player = 1;
        return player;
    }
    else if (c == 'p' && cSelect == 'r' )
    {
        printf("You Wins!!!..Paper wraps the Rock^*^\n");
        player = 1;
        return player;
    }
    else if (c == 's' && cSelect == 'p')
    {
        printf("You Wins!!!..Scissor cuts the paper^*^\n");
        player = 1;
        return player;

    }
    else
    {
        printf("Tie....No one gets point\n");
        return -1;
    }

}
int start_game(char c)
{
    srand(time(0));
    int comInput = rand()%3+1;
    char cSelect;
    if(comInput == 1)
    {
        cSelect = 'r';
        printf("Computers Choose:.... Rock ^.^\n");
    }
    else if(comInput == 2)
    {
        cSelect = 'p';
        printf("Computers Choose:.... Paper ^.^\n");
    }
    else if(comInput == 3)
    {
        cSelect = 's';
        printf("Computers Choose:.... Scissor ^.^\n");
    }

    int winner = getwinner(c, cSelect);
    if(winner == 1)
    {
        return 1;

    }
    if(winner == 2)
    {
        return 2;
    }
    else if(winner == -1)
    {
        return -1;
    }

}
void savescore(int p)
{
    int score;
    FILE *fptr,*fptrr;
    int cnt = 0;
    int a[5];
    fptr = fopen("rockpaperscissors.txt","r");
    while(!feof(fptr))
    {
        fscanf(fptr, "%d",&score );
        a[cnt] = score;
        cnt++;
    }

    fclose(fptr);
    int ind = -1;
    for(int i = 0; i<cnt-1; i++)
    {
        if(p>a[i])
        {
            ind = i;
        }
    }

    if(ind == -1 && cnt-1==0)
    {
        fptrr = fopen("rockpaperscissors.txt","w");
        fptrr = fopen("rockpaperscissors.txt","a");
        fprintf(fptrr,"%d\n",p);
        fclose(fptrr);

    }

    else if(ind >-1 && cnt-1!= 0)
    {
        for(int i=cnt-1; i>=ind; i--)
        {
            a[i] = a[i-1];
        }
        if(ind == 0)
        {
           a[ind]=p;
        }
        else a[ind-1] = p;
        if(cnt<6)
        {
            cnt++;
        }

        int temp;
        for(int i = 0; i<cnt-1; i++)
        {
            for(int j=i+1; j<cnt-1; j++)
            {
                if(a[i]<a[j])
                {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
        fptrr = fopen("rockpaperscissors.txt","w");
        fptrr = fopen("rockpaperscissors.txt","a");
        for(int i = 0; i<cnt-1; i++)
        {
            fprintf(fptrr,"%d\n",a[i]);
        }
        fclose(fptrr);
    }
}
void high_score()
{
    int score;
    FILE * fptr;
    fptr = fopen("rockpaperscissors.txt","r");
    int cnt = 0;
    int a[5];
    while(!feof(fptr))
    {
        fscanf(fptr,"%d",&score);
        a[cnt] = score;
        cnt++;
    }
    if(cnt-1==0){
      printf("\nOpps!! No record found. please make a high score...^.^\n\n");
    }
    int k = 1;
    for(int i = 0; i<cnt-1; i++)
    {
        printf("%d: %d\n",k,a[i]);
        k++;
    }
    printf("Back to main Menu");
    for(int i = 0; i<5; i++)
    {
        wait();
        printf(".");
    }
    printf("\n");
}

int main()
{
    printf("\t\t\t............Rock Paper Scissors Game.............\n");
    printf("\t\t\t............Choose Option.............\n");
    while(1)
    {
        printf("\t\t\t 1. Start Game\n");
        printf("\t\t\t 2. High Score\n");
        printf("\t\t\t 3. Exit\n");
        int opt;
        printf("Choose option: ");
        scanf("%d",&opt);
        printf("\n");
        if(opt == 1)
        {
            printf("Starting Game");
            for(int i = 0; i<5; i++)
            {
                wait();
                printf(".");
            }
            printf("\n");
            printf("Rock = r\nPaper = p\nScissors = s\n");
            printf("...Press any key to stop the game......\n");
            int player = 0, comp = 0;
            while (1)
            {
                char c;
                getchar();
                scanf("%c",&c);

                if(c == 'r')
                {

                    printf("You choose:....Rock^.^\n");
                    int res = start_game(c);
                    if(res == 1)
                    {
                        player++;
                    }
                    else if( res == 2)
                    {
                        comp++;
                    }
                }
                else if(c == 'p')
                {
                    printf("You choose:....Paper^.^\n");
                    int res = start_game(c);
                    if(res == 1)
                    {
                        player++;
                    }
                    else if( res == 2)
                    {
                        comp++;
                    }
                }
                else if(c=='s')
                {
                    printf("You choose:....Scissor^.^\n");
                    int res = start_game(c);
                    if(res == 1)
                    {
                        player++;
                    }
                    else if( res == 2)
                    {
                        comp++;
                    }
                }

                else
                {
                    savescore(player);
                    if(player>comp)
                    {

                        printf("\nPlayer Win. Player score: %d", player);
                        printf("\n");
                    }
                    else if(player<comp)
                    {
                        printf("\nComputer Win. Computer score: %d", comp);
                        printf("\n");
                    }
                    else
                    {
                        printf("\nTie!! Nobody win.\n");
                    }
                    printf("Returning to main menu");
                    for(int i = 0; i<5; i++)
                    {
                        wait();
                        printf(".");
                    }
                    printf("\n");
                    break;
                }

            }

        }
        else if(opt == 2)
        {
            printf("Opening high Score");
            for(int i = 0; i<5; i++)
            {
                wait();
                printf(".");
            }
            printf("\n");
            high_score();
        }
        else if(opt == 3)
        {
            printf("Closing game");
            for(int i = 0; i<5; i++)
            {
                wait();
                printf(".");
            }
            printf("\n");
            break;
        }
        else
        {

            printf("Wrong press. Please try again");
            for(int i = 0; i<5; i++)
            {
                wait();
                printf(".");
            }
            printf("\n");
        }

    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "All_Fcts.h"
#include <time.h>

struct joueur joueur,machine;


void choose_first2(void)//tirage au sort
{

    int n=random_entre_deux_int(1,2);
    if (n==1)
    {
        joueur.id=1;
        machine.id = 2;
        printf("\n                                     Joueur>>:start first with black pion!\n");
    }
    else
    {
        machine.id=1;
        joueur.id = 2;
        printf("\n                                     Machine>>start first with black pion!\n");
    }
}

void Joueur_Ordinateur(int index)

{
    int bt=0;
    int wt=0;
    int BLACK[81]= {0};
    int WHITE[81]= {0};
    //adversaire=(player==1)?2:1;
    int s=ko_prevent();
Refaire4:
    {
        color(7,0);
        affiche_grille();

        printf("\n                                     |-->Joueur:your turn!\n");

        printf("                                     |->votre choix d'indice i>>");
        if (s==1)
        {
            color(4,0);
            printf("\n                                     |==>warnning!!ko\n");
            color(7,0);
            system("pause");
            system("cls");
            s=0;
            goto Refaire4;

        }
        srand(time(NULL));

        index=random_entre_deux_int(80,0);
        if((index<0)||(index>80))
        {
            if(index==404)
            {
                printf("                                     |==>voulez vous vraiment quiter?[ 1 = YES ] [ anything else = NO ]");
                printf("\n                                      1) OUI    2) NON -->");
                scanf("%d",&index);
                if (index==1)
                {
                    system("cls");
                    affichage_menu();

                    exit(0);
                }
                else
                {
                    system("cls");
                    goto Refaire4 ;
                }

            }
            else if (index==505)
            {
                player=(player==1)?2:1;
                system("cls");
                goto Refaire4;
            }
            color(4,0);
            printf("                                     |==>warnning!!donne une indice entre 0 et 80!\n");

            system("cls");
            goto Refaire4;
        }
        else if (position_vide(index)==0)
        {
            color(4,0);
            printf("                                     |==>warnning!!occupied position\n");
            system("cls");
            goto Refaire4;
        }
        else if (Suicide(index)==1)
        {
            color(4,0);
            printf("                                     |==>warnning!!suicide\n");

            system("cls");
            goto Refaire4;
        }

    }
    M[index]=player;
    adversaire=(player==1)?2:1;
    for (int j=0; j<81; j++)
    {
        if(M[j]==adversaire)//to decrease the complexity & make sure that the captured pions belong to the adverse
            capture_group(j);
    }
    for (int j=0; j<81; j++)
    {
        int visited1[81]= {0};
        int visited2[81]= {0};

        territory_found=1;
        territory(j,visited1,1);
        if(territory_found==1)
        {
            for (int k=0; k<81; k++)
            {
                if(visited1[k]==1)
                {
                    BLACK[k]=visited1[k];
                }

            }
        }
        territory_found=1;
        territory(j,visited2,2);
        if(territory_found==1)
        {
            for (int k=0; k<81; k++)
            {
                if(visited1[k]==1)
                {
                    WHITE[k]=visited2[k];
                }

            }
        }

    }

    for(int i=0; i<81; i++)
    {
        if(BLACK[i]==1)
            bt++;
        if(WHITE[i]==1)
            wt++;
    }


    black_territory=bt;
    white_territory=wt;

}

void Joueur_Humain(int index)
{
    int BLACK[81]= {0};
    int WHITE[81]= {0};
    int s=ko_prevent();
    int bt=0,wt=0;
Refaire7:
    {
        instructions_2();


        color(7,0);
        affiche_grille();

        printf("\n                                     |-->Joueur :your turn!\n");

        printf("                                     |->votre choix d'indice i>>");
        if (s==1)
        {
            color(4,0);
            printf("\n                                     |==>warnning!!ko\n");
            color(7,0);
            system("pause");
            system("cls");
            s=0;
            goto Refaire7;

        }
        scanf("%d",&index);

        if((index<0)||(index>80))
        {
            if(index==404)
            {
                color(4,0);
                printf("                                     |==>voulez vous vraiment quiter?[ 1 = YES ] [ anything else = NO ]");
                printf("\n                                      1) OUI    2) NON -->");
                color(7,0);
                scanf("%d",&index);
                if (index==1)
                {
                    system("cls");
                    Final_Score();

                    exit(0);
                }
                else
                {
                    system("cls");
                    goto Refaire7 ;
                }

            }
            else if (index==505)
            {
                player=(player==1)?2:1;
                system("cls");
                goto Refaire7;
            }
            color(4,0);
            printf("                                     |==>warnning!!donne une indice entre 0 et 80!\n");

            system("cls");
            goto Refaire7;
        }
        else if (position_vide(index)==0)
        {
            color(4,0);
            printf("                                     |==>warnning!!occupied position\n");
            system("cls");
            goto Refaire7;
        }
        else if (Suicide(index)==1)
        {
            color(4,0);
            printf("                                     |==>warnning!!suicide\n");

            system("cls");
            goto Refaire7;
        }

    }

    M[index]=player;
    adversaire=(player==1)?2:1;
    for (int j=0; j<81; j++)
    {
        if(M[j]==adversaire)//to decrease the complexity & make sure that the captured pions belong to the adverse
            capture_group(j);
    }

    for (int j=0; j<81; j++)
    {
        int visited1[81]= {0};
        int visited2[81]= {0};

        territory_found=1;
        territory(j,visited1,1);
        if(territory_found==1)
        {
            for (int k=0; k<81; k++)
            {
                if(visited1[k]==1)
                {
                    BLACK[k]=visited1[k];
                }

            }
        }
        territory_found=1;
        territory(j,visited2,2);
        if(territory_found==1)
        {
            for (int k=0; k<81; k++)
            {
                if(visited1[k]==1)
                {
                    WHITE[k]=visited2[k];
                }

            }
        }

    }

    for(int i=0; i<81; i++)
    {
        if(BLACK[i]==1)
            bt++;
        if(WHITE[i]==1)
            wt++;
    }


    black_territory=bt;
    white_territory=wt;


}

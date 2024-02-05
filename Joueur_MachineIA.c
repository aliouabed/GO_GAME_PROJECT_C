#include <stdio.h>
#include <stdlib.h>
#include "All_Fcts.h"
#include <time.h>




void Joueur_OrdinateurIA(int index)
{
    int BLACK[81]= {0};
    int WHITE[81]= {0};
    int s=ko_prevent();
    int bt=0,wt=0;
Refaire9:
    {


        color(7,0);
        affiche_grille();

        printf("\n                                     |-->Joueur:your turn!\n");

        printf("                                     |-1>votre choix d'indice i>>");
        if (s==1)
        {
            color(4,0);
            printf("\n                                     |==>warnning!!ko\n");
            color(7,0);
            system("pause");
            system("cls");
            s=0;
            goto Refaire9;

        }
        if(machine_capture()!=-1)
            index=machine_capture();
        else if(save_group()!=-1)
            index=save_group();
        else if(surround()!=-1)
            index=surround();


        else
        {
            srand(time(NULL));
            index=random_entre_deux_int(80,0);
        }


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
                    goto Refaire9 ;
                }

            }
            else if (index==505)
            {
                player=(player==1)?2:1;
                system("cls");
                goto Refaire9;
            }
            color(4,0);
            printf("                                     |==>warnning!!donne une indice entre 0 et 80!\n");

            system("cls");
            goto Refaire9;
        }
        else if (position_vide(index)==0)
        {
            color(4,0);
            printf("                                     |==>warnning!!occupied position\n");
            system("cls");
            goto Refaire9;
        }
        else if (Suicide(index)==1)
        {
            color(4,0);
            printf("                                     |==>warnning!!suicide\n");

            system("cls");
            goto Refaire9;
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




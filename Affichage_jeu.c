#include <stdio.h>
#include <stdlib.h>
#include "All_Fcts.h"
#include <windows.h>


void color(int text_color, int bg_color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int color = text_color + (bg_color * 16);
    SetConsoleTextAttribute(hConsole, color);
}

void instructions_1()
{
    color(6,0);
    printf("   --------------------------------------");
    printf("\n   |  404 to exit   | |  505  to pass   | \n");
    color(7,0);
    printf("   -----------------------------------------------------------------------");

    if(joueur1.id==1)
    {
        color(11,0);

        printf("\n   |  player_%d:%s  | | black_stones:%d   | capture %d  | black_territory:%d  \n",joueur1.id,joueur1.nom,count_stones(1),count_captured_white,black_territory);
        printf("   -------------------------------------------------------------------------");
    }

    else
    {
        color(2,0);

        printf("\n   |  player_%d:%s  | | white_stones: %d   | capture %.1f | white_territory:%d\n",joueur1.id,joueur1.nom,count_stones(2),count_captured_black,white_territory);
        printf("   -----------------------------------------------------------------------");
    }

    if(joueur2.id==1)
    {
        color(11,0);

        printf("\n   |  player_%d:%s  | | black_stones: %d   | capture %d | black_territory:%d \n",joueur2.id,joueur2.nom,count_stones(1),count_captured_white,black_territory);
        printf("   -----------------------------------------------------------------------");
    }

    else
    {
        color(2,0);

        printf("\n   |  player_%d:%s  | | black_stones: %d   | capture %.1f | white_territory:%d\n",joueur2.id,joueur2.nom,count_stones(2),count_captured_black,white_territory);
        printf("    -----------------------------------------------------------------------");
    }
    //*******************************************

    color(7,0);
}
void instructions_2()
{
    color(6,0);
    printf("   --------------------------------------");
    printf("\n   |  404 to exit   | |  505  to pass   | \n");
    color(7,0);
    printf("   -----------------------------------------------------------------------");
    if(joueur.id==1)
    {
        color(11,0);

        printf("\n   |  player  | | black_stones:%d   | capture: %d | black_territory:%d  \n",count_stones(1),count_captured_white,black_territory);
        printf("   -----------------------------------------------------------------------");
    }

    else
    {
        color(2,0);

        printf("\n   |  player  | | white_stones: %d   |  capture: %.1f | white_territory:%d\n",count_stones(2),count_captured_black,white_territory);
        printf("   -----------------------------------------------------------------------");
    }
    if(machine.id==1)
    {
        color(11,0);

        printf("\n   |  machine  | | black_stones:%d   | capture: %d | black_territory:%d  \n",count_stones(1),count_captured_white,black_territory);
        printf("   -----------------------------------------------------------------------");
    }

    else
    {
        color(2,0);

        printf("\n   |  machine  | | white_stones: %d   |  capture: %.1f | white_territory:%d\n",count_stones(2),count_captured_black,white_territory);
        printf("   -----------------------------------------------------------------------");
    }
    color(7,0);
}
void affichage_menu()
{
    color(14,0);
    printf("                          ________________________\n");
    printf("\n                          |BIENVENUE AU TSUME_GO!|");
    printf("\n                          ________________________\n\n");
    printf("\t                           _______________________\n");
    printf("\t                          |                       | \n");
    printf("\t                          |    1 >   P L A Y      |\n");
    printf("\t                          |_______________________|\n");
    printf("\t                           _______________________\n");
    printf("\t                          |                       | \n");
    printf("\t                          |    2 >   R U L E S    |\n");
    printf("\t                          |_______________________|\n");
    printf("\t                           _______________________\n");
    printf("\t                          |                       | \n");
    printf("\t                          |    3 >   E X I T      |\n");
    printf("\t                          |_______________________|\n");
    color(11,0);
    printf("\n\n                           |-->Entrer votre choix:");
    scanf("%d",&choix);

    color(7,0);

}
void rules(void)
{
    printf("1.1 Regles generales \n1. Le go se joue a deux joueurs. \n2. Un joueur joue avec les pierres noires, l’autre avec les pierres blanches. Les joueurs jouent leurs coups un par un par un a tour de role. \n3. Un coup consiste a placer une pierre sur une intersection du quadrillage. Les pierres peuvent egalement etre placees sur les bords de celui-ci. \n4. Une fois qu’une pierre est placee sur une intersection, elle ne peut plus etre deplacee. \n5. Quand il y a une difference de force entre les deux adversaires, le joueur le plus faible place des pierres supplementaires sur le plateau pour compenser cette difference de niveau. \n6. Dans une partie e egalite, le joueur ayant les pierres noires joue toujours le premier, mais dans une partie à handicap, c’est le Blanc qui commence. \n");

}
void affiche_grille(void)
{
    color(4,0);

    printf("#TSUME_GO#\n");
    color(7,0);
    printf("                                           A      B      C      D      E      F      G      H      I\n\n");
    //instructions();
    for(int i=0; i<81; i++)
    {

        if(i%9==0)
        {
            printf("                                      %d   ",i/9);

            for(int j=i; j<i+9; j++)
            {
                if (M[j]==0)
                {
                    if(j<10)
                        if (j!=9)
                        {

                            printf(" %d",j);

                        }

                        else
                        {

                            printf("%d ",j);

                        }


                    else
                    {
                        printf("%d",j);

                    }


                }
                if (M[j]==1)
                {
                    if(j<10)
                    {
                        if (j!=9)
                        {
                            color(0,11);
                            printf(" %d",j);
                            color(7,0);
                        }
                        else
                        {
                            color(0,11);
                            printf("%d ",j);
                            color(7,0);
                        }

                    }
                    else
                    {
                        color(0,11);
                        printf("%d",j);
                        color(7,0);
                    }


                }
                if (M[j]==2)
                {
                    if(j<10)
                    {
                        if (j!=9)
                        {
                            color(0,2);
                            printf(" %d",j);
                            color(7,0);
                        }
                        else
                        {
                            color(0,2);
                            printf("%d ",j);
                            color(7,0);
                        }

                    }
                    else
                    {
                        color(0,2);
                        printf("%d",j);
                        color(7,0);
                    }

                }
                if (j!=i+8)
                    printf(" ----");


            }
            printf("\n");
        }

        else
        {
            if ((i<=72)&&(i%3==0))
            {
                printf("                                           ");
                for(int j=0; j<9; j++)
                {
                    printf("| ");
                    if (j!=8)
                        printf("     ");
                }
                printf("\n");



            }
        }
    }
}

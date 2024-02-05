#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "All_Fcts.h"

int choix;
int index;
int player;
int adversaire;
int M[81]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
           };

int main()
{

Refaire1:
    {
        system("cls");
        affichage_menu();

        switch(choix)
        {
        case 1:
        {
Refaire2:
            {
                system("cls");
                color(14,0);
                printf("\n\n\t                            _______________________\n");
                printf("\t                           |                       | \n");
                printf("\t                           |  1>Joueur vs Joueur   |\n");
                printf("\t                           |_______________________|\n");
                printf("\t                            _______________________\n");
                printf("\t                           |                       | \n");
                printf("\t                           |  2 >Joueur VS Machine |\n");
                printf("\t                           |_______________________|\n");
                printf("\t                            _______________________\n");
                printf("\t                           |                       | \n");
                printf("\t                           |   3 >return to menu   |\n");
                printf("\t                           |_______________________|\n");
                color(11,0);
                printf("\n\n\n\t                           |-->votre choix est:");
                scanf("%d",&choix);
                if(choix<1 || choix>3)
                {
                    printf("          hors liste de choix!!\n");
                    system("pause");
                    goto Refaire2;
                }
            }
            if(choix==1)
            {
                system("cls");
                joueur_information();
                choose_first();
                system("pause");



                do
                {
                    system("cls");
                    Joueur_VS_Joueur(index);

                    pass();

                }
                while(1);
            }
            if(choix==2)
            {
                system("cls");
Refaire6:
                {
                    system("cls");
                    color(14,0);
                    printf("\n\n\t                            _______________________\n");
                    printf("\t                           |                       | \n");
                    printf("\t                           |  1>FACILE             |\n");
                    printf("\t                           |_______________________|\n");
                    printf("\t                            _______________________\n");
                    printf("\t                           |                       | \n");
                    printf("\t                           |  2 >MOYEN             |\n");
                    printf("\t                           |_______________________|\n");
                    printf("\t                            _______________________\n");
                    printf("\t                           |                       | \n");
                    printf("\t                           |   3 >return to menu   |\n");
                    printf("\t                           |_______________________|\n");
                    color(11,0);
                    printf("\n\n\n\t                           |-->votre choix est:");
                    scanf("%d",&choix);

                    if(choix<1 || choix>3)
                    {

                        color(4,0);
                        printf("          hors liste de choix!!\n");
                        color(7,0);
                        system("pause");
                        goto Refaire6;
                    }
                    //////////////////////////////////////j vs m//////////////////////////
                    if(choix==1)
                    {

                        system("cls");
                        choose_first2();


                        do
                        {
                            system("cls");

                            if (player==machine.id)
                            {
                                Joueur_Ordinateur(index);
                            }
                            if (player==joueur.id)
                            {
                                Joueur_Humain(index);
                            }


                            pass();

                        }
                        while(1);

                    }
                    if(choix==2)
                    {

                        system("cls");
                        choose_first2();


                        do
                        {
                            system("cls");

                            if (player==machine.id)
                            {
                                Joueur_OrdinateurIA(index);
                            }
                            if (player==joueur.id)
                            {
                                Joueur_Humain(index);
                            }


                            pass();

                        }
                        while(1);

                    }
                }
                if(choix==3)
                {
                    goto Refaire1;
                }
            }
            if(choix==3)
            {
                goto Refaire1;
            }




            break;
        }

        case 2:
        {
            system("cls");
            rules();
            printf("          >>return to menu\n");
            system("pause");
            goto Refaire1;
            break;
        }
        case 3:
        {

            system("cls");
            color(4,0);
            printf("\n\n\n          >>>voulez-vous vraiment quiter?\n");
            printf("          1)Oui                2)Non \n");
            color(11,0);
            printf("          votre choix est:");
            scanf("%d",&choix);
            if (choix==1)
                exit(0);
            if (choix==2)
            {
                system("cls");
                goto Refaire1;
            }
            break;
        }
        default:
        {
            color(4,0);
            printf("          svp votre choix est hors liste!!\n");
            system("pause");
            system("cls");
            goto Refaire1;
            break;
        }
        }



    }
    return 0;
}







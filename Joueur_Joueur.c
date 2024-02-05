#include <stdio.h>
#include <stdlib.h>
#include "All_Fcts.h"
#include <time.h>



struct joueur joueur1,joueur2;
int player=1;//le noir joue tjrs premierement
int before_move1_M[81];//pour enregistrer le goban
int after_move1M[81];
int after_move2M[81];
int is_KO=0; //initialiser par zero car on a pas le ko en premier joue
int black_territory=0;
int white_territory=0;
int before_pass1_M[81]= {9};//si les deux joueur ont decide de resigner donc la fin de jeu
int after_pass2_M[81]= {9};


//random nb entre 2 int
int random_entre_deux_int(int max,int min)
{
    srand(time(NULL));//ensures that a different seed value will be used each time the program runs
    return rand()%(max-min)+min+1;;/*The % 2 operation restricts the range of the generated number
                                       to 0 or 1, and adding 1 maps it to the desired range of [1, 2].*/
}

//si les deux joueurs decide de faire un passes successivement
int End_game(int G[81],int H[81])
{
    for (int i=0; i<81; i++)
    {
        if(G[i]!=H[i])
            return 0;
    }
    return 1;
}

//les info autour les deux joueurs
void joueur_information(void)
{
    color(14,0);
    printf("\n\n                          |=>Veuillez saisir le nom du premier joueur |->:");
    scanf("%s",joueur1.nom);
    printf("\n\n                                     |=>Veuillez saisir le nom du deuxieme joueur |->:");
    scanf("%s",joueur2.nom);

}
///////////choix aleatoire du premier joueur
void choose_first(void)
{
    color(11,0);
    int n=random_entre_deux_int(2,1);
    if (n==1)
    {
        joueur1.id=1;
        joueur2.id = 2;
        printf("\n\n\n                          Joueur%d>>%s:start first with black pion! ",joueur1.id,joueur1.nom);
        color(11,11);
        printf("  \n");
        color(7,0);
    }
    else
    {
        joueur2.id=1;
        joueur1.id = 2;
        printf("\n\n\n                          Joueur%d>>%s:start first with black pion!",joueur2.id,joueur2.nom);
        color(11,11);
        printf("  \n");
        color(7,0);
    }
}

//organiser les tours de chaque joueur
void pass(void)
{

    player=(player==1)? 2:1;

}

void Final_Score()
{
    float sum_black=0;
    float sum_white=0;
    sum_black=count_captured_white+count_stones(1)+black_territory;
    sum_white=count_captured_black+count_stones(2)+white_territory;
    if(sum_black>sum_white)
    {
        color(2,0);
        printf("\n\n\n\n\n\t\t black won with %.2f",sum_black-sum_white);
        color(7,0);
    }
    else
    {
        color(11,0);
        printf("\n\n\n\n\n\t\t white won with %.2f",sum_white-sum_black);
        color(7,0);
    }
}


void Joueur_VS_Joueur(int index)
{
    int bt=0;//variable locale pour nous aider a calculer le territoire du noir
    int wt=0;//variable locale pour nous aider a calculer le territoire du blanc
    int BLACK[81]= {0};
    int WHITE[81]= {0};




    is_KO=ko_prevent();//is_KO vaut 0 si on a pas de ko ,1 sinon

Refaire3:
    {
        for (int j=0; j<81; j++)//enregistrer le goban pour definir la situation de resignation de deux jrs
        {
            before_pass1_M[j]=after_pass2_M[j];
            after_pass2_M[j]=M[j];

        }

        instructions_1();//affiche le tableau de resultat/comment faire passe ou exit
        color(7,0);
        affiche_grille();//affiche le goban
        if (player==joueur1.id&&joueur1.id==1)//pour connaitre le tour de qui?
        {
            color(11,0);
            printf("\n                                     |-->Joueur%d '%s':your turn!\n",joueur1.id,joueur1.nom);
        }
        if (player==joueur1.id&&joueur1.id==2)
        {
            color(2,0);
            printf("\n                                     |-->Joueur%d '%s':your turn!\n",joueur1.id,joueur1.nom);
        }

        if (player==joueur2.id&&joueur2.id==1)
        {
            color(11,0);
            printf("\n                                     |-->Joueur%d '%s':your turn!\n",joueur2.id,joueur2.nom);
        }
        if (player==joueur2.id&&joueur2.id==2)
        {
            color(2,0);
            printf("\n                                     |-->Joueur%d '%s':your turn!\n",joueur2.id,joueur2.nom);
        }
        color(7,0);


        printf("                                     |->votre choix d'indice i>>");
        if (is_KO==1)//si on a un ko
        {
            color(4,0);

            printf("\n                                     |==>warnning!!ko\n");
            color(7,0);
            system("pause");
            system("cls");
            is_KO=0;//l'indice vient avant le teste de ko /read the code from bottom to head
            goto Refaire3;

        }
        scanf("%d",&index);
        if((index<0)||(index>80))
        {
            if(index==404)//pour faire sourtir de jeu
            {
                color(4,0);

                printf("                                     |==>voulez vous vraiment quiter?[ 1 = YES ] [ anything else = NO ]");
                printf("\n                                      1) OUI    2) NON -->");
                color(7,0);
                scanf("%d",&index);
                if (index==1)
                {
                    system("cls");
                    Final_Score();//affiche le gagnant
                    printf("\t\t\t\n\n");
                    system("pause");
                    system("cls");
                    exit(0);
                }
                else
                {

                    system("cls");
                    goto Refaire3 ;
                }

            }
            else if (index==505)
            {
                pass();
                if(End_game(before_pass1_M,after_pass2_M)==1)// 2 passes==end game
                {
                    system("cls");
                    Final_Score();
                    printf("\t\t\t\n\n");
                    system("pause");
                    system("cls");
                    exit(0);
                }
                else
                {
                    system("cls");
                    goto Refaire3;
                }


            }
            color(4,0);

            printf("                                     |==>warnning!!donne une indice entre 0 et 80!\n");

            system("pause");
            system("cls");
            goto Refaire3;
        }
        else if (position_vide(index)==0)//non vide si 0/1 sinon
        {
            color(4,0);

            printf("                                     |==>warnning!!occupied position\n");
            system("                                     pause");
            system("cls");
            goto Refaire3;
        }
        else if (Suicide(index)==1)
        {
            color(4,0);
            printf("                                     |==>warnning!!suicide\n");

            system("pause");
            system("cls");
            goto Refaire3;
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
        int visited1[81]= {0};//sauvgarder les amis des positions vide de chaque j appartiennent  a player 1
        int visited2[81]= {0};//sauvgarder les amis des positions vide de chaque j appartiennent  a player 2

        territory_found=1;
        territory(j,visited1,1);//remplir visited1 et changer la valeur de territory_found si on a pas de territoire
        if(territory_found==1)//si on a un territoire de black(player 1)
        {
            for (int k=0; k<81; k++)
            {
                if(visited1[k]==1)//pour eviter de remplir les indices de BLACK qui vaut 1 par 0(on cherche le total sans redondance)
                {
                    BLACK[k]=visited1[k];//remplir la matrice BLACK par les 1 des amis de chaque j
                }

            }
        }
        territory_found=1;
        territory(j,visited2,2);//remplir visited2 et changer la valeur de territory_found si on a pas de territoire
        if(territory_found==1)
        {
            for (int k=0; k<81; k++)
            {
                if(visited1[k]==1)//pour eviter de remplir les indices de WHITE qui vaut 1 par 0(on cherche le total sans redondance)
                {
                    WHITE[k]=visited2[k];
                }

            }
        }

    }

    for(int i=0; i<81; i++)
    {
        if(BLACK[i]==1)//les positions appartient au noir territoire
        {
            bt++;

        }

        if(WHITE[i]==1)//les positions appartient au blanc territoire
        {
            wt++;
        }

    }


    black_territory=bt;
    white_territory=wt;







}









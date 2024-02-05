#include <stdio.h>
#include <stdlib.h>
#include "All_Fcts.h"

int adversaire;
int before_move1_M[81]= {9};//pour eviter le ko pour la premiere fois(eviter initialisation par 0)
int after_move1M[81]= {9};
int after_move2M[81]= {9};
int ko=0;//pour la premiere fois on a pas de ko
float count_captured_black=6.5;//komi en jeu de go(belong to white)
int count_captured_white=0;
int territory_found;//on a un territoire ou non


int position_vide(int i)
{
    if ((M[i]==1)||(M[i]==2))
    {
        return 0;
    }
    else if (M[i]==0)
    {
        return 1;
    }
}

//l'emplacements de pion % une position donner
int position_haut(int i)
{
    if(i>8)

        return i-9;
    else
        return -1;

}
int position_bas(int i)
{
    if (i<72)

        return i+9;
    else
        return -1;

}
int position_droit(int i)
{
    if((i%9)!=8)

        return i+1;
    else
        return -1;

}
int position_gauche(int i)
{
    if((i%9)!=0)

        return i-1;
    else
        return -1;

}

/*check-group_lib:The check_group function is called recursively to
traverse the group and mark all stones as checked and calculate liberte degre
of every position(0 si position vide 1 sinon)*/

void check_group_lib(int i,int M[81],int checked[81],int liberte[81])
{
    if (M[i]!=0)//position non vide
    {
        checked[i]=1;//deja traite pour eviter la boucle infinie
        int h,b,g,d;
        h=position_haut(i);
        b=position_bas(i);
        g=position_gauche(i);
        d=position_droit(i);

        if(h!=-1 && M[h]==0)//tester l'existance de la position et est ce qu'elle  vide?
            liberte[h]=1;//si h vide :la position h dans liberte prend la valeur 1
        if(h!=-1 && M[h]==M[i]&&checked[h]==0)
        {
            /*la position haut existe dans le goban et remplie par une
            pion(soit noir soit blanche et cette position n'est pas parcourie auparavant.*/

            checked[h]=1;//mark this position as checked
            check_group_lib(h,M,checked,liberte);
        }//de mm pour ces positions
        if(b!=-1 && M[b]==0)
            liberte[b]=1;
        if(b!=-1 && M[b]==M[i]&&checked[b]==0)
        {
            checked[b]=1;
            check_group_lib(b,M,checked,liberte);
        }
        if(d!=-1 && M[d]==0)
            liberte[d]=1;
        if(d!=-1 && M[d]==M[i]&&checked[d]==0)
        {
            checked[d]=1;
            check_group_lib(d,M,checked,liberte);
        }
        if(g!=-1 && M[g]==0)
            liberte[g]=1;
        if(g!=-1 && M[g]==M[i]&&checked[g]==0)
        {
            checked[g]=1;
            check_group_lib(g,M,checked,liberte);
        }
    }
}
//calcule le degre de liberte d'un grp
int count_liberte(int liberte[81])
{
    int sum_degre=0;
    for(int j=0; j<81; j++)
    {
        sum_degre+=liberte[j];
    }
    return sum_degre;
}
//capture case
void capture_group(int i)
{

    int checked[81]= {0};//deja traite
    int liberte[81]= {0};//sauvgarder la liberte de groupe des amis de l'intersection i
    int sum_degre=0;//calculate the total degre of liberte of grp


    check_group_lib(i,M,checked,liberte);// find all stones in the group(les amis de i)

    sum_degre=count_liberte(liberte);//calculer le degre de liberte de group de i

    if(sum_degre==0)  //if the grp is surrounded
    {
        if (M[i]==2)//white pions
        {
            for (int j = 0; j < 81; j++)
            {
                if (checked[j] == 1)     //ami du pion i
                {
                    M[j] = 0;  //remove it
                    count_captured_white++;
                }
            }
        }
        if (M[i]==1)//black pion
        {

            for (int j = 0; j < 81; j++)
            {
                if (checked[j] == 1)     //friend of pion i
                {
                    M[j] = 0;  //remove it
                    count_captured_black++;

                }
            }
        }
    }

}

//suicide case:pour definir suicide on definit non suicide cas
int Suicide(int i)
{
    int G[81];//matrice nous aide a supposer que le joueur a joue et tester l'effet de cette move(imaginaire)
    int sum_degre=0;//calculate the total degre of liberte of grp
    int h,g,b,d;
    int checked[81]= {0};//deja traite
    int liberte[81]= {0};
    h=position_haut(i);
    b=position_bas(i);
    g=position_gauche(i);
    d=position_droit(i);
    if ((d!=-1&&M[d]==0)||(h!=-1&&M[h]==0)||(g!=-1&&M[g]==0)||(b!=-1&&M[b]==0))//il y a une degre de liberte apart i(position vide adjacent de i)
        return 0;
    for (int j=0; j<81; j++)
    {
        G[j]=M[j];
    }
    G[i]=player;//on suppose que le joueur a joue
    adversaire=(player==1)?2:1;//le joueur adversaire

    check_group_lib(i,G,checked,liberte);//regroupe les amis(et leur deg de liberte) de de i apres on suppose que le joueur deja joue
    sum_degre=count_liberte(liberte);//calculer le drgre de liberte de group de i

    if(sum_degre>=1)//une position vide apart la position qu'on a supposer que le joueuer  choisissait
    {
        return 0;//not suicide
    }
    else//le degre de liberte de groupe vaut 0(ms tester si on va capturer un group d'adversaire?)
    {
        for (int j=0; j<81; j++)//parcourer le goban (on a supposer que le jour deja deplasser un pion dans la position i)
        {
            int checked[81]= {0};
            int liberte[81]= {0};
            if(G[j]==adversaire)
            {
                check_group_lib(j,G,checked,liberte);//l'effet de cette move sur un groupe d'adversaire?
                if(count_liberte(liberte)==0)//si elle annule le degre de lib d'un grp d'adversaire (for capture)
                {
                    return 0;
                }

            }
        }

    }
    return 1;

}

//tester si on a un KO ou non
int ko_move(int pre_M[81],int after_M[81])
{
    for(int j=0; j<81; j++)
    {
        if(after_M[j]!=pre_M[j])
            return 0;
    }
    return 1;
}


int ko_prevent()//pour faire un marche ariere et restaurer le goban
{

    if(ko==0)//to save the goban situation each time
    {
        for(int j=0; j<81; j++)
        {
            before_move1_M[j]=after_move1M[j];
            after_move1M[j]=after_move2M[j];
            after_move2M[j]=M[j];
        }


    }
    ko=ko_move(before_move1_M,M);//1 si les deux matrice sont egaux 0 sinon
    if(ko==1)
    {
        color(4,0);
        player=(player==1)?2:1;//to give the player another chance to play again

        for(int j=0; j<81; j++)
        {

            M[j]=after_move1M[j];//faire une marche arriere pour restaurer le goban situation apres player1 a fait sa move
            after_move2M[j]=before_move1_M[j];


        }
        if(player==1)
            count_captured_white-=1;//on ajoute un point au player qui traverse un cas de ko donc on doit le rejeter
        if(player==2)
            count_captured_black-=1;//on ajoute un point au player qui traverse un cas de ko donc on doit le rejeter


    }
    return ko;
}
//calculer le nombre de stones in the board
int count_stones(int player)
{
    int sum;
    for (int p = 0; p < 81; p++)
    {
        if (M[p]== player)
        {
            sum++;
        }
    }
    return sum;
}

//accumuler les intersections vide qui appartient au meme groupe
void territory(int i,int visited[81],int color)//color to definir le territoire de qui?
{
    adversaire=(color==1)?2:1;//le joueur adversaire
    if (M[i]==0)
    {
        visited[i]=1;//mark it as checked
        int h,b,g,d;
        h=position_haut(i);
        b=position_bas(i);
        g=position_gauche(i);
        d=position_droit(i);

        if(h!=-1 && M[h]==0&&visited[h]==0)//position existe et non encore traite

        {
            visited[h]=1;//mark this position as checked
            territory(h,visited,color);
        }
        if(h!=-1&&M[h]==adversaire)//si on rencontre un pion d'adversaire lors de parcours
            territory_found=0;//in this case no territory is founded
        if(b!=-1 && M[b]==0&&visited[b]==0)

        {
            visited[b]=1;//mark this position as checked
            territory(b,visited,color);
        }
        if(b!=-1&&M[b]==adversaire)
            territory_found=0;
        if(d!=-1 && M[d]==0&&visited[d]==0)

        {
            visited[d]=1;//mark this position as checked
            territory(d,visited,color);
        }
        if(d!=-1&&M[d]==adversaire)
            territory_found=0;
        if(g!=-1 && M[g]==0&&visited[g]==0)

        {
            visited[g]=1;//mark this position as checked
            territory(g,visited,color);
        }

        if(g!=-1&&M[g]==adversaire)
            territory_found=0;

    }
    else
        territory_found=0;

}

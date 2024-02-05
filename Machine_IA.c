#include <stdio.h>
#include <stdlib.h>
#include "All_Fcts.h"

int machine_capture()
{
    for (int i=0; i<81; i++)
    {
        int checked[81]= {0};
        int liberte[81]= {0};

        if(M[i]==joueur.id)//les pions d'adversaire
        {
            check_group_lib(i,M,checked,liberte);//calculer la liberter of chaque groupe du joueur dans le goban
            if(count_liberte(liberte)==1) //si on a un groupe d'adversaire a juste un seul deg de liberte donc essaye de captuer ce grp
            {
                for(int k=0; k<81; k++)
                {
                    if((liberte[k]==1)&&(Suicide(k)==0))//vient a cette intersection et capturer le grp
                    {
                        return k;
                    }


                }

            }
        }


    }
    return -1;//si on a pas de grp d'adversaire avec un seul deg de liberte
}
int save_group()//essaye d'augmenter le degre de liberte de votre group si le group n'est pas dans les frontieres du goban
{
    for (int i=0; i<81; i++)
    {
        int checked[81]= {0};
        int liberte[81]= {0};

        if(M[i]==machine.id)//pion de machine
        {
            check_group_lib(i,M,checked,liberte);
            if(count_liberte(liberte)==2)//si le degre de liberte de chaque grp egale a 2(eviter un deg de liberte car l'adversaire peut captuerer votere grp a la fin)
            {
                for(int k=0; k<81; k++)
                {
                    int h,b,g,d;
                    h=position_haut(k);
                    b=position_bas(k);
                    g=position_gauche(k);
                    d=position_droit(k);
                    if((liberte[k]==1)&&(h!=-1&&g!=-1&&b!=-1&&d!=-1)&&(minimise_deg_lib(k)==0)&&(Suicide(k)==0))//pour assurer que le grp n'est pas dans les frontieres
                    {
                        return k;
                    }
                }


            }

        }

    }
    return -1;
}




int minimise_deg_lib(int j)//tester l'effet de place un pion sur une intersection sur un group de machine
{

    int checked[81]= {0};
    int liberte[81]= {0};
    int G[81]= {0};
    for(int k=0; k<81; k++)
    {
        G[k]=M[k];
    }

    G[j]=machine.id;//assume that machine makes a move


    check_group_lib(j,G,checked,liberte);
    if(count_liberte(liberte)==1)//makes the grp of j with a unique liberte
        return 1;//cette move minimise le degre de liberte de grp de j
    return 0;

}
int surround()//try to surround the adversaire
{
    int min_liberte=82;//any value superieur a 80
    for (int i=0; i<81; i++)//parcours le goban
    {
        int checked[81]= {0};
        int liberte[81]= {0};

        if(M[i]==joueur.id)//adversaire pion
        {
            check_group_lib(i,M,checked,liberte);//calcule le degre de liberte de chaque grp
            if(min_liberte>count_liberte(liberte))//help us to knowc the grp that has the minimum of deg liberte
            {
                min_liberte=count_liberte(liberte);

            }


        }
    }
    for (int i=0; i<81; i++)
    {
        int checked[81]= {0};
        int liberte[81]= {0};

        if(M[i]==joueur.id)
        {
            check_group_lib(i,M,checked,liberte);
            if(count_liberte(liberte)==min_liberte)//choose the grp that has the minimum of degre liberte
            {
                for(int k=0;k<81; k++)
                {
                    if((liberte[k]==1)&&(Suicide(k)==0))//empty position(in grp that has the min deg de liberte) and not suicide
                        return k;
                }

            }


        }
    }
        return -1;

}


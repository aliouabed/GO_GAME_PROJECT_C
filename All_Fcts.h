#ifndef ALL_FCTS_H_INCLUDED
#define ALL_FCTS_H_INCLUDED

//***********************************************VARIABLE EXTERN DECLARATION
extern int choix;
extern int territory_found;
extern int M[81];
extern int player;
extern int adversaire;
extern struct joueur joueur1,joueur2,joueur,machine;
extern float count_captured_black;
extern int count_captured_white;
extern int black_territory;
extern int white_territory;
extern int territory_of;

//****************************************************************AFFICHAGE_JEU

void instructions();
void affichage_menu(void);
void affiche_grille(void);
void rules(void);
void joueur_information(void);
void color(int text_color, int bg_color);

//***************************************************************REGLES_JEU
//************************************************************************

int position_vide(int i);
int Suicide(int i);
int ko_move(int pre_M[81],int after_M[81]);
void capture_group(int i);
int count_liberte(int liberte[81]);
void territory(int i,int visited[81],int color);
int ko_prevent();
void check_group_lib(int i,int M[81],int checked[81],int liberte[81]);

//********************************************************************
//*************************************************HELP IN REGLES_JEU

int degre_liberte(int i);
int position_haut(int i);
int position_bas(int i);
int position_droit(int i);
int position_gauche(int i);
int End_game(int G[81],int H[81]);
void pass(void);

//*******************************************************JOUEURVSJOUEUR

void Joueur_VS_Joueur(int index);
void choose_first(void);
int random_entre_deux_int(int max,int min);


//****************************************************JOUEUR VS MACHINE

void choose_first2(void);
void Joueur_Ordinateur(int index);
void Joueur_Humain(int index);
void instructions_2();
void Final_Score();

//******************************************************************STRUCTS
struct joueur
{
    char nom[20];
    int id;
};


#endif //ALL_FCTS_H_INCLUDED

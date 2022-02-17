#include <iostream>
#include <winbgim.h>
#include <stdlib.h>
#include <graphics.h>
#include <stdio.h>
#include <windows.h>
#include "mmsystem.h"
#include <fstream>
#include <shellapi.h>
using namespace std;
FILE* Setari=fopen("setari.txt","r+");
FILE* lvl=fopen("LevelAttachment.txt","r+");
FILE* nivelcurent=fopen("nivelcurent.txt","r+");

char atasareNivel[50]=" ";
char sirSpatii[61]="                                                            ";
int font=0;
const int xjoc=6;
const int yjoc=6;
int TablaDeJoc[xjoc][yjoc];
const int Max_Resolution_X=1920;
const int Max_Resolution_Y=1080;
float rezolutie=1.5;//
int limba=1;//engleza
int sunet=1;//on
int nivel=1;
int MatriceNivel[xjoc][yjoc];
int niv=0;
int nrVulpiOriz=0;
int nrVulpiVer=0;

bool mutarepieseswitch=false;
bool menu=true;
bool crearenivelswitch=true;
bool playnivelcreat=false;
bool interfata=true;
bool citiresirswitch=false;

const char* InterfataPlayPlay="PieseInterfata\\InterfataPlayPlay.jpg";
const char* InterfataPlayBack="PieseInterfata\\InterfataPlayBack.jpg";
const char* InterfataPlayAgrafa="PieseInterfata\\InterfataPlayAgrafa.jpg";
const char* InterfataPlayTarnacop="PieseInterfata\\InterfataPlayTarnacop.jpg";
const char* BackButtonGreenn="Images\\BackButtonGreen.jpg";

const char* PlayInitializareNivel="Images\\PlayInitializareNivel.jpg";
const char* NiveleMemorate="Images\\NiveleMemorate.jpg";
const char* interfataPlayDefault="Images\\InterfataPlay.jpg";
const char* Nivel0="CreareNivel\\Nivel0.jpg";
const char* Nivel1="CreareNivel\\Nivel1.jpg";
const char* Nivel2="CreareNivel\\Nivel2.jpg";
const char* Nivel3="CreareNivel\\Nivel3.jpg";
const char* Nivel4="CreareNivel\\Nivel4.jpg";
const char* Nivel5="CreareNivel\\Nivel5.jpg";
const char* Nivel6="CreareNivel\\Nivel6.jpg";
const char* Nivel7="CreareNivel\\Nivel7.jpg";
const char* Nivel8="CreareNivel\\Nivel8.jpg";
const char* Nivel9="CreareNivel\\Nivel9.jpg";
const char* Nivel10="CreareNivel\\Nivel10.jpg";
const char* Nivel11="CreareNivel\\Nivel11.jpg";
const char* Nivel12="CreareNivel\\Nivel12.jpg";
const char* Nivel13="CreareNivel\\Nivel13.jpg";
const char* Nivel14="CreareNivel\\Nivel14.jpg";
const char* Nivel15="CreareNivel\\Nivel15.jpg";
const char* Nivel16="CreareNivel\\Nivel16.jpg";
const char* Nivel17="CreareNivel\\Nivel17.jpg";
const char* Nivel18="CreareNivel\\Nivel18.jpg";
const char* Nivel19="CreareNivel\\Nivel19.jpg";
const char* Nivel20="CreareNivel\\Nivel20.jpg";
const char* Nivel21="CreareNivel\\Nivel21.jpg";
const char* Nivel22="CreareNivel\\Nivel22.jpg";
const char* Nivel23="CreareNivel\\Nivel23.jpg";
const char* Nivel24="CreareNivel\\Nivel24.jpg";


const char* PlayBackButton="Images\\PlayBackButton.jpg";
const char* Meniu="Images\\Meniu.jpg";
const char* PlayButtonHighlight="Images\\PlayButton.jpg";
const char* SettingsButtonHighlight="Images\\SettingsButton.jpg";
const char* RulesButtonHighlight="Images\\RulesButton.jpg";
const char* QuitButtonHighlight="Images\\QuitButton.jpg";
const char* rulesMenu="Images\\RulesMenu.jpg";
const char* Work="Images\\Workinprogress.jpg";

const char* CreareNivel="CreareNivel\\CreareNivel.jpg";
const char* Atasare="Images\\Atasare_Settings.jpg";

const char* SettingsMenu1280OffE="SettingsMenu\\SettingsMenu1280OffE.jpg";
const char* SettingsMenu1280OnE="SettingsMenu\\SettingsMenu1280OnE.jpg";
const char* SettingsMenu1920OffE="SettingsMenu\\SettingsMenu1920OffE.jpg";
const char* SettingsMenu1920OnE="SettingsMenu\\SettingsMenu1920OnE.jpg";
const char* GameRules="Images\\GameRulesFinal.jpg";

const char* FundalPlay="Images\\Play.jpg";

const char* Rabbit="Piese\\iepure.jpg";
const char* Mushroom="Piese\\mushroom.jpg";
const char* Tunnel="Piese\\tunel.jpg";

const char* VulpeVerticalaJosCoada="Piese\\VulpeVerticalaJosCoada.jpg";
const char* VulpeVerticalaJosCap="Piese\\VulpeVerticalaJosCap.jpg";
const char* VulpeVerticalaSusCoada="Piese\\VulpeVerticalaSusCoada.jpg";
const char* VulpeVerticalaSusCap="Piese\\VulpeVerticalaSusCap.jpg";

const char* VulpeOrizontalaDreaptaCoada="Piese\\VulpeOrizontalaDreaptaCoada.jpg";
const char* VulpeOrizontalaDreaptaCap="Piese\\VulpeOrizontalaDreaptaCap.jpg";
const char* VulpeOrizontalaStangaCoada="Piese\\VulpeOrizontalaStangaCoada.jpg";
const char* VulpeOrizontalaStangaCap="Piese\\VulpeOrizontalaStangaCap.jpg";

const char* Patrat="Piese\\Patrat.jpg";
const char* TunnelWithRabbit="Piese\\tunelcuiepure.jpg";

const char* ReguliRomana="Romana\\ReguliRomana.jpg";
const char* MeniuRomana="Romana\\MeniuRomana.jpg";
const char* MeniuRomanaInchidereJoc="Romana\\MeniuRomanaInchidereJoc.jpg";
const char* MeniuRomanaJoc="Romana\\MeniuRomanaJoc.jpg";
const char* MeniuRomanaOptiuni="Romana\\MeniuRomanaOptiuni.jpg";
const char* MeniuRomanaReguli="Romana\\MeniuRomanaReguli.jpg";
const char* SettingsMenu1280OpritR="Romana\\SettingsMenu1280OpritR.jpg";
const char* SettingsMenu1280PornitR="Romana\\SettingsMenu1280PornitR.jpg";
const char* SettingsMenu1920OpritR="Romana\\SettingsMenu1920OpritR.jpg";
const char* SettingsMenu1920PornitR="Romana\\SettingsMenu1920PornitR.jpg";

void citireNivel()
{
    fseek(nivelcurent,0, SEEK_SET);
    fscanf(nivelcurent,"%d",&niv);
}
void scriereNivel()
{
    fseek(nivelcurent,0, SEEK_SET);
    fprintf(nivelcurent,"%d\n",niv);
}
void StartSettings()
{
    fseek(Setari,0, SEEK_SET);
    fscanf(Setari,"%f",&rezolutie);
    fscanf(Setari,"%d",&limba);
    fscanf(Setari,"%d",&sunet);
}
void SaveSettings()
{
    fseek(Setari,0, SEEK_SET);
    fprintf(Setari,"%f\n",rezolutie);
    fprintf(Setari,"%d\n",limba);
    fprintf(Setari,"%d\n",sunet);
}
int amObstacolColoana(int x,int y,int z)
{
  if(y-x==1)
    return 0;
  int i;
  for(i=x+1;i<y;i++)
    if(TablaDeJoc[i][z]==0)
      return 0;
  return 1;
}
int amObstacolLinie(int x,int y,int z)
{
    if(y-x==1)
    return 0;
   int i;
  for(i=x+1;i<y;i++)
    if(TablaDeJoc[z][i]==0)
      return 0;
  return 1;
}
int amObstacolVulpeVerticala(int x,int y,int z,int piesa)
{
    int i=x;
    if(x<y)
    {
        if(TablaDeJoc[i][z]==piesa&&TablaDeJoc[i+1][z]==piesa)
        {
            cout<<"coada"<<endl;
            for(i=x+2; i<=y; i++)
                if(TablaDeJoc[i][z]!=0)
                {
                    cout<<"nu vede"<<endl;
                    return 0;
                }
        }
        else
        {
            for(i=x+1; i<=y; i++)
                if(TablaDeJoc[i][z]!=0)
                {
                    cout<<"nu vede1";
                    return 0;
                }
        }
    }
    else if (x>y)
    {
        for(i=y; i<=x; i++)
            if(TablaDeJoc[i][z]==piesa)
            {
                i=i+1;
            }
            else    if(TablaDeJoc[i][z]!=0)
                return 0;
                cout<<"nu";
    }
    return 1;
}

int amObstacolVulpeOrizontala(int x,int y,int z,int piesa)
{
  int i=x;
 if(x<y)
 {
  if(TablaDeJoc[z][i]==piesa&&TablaDeJoc[z][i+1]==piesa)
  {

      for(i=x+2;i<=y;i++)
        if(TablaDeJoc[z][i]!=0)
        return 0;
  }
  else
  {
      for(i=x+1;i<=y;i++)
        if(TablaDeJoc[z][i]!=0)
        return 0;
  }
}
else if (x>y)
{
    int i=x;
    if(TablaDeJoc[z][i]==piesa&&TablaDeJoc[z][i-1]==piesa)
    {
      x=x-1;
      for(i=y;i<x;i++)
            if(TablaDeJoc[z][i]!=0)
             return 0;
    }
    else
    {
     for(i=y;i<x;i++)
            if(TablaDeJoc[z][i]!=0)
             return 0;
    }
}
  return 1;
}
void deseneazaPiesa(int linia, int coloana, const char *p)
{
    int numar=5;
    int latime=800/rezolutie;
    int inaltime=800/rezolutie;
    int latura=latime/numar;
    int sus=(1080/rezolutie-latime)/2;
    int stanga=(1920/rezolutie-inaltime)/2;
    int x1,y1,x2,y2;
    x1=stanga+latura*(coloana-1);
    y1=sus+latura*(linia-1);
    x2=x1+latura;
    y2=y1+latura;
    readimagefile(p,x1,y1,x2,y2);
}
void PlayMenu(int cheie1,int cheie2);
void meniuNivele();
void draw(const char *p);
void InterfataPlay();
void declarariMeniuNivele()
{
     int i;
    int j;
    int aux=0;
    for(i=1;i<=5;i++)
         for(j=1;j<=5;j++)
           {
               MatriceNivel[i][j]=aux;
               aux++;
           }
           draw(NiveleMemorate);
                deseneazaPiesa(1,1,Nivel0);
                deseneazaPiesa(1,2,Nivel1);
                deseneazaPiesa(1,3,Nivel2);
                deseneazaPiesa(1,4,Nivel3);
                deseneazaPiesa(1,5,Nivel4);

                deseneazaPiesa(2,1,Nivel5);
                deseneazaPiesa(2,2,Nivel6);
                deseneazaPiesa(2,3,Nivel7);
                deseneazaPiesa(2,4,Nivel8);
                deseneazaPiesa(2,5,Nivel9);

                deseneazaPiesa(3,1,Nivel10);
                deseneazaPiesa(3,2,Nivel11);
                deseneazaPiesa(3,3,Nivel12);
                deseneazaPiesa(3,4,Nivel13);
                deseneazaPiesa(3,5,Nivel14);

                deseneazaPiesa(4,1,Nivel15);
                deseneazaPiesa(4,2,Nivel16);
                deseneazaPiesa(4,3,Nivel17);
                deseneazaPiesa(4,4,Nivel18);
                deseneazaPiesa(4,5,Nivel19);

                deseneazaPiesa(5,1,Nivel20);
                deseneazaPiesa(5,2,Nivel21);
                deseneazaPiesa(5,3,Nivel22);
                deseneazaPiesa(5,4,Nivel23);
                deseneazaPiesa(5,5,Nivel24);
         meniuNivele();
}
void meniuNivele()
{
    int numar=5;
    int latime=800/rezolutie;
    int inaltime=800/rezolutie;
    int latura=latime/numar;
    int sus=(1080/rezolutie-latime)/2;
    int stanga=(1920/rezolutie-inaltime)/2;
    int linia1,coloana1,x,y;

    int click=false;
    do
        if(ismouseclick(WM_LBUTTONDOWN) && !click)
        {
            click=true;
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();
            linia1=(y-sus)/latura+1;
            coloana1=(x-stanga)/latura+1;
        } while (!click);
    if(x>32/rezolutie&&x<253/rezolutie&&y>833/rezolutie&&y<1034/rezolutie)
    {
        interfata=true;
        InterfataPlay();
    }
    if(niv>=MatriceNivel[linia1][coloana1]&& (x>=547/rezolutie&&x<=1368/rezolutie&&y>=132/rezolutie&&y<=946/rezolutie))
    {
        int w=0;
        FILE* fil=fopen("NiveleCodateBruh.txt","r");
        int x1=-1;
        char rand[30][60];
        while(!feof(fil))
        {
            if(!fgets(rand[++x1],sizeof(rand[x1]),fil))
        {
            perror("Eroare la citire:");
            exit(1);
        }
            if(x1==MatriceNivel[linia1][coloana1])
            {

                for(int p=1;p<=5;p++)
                    for(int j=1;j<=5;j++)
                {
                    TablaDeJoc[p][j]=rand[x1][w]-'0';
                    w=w+2;
                }
                   int nush=MatriceNivel[linia1][coloana1];
                PlayMenu(niv,nush);
            }
        }


    }
    else {cout<<"actiune imposibila";
           meniuNivele();
    }
}

/////////FUNCTII MENIU////////////
void draw(const char *p)
{
    readimagefile(p,0,0,Max_Resolution_X/rezolutie,Max_Resolution_Y/rezolutie);
}


void openMenuInterface();
//////////////////////////PATRUT/////////////////////////////////////
void mutarePiesa();
/////////////////////////////////////////////////////////////////////
void InterfataPlay();
void PlayMenu(int cheie1, int cheie2)
{



    for(int i=0; i<=xjoc; i++)
    {
        TablaDeJoc[i][0]=9;
        TablaDeJoc[i][yjoc]=9;
    }
    for(int i=0; i<=yjoc; i++)
    {
        TablaDeJoc[0][i]=9;
        TablaDeJoc[xjoc][i]=9;
    }
   // draw(FundalPlay);
draw(PlayBackButton);

     for(int i=1; i<xjoc; i++)
        for(int j=1; j<yjoc; j++)
        {
            if(TablaDeJoc[i][j]==1)
                      deseneazaPiesa(i,j,Rabbit);
            else if(TablaDeJoc[i][j]==4)
                      deseneazaPiesa(i,j,Tunnel);
            else    if(TablaDeJoc[i][j]==5)
                      deseneazaPiesa(i,j,Mushroom);
            else if (TablaDeJoc[i][j]==2&&TablaDeJoc[i+1][j]==2)
                     {
                         deseneazaPiesa(i,j,VulpeVerticalaJosCoada);
                         deseneazaPiesa(i+1,j,VulpeVerticalaJosCap);
                     }
            else if(TablaDeJoc[i][j]==3&&TablaDeJoc[i][j+1]==3)
            {
                         deseneazaPiesa(i,j,VulpeOrizontalaDreaptaCoada);
                         deseneazaPiesa(i,j+1,VulpeOrizontalaDreaptaCap);
            }
            else if(TablaDeJoc[i][j]==6&&TablaDeJoc[i+1][j]==6)
            {
                         deseneazaPiesa(i,j,VulpeVerticalaSusCap);
                         deseneazaPiesa(i+1,j,VulpeVerticalaSusCoada);
            }
             else if(TablaDeJoc[i][j]==7&&TablaDeJoc[i][j+1]==7)
             {
                         deseneazaPiesa(i,j,VulpeOrizontalaStangaCap);
                         deseneazaPiesa(i,j+1,VulpeOrizontalaStangaCoada);
             }
             else if(TablaDeJoc[i][j]==8)
                deseneazaPiesa(i,j,TunnelWithRabbit);
            else if(TablaDeJoc[i][j]==0)
                 deseneazaPiesa(i,j,Patrat);
        }
    mutarepieseswitch=true;
    do{
    mutarePiesa();
    }while(mutarepieseswitch);
    if(cheie1==-7&&cheie2==0)
    {
        interfata=true;
        InterfataPlay();
    }
    if (cheie1==cheie2)
    {niv=niv+1;
      cout<<niv;
      scriereNivel();
     declarariMeniuNivele();
    }
    if (cheie1>=cheie2)////////////////////////////////////////////////////////BRUH///////////////
       declarariMeniuNivele();


}
void initializareNivel();
void citesteSir(char s[50],int x, int y);
void mutarePiesa()
{   int numar=5;
    int latime=800/rezolutie;
    int inaltime=800/rezolutie;
    int latura=latime/numar;
    int sus=(1080/rezolutie-latime)/2;
    int stanga=(1920/rezolutie-inaltime)/2;
    int linia1,coloana1,linia2,coloana2,x,y;
    int okObstacol=0;
    int x1, y1, x2, y2;
    int xmijloc, ymijloc;
    if(playnivelcreat==true)
        readimagefile(BackButtonGreenn,0,0,100/rezolutie,100/rezolutie); ////boooon //////dragoi alupigus
    int click=false;
    do
        if(ismouseclick(WM_LBUTTONDOWN) && !click)
        {
            click=true;
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();
            linia1=(y-sus)/latura+1;
            coloana1=(x-stanga)/latura+1;
        } while (!click);
    if(playnivelcreat==true&&(x>0&&x<100/rezolutie&&y>0&&y<100/rezolutie))
    {
        playnivelcreat=false;
        initializareNivel();
    }
     if(mutarepieseswitch==true&&citiresirswitch==true&&x>32/rezolutie&&x<253/rezolutie&&y>833/rezolutie&&y<1034/rezolutie)
    {
        citiresirswitch=false;
        interfata=true;
        InterfataPlay();
    }
    if(mutarepieseswitch==true&&x>32/rezolutie&&x<253/rezolutie&&y>833/rezolutie&&y<1034/rezolutie)
    {
        mutarepieseswitch=false;
        declarariMeniuNivele();
    }

    if(TablaDeJoc[linia1][coloana1]==1)
    {

        click=false;
        do
            if(ismouseclick(WM_LBUTTONDOWN) && !click)
            {
                click=true;
                clearmouseclick(WM_LBUTTONDOWN);
                x=mousex();
                y=mousey();
                linia2=(y-sus)/latura+1;
                coloana2=(x-stanga)/latura+1;
            }
        while (!click);
/////////////////////////////////////////////////
  if(TablaDeJoc[linia2][coloana2]==4&& (x>=547/rezolutie&&x<=1368/rezolutie&&y>=132/rezolutie&&y<=946/rezolutie))
  {
       if(coloana1==coloana2)
            {
                if(linia1<linia2)
                    okObstacol=amObstacolColoana(linia1,linia2,coloana1);
                else if(linia1>linia2)
                    okObstacol=amObstacolColoana(linia2,linia1,coloana1);
                if(okObstacol==1)
                {
                    TablaDeJoc[linia1][coloana1]=0;
                    deseneazaPiesa(linia1,coloana1,Patrat);
                    TablaDeJoc[linia2][coloana2]=8;
                    deseneazaPiesa(linia2,coloana2,TunnelWithRabbit);
                }
                else
                    cout<<"eroare"<<endl;
            }
            else if(linia1==linia2)
            {
                if(coloana1<coloana2)
                    okObstacol=amObstacolLinie(coloana1,coloana2,linia1);
                else if(coloana1>coloana2)
                    okObstacol=amObstacolLinie(coloana2,coloana1,linia1);
                if(okObstacol==1)
                {
                    TablaDeJoc[linia1][coloana1]=0;
                    deseneazaPiesa(linia1,coloana1,Patrat);
                    TablaDeJoc[linia2][coloana2]=8;
                    deseneazaPiesa(linia2,coloana2,TunnelWithRabbit);
                }
                else
                    cout<<"eroare"<<endl;
            }
  }
//////////////////////////////////////////////////////////////////////////////////////////////////////////
       else    {  if(TablaDeJoc[linia2][coloana2]==0&& (x>=547/rezolutie&&x<=1368/rezolutie&&y>=132/rezolutie&&y<=946/rezolutie))

             if(coloana1==coloana2)
            {
                if(linia1<linia2)
                    okObstacol=amObstacolColoana(linia1,linia2,coloana1);
                else if(linia1>linia2)
                    okObstacol=amObstacolColoana(linia2,linia1,coloana1);
                if(okObstacol==1)
                {
                    TablaDeJoc[linia1][coloana1]=0;
                    deseneazaPiesa(linia1,coloana1,Patrat);
                    TablaDeJoc[linia2][coloana2]=1;
                    deseneazaPiesa(linia2,coloana2,Rabbit);
                }
                else
                    cout<<"eroare"<<endl;
            }
            else if(linia1==linia2)
            {
                if(coloana1<coloana2)
                    okObstacol=amObstacolLinie(coloana1,coloana2,linia1);
                else if(coloana1>coloana2)
                    okObstacol=amObstacolLinie(coloana2,coloana1,linia1);
                if(okObstacol==1)
                {
                    TablaDeJoc[linia1][coloana1]=0;
                    deseneazaPiesa(linia1,coloana1,Patrat);
                    TablaDeJoc[linia2][coloana2]=1;
                    deseneazaPiesa(linia2,coloana2,Rabbit);
                }
                else
                    cout<<"eroare"<<endl;
            } }
        //}
    }
    else   if(TablaDeJoc[linia1][coloana1]==2)
    {
        click=false;
        do
            if(ismouseclick(WM_LBUTTONDOWN) && !click)
            {
                click=true;
                clearmouseclick(WM_LBUTTONDOWN);
                x=mousex();
                y=mousey();
                linia2=(y-sus)/latura+1;
                coloana2=(x-stanga)/latura+1;

            }
        while(!click);
        if(TablaDeJoc[linia2][coloana2]!=0&& !(x>=547/rezolutie&&x<=1368/rezolutie&&y>=132/rezolutie&&y<=946/rezolutie))
            cout<<"eroare"<<endl;
        else
        {
            if(linia2>linia1&&coloana1==coloana2)
            {
                okObstacol=amObstacolVulpeVerticala(linia1,linia2,coloana1,2);
                if(okObstacol==1)
                {
                     if(TablaDeJoc[linia1][coloana1]==2&&TablaDeJoc[linia1-1][coloana1]==2)
                {
                    TablaDeJoc[linia1][coloana1]=0;
                    TablaDeJoc[linia1-1][coloana1]=0;
                    deseneazaPiesa(linia1,coloana1,Patrat);
                    deseneazaPiesa(linia1-1,coloana1,Patrat);
                    TablaDeJoc[linia2][coloana2]=2;
                    TablaDeJoc[linia2-1][coloana2]=2;
                    deseneazaPiesa(linia2,coloana2,VulpeVerticalaJosCap);
                    deseneazaPiesa(linia2-1,coloana2,VulpeVerticalaJosCoada);
                }
                else if(TablaDeJoc[linia1][coloana1]==2&&TablaDeJoc[linia1+1][coloana1]==2)
                {
                    TablaDeJoc[linia1][coloana1]=0;
                    TablaDeJoc[linia1+1][coloana1]=0;
                    deseneazaPiesa(linia1,coloana1,Patrat);
                    deseneazaPiesa(linia1+1,coloana1,Patrat);
                    TablaDeJoc[linia2-1][coloana2]=2;
                    TablaDeJoc[linia2][coloana2]=2;
                    deseneazaPiesa(linia2-1,coloana2,VulpeVerticalaJosCoada);
                    deseneazaPiesa(linia2,coloana2,VulpeVerticalaJosCap);
                }
                }
            }
            else if(linia2<linia1&&coloana1==coloana2)
            {
                  okObstacol=amObstacolVulpeVerticala(linia1,linia2,coloana1,2);
                     if(okObstacol==1)
                     {
                           if(TablaDeJoc[linia1][coloana1]==2&&TablaDeJoc[linia1-1][coloana1]==2)
                           {
                               TablaDeJoc[linia1][coloana1]=0;
                               TablaDeJoc[linia1-1][coloana1]=0;
                               deseneazaPiesa(linia1,coloana1,Patrat);
                               deseneazaPiesa(linia1-1,coloana1,Patrat);
                               TablaDeJoc[linia2][coloana2]=2;
                               TablaDeJoc[linia2+1][coloana2]=2;
                               deseneazaPiesa(linia2,coloana2,VulpeVerticalaJosCoada);
                               deseneazaPiesa(linia2+1,coloana2,VulpeVerticalaJosCap);
                           }
                    else if(TablaDeJoc[linia1][coloana1]==2&&TablaDeJoc[linia1+1][coloana1]==2)
                           {
                            TablaDeJoc[linia1][coloana1]=0;
                            TablaDeJoc[linia1+1][coloana1]=0;
                            deseneazaPiesa(linia1,coloana1,Patrat);
                            deseneazaPiesa(linia1+1,coloana1,Patrat);
                            TablaDeJoc[linia2][coloana2]=2;
                               TablaDeJoc[linia2+1][coloana2]=2;
                               deseneazaPiesa(linia2,coloana2,VulpeVerticalaJosCoada);
                               deseneazaPiesa(linia2+1,coloana2,VulpeVerticalaJosCap);

                           }
                     }
                     else cout<<"eroare inapoi boss";
            }

        }

    }
    //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX//
    else   if(TablaDeJoc[linia1][coloana1]==6)
    {
        click=false;
        do
            if(ismouseclick(WM_LBUTTONDOWN) && !click)
            {
                click=true;
                clearmouseclick(WM_LBUTTONDOWN);
                x=mousex();
                y=mousey();
                linia2=(y-sus)/latura+1;
                coloana2=(x-stanga)/latura+1;

            }
        while(!click);
        if(TablaDeJoc[linia2][coloana2]!=0&& !(x>=547/rezolutie&&x<=1368/rezolutie&&y>=132/rezolutie&&y<=946/rezolutie))
            cout<<"eroare"<<endl;
        else
        {
            if(linia2>linia1&&coloana1==coloana2)
            {
                okObstacol=amObstacolVulpeVerticala(linia1,linia2,coloana1,6);
                if(okObstacol==1)
                {
                     if(TablaDeJoc[linia1][coloana1]==6&&TablaDeJoc[linia1-1][coloana1]==6)
                {
                    TablaDeJoc[linia1][coloana1]=0;
                    TablaDeJoc[linia1-1][coloana1]=0;
                    deseneazaPiesa(linia1,coloana1,Patrat);
                    deseneazaPiesa(linia1-1,coloana1,Patrat);
                    TablaDeJoc[linia2][coloana2]=6;
                    TablaDeJoc[linia2-1][coloana2]=6;
                    deseneazaPiesa(linia2,coloana2,VulpeVerticalaSusCoada);
                    deseneazaPiesa(linia2-1,coloana2,VulpeVerticalaSusCap);
                }
                else if(TablaDeJoc[linia1][coloana1]==6&&TablaDeJoc[linia1+1][coloana1]==6)
                {
                    TablaDeJoc[linia1][coloana1]=0;
                    TablaDeJoc[linia1+1][coloana1]=0;
                    deseneazaPiesa(linia1,coloana1,Patrat);
                    deseneazaPiesa(linia1+1,coloana1,Patrat);
                    TablaDeJoc[linia2-1][coloana2]=6;
                    TablaDeJoc[linia2][coloana2]=6;
                    deseneazaPiesa(linia2,coloana2,VulpeVerticalaSusCoada);
                    deseneazaPiesa(linia2-1,coloana2,VulpeVerticalaSusCap);
                }
                }
            }
            else if(linia2<linia1&&coloana1==coloana2)
            {
                  okObstacol=amObstacolVulpeVerticala(linia1,linia2,coloana1,6);
                     if(okObstacol==1)
                     {
                           if(TablaDeJoc[linia1][coloana1]==6&&TablaDeJoc[linia1-1][coloana1]==6)
                           {
                               TablaDeJoc[linia1][coloana1]=0;
                               TablaDeJoc[linia1-1][coloana1]=0;
                               deseneazaPiesa(linia1,coloana1,Patrat);
                               deseneazaPiesa(linia1-1,coloana1,Patrat);
                               TablaDeJoc[linia2][coloana2]=6;
                               TablaDeJoc[linia2+1][coloana2]=6;
                               deseneazaPiesa(linia2,coloana2,VulpeVerticalaSusCap);
                               deseneazaPiesa(linia2+1,coloana2,VulpeVerticalaSusCoada);
                           }
                    else if(TablaDeJoc[linia1][coloana1]==6&&TablaDeJoc[linia1+1][coloana1]==6)
                           {
                            TablaDeJoc[linia1][coloana1]=0;
                            TablaDeJoc[linia1+1][coloana1]=0;
                            deseneazaPiesa(linia1,coloana1,Patrat);
                            deseneazaPiesa(linia1+1,coloana1,Patrat);
                            TablaDeJoc[linia2][coloana2]=6;
                               TablaDeJoc[linia2+1][coloana2]=6;
                              deseneazaPiesa(linia2,coloana2,VulpeVerticalaSusCap);
                              deseneazaPiesa(linia2+1,coloana2,VulpeVerticalaSusCoada);

                           }
                     }
                     else cout<<"eroare inapoi boss";
            }

        }

    }
    //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX//
     else if(TablaDeJoc[linia1][coloana1]==3)
    {
        click=false;
        do
            if(ismouseclick(WM_LBUTTONDOWN) && !click)
            {
                click=true;
                clearmouseclick(WM_LBUTTONDOWN);
                x=mousex();
                y=mousey();
                linia2=(y-sus)/latura+1;
                coloana2=(x-stanga)/latura+1;

            }
        while(!click);
        if(TablaDeJoc[linia2][coloana2]!=0&& !(x>=547/rezolutie&&x<=1368/rezolutie&&y>=132/rezolutie&&y<=946/rezolutie))
            cout<<"eroare"<<endl;
        else
        {
            if (coloana2>coloana1&&linia1==linia2)
            {
                okObstacol=amObstacolVulpeOrizontala(coloana1,coloana2,linia1,3);
                if(okObstacol==1)
                {
                   if(TablaDeJoc[linia1][coloana1]==3&&TablaDeJoc[linia1][coloana1-1]==3)
                   {
                    TablaDeJoc[linia1][coloana1]=0;
                    TablaDeJoc[linia1][coloana1-1]=0;
                    deseneazaPiesa(linia1,coloana1,Patrat);
                    deseneazaPiesa(linia1,coloana1-1,Patrat);
                    TablaDeJoc[linia2][coloana2]=3;
                    TablaDeJoc[linia2][coloana2-1]=3;
                    deseneazaPiesa(linia2,coloana2,VulpeOrizontalaDreaptaCap);
                    deseneazaPiesa(linia2,coloana2-1,VulpeOrizontalaDreaptaCoada);
                   }
                   else if(TablaDeJoc[linia1][coloana1]==3&&TablaDeJoc[linia1][coloana1+1]==3)
                   {

                    TablaDeJoc[linia1][coloana1]=0;
                    TablaDeJoc[linia1][coloana1+1]=0;
                    deseneazaPiesa(linia1,coloana1,Patrat);
                    deseneazaPiesa(linia1,coloana1+1,Patrat);
                    TablaDeJoc[linia2][coloana2]=3;
                    TablaDeJoc[linia2][coloana2-1]=3;
                    deseneazaPiesa(linia2,coloana2-1,VulpeOrizontalaDreaptaCoada);
                    deseneazaPiesa(linia2,coloana2,VulpeOrizontalaDreaptaCap);
                   }
                }
            }
            else if(coloana2<coloana1&&linia1==linia2)
            {
                okObstacol=amObstacolVulpeOrizontala(coloana1,coloana2,linia1,3);
                if(okObstacol==1)
                {
                   if(TablaDeJoc[linia1][coloana1]==3&&TablaDeJoc[linia1][coloana1-1]==3)
                   {
                    TablaDeJoc[linia1][coloana1]=0;
                    TablaDeJoc[linia1][coloana1-1]=0;
                    deseneazaPiesa(linia1,coloana1,Patrat);
                    deseneazaPiesa(linia1,coloana1-1,Patrat);
                    TablaDeJoc[linia2][coloana2]=3;
                    TablaDeJoc[linia2][coloana2+1]=3;
                    deseneazaPiesa(linia2,coloana2,VulpeOrizontalaDreaptaCoada);
                    deseneazaPiesa(linia2,coloana2+1,VulpeOrizontalaDreaptaCap);

                   }
                   else if(TablaDeJoc[linia1][coloana1]==3&&TablaDeJoc[linia1][coloana1+1]==3)
                   {
                    TablaDeJoc[linia1][coloana1]=0;
                    TablaDeJoc[linia1][coloana1+1]=0;
                    deseneazaPiesa(linia1,coloana1,Patrat);
                    deseneazaPiesa(linia1,coloana1+1,Patrat);
                    TablaDeJoc[linia2][coloana2]=3;
                    TablaDeJoc[linia2][coloana2+1]=3;
                    deseneazaPiesa(linia2,coloana2,VulpeOrizontalaDreaptaCoada);
                    deseneazaPiesa(linia2,coloana2+1,VulpeOrizontalaDreaptaCap);
                   }
                }
            }
        }
    }
////XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX NOT DONEEE YEEEETTa
    else if(TablaDeJoc[linia1][coloana1]==7)
    {
       click=false;
        do
            if(ismouseclick(WM_LBUTTONDOWN) && !click)
            {
                click=true;
                clearmouseclick(WM_LBUTTONDOWN);
                x=mousex();
                y=mousey();
                linia2=(y-sus)/latura+1;
                coloana2=(x-stanga)/latura+1;

            }
        while(!click);
        if(TablaDeJoc[linia2][coloana2]!=0&& !(x>=547/rezolutie&&x<=1368/rezolutie&&y>=132/rezolutie&&y<=946/rezolutie))
            cout<<"eroare"<<endl;
        else
        {

            if (coloana2>coloana1&&linia1==linia2)
            {
                okObstacol=amObstacolVulpeOrizontala(coloana1,coloana2,linia1,7);
                if(okObstacol==1)
                {
                   if(TablaDeJoc[linia1][coloana1]==7&&TablaDeJoc[linia1][coloana1-1]==7)
                   {
                    TablaDeJoc[linia1][coloana1]=0;
                    TablaDeJoc[linia1][coloana1-1]=0;
                    deseneazaPiesa(linia1,coloana1,Patrat);
                    deseneazaPiesa(linia1,coloana1-1,Patrat);
                    TablaDeJoc[linia2][coloana2]=7;
                    TablaDeJoc[linia2][coloana2-1]=7;
                    deseneazaPiesa(linia2,coloana2,VulpeOrizontalaStangaCoada);
                    deseneazaPiesa(linia2,coloana2-1,VulpeOrizontalaStangaCap);
                   }
                   else if(TablaDeJoc[linia1][coloana1]==7&&TablaDeJoc[linia1][coloana1+1]==7)
                   {

                    TablaDeJoc[linia1][coloana1]=0;
                    TablaDeJoc[linia1][coloana1+1]=0;
                    deseneazaPiesa(linia1,coloana1,Patrat);
                    deseneazaPiesa(linia1,coloana1+1,Patrat);
                    TablaDeJoc[linia2][coloana2]=7;
                    TablaDeJoc[linia2][coloana2-1]=7;
                    deseneazaPiesa(linia2,coloana2,VulpeOrizontalaStangaCoada);
                    deseneazaPiesa(linia2,coloana2-1,VulpeOrizontalaStangaCap);
                   }
                }
            }
            else if(coloana2<coloana1&&linia1==linia2)
            {
                okObstacol=amObstacolVulpeOrizontala(coloana1,coloana2,linia1,7);
                if(okObstacol==1)
                {
                   if(TablaDeJoc[linia1][coloana1]==7&&TablaDeJoc[linia1][coloana1-1]==7)
                   {
                    TablaDeJoc[linia1][coloana1]=0;
                    TablaDeJoc[linia1][coloana1-1]=0;
                    deseneazaPiesa(linia1,coloana1,Patrat);
                    deseneazaPiesa(linia1,coloana1-1,Patrat);
                    TablaDeJoc[linia2][coloana2]=7;
                    TablaDeJoc[linia2][coloana2+1]=7;
                    deseneazaPiesa(linia2,coloana2,VulpeOrizontalaStangaCap);
                    deseneazaPiesa(linia2,coloana2+1,VulpeOrizontalaStangaCoada);

                   }
                   else if(TablaDeJoc[linia1][coloana1]==7&&TablaDeJoc[linia1][coloana1+1]==7)
                   {
                    TablaDeJoc[linia1][coloana1]=0;
                    TablaDeJoc[linia1][coloana1+1]=0;
                    deseneazaPiesa(linia1,coloana1,Patrat);
                    deseneazaPiesa(linia1,coloana1+1,Patrat);
                    TablaDeJoc[linia2][coloana2]=7;
                    TablaDeJoc[linia2][coloana2+1]=7;
                    deseneazaPiesa(linia2,coloana2,VulpeOrizontalaStangaCap);
                    deseneazaPiesa(linia2,coloana2+1,VulpeOrizontalaStangaCoada);
                   }
                }
            }
        }
    }
//////////////////XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    //////////////////////////iepure in tunel///////////////////////
  else if(TablaDeJoc[linia1][coloana1]==8)
    {

        click=false;
        do
            if(ismouseclick(WM_LBUTTONDOWN) && !click)
            {
                click=true;
                clearmouseclick(WM_LBUTTONDOWN);
                x=mousex();
                y=mousey();
                linia2=(y-sus)/latura+1;
                coloana2=(x-stanga)/latura+1;
            }
        while (!click);
/////////////////////////////////////////////////
  if(TablaDeJoc[linia2][coloana2]==4)
  {
       if(coloana1==coloana2)
            {
                if(linia1<linia2)
                    okObstacol=amObstacolColoana(linia1,linia2,coloana1);
                else if(linia1>linia2)
                    okObstacol=amObstacolColoana(linia2,linia1,coloana1);
                if(okObstacol==1)
                {
                    TablaDeJoc[linia1][coloana1]=4;
                    deseneazaPiesa(linia1,coloana1,Tunnel);
                    TablaDeJoc[linia2][coloana2]=8;
                    deseneazaPiesa(linia2,coloana2,TunnelWithRabbit);
                }
                else
                    cout<<"eroare"<<endl;
            }
            else if(linia1==linia2)
            {
                if(coloana1<coloana2)
                    okObstacol=amObstacolLinie(coloana1,coloana2,linia1);
                else if(coloana1>coloana2)
                    okObstacol=amObstacolLinie(coloana2,coloana1,linia1);
                if(okObstacol==1)
                {
                    TablaDeJoc[linia1][coloana1]=4;
                    deseneazaPiesa(linia1,coloana1,Tunnel);
                    TablaDeJoc[linia2][coloana2]=8;
                    deseneazaPiesa(linia2,coloana2,TunnelWithRabbit);
                }
                else
                    cout<<"eroare"<<endl;
            }
  }
//////////////////////////////////////////////////////////////////////////////////////////////////////////
       else     if(TablaDeJoc[linia2][coloana2]==0&& (x>=547/rezolutie&&x<=1368/rezolutie&&y>=132/rezolutie&&y<=946/rezolutie))
               {
            if(coloana1==coloana2)
            {
                if(linia1<linia2)
                    okObstacol=amObstacolColoana(linia1,linia2,coloana1);
                else if(linia1>linia2)
                    okObstacol=amObstacolColoana(linia2,linia1,coloana1);
                if(okObstacol==1)
                {
                    TablaDeJoc[linia1][coloana1]=4;
                    deseneazaPiesa(linia1,coloana1,Tunnel);
                    TablaDeJoc[linia2][coloana2]=1;
                    deseneazaPiesa(linia2,coloana2,Rabbit);
                }
                else
                    cout<<"eroare"<<endl;
            }
            else if(linia1==linia2)
            {
                if(coloana1<coloana2)
                    okObstacol=amObstacolLinie(coloana1,coloana2,linia1);
                else if(coloana1>coloana2)
                    okObstacol=amObstacolLinie(coloana2,coloana1,linia1);
                if(okObstacol==1)
                {
                    TablaDeJoc[linia1][coloana1]=4;
                    deseneazaPiesa(linia1,coloana1,Tunnel);
                    TablaDeJoc[linia2][coloana2]=1;
                    deseneazaPiesa(linia2,coloana2,Rabbit);
                }
                else
                    cout<<"eroare"<<endl;
            } }
        //}
    }


    for(int i =0;i<=6;i++)
    {
        for(int j=0;j<=6;j++)
            cout<<TablaDeJoc[i][j]<<' ';
        cout<<endl;
    }
    cout<<endl;
    int catiIepuri=0;
    for(int i=1;i<=5;i++)
        for(int j=1;j<=5;j++)
         if(TablaDeJoc[i][j]==1)
           catiIepuri++;
    if(catiIepuri==0)
        {mutarepieseswitch=false;playnivelcreat=false;}
 }
void SettingsMenu()
{

  int ok=1;
  int x;
  int y;
cout<<rezolutie<<' '<<sunet<<' '<<limba;
  if(rezolutie==1&&sunet==1&&limba==1)
    draw(SettingsMenu1920OnE);
  if(rezolutie==1&&sunet==0&&limba==1)
    draw(SettingsMenu1920OffE);
  if(rezolutie==1.5&&sunet==1&&limba==1)
    draw(SettingsMenu1280OnE);
  if(rezolutie==1.5&&sunet==0&&limba==1)
    draw(SettingsMenu1280OffE);
  if(rezolutie==1&&sunet==1&&limba==0)
    draw(SettingsMenu1920PornitR);
  if(rezolutie==1&&sunet==0&&limba==0)
    draw(SettingsMenu1920OpritR);
  if(rezolutie==1.5&&sunet==1&&limba==0)
     draw(SettingsMenu1280PornitR);
  if(rezolutie==1.5&&sunet==0&&limba==0)
     draw(SettingsMenu1280OpritR);
  if(limba==1)
  {
  while(ok==1)
  {
     if(ismouseclick(WM_LBUTTONDOWN))
      {
           x=mousex();
           y=mousey();
      clearmouseclick(WM_LBUTTONDOWN);

      if(x>=1726/rezolutie&&x<=1867/rezolutie&&y>=967/rezolutie&&y<=1027/rezolutie)
      {

          menu=true;
          openMenuInterface();
          ok=0;
      }
      if(x>=962/rezolutie&&x<=1040/rezolutie&&y>=483/rezolutie&&y<=534/rezolutie)
      {
        if (sunet==0)
        {
            sunet=1;
            SaveSettings();
            PlaySound("dubluve.wav",NULL,SND_ASYNC|SND_LOOP);
            SettingsMenu();
        }
      }
       if(x>=1050/rezolutie&&x<=1148/rezolutie&&y>=485/rezolutie&&y<=540/rezolutie)
       {
           if(sunet==1)
           {
               sunet=0;
                SaveSettings();
               PlaySound(NULL,NULL,SND_ASYNC);
                SettingsMenu();
           }
       }
       if(x>=869/rezolutie&&x<=1112/rezolutie&&y>=259/rezolutie&&y<=302/rezolutie)
       {
           if(rezolutie==1.5)
            {
            rezolutie=1;
            SaveSettings();
            closegraph();
            initwindow(Max_Resolution_X/rezolutie,Max_Resolution_Y/rezolutie);
            SettingsMenu();

            }
       }
       if(x>=1121/rezolutie&&x<=1341/rezolutie&&y>=257/rezolutie&&y<=301/rezolutie)
       {
           if(rezolutie==1)
           {
               rezolutie=1.5;
            SaveSettings();
            closegraph();
            initwindow(Max_Resolution_X/rezolutie,Max_Resolution_Y/rezolutie);
            SettingsMenu();
           }
       }
       if(x>=1059/rezolutie&&x<=1297/rezolutie&&y>=713/rezolutie&&y<=762/rezolutie)
       {
           limba=0;
            SaveSettings();
           SettingsMenu();
       }
      }
  }
  }
  else if(limba==0)////////////////////////////////RO////////
  {
    while(ok==1)
  {
     if(ismouseclick(WM_LBUTTONDOWN))
      {
           x=mousex();
           y=mousey();
      clearmouseclick(WM_LBUTTONDOWN);

      if(x>=1726/rezolutie&&x<=1885/rezolutie&&y>=948/rezolutie&&y<=1018/rezolutie)
      {

          menu=true;
          openMenuInterface();
          ok=0;
      }
      if(x>=896/rezolutie&&x<=1057/rezolutie&&y>=480/rezolutie&&y<=538/rezolutie)
      {
        if (sunet==0)
        {
            sunet=1;
            SaveSettings();
            PlaySound("dubluve.wav",NULL,SND_ASYNC|SND_LOOP);
             SettingsMenu();

        }
      }
       if(x>=1066/rezolutie&&x<=1203/rezolutie&&y>=481/rezolutie&&y<=538/rezolutie)
       {
           if(sunet==1)
           {
               sunet=0;
                SaveSettings();
               PlaySound(NULL,NULL,SND_ASYNC);
                SettingsMenu();
           }
       }
      if(x>=857/rezolutie&&x<=1091/rezolutie&&y>=263/rezolutie&&y<=297/rezolutie)
       {
           if(rezolutie==1.5)
            {
            rezolutie=1;
            SaveSettings();
            closegraph();
            initwindow(Max_Resolution_X/rezolutie,Max_Resolution_Y/rezolutie);
            SettingsMenu();

            }
       }
       if(x>=1118/rezolutie&&x<=1332/rezolutie&&y>=260/rezolutie&&y<=301/rezolutie)
       {
           if(rezolutie==1)
           {
               rezolutie=1.5;
            SaveSettings();
            closegraph();
            initwindow(Max_Resolution_X/rezolutie,Max_Resolution_Y/rezolutie);
            SettingsMenu();
           }
       }
       if(x>=861/rezolutie&&x<=1041/rezolutie&&y>=711/rezolutie&&y<=763/rezolutie)
       {
           limba=1;
            SaveSettings();
           SettingsMenu();
       }
      }
  }
  }
}
void RulesMenu()
{ int ok=1;
  int x;
  int y;

  if(limba==1)
  {
  draw(GameRules);
  while(ok==1)
  {
     if(ismouseclick(WM_LBUTTONDOWN))
      {
           x=mousex();
           y=mousey();
      clearmouseclick(WM_LBUTTONDOWN);

      if(x>=1726/rezolutie&&x<=1867/rezolutie&&y>=967/rezolutie&&y<=1027/rezolutie)
      {

          menu=true;
          ok=0;
          openMenuInterface();

      }


      }
  }
  }
  else if(limba==0)//////////RO
  {
   draw(ReguliRomana);
  while(ok==1)
  {
     if(ismouseclick(WM_LBUTTONDOWN))
      {
           x=mousex();
           y=mousey();
      clearmouseclick(WM_LBUTTONDOWN);

      if(x>=1726/rezolutie&&x<=1885/rezolutie&&y>=948/rezolutie&&y<=1018/rezolutie)
      {

          menu=true;
           ok=0;
          openMenuInterface();

      }


      }
  }
  }
}
void updateMenu();
void updateMenu()
{   int x=mousex();
    int y=mousey();
    clearmouseclick(WM_LBUTTONDOWN);

 if(limba==1)
 {
    if(ismouseclick(WM_MOUSEMOVE))
      {
           x=mousex();
           y=mousey();
      }
    clearmouseclick(WM_MOUSEMOVE);

    if(x>=865/rezolutie&&x<=1019/rezolutie&&y>=292/rezolutie&&y<=351/rezolutie)//
        {
             draw(PlayButtonHighlight);
              if(ismouseclick(WM_LBUTTONDOWN))
              {
                  clearmouseclick(WM_LBUTTONDOWN);
                  menu=false;
                  interfata=true;
                  InterfataPlay();
              }
        }
    else if(x>=837/rezolutie&&x<=1083/rezolutie&&y>=440/rezolutie&&y<=506/rezolutie)
        {
            draw(SettingsButtonHighlight);
             if(ismouseclick(WM_LBUTTONDOWN))
              {
                  clearmouseclick(WM_LBUTTONDOWN);
                  menu=false;
                  SettingsMenu();
              }
        }
    else if(x>=869/rezolutie&&x<=1041/rezolutie&&y>=584/rezolutie&&y<=639/rezolutie)
        {
            draw(RulesButtonHighlight);
             if(ismouseclick(WM_LBUTTONDOWN))
              {
                  clearmouseclick(WM_LBUTTONDOWN);
                  menu=false;
                  RulesMenu();
              }
        }
    else if(x>=891/rezolutie&&x<=1032/rezolutie&&y>=729/rezolutie&&y<=788/rezolutie)
        {
            draw(QuitButtonHighlight);
             if(ismouseclick(WM_LBUTTONDOWN))
              {
                  clearmouseclick(WM_LBUTTONDOWN);
                  menu=false;
                  exit(1);
              }
        }
    else
        draw(Meniu);

   }
   else if(limba==0)///////////////////////RO
   {
      if(ismouseclick(WM_MOUSEMOVE))
      {
           x=mousex();
           y=mousey();
      }
    clearmouseclick(WM_MOUSEMOVE);

    if(x>=867/rezolutie&&x<=1047/rezolutie&&y>=282/rezolutie&&y<=355/rezolutie)//
        {
             draw(MeniuRomanaJoc);
              if(ismouseclick(WM_LBUTTONDOWN))
              {
                  clearmouseclick(WM_LBUTTONDOWN);
                  menu=false;
                 interfata=true;
                  InterfataPlay();
              }
        }
    else if(x>=848/rezolutie&&x<=1085/rezolutie&&y>=434/rezolutie&&y<=513/rezolutie)
        {
            draw(MeniuRomanaOptiuni);
             if(ismouseclick(WM_LBUTTONDOWN))
              {
                  clearmouseclick(WM_LBUTTONDOWN);
                  menu=false;
                  SettingsMenu();
              }
        }
    else if(x>=853/rezolutie&&x<=1056/rezolutie&&y>=577/rezolutie&&y<=644/rezolutie)
        {
            draw(MeniuRomanaReguli);
             if(ismouseclick(WM_LBUTTONDOWN))
              {
                  clearmouseclick(WM_LBUTTONDOWN);
                  menu=false;
                  RulesMenu();
              }
        }
    else if(x>=895/rezolutie&&x<=1020/rezolutie&&y>=723/rezolutie&&y<=801/rezolutie)
        {
            draw(MeniuRomanaInchidereJoc);
             if(ismouseclick(WM_LBUTTONDOWN))
              {
                  clearmouseclick(WM_LBUTTONDOWN);
                  menu=false;
                  exit(1);
              }
        }
    else
        draw(MeniuRomana);
   }
}
void openMenuInterface()
{
    while(menu)
    {
        updateMenu();
    }
}
void initializareNivel();
void InterfataPlay();
void LevelCreator()
{
    int piesa=0;
    int numar=5;
    int latime=800/rezolutie;
    int inaltime=800/rezolutie;
    int latura=latime/numar;
    int sus=(1080/rezolutie-latime)/2;
    int stanga=(1920/rezolutie-inaltime)/2;
    int linia2,coloana2,x,y;
    int click=false;

    do
        if(ismouseclick(WM_LBUTTONDOWN) && !click)
        {
            click=true;
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();
        } while (!click);

    if(x>=1440/rezolutie&&x<=1619/rezolutie&&y>=233/rezolutie&&y<=407/rezolutie) /// iepure
    {
        piesa=1;
        click=false;
        do
            if(ismouseclick(WM_LBUTTONDOWN) && !click)
            {
                click=true;
                clearmouseclick(WM_LBUTTONDOWN);
                x=mousex();
                y=mousey();
                linia2=(y-sus)/latura+1;
                coloana2=(x-stanga)/latura+1;
            }
        while (!click);
        if(TablaDeJoc[linia2][coloana2]==0 && (x>=547/rezolutie&&x<=1368/rezolutie&&y>=132/rezolutie&&y<=946/rezolutie))
            {
            TablaDeJoc[linia2][coloana2]=piesa;
            deseneazaPiesa(linia2,coloana2,Rabbit);
            }

    }
    else
    if(x>=1662/rezolutie&&x<=1858/rezolutie&&y>=265/rezolutie&&y<=411/rezolutie) /// ciuperca
        {
        piesa=5;
        click=false;
        do
            if(ismouseclick(WM_LBUTTONDOWN) && !click)
            {
                click=true;
                clearmouseclick(WM_LBUTTONDOWN);
                x=mousex();
                y=mousey();
                linia2=(y-sus)/latura+1;
                coloana2=(x-stanga)/latura+1;
            }
        while (!click);
        if(TablaDeJoc[linia2][coloana2]==0 && (x>=547/rezolutie&&x<=1368/rezolutie&&y>=132/rezolutie&&y<=946/rezolutie))
            {
                TablaDeJoc[linia2][coloana2]=piesa;
                deseneazaPiesa(linia2,coloana2,Mushroom);
            }
    }
    else
    if(x>=1457/rezolutie&&x<=1601/rezolutie&&y>=427/rezolutie&&y<=568/rezolutie) /// tunel
        {
        piesa=4;
        click=false;
        do
            if(ismouseclick(WM_LBUTTONDOWN) && !click)
            {
                click=true;
                clearmouseclick(WM_LBUTTONDOWN);
                x=mousex();
                y=mousey();
                linia2=(y-sus)/latura+1;
                coloana2=(x-stanga)/latura+1;
            }
        while (!click);
        if(TablaDeJoc[linia2][coloana2]==0 && (x>=547/rezolutie&&x<=1368/rezolutie&&y>=132/rezolutie&&y<=946/rezolutie))
            {
                TablaDeJoc[linia2][coloana2]=piesa;
                deseneazaPiesa(linia2,coloana2,Tunnel);
            }
        }
        if(x>=1681/rezolutie&&x<=1842/rezolutie&&y>=430/rezolutie&&y<=566/rezolutie) /// tunel iepure
        {
        piesa=8;
        click=false;
        do
            if(ismouseclick(WM_LBUTTONDOWN) && !click)
            {
                click=true;
                clearmouseclick(WM_LBUTTONDOWN);
                x=mousex();
                y=mousey();
                linia2=(y-sus)/latura+1;
                coloana2=(x-stanga)/latura+1;
            }
        while (!click);
        if(TablaDeJoc[linia2][coloana2]==0 && (x>=547/rezolutie&&x<=1368/rezolutie&&y>=132/rezolutie&&y<=946/rezolutie))
            {
                TablaDeJoc[linia2][coloana2]=piesa;
                deseneazaPiesa(linia2,coloana2,TunnelWithRabbit);
            }
        }
        else
    if(x>=1464/rezolutie&&x<=1613/rezolutie&&y>=612/rezolutie&&y<=737/rezolutie) /// vulpe orizontala
{   if(nrVulpiOriz==1)
    {
        piesa=7;
        click=false;
        do
            if(ismouseclick(WM_LBUTTONDOWN) && !click)
            {
                click=true;
                clearmouseclick(WM_LBUTTONDOWN);
                x=mousex();
                y=mousey();
                linia2=(y-sus)/latura+1;
                coloana2=(x-stanga)/latura+1;
            }
        while (!click);
        if(TablaDeJoc[linia2][coloana2]==0 && (x>=547/rezolutie&&x<=1368/rezolutie&&y>=132/rezolutie&&y<=946/rezolutie) && !(coloana2==5)&& TablaDeJoc[linia2][coloana2+1]==0)
            {
                TablaDeJoc[linia2][coloana2]=piesa;
                TablaDeJoc[linia2][coloana2+1]=piesa;
                deseneazaPiesa(linia2,coloana2,VulpeOrizontalaStangaCap);
                deseneazaPiesa(linia2,coloana2+1,VulpeOrizontalaStangaCoada);
                nrVulpiOriz--;
                readimagefile(PlayInitializareNivel,1464/rezolutie,612/rezolutie,1613/rezolutie,737/rezolutie);
            }

    }
}
    else
    if(x>=1709/rezolutie&&x<=1805/rezolutie&&y>=586/rezolutie&&y<=744/rezolutie) /// vulpe verticala
{    if(nrVulpiVer==1)
     {


        piesa=2;
        click=false;
        do
            if(ismouseclick(WM_LBUTTONDOWN) && !click)
            {
                click=true;
                clearmouseclick(WM_LBUTTONDOWN);
                x=mousex();
                y=mousey();
                linia2=(y-sus)/latura+1;
                coloana2=(x-stanga)/latura+1;
            }
        while (!click);
        if(TablaDeJoc[linia2][coloana2]==0 && (x>=547/rezolutie&&x<=1368/rezolutie&&y>=132/rezolutie&&y<=946/rezolutie) && !(linia2==1) && TablaDeJoc[linia2-1][coloana2]==0)
            {
                TablaDeJoc[linia2][coloana2]=piesa;
                TablaDeJoc[linia2-1][coloana2]=piesa;
                deseneazaPiesa(linia2,coloana2,VulpeVerticalaJosCap);
                deseneazaPiesa(linia2-1,coloana2,VulpeVerticalaJosCoada);
                nrVulpiVer--;
                readimagefile(PlayInitializareNivel,1709/rezolutie,586/rezolutie,1805/rezolutie,744/rezolutie);
            }
}
}
        else if(x>=71/rezolutie&&x<=304/rezolutie&&y>=162/rezolutie&&y<=396/rezolutie)
        {
           playnivelcreat=1;
           readimagefile(PlayInitializareNivel,0,0,547/rezolutie,1080/rezolutie);
           readimagefile(PlayInitializareNivel,1378/rezolutie,0,1920/rezolutie,1080/rezolutie);
           do{
            mutarePiesa();}while(playnivelcreat==1);
            if(playnivelcreat==0)
                initializareNivel();

        }
        else if(x>=72/rezolutie&&x<=287/rezolutie&&y>=486/rezolutie&&y<=684/rezolutie)
        {
             FILE* nivel_creare=fopen("nivel_creare.txt","w");
            for(int i=1;i<=5;i++)
            for(int j=1;j<=5;j++)
            {
                fprintf(nivel_creare,"%d",TablaDeJoc[i][j]);
                fprintf(nivel_creare,"%s"," ");

            }
            fclose(nivel_creare);
            ShellExecuteA(NULL, "open", "nivel_creare.txt", NULL, NULL, 5);
        }
        else if(x>=71/rezolutie&&x<=292/rezolutie&&y>=749/rezolutie&&y<=960/rezolutie)
        {
            interfata=true; StartSettings();
            InterfataPlay();
        }
    for(int i=1;i<=5;i++)
    {for(int j=1;j<=5;j++)
    cout<<TablaDeJoc[i][j]<<' ';
    cout<<endl;
    }
    cout<<endl;


}

void initializareNivel()
{
    for(int i=0; i<=xjoc; i++)
    {
        TablaDeJoc[i][0]=9;
        TablaDeJoc[i][yjoc]=9;
    }
    for(int i=0; i<=yjoc; i++)
    {
        TablaDeJoc[0][i]=9;
        TablaDeJoc[xjoc][i]=9;
    }
    draw(CreareNivel);
    for(int i=1;i<=5;i++)
        for(int j=1;j<=5;j++)
       {
        TablaDeJoc[i][j]=0;
        deseneazaPiesa(i,j,Patrat);
        }
    nrVulpiOriz=1;
    nrVulpiVer=1;

    do{
        LevelCreator();
    }while(crearenivelswitch==true);

}
void citesteSir(char s[50],int x, int y)
{
    draw(Atasare);
    int testVulpiVert=0;
    int testVulpiOriz=0;
    strcpy(s,"");
    char s1[50];
    char t[2];
    char tasta;
    t[0]=tasta;
    t[1]='\0';
    strcat(s,t);
    s[0]='\0';
    strcpy(s1,s);
    strcat(s1,"_");
    settextstyle(1,HORIZ_DIR,1);
    setcolor(WHITE);
    outtextxy(x,y,s1);


    do
    {
        tasta=getch();
        if (tasta==8) // backspace
            if (strlen(s)>0)
            {
                setcolor(BLACK);
                strcpy(s1,s);
                strcat(s1,"_");
                outtextxy(x,y,s1);
                s[strlen(s)-1]='\0';
                strcpy(s1,s);
                strcat(s1,"_");
                outtextxy(x,y,s1);
                setcolor(WHITE);
                outtextxy(x,y,s1);
            }
            else
                Beep(1000,100);
        else if (tasta!=13&&strlen(s)<=49)
        {
            t[0]=tasta;
            t[1]='\0';
            strcat(s,t);
            strcpy(s1,s);
            strcat(s," ");
            strcat(s1,"_");
            setcolor(WHITE);
            outtextxy(x,y,s1);
        }

    }
    while (tasta!=13);
    strcat(s1,"_");
    setcolor(BLACK);
    outtextxy(x,y,s1);
    setcolor(WHITE);
   for(int i=1;i<=5;i++)
        for(int j=1;j<=5;j++)
            TablaDeJoc[i][j]=0;
    fseek(lvl,0,SEEK_SET);
    fprintf(lvl,"%s",sirSpatii);
    fseek(lvl,0,SEEK_SET);
    fprintf(lvl,"%s",atasareNivel);
    fseek(lvl,0,SEEK_SET);
    for(int i=1;i<=5;i++)
        for(int j=1;j<=5;j++)
    {
        fscanf(lvl,"%d ",&TablaDeJoc[i][j]);

    }

    for(int i=1;i<=5;i++)
        for(int j=1;j<=5;j++)
        {
            if((TablaDeJoc[i][j]==3||TablaDeJoc[i][j]==6||TablaDeJoc[i][j]==9)&&(i>=1&&i<=5&&j>=1&&j<=5))
            {
                cout<<"piese invalide"<<TablaDeJoc[i][j]<<i<<' '<<j;
                 for(int i=1;i<=5;i++)
              for(int j=1;j<=5;j++)
                TablaDeJoc[i][j]=0;
                interfata=true;
                InterfataPlay();
            }
        else if(TablaDeJoc[i][j]==2)
        {
            if(TablaDeJoc[i+1][j]!=2)
            {
                if(TablaDeJoc[i-1][j]!=2)
                {
                    cout<<"jos"<<' '<<j;
                    for(int i=1; i<=5; i++)
                        for(int j=1; j<=5; j++)
                            TablaDeJoc[i][j]=0;
                    interfata=true;
                    InterfataPlay();
                }
                for(i=1; i<=5; i++)
                    if(TablaDeJoc[i][j]==2)
                        testVulpiVert++;
                if(testVulpiVert!=2)
                {
                    for(int i=1; i<=5; i++)
                        for(int j=1; j<=5; j++)
                            TablaDeJoc[i][j]=0;
                    interfata=true;
                    InterfataPlay();
                }
            }
        }
        else if(TablaDeJoc[i][j]==7)
        {

            if(TablaDeJoc[i][j+1]!=7)
            {
                if(TablaDeJoc[i][j-1]!=7)
                {
                    cout<<"dreapta"<<' '<<j;
                    for(int i=1; i<=5; i++)
                        for(int j=1; j<=5; j++)
                            TablaDeJoc[i][j]=0;
                    interfata=true;
                    InterfataPlay();
                }
            }
             for(j=1; j<=5; j++)
                if(TablaDeJoc[i][j]==7)
                    testVulpiOriz++;
            if(testVulpiOriz!=2)
            {
                for(int i=1; i<=5; i++)
                    for(int j=1; j<=5; j++)
                        TablaDeJoc[i][j]=0;
                interfata=true;
                InterfataPlay();
            }
        }

    }
              citiresirswitch=true;
               PlayMenu(-7,0);



}
void updateInterfataPlay()
{
    int x=mousex();
    int y=mousey();
    clearmouseclick(WM_LBUTTONDOWN);

    if(ismouseclick(WM_MOUSEMOVE))
      {
           x=mousex();
           y=mousey();
      }
    clearmouseclick(WM_MOUSEMOVE);
    if(x>=827/rezolutie&&x<=1115/rezolutie&&y>=378/rezolutie&&y<=674/rezolutie)
      {
          draw(InterfataPlayPlay);
          if(ismouseclick(WM_LBUTTONDOWN))
              {
                  clearmouseclick(WM_LBUTTONDOWN);
                  interfata=false;
                  declarariMeniuNivele();
              }
      }
    else
    if(x>=400/rezolutie&&x<=680/rezolutie&&y>=378/rezolutie&&y<=673/rezolutie)
     {
         draw(InterfataPlayAgrafa);
         if(ismouseclick(WM_LBUTTONDOWN))
              {
                  clearmouseclick(WM_LBUTTONDOWN);
                  interfata=false;
                  citesteSir(atasareNivel,525/rezolutie,550/rezolutie);
              }
     }
    else
    if(x>=1232/rezolutie&&x<=1620/rezolutie&&y>=378/rezolutie&&y<=693/rezolutie)
   {
       draw(InterfataPlayTarnacop);
       if(ismouseclick(WM_LBUTTONDOWN))
              {
                  clearmouseclick(WM_LBUTTONDOWN);
                  interfata=false;
                  initializareNivel();
              }
   }
    else
    if(x>=828/rezolutie&&x<=1109/rezolutie&&y>=730/rezolutie&&y<=1009/rezolutie)
    {
        draw(InterfataPlayBack);
         if(ismouseclick(WM_LBUTTONDOWN))
              {
                  clearmouseclick(WM_LBUTTONDOWN);
                  interfata=false;
                  menu=true;
                  openMenuInterface();
              }
    }
    else draw(interfataPlayDefault);


}
void InterfataPlay()
{
     while(interfata)
     {
         updateInterfataPlay();
     }
}
int main()
{
    StartSettings();
    citireNivel();
    initwindow(Max_Resolution_X/rezolutie,Max_Resolution_Y/rezolutie);

    if(sunet==1)
    PlaySound("dubluve.wav",NULL,SND_ASYNC|SND_LOOP);
  openMenuInterface();

    getch();
    closegraph();
    return 0;
}

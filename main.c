#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.c>
#include <string.h>
#include "portugues.h" //1
#include "ingles.h" // 2
#include "espanhol.h" // 3

struct first_menu{
    int menu;
}menu;

int main()
{
    setlocale(LC_ALL, "Portuguese");
            //////////
            // MENU //
            //////////
    int voltar;
    do{
    printf("---------------------------\n");
    printf("Language: \n");
    textcolor(LIGHTRED);
    printf("1-PT\n");
    textcolor(LIGHTBLUE);
    printf("2-ENG\n");
    textcolor(YELLOW);
    printf("3-ES\n");
    textcolor(LIGHTCYAN);
    printf("--> ");
    textcolor(WHITE);
    scanf("%i",&menu.menu);
    printf("---------------------------\n");
    switch(menu.menu)
    {
        // PORTUGUÊS
        case 1: printf("PT\n");
        system("cls");
        portuguese_menu();
        break;
        // INGLÊS
        case 2: printf("ENG\n");
        system("cls");
        ingles_menu();
        break;
        // ESPANHOL
        case 3: printf("ES\n");
        system("cls");
        espanhol_menu();
        break;

        default: printf("ERRO! REINICIE O SISTEMA!\n");break;
    }
    textcolor(LIGHTRED);
    printf("---------------------------------------------------\n");
    textcolor(LIGHTRED);
    printf("Concluido. Deseja voltar ao ínicio?\n 1-Sim\n 2-Não\n");
    textcolor(LIGHTRED);
    printf("---------------------------------------------------\n");
    textcolor(WHITE);
    scanf("%i",&voltar);
    fflush(stdin);
    system("cls");
    }while(voltar==1);

        return 0;
}

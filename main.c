#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.c>
#include "portugues.h"

struct first_menu{
    int menu;
}menu;

int main()
{
    setlocale(LC_ALL, "Portuguese");
            //////////
            // MENU //
            //////////
    printf("---------------------------\n");
    printf("Language: \n");
    textcolor(LIGHTRED);
    printf("1-PT\n");
    textcolor(LIGHTBLUE);
    printf("2-ENG\n");
    textcolor(YELLOW);
    printf("3-ES\n");
    textcolor(BLUE);
    printf("4-FR\n");
    textcolor(WHITE);
    printf("--> ");
    scanf("%i",&menu.menu);
    printf("---------------------------\n");
    switch(menu.menu)
    {
        // PORTUGUÊS
        case 1: printf("PT\n");
        system("cls");
        portuguese_first();
        break;
        // INGLÊS
        case 2: printf("ENG\n");
        system("cls");
        //call_first();
        break;
        // ESPANHOL
        case 3: printf("ES\n");
        system("cls");
        //call_first();
        break;
        // FRANCÊS
        case 4: printf("FR\n");
        system("cls");
        //call_first();
        break;

        default: printf("ERRO! REINICIE O SISTEMA!\n");
    }
        return 0;
}

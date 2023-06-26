#ifndef INGLES_H_INCLUDED
#define INGLES_H_INCLUDED


#define MAX_DOENCAS 10
struct relatorio_ingles{
    int idade;
    char sexo[10];
    char local[100];
    int telefone;
    int estado;
    int estado_mau;
    int suporte_vida;
    char doenca[100];
}rela_ingles;

struct incendio_ingles{
    int tipo;
    char nome[30];
    int telefone;
    char local_incendio[100];
}inc_ingles;

struct acidente_ingles{
    char nome[30];
    int telefone;
    int idade_vitima;
    char local_acidente[100];
    int vitima;
    int estado_vitima;
}aci_ingles;

struct relatorio_com_vetor_ingles{
    struct relatorio rel;
    char doenca[MAX_DOENCAS][100];
};

void ingles_menu() {
    int opcao;
    FILE* ficheiro;
    int num = 0;
    FILE* contador;
    FILE* tipoincendio;
    FILE* rela_acidente;
    textcolor(LIGHTBLUE);
    printf(R"EOF(
                                       __     __     _____
                                      /  |   /  |   / ___ `.
                                      `| |   `| |  |_/___) |
                                       | |    | |   .'____.'
                                      _| |_  _| |_ / /_____
                                     |_____||_____||_______|
                  )EOF");
    textcolor(LIGHTGRAY);
    printf("\n\n                       Hello, this is about the medical emergency!\n                       How can I help??");
    textcolor(YELLOW);
    printf("\n\n                       1-MEDICAL EMERGENCY");
    textcolor(LIGHTRED);
    printf("\n\n                       2-RURAL FIRE\n                        |FORESTRY\n                        |INDUSTRIAL\n                        ----------------");
    textcolor(LIGHTBLUE);
    printf("\n\n                       3-ACCIDENTS");
    textcolor(LIGHTGRAY);
    printf("\n\n                       4-QUIT\n\n");
    printf("\n\n --> ");
    textcolor(WHITE);
    scanf("%i", &opcao);
    fflush(stdin);
    switch(opcao)
    {
        // EMERGÊNCIA MÉDICA                                                                                                                                                                      // EMERGÊNCIA MÉDICA
        case 1:
            system("cls");
        textcolor(LIGHTRED);
            printf(R"EOF(

   o_______________}o{
   |              |   \
   |    112       |____\_____
   | _____        |    |_o__ |
   [/ ___ \       |   / ___ \|
  []_/.-.\_\______|__/_/.-.\_[]
     |(O)|             |(O)|
      '-'   ScS         '-'
---   ---   ---   ---   ---   ---
                         )EOF");

            textcolor(LIGHTBLUE);
            printf("\n   MEDICAL EMERGENCY\n");

            textcolor(LIGHTGREEN);
            // info do relatório
            printf("Enter the person's age:\n -->");
            textcolor(WHITE);
            scanf("%i",&rela.idade);
            fflush(stdin);

            textcolor(LIGHTMAGENTA);
            printf("Enter the person's gender (M or F):\n -->");
            textcolor(WHITE);
            scanf("%s",&rela.sexo);
            fflush(stdin);

            textcolor(LIGHTBLUE);
            printf("Enter this phone number:\n  (9 digits)-->");
            textcolor(WHITE);
            scanf("%i", &rela.telefone);
            fflush(stdin);

            textcolor(LIGHTCYAN);
            printf("Describe as much as possible where you are.\n (Example: Entrecampos, inside the station next to the ticket office):\n");
            textcolor(WHITE);
            fgets(rela.local, 100, stdin);

            textcolor(LIGHTRED);
            printf("Tell if the Individual suffers from any disease:\n");
            textcolor(WHITE);
            fgets(rela.doenca, 100, stdin);

            ficheiro = fopen("ocorrencia.txt", "a");
            fprintf(ficheiro, "-------------- OCORRÊNCIA %i --------------\n", num);
            fprintf(ficheiro, "Idade do Indivíduo: %i\n", rela.idade);
            fprintf(ficheiro, "Sexo do Indivíduo: %s\n", rela.sexo);
            fprintf(ficheiro, "Telefone do Indivíduo: %i\n", rela.telefone);
            fprintf(ficheiro, "Local: %s\n",rela.local);
            fprintf(ficheiro, "Doença: %s\n",rela.doenca);

            // ESTADO DO INDIVÍDUO                                                                                                                                       // EMERGENCIA MEDICA - ESTADO DO INDIVIDUO
            textcolor(LIGHTGREEN);
            printf("Is the individual in good condition?\n1-Yes\n2-No\n -->");
            textcolor(WHITE);
            scanf("%i",&rela.estado);
            fflush(stdin);
            if(rela.estado==1)
            {
                // BOM ESTADO
                printf("Individual in good condition: If the individual is in good condition,\njust wait for our vehicle to travel to the rescue location.\n");
            } else{
                // MAU ESTADO
                            textcolor(LIGHTRED);
                printf("Subject in poor condition: Is the subject short of breath or unconscious?\n1-Yes\n2-No\n -->");
                textcolor(WHITE);
                scanf("%i",&rela.estado_mau);
                fflush(stdin);
                if(rela.estado_mau==1)
                {
                                textcolor(LIGHTRED);
                // ESTADO MAU - O QUE SE FAZER??
                printf("Do you know how to perform basic life support?\n1-Yes\n2-No\n -->");
                textcolor(WHITE);
                scanf("%i",&rela.suporte_vida);
                fflush(stdin);
                if(rela.suporte_vida==1)
                {
                    // SABE SUPORTE BÁSICO DE VIDA
                    printf("You can start doing BASIC LIFE SUPPORT.\n Pay close attention and be relaxed.\n");
                } else if(rela.idade<18)
                {
                    textcolor(LIGHTBLUE);
                    // ENSINAR SUPORTE BÁSICO DE VIDA CRIANÇA
                    printf("As soon as you verify that the infant/child is not breathing normally, give 5 breaths with only the amount of air needed to effectively expand the chest.\n");
                    printf("Adapt the compressions to the size of the victim: if a baby up to one year old, use only 2 fingers and if a child up to 8 years old, just one hand, depressing up to 1/3 of the chest height.\n");
                } else{
                    textcolor(LIGHTGREEN);
                    // ENSINAR SUPORTE BÁSICO DE VIDA ADULTO
                    printf("Lay the victim on the ground with his stomach facing up,\n place your hands overlapping with fingers interlaced in the middle of the victim's chest.\n");
                    printf("With your arms straight and perpendicular to the victim's body, press the chest, making it visibly lower and relieve.\n Repeat this compression and decompression movement of the victim's chest 30 times at a rate of 100 to 120 per minute.\ n");
                    printf("After 30 compressions, give two breaths through the victim's mouth. To do this, fill your lungs with air and exhale into the victim's mouth,\n covering his nose with your fingers and isolating the victim's lips with your lips, so that there is no air leakage.\n Although mouth ventilation -to-mouth is relatively safe, with no cases of serious infection described, the use of resuscitation masks is recommended. In cases where ventilations are not possible, perform compressions only.\n");
                    printf("After ventilating, resume compressions and always follow the sequence of 30 chest compressions with 2 breaths. Keep maneuvering until help arrives or the victim recovers.\n");
                }
                } else{
                // BOM ESTADO
                textcolor(LIGHTGRAY);
                printf("Individual in good condition: If the individual is in good condition,\njust wait for our vehicle to travel to the rescue location.\n");
                }
            }
            fclose(ficheiro);
            break;

        // INCÊNDIOS
        case 2:
            system("cls");
            textcolor(LIGHTRED);
            printf("  FIRE\n");
            textcolor(LIGHTCYAN);
            printf("What is the type of fire:\n1-Rural Fire\n2-Forest Fire\n3-Industrial Fire\n --> ");
            textcolor(WHITE);
            scanf("%i", &inc.tipo);
            fflush(stdin);
            switch(inc.tipo)
            {
                case 1: textcolor(LIGHTBLUE);                                                                                                                                                                                          // incendio rural
                        printf("  COUNTRY FIRE  \n");
                        // rural
                        textcolor(LIGHTCYAN);
                        printf("What is your name?\n");
                        textcolor(WHITE);
                        scanf("%s",&inc.nome);
                        fflush(stdin);
                        textcolor(LIGHTGREEN);
                        printf("Where is the fire site?\n");
                        textcolor(WHITE);
                        scanf("%s",&inc.local_incendio);
                        fflush(stdin);
                        textcolor(LIGHTMAGENTA);
                        printf("What is your phone number\n");
                        textcolor(WHITE);
                        scanf("%i",&inc.telefone);
                        fflush(stdin);

                        tipoincendio = fopen("incendio.txt", "a");
                        fprintf(tipoincendio, "--------------  CHAMADA DE INCÊNDIO  --------------\n");
                        fprintf(tipoincendio, "Tipo de Incêndio: INCÊNDIO RURAL\n");
                        fprintf(tipoincendio, "Nome: %s\n",inc.nome);
                        fprintf(tipoincendio, "Local: %s\n",inc.local_incendio);
                        fprintf(tipoincendio, "Telefone: %i\n",inc.telefone);

                        break;

                case 2: textcolor(LIGHTRED);
                        printf("  FOREST FIRE  \n");                                                                                                                                                                                  // incendio florestal
                        // florestal
                        textcolor(LIGHTCYAN);
                        printf("What is your name?\n");
                        textcolor(WHITE);
                        scanf("%s",&inc.nome);
                        fflush(stdin);
                        textcolor(LIGHTGREEN);
                        printf("Where is the fire site?\n");
                        textcolor(WHITE);
                        scanf("%s",&inc.local_incendio);
                        fflush(stdin);
                        textcolor(LIGHTMAGENTA);
                        printf("What is your phone number\n");
                        textcolor(WHITE);
                        scanf("%i",&inc.telefone);
                        fflush(stdin);

                        tipoincendio = fopen("incendio.txt", "a");
                        fprintf(tipoincendio, "--------------  CHAMADA DE INCÊNDIO  --------------\n");
                        fprintf(tipoincendio, "Tipo de Incêndio: INCÊNDIO FLORESTAL\n");
                        fprintf(tipoincendio, "Nome: %s\n",inc.nome);
                        fprintf(tipoincendio, "Local: %s\n",inc.local_incendio);
                        fprintf(tipoincendio, "Telefone: %i\n",inc.telefone);
                        break;

                case 3: textcolor(LIGHTGREEN);                                                                                                                                                                                         // incendio industrial
                        printf("  INDUSTRIAL FIRE  \n");
                        // industrial
                        printf("What is your name?\n");
                        textcolor(WHITE);
                        scanf("%s",&inc.nome);
                        fflush(stdin);

                        printf("Where is the fire site?\n");
                        textcolor(WHITE);
                        scanf("%s",&inc.local_incendio);
                        fflush(stdin);

                        printf("What is your phone number\n");
                        textcolor(WHITE);
                        scanf("%i",&inc.telefone);
                        fflush(stdin);

                        ficheiro = fopen("incendio.txt", "a");
                        fprintf(tipoincendio, "--------------  CHAMADA DE INCÊNDIO  --------------\n");
                        fprintf(tipoincendio, "Tipo de Incêndio: INCÊNDIO INDUSTRIAL\n");
                        fprintf(tipoincendio, "Nome: %s\n",inc.nome);
                        fprintf(tipoincendio, "Local: %s\n",inc.local_incendio);
                        fprintf(tipoincendio, "Telefone: %i\n",inc.telefone);

                        break;
                        default: printf("Encontramos algum problema, repita o programa.\n");break;
            }
            fclose(tipoincendio);
            break;

        // ACIDENTES
        case 3:                                                                                                                                                                                         // ACIDENTE
            system("cls");
            textcolor(LIGHTRED);
            printf("  ACCIDENT\n");
            textcolor(LIGHTCYAN);

            printf("What is your name?\n");
            textcolor(WHITE);
            scanf("%s",&aci.nome);
            fflush(stdin);

            printf("Enter the person's age:\n -->");
            textcolor(WHITE);
            scanf("%i",&aci.idade_vitima);
            fflush(stdin);

            printf("Where is the location of the Accident?\n");
            scanf("%s",&aci.local_acidente);
            fflush(stdin);

            printf("What is your phone number\n");
            textcolor(WHITE);
            scanf("%i",&aci.telefone);
            fflush(stdin);

            printf("Is there any victim?\n1-Yes\n2-No\n--> ");
            textcolor(WHITE);
            scanf("%i",&aci.vitima);
            fflush(stdin);
            if(aci.vitima==1)
            {
                printf("How is the victim?\n1-Good\n2-Bad\n--> ");
                textcolor(WHITE);
                scanf("%i",&aci.estado_vitima);
                if(aci.estado_vitima==2)
                {
                    printf("The Medical Emergency also comes to meet the place. Hope you wait.\n For the teams to arrive on site.\n");
                } else{
                    printf("Just wait for the firefighters to arrive to help.\n");
                }
            }

            rela_acidente = fopen("acidente.txt", "a");
                        fprintf(rela_acidente, "--------------  CHAMADA DE ACIDENTE  --------------\n");
                        fprintf(rela_acidente, "Tipo: ACIDENTE\n");
                        fprintf(rela_acidente, "Nome: %s\n",aci.nome);
                        fprintf(rela_acidente, "Idade do Indivíduo: %i\n",aci.idade_vitima);
                        fprintf(rela_acidente, "Local: %s\n",aci.local_acidente);
                        fprintf(rela_acidente, "Telefone: %i\n",aci.telefone);
                        fclose(rela_acidente);
            break;
        // SAIR
        case 4:
            printf("Press enter to exit...");
            getchar(); // Espera pela entrada de um caractere
            break;
            textcolor(RED);
        default: printf("Error!!\n Did you type a wrong character?\n Repeat the program.\n");
}
}

#endif // INGLES_H_INCLUDED

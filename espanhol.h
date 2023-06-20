#ifndef ESPANHOL_H_INCLUDED
#define ESPANHOL_H_INCLUDED



#define MAX_DOENCAS 10

struct relatorio_espanhol{
    int idade;
    char sexo[10];
    char local[100];
    int telefone;
    int estado;
    int estado_mau;
    int suporte_vida;
    char doenca[100];
}rela_espanhol;

struct incendio_espanhol{
    int tipo;
    char nome[30];
    int telefone;
    char local_incendio[100];
}inc_espanhol;

struct acidente_espanhol{
    char nome[30];
    int telefone;
    int idade_vitima;
    char local_acidente[100];
    int vitima;
    int estado_vitima;
}aci_espanhol;

struct relatorio_com_vetor_espanhol{
    struct relatorio rel;
    char doenca[MAX_DOENCAS][100];
};

void espanhol_menu() {
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
    printf("\n\n                       ¡Hola, esto es una emergencia médica!\n                       ¿Cómo puedo ayudarlo???");
    textcolor(YELLOW);
    printf("\n\n                       1-EMERGENCIA MÉDICA");
    textcolor(LIGHTRED);
    printf("\n\n                       2-FUEGO PAÍS\n                        |FORESTAL\n                        |INDUSTRIAL\n                        ----------------");
    textcolor(LIGHTBLUE);
    printf("\n\n                       3-Accidentes");
    textcolor(LIGHTGRAY);
    printf("\n\n                       4-SALIR\n\n");
    printf("\n\n --> ");
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
            printf("\n   EMERGÊNCIA MÉDICA\n");

            textcolor(LIGHTGREEN);
            // info do relatório
            printf("Ingresa la edad de la persona:\n -->");
            scanf("%i",&rela.idade);
            fflush(stdin);

            textcolor(LIGHTMAGENTA);
            printf("Ingrese el sexo de la persona (M o F):\n -->");
            scanf("%s",&rela.sexo);
            fflush(stdin);

            textcolor(LIGHTBLUE);
            printf("Ingrese este número de teléfono:\n (9 dígitos)-->");
            scanf("%i", &rela.telefone);
            fflush(stdin);

            textcolor(LIGHTCYAN);
            printf("Describe lo más posible dónde te encuentras.\n (Ejemplo: Entrecampos, dentro de la estación al lado de la taquilla):\n");
            fgets(rela.local, 100, stdin);

            textcolor(LIGHTRED);
            printf("Decir si el individuo padece alguna enfermedad:\n");
            fgets(rela.doenca, 100, stdin);

            ficheiro = fopen("ocorrencia.txt", "a");
            fprintf(ficheiro, "-------------- OCURRENCIA %i --------------\n", num);
            fprintf(ficheiro, "Edad del individuo: %i\n", rela.idade);
            fprintf(ficheiro, "Género del individuo: %s\n", rela.sexo);
            fprintf(ficheiro, "Teléfono del individuo: %i\n", rela.telefone);
            fprintf(ficheiro, "Local: %s\n",rela.local);
            fprintf(ficheiro, "Enfermedad: %s\n",rela.doenca);

            // ESTADO DO INDIVÍDUO                                                                                                                                       // EMERGENCIA MEDICA - ESTADO DO INDIVIDUO
            textcolor(LIGHTGREEN);
            printf("¿El individuo está en buenas condiciones?\n1-Sí\n2-No\n -->");
            scanf("%i",&rela.estado);
            fflush(stdin);
            if(rela.estado==1)
            {
                // BOM ESTADO
                printf("Individuo en buen estado: Si el individuo está en buen estado,\nsolo esperar a que nuestro vehículo se desplace al lugar del rescate.\n");
            } else{
                // MAU ESTADO
                            textcolor(LIGHTRED);
                printf("Sujeto en malas condiciones: ¿El sujeto tiene dificultad para respirar o está inconsciente?\n1-Sí\n2-No\n -->");
                scanf("%i",&rela.estado_mau);
                fflush(stdin);
                if(rela.estado_mau==1)
                {
                                textcolor(LIGHTRED);
                // ESTADO MAU - O QUE SE FAZER??
                printf("¿Sabes cómo realizar el soporte vital básico?\n1-Sí\n2-No\n--> ");
                scanf("%i",&rela.suporte_vida);
                fflush(stdin);
                if(rela.suporte_vida==1)
                {
                    // SABE SUPORTE BÁSICO DE VIDA
                    printf("Puedes empezar a hacer SOPORTE VITAL BÁSICO.\n Presta mucha atención y relájate.\n\n");
                } else if(rela.idade<18)
                {
                    textcolor(LIGHTBLUE);
                    // ENSINAR SUPORTE BÁSICO DE VIDA CRIANÇA
                    printf("Tan pronto como verifique que el bebé/niño no está respirando normalmente, dé 5 respiraciones con solo la cantidad de aire necesaria para expandir efectivamente el pecho.\n");
                    printf("Adapte las compresiones al tamaño de la víctima: para bebés hasta un año, use solo 2 dedos y para niños hasta 8 años, solo una mano, presionando hasta 1/3 de la altura del pecho.\n");
                } else{
                    textcolor(LIGHTGREEN);
                    // ENSINAR SUPORTE BÁSICO DE VIDA ADULTO
                    printf("Acueste a la víctima en el suelo con el vientre hacia arriba,\n coloque las manos superpuestas con los dedos entrelazados en el medio del pecho de la víctima.\n");
                    printf("Con los brazos rectos y perpendiculares al cuerpo de la víctima, presione el tórax, haciéndolo bajar y aliviar visiblemente.\n Repita este movimiento de compresión y descompresión del tórax de la víctima 30 veces a un ritmo de 100 a 120 por minuto.\n");
                    printf("Después de 30 compresiones, dé dos respiraciones por la boca de la víctima. Para ello, llena tus pulmones de aire y exhala en la boca de la víctima,\n tapándole la nariz con los dedos y aislando los labios de la víctima con los tuyos, para que no haya fugas de aire.\n Aunque la ventilación boca a boca es relativamente seguro, sin que se hayan descrito casos de infección grave, se recomienda el uso de mascarillas de reanimación. En los casos en que las ventilaciones no sean posibles, realice solo compresiones.\n");
                    printf("Después de ventilar, reanude las compresiones y siga siempre la secuencia de 30 compresiones torácicas con 2 ventilaciones. Sigue maniobrando hasta que llegue la ayuda o la víctima se recupere.\n");
                }
                } else{
                // BOM ESTADO
                textcolor(LIGHTGRAY);
                printf("Individuo en buen estado: Si el individuo está en buen estado,\nsolo espere a que nuestro vehículo se desplace al lugar de rescate.\n");
                }
            }
            fclose(ficheiro);
            break;

        // INCÊNDIOS
        case 2:
            system("cls");
            textcolor(LIGHTRED);
            printf("  FUEGO\n");
            textcolor(LIGHTCYAN);
            printf("Cuál es el tipo de incendio:\n1-Incendio rural\n2-Incendio forestal\n3-Incendio industrial\n --> ");
            scanf("%i", &inc.tipo);
            fflush(stdin);
            switch(inc.tipo)
            {
                case 1: textcolor(LIGHTBLUE);                                                                                                                                                                                          // incendio rural
                        printf("  FUEGO PAÍS  \n");
                        // rural
                        textcolor(LIGHTCYAN);
                        printf("¿Cual es tu nombre?\n");
                        scanf("%s",&inc.nome);
                        fflush(stdin);
                        textcolor(LIGHTGREEN);
                        printf("¿Dónde está el lugar del incendio?\n");
                        scanf("%s",&inc.local_incendio);
                        fflush(stdin);
                        textcolor(LIGHTMAGENTA);
                        printf("Cuál es tu número de teléfono\n");
                        scanf("%i",&inc.telefone);
                        fflush(stdin);

                        tipoincendio = fopen("incendio.txt", "a");
                        fprintf(tipoincendio, "-------------- LLAMADA DE FUEGO --------------\n");
                        fprintf(tipoincendio, "Tipo de Fuego: Fuego Rural\n");
                        fprintf(tipoincendio, "Nombre: %s\n",inc.nome);
                        fprintf(tipoincendio, "Local: %s\n",inc.local_incendio);
                        fprintf(tipoincendio, "Teléfono: %i\n",inc.telefone);

                        break;

                case 2: textcolor(LIGHTRED);
                        printf("  INCÊNDIO Forestal  \n");                                                                                                                                                                                  // incendio florestal
                        // florestal
                        textcolor(LIGHTCYAN);
                        printf("¿Cual es tu nombre?\n");
                        scanf("%s",&inc.nome);
                        fflush(stdin);
                        textcolor(LIGHTGREEN);
                        printf("¿Dónde está el lugar del incendio?\n");
                        scanf("%s",&inc.local_incendio);
                        fflush(stdin);
                        textcolor(LIGHTMAGENTA);
                        printf("Cuál es tu número de teléfono\n");
                        scanf("%i",&inc.telefone);
                        fflush(stdin);;

                        tipoincendio = fopen("incendio.txt", "a");
                        fprintf(tipoincendio, "-------------- LLAMADA DE FUEGO --------------\n");
                        fprintf(tipoincendio, "Tipo de Fuego: Fuego forestal\n");
                        fprintf(tipoincendio, "Nombre: %s\n",inc.nome);
                        fprintf(tipoincendio, "Local: %s\n",inc.local_incendio);
                        fprintf(tipoincendio, "Teléfono: %i\n",inc.telefone);
                        break;

                case 3: textcolor(LIGHTGREEN);                                                                                                                                                                                         // incendio industrial
                        printf("  INCÊNDIO INDUSTRIAL  \n");
                        // industrial
                        textcolor(LIGHTCYAN);
                        printf("¿Cual es tu nombre?\n");
                        scanf("%s",&inc.nome);
                        fflush(stdin);
                        textcolor(LIGHTGREEN);
                        printf("¿Dónde está el lugar del incendio?\n");
                        scanf("%s",&inc.local_incendio);
                        fflush(stdin);
                        textcolor(LIGHTMAGENTA);
                        printf("Cuál es tu número de teléfono\n");
                        scanf("%i",&inc.telefone);
                        fflush(stdin);
                        ficheiro = fopen("incendio.txt", "a");
                        fprintf(tipoincendio, "-------------- LLAMADA DE FUEGO --------------\n");
                        fprintf(tipoincendio, "Tipo de Fuego: Fuego industrial\n");
                        fprintf(tipoincendio, "Nombre: %s\n",inc.nome);
                        fprintf(tipoincendio, "Local: %s\n",inc.local_incendio);
                        fprintf(tipoincendio, "Teléfono: %i\n",inc.telefone);

                        break;
                        default: printf("Encontramos un problema, vuelva a ejecutar el programa.\n");break;
            }
            fclose(tipoincendio);
            break;

        // ACIDENTES
        case 3:                                                                                                                                                                                         // ACIDENTE
            system("cls");
            textcolor(LIGHTRED);
            printf("  ACCIDENTE\n");
            textcolor(LIGHTCYAN);

            printf("Cual es tu nombre?\n");
            scanf("%s",&aci.nome);
            fflush(stdin);

            printf("Ingrese la edad de la persona:\n -->");
            scanf("%i",&aci.idade_vitima);
            fflush(stdin);

            printf("¿Dónde está el lugar del Accidente?\n");
            scanf("%s",&aci.local_acidente);
            fflush(stdin);

            printf("Cuál es tu número de teléfono\n");
            scanf("%i",&aci.telefone);
            fflush(stdin);

            printf("¿Hay víctimas?\n1-Sí\n2-No\n--> ");
            scanf("%i",&aci.vitima);
            fflush(stdin);
            if(aci.vitima==1)
            {
                printf("¿Cómo está la víctima?\n1-Bien\n2-Malo\n--> ");
                scanf("%i",&aci.estado_vitima);
                if(aci.estado_vitima==2)
                {
                    printf("La Emergencia Médica también viene al encuentro del lugar. Espero que esperes.\n A que los equipos lleguen al sitio.\n");
                } else{
                    printf("Solo espera a que lleguen los bomberos para ayudar.\n");
                }
            }

            rela_acidente = fopen("acidente.txt", "a");
                        fprintf(rela_acidente, "--------------  LLAMADA DE ACCIDENTE  --------------\n");
                        fprintf(rela_acidente, "Tipo: ACCIDENTE\n");
                        fprintf(rela_acidente, "Nombre: %s\n",aci.nome);
                        fprintf(rela_acidente, "Edad del individuo: %i\n",aci.idade_vitima);
                        fprintf(rela_acidente, "Local: %s\n",aci.local_acidente);
                        fprintf(rela_acidente, "Teléfono: %i\n",aci.telefone);
                        fclose(rela_acidente);
            break;
        // SAIR
        case 4:
            printf("Presiona enter para salir...                                                              ");
            getchar(); // Espera pela entrada de um caractere
            break;
                    default: printf("Erro!!\n");
}
}
#endif // ESPANHOL_H_INCLUDED

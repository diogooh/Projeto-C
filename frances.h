#ifndef FRANCES_H_INCLUDED
#define FRANCES_H_INCLUDED

#define MAX_DOENCAS 10
struct relatorio_frances{
    int idade;
    char sexo[10];
    char local[100];
    int telefone;
    int estado;
    int estado_mau;
    int suporte_vida;
    char doenca[100];
}rela_frances;

struct incendio_frances{
    int tipo;
    char nome[30];
    int telefone;
    char local_incendio[100];
}inc_frances;

struct acidente_frances{
    char nome[30];
    int telefone;
    int idade_vitima;
    char local_acidente[100];
    int vitima;
    int estado_vitima;
}aci_frances;

struct relatorio_com_vetor_frances{
    struct relatorio rel;
    char doenca[MAX_DOENCAS][100];
};

void frances_menu() {
    int opcao;
    FILE* ficheiro;
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
    printf("\n\n                       Ol� daqui fala da emerg�ncia m�dica!\n                       Em que posso ajudar??");
    textcolor(YELLOW);
    printf("\n\n                       1-EMERG�NCIA M�DICA");
    textcolor(LIGHTRED);
    printf("\n\n                       2-INC�NDIO RURAL\n                        |FLORESTAL\n                        |INDUSTRIAL\n                        ----------------");
    textcolor(LIGHTBLUE);
    printf("\n\n                       3-ACIDENTES");
    textcolor(LIGHTGRAY);
    printf("\n\n                       4-SAIR\n\n");
    printf("\n\n --> ");
    scanf("%i", &opcao);
    fflush(stdin);
    switch(opcao)
    {
        // EMERG�NCIA M�DICA                                                                                                                                                                      // EMERG�NCIA M�DICA
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
            printf("\n   EMERG�NCIA M�DICA\n");

            textcolor(LIGHTGREEN);
            // info do relat�rio
            printf("Digite a idade da pessoa:\n -->");
            scanf("%i",&rela.idade);
            fflush(stdin);

            textcolor(LIGHTMAGENTA);
            printf("Digite o sexo da pessoa (M ou F):\n -->");
            scanf("%s",&rela.sexo);
            fflush(stdin);

            textcolor(LIGHTBLUE);
            printf("Digite este n�mero de telefone:\n  (9 Digitos)-->");
            scanf("%i", &rela.telefone);
            fflush(stdin);

            textcolor(LIGHTCYAN);
            printf("Descreva ao m�ximo o local onde se encontra.\n (Exemplo: Entrecampos, dentro da esta��o ao lado da bilheteira):\n");
            fgets(rela.local, 100, stdin);

            textcolor(LIGHTRED);
            printf("Diga se o Indiv�duo sofre de alguma doen�a:\n");
            fgets(rela.doenca, 100, stdin);

            ficheiro = fopen("ocorrencia.txt", "a");
            fprintf(ficheiro, "-------------- OCORR�NCIA --------------\n");
            fprintf(ficheiro, "Idade do Indiv�duo: %i\n", rela.idade);
            fprintf(ficheiro, "Sexo do Indiv�duo: %s\n", rela.sexo);
            fprintf(ficheiro, "Telefone do Indiv�duo: %i\n", rela.telefone);
            fprintf(ficheiro, "Local: %s\n",rela.local);
            fprintf(ficheiro, "Doen�a: %s\n",rela.doenca);

            // ESTADO DO INDIV�DUO                                                                                                                                       // EMERGENCIA MEDICA - ESTADO DO INDIVIDUO
            textcolor(LIGHTGREEN);
            printf("O Indiv�duo est� em bom estado?\n1-Sim\n2-N�o\n -->");
            scanf("%i",&rela.estado);
            fflush(stdin);
            if(rela.estado==1)
            {
                // BOM ESTADO
                printf("Individuo em bom Estado: Se o indiv�duo encontra-se em bom estado,\napenas aguarde a nossa viatura deslocar-se ao local de resgate.\n");
            } else{
                // MAU ESTADO
                            textcolor(LIGHTRED);
                printf("Individuo em mau Estado: O Indiv�duo est� com Falta de Ar ou Inconsciente?\n1-Sim\n2-N�o\n -->");
                scanf("%i",&rela.estado_mau);
                fflush(stdin);
                if(rela.estado_mau==1)
                {
                                textcolor(LIGHTRED);
                // ESTADO MAU - O QUE SE FAZER??
                printf("Sabe fazer suporte b�sico de vida?\n1-Sim\n2-N�o\n -->");
                scanf("%i",&rela.suporte_vida);
                fflush(stdin);
                if(rela.suporte_vida==1)
                {
                    // SABE SUPORTE B�SICO DE VIDA
                    printf("Pode come�ar a fazer SUPORTE B�SICO DE VIDA.\n Tenha bastante aten��o e esteja relaxada.\n");
                } else if(rela.idade<18)
                {
                    textcolor(LIGHTBLUE);
                    // ENSINAR SUPORTE B�SICO DE VIDA CRIAN�A
                    printf("Logo que verifique que o latente/crian�a n�o respira normalmente, fa�a 5 ventila��es apenas com a quantidade de ar necess�ria para expandir eficazmente o t�rax.\n");
                    printf("Adapte as compress�es ao tamanho da v�tima: se beb� at� um ano use apenas 2 dedos e se crian�a at� 8 anos apenas uma m�o, deprimindo at� 1/3 da altura do t�rax.\n");
                } else{
                    textcolor(LIGHTGREEN);
                    // ENSINAR SUPORTE B�SICO DE VIDA ADULTO
                    printf("Deite a vitima no ch�o com a barriga virada para cima,\n coloque as suas m�os sobrepostas com os dedos entrela�ados no meio do peito da v�tima.\n");
                    printf("Com os bra�os esticados e perpendiculares ao corpo da v�tima, pressione o peito, fazendo com que este baixe visivelmente e alivie.\n Repita 30 vezes este movimento de compress�o e descompress�o do peito da v�tima a um ritmo de 100 a 120 por minuto.\n");
                    printf("Ao fim das 30 compress�es efetue duas ventila��es atrav�s da boca da v�tima. Para isso encha os pulm�es de ar e expire para a boca da v�tima,\n tapando-lhe o nariz com os seus dedos e isolando com os seus l�bios os da v�tima, para que n�o exista fuga do ar.\n Embora a ventila��o boca-a-boca seja relativamente segura, sem casos de infe��o grave descritos, � recomend�vel a utiliza��o de m�scaras de reanima��o. Nos casos em que n�o seja poss�vel fazer ventila��es, fa�a apenas as compress�es.\n");
                    printf("Ap�s ventilar, retome as compress�es e siga sempre a sequ�ncia de 30 compress�es tor�cicas com 2 ventila��es. Mantenha as manobras at� � chegada de ajuda ou a v�tima recuperar.\n");
                }
                } else{
                // BOM ESTADO
                textcolor(LIGHTGRAY);
                printf("Individuo em bom Estado: Se o indiv�duo encontra-se em bom estado,\napenas aguarde a nossa viatura deslocar-se ao local de resgate.\n");
                }
            }
            fclose(ficheiro);
            break;

        // INC�NDIOS
        case 2:
            system("cls");
            textcolor(LIGHTRED);
            printf("  INC�NDIOS\n");
            textcolor(LIGHTCYAN);
            printf("Qual � o tipo de inc�ndios:\n1-Inc�ndio Rural\n2-Inc�ndio Florestal\n3-Inc�ndio Industrial\n --> ");
            scanf("%i", &inc.tipo);
            fflush(stdin);
            switch(inc.tipo)
            {
                case 1: textcolor(LIGHTBLUE);                                                                                                                                                                                          // incendio rural
                        printf("  INC�NDIO RURAL  \n");
                        // rural
                        textcolor(LIGHTCYAN);
                        printf("Qual � o seu nome?\n");
                        scanf("%s",&inc.nome);
                        fflush(stdin);
                        textcolor(LIGHTGREEN);
                        printf("Onde � o local do inc�ndio?\n");
                        scanf("%s",&inc.local_incendio);
                        fflush(stdin);
                        textcolor(LIGHTMAGENTA);
                        printf("Qual � o seu n�mero de telefone\n");
                        scanf("%i",&inc.telefone);
                        fflush(stdin);

                        tipoincendio = fopen("incendio.txt", "a");
                        fprintf(tipoincendio, "--------------  CHAMADA DE INC�NDIO  --------------\n");
                        fprintf(tipoincendio, "Tipo de Inc�ndio: INC�NDIO RURAL\n");
                        fprintf(tipoincendio, "Nome: %s\n",inc.nome);
                        fprintf(tipoincendio, "Local: %s\n",inc.local_incendio);
                        fprintf(tipoincendio, "Telefone: %i\n",inc.telefone);

                        break;

                case 2: textcolor(LIGHTRED);
                        printf("  INC�NDIO FLORESTAL  \n");                                                                                                                                                                                  // incendio florestal
                        // florestal
                        textcolor(LIGHTCYAN);
                        printf("Qual � o seu nome?\n");
                        scanf("%s",&inc.nome);
                        fflush(stdin);
                        textcolor(LIGHTGREEN);
                        printf("Onde � o local do inc�ndio?\n");
                        scanf("%s",&inc.local_incendio);
                        fflush(stdin);
                        textcolor(LIGHTMAGENTA);
                        printf("Qual � o seu n�mero de telefone\n");
                        scanf("%i",&inc.telefone);
                        fflush(stdin);

                        tipoincendio = fopen("incendio.txt", "a");
                        fprintf(tipoincendio, "--------------  CHAMADA DE INC�NDIO  --------------\n");
                        fprintf(tipoincendio, "Tipo de Inc�ndio: INC�NDIO FLORESTAL\n");
                        fprintf(tipoincendio, "Nome: %s\n",inc.nome);
                        fprintf(tipoincendio, "Local: %s\n",inc.local_incendio);
                        fprintf(tipoincendio, "Telefone: %i\n",inc.telefone);
                        break;

                case 3: textcolor(LIGHTGREEN);                                                                                                                                                                                         // incendio industrial
                        printf("  INC�NDIO INDUSTRIAL  \n");
                        // industrial
                        printf("Qual � o seu nome?\n");
                        scanf("%s",&inc.nome);
                        fflush(stdin);

                        printf("Onde � o local do inc�ndio?\n");
                        scanf("%s",&inc.local_incendio);
                        fflush(stdin);

                        printf("Qual � o seu n�mero de telefone\n");
                        scanf("%i",&inc.telefone);
                        fflush(stdin);

                        ficheiro = fopen("incendio.txt", "a");
                        fprintf(tipoincendio, "--------------  CHAMADA DE INC�NDIO  --------------\n");
                        fprintf(tipoincendio, "Tipo de Inc�ndio: INC�NDIO INDUSTRIAL\n");
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
            printf("  ACIDENTE\n");
            textcolor(LIGHTCYAN);

            printf("Qual � o seu nome?\n");
            scanf("%s",&aci.nome);
            fflush(stdin);

            printf("Digite a idade da pessoa:\n -->");
            scanf("%i",&aci.idade_vitima);
            fflush(stdin);

            printf("Onde � o local do Acidente?\n");
            scanf("%s",&aci.local_acidente);
            fflush(stdin);

            printf("Qual � o seu n�mero de telefone\n");
            scanf("%i",&aci.telefone);
            fflush(stdin);

            printf("Tem alguma vitima?\n1-Sim\n2-N�o\n--> ");
            scanf("%i",&aci.vitima);
            fflush(stdin);
            if(aci.vitima==1)
            {
                printf("Como se encontra a vitima?\n1-Bem\n2-Mal\n--> ");
                scanf("%i",&aci.estado_vitima);
                if(aci.estado_vitima==2)
                {
                    printf("A Emerg�ncia M�dica vem tamb�m ao encontro do local. Espero que aguarde.\n Pelas equipas chegarem ao local.\n");
                } else{
                    printf("A espere apenas pelos bombeiros chegarem para ajudar.\n");
                }
            }

            rela_acidente = fopen("acidente.txt", "a");
                        fprintf(rela_acidente, "--------------  CHAMADA DE ACIDENTE  --------------\n");
                        fprintf(rela_acidente, "Tipo: ACIDENTE\n");
                        fprintf(rela_acidente, "Nome: %s\n",aci.nome);
                        fprintf(rela_acidente, "Idade do Indiv�duo: %i\n",aci.idade_vitima);
                        fprintf(rela_acidente, "Local: %s\n",aci.local_acidente);
                        fprintf(rela_acidente, "Telefone: %i\n",aci.telefone);
                        fclose(rela_acidente);
            break;
        // SAIR
        case 4:
            printf("Pressione Enter para sair...");
            getchar(); // Espera pela entrada de um caractere
            break;
}
}

#endif // FRANCES_H_INCLUDED

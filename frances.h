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
    printf("\n\n                       Olá daqui fala da emergência médica!\n                       Em que posso ajudar??");
    textcolor(YELLOW);
    printf("\n\n                       1-EMERGÊNCIA MÉDICA");
    textcolor(LIGHTRED);
    printf("\n\n                       2-INCÊNDIO RURAL\n                        |FLORESTAL\n                        |INDUSTRIAL\n                        ----------------");
    textcolor(LIGHTBLUE);
    printf("\n\n                       3-ACIDENTES");
    textcolor(LIGHTGRAY);
    printf("\n\n                       4-SAIR\n\n");
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
            printf("Digite a idade da pessoa:\n -->");
            scanf("%i",&rela.idade);
            fflush(stdin);

            textcolor(LIGHTMAGENTA);
            printf("Digite o sexo da pessoa (M ou F):\n -->");
            scanf("%s",&rela.sexo);
            fflush(stdin);

            textcolor(LIGHTBLUE);
            printf("Digite este número de telefone:\n  (9 Digitos)-->");
            scanf("%i", &rela.telefone);
            fflush(stdin);

            textcolor(LIGHTCYAN);
            printf("Descreva ao máximo o local onde se encontra.\n (Exemplo: Entrecampos, dentro da estação ao lado da bilheteira):\n");
            fgets(rela.local, 100, stdin);

            textcolor(LIGHTRED);
            printf("Diga se o Indivíduo sofre de alguma doença:\n");
            fgets(rela.doenca, 100, stdin);

            ficheiro = fopen("ocorrencia.txt", "a");
            fprintf(ficheiro, "-------------- OCORRÊNCIA --------------\n");
            fprintf(ficheiro, "Idade do Indivíduo: %i\n", rela.idade);
            fprintf(ficheiro, "Sexo do Indivíduo: %s\n", rela.sexo);
            fprintf(ficheiro, "Telefone do Indivíduo: %i\n", rela.telefone);
            fprintf(ficheiro, "Local: %s\n",rela.local);
            fprintf(ficheiro, "Doença: %s\n",rela.doenca);

            // ESTADO DO INDIVÍDUO                                                                                                                                       // EMERGENCIA MEDICA - ESTADO DO INDIVIDUO
            textcolor(LIGHTGREEN);
            printf("O Indivíduo está em bom estado?\n1-Sim\n2-Não\n -->");
            scanf("%i",&rela.estado);
            fflush(stdin);
            if(rela.estado==1)
            {
                // BOM ESTADO
                printf("Individuo em bom Estado: Se o indivíduo encontra-se em bom estado,\napenas aguarde a nossa viatura deslocar-se ao local de resgate.\n");
            } else{
                // MAU ESTADO
                            textcolor(LIGHTRED);
                printf("Individuo em mau Estado: O Indivíduo está com Falta de Ar ou Inconsciente?\n1-Sim\n2-Não\n -->");
                scanf("%i",&rela.estado_mau);
                fflush(stdin);
                if(rela.estado_mau==1)
                {
                                textcolor(LIGHTRED);
                // ESTADO MAU - O QUE SE FAZER??
                printf("Sabe fazer suporte básico de vida?\n1-Sim\n2-Não\n -->");
                scanf("%i",&rela.suporte_vida);
                fflush(stdin);
                if(rela.suporte_vida==1)
                {
                    // SABE SUPORTE BÁSICO DE VIDA
                    printf("Pode começar a fazer SUPORTE BÁSICO DE VIDA.\n Tenha bastante atenção e esteja relaxada.\n");
                } else if(rela.idade<18)
                {
                    textcolor(LIGHTBLUE);
                    // ENSINAR SUPORTE BÁSICO DE VIDA CRIANÇA
                    printf("Logo que verifique que o latente/criança não respira normalmente, faça 5 ventilações apenas com a quantidade de ar necessária para expandir eficazmente o tórax.\n");
                    printf("Adapte as compressões ao tamanho da vítima: se bebé até um ano use apenas 2 dedos e se criança até 8 anos apenas uma mão, deprimindo até 1/3 da altura do tórax.\n");
                } else{
                    textcolor(LIGHTGREEN);
                    // ENSINAR SUPORTE BÁSICO DE VIDA ADULTO
                    printf("Deite a vitima no chão com a barriga virada para cima,\n coloque as suas mãos sobrepostas com os dedos entrelaçados no meio do peito da vítima.\n");
                    printf("Com os braços esticados e perpendiculares ao corpo da vítima, pressione o peito, fazendo com que este baixe visivelmente e alivie.\n Repita 30 vezes este movimento de compressão e descompressão do peito da vítima a um ritmo de 100 a 120 por minuto.\n");
                    printf("Ao fim das 30 compressões efetue duas ventilações através da boca da vítima. Para isso encha os pulmões de ar e expire para a boca da vítima,\n tapando-lhe o nariz com os seus dedos e isolando com os seus lábios os da vítima, para que não exista fuga do ar.\n Embora a ventilação boca-a-boca seja relativamente segura, sem casos de infeção grave descritos, é recomendável a utilização de máscaras de reanimação. Nos casos em que não seja possível fazer ventilações, faça apenas as compressões.\n");
                    printf("Após ventilar, retome as compressões e siga sempre a sequência de 30 compressões torácicas com 2 ventilações. Mantenha as manobras até à chegada de ajuda ou a vítima recuperar.\n");
                }
                } else{
                // BOM ESTADO
                textcolor(LIGHTGRAY);
                printf("Individuo em bom Estado: Se o indivíduo encontra-se em bom estado,\napenas aguarde a nossa viatura deslocar-se ao local de resgate.\n");
                }
            }
            fclose(ficheiro);
            break;

        // INCÊNDIOS
        case 2:
            system("cls");
            textcolor(LIGHTRED);
            printf("  INCÊNDIOS\n");
            textcolor(LIGHTCYAN);
            printf("Qual é o tipo de incêndios:\n1-Incêndio Rural\n2-Incêndio Florestal\n3-Incêndio Industrial\n --> ");
            scanf("%i", &inc.tipo);
            fflush(stdin);
            switch(inc.tipo)
            {
                case 1: textcolor(LIGHTBLUE);                                                                                                                                                                                          // incendio rural
                        printf("  INCÊNDIO RURAL  \n");
                        // rural
                        textcolor(LIGHTCYAN);
                        printf("Qual é o seu nome?\n");
                        scanf("%s",&inc.nome);
                        fflush(stdin);
                        textcolor(LIGHTGREEN);
                        printf("Onde é o local do incêndio?\n");
                        scanf("%s",&inc.local_incendio);
                        fflush(stdin);
                        textcolor(LIGHTMAGENTA);
                        printf("Qual é o seu número de telefone\n");
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
                        printf("  INCÊNDIO FLORESTAL  \n");                                                                                                                                                                                  // incendio florestal
                        // florestal
                        textcolor(LIGHTCYAN);
                        printf("Qual é o seu nome?\n");
                        scanf("%s",&inc.nome);
                        fflush(stdin);
                        textcolor(LIGHTGREEN);
                        printf("Onde é o local do incêndio?\n");
                        scanf("%s",&inc.local_incendio);
                        fflush(stdin);
                        textcolor(LIGHTMAGENTA);
                        printf("Qual é o seu número de telefone\n");
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
                        printf("  INCÊNDIO INDUSTRIAL  \n");
                        // industrial
                        printf("Qual é o seu nome?\n");
                        scanf("%s",&inc.nome);
                        fflush(stdin);

                        printf("Onde é o local do incêndio?\n");
                        scanf("%s",&inc.local_incendio);
                        fflush(stdin);

                        printf("Qual é o seu número de telefone\n");
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
            printf("  ACIDENTE\n");
            textcolor(LIGHTCYAN);

            printf("Qual é o seu nome?\n");
            scanf("%s",&aci.nome);
            fflush(stdin);

            printf("Digite a idade da pessoa:\n -->");
            scanf("%i",&aci.idade_vitima);
            fflush(stdin);

            printf("Onde é o local do Acidente?\n");
            scanf("%s",&aci.local_acidente);
            fflush(stdin);

            printf("Qual é o seu número de telefone\n");
            scanf("%i",&aci.telefone);
            fflush(stdin);

            printf("Tem alguma vitima?\n1-Sim\n2-Não\n--> ");
            scanf("%i",&aci.vitima);
            fflush(stdin);
            if(aci.vitima==1)
            {
                printf("Como se encontra a vitima?\n1-Bem\n2-Mal\n--> ");
                scanf("%i",&aci.estado_vitima);
                if(aci.estado_vitima==2)
                {
                    printf("A Emergência Médica vem também ao encontro do local. Espero que aguarde.\n Pelas equipas chegarem ao local.\n");
                } else{
                    printf("A espere apenas pelos bombeiros chegarem para ajudar.\n");
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
            printf("Pressione Enter para sair...");
            getchar(); // Espera pela entrada de um caractere
            break;
}
}

#endif // FRANCES_H_INCLUDED

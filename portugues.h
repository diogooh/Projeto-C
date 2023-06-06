#ifndef PORTUGUES_H_INCLUDED
#define PORTUGUES_H_INCLUDED
#include <time.h>


struct relatorio{
    int idade;
    char sexo[10]; // Alterado para um array de caracteres
    char local[100];
    int telefone;
    int estado;
    int estado_mau;
    int suporte_vida;
}rela;

void portuguese_first() {
    int opcao, ocorrencia;
    FILE* ficheiro;
    int num = 0;
    FILE* contador;
    textcolor(LIGHTBLUE);
    printf(R"EOF(
                                       __     __     _____
                                      /  |   /  |   / ___ `.
                                      `| |   `| |  |_/___) |
                                       | |    | |   .'____.'
                                      _| |_  _| |_ / /_____
                                     |_____||_____||_______|
                  )EOF");
    textcolor(LIGHTCYAN);
    printf("\n\n                       Olá daqui fala da emergência médica!\n                       Em que posso ajudar??");
    textcolor(YELLOW);
    printf("\n\n                       1-EMERGÊNCIA MÉDICA");
    textcolor(LIGHTRED);
    printf("\n\n                       2-INCÊNDIO RURAL\n                        |FLORESTAL\n                        |INDUSTRIAL\n                        ----------------");
    textcolor(LIGHTBLUE);
    printf("\n\n                       3-ACIDENTES");
    textcolor(LIGHTGREEN);
    printf("\n\n                       4-Marcar Consultas/Exames");
    textcolor(LIGHTGRAY);
    printf("\n\n                       5-SAIR\n\n");
    scanf("%i", &opcao);
    fflush(stdin);
    switch(opcao)
    {
        // EMERGÊNCIA MÉDICA
        case 1:

            // CONTADOR
            contador = fopen("contador.txt", "r+");
            fprintf(contador, "%i", num + 1);
            fclose(contador);

            printf("Digite a idade da pessoa:\n -->");
            scanf("%i",&rela.idade);
            fflush(stdin);

            printf("Digite o sexo da pessoa (M ou F):\n -->");
            scanf("%s",&rela.sexo);
            fflush(stdin);

            printf("Digite este número de telefone:\n  (9 Digitos)-->");
            scanf("%i", &rela.telefone);
            fflush(stdin);


            printf("Descreva ao máximo o local onde se encontra.\n (Exemplo: Entrecampos, dentro da estação ao lado da bilheteira).\n");
            fgets(rela.local, 100, stdin);

            ficheiro = fopen("ocorrencia.txt", "a");
            fprintf(ficheiro, "-------------- OCORRÊNCIA %i --------------\n", num);
            fprintf(ficheiro, "Idade do Indivíduo: %i\n", rela.idade);
            fprintf(ficheiro, "Sexo do Indivíduo: %s\n", rela.sexo);
            fprintf(ficheiro, "Telefone do Indivíduo: %i\n", rela.telefone);
            fprintf(ficheiro, "Local: %s\n",rela.local);

            // ESTADO DO INDIVÍDUO
            printf("O Indivíduo está em bom estado?\n1-Sim\n2-Não\n -->");
            scanf("%i",&rela.estado);
            fflush(stdin);
            if(rela.estado==1)
            {
                // BOM ESTADO
                printf("Individuo em bom Estado: Se o indivíduo encontra-se em bom estado,\napenas aguarde a nossa viatura deslocar-se ao local de resgate.\n");
            } else{
                // MAU ESTADO
                printf("Individuo em mau Estado: O Indivíduo está com Falta de Ar ou Inconsciente?\n1-Sim\n2-Não\n -->");
                scanf("%i",&rela.estado_mau);
                fflush(stdin);
                if(rela.estado_mau==1)
                {
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
                    // ENSINAR SUPORTE BÁSICO DE VIDA CRIANÇA
                    printf("Logo que verifique que o latente/criança não respira normalmente, faça 5 ventilações apenas com a quantidade de ar necessária para expandir eficazmente o tórax.\n");
                    printf("Adapte as compressões ao tamanho da vítima: se bebé até um ano use apenas 2 dedos e se criança até 8 anos apenas uma mão, deprimindo até 1/3 da altura do tórax.\n");
                } else{
                    // ENSINAR SUPORTE BÁSICO DE VIDA ADULTO
                    printf("Deite a vitima no chão com a barriga virada para cima,\n coloque as suas mãos sobrepostas com os dedos entrelaçados no meio do peito da vítima.\n");
                    printf("Com os braços esticados e perpendiculares ao corpo da vítima, pressione o peito, fazendo com que este baixe visivelmente e alivie.\n Repita 30 vezes este movimento de compressão e descompressão do peito da vítima a um ritmo de 100 a 120 por minuto.\n");
                    printf("Ao fim das 30 compressões efetue duas ventilações através da boca da vítima. Para isso encha os pulmões de ar e expire para a boca da vítima,\n tapando-lhe o nariz com os seus dedos e isolando com os seus lábios os da vítima, para que não exista fuga do ar.\n Embora a ventilação boca-a-boca seja relativamente segura, sem casos de infeção grave descritos, é recomendável a utilização de máscaras de reanimação. Nos casos em que não seja possível fazer ventilações, faça apenas as compressões.\n");
                    printf("Após ventilar, retome as compressões e siga sempre a sequência de 30 compressões torácicas com 2 ventilações. Mantenha as manobras até à chegada de ajuda ou a vítima recuperar.\n");
                }
                } else{
                // BOM ESTADO
                printf("Individuo em bom Estado: Se o indivíduo encontra-se em bom estado,\napenas aguarde a nossa viatura deslocar-se ao local de resgate.\n");
                }
            }
            fclose(ficheiro);
            break;

        // INCÊNDIOS
        case 2:
            break;

        // ACIDENTES
        case 3:
            break;

        // CONSULTAS
        case 4:
            break;

        // SAIR
        case 5:
            printf("Pressione Enter para sair...");
            getchar(); // Espera pela entrada de um caractere
            break;
}
}
#endif // PORTUGUES_H_INCLUDED

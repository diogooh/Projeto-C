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
    printf("\n\n                       Ol� daqui fala da emerg�ncia m�dica!\n                       Em que posso ajudar??");
    textcolor(YELLOW);
    printf("\n\n                       1-EMERG�NCIA M�DICA");
    textcolor(LIGHTRED);
    printf("\n\n                       2-INC�NDIO RURAL\n                        |FLORESTAL\n                        |INDUSTRIAL\n                        ----------------");
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
        // EMERG�NCIA M�DICA
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

            printf("Digite este n�mero de telefone:\n  (9 Digitos)-->");
            scanf("%i", &rela.telefone);
            fflush(stdin);


            printf("Descreva ao m�ximo o local onde se encontra.\n (Exemplo: Entrecampos, dentro da esta��o ao lado da bilheteira).\n");
            fgets(rela.local, 100, stdin);

            ficheiro = fopen("ocorrencia.txt", "a");
            fprintf(ficheiro, "-------------- OCORR�NCIA %i --------------\n", num);
            fprintf(ficheiro, "Idade do Indiv�duo: %i\n", rela.idade);
            fprintf(ficheiro, "Sexo do Indiv�duo: %s\n", rela.sexo);
            fprintf(ficheiro, "Telefone do Indiv�duo: %i\n", rela.telefone);
            fprintf(ficheiro, "Local: %s\n",rela.local);

            // ESTADO DO INDIV�DUO
            printf("O Indiv�duo est� em bom estado?\n1-Sim\n2-N�o\n -->");
            scanf("%i",&rela.estado);
            fflush(stdin);
            if(rela.estado==1)
            {
                // BOM ESTADO
                printf("Individuo em bom Estado: Se o indiv�duo encontra-se em bom estado,\napenas aguarde a nossa viatura deslocar-se ao local de resgate.\n");
            } else{
                // MAU ESTADO
                printf("Individuo em mau Estado: O Indiv�duo est� com Falta de Ar ou Inconsciente?\n1-Sim\n2-N�o\n -->");
                scanf("%i",&rela.estado_mau);
                fflush(stdin);
                if(rela.estado_mau==1)
                {
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
                    // ENSINAR SUPORTE B�SICO DE VIDA CRIAN�A
                    printf("Logo que verifique que o latente/crian�a n�o respira normalmente, fa�a 5 ventila��es apenas com a quantidade de ar necess�ria para expandir eficazmente o t�rax.\n");
                    printf("Adapte as compress�es ao tamanho da v�tima: se beb� at� um ano use apenas 2 dedos e se crian�a at� 8 anos apenas uma m�o, deprimindo at� 1/3 da altura do t�rax.\n");
                } else{
                    // ENSINAR SUPORTE B�SICO DE VIDA ADULTO
                    printf("Deite a vitima no ch�o com a barriga virada para cima,\n coloque as suas m�os sobrepostas com os dedos entrela�ados no meio do peito da v�tima.\n");
                    printf("Com os bra�os esticados e perpendiculares ao corpo da v�tima, pressione o peito, fazendo com que este baixe visivelmente e alivie.\n Repita 30 vezes este movimento de compress�o e descompress�o do peito da v�tima a um ritmo de 100 a 120 por minuto.\n");
                    printf("Ao fim das 30 compress�es efetue duas ventila��es atrav�s da boca da v�tima. Para isso encha os pulm�es de ar e expire para a boca da v�tima,\n tapando-lhe o nariz com os seus dedos e isolando com os seus l�bios os da v�tima, para que n�o exista fuga do ar.\n Embora a ventila��o boca-a-boca seja relativamente segura, sem casos de infe��o grave descritos, � recomend�vel a utiliza��o de m�scaras de reanima��o. Nos casos em que n�o seja poss�vel fazer ventila��es, fa�a apenas as compress�es.\n");
                    printf("Ap�s ventilar, retome as compress�es e siga sempre a sequ�ncia de 30 compress�es tor�cicas com 2 ventila��es. Mantenha as manobras at� � chegada de ajuda ou a v�tima recuperar.\n");
                }
                } else{
                // BOM ESTADO
                printf("Individuo em bom Estado: Se o indiv�duo encontra-se em bom estado,\napenas aguarde a nossa viatura deslocar-se ao local de resgate.\n");
                }
            }
            fclose(ficheiro);
            break;

        // INC�NDIOS
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

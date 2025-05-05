#include <stdio.h>
#include <string.h>
#define pontosstatus 20
#define limitestatus 5
#define classesmax 4
#define racamax 4
#define qtdbonusraca 2

//------/-------------------------------------------------------------------------//
int SetVesselStatus() {
    int statusp[6];
    for (int cc = 0; cc < 6; cc++) {
        statusp[cc] = 0;
    }
}
//---------------------------------------------------------------------------------------//
int main()
{
    //ordem: Clérigo, Guerreiro, Bardo, Ladino//
    //status base//
    int statusbaseclasse[3][classesmax] = {
        {12, 20, 16, 14},
        {20, 12, 16, 14},
        {14, 16, 15, 15}
    };

   //bonus de raça//
   //ordem: Sireno, Polar, Gatuno, Harpia//
        //atributo
    int bdr[qtdbonusraca][classesmax] = {
        {1, 0, 1, 4},
        {4, 2, 3, 3}
    };
        //valor//
    int vbdr[qtdbonusraca][classesmax] = {
        {2, 1, 3, 2},
        {3, 4, 2, 3}
    };
    
    char statusnome[6][10] = {
        "Força",
        "Destreza",
        "Vigor",
        "Intelecto",
        "Sabedoria",
        "Carisma"
        
    };
    char atrnome[3][20] = {
        "Vida máxima",
        "Mana máxima",
        "Classe de Armadura"
    };
    char caracteristicas[3][10] = {
        "Nome",
        "Raça",
        "Classe"
    };
    
    char racas[racamax][15] = {
        "Sireno",
        "Polar",
        "Gatuno",
        "Harpia"
    };
    
    char classes[classesmax][15] = {
        "Clérigo",
        "Guerreiro",
        "Bardo",
        "Ladino"
    };

/*    enum Classes {
    CLERIC = 0,
    WARRIOR = 1,
    BARD = 2,
    ROGUE = 3
};
    */
    
    //status do player//
    char caracp[3][20];
    //hp, mana, ca//
    int atrb[3];
    //for, dex, vig int, sab, car//
    int statusp[6];
    
    //operações e variáveis sistemicas//
    int ee, ea, ec = 0;
    int checkr, checks;
    int esccl, escr;
    
    for (int cc = 0; cc < 6; cc++) {
        statusp[cc] = 0;
    }
    
    printf("Qual o nome de seu personagem? Máximo de 20 caracteres \n");
    fgets(caracp[0], sizeof(caracp[0]), stdin);
  
  //classe//
    printf("Qual será sua classe? \n");
    for (int gg = 0; gg < classesmax; gg++) {
        printf("\t %d. %s \n", gg + 1, classes[gg]);
    }
    scanf("%d",&esccl);
    for (int hh = 0; hh < 3; hh++) {
        atrb[hh] = statusbaseclasse[hh][esccl - 1];
    }
    strcpy(caracp[2],classes[esccl - 1]);
    
    //atributos//
    printf("Defina seus atributos. Você tem %d pontos para dividir entre todos. \n", pontosstatus);
    checks = pontosstatus;
    
    
    for (ee = 0; ee < 6 && ec == 0; ee++) {
        printf("Quantos pontos colocará em %s? Pode, no máximo %d \n", statusnome[ee], limitestatus);
        printf("Você tem %d pontos restantes. \n", checks);
        scanf("%d", &ea);
        if (ea > limitestatus || ea < 0){
            printf("Opção inválida. Digite outra vez, corretamente agora. \n");
            ee--;
            continue;
        } else {
            statusp[ee] += ea;
            checks -= statusp[ee];
        }
        
        
        }
        if (checks > 0) {
            printf("Houve sobra de pontos. Redistribua corretamente, por favor. se não usar esses pontos agora, você os perderá. \n");
            ee = 0;
        } 
    
    
    printf("Qual será sua raça? \n");
    for (int ii = 0; ii < racamax; ii++) {
      printf("\t %d.%s. Bônus em %s e %s. \n",ii + 1, racas[ii], statusnome[bdr[0][ii]], statusnome[bdr[1][ii]]);  
    }
    
    //raça//
    do {
        scanf("%d",&escr);
        switch(escr) {
        case 1:
        case 2:
        case 3:
        case 4:
            statusp[bdr[0][escr - 1]] += vbdr[0][escr - 1];
            statusp[bdr[1][escr - 1]] += vbdr[1][escr - 1];
            checkr = 1;
            break;
        default: 
        printf("Opção inválida.");
    }

    } while (checkr != 1);
    strcpy(caracp[1],racas[escr - 1]);

    //soma de atributos//
    atrb[0] += statusp[2];
    atrb[1] += statusp[3];
    atrb[2] += statusp[2];
   
    //imprime a ficha//
    
    for (int ff = 0; ff < 3; ff++) {
        printf("%s: %s \n", caracteristicas[ff],caracp[ff]);
    }
    for (int bb = 0; bb < 3; bb++) {
        printf("%s: %d \n", atrnome[bb], atrb[bb]);
    }
    for (int aa = 0; aa < 6; aa++) {
        printf("%s: %d \n", statusnome[aa], statusp[aa]);
    }
    
    return 0;
}

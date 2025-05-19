#include <stdio.h>
#include <string.h>
#define MaxStsPoints 20
#define MinPtsPerAtr 1
#define MaxPtsPerAtr 5
#define MaxClass 4
#define MaxRace 4
#define QtdBnsRace 2
#define MaxName 15

//------/-------------------------------------------------------------------------//
typedef struct {
    char ClassName[15];
    int BaseHP;
    int BaseMana;
    int ArmorClass;
} ClassModel;

typedef struct {
    char RaceName[12];
    int BonusRace[QtdBnsRace];
    int BnsValue[QtdBnsRace];
} RaceModel;

typedef struct {
    char CaracPlayer[3][MaxName];
    int AtrPlayer[3];
    int StatPlayer[6];
 }Player;

typedef struct {
    char Stats[6][10];
    char Atributes[3][20];
    char Characteristics[3][10];
} PrintName;

int PtsLasting = MaxStsPoints;
int FlagYN = 0;
Player Sheet;

void ResetingStats(char Confirm);
//---------------------------------------------------------------------------------------//
int main() {
   
    int PrintCycle= 0;
    int PtsDestined, PtValid;

    enum Stats {
        STR = 0, NAME = 0, HP = 0,
        DEX = 1, CLASS = 1, MANA = 1,
        VIG = 2, RACE = 2, CA = 2,
        INT = 3,
        SAB = 4,
        CHR = 5,
    };
    
    ClassModel classes[MaxClass] = {
        {"Clérigo", 12, 20, 14},
        {"Guerreiro", 20, 12, 16},
        {"Bardo", 14, 16, 15},
        {"Ladino", 16, 14, 15},
    };

    RaceModel Races[MaxRace] = {
        {"Sireno", {DEX, SAB}, {2,3}},
        {"Polar", {STR, VIG}, {1,4}},
        {"Gatuno", {DEX, INT}, {3,2}},
        {"Harpia", {INT, SAB}, {2,3}},
    };


    PrintName Printable = {
        {"Força", "Destreza","Vigor","Intelecto","Sabedoria","Carisma"},
        {"Vida máxima", "Mana máxima", "Classe de Armadura"},
        {"Nome", "Classe", "Raça"},
    };


    int ClassSelected, RaceSelected;
    
    printf("Qual o nome de seu personagem? Máximo de 20 caracteres \n");
    fgets(Sheet.CaracPlayer[NAME], sizeof(Sheet.CaracPlayer[NAME]), stdin);
    Sheet.CaracPlayer[NAME][strcspn(Sheet.CaracPlayer[NAME], "\n")] = '\0';


    printf("Qual será sua classe? \n");
    for (int aa = 0; aa < MaxClass; aa++) {
        printf("\t %d. %s \n", aa + 1, classes[aa].ClassName);
    }
    scanf("%d", &ClassSelected);
    while (getchar() != '\n');
    strcpy(Sheet.CaracPlayer[CLASS],classes[ClassSelected - 1].ClassName);
    Sheet.AtrPlayer[HP] = classes[ClassSelected - 1].BaseHP;
    Sheet.AtrPlayer[MANA] = classes[ClassSelected -1].BaseMana;
    Sheet.AtrPlayer[CA] = classes[ClassSelected -1].ArmorClass;


    do {
        char Confirm;

        for (int bb = 0; bb < 6; bb++) {
        if (PtsLasting)
        printf("Quantos pontos você colocará em %s? Você tem %d pontos. Limite de %d por atributo. \n", Printable.Stats[bb], PtsLasting, MaxPtsPerAtr);
        do {
            PtValid = 0;
            scanf("%d", &PtsDestined);
            while (getchar() != '\n');
            if (PtsDestined < MinPtsPerAtr || PtsDestined > MaxPtsPerAtr) {
                printf("Opção inválida. Escolha um valor dentro do intervalo (De %d a %d) \n", MinPtsPerAtr, MaxPtsPerAtr);
            } else if (PtsDestined > PtsLasting) {
                printf("Erro! A quantia selecionada é maior do que a quantia de pontos disponíveis. Lembre-se, você só tem %d pontos restantes \n", PtsLasting);
            }else {
                PtValid = 1;
                PtsLasting -= PtsDestined;
                Sheet.StatPlayer[bb] = PtsDestined;
            }
        } while (PtValid == 0);
    }

        if (PtsLasting > 0) {
            printf("Você deixou %d pontos restantes. Esses pontos serão permanentemente perdidos. Você quer redistribuir seus pontos? (S/N)", PtsLasting);
            scanf("%c", &Confirm);
            while (getchar() != '\n');
            ResetingStats(Confirm);
        } else {
            FlagYN = 1;
        }
    } while (FlagYN == 0);
    
    
    

    printf("Escolha sua raça: \n");
    for (int cc = 0; cc < MaxRace; cc++) {
        printf("\t %d. %s: Bônus em %s e %s \n", cc + 1, Races[cc].RaceName, Printable.Stats[Races[cc].BonusRace[0]], Printable.Stats[Races[cc].BonusRace[1]]);
    }
    scanf("%d", &RaceSelected);
    while (getchar() != '\n');
    strcpy(Sheet.CaracPlayer[RACE],Races[RaceSelected - 1].RaceName);
    for (int dd = 0; dd < QtdBnsRace; dd++) {
        Sheet.StatPlayer[Races[RaceSelected - 1].BonusRace[dd]] += Races[RaceSelected - 1].BnsValue[dd];
    }

    //final set
    Sheet.AtrPlayer[HP] += Sheet.StatPlayer[VIG];
    Sheet.AtrPlayer[MANA] += Sheet.StatPlayer[INT];
    Sheet.AtrPlayer[CA] += Sheet.StatPlayer[VIG];

    for (PrintCycle = 0;PrintCycle < 3; PrintCycle++) {
        printf("%s: %s \n", Printable.Characteristics[PrintCycle], Sheet.CaracPlayer[PrintCycle]);
    }
    for (PrintCycle = 0;PrintCycle < 3; PrintCycle++) {
        printf("%s: %d \n", Printable.Atributes[PrintCycle], Sheet.AtrPlayer[PrintCycle]);
    }
    for (PrintCycle = 0;PrintCycle < 6; PrintCycle++) {
        printf("%s: %d \n", Printable.Stats[PrintCycle], Sheet.StatPlayer[PrintCycle]);
    }

    return 0;
}

void ResetingStats(char Confirm) {
    switch (Confirm) {
    case 'S':
    case 's':
        for (int bb = 0; bb < 6; bb++) {
            Sheet.StatPlayer[bb] = 0;
        }
        PtsLasting = MaxStsPoints;
        break;
    
    case 'N':
    case 'n':
        FlagYN = 1;
        break;
    }
}
#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h> //pre mazanie
#include <stdlib.h>
#include <float.h> // Strojovy epsilon
#define PI 3.14159265358979323846f //Definovanie pi pre Uloha 1.5
#define EPSILON 0.000000001f
#include <string.h> // pre lepsie citanie retazca

void rimske(int n)
{
    while (n != 0)
    {

        if (n >= 100)   // 100 - c
        {
            printf("C");
            n -= 100;
        }

        else if (n >= 90)    // 90 - xc
        {
            printf("XC");
            n -= 90;
        }

        else if (n >= 50)    // 50 - l
        {
            printf("L");
            n -= 50;
        }

        else if (n >= 40)    // 40 - xl
        {
            printf("XL");
            n -= 40;
        }

        else if (n >= 10)    // 10 - x
        {
            printf("X");
            n -= 10;
        }

        else if (n >= 9)     // 9 - ix
        {
            printf("IX");
            n -= 9;
        }

        else if (n >= 5)     // 5 - v
        {
            printf("V");
            n -= 5;
        }

        else if (n >= 4)     // 4 - iv
        {
            printf("IV");
            n -= 4;
        }

        else if (n >= 1)     // 1 - i
        {
            printf("I");
            n -= 1;
        }

    }

    return 0;

    /*while (n > 0) {
        switch (n % 100 / 10) {
            case 9: printf("XC"); n -= 90; break;
            case 4: printf("XL"); n -= 40; break;
            case 3: printf("XXX"); n -= 30; break;
            case 2: printf("XX"); n -= 20; break;
            case 1: printf("X"); n -= 10; break;
        }

        switch (n % 10) {
            case 9: printf("IX"); n -= 9; break;
            case 4: printf("IV"); n -= 4; break;
            case 3: printf("III"); n -= 3; break;
            case 2: printf("II"); n -= 2; break;
            case 1: printf("I"); n -= 1; break;
        }
    }

    return 0;*/

}

void prevod(int znak)
{
    int pole[100], i; //predpokladam ze to nebude mat viac ako 100 znakov
    for (i = 0; znak > 0; i++){ //Delenie a zistenie cifier
        pole[i] = znak % 2;
        znak = znak / 2;
    }
    for (i = i - 1; i >= 0; i--)  //Vypis cifier v opacnom poradi
    {
        printf("%d", pole[i]);
    }
    printf("\n");
    return 0;
}

void uloha1()
{
    system("cls");
    int cislo = 33777, pismeno = 0;
    printf("============ULOHA 1.1===========\n");
    printf("Zadajte zvolene pismeno (napr. X): ");
    pismeno = getchar();
    printf("Prevod %d je v DEC: %d, HEXA: %X  a v BIN: ", cislo, cislo, cislo); prevod(cislo);
    printf("Prevod %c je v DEC: %d, HEXA: %X  a v BIN: ", pismeno, pismeno, pismeno); prevod(pismeno);
    printf("===Stacte ENTER pre ukoncenie===\n"); getchar();
    getchar();
}

void uloha2()
{
    system("cls");
    int cislo = 0;
    printf("============ULOHA 1.2===========\n");
    printf("Zadajte cislo, ktore chcete previest do rimskych: ", cislo);
    scanf("%d", &cislo);
    rimske(cislo);
    printf("\n");
    printf("===Stacte ENTER pre ukoncenie===\n"); getchar();
    getchar();
}

void uloha3()
{
    system("cls");
    int premenna = 0, premenna1 = 1, nasledujuca_premenna = premenna + premenna1, k = 0, i = 0;
    printf("============ULOHA 1.3===========\n");
    printf("Zadajte cislo, ktore bude ohranicenie Fibonacciho postupnosti: ");
    scanf("%d", &k);
    printf("Cisla vo Fibonacciho postupnosti su: %d", premenna1);
    while (premenna <= nasledujuca_premenna) {
        if (nasledujuca_premenna > k) {
            break;
        }
        printf(", %d", nasledujuca_premenna);
        premenna = premenna1;
        premenna1 = nasledujuca_premenna;
        nasledujuca_premenna = premenna + premenna1;

        i++;
    }
    printf("\n===Stacte ENTER pre ukoncenie===\n"); getchar();
    getchar();
}

void uloha6() {

    system("cls");
    puts("============ULOHA 1.6===========");
    char retazec[100];
    char zosekane_pole[100];
    unsigned char checksum = 0;
    int i;
    printf("Zadajte retazec, ktoremu chyba kontrolna sucet (podla vzoru :10010000214601360121470136007EFE09D21901XX): ");
    fgets(retazec, sizeof(retazec), stdin);

    int len = strlen(retazec);
    if (len >= 11) {
        strncpy(zosekane_pole, retazec + 1, len - 3);
        zosekane_pole[len - 3] = '\0';
    } else {
        fprintf(stderr, "Niekde nastala chyba!\n");
        return;
    }


    int len1 = strlen(zosekane_pole);
    if (len1 < 11) {
        printf("Nie je dostatok dat pre citanie!\n");
        return;
    }

    for (i = 0; i < len1 - 2; i += 2) {
        unsigned int byte;
        sscanf(zosekane_pole + i, "%2X", &byte);
        checksum += (unsigned char)byte;
    }
    printf("Kontrolny sucet je: %02X\n", 0xFF - checksum + 1);
    printf("===Stacte ENTER pre ukoncenie===\n");
    getchar();
}


void main()
{
    char vyber;
    while (1) {
        system("cls");
        printf("==========BLOK 1===========\n");
        printf("Uloha 1.1 - Prevod cisel\nUloha 1.2 - Prevod cisla na rimske\nUloha 1.3 - Fibonacciho postupnost\n\033[9mUloha 1.4 - Strojovy epsilon\nUloha 1.5 - Sinus pomocou Taylorovho radu\033[0m\nUloha 1.6 - IntelHEX\n");
        printf("===========================\n");
        printf("Vyberte od 1 po 6 (pre ukoncenie stlacte Q): ");
        scanf("%c", &vyber);

        switch (vyber) {
        case '1':
            getchar();
            uloha1();
            break;
        case '2':
            getchar();
            uloha2();
            break;
        case '3':
            getchar();
            uloha3();
            break;
        case '4':
            getchar();
            //uloha4();
            break;
        case '5':
            getchar();
            //uloha5();
            break;
        case '6':
            getchar();
            uloha6();
            break;

        case 'Q':
        case 'q':
            exit(0);
        default:
            printf("Zle zadany vyber, prosim skuste to znovu\n");
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Client
{
    int id_client, id_sesizare;
    char nume[50], prenume[50], telefon[10], oras[50], studii;
    union
    {
        struct
        {
            char nume_generala[50];
            int an_terminare;
            char oras[20];
        } generala;
        struct
        {
            char nume_liceu[50];
            int an_terminare;
            char oras[20];
        } liceu;
        struct
        {
            char nume_facultate[50];
            int an_terminare;
            char oras[20];
        } facultate;
    } std;
} x[100];
int cmp(const void *a, const void *b) ///qsort
{
    struct Client x, y;
    x=*(struct Client*)a;
    y=*(struct Client*)b;
    if(strcmp(x.nume, y.nume) <0)
        return -1;
    if(strcmp(x.nume, y.nume) >0)
        return 1;
    if(strcmp(x.prenume, y.prenume) <0)
        return -1;
    if(strcmp(x.prenume, y.prenume) >0)
        return 1;
    return 0;
}
struct Sesizare
{
    int id_sesizare, id_operator;
    char specializare[50];
} b[100];
struct Operator
{
    int id_operator;
    char nume[50], prenume[50], specializare[50];
    float profit;
} c[100];
struct Sef
{
    char nume[50], prenume[50];
    float profit;
} d[100];
struct specializare
{
    int id_sesizare, id_operator;
    char specializare[50];
} e[100];
int erori(char numar[100])
{
    int i;
    printf("%s", numar);
    for(i = 1; i <= strlen(numar); i++)
        if(numar[i]>='A' && numar[i]<='Z')
            if(numar[i]>='a' && numar[i]<='z')
            return 1;
    return 0;
}
int main()
{
    char n, oras[50], val;
    int client, operator, sesizare, specializare, i, proceduri, eroare=0;
    float min, max, media=0, s=0;
    printf("\n\n                                            Baza de date Call center\n");
    printf("                                         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    printf(" Introduceti numarul clientilor: ");
    scanf("%d",&client);
    for(i = 1; i <= client; i++)
    {
        printf("\n\n-----------------------------------------------------\n");
        printf(" Introduceti datele de identificare ale clientului %d.\n", i);
        printf("-----------------------------------------------------\n");
        printf("\n Id client: ");
        scanf("%d", &x[i].id_client);
        printf("\n Numele clientului: ");
        scanf("%s", x[i].nume);
        printf("\n Prenumele clientului: ");
        scanf("%s", x[i].prenume);
        printf("\n Telefon client: ");
        scanf("%s", x[i].telefon);
        printf("\n Orasul de domiciliu: ");
        scanf("%s", x[i].oras);
        printf("\n Id sesizare: ");
        scanf("%d", &x[i].id_sesizare);
        printf("\n Introduceti datele despre studii ale clientului %d.\n\n", i);
        printf(" Studii (f-fara, g-generala, l-liceu, s-superioare): ");
        scanf("%s", &x[i].studii);
        switch(x[i].studii)
        {
        case 'g':
            printf("\n Introduceti numele institutiei de invatamant gimnazial: ");
            gets(x[i].std.generala.nume_generala);
            gets(x[i].std.generala.nume_generala);
            printf("\n Introduceti anul de terminare al %s: ", x[i].std.generala.nume_generala);
            scanf("&d", &x[i].std.generala.an_terminare);
            printf("\n Introduceti orasul in care este situata %s: ", x[i].std.generala.nume_generala);
            gets(x[i].std.generala.oras);
            gets(x[i].std.generala.oras);
            break;
        case 'l':
            printf("\n Introduceti numele institutiei de invatamant liceal: ");
            gets(x[i].std.liceu.nume_liceu);
            gets(x[i].std.liceu.nume_liceu);
            printf("\n Introduceti anul de terminare al %s: ", x[i].std.liceu.nume_liceu);
            scanf("&d", &x[i].std.liceu.an_terminare);
            printf("\n Introduceti orasul in care este situat %s: ", x[i].std.liceu.nume_liceu);
            gets(x[i].std.liceu.oras);
            gets(x[i].std.liceu.oras);
            break;
        case 's':
            printf("\n Introduceti numele institutiei de invatamant superior: ");
            gets(x[i].std.facultate.nume_facultate);
            gets(x[i].std.facultate.nume_facultate);
            printf("\n Introduceti anul de terminare al %s: ", x[i].std.facultate.nume_facultate);
            scanf("&d", &x[i].std.facultate.an_terminare);
            printf("\n Introduceti orasul in care este situata %s: ", x[i].std.facultate.nume_facultate);
            gets(x[i].std.facultate.oras);
            gets(x[i].std.facultate.oras);
            break;
        case 'f':
            break;
        }
    }
    printf("\n________________________________________________________________________________________________________________________\n\n");
    printf(" Introduceti numarul operatorilor: ");
    scanf("%d",&operator);
    for(i = 1; i <= operator; i++)
    {
        printf("\n\n-------------------------------------------------------\n");
        printf(" Introduceti datele de identificare ale operatorului %d.\n", i);
        printf("-------------------------------------------------------\n");
        printf("\n Id operator: ");
        scanf("%d", &c[i].id_operator);
        printf("\n Numele operatorului: ");
        scanf("%s", c[i].nume);
        printf("\n Prenumele operatorului: ");
        gets(c[i].prenume);
        gets(c[i].prenume);
        printf("\n Specializarea operatorului: ");
        gets(c[i].specializare);
        printf("\n Profit: ");
        scanf("%f", &c[i].profit);
    }
    printf("\n________________________________________________________________________________________________________________________\n\n");
    printf(" Introduceti numarul sesizarilor: ");
    scanf("%d",&sesizare);
    for(i = 1; i <= sesizare; i++)
    {
        printf("\n\n--------------------------------\n");
        printf(" Introduceti datele sesizarii %d.\n", i);
        printf("--------------------------------\n");
        printf("\n Id sesizare: ");
        scanf("%d", &b[i].id_sesizare);
        printf("\n Specializare: ");
        gets(b[i].specializare);
        gets(b[i].specializare);
        printf("\n Id operator: ");
        scanf("%d", &b[i].id_operator);
    }
    printf("\n________________________________________________________________________________________________________________________\n\n");
    printf(" Introduceti datele sefului:\n ");
    printf("\n Numele sefului: ");
    scanf("%s", d[0].nume);
    printf("\n Prenumele sefului: ");
    gets(d[0].prenume);
    gets(c[i].prenume);
    for(i = 1; i <= operator; i++)
        d[0].profit+=c[i].profit; ///calcularea campului "profit" din structura Sef in functie de campul "taxa" din structura Operator.
    printf("\n Profitul total al firmei este: %.3f lei", d[0].profit);
    printf("\n________________________________________________________________________________________________________________________\n\n");
    printf(" Introduceti numarul specializarilor: ");
    scanf("%d",&specializare);
    for(i = 1; i <= specializare; i++)
    {
        printf("\n\n------------------------------------\n");
        printf(" Introduceti datele specializarii %d.\n", i);
        printf("------------------------------------\n");
        printf("\n Id operator: ");
        scanf("%d", &e[i].id_operator);
        printf("\n Id sesizare: ");
        scanf("%d", &e[i].id_sesizare);
        printf("\n Specializare: ");
        gets(e[i].specializare);
        gets(e[i].specializare);
    }
    printf("\n________________________________________________________________________________________________________________________\n\n");
    printf(" Ce doriti sa faceti in continuare?\n");
    printf(" Apasati '1' pentru introducerea unui client/ operator nou\n");
    printf("         '2' pentru a afla cel mai mic profit\n");
    printf("         '3' pentru a afla cel mai mare profit\n");
    printf("         '4' pentru a calcula comisionul pe care il castiga fiecare operator\n");
    printf("         '5' pentru a calcula profitul total al firmei\n");
    printf("          orice alt caracter pentru a continua");
    printf("\n\n Urmatoarea operatie efectuata este: ");
    scanf("%d", &proceduri);
    if(proceduri == 1) //adaugarea unui nou client/operator
    {
        printf("\n\n Daca doriti sa introduceti un client noua apasati 'c'. Daca doriti sa introduceti un operator nou apasati 'o'.: ");
        scanf("%c", &n);
        scanf("%c", &n);
        if(n == 'c')
            for(i = client+1; i <= client+1; i++)
            {
                printf("\n\n-----------------------------------------------------\n");
                printf(" Introduceti datele de identificare ale clientului %d.\n", i);
                printf("-----------------------------------------------------\n");
                printf(" Id client: ");
                scanf("%d", &x[i].id_client);
                printf("\n Numele clientului: ");
                gets(x[i].nume);
                gets(x[i].nume);
                printf("\n Prenumele clientului: ");
                gets(x[i].prenume);
                printf("\n Telefon client: ");
                gets(x[i].telefon);
                printf("\n Orasul de domiciliu: ");
                gets(x[i].oras);
                printf("\n Id sesizare: ");
                scanf("%d", &x[i].id_sesizare);
                printf("\n Introduceti datele despre studii ale clientului %d.\n\n", i);
                printf(" Studii (f-fara, g-generala, l-liceu, s-superioare): ");
                scanf("%s", &x[i].studii);
                switch(x[i].studii)
                {
                case 'g':
                    printf("\n Introduceti numele institutiei de invatamant gimnazial: ");
                    gets(x[i].std.generala.nume_generala);
                    gets(x[i].std.generala.nume_generala);
                    printf("\n Introduceti anul de terminare al %s: ", x[i].std.generala.nume_generala);
                    scanf("&d", &x[i].std.generala.an_terminare);
                    printf("\n Introduceti orasul in care este situata %s: ", x[i].std.generala.nume_generala);
                    gets(x[i].std.generala.oras);
                    gets(x[i].std.generala.oras);
                    break;
                case 'l':
                    printf("\n Introduceti numele institutiei de invatamant liceal: ");
                    gets(x[i].std.liceu.nume_liceu);
                    gets(x[i].std.liceu.nume_liceu);
                    printf("\n Introduceti anul de terminare al %s: ", x[i].std.liceu.nume_liceu);
                    scanf("&d", &x[i].std.liceu.an_terminare);
                    printf("\n Introduceti orasul in care este situat %s: ", x[i].std.liceu.nume_liceu);
                    gets(x[i].std.liceu.oras);
                    gets(x[i].std.liceu.oras);
                    break;
                case 's':
                    printf("\n Introduceti numele institutiei de invatamant superior: ");
                    gets(x[i].std.facultate.nume_facultate);
                    gets(x[i].std.facultate.nume_facultate);
                    printf("\n Introduceti anul de terminare al %s: ", x[i].std.facultate.nume_facultate);
                    scanf("&d", &x[i].std.facultate.an_terminare);
                    printf("\n Introduceti orasul in care este situata %s: ", x[i].std.facultate.nume_facultate);
                    gets(x[i].std.facultate.oras);
                    gets(x[i].std.facultate.oras);
                    break;
                case 'f':
                    break;
                }
            }
        else if(n == 'o')
            for(i = operator+1; i <= operator+1; i++)
            {
                printf("\n\n-------------------------------------------------------\n");
                printf(" Introduceti datele de identificare ale operatorului %d.\n", i);
                printf("-------------------------------------------------------\n");
                printf(" Id operator: ");
                scanf("%d", &c[i].id_operator);
                printf("\n Numele operatorului: ");
                gets(c[i].nume);
                gets(c[i].nume);
                printf("\n Prenumele operatorului: ");
                gets(c[i].prenume);
                printf("\n Specializarea operatorului: ");
                gets(c[i].specializare);
                printf("\n Taxa: ");
                scanf("%f", &c[i].profit);
                d[0].profit+=c[i].profit;
                printf("\n Noul profit total al firmei este: ", d[0].profit);
            }
    }
    if(proceduri == 2) ///cel mai mic profit
    {
        if(operator == 1)
        {
            min=c[1].profit;
            printf("\n Cel mai mic profit a fost de: %.3f lei.", min);
        }
        else
        {
            min=c[1].profit;
            for(i = 1; i <= operator; i++)
                if(min >= c[i].profit)
                    min=c[i].profit;
            printf("\n Cel mai mic profit a fost de: %.3f lei.", min);
        }
    }
    if(proceduri == 3) ///cel mai mare profit
    {
        if(operator == 1)
        {
            max=c[1].profit;
            printf("\n Cel mai mare profit a fost de: %.3f lei.", max, c[1].nume, c[1].prenume);
        }
        else
        {
            max = c[1].profit;
            for(i = 1; i <= operator; i++)
                if(max <= c[i].profit)
                    max=c[i].profit;
            printf("\n Cel mai mare profit a fost de: %.3f lei.", max);
        }
    }
    if(proceduri == 4) ///comision  perceput de fiecare operator
    {
        s=d[0].profit*50/100;
        media=s/operator;
        printf("\n Fiecare operator incaseaza un comision de %.3f lei.", media);
    }
    if(proceduri == 5) ///profitul total al firmei
    {
        printf("\n Profitul total al firmei este: %.3f lei", d[0].profit);
    }
    if(n == 'c') ///sortare in cazul in care se adauga inca un client
    {
        qsort(x+1, client+1, sizeof(struct Client), cmp); ///ordonati toti clientii dupa campul nume (iar in cazul in care au acelasi nume, dupa prenume)
        printf("\n\n Clientii ordonati in ordine alfabetica sunt:\n");
        printf("\n Id   Nume     Prenume     Id sesizare\n");
        for(i = 1; i <= client+1; i++)
        {
            printf(" %d   %s   %s   %d", x[i].id_client, x[i].nume, x[i].prenume, x[i].id_sesizare);
            printf("\n");
        }
    }
    else ///sortare clienti existenti
    {
        qsort(x+1, client, sizeof(struct Client), cmp);
        printf("\n\n Clientii ordonati in ordine alfabetica sunt:\n");
        printf("\n Id   Nume     Prenume     Id sesizare\n");
        for(i = 1; i <= client; i++)
        {
            printf(" %d    %s   %s    %d", x[i].id_client, x[i].nume, x[i].prenume, x[i].id_sesizare);
            printf("\n");
        }
    }
    printf("\n\n Cerinta1: Sa se introduca de la tastatura numele si prenumele clientului precum si id_sesizare si sa se afiseze numele si prenumele operatorului care trebuie sa indeplineasca sesizarea.");
    printf("\n\n Introduceti numele clientului: ");
    gets(x[0].nume);
    gets(x[0].nume);
    printf("\n Introduceti prenumele clientului: ");
    gets(x[0].prenume);
    printf("\n Introduceti id sesizare: ");
    scanf("%d", &x[0].id_sesizare);
    for(i = 1; i <= specializare; i++)
        if(x[0].id_sesizare == b[i].id_sesizare)
            if(b[i].id_operator == c[i].id_operator)
                printf("\n Operatorul care are de indeplinit sesizarea %d este: %s %s",x[0].id_sesizare, c[i].nume, c[i].prenume);
    printf("\n________________________________________________________________________________________________________________________\n\n");
    printf(" Cerinta2: Sa se afiseze numele si prenumele clientilor care au domiciliul intr-un oras citit de la tastatura.\n");
    printf("\n Introduceti orasul dupa care doriti sa sortati clientii: ");
    scanf("%s", &oras);
    if(n=='c')
    {
        for(i=1; i<=client+1; i++)
        {
            val=strcmp(x[i].oras, oras);
            if(val == 0)
            {
                qsort(x+1, client+1, sizeof(struct Client), cmp); //sortare cerinta 2
                printf("\n\n Clientii ordonati in ordine alfabetica din orasul %s sunt: \n\n", oras);
                printf(" Id   Nume     Prenume     Id sesizare\n");
                for(i = 1; i <= client+1; i++)
                {
                    printf(" %d    %s   %s    %d", x[i].id_client, x[i].nume, x[i].prenume, x[i].id_sesizare);
                    printf("\n");
                }
            }
        }
    }
    else
    {
        for(i = 1; i <= client; i++)
        {
            val = strcmp(x[i].oras, oras);
            if(val == 0)
            {
                qsort(x+1, client, sizeof(struct Client), cmp); //sortare cerinta 2
                printf("\n\n Clientii ordonati in ordine alfabetica din orasul %s sunt: \n\n", oras);
                printf(" Id   Nume     Prenume     Id sesizare\n");
                for(i = 1; i <= client; i++)
                {
                    printf(" %d    %s   %s    %d", x[i].id_client, x[i].nume, x[i].prenume, x[i].id_sesizare);
                    printf("\n");
                }
            }
        }
    }
    return 0;
}

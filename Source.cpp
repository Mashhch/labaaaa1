#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>



int f1(int n) { n = n + 1;  return n; }
int f2(int n) { n = n + 2;  return n; }
int f3(int n) { n = n + 3; return n; }
int f4(int n) { n = n + 4; return n; }
int f5(int n) { n = n + 5; return n; }
int f6(int n) { n = n + 6; return n; }
int f7(int n) { n = n + 7; return n; }
int f8(int n) { n = n + 8; return n; }
int f9(int n) { n = n + 9; return n; }
int f10(int n) { n = n + 10; return n; }

char* f11(char* s1, char s[20])
{
    
    char m[] = "AAAAAAAAAAAAAAAAAAA";
    for (int i = 0; i < 20; i++)
        s[i] = m[i];
    s1 = s;
    return s1;
}
char* f12(char* s1, char s[20])
{
    char m[] = "this is a string kk";
    for (int i = 0; i < 20; i++)
        s[i] = m[i];
    s1 = s;
    return s1;
}
char* f13(char* s1, char s[20])
{
    char m[] = "This is a string kk";
    for (int i = 0; i < 20; i++)
        s[i] = m[i];
    s1 = s;
    return s1;
}
char* f14(char* s1, char s[20])
{
    char m[] = "What can i dooooooo";
    for (int i = 0; i < 20; i++)
        s[i] = m[i];
    s1 = s;
    return s1;
}
char* f15(char* s1, char s[20])
{
    char m[] = "i can do nothingggg";
    for (int i = 0; i < 20; i++)
        s[i] = m[i];
    s1 = s;
    return s1;
}
char* f16(char* s1, char s[20])
{
    char m[] = "my english is baddd";
    for (int i = 0; i < 20; i++)
        s[i] = m[i];
    s1 = s;
    return s1;
}
char* f17(char* s1, char s[20])
{
    char m[] = "QWERTYUIOPASDFGHJKL";
    for (int i = 0; i < 20; i++)
        s[i] = m[i];
    s1 = s;

    return s1;
}
char* f18(char* s1, char s[20])
{
    char m[] = "yuiopasdfghjklzxcvb";
    for (int i = 0; i < 20; i++)
        s[i] = m[i];
    s1 = s;

    return s1;
}
char* f19(char* s1, char s[20])
{
    char m[] = "OOuipasdfghjklzxcvb";
    for (int i = 0; i < 20; i++)
        s[i] = m[i];
    s1 = s;

    return s1;
}

// ������ ���������� �� �������
void** mass_fint() {

    void** funcs = (void**)malloc(9 * sizeof(void*));
    for (int i = 0; i < 9; i++)
        funcs[i] = (void*)malloc(sizeof(void*));
    funcs[0] = (void*)(&f1);
    funcs[1] = (void*)(&f2);
    funcs[2] = (void*)(&f3);
    funcs[3] = (void*)(&f4);
    funcs[4] = (void*)(&f5);
    funcs[5] = (void*)(&f6);
    funcs[6] = (void*)(&f7);
    funcs[7] = (void*)(&f8);
    funcs[8] = (void*)(&f9);

    return funcs;
}

void** mass_fchar() {

    void** funcs = (void**)malloc(9 * sizeof(void*));
    for (int i = 0; i < 9; i++)
        funcs[i] = (void*)malloc(sizeof(void*));
    funcs[0] = (void*)(&f11);
    funcs[1] = (void*)(&f12);
    funcs[2] = (void*)(&f13);
    funcs[3] = (void*)(&f14);
    funcs[4] = (void*)(&f15);
    funcs[5] = (void*)(&f16);
    funcs[6] = (void*)(&f17);
    funcs[7] = (void*)(&f18);
    funcs[8] = (void*)(&f19);

    return funcs;
}

typedef struct {
    char* s1;
    int dlins1;
    char* s2;
    int dlins2;
    char* s_out; // ��������� ������
    int dlins_out;
} String;

typedef struct {
    void** A; // ������
    int N; // ����� ��������� � �������
    char tip; //  i - integer, c -char, s - stroka
    int dlinstr; // ����� ����� � �������
    int arg; //�������� ��� int
    char* sukaz_arg[9]; //�������� ��� char
    char s_arg[9][20]; //�������� ��� char
    int i; //������� ��� where
}Arr;

Arr AddElem(Arr Massiv, void* elem)
{
    void** elems = (void**)malloc((Massiv.N + 1) * sizeof(void*));
    for (int i = 0; i < Massiv.N; i++)
        elems[i] = Massiv.A[i];
    elems[Massiv.N] = elem;
    free(Massiv.A);
    Massiv.N++;
    Massiv.A = elems;
    return Massiv;
}

char* concat(String string)
{
    for (int i = 0; i < string.dlins1; i++)
        string.s_out[i] = string.s1[i];
    for (int j = 0; j < string.dlins2; j++)
        string.s_out[j + string.dlins1] = string.s2[j];
    string.dlins_out = string.dlins1 + string.dlins2;
    return string.s_out;
}
 int ctestconcet(String string)
 {
     int flag = 1;
     for (int j = 0; j < string.dlins1; j++)
     {
         if (string.s1[j] != string.s_out[j])
             flag = 0;
     }
     printf("%d", flag);
     for (int j = 0; j < string.dlins2; j++)
     {
         if (string.s_out[j + string.dlins1] != string.s2[j])
             flag = 0;
     }
     printf("%d", flag);
     if (string.dlins_out != (string.dlins1 + string.dlins2))
         flag = 0;
     return flag;
 }

void ctest1(Arr Massiv)
{
    //struct Arr
    printf("\n���������: Massiv\n���������� ��������� � �������: %d", Massiv.N);
    if (Massiv.tip == 'c')
        printf("\n������ ������ ��������� �� �������, ������������ ��������� �� char");
    if (Massiv.tip == 'i')
        printf("\n������ ������ ��������� �� �������, ������������ ��������� �� int");
    if (Massiv.tip == 's')
        printf("\n������ ������ ��������� �� char");
}

void ctest2(String string)
{
    //concat
    string.dlins1 = 6;
    string.dlins2 = 4;
    string.dlins_out = string.dlins1 + string.dlins2;
    string.s1 = (char*)malloc(string.dlins1 * sizeof(char));
    string.s2 = (char*)malloc(string.dlins2 * sizeof(char));
    string.s_out = (char*)malloc(string.dlins_out * sizeof(char));
    for (int i = 0; i < string.dlins1; i++)
        string.s1[i] = 'A';
    for (int i = 0; i < string.dlins2; i++)
        string.s2[i] = 'a';
    string.s_out = concat(string);
    int test = ctestconcet(string);
    if (test == 1)
        printf("\nconcat correct");
    else
        printf("\nconcat incorrect");

}

Arr F1(Arr Massiv)
{
    void* R;
    int* a = (int*)malloc(Massiv.N * sizeof(int));
    int N = Massiv.N;
    if (Massiv.tip == 'i' ) //int func
    {
        for (int i = 0; i < Massiv.N; i++)
            a[i] = ((int(*)(int))Massiv.A[i])(Massiv.arg) * (-1); // ������ ����� * -1    
        Massiv.A = malloc(Massiv.N * sizeof(int*));
        for (int i = 0; i < Massiv.N; i++)
            (int*)Massiv.A[i] = a[i];
    }
    if (Massiv.tip == 's') // stroka
    {
        for (int i = 0; i < Massiv.N; i++)
        {
            if ('a' <= *((char*)Massiv.A[i]) && *((char*)Massiv.A[i]) <= 'z')
                *((char*)Massiv.A[i]) = *((char*)Massiv.A[i]) + 'A' - 'a'; 
        }
    }

    if (Massiv.tip == 'c') // char func
    {
        for (int j = 0; j < Massiv.N; j++)
        {
            for (int i = 0; i < Massiv.N - 1; i++)
            {

                if ('a' <= *(((char* (*)(char*, char k[20])) Massiv.A[i]) (Massiv.sukaz_arg[i], Massiv.s_arg[i])) && *(((char* (*)(char*, char k[20])) Massiv.A[i]) (Massiv.sukaz_arg[i], Massiv.s_arg[i])) <= 'z')
                {
                    R = Massiv.A[i];
                    Massiv.A[i] = Massiv.A[i + 1];
                    Massiv.A[i + 1] = R;
                }
            }
        }
    }
    return Massiv;
}

Arr map( Arr Massiv, Arr F(Arr Massiv))
{
    Arr NewMassiv;
    NewMassiv = Massiv;
   NewMassiv = (*F)(NewMassiv);
    return NewMassiv;
}

int boolf(Arr Massiv)
{
    int flag = 0;
    if (Massiv.tip == 'i') //int func
    {
            if (((int(*)(int))Massiv.A[Massiv.i])(Massiv.arg) %2 == 0)
                flag = 1; // :2
    }
    if (Massiv.tip == 's') // stroka
    {
            if ('A' <= *((char*)Massiv.A[Massiv.i]) && *((char*)Massiv.A[Massiv.i]) <= 'Z')
                flag = 1;// ������ ���������� �� ���������
        }

    if (Massiv.tip == 'c') // char func
    {
        if ('A' <= *(((char* (*)(char*, char k[20])) Massiv.A[Massiv.i]) (Massiv.sukaz_arg[Massiv.i], Massiv.s_arg[Massiv.i])) && *(((char* (*)(char*, char k[20])) Massiv.A[Massiv.i]) (Massiv.sukaz_arg[Massiv.i], Massiv.s_arg[Massiv.i])) <= 'Z')
                flag = 1; // ������ ���������� �� ���������
    }
    if (flag == 1) return 1; else return 0;
}
Arr where(Arr Massiv, int F(Arr Massiv))
//void** where(int* newN, void** newA, int N, void** A, char tip, int arg, char* s1[9], char s[9][20],int (*F)(int i, void** A, char tip, int arg, char* s1[9], char s[9][20]))
{
    Arr NewMassiv; 
    NewMassiv = Massiv;
    int j = 0;
    int chet = 0;
    NewMassiv.i = 0;
    int t;
    for (NewMassiv.i = 0; NewMassiv.i <NewMassiv.N; NewMassiv.i++)
    {
        t = (*F)(NewMassiv);
        if (t == 1)
            chet++;
    }
    void** newA = (void**)malloc(chet * sizeof(void*));
    Massiv.i = 0;
    for (NewMassiv.i = 0; NewMassiv.i < NewMassiv.N; NewMassiv.i++)
    {
        t = (*F)(NewMassiv);
        if (t == 1)
        {
            newA[j] = NewMassiv.A[NewMassiv.i];
            j++;
        }
    }
    NewMassiv.A = malloc(chet * sizeof(void*));
    NewMassiv.N = chet;
    for (int i = 0; i < NewMassiv.N; i++)
        NewMassiv.A[i] = newA[i];

    return NewMassiv;
}


main()
{
    Arr Massiv;
    Arr NewMassiv;
    String string;
    Arr (*ukazf1)(Arr Massiv);
    int (*ukazf2)(Arr Massiv);
    Massiv.N = 0;
    Massiv.tip = '0'; //  i - integer, c -char, s - stroka
    Massiv.dlinstr = 0; // ����� ����� � �������
    Massiv.arg=0;
    Massiv.i = 0; //�������
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 2; j++)
            (Massiv.s_arg)[i][j] = '0';
        Massiv.sukaz_arg[i] = &Massiv.s_arg[i];
    }
    system("chcp 1251");
    system("cls");
    char SET[] = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm123456789";
    int set_len;
    srand((unsigned)time(NULL));
    int deistvie_int = 0;
    char deistvie;
    ukazf1 = &F1;
    ukazf2 = &boolf;
    int flag = 0;
    int flag2 = 0;
    rewind(stdin);
    while (deistvie_int >= 0 && deistvie_int <= 9)
    {
        deistvie_int = 10;
        printf("\n\n0 - �������������� ���� ������� int;\n1 - �������������� ���� ������� char;\n2 - �������������� ���� �����;\n3 - ������ ���� ������� int;\n4 - ������ ���� ������� char; \n5 - ������ ���� �����; 6 - concat; \n7 - ctest\n����� - ����� ������ �������;\n");
        rewind(stdin);
        deistvie = getchar();

        if (deistvie >= '0' && deistvie <= '7')
            deistvie_int = (deistvie - '0');

        if (deistvie_int == 0) //�������������� ���� ������� int
        {
            flag = 1;
            Massiv.arg = rand() % 15;
            Massiv.tip = 'i';
            Massiv.N = rand() % 9 + 1;
            printf("����������� ��������� � �������: %d", Massiv.N);
            Massiv.A = (void**)malloc(Massiv.N * sizeof(void*)); // ������������ ������ ���������� �� ������� 
                   //��������� �� �������
            for (int i = 0; i < Massiv.N; i++)
                Massiv.A[i] = mass_fint()[i];
            printf("��������, ���������� � �������: %d", Massiv.arg);
            printf("\n�������� ������� � �������:");
            for (int i = 0; i < Massiv.N; i++)
            {
                printf("\nf(%d) = ", i);
                printf("%d", ((int(*)(int))Massiv.A[i])(Massiv.arg));
            }
            char fff = '1';
            while (fff >= '1' && fff <= '5')
            {
                printf("\n�������: 1 - map;\n 2 -where;\n 3 - �������� �������,\n 4 - ������� ������� ��� ������� i,\n 5 - ������� �� ����� ��� ��������,\n����� ������ ������� - ����� � ������� ����; \n");
                rewind(stdin);
                scanf("%c", &fff);
                rewind(stdin);
                if (fff == '1')
                {
                    NewMassiv = map(Massiv, *ukazf1);
                    printf("\nMAP: ������ �� �������� �������, ���������� �� (-1):\n");
                    for (int i = 0; i < NewMassiv.N; i++)
                    {
                        printf("\nf(%d) = ", i);
                        printf("%d", (int*)NewMassiv.A[i]);
                    }
                }
                if (fff == '2')
                {
                    NewMassiv = where(Massiv, *ukazf2);
                    printf("\nWHERE: ������ �� �������� �������, ������� 2:\n");
                    for (int i = 0; i < NewMassiv.N; i++)
                    {
                        printf("\nf(%d) = ", i);
                        printf("%d", ((int(*)(int))(NewMassiv.A)[i])(NewMassiv.arg));
                    }
                }
                if (fff == '3')
                {
                    printf("\n������� ����� �������, ������� �� ������ ��������(1-10): ");
                    char numb;
                    scanf("%c", &numb);
                    if (numb < '1' && numb> '9')
                        printf("\n����� ������� ���, ��������� ������� �����");
                    else
                    {
                        int numb_int = (numb - '0');
                        Massiv = AddElem(Massiv, mass_fint()[numb_int-1]);
                    }
                }
                if (fff == '4')
                {
                    printf("\n������� ����� ��������(0-%d): ", Massiv.N);
                    int num = 1;
                    scanf("%d", &num);
                    if (num < '0' && num >= Massiv.N)
                        printf("\n������ �������� �� ����������, ��������� ������� �����");
                    else
                    {
                        printf("\nf(%d) = ", num);
                        printf("%d", ((int(*)(int))(Massiv.A)[num])(Massiv.arg));
                    }
                }
                if (fff == '5')
                {
                    printf("\n�������� ������� � �������:");
                    for (int i = 0; i < Massiv.N; i++)
                    {
                        printf("\nf(%d) = ", i);
                        printf("%d", ((int(*)(int))Massiv.A[i])(Massiv.arg));
                    }
                }
            }
        }


        if (deistvie_int == 1)//�������������� ���� ������� char
        {
            flag = 1;
            Massiv.tip= 'c';
            Massiv.N = rand() % 9 + 1;
            printf("����������� ��������� � �������: %d", Massiv.N);
            Massiv.A = (void**)malloc(Massiv.N * sizeof(void*)); // ������������ ������ ���������� �� ������� 
                   //��������� �� �������
            for (int i = 0; i < Massiv.N; i++)
                Massiv.A[i] = mass_fchar()[i];
            printf("\n�������� ������� � �������: ");
            for (int i = 0; i < Massiv.N; i++)
            {
                printf("\n f%d ������: ", i);
                printf("%s", (((char* (*)(char*, char k[20])) Massiv.A[i])) (Massiv.sukaz_arg[i], Massiv.s_arg[i]));
            }

            char fff = '1';
            while (fff >= '1' && fff <= '5')
            {
                printf("\n�������: 1 - map;\n 2 -where;\n 3 - �������� �������,\n 4 - ������� ������� ��� ������� i,\n 5 - ������� �� ����� ��� ��������,\n����� ������ ������� - ����� � ������� ����; \n");
                rewind(stdin);
                scanf("%c", &fff);
                rewind(stdin);
                if (fff == '1')
                {
                    NewMassiv = map(Massiv, *ukazf1);
                    printf("\nMAP: ������ �������, ��� �������, ������������ �� �������� �����, �������� �� ��������� �������� ������� : \n");
                    for (int i = 0; i < NewMassiv.N; i++)
                    {
                        printf("\nf(%d) = ", i);
                        printf("%s", (((char* (*)(char*, char k[20])) Massiv.A[i])) (Massiv.sukaz_arg[i], Massiv.s_arg[i]));
                    }
                }
                if (fff == '2')
                {
                    NewMassiv = where(Massiv, *ukazf2);
                    printf("\nWhere: ������ �������, ������������ ������, ������������ �� ��������� �����:\n");
                    for (int i = 0; i < NewMassiv.N; i++)
                    {
                        printf("\nf(%d) = ", i);
                        printf("%s", (((char* (*)(char*, char k[20])) NewMassiv.A[i])) (NewMassiv.sukaz_arg[i], NewMassiv.s_arg[i]));
                    }
                }
                if (fff == '3')
                {
                        printf("\n������� ����� �������, ������� �� ������ ��������(1-9): ");
                        char numb;
                        rewind(stdin);
                        scanf("%c", &numb);
                        if (numb < '1' && numb> '9')
                            printf("\n����� ������� ���, ��������� ������� �����");
                        else
                        {
                            int numb_int = (numb - '0');
                            Massiv = AddElem(Massiv, mass_fchar()[numb_int - 1]);
                        }
                }
                if (fff == '4')
                {
                        printf("\n������� ����� ��������(0-%d): ", Massiv.N);
                        int num = 1;
                        scanf("%d", &num);
                        if (num < '0' && num > Massiv.N)
                            printf("\n������ �������� �� ����������, ��������� ������� �����");
                        else
                        {
                            printf("\n f%d ������: ", num);
                            printf("%s", (((char* (*)(char*, char k[20])) Massiv.A[num-1])) (Massiv.sukaz_arg[num-1], Massiv.s_arg[num-1]));
                        }
                }
                    if (fff == '5')
                    {
                        printf("\n�������� ������� � �������: ");
                        for (int i = 0; i < Massiv.N; i++)
                        {
                            printf("\n f%d ������: ", i);
                            printf("%s", (((char* (*)(char*, char k[20])) Massiv.A[i])) (Massiv.sukaz_arg[i], Massiv.s_arg[i]));
                        }
                    }
            }
        }

        if (deistvie_int == 2)//�������������� ���� �����
        {
            flag = 1;
            Massiv.tip = 's';
            Massiv.dlinstr = rand() % 33 + 1;
            Massiv.N = rand() % 33 + 1;
            printf("\n����������� ��������� � �������: %d", Massiv.N);
            printf("\n����� �����: %d", Massiv.dlinstr);
            Massiv.A = (void**)malloc(Massiv.N * sizeof(void*)); // ������������ ������ ���������� �� ������
            char* a = (char*)malloc((Massiv.N) * Massiv.dlinstr * sizeof(char));
            for (int i = 0; i < Massiv.N; i++)
            {
                for (int j = 0; j < Massiv.dlinstr; j++)
                {
                    srand(j + i * 12 + (unsigned)time(NULL));
                    set_len = strlen(SET);
                    *(a + i * Massiv.dlinstr + j) = SET[rand() % set_len];
                }
                Massiv.A[i] = a + i * Massiv.dlinstr;
            }
            printf("\n C����� � ������������ �������:");
            for (int i = 0; i < Massiv.N; i++)
            {
                printf("\n %d ������:", i);
                for (int j = 0; j < Massiv.dlinstr; j++)
                    printf("%c", *((char*)Massiv.A[i] + j));
            }
            char fff = '1';
            while (fff >= '1' && fff <= '5')
            {
                printf("\n�������: 1 - map;\n 2 -where;\n 3 - �������� �������,\n 4 - ������� ������� ��� ������� i,\n 5 - ������� �� ����� ��� ��������,\n����� ������ ������� - ����� � ������� ����; \n");
                rewind(stdin);
                scanf("%c", &fff);
                rewind(stdin);
                if (fff == '1')
                {
                    NewMassiv = map(Massiv, *ukazf1);
                    printf("\nMAP: ��������� ������ ����� � ������ ������ � ���������: \n");
                    for (int i = 0; i < Massiv.N; i++)
                    {
                        printf("\ns%d - ", i);
                        printf("%c", *((char*)NewMassiv.A[i]));
                    }
                }
                if (fff == '2')
                {
                    NewMassiv = where(Massiv, *ukazf2);
                    printf("\nWhere: ������, ������������ �� �����:\n");
                    for (int i = 0; i < NewMassiv.N; i++)
                    {
                        printf("\n %d ������:", i);
                        for (int j = 0; j < NewMassiv.dlinstr; j++)
                            printf("%c", *((char*)NewMassiv.A[i] + j));
                    }
                }
                if (fff == '3')
                {
                    rewind(stdin);
                    printf("\n������� ������, ������� �� ������ ��������(����� %d): ", Massiv.dlinstr);
                    void* a = (void*)malloc(Massiv.dlinstr * sizeof(char));
                    for (int j = 0; j < Massiv.dlinstr; j++)
                        scanf("%c", (char*)a + j);
                    rewind(stdin);
                    Massiv = AddElem(Massiv, a);
                }
                if (fff == '4')
                {
                    printf("\n������� ����� ��������(0-%d): ", Massiv.N);
                    int num = 1;
                    scanf("%d", &num);
                    if (num < '0' && num > Massiv.N)
                         printf("\n������ �������� �� ����������, ��������� ������� �����");
                    else
                    {
                     printf("\nf(%d) = ", num);
                        for (int j = 0; j < Massiv.dlinstr; j++)
                        printf("%c", *((char*)Massiv.A[num] + j));
                    }
                }
                if (fff == '5')
                {
                    printf("\n C����� � ������������ �������:");
                    for (int i = 0; i < Massiv.N; i++)
                    {
                        printf("\n %d ������:", i);
                        for (int j = 0; j < Massiv.dlinstr; j++)
                            printf("%c", *((char*)Massiv.A[i] + j));
                    }
                }
            }
        free(a);
        }

        if (deistvie_int == 3)//������ ���� �������� int
        {
            flag = 1;
            printf("\n������� �����, ����������� � �������� ��������� �������: ");
            scanf("%d", &Massiv.arg);
            Massiv.tip = 'i';
            printf("\n������� ���������� ��������� � �������(<10): ");
            scanf("%d", &Massiv.N);
            Massiv.A = (void**)malloc(Massiv.N * sizeof(void*)); // ������������ ������ ���������� �� ������� 
                   //��������� �� �������
            for (int i = 0; i < Massiv.N; i++)
                Massiv.A[i] = mass_fint()[i];
            printf("\n�������� ������� � �������: ");
            for (int i = 0; i < Massiv.N; i++)
            {
                printf("\nf(%d) = ", i);
                printf("%d", ((int(*)(int))Massiv.A[i])(Massiv.arg));
            }
            char fff = '1';
            while (fff >= '1' && fff <= '5')
            {
                printf("\n�������: 1 - map;\n 2 -where;\n 3 - �������� �������,\n 4 - ������� ������� ��� ������� i,\n 5 - ������� �� ����� ��� ��������,\n����� ������ ������� - ����� � ������� ����; \n");
                rewind(stdin);
                scanf("%c", &fff);
                rewind(stdin);
                if (fff == '1')
                {
                    NewMassiv = map(Massiv, *ukazf1);
                    printf("\nMAP: ������ �� �������� �������, ���������� �� (-1):\n");
                    for (int i = 0; i < NewMassiv.N; i++)
                    {
                        printf("\nf(%d) = ", i);
                        printf("%d", (int*)NewMassiv.A[i]);
                    }
                }
                if (fff == '2')
                {
                    NewMassiv = where(Massiv, *ukazf2);
                    printf("\nWHERE: ������ �� �������� �������, ������� 2:\n");
                    for (int i = 0; i < NewMassiv.N; i++)
                    {
                        printf("\nf(%d) = ", i);
                        printf("%d", ((int(*)(int))(NewMassiv.A)[i])(NewMassiv.arg));
                    }
                }
                if (fff == '3')
                {
                    printf("\n������� ����� �������, ������� �� ������ ��������(1-10): ");
                    char numb;
                    scanf("%c", &numb);
                    if (numb < '1' && numb> '9')
                        printf("\n����� ������� ���, ��������� ������� �����");
                    else
                    {
                        int numb_int = (numb - '0');
                        Massiv = AddElem(Massiv, mass_fint()[numb_int - 1]);
                    }
                }
                if (fff == '4')
                {
                    printf("\n������� ����� ��������(0-%d): ", Massiv.N);
                    int num = 1;
                    scanf("%d", &num);
                    if (num < '0' && num > Massiv.N)
                        printf("\n������ �������� �� ����������, ��������� ������� �����");
                    else
                    {
                        printf("\nf(%d) = ", num);
                        printf("%d", ((int(*)(int))(Massiv.A)[num])(Massiv.arg));
                    }
                }
                if (fff == '5')
                {
                    printf("\n�������� ������� � �������:");
                    for (int i = 0; i < Massiv.N; i++)
                    {
                        printf("\nf(%d) = ", i);
                        printf("%d", ((int(*)(int))Massiv.A[i])(Massiv.arg));
                    }
                }
            }
        }

        if (deistvie_int == 4)//������ ���� ������� char
        {
            flag = 1;
            Massiv.tip = 'c';
            printf("\n������� ���������� ��������� � �������(<10)");
            scanf("%d", &Massiv.N);
            Massiv.A = (void**)malloc(Massiv.N * sizeof(void*)); // ������������ ������ ���������� �� ������� 
                   //��������� �� �������
            for (int i = 0; i < Massiv.N; i++)
                Massiv.A[i] = mass_fchar()[i];
            printf("\n�������� ������� � �������: ");
            for (int i = 0; i < Massiv.N; i++)
            {
                printf("\n %d ������: ", i);
                printf("%s", (((char* (*)(char*, char k[20])) Massiv.A[i])) (Massiv. sukaz_arg[i], Massiv.s_arg[i]));
            }
            char fff = '1';
            while (fff >= '1' && fff <= '2')
            {
                printf("\n�������: 1 - map; 2 -where; ����� ������ ������� - ����� � ������� ����; \n");
                rewind(stdin);
                scanf("%c", &fff);
                rewind(stdin);
                char fff = '1';
                while (fff >= '1' && fff <= '5')
                {
                    printf("\n�������: 1 - map;\n 2 -where;\n 3 - �������� �������,\n 4 - ������� ������� ��� ������� i,\n 5 - ������� �� ����� ��� ��������,\n����� ������ ������� - ����� � ������� ����; \n");
                    rewind(stdin);
                    scanf("%c", &fff);
                    rewind(stdin);
                    if (fff == '1')
                    {
                        NewMassiv = map(Massiv, *ukazf1);
                        printf("\nMAP: ������ �������, ��� �������, ������������ �� �������� �����, �������� �� ��������� �������� ������� : \n");
                        for (int i = 0; i < NewMassiv.N; i++)
                        {
                            printf("\nf(%d) = ", i);
                            printf("%s", (((char* (*)(char*, char k[20])) Massiv.A[i])) (Massiv.sukaz_arg[i], Massiv.s_arg[i]));
                        }
                    }
                    if (fff == '2')
                    {
                        NewMassiv = where(Massiv, *ukazf2);
                        printf("\nWhere: ������ �������, ������������ ������, ������������ �� ��������� �����:\n");
                        for (int i = 0; i < NewMassiv.N; i++)
                        {
                            printf("\nf(%d) = ", i);
                            printf("%s", (((char* (*)(char*, char k[20])) NewMassiv.A[i])) (NewMassiv.sukaz_arg[i], NewMassiv.s_arg[i]));
                        }
                    }
                        if (fff == '3')
                        {
                            printf("\n������� ����� �������, ������� �� ������ ��������(1-9): ");
                            char numb;
                            scanf("%c", &numb);
                            if (numb < '1' && numb> '9')
                                printf("\n����� ������� ���, ��������� ������� �����");
                            else
                            {
                                int numb_int = (numb - '0');
                                Massiv = AddElem(Massiv, mass_fchar()[numb_int - 1]);
                            }
                        }
                        if (fff == '4')
                        {
                            printf("\n������� ����� ��������(0-%d): ", Massiv.N);
                            int num = 1;
                            scanf("%d", &num);
                            if (num < '0' && num > Massiv.N)
                                printf("\n������ �������� �� ����������, ��������� ������� �����");
                            else
                            {
                                printf("\n f%d ������: ", num);
                                printf("%s", (((char* (*)(char*, char k[20])) Massiv.A[num - 1])) (Massiv.sukaz_arg[num - 1], Massiv.s_arg[num - 1]));
                            }
                        }
                        if (fff == '5')
                        {
                            printf("\n�������� ������� � �������: ");
                            for (int i = 0; i < Massiv.N; i++)
                            {
                                printf("\n f%d ������: ", i);
                                printf("%s", (((char* (*)(char*, char k[20])) Massiv.A[i])) (Massiv.sukaz_arg[i], Massiv.s_arg[i]));
                            }
                        }
                }
            }
        }

        if (deistvie_int == 5) //������ ���� �����
        {
            flag = 1;
            Massiv.tip = 's';
            printf("\n������� ���������� ��������� � �������: ");
            rewind(stdin);
            scanf("%d", &Massiv.N);
            printf("\n������� ����� ������: ");
            rewind(stdin);
            scanf("%d", &Massiv.dlinstr);
            rewind(stdin);
            Massiv.A = (void**)malloc(Massiv.N * sizeof(void*)); // ������������ ������ ���������� �� ������
            char* a = (char*)malloc((Massiv.N) * Massiv.dlinstr * sizeof(char));
            printf("\n�������  ������ �� %d ��������(� ������ ������������ ����������� ������ %d ��������� �������)", Massiv.dlinstr, Massiv.dlinstr);
            rewind(stdin);
            for (int i = 0; i < Massiv.N; i++)
            {
                printf("\n%d ������:", i);
                for (int j = 0; j < Massiv.dlinstr; j++)
                    scanf("%c", (a + i * Massiv.dlinstr + j));
                rewind(stdin);
            }

            for (int i = 0; i < Massiv.N; i++)
                Massiv.A[i] = a + i * Massiv.dlinstr;
            printf("\n C����� � ������������ �������:");
            for (int i = 0; i < Massiv.N; i++)
            {
                printf("\n %d ������:", i);
                for (int j = 0; j < Massiv.dlinstr; j++)
                    printf("%c", *((char*)Massiv.A[i] + j));
            }
            char fff = '1';
            while (fff >= '1' && fff <= '5')
            {
                printf("\n�������: 1 - map;\n 2 -where;\n 3 - �������� �������,\n 4 - ������� ������� ��� ������� i,\n 5 - ������� �� ����� ��� ��������,\n����� ������ ������� - ����� � ������� ����; \n");
                rewind(stdin);
                scanf("%c", &fff);
                rewind(stdin);
                if (fff == '1')
                {
                    NewMassiv = map(Massiv, *ukazf1);
                    printf("\nMAP: ��������� ������ ����� � ������ ������ � ���������: \n");
                    for (int i = 0; i < Massiv.N; i++)
                    {
                        printf("\ns%d - ", i);
                        printf("%c", *((char*)NewMassiv.A[i]));
                    }
                }
                if (fff == '2')
                {
                    NewMassiv = where(Massiv, *ukazf2);
                    printf("\nWhere: ������, ������������ �� �����:\n");
                    for (int i = 0; i < NewMassiv.N; i++)
                    {
                        printf("\n %d ������:", i);
                        for (int j = 0; j < NewMassiv.dlinstr; j++)
                            printf("%c", *((char*)NewMassiv.A[i] + j));
                    }
                }
                if (fff == '3')
                {
                    printf("\n������� ������, ������� �� ������ ��������(����� %d): ", Massiv.dlinstr);
                    void* a = (void*)malloc(Massiv.dlinstr * sizeof(char));
                    for (int j = 0; j < Massiv.dlinstr; j++)
                        scanf("%c", (char*)a + j);
                    rewind(stdin);
                    Massiv = AddElem(Massiv, a);
                }
                if (fff == '4')
                {
                    printf("\n������� ����� ��������(0-%d): ", Massiv.N);
                    int num = 1;
                    scanf("%d", &num);
                    if (num < '0' && num > Massiv.N)
                        printf("\n������ �������� �� ����������, ��������� ������� �����");
                    else
                    {
                        printf("\nf(%d) = ", num);
                        for (int j = 0; j < Massiv.dlinstr; j++)
                            printf("%c", *((char*)Massiv.A[num] + j));
                    }
                }
                if (fff == '5')
                {
                    printf("\n C����� � ������������ �������:");
                    for (int i = 0; i < Massiv.N; i++)
                    {
                        printf("\n %d ������:", i);
                        for (int j = 0; j < Massiv.dlinstr; j++)
                            printf("%c", *((char*)Massiv.A[i] + j));
                    }
                }
            }
            free(a);
        }

        if (deistvie_int == 6) //concat
        {
            flag2 = 1;
            string.dlins1 = rand() % 13 + 1;
            string.dlins2 = rand() % 17 + 1;
            string.dlins_out = string.dlins1 + string.dlins2;
            printf("����� 1 ������: %d;\n ����� 2 ������: %d", string.dlins1, string.dlins2);
            string.s1 = (char*)malloc(string.dlins1 * sizeof(char));
            string.s2 = (char*)malloc(string.dlins2 * sizeof(char));
            string.s_out = (char*)malloc(string.dlins_out * sizeof(char));
            int set_len;
            set_len = strlen(SET);
            srand(string.dlins1);
            printf("\n 1 ������: ");
            for (int i = 0; i < string.dlins1; i++)
            {
                string.s1[i] = SET[(rand() + i) % set_len];
                printf("%c", string.s1[i]);
            }
            srand(string.dlins2);
            printf("\n 2 ������: ");
            for (int i = 0; i < string.dlins2; i++)
            {
                string.s2[i] = SET[(rand() + i) % set_len];
                printf("%c", string.s2[i]);
            }
            string.s_out = concat(string);
            printf("\nf1 ��������� ������: ");
            for (int i = 0; i < string.dlins_out; i++)
                printf("%c", string.s_out[i]);
        }

        if (deistvie_int == 7)
        {
           if (flag == 1) ctest1(Massiv);
           if (flag2 ==1) ctest2(string);
        }
    }
    free(Massiv.A);
    free(NewMassiv.A);
}
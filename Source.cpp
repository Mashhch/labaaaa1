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

// массив указателей на функции
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
} String;

typedef struct {
    void** A; // массив
    int N; // колво элементов в массиве
    char tip; //  i - integer, c -char, s - stroka
    int dlinstr; // длина строк в массиве
}Arr;

Arr AddElem(Arr Massiv, void* elem)
{
    void** elems = (void**)malloc((unsigned long int)((Massiv.N) + 1) * sizeof(void*));
    for (int i = 0; i < Massiv.N; i++)
        elems[i] = Massiv.A[i];
    elems[Massiv.N] = elem;
    free(Massiv.A);
    Massiv.N++;
    Massiv.A = elems;
    return Massiv;
}

char* concat(String string, char* s_out)
{
    s_out = (char*)malloc((string.dlins1 + string.dlins2 )* sizeof(char));
    int dlins_out;
    for (int i = 0; i < string.dlins1; i++)
        s_out[i] = string.s1[i];
    for (int j = 0; j < string.dlins2; j++)
        s_out[j + string.dlins1] = string.s2[j];
    dlins_out = string.dlins1 + string.dlins2;
    return s_out;
}


void ctest1(Arr Massiv)
{
    //struct Arr
    printf("\nСтруктура: Massiv\nКоличество элементов в массиве: %d", Massiv.N);
    if (Massiv.tip == 'c')
        printf("\nМассив хранит указатели на функции, возвращающие указатель на char");
    if (Massiv.tip == 'i')
        printf("\nМассив хранит указатели на функции, возвращающие указатель на int");
    if (Massiv.tip == 's')
        printf("\nМассив хранит указатели на char");
}

void* F1(void* A)
{
    int flag = 0;
    char* sukaz_arg[9]; 
    char s_arg[9][20];
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 2; j++)
            s_arg[i][j] = '0';
        sukaz_arg[i] = &s_arg[i];
    }
    for (int i = 0; i < 9; i++)
    {
        if (A == mass_fchar()[i])
        {
            flag = 1;
            if ('a' <= *(((char* (*)(char*, char k[20])) A) (sukaz_arg, s_arg)) && *(((char* (*)(char*, char k[20])) A) (sukaz_arg, s_arg)) <= 'z')
            {
                if (i != 0)
                {
                    A = mass_fchar()[i - 1];
                }
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        if (A == mass_fint()[i])
        {
            flag = 1;
            (int*)A = ((int(*)(int))mass_fint()[i])(i)* (-1);
        }
    }

    if (flag == 0)
    {
        if (*((char*)A) <= 'z' && *((char*)A) >= 'a')
             *((char*)A) = *((char*)A) + 'A' - 'a';
    }

    return A;
}

Arr map( Arr Massiv, void* F(void*))
{
    Arr NewMassiv;
    NewMassiv = Massiv;
    for (int i = 0;i<NewMassiv.N;i++)
      NewMassiv.A[i] = (*F)(NewMassiv.A[i]);
    return NewMassiv;
}

int boolf(Arr Massiv, int i)
{
    char* sukaz_arg[9]; //аргумент для char
    char s_arg[9][20]; //аргумент для char
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 2; j++)
            s_arg[i][j] = '0';
        sukaz_arg[i] = &s_arg[i];
    }
    int flag = 0;
    if (Massiv.tip == 'i') //int func
    {
        if (((int(*)(int))Massiv.A[i])(i) % 3 == 0)
        {
            flag = 1; // :3
        }
    }
    if (Massiv.tip == 's') // stroka
    {
        if ('A' <= *((char*)Massiv.A[i]) && *((char*)Massiv.A[i]) <= 'Z')
            flag = 1;// строка начинается на заглавную
    }

    if (Massiv.tip == 'c') // char func
    {
        if ('A' <= *(((char* (*)(char*, char k[20])) Massiv.A[i]) (sukaz_arg[i], s_arg[i])) && *(((char* (*)(char*, char k[20])) Massiv.A[i]) (sukaz_arg[i], s_arg[i])) <= 'Z')
            flag = 1; // строка начинается на заглавную
    }
    if (flag == 1) return 1; else return 0;
}
Arr where(Arr Massiv, int F(Arr Massiv, int i))
//void** where(int* newN, void** newA, int N, void** A, char tip, int arg, char* s1[9], char s[9][20],int (*F)(int i, void** A, char tip, int arg, char* s1[9], char s[9][20]))
{
    Arr NewMassiv;
    NewMassiv = Massiv;
    int j = 0;
    int chet = 0;
    int i = 0;
    int t;
    for (i = 0; i < NewMassiv.N; i++)
    {
        t = (*F)(NewMassiv, i);
        if (t == 1)
            chet++;
    }
    void** newA = (void**)malloc(chet * sizeof(void*));
    for (i = 0; i < NewMassiv.N; i++)
    {
        t = (*F)(NewMassiv, i);
        if (t == 1)
        {
            newA[j] = NewMassiv.A[i];
            j++;
        }
    }
    NewMassiv.N = chet;
    return NewMassiv;
}

main()
{
    char* sukaz_arg[9];
    char s_arg[9][20];
    Arr Massiv;
    Arr NewMassiv;
    String string;
    void* (*ukazf1)(void* A);
    int (*ukazf2)(Arr Massiv, int i);
    Massiv.N = 0;
    Massiv.tip = '0'; //  i - integer, c -char, s - stroka
    Massiv.dlinstr = 0; // длина строк в массиве
    int arg = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 2; j++)
            (s_arg)[i][j] = '0';
        sukaz_arg[i] = &s_arg[i];
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
        printf("\n\n0 - Автоматический ввод функций int;\n1 - Автоматический ввод функций char;\n2 - Автоматический ввод строк;\n3 - ручной ввод функций int;\n4 - ручной ввод функций char; \n5 - ручной ввод строк; 6 - concat; \n7 - ctest\nВыход - любая другая клавиша;\n");
        rewind(stdin);
        deistvie = getchar();

        if (deistvie >= '0' && deistvie <= '7')
            deistvie_int = (deistvie - '0');

        if (deistvie_int == 0) //Автоматический ввод функций int
        {
            flag = 1;
            arg = rand() % 15;
            Massiv.tip = 'i';
            Massiv.N = rand() % 9 + 1;
            printf("Колличество элементов в массиве: %d", Massiv.N);
            Massiv.A = (void**)malloc(Massiv.N * sizeof(void*)); // динамический массив указателей на функции 
                   //указатели на функции
            for (int i = 0; i < Massiv.N; i++)
                Massiv.A[i] = mass_fint()[i];
            printf("Значение, подаваемое в функции: %d", arg);
            printf("\nЗначения функций в массиве:");
            for (int i = 0; i < Massiv.N; i++)
            {
                printf("\nf(%d) = ", i);
                printf("%d", ((int(*)(int))Massiv.A[i])(arg));
            }
            char fff = '1';
            while (fff >= '1' && fff <= '5')
            {
                printf("\nФункции: 1 - map;\n 2 -where;\n 3 - добавить элемент,\n 4 - вывести элемент под номером i,\n 5 - вывести на экран все элементы,\nЛюбая другая клавиша - выход в главное меню; \n");
                rewind(stdin);
                scanf("%c", &fff);
                rewind(stdin);
                if (fff == '1')
                {
                    NewMassiv = map(Massiv, *ukazf1);
                    printf("\nMAP: В i функцию посылается arg = i, значение умножается на (-1):\n");
                    for (int i = 0; i < NewMassiv.N; i++)
                    {
                        printf("\nf(%d) = ", i);
                        printf("%d", (int*)NewMassiv.A[i]);
                    }
                }
                if (fff == '2')
                {
                    NewMassiv = where(Massiv, *ukazf2);
                    printf("\nWHERE: массив из значений функций, кратных 3, при arg = i:\n");
                    for (int i = 0; i < NewMassiv.N; i++)
                    {
                        printf("\nf(%d) = ", i);
                        printf("%d", ((int(*)(int))(NewMassiv.A)[i])(arg));
                    }
                }
                if (fff == '3')
                {
                    printf("\nВведите номер функции, которую вы хотите добавить(1-10): ");
                    char numb;
                    scanf("%c", &numb);
                    if (numb < '1' && numb> '9')
                        printf("\nТакой функции нет, повторите попытку ввода");
                    else
                    {
                        int numb_int = (numb - '0');
                        Massiv = AddElem(Massiv, mass_fint()[numb_int - 1]);
                    }
                }
                if (fff == '4')
                {
                    printf("\nВведите номер элемента(0-%d): ", Massiv.N);
                    int num = 1;
                    scanf("%d", &num);
                    if (num < '0' && num >= Massiv.N)
                        printf("\nТакого элемента не существует, повторите попытку ввода");
                    else
                    {
                        printf("\nf(%d) = ", num);
                        printf("%d", ((int(*)(int))(Massiv.A)[num])(arg));
                    }
                }
                if (fff == '5')
                {
                    printf("\nЗначения функций в массиве:");
                    for (int i = 0; i < Massiv.N; i++)
                    {
                        printf("\nf(%d) = ", i);
                        printf("%d", ((int(*)(int))Massiv.A[i])(arg));
                    }
                }
            }
        }


        if (deistvie_int == 1)//Автоматический ввод функций char
        {
            flag = 1;
            Massiv.tip = 'c';
            Massiv.N = rand() % 9 + 1;
            printf("Колличество элементов в массиве: %d", Massiv.N);
            Massiv.A = (void**)malloc(Massiv.N * sizeof(void*)); // динамический массив указателей на функции 
                   //указатели на функции
            for (int i = 0; i < Massiv.N; i++)
                Massiv.A[i] = mass_fchar()[i];
            printf("\nЗначения функций в массиве: ");
            for (int i = 0; i < Massiv.N; i++)
            {
                printf("\n f%d строка: ", i);
                printf("%s", (((char* (*)(char*, char k[20])) Massiv.A[i])) (sukaz_arg[i], s_arg[i]));
            }

            char fff = '1';
            while (fff >= '1' && fff <= '5')
            {
                printf("\nФункции: 1 - map;\n 2 -where;\n 3 - добавить элемент,\n 4 - вывести элемент под номером i,\n 5 - вывести на экран все элементы,\nЛюбая другая клавиша - выход в главное меню; \n");
                rewind(stdin);
                scanf("%c", &fff);
                rewind(stdin);
                if (fff == '1')
                {
                    NewMassiv = map(Massiv, *ukazf1);
                    printf("\nMAP: массив указателей на функцийЖ если функция начинающаяся на строчную букву, \nячейке массива присваевается адрес предыдущей по номеру функции: \n");
                    for (int i = 0; i < NewMassiv.N; i++)
                    {
                        printf("\nf(%d) = ", i);
                        printf("%s", (((char* (*)(char*, char k[20])) Massiv.A[i])) (sukaz_arg[i], s_arg[i]));
                    }
                }
                if (fff == '2')
                {
                    NewMassiv = where(Massiv, *ukazf2);
                    printf("\nWhere: массив функций, возвращающих строки, начинающиеся на заглавные буквы:\n");
                    for (int i = 0; i < NewMassiv.N; i++)
                    {
                        printf("\nf(%d) = ", i);
                        printf("%s", (((char* (*)(char*, char k[20])) NewMassiv.A[i])) (sukaz_arg, s_arg));
                    }
                }
                if (fff == '3')
                {
                    printf("\nВведите номер функции, которую вы хотите добавить(1-9): ");
                    char numb;
                    rewind(stdin);
                    scanf("%c", &numb);
                    if (numb < '1' && numb> '9')
                        printf("\nТакой функции нет, повторите попытку ввода");
                    else
                    {
                        int numb_int = (numb - '0');
                        Massiv = AddElem(Massiv, mass_fchar()[numb_int - 1]);
                    }
                }
                if (fff == '4')
                {
                    printf("\nВведите номер элемента(0-%d): ", Massiv.N);
                    int num = 1;
                    scanf("%d", &num);
                    if (num < '0' && num > Massiv.N)
                        printf("\nТакого элемента не существует, повторите попытку ввода");
                    else
                    {
                        printf("\n f%d строка: ", num);
                        printf("%s", (((char* (*)(char*, char k[20])) Massiv.A[num - 1])) (sukaz_arg[num - 1], s_arg[num - 1]));
                    }
                }
                if (fff == '5')
                {
                    printf("\nЗначения функций в массиве: ");
                    for (int i = 0; i < Massiv.N; i++)
                    {
                        printf("\n f%d строка: ", i);
                        printf("%s", (((char* (*)(char*, char k[20])) Massiv.A[i])) (sukaz_arg, s_arg));
                    }
                }
            }
        }

        if (deistvie_int == 2)//Автоматический ввод строк
        {
            flag = 1;
            Massiv.tip = 's';
            Massiv.dlinstr = rand() % 33 + 1;
            Massiv.N = rand() % 33 + 1;
            printf("\nКолличество элементов в массиве: %d", Massiv.N);
            printf("\nДлина строк: %d", Massiv.dlinstr);
            Massiv.A = (void**)malloc(Massiv.N * sizeof(void*)); // динамический массив указателей на строки
            char* a = (char*)malloc((unsigned long long)(Massiv.N) * (unsigned long long)Massiv.dlinstr * sizeof(char));
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
            printf("\n Cтроки в динамическом массиве:");
            for (int i = 0; i < Massiv.N; i++)
            {
                printf("\n %d строка:", i);
                for (int j = 0; j < Massiv.dlinstr; j++)
                    printf("%c", *((char*)Massiv.A[i] + j));
            }
            char fff = '1';
            while (fff >= '1' && fff <= '5')
            {
                printf("\nФункции: 1 - map;\n 2 -where;\n 3 - добавить элемент,\n 4 - вывести элемент под номером i,\n 5 - вывести на экран все элементы,\nЛюбая другая клавиша - выход в главное меню; \n");
                rewind(stdin);
                scanf("%c", &fff);
                rewind(stdin);
                if (fff == '1')
                {
                    NewMassiv = map(Massiv, *ukazf1);
                    printf("\nMAP: Массив первых букв строк, переведенных в заглавные: \n");
                    for (int i = 0; i < Massiv.N; i++)
                    {
                        printf("\ns%d - ", i);
                        printf("%c", *((char*)NewMassiv.A[i]));
                    }
                }
                if (fff == '2')
                {
                    NewMassiv = where(Massiv, *ukazf2);
                    printf("\nWhere: Строки, начинающиеся на буквы:\n");
                    for (int i = 0; i < NewMassiv.N; i++)
                    {
                        printf("\n %d строка:", i);
                        for (int j = 0; j < NewMassiv.dlinstr; j++)
                            printf("%c", *((char*)NewMassiv.A[i] + j));
                    }
                }
                if (fff == '3')
                {
                    rewind(stdin);
                    printf("\nВведите строку, которую вы хотите добавить(длины %d): ", Massiv.dlinstr);
                    void* a = (void*)malloc(Massiv.dlinstr * sizeof(char));
                    for (int j = 0; j < Massiv.dlinstr; j++)
                        scanf("%c", (char*)a + j);
                    rewind(stdin);
                    Massiv = AddElem(Massiv, a);
                }
                if (fff == '4')
                {
                    printf("\nВведите номер элемента(0-%d): ", Massiv.N);
                    int num = 1;
                    scanf("%d", &num);
                    if (num < '0' && num > Massiv.N)
                        printf("\nТакого элемента не существует, повторите попытку ввода");
                    else
                    {
                        printf("\nf(%d) = ", num);
                        for (int j = 0; j < Massiv.dlinstr; j++)
                            printf("%c", *((char*)Massiv.A[num] + j));
                    }
                }
                if (fff == '5')
                {
                    printf("\n Cтроки в динамическом массиве:");
                    for (int i = 0; i < Massiv.N; i++)
                    {
                        printf("\n %d строка:", i);
                        for (int j = 0; j < Massiv.dlinstr; j++)
                            printf("%c", *((char*)Massiv.A[i] + j));
                    }
                }
            }
            free(a);
        }

        if (deistvie_int == 3)//ручной ввод функиций int
        {
            flag = 1;
            printf("\nВведите число, выступающее в качестве аргумента функций: ");
            scanf("%d", &arg);
            Massiv.tip = 'i';
            printf("\nВведите количество элементов в массиве(<10): ");
            scanf("%d", &Massiv.N);
            Massiv.A = (void**)malloc(Massiv.N * sizeof(void*)); // динамический массив указателей на функции 
                   //указатели на функции
            for (int i = 0; i < Massiv.N; i++)
                Massiv.A[i] = mass_fint()[i];
            printf("\nЗначения функций в массиве: ");
            for (int i = 0; i < Massiv.N; i++)
            {
                printf("\nf(%d) = ", i);
                printf("%d", ((int(*)(int))Massiv.A[i])(arg));
            }
            char fff = '1';
            while (fff >= '1' && fff <= '5')
            {
                printf("\nФункции: 1 - map;\n 2 -where;\n 3 - добавить элемент,\n 4 - вывести элемент под номером i,\n 5 - вывести на экран все элементы,\nЛюбая другая клавиша - выход в главное меню; \n");
                rewind(stdin);
                scanf("%c", &fff);
                rewind(stdin);
                if (fff == '1')
                {
                    NewMassiv = map(Massiv, *ukazf1);
                    printf("\nMAP: В i функцию посылается arg = i, значение умножается на (-1):\n");
                    for (int i = 0; i < NewMassiv.N; i++)
                    {
                        printf("\nf(%d) = ", i);
                        printf("%d", (int*)NewMassiv.A[i]);
                    }
                }
                if (fff == '2')
                {
                    NewMassiv = where(Massiv, *ukazf2);
                    printf("\nWHERE: массив из значений функций, кратных 3, при arg = i:\n");
                    for (int i = 0; i < NewMassiv.N; i++)
                    {
                        printf("\nf(%d) = ", i);
                        printf("%d", ((int(*)(int))(NewMassiv.A)[i])(arg));
                    }
                }
                if (fff == '3')
                {
                    printf("\nВведите номер функции, которую вы хотите добавить(1-10): ");
                    char numb;
                    scanf("%c", &numb);
                    if (numb < '1' && numb> '9')
                        printf("\nТакой функции нет, повторите попытку ввода");
                    else
                    {
                        int numb_int = (numb - '0');
                        Massiv = AddElem(Massiv, mass_fint()[numb_int - 1]);
                    }
                }
                if (fff == '4')
                {
                    printf("\nВведите номер элемента(0-%d): ", Massiv.N);
                    int num = 1;
                    scanf("%d", &num);
                    if (num < '0' && num > Massiv.N)
                        printf("\nТакого элемента не существует, повторите попытку ввода");
                    else
                    {
                        printf("\nf(%d) = ", num);
                        printf("%d", ((int(*)(int))(Massiv.A)[num])(arg));
                    }
                }
                if (fff == '5')
                {
                    printf("\nЗначения функций в массиве:");
                    for (int i = 0; i < Massiv.N; i++)
                    {
                        printf("\nf(%d) = ", i);
                        printf("%d", ((int(*)(int))Massiv.A[i])(arg));
                    }
                }
            }
        }

        if (deistvie_int == 4)//Ручной ввод функций char
        {
            flag = 1;
            Massiv.tip = 'c';
            printf("\nВведите количество элементов в массиве(<10)");
            scanf("%d", &Massiv.N);
            Massiv.A = (void**)malloc(Massiv.N * sizeof(void*)); // динамический массив указателей на функции 
                   //указатели на функции
            for (int i = 0; i < Massiv.N; i++)
                Massiv.A[i] = mass_fchar()[i];
            printf("\nЗначения функций в массиве: ");
            for (int i = 0; i < Massiv.N; i++)
            {
                printf("\n %d строка: ", i);
                printf("%s", (((char* (*)(char*, char k[20])) Massiv.A[i])) (sukaz_arg[i], s_arg[i]));
            }
            char fff = '1';
            while (fff >= '1' && fff <= '2')
            {
                printf("\nФункции: 1 - map; 2 -where; Любая другая клавиша - выход в главное меню; \n");
                rewind(stdin);
                scanf("%c", &fff);
                rewind(stdin);
                char fff = '1';
                while (fff >= '1' && fff <= '5')
                {
                    printf("\nФункции: 1 - map;\n 2 -where;\n 3 - добавить элемент,\n 4 - вывести элемент под номером i,\n 5 - вывести на экран все элементы,\nЛюбая другая клавиша - выход в главное меню; \n");
                    rewind(stdin);
                    scanf("%c", &fff);
                    rewind(stdin);
                    if (fff == '1')
                    {
                        NewMassiv = map(Massiv, *ukazf1);
                        printf("\nMAP: массив указателей на функцийЖ если функция начинающаяся на строчную букву, \nячейке массива присваевается адрес предыдущей по номеру функции: \n");
                        for (int i = 0; i < NewMassiv.N; i++)
                        {
                            printf("\nf(%d) = ", i);
                            printf("%s", (((char* (*)(char*, char k[20])) Massiv.A[i])) (sukaz_arg[i], s_arg[i]));
                        }
                    }
                    if (fff == '2')
                    {
                        NewMassiv = where(Massiv, *ukazf2);
                        printf("\nWhere: массив функций, возвращающих строки, начинающиеся на заглавные буквы:\n");
                        for (int i = 0; i < NewMassiv.N; i++)
                        {
                            printf("\nf(%d) = ", i);
                            printf("%s", (((char* (*)(char*, char k[20])) NewMassiv.A[i])) (sukaz_arg, s_arg));
                        }
                    }
                    if (fff == '3')
                    {
                        printf("\nВведите номер функции, которую вы хотите добавить(1-9): ");
                        char numb;
                        scanf("%c", &numb);
                        if (numb < '1' && numb> '9')
                            printf("\nТакой функции нет, повторите попытку ввода");
                        else
                        {
                            int numb_int = (numb - '0');
                            Massiv = AddElem(Massiv, mass_fchar()[numb_int - 1]);
                        }
                    }
                    if (fff == '4')
                    {
                        printf("\nВведите номер элемента(0-%d): ", Massiv.N);
                        int num = 1;
                        scanf("%d", &num);
                        if (num < '0' && num > Massiv.N)
                            printf("\nТакого элемента не существует, повторите попытку ввода");
                        else
                        {
                            printf("\n f%d строка: ", num);
                            printf("%s", (((char* (*)(char*, char k[20])) Massiv.A[num - 1])) (sukaz_arg[num - 1], s_arg[num - 1]));
                        }
                    }
                    if (fff == '5')
                    {
                        printf("\nЗначения функций в массиве: ");
                        for (int i = 0; i < Massiv.N; i++)
                        {
                            printf("\n f%d строка: ", i);
                            printf("%s", (((char* (*)(char*, char k[20])) Massiv.A[i])) (sukaz_arg[i], s_arg[i]));
                        }
                    }
                }
            }
        }

        if (deistvie_int == 5) //ручной ввод строк
        {
            flag = 1;
            Massiv.tip = 's';
            printf("\nВведите количество элементов в массиве: ");
            rewind(stdin);
            scanf("%d", &Massiv.N);
            printf("\nВведите длину строки: ");
            rewind(stdin);
            scanf("%d", &Massiv.dlinstr);
            rewind(stdin);
            Massiv.A = (void**)malloc(Massiv.N * sizeof(void*)); // динамический массив указателей на строки
            char* a = (char*)malloc((Massiv.N) * Massiv.dlinstr * sizeof(char));
            printf("\nВведите  строки из %d символов(в случае переполнения учитываются первые %d введенных символа)", Massiv.dlinstr, Massiv.dlinstr);
            rewind(stdin);
            for (int i = 0; i < Massiv.N; i++)
            {
                printf("\n%d строка:", i);
                for (int j = 0; j < Massiv.dlinstr; j++)
                    scanf("%c", (a + i * Massiv.dlinstr + j));
                rewind(stdin);
            }

            for (int i = 0; i < Massiv.N; i++)
                Massiv.A[i] = a + i * Massiv.dlinstr;
            printf("\n Cтроки в динамическом массиве:");
            for (int i = 0; i < Massiv.N; i++)
            {
                printf("\n %d строка:", i);
                for (int j = 0; j < Massiv.dlinstr; j++)
                    printf("%c", *((char*)Massiv.A[i] + j));
            }
            char fff = '1';
            while (fff >= '1' && fff <= '5')
            {
                printf("\nФункции: 1 - map;\n 2 -where;\n 3 - добавить элемент,\n 4 - вывести элемент под номером i,\n 5 - вывести на экран все элементы,\nЛюбая другая клавиша - выход в главное меню; \n");
                rewind(stdin);
                scanf("%c", &fff);
                rewind(stdin);
                if (fff == '1')
                {
                    NewMassiv = map(Massiv, *ukazf1);
                    printf("\nMAP: Массив первых букв строк, переведенных в заглавные: \n");
                    for (int i = 0; i < Massiv.N; i++)
                    {
                        printf("\ns%d - ", i);
                        printf("%c", *((char*)NewMassiv.A[i]));
                    }
                }
                if (fff == '2')
                {
                    NewMassiv = where(Massiv, *ukazf2);
                    printf("\nWhere: Строки, начинающиеся на буквы:\n");
                    for (int i = 0; i < NewMassiv.N; i++)
                    {
                        printf("\n %d строка:", i);
                        for (int j = 0; j < NewMassiv.dlinstr; j++)
                            printf("%c", *((char*)NewMassiv.A[i] + j));
                    }
                }
                if (fff == '3')
                {
                    printf("\nВведите строку, которую вы хотите добавить(длины %d): ", Massiv.dlinstr);
                    void* a = (void*)malloc(Massiv.dlinstr * sizeof(char));
                    for (int j = 0; j < Massiv.dlinstr; j++)
                        scanf("%c", (char*)a + j);
                    rewind(stdin);
                    Massiv = AddElem(Massiv, a);
                }
                if (fff == '4')
                {
                    printf("\nВведите номер элемента(0-%d): ", Massiv.N);
                    int num = 1;
                    scanf("%d", &num);
                    if (num < '0' && num > Massiv.N)
                        printf("\nТакого элемента не существует, повторите попытку ввода");
                    else
                    {
                        printf("\nf(%d) = ", num);
                        for (int j = 0; j < Massiv.dlinstr; j++)
                            printf("%c", *((char*)Massiv.A[num] + j));
                    }
                }
                if (fff == '5')
                {
                    printf("\n Cтроки в динамическом массиве:");
                    for (int i = 0; i < Massiv.N; i++)
                    {
                        printf("\n %d строка:", i);
                        for (int j = 0; j < Massiv.dlinstr; j++)
                            printf("%c", *((char*)Massiv.A[i] + j));
                    }
                }
            }
            free(a);
        }

        if (deistvie_int == 6) //concat
        {
            char* s_out; // склеенная строка
            int dlins_out;
            flag2 = 1;
            string.dlins1 = rand() % 13 + 1;
            string.dlins2 = rand() % 17 + 1;
            dlins_out = string.dlins1 + string.dlins2;
            printf("Длина 1 строки: %d;\n Длина 2 строки: %d", string.dlins1, string.dlins2);
            string.s1 = (char*)malloc(string.dlins1 * sizeof(char));
            string.s2 = (char*)malloc(string.dlins2 * sizeof(char));
            s_out = (char*)malloc(dlins_out * sizeof(char));
            int set_len;
            set_len = strlen(SET);
            srand(string.dlins1);
            printf("\n 1 строка: ");
            for (int i = 0; i < string.dlins1; i++)
            {
                string.s1[i] = SET[(rand() + i) % set_len];
                printf("%c", string.s1[i]);
            }
            srand(string.dlins2);
            printf("\n 2 строка: ");
            for (int i = 0; i < string.dlins2; i++)
            {
                string.s2[i] = SET[(rand() + i) % set_len];
                printf("%c", string.s2[i]);
            }
            s_out = concat(string,s_out);
            printf("\nf1 Склеенная строка: ");
            for (int i = 0; i < string.dlins2+ string.dlins1; i++)
                printf("%c", s_out[i]);
        }

        if (deistvie_int == 7)
        {
            if (flag == 1) ctest1(Massiv);
        }
    }
    free(Massiv.A);
    free(NewMassiv.A);
}

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <functional>
// Задание 2. Дан текстовый файл.Необходимо создать
// новый файл и записать в него такую статистику по исходному файлу :
// ■■ Количество символов;
// ■■ Количество строк;
// ■■ Количество гласных; A,E,I,O,U,Y
// ■■ Количество согласных; B,C,D,F,G,H,J,K,L,M,N,P,Q,R,S,T,V,W,X,Z
// ■■ Количество цифр.

const int BUFF = 100;


void num_str(char* num_s)  // ■■ Количество символов
{
    std::cout << "Number of characters = " << strlen(num_s) << std::endl;
    
}

void num_vowels_and_consonants(char* num_s)  // ■■ Количество гласных и согласных
{
    int rezalt = strlen(num_s);
    int iter1 = 0;
    int iter2 = 0;
    for (size_t i = 0; i < rezalt; i++)  
    {
        if (num_s[i] == 'a' || num_s[i] == 'e' || num_s[i] == 'i' ||
            num_s[i] == 'o' || num_s[i] == 'u' || num_s[i] == 'y')
        {
            iter1++;
        }
        else
        {
            iter2++;
        }
    }
    std::cout << "Number of vowels = " << iter1 << std::endl;
    std::cout << "Number of consonants = " << iter2 << std::endl;
}

void num_num(char* num_s)  // ■■ Количество цифр.
{
    int rezalt = strlen(num_s);
    int iter = 0;
    for (size_t i = 0; i < rezalt; i++)
    {
        if (num_s[i] == '0' || num_s[i] == '1' || num_s[i] == '2' ||
            num_s[i] == '3' || num_s[i] == '4' || num_s[i] == '5' ||
            num_s[i] == '6' || num_s[i] == '7' || num_s[i] == '8' ||
            num_s[i] == '9')
        {
            iter++;
        }

    }
    std::cout << "Number of digits = " << iter << std::endl;
 
}
void next_line(char* num_s)  // ■■ Количество строк;
{
    int rezalt = strlen(num_s);
    int iter = 0;
    for (size_t i = 0; i < rezalt; i++)
    {
        if (num_s[i] == '\n')
        {
            iter++;
        }

    }
    std::cout << "Number of lines = " << iter << std::endl;
}

int main()
{ 
    // file_main.txt
    // file_stat.txt

    FILE* F = fopen("file_main.txt", "rt");  // "rt" - для чтения в текстовом виде с начала файла
    
    if (F == NULL)
    {
        std::cout << "file_main.txt not found" << std::endl;
        return -1;
    }
    std::cout << "file_main.txt open  " << std::endl;

    char file_txt[BUFF];
    fgets(file_txt, BUFF, F);

    std::cout << std::endl;
    std::cout << "file_main.txt = " << file_txt;
    std::cout << std::endl << std::endl;
    std::cout << "___Statistics___" << std::endl;
    num_str(file_txt);
    num_vowels_and_consonants(file_txt);
    num_num(file_txt);
    next_line(file_txt);

    std::cout << std::endl;

    FILE* G = fopen("file_stat.txt", "wt");  // "wt" - для записи в текстовом виде

    if (G == NULL)
    {
        std::cout << "file_stat.txt not found" << std::endl;
        return -2;
    }
    std::cout << "file_stat.txt open  " << std::endl;

    

    void (*stat1)(char*) = num_str;   // указатели на функции 
    void (*stat2)(char*) = num_vowels_and_consonants;
    void (*stat3)(char*) = num_num;
    void (*stat4)(char*) = next_line;
     
    //fwrite(&stat1, sizeof(char), 1, G);
    //fflush(G);

    std::ofstream file;
    file.open("file_stat.txt");
    if (file.is_open()) {
       
    }
    
    std::cout << std::endl;

  
    std::cout << reinterpret_cast<void*>(num_str) << std::endl
        << num_vowels_and_consonants << std::endl
        << num_num << std::endl
        << next_line << std::endl;

    std::cout << std::endl;

    std::cout << *stat1 << std::endl
        << stat2 << std::endl
        << stat3 << std::endl
        << stat4 << std::endl;
    
    file.close();
    fclose(F);
    fclose(G);
}

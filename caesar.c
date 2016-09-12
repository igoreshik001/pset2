#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[]) 
{
    // Проверка на количество аргументов
    if (argc<2 || argc>2)
    {
        printf("return");
        return 1;
    }
    
    int lenmess;// Длина сообщения
    int key = atoi(argv[1]);// Ключ переводим из стрингов в инт
    
    string mess;// сообщение
    //Инициализация сообщения, его длинны и проверка на содержание (на ноль)
    do
    {
        printf("plaintext: ");
        mess=get_string();
        for(lenmess=0;mess[lenmess]!='\0';lenmess++);
    }while(mess[0]==0);
    // создаем два массива с повторением (в два круга, чтобы удобно было смещать буквы), малых букв и больших (заглавных)
    char alf_m[52], alf_b[52];//alf_m - малые буквы, alf_b - большие буквы
    for (int n=65;n<65+26;n++)
    {
        alf_b[n-65]=n,alf_b[n-65+26]=n;
        alf_m[n-65]=n+32,alf_m[n-65+26]=n+32;
    }
    // Сокращаем ключ
    while ( key>26)
    {
        key=key%26;
    }
    //вывод результата со смещением
    printf("ciphertext: ");
    for (int n=0;n<lenmess;n++)
    {
        if (mess[n]>64 && mess[n]<91)// Если символ в диапазоне (asci) больших
        {
            printf("%c",alf_b[mess[n]-65+key]);// Выводим из массива с болшими символами
        }
        else if(mess[n]>96 && mess[n]<123)// Если в диапазоне малых
        {
            printf("%c",alf_m[mess[n]-97+key]);// Из "малого" массива
        }
        else// Иначе (ни там, ни тут)
        {
            printf("%c",mess[n]);// Не смещаем, выводим символ такой же как был
        }
    }
    printf("\n"); // Снос
    return 0;
    
}

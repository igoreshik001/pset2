#include <stdio.h>
#include <cs50.h>
//#include <string.h>
//#include <stdlib.h>
//#include <ctype.h>

int main(int argc, string argv[]) 
{
    //Проверка на количетво аргументов
    if (argc!=2)
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }
    
    int messlen,keylen;//Длинна сообщения и длинна ключа
    string key = (argv[1]);//Иниц. ключ с 1-го аргумента
    //Иниц. длинну ключа и проверка аргумента на лишние символы, если лишние "схлоп"
    for(keylen=0;key[keylen]!='\0';keylen++)
        if (key[keylen]<65 || ( key[keylen]>65+26 && key[keylen]<97) || key[keylen]>97+26)
        {
            printf("Usage: ./vigenere k\n");
            return 1;
        }
    // Иниц. сообщение через ввод пользователя
    string mess;
    do
    {
        printf("plaintext: ");
        mess=GetString();
        for(messlen=0;mess[messlen]!='\0';messlen++);
        //printf("%i\n",l);
    }
    while(mess[0]==0 && messlen==0);
    //Сбор двух массивов (малые и большие буквы) символов
    char alf_m[52], alf_b[52];
    for (int n=65;n<65+26;n++)
    {
        alf_b[n-65]=n,alf_b[n-65+26]=n;
        alf_m[n-65]=n+32,alf_m[n-65+26]=n+32;
    }
    //Вывод результата
    int offsetkey=0;// Иниц. смещщение индекса по ключу
    printf("ciphertext: ");
    for (int en=0;en<messlen;en++)// Перебор сообщения по символам
    {
        if ( key[offsetkey]<91)// Если символ ключа большой(заглавная буква)
        {
            key[offsetkey]+=32;// смещаем на малую
        }
        if (mess[en]>64 && mess[en]<91)//Если символ сообщения большой
        {
            printf("%c",alf_b[mess[en]-65+key[offsetkey]-97]);//Выводим из массива с большими символами 
        }
        else if(mess[en]>96 && mess[en]<123)//Если малый
        {
            printf("%c",alf_m[mess[en]-97+key[offsetkey]-97]);// из масссива с малыми
        }
        else
        {
            printf("%c",mess[en]);//иначе не меняя
            offsetkey--;// минусуем чтобы не смещать ключ
        }
        offsetkey++;//смещаем ключ на 1
        // Если ключ прошел круг, обнуляем
        if (offsetkey>=keylen)
        {
            offsetkey=0;
        }
    }
    printf("\n");//Снос
    return 0;
    
}

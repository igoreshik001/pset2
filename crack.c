#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    //проверка на количество аргументов
    if (argc!=2){
        printf("Usage: ./crack hash\n");
        return 1;
    }
    //Иниц. аргумента
    string hash=argv[1];
    //Иниц. массива симврлов ( алфавит из больших и малых букв)
    char alphabet[52];
    for (int i=0 ;i<26 ;i++)
    {
        alphabet[i]=i+'A', alphabet[i+26]=i+'a';
    }
    
    char pass[5]="";// Будущий пароль
    int flag=0;// флаг, для брейка циклов
    int index=0;// индекс для pass
    // Четыре цикла, на каждый разряд
    for (int i=-1; i<52; i++)// индекс срабатывает только при i=0
    {
        if (flag){//Если флаг помечен, выход из цикла
            break;}
        if (i==0){ //а вот и индекс
            index=3;
            pass[0]='A';}
        if (i>0){
            index=3;
            pass[index-3]=alphabet[i];}
        // та же схема. Цикл на следующий разряд 
        for ( int i1=-1; i1<52; i1++)
        {
            if (flag){
                break;}
            if (i1==0 && i==-1){
                index=2;
                pass[0]='A';}
            if (i1>0){
                pass[index-2]=alphabet[i1];}
            //   та же схема. Цикл на следующий разряд  
            for ( int i2=-1; i2<52; i2++)
            {
                if (flag){
                    break;}
                if (i2==0 && i1==-1 && i==-1){
                    index=1;
                    pass[0]='A';}
                if ( i2>0){
                    pass[index-1]=alphabet[i2];}
                // Крайний цикл
                for ( int i3=0; i3<52; i3++)
                {
                    if (flag){
                        break;}
                    pass[index]=alphabet[i3];// цикл по первому кругу имеет индекс [0] и массив состоит из одного символа,
                    //                          по второму [1], третьему [2] и четвертому [3]
                    string crack=crypt(pass, "50");// хеш функция по текущему паролю
                    // посимвольное сравнение хеш значений текущего (crack) пароля и данной хеш из аргумента
                    for (int n=0; n<13; n++)
                    {
                        if (crack[n]==hash[n])//если символы совпадают, меняем флаг на тру
                        {
                            flag=1;
                        }
                        else// если нет, то фальс, и сбрасываем цикл так как он уже не имеет смысла
                        {
                            flag=0;
                            break;
                        }
                    }
                }
            }
        }
    }
    
    printf("%s\n", pass);// вывод результата
}

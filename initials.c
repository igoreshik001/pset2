#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main ()
{
    // Перемернные: имя и длина строки имени
    string name;
    int lenname;
    // Инициализация переменных: имя( ввод пользоваеуля) и длина строки имя
    do
    {
        name = get_string();
    }
    while (name[0] == 0);
    lenname = strlen(name);
    //Проверка первой буквы на пробел, если не пробел вывод большой буквы
    if (name[0] != ' ')
    {
        printf("%c", toupper(name[0]));
    }
    //Перебор по буквам
    for (int i=0; i<lenname; i++)
    {
        //Проверка текущуй буквы на пробел и следующей на "не пробел ", выводим следующую большую букву
        if (name[i] == ' ' && name[i+1] != ' ' && i+1 < lenname)
        {
            printf("%c", toupper(name[i+1]));
        }
    }
    // Вывод переноса строки
    printf("\n");
    
    
}

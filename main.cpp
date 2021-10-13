#include <iostream>
#include "Header.h"
#include <locale.h>

using namespace std;

int main()
{
setlocale(LC_ALL,"Rus");
   tree* t=build();
   int i=1,id,w,lev;
   std::cout<<"Выберите действие:1-печать,2-добавить,3-удалить,4-индивидуальное задание,5-закончить\n";
   while(i){
        int c;
        std::cin>>c;
       switch(c){
            case 1:printin(t,0);
                    break;
            case 2:std::cout<<"Введите id и вес соответсвенно\n";
                    std::cin>>id>>w;
                    add(t,id,w);
                    break;
            case 3:std::cout<<"Введите id удаляемого элемента\n";
                    std::cin>>id;
                    Delete(t,id);
                    break;
            case 4:std::cout<<"Введите вес и уровень соответсвенно\n";
                    std::cin>>w>>lev;
                    individual(t,w,lev,0);
                    break;
            case 5:i=0;
                    break;
       }
   }
    return 0;
}

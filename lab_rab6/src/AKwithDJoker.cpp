#include "../hdr/AKfunc.hpp"

int main(){
    initBohr();
    string text, temp;
    char razd;
    cout<<"Введите текст:\n";
    cin>>text;
    cout<<"Введите шаблон:\n";
    cin>>temp;
    cout<<"Введите символ джокера:\n";
    cin>>razd;
    stringstream str_pat(temp);
    vector<int> count(text.size(),0); //вектор, содержащий счётчики вхождений частей шаблона
    vector<string> pattern; //вектор для частей шаблона
    vector<int> lenght = spliter(str_pat, razd, pattern);//места, где части шаблона заканчиваются в самом шаблоне
    findAllPosForDjoker(text, count, lenght);
    cout<<"Ответ:\n";
    printDj(count,text.size()-temp.size()+1,pattern.size());

    return 0;
}
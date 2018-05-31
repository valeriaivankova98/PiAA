#include "../hdr/AKfunc.hpp"

int main(){
    initBohr();
    string text, temp;
    int n;
    cout<<"Введите текст:\n";
    cin>>text;
    cout<<"Введите число шаблонов:\n";
    cin>>n;
    vector<string> pattern;
    map<int,vector<int>> answ;
    for(int i=0; i<n; i++){
        cout<<"Введите шаблоны:\n";
        cin>>temp;
        addstrBohr(temp, pattern);
    }
    findAllPosForStandart(text, pattern,answ);
    
    cout<<"Ответ:\n";
    printSt(answ);
    return 0;
}
#include "../hdr/AKfunc.hpp"

vector<Bohr> bohr;

Bohr makeBohr(int p, char c){ //Функции создания новой вершины и инициализации бора
    Bohr v;
    v.nextV[c]=v.auto_move[c]=-1;
    v.flag = false;
    v.suff_link = -1; //изначально - суф. ссылки нет
    v.parent = p; //передаем номер отца и символ на ребре в бор
    v.symb = c;
    v.suff_flink = -1;
    return v;
}

void initBohr(){
    bohr.clear();
    bohr.push_back(makeBohr(0,'$'));
}

void addstrBohr(const string& s, vector<string>& pattern){ //Процедура добавление строки-образца в бор
    int num = 0;
    for (size_t i = 0; i < s.length(); ++i){
        char ch = s[i];
        if(bohr[num].nextV.find(ch)==bohr[num].nextV.end() || bohr[num].nextV[ch]==-1){
            bohr.push_back(makeBohr(num, ch));
            bohr[num].nextV[ch] = bohr.size() - 1;
        }
        num=bohr[num].nextV[ch];
    }
    bohr[num].flag = true;
    pattern.push_back(s);
    bohr[num].pat_num.push_back(pattern.size() - 1);
}

int getSuff_link(int v){
    if (bohr[v].suff_link == -1){ //если еще не считали
        if (v == 0 || bohr[v].parent == 0) //если v - корень или предок v - корень
            bohr[v].suff_link = 0;
        else
            bohr[v].suff_link=getAuto_move(getSuff_link(bohr[v].parent), bohr[v].symb);
    }
    return bohr[v].suff_link;
}

int getAuto_move(int v, char ch){
    if (bohr[v].auto_move.find(ch)==bohr[v].auto_move.end() || bohr[v].auto_move[ch]==-1){
        if (bohr[v].nextV.find(ch)!=bohr[v].nextV.end() && bohr[v].nextV[ch]!=-1)
            bohr[v].auto_move[ch] = bohr[v].nextV[ch];
        else{
            if (v == 0)
                bohr[v].auto_move[ch] = 0;
            else
                bohr[v].auto_move[ch]=getAuto_move(getSuff_link(v), ch);
        }
    }
    return bohr[v].auto_move[ch];
}

int getSuff_flink(int v){
    if (bohr[v].suff_flink == -1) {
        int u = getSuff_link(v);
        if (u == 0)
            bohr[v].suff_flink = 0;
    else
        bohr[v].suff_flink = (bohr[u].flag) ? u : getSuff_flink(u);
    }
    return bohr[v].suff_flink;
}

void checkForStandart(int v,int i,const vector<string>& pattern, map<int,vector<int>>& answ){
    for(int u = v; u != 0; u = getSuff_flink(u)) {
        if (bohr[u].flag){
            answ[i - pattern[bohr[u].pat_num[0]].size() + 1].push_back(bohr[u].pat_num[0] + 1);
        }
    }
}

void checkForDjoker(int v,int i,vector<int>& count, const vector<int>& lenght){
    for(int u = v; u != 0; u = getSuff_flink(u)){
        if (bohr[u].flag){
            for(const auto& it: bohr[u].pat_num){
                if((size_t)(i-lenght[it])<count.size()){
                    count[i-lenght[it]]++;
                }
            }
        }
    }
}

void findAllPosForStandart(const string& s,const vector<string>& pattern, map<int,vector<int>>& answ){
    int u = 0;
    for(size_t i = 0; i < s.size(); i++) {
        u = getAuto_move(u, s[i]);
        checkForStandart(u, i+1, pattern, answ);

    }
}

void findAllPosForDjoker(const string& s,vector<int>& count, const vector<int>& lenght){
    int u = 0;
    for(size_t i = 0; i < s.size(); i++) {
        u = getAuto_move(u, s[i]);
        checkForDjoker(u, i+1, count,lenght);
    }
}

vector<int> spliter(stringstream& str_pat, char razd, vector<string>& pattern){
    vector<int> lenght;
    int len=0;
    string tmp;
    while(getline(str_pat,tmp,razd)){
      if(tmp.size()>0){
        len+=tmp.size();
        lenght.push_back(len);
        addstrBohr(tmp, pattern);
      }
      len++;
    }
    return lenght;
}
void printDj(const vector<int>& count, int stopper, int pattern_size){
    for(int i=0;i<stopper;i++){
        if(count[i]==pattern_size)
            cout<<i+1<<"\n";
    }
}

void printSt(map<int, vector<int>>& answ){
    for(auto& it: answ){
        sort(it.second.begin(),it.second.end());
        for(const auto& it_sec: it.second)
        cout<<it.first<<" "<<it_sec<<"\n";
    }
}
#include <iostream>
#include <string>
using namespace std;

class element{
public:
    int num[10000];
    int leng;
    int startnum;
    element(){
        for(int i = 0 ; i< 10000; i++){
            num[i] = 0;
        }
        leng = 0;
        startnum = 0;
    }
};
int empty(element *ele){
    if(ele->startnum % 10000 == ele->leng % 10000)
        return 1; 
    else
        return 0;
}

void push(element *ele, int num){
    ele->num[ele->leng % 10000] = num;
    ele->leng++;
}

void pop(element *ele){
     if(empty(ele) == 1)
        cout << "-1" << endl;
    else{
        cout << ele->num[ele->startnum % 10000] << endl;
        ele->startnum++;
    }
}

void size(element *ele){
    cout << ele->leng % 10000 - ele->startnum % 10000 << endl;
}

void front(element *ele){
    if(empty(ele) == 1)
        cout << "-1" << endl;
    else{
        cout << ele->num[ele->startnum % 10000] << endl;
    }
}

void back(element *ele){
    if(empty(ele) == 1)
        cout << "-1" << endl;
    else{
        cout << ele->num[(ele->leng % 10000) -1] << endl;
    }
}

int main(){
    element ele;
    int N;
    cin >> N;
    string input;
    for(int i = 0; i < N; i++){
        cin >> input;
        string a, b;
        a = input.substr(0,3);
        if(!a.compare("pus")){
            cin >> b;
            int num = stoi(b);
            push(&ele, num);
        } 
        else if(!a.compare("pop")){
            pop(&ele);
        }else if(!a.compare("fro")){
            front(&ele);
        }else if(!a.compare("bac")){
            back(&ele);
        }else if(!a.compare("siz")){
            size(&ele);
        }else if(!a.compare("emp")){
            int flag = empty(&ele);
            if(flag == 1){
                cout << "1" << endl;
            }else{
                cout << "0" << endl;
            }    
        }
    }
}

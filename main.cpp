#include <iostream>

using namespace std;

void SHR(string & , int , int);
void SHL(string & , int , int);
void REM(string & , int* , int);
void REV(string & , int);
void PUT(string & , int , char);
void reverseByIndex(string & , int , int);
void Delete(string & , int* , string , int);
void newString(string & , int*);



int main(){
    int n;
    cin >> n ;
    string s ;
    getline(cin >> ws , s);
    while (true){
        string order ;
        cin >> order ;
        if(order == "SHR"){
            int num ;
            cin >> num ;
            SHR(s,n,num);
        }else if(order == "SHL"){
            int num ;
            cin >> num ;
            SHL(s,n,num);
        }else if(order == "REM"){
            int num ;
            cin >> num ;
            if(num > n){
                cout << "ERROR" ;
                continue;
            }
            REM(s , &n , num);
        }else if(order == "REV"){
            REV(s , n);
        }else if(order == "PUT"){
            int num ;
            char key ;
            cin >> num >> key ;
            PUT(s , num , key);
        }else if(order == "PRI"){
            if(n > 0){
                cout << s << endl ;
            }else {
                cout << "EMPTY" << endl ;
            }
        }else if(order == "reverseByIndex"){
            int num1 , num2 ;
            cin >> num1 >> num2 ;
            reverseByIndex(s , num1 , num2);
        }else if(order == "delete"){
            string key ;
            cin >> key ;
            int m = key.size() ;
            Delete(s , &n , key , m);
        }else if(order == "newString"){
            newString(s , &n);
        }else {
            break;
        }
    }
    return 0 ;
}

void SHR(string &s , int n , int num){
    for(int i = 0 ; i < num ; i++){
        char q = s[n-1] ;
        for(int j = n-2 ; j >= 0 ; j--){
            s[j+1] = s[j] ;
        }
        s[0] = q ;
    }
}
void SHL(string &s , int n , int num){
    for(int i = 0 ; i < num ; i++){
        char q = s[0] ;
        for(int j = 1 ; j < n ; j++){
            s[j-1] = s[j] ;
        }
        s[n-1] = q ;
    }
}
void REM(string &s , int *n , int num){
    for(int i = *n-num ; i < *n ; i++){
        s[i] = '\0';
    }
    *n -= num ;
}
void REV(string &s , int n){
    for(int i = 0 ; i < n/2 ; i++){
        char q = s[i] ;
        s[i] = s[n-1-i];
        s[n-1-i] = q ;
    }
}
void PUT(string &s , int num , char key){
    s[num-1] = key ;
}
void reverseByIndex(string &s , int num1 , int num2){
    for(int i = 0 ; i < ((num2-num1)/2)+1 ; i++){
        char q = s[num1+i] ;
        s[num1+i] = s[num2-i];
        s[num2-i] = q ;
    }
}
void Delete(string &s , int* n , string key , int m){
    for(int i = 0 ; i < *n-m+1 ; i++){
        string q = s.substr(i , m);
        if(q == key){
            int k = 0 ;
            for(int j = i+m ; j < *n ; j++){
                s[i+k] = s[j] ;
                k++ ;
            }
            REM(s , &*n , m);
        }
    }
}
void newString(string &s , int* n){
    string num ;
    for(int i = 0 ; i < *n ; i++){
        if((int)s[i] >= 48 && (int)s[i] <= 57){
            num += s[i] ;
            continue;
        }
        int w = (int)s[i] ;
        int e = w/100;
        if(e != 0){
            w = w % 100 ;
            num += char(e +'0');
        }
        int r = w/10;
        w = w % 10 ;
        num += char(r +'0');
        num += char(w +'0');
    }
    if(num.size()%2 == 1){
        num += "0" ;
    }
    string num2 ;
    for(int i = 0 ; i < num.size() ; i+=2){
        int sum = 0 ;
        sum = ((int)num[i]-48)*10 + ((int)num[i+1]-48) ;
        if(sum < 32){
            sum += 32 ;
        }
        num2 += char(sum) ;
    }
    s = num2 ;
    *n = s.size();
}

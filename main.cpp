#include <iostream>
using namespace std;

void makesame(string &s1, string &s2){
    int S1len = s1.length();
    int S2len = s2.length();
    
    if(S1len >= S2len){
        int diff = S1len - S2len;
        for(int i = 0; i < diff; i++){
            s2.insert(0,"0");
        }
    }else{
        int diff = S2len - S1len;
        for(int i = 0; i < diff; i++){
            s1.insert(0,"0");
        }
    }

}

string addition(string s1, string s2, int a){
    makesame(s1, s2);  

    string sum;
    int c = 0;  

    for(int i = s1.length() - 1; i >= 0; i--){
        int rec = int(s1[i] - '0') + int(s2[i] - '0') + c;
        c = 0;

        if(rec >= a){
            c = 1;  
            rec = rec - a;
        }

        sum.insert(0, to_string(rec)); 
    }

    if(c == 1){
        sum.insert(0, to_string(c));  
    }
    
    return sum;
}
 
    







int main(int argc, char*argv[]){
    string s1, s2;
    int a;

    cin >> s1 >> s2 >> a;

    cout<< addition(s1,s2,a) << endl;
    return 0;
}

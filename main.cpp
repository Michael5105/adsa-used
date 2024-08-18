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
 
    
string substration(string s1, string s2, int a){
    makesame(s1, s2);  

    string diff;
    int c = 0;  

    for(int i = s1.length() - 1; i >= 0; i--){
        int difft = 0;

        if(int(s1[i]-'0') - int(s2[i]-'0') - c < 0){
            difft = int(s1[i] - '0') - int(s2[i] - '0') + a - c;
            c = 1;
        }

        else{
            difft = int(s1[i] - '0') - int(s2[i] - '0') - c;
            c = 0;
        }
        diff.insert(0,to_string(difft));
    }

    
    return diff;
}


string multiplication(string s1, string s2, int a){
    makesame(s1, s2);  
    string mul;
    
    for(int i = s1.length() - 1; i >= 0; i--){
            string multi_t = "";
            int c = 0;

        for(int j = s2.length() - 1; j >= 0; j--){
            int multi_s = 0;

            if(int(s2[j]-'0')*int(s1[i]-'0') + c>= a){
                multi_s = (int(s2[j]-'0')*int(s1[i]-'0') + c) %a;
                c = (int(s2[j]-'0')*int(s1[i]-'0') + c - multi_s) / a; 
            }
            else{
                multi_s=(int(s2[j]-'0')*int(s1[i]-'0') + c);
                c = 0;
            }
            multi_t.insert(0,to_string(multi_s));
        }
        if (c != 0){
            multi_t.insert(0,to_string(c));
        }
        for(int k = 0; k < int(s1.length()-1)-i;k++){
            multi_t.append("0");
        }
        mul = addition(mul,multi_t,a);
    }
    while (mul.length() > 1 && mul[0] == '0') {
        mul.erase(0, 1);
    }
    return mul;

}

string karatsuba(string s1, string s2, int a){
    makesame(s1, s2);
    string ans;
    
    int length = s1.length();
    if(length <= 3){
        return multiplication(s1,s2,a);
    }

    string a1 = s1.substr(0, length/2);
    string a0 = s1.substr(length/2,length-length/2);
    string b1 = s2.substr(0,length/2);
    string b0 = s2.substr(length/2,length-length/2);

    string p0 = karatsuba(a0, b0, a);
    string p1 = karatsuba(addition(a1, a0, a), addition(b1, b0, a), a);
    string p2 = karatsuba(a1, b1, a);
    string p3 = substration(p1, addition(p2, p0, a), a);

    for(int i = 0; i < 2*(length-length/2);i++){
        p2.append("0");

    }

    for(int i = 0; i < (length-length/2); i++){
        p3.append("0");
    }

    ans = addition(addition(p2, p3, a), p0 , a);
    return ans;
}

int main(int argc, char*argv[]){
    string s1, s2;
    int a;

    cin >> s1 >> s2 >> a;

    cout<<addition(s1,s2,a)<<" "<<karatsuba(s1,s2,a) << endl;
    return 0;
}

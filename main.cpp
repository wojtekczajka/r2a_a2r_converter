#include <iostream>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;

map<int, char> dict_a2r;
map<char, int> dict_r2a;

int r2a(const char* input){
    if(*input == '\0')
        return 0;
    else if(*(input + 1) != '\0'){
        return dict_r2a[*input] < dict_r2a[*(input + 1)] ?
               (dict_r2a[*(input + 1)] - dict_r2a[*input]) + r2a(input + 2) : dict_r2a[*input] + r2a(input + 1);
    }
    else
        return dict_r2a[*input] + r2a(input + 1);
}

string a2r(int input){
    string ret; int multiplier = 1;
    while(input !=0){
        int rest = input % 10;
        if(rest == 4){
            auto x = dict_a2r.find((rest * multiplier) + multiplier);
            ret += x->second;
            x--;
            ret += x->second;
        }
        else if(rest % 10 == 9){
            auto x = dict_a2r.find((rest * multiplier) + multiplier);
            ret += x->second;
            x--; x--;
            ret += x->second;
        }
        else if (rest != 0){
            auto x = dict_a2r.find(multiplier);
            if(rest % 10 < 5){
                for(int i = 0; i < rest; i++)
                    ret += x->second;
            }
            else{
                for(int i = 0; i < rest - 5; i++)
                    ret += x->second;
                auto y = dict_a2r.find(5 * multiplier);
                ret += y->second;
            }
        }
        input /= 10; multiplier *= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main(){
    dict_a2r = {
            {1, 'I'}, {5,'V'}, {10, 'X'}, {50, 'L'}, {100, 'C'}, {500, 'D'}, {1000, 'M'},
            };
    dict_r2a = {
             {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000},
     };
     cout << "some examples" << endl;
     cout << "3921 = " << a2r(3921) << endl;
     cout << "CDXCIX = " << r2a("CDXCIX") << endl;
}

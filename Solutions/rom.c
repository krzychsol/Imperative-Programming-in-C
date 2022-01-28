#include <stdio.h>

typedef struct{
    char *sym;
    int val;
}numeral;

int maxNume(numeral *nu, int num){
    int i, index;
    for(i = 0; i<13; i++){
        if(nu[i].val <= num)
            index = i;
    }

    return index;
}

void decToRoman(numeral *nu, int num){
    int max;
    if(num != 0){
        max = maxNume(nu, num);
        printf("%s", nu[max].sym);
        num -= nu[max].val;
        decToRoman(nu, num);
    }
}

int roman_to_arabic(char num[]){
    int result = 0;
    int idx = 0;

    while(num[idx]){
        switch (num[idx]) {
            case 'I':
                result += 1;
                break;
            case 'V':
                result += 5;
                break;
            case 'X':
                result += 10;
                break;
            case 'L':
                result += 50;
                break;
            case 'C':
                result += 100;
                break;
            case 'D':
                result += 500;
                break;
            case 'M':
                result += 1000;
                break;
            default:
                return -1;
        }

        if(num[idx+1]){

            if( num[idx] == 'I' && num[idx+1] == 'V'){
                result -= 2;
            }
            if( num[idx] == 'I' && num[idx+1] == 'X'){
                result -= 2;
            }
            if( num[idx] == 'X' && num[idx+1] == 'L'){
                result -= 20;
            }
            if( num[idx] == 'X' && num[idx+1] == 'C'){
                result -= 20;
            }
            if( num[idx] == 'C' && num[idx+1] == 'D'){
                result -= 200;
            }
            if( num[idx] == 'C' && num[idx+1] == 'M'){
                result -= 200;
            }
        }

        idx++;

    }
    return result;
}

int main() {
    char num1[32];
    char num2[32];

    scanf("%s %s",&num1,&num2);

    numeral nume[13] = {{"I",1},{"IV",4},{"V",5},{"IX",9}, {"X",10},{"XL",40},{"L",50},{"XC",90},
                        {"C",100},{"CD",400},{"D",500},{"CM",900},{"M",1000}};

    int number;
    number = roman_to_arabic(num1) + roman_to_arabic(num2);
    decToRoman(nume, number);

    return 0;
}

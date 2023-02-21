#include<string.h>
#include<stdlib.h>
 
 unsigned char A[] = {0b11111111, 0b11111111, 0b00000001, 0b11110110, 0b11110110, 0b00000001, 0b11111111, 0b11111111};
 unsigned char B[] = {0b11111111, 0b11111111, 0b00000000, 0b01100110, 0b01100110, 0b00011000, 0b11111111, 0b11111111};
 unsigned char C[] = {0b11111111, 0b11111111, 0b10000001, 0b01111110, 0b01111110, 0b01111110, 0b11111111, 0b11111111};
 unsigned char D[] = {0b11111111, 0b11111111, 0b00000000, 0b01111110, 0b10111101, 0b11000011, 0b11111111, 0b11111111};
 unsigned char E[] = {0b11111111, 0b11111111, 0b00000000, 0b01100110, 0b01100110, 0b01100110, 0b11111111, 0b11111111};
 unsigned char F[] = {0b11111111, 0b11111111, 0b00000000, 0b11110110, 0b11110110, 0b11110110, 0b11111111, 0b11111111};
 unsigned char G[] = {0b11111111, 0b11111111, 0b00000000, 0b01111110, 0b01101110, 0b00001110, 0b11111111, 0b11111111};
 unsigned char H[] = {0b11111111, 0b11111111, 0b00000000, 0b11100111, 0b11100111, 0b00000000, 0b11111111, 0b11111111};
 unsigned char I[] = {0b11111111, 0b11111111, 0b01111110, 0b00000000, 0b00000000, 0b01111110, 0b11111111, 0b11111111};
 unsigned char J[] = {0b11111111, 0b11111111, 0b10111110, 0b01111110, 0b01111110, 0b00000000, 0b11111111, 0b11111111};
 unsigned char K[] = {0b11111111, 0b11111111, 0b00000000, 0b11000011, 0b10111101, 0b01111110, 0b11111111, 0b11111111};
 unsigned char L[] = {0b11111111, 0b11111111, 0b00000000, 0b01111111, 0b01111111, 0b01111111, 0b11111111, 0b11111111};
 unsigned char M[] = {0b11111111, 0b00000000, 0b11111101, 0b11111011, 0b11111011, 0b11111101, 0b00000000, 0b11111111};
 unsigned char N[] = {0b11111111, 0b00000000, 0b11111001, 0b11110011, 0b11100111, 0b11001111, 0b00000000, 0b11111111};
 unsigned char O[] = {0b11111111, 0b11111111, 0b10000001, 0b01111110, 0b01111110, 0b10000001, 0b11111111, 0b11111111};
 unsigned char P[] = {0b11111111, 0b11111111, 0b00000000, 0b11110110, 0b11110110, 0b11110000, 0b11111111, 0b11111111};
 unsigned char Q[] = {0b11111111, 0b11000011, 0b10111101, 0b10101101, 0b10011101, 0b10000011, 0b01111111, 0b11111111};
 unsigned char R[] = {0b11111111, 0b11111111, 0b00000000, 0b11001110, 0b10101110, 0b01100000, 0b11111111, 0b11111111};
 unsigned char S[] = {0b11111111, 0b11111111, 0b01111000, 0b01110110, 0b01101110, 0b00011110, 0b11111111, 0b11111111};
 unsigned char T[] = {0b11111111, 0b11111110, 0b11111110, 0b00000000, 0b00000000, 0b11111110, 0b11111110, 0b11111111};
 unsigned char U[] = {0b11111111, 0b11111111, 0b00000000, 0b01111111, 0b01111111, 0b00000000, 0b11111111, 0b11111111};
 unsigned char V[] = {0b11111111, 0b11000000, 0b10111111, 0b01111111, 0b01111111, 0b10111111, 0b11000000, 0b11111111};
 unsigned char W[] = {0b11111111, 0b00000000, 0b10111111, 0b11011111, 0b11011111, 0b10111111, 0b00000000, 0b11111111};
 unsigned char X[] = {0b11111111, 0b10111101, 0b11011011, 0b11100111, 0b11100111, 0b11011011, 0b10111101, 0b11111111};
 unsigned char Y[] = {0b11111111, 0b01111100, 0b01111011, 0b00000111, 0b00000111, 0b01111011, 0b01111100, 0b11111111};
 unsigned char Z[] = {0b11111111, 0b00111110, 0b01011110, 0b01101110, 0b01110110, 0b01111010, 0b01111100, 0b11111111};
 unsigned char SPACE[] = {0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111};
 unsigned char EXCLAMATION[] = {0b11111111, 0b11111111, 0b11111111, 0b00100000, 0b00100000, 0b11111111, 0b11111111, 0b11111111};
 unsigned char SMILEY[] = {0b11011111, 0b10111001, 0b01111001, 0b01111111, 0b01111111, 0b01111001, 0b10111001, 0b11011111};
 unsigned char QUESTION[] = {0b11111111, 0b11111111, 0b01000110, 0b11110110, 0b11110110, 0b11110000, 0b11111111, 0b11111111};
 unsigned char THREE[] = {0b11111111, 0b11111111, 0b01100110, 0b01100110, 0b01100110, 0b00000000, 0b11111111, 0b11111111};
 
 int invert = 0;
 int length = 0;
 int start = 0;
 
 void load(unsigned char *ch, unsigned char *arr)
 {
    arr[start] = ch[0]^invert;
    arr[start+1] = ch[1]^invert;
    arr[start+2] = ch[2]^invert;
    arr[start+3] = ch[3]^invert;
    arr[start+4] = ch[4]^invert;
    arr[start+5] = ch[5]^invert;
    arr[start+6] = ch[6]^invert;
    arr[start+7] = ch[7]^invert;
    start+=8;
 }    
 
 unsigned char* loadArr(unsigned char* str)
 {
    start = 0;
    int l = strlen((char*)str);
    length = (l+1)*8;
    unsigned char* arr = (unsigned char *)malloc(length * sizeof(char));
    while(*str){
        switch(*str){
            case 'A':
                load(A, arr);
                break;
            case 'B':
                load(B, arr);
                break;
            case 'C':
                load(C, arr);
                break;
            case 'D':
                load(D, arr);
                break;
            case 'E':
                load(E, arr);
                break;
            case 'F':
                load(F, arr);
                break;
            case 'G':
                load(G, arr);
                break;
            case 'H':
                load(H, arr);
                break;
            case 'I':
                load(I, arr);
                break;
            case 'J':
                load(J, arr);
                break;
            case 'K':
                load(K, arr);
                break;
            case 'L':
                load(L, arr);
                break;
            case 'M':
                load(M, arr);
                break;
            case 'N':
                load(N, arr);
                break;
            case 'O':
                load(O, arr);
                break;
            case 'P':
                load(P, arr);
                break;
            case 'Q':
                load(Q, arr);
                break;
            case 'R':
                load(R, arr);
                break;
            case 'S':
                load(S, arr);
                break;
            case 'T':
                load(T, arr);
                break;
            case 'U':
                load(U, arr);
                break;
            case 'V':
                load(V, arr);
                break;
            case 'W':
                load(W, arr);
                break;
            case 'X':
                load(X, arr);
                break;
            case 'Y':
                load(Y, arr);
                break;
            case 'Z':
                load(Z, arr);
                break;
            case ' ':
                load(SPACE, arr);
                break;
            case '!':
                load(EXCLAMATION, arr);
                break;
            case 's':
                load(SMILEY, arr);
                break;
            case '?':
                load(QUESTION, arr);
                break;
			case '3':
				load(THREE, arr);
				break;
        }
        str++;
    }
    load(SPACE, arr);
    return arr;
 }
 
 int getLength()
 {
     return length;
 }
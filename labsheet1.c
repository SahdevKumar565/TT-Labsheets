
//===============================
// Lab Sheet 1 - Solutions in C
//===============================

// Q1: Reverse a String
#include <stdio.h>
#include <string.h>
int main_q1() {
    char str[100];
    printf("Enter a string: ");
    gets(str);
    int i=0, j=strlen(str)-1;
    while(i<j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++; j--;
    }
    printf("Reversed String: %s\n", str);
    return 0;
}

// Q2: Replace Substring
#include <stdio.h>
#include <string.h>
int main_q2() {
    char str[200] = "I like C. C is powerful.";
    char find[10] = "C", replace[10] = "C++";
    char result[300] = "";
    char *pos, temp[200];
    strcpy(temp, str);
    while((pos = strstr(temp, find))) {
        *pos = '\0';
        strcat(result, temp);
        strcat(result, replace);
        strcpy(temp, pos + strlen(find));
    }
    strcat(result, temp);
    printf("Result: %s\n", result);
    return 0;
}

// Q3: Linear Search
#include <stdio.h>
int main_q3() {
    int arr[5] = {10, 20, 30, 40, 50}, n=5, key, i, found=0;
    printf("Enter number to search: ");
    scanf("%d", &key);
    for(i=0; i<n; i++) {
        if(arr[i]==key) { found=1; break; }
    }
    if(found) printf("%d found at index %d\n", key, i);
    else printf("%d not found\n", key);
    return 0;
}

// Q4: Bubble Sort
#include <stdio.h>
int main_q4() {
    int arr[5] = {34, 12, 5, 66, 1}, n=5, i, j, temp;
    for(i=0; i<n-1; i++) {
        for(j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("Sorted array: ");
    for(i=0; i<n; i++) printf("%d ", arr[i]);
    return 0;
}

// Q5: Reverse Array
#include <stdio.h>
int main_q5() {
    int arr[5] = {1,2,3,4,5}, i, j, temp;
    for(i=0, j=4; i<j; i++, j--) {
        temp=arr[i]; arr[i]=arr[j]; arr[j]=temp;
    }
    printf("Reversed array: ");
    for(i=0;i<5;i++) printf("%d ", arr[i]);
    return 0;
}

// Q6: Remove Duplicates
#include <stdio.h>
int main_q6() {
    int arr[7]={1,2,2,3,4,4,5}, n=7, i,j,k;
    for(i=0;i<n;i++) {
        for(j=i+1;j<n;j++) {
            if(arr[i]==arr[j]) {
                for(k=j;k<n-1;k++) arr[k]=arr[k+1];
                n--; j--;
            }
        }
    }
    printf("Array without duplicates: ");
    for(i=0;i<n;i++) printf("%d ", arr[i]);
    return 0;
}

// Q7: Merge Two Sorted Arrays
#include <stdio.h>
int main_q7() {
    int a[3]={1,3,5}, b[3]={2,4,6}, c[6], i=0,j=0,k=0;
    while(i<3 && j<3) {
        if(a[i]<b[j]) c[k++]=a[i++];
        else c[k++]=b[j++];
    }
    while(i<3) c[k++]=a[i++];
    while(j<3) c[k++]=b[j++];
    printf("Merged array: ");
    for(i=0;i<6;i++) printf("%d ", c[i]);
    return 0;
}

// Q8: Read File
#include <stdio.h>
int main_q8() {
    FILE *fp; char ch;
    fp=fopen("test.txt","r");
    if(fp==NULL){ printf("File not found!"); return 0; }
    while((ch=fgetc(fp))!=EOF) printf("%c",ch);
    fclose(fp);
    return 0;
}

// Q9: Copy File
#include <stdio.h>
int main_q9() {
    FILE *src, *dest; char ch;
    src=fopen("source.txt","r");
    dest=fopen("copy.txt","w");
    while((ch=fgetc(src))!=EOF) fputc(ch,dest);
    fclose(src); fclose(dest);
    printf("File copied successfully\n");
    return 0;
}

// Q10: Search Word in File
#include <stdio.h>
#include <string.h>
int main_q10() {
    FILE *fp; char word[20]="hello", temp[200]; int found=0;
    fp=fopen("test.txt","r");
    while(fscanf(fp,"%s",temp)!=EOF) {
        if(strcmp(temp,word)==0){ found=1; break; }
    }
    if(found) printf("Word found\n"); else printf("Word not found\n");
    fclose(fp);
    return 0;
}

// Project 1: Calculator
#include <stdio.h>
int main_p1() {
    char op; double a, b;
    printf("Enter operator (+ - * /): ");
    scanf(" %c", &op);
    printf("Enter two numbers: ");
    scanf("%lf %lf", &a, &b);
    switch(op) {
        case '+': printf("Result = %.2lf\n", a+b); break;
        case '-': printf("Result = %.2lf\n", a-b); break;
        case '*': printf("Result = %.2lf\n", a*b); break;
        case '/': if(b!=0) printf("Result = %.2lf\n", a/b); else printf("Divide by zero error\n"); break;
        default: printf("Invalid operator\n");
    }
    return 0;
}

// Project 2: Number Guessing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main_p2() {
    int num, guess, tries=0;
    srand(time(0));
    num = rand()%100 + 1;
    printf("Guess the number (1-100): ");
    do {
        scanf("%d", &guess); tries++;
        if(guess>num) printf("Too high! Try again: ");
        else if(guess<num) printf("Too low! Try again: ");
        else printf("Correct! You guessed in %d tries\n", tries);
    } while(guess!=num);
    return 0;
}

// Project 3: Tic Tac Toe
#include <stdio.h>
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
void showBoard() {
    printf("\n");
    for(int i=0;i<3;i++){ for(int j=0;j<3;j++) printf(" %c ", board[i][j]); printf("\n"); }
}
int checkWin() {
    for(int i=0;i<3;i++) if(board[i][0]==board[i][1] && board[i][1]==board[i][2]) return 1;
    for(int i=0;i<3;i++) if(board[0][i]==board[1][i] && board[1][i]==board[2][i]) return 1;
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]) return 1;
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0]) return 1;
    return 0;
}
int main_p3() {
    int choice, player=1, moves=0; char mark;
    while(1) {
        showBoard();
        mark = (player==1)? 'X':'O';
        printf("Player %d, enter position: ", player);
        scanf("%d", &choice);
        int r=(choice-1)/3, c=(choice-1)%3;
        if(board[r][c]!='X' && board[r][c]!='O') {
            board[r][c]=mark; moves++;
            if(checkWin()){ showBoard(); printf("Player %d wins!\n", player); break; }
            if(moves==9){ showBoard(); printf("Draw!\n"); break; }
            player=(player==1)?2:1;
        } else printf("Invalid move, try again!\n");
    }
    return 0;
}

// Project 4: Hangman (word=apple)
#include <stdio.h>
#include <string.h>
int main_p4() {
    char word[]="apple", guess[20], letter; int len=strlen(word), correct=0, tries=6;
    for(int i=0;i<len;i++) guess[i]='_'; guess[len]='\0';
    while(tries>0 && correct<len) {
        printf("Word: %s   Tries left: %d\n", guess, tries);
        printf("Guess a letter: "); scanf(" %c",&letter);
        int found=0;
        for(int i=0;i<len;i++) if(word[i]==letter && guess[i]=='_') { guess[i]=letter; correct++; found=1; }
        if(!found) tries--;
    }
    if(correct==len) printf("You guessed it! Word = %s\n", word);
    else printf("Game Over! Word was %s\n", word);
    return 0;
}

// Project 5: Quiz Game
#include <stdio.h>
int main_p5() {
    int score=0, ans;
    printf("Q1. Capital of India?\n1) Delhi  2) Mumbai\n");
    scanf("%d",&ans); if(ans==1) score++;
    printf("Q2. 2+2=?\n1) 3  2) 4\n");
    scanf("%d",&ans); if(ans==2) score++;
    printf("Q3. Largest ocean?\n1) Pacific  2) Atlantic\n");
    scanf("%d",&ans); if(ans==1) score++;
    printf("Your Score = %d/3\n", score);
    return 0;
}

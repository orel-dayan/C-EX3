#include <stdio.h>
#include <string.h>
#define LINE 256 
#define WORD 30
int getline_(char s[]);
int getword(char w[]);
int substring(char *str1, char *str2);
int similar(char *s, char *t, int n);
void print_lines(char *str);
void print_similar_words(char *str);

int main() {
    char word[WORD];
    char user,blank;
    scanf("%s %c%c",word,&user,&blank);
    if (user == 'a')
    {
        print_lines(word);
    }

    else if (user == 'b')
    {
        print_similar_words(word);
    }    
    return 0;
}


//func A

int getline_(char s[])
{
    int i = 0,c = 0;
    for (i = 0; i < LINE - 1 && c != '\n' && c!='\r'; ++i){
        if((c = getchar()) != EOF)
            if(c != '\r')
                s[i] = c;
            else
                s[i] = '\n';
        else
            return 0;
    }

    if (i==0) return 1;   
    s[i] = '\0';
    return i;
}

int substring(char *str1, char *str2)
{
    int len1 = strlen(str1); // length of str1
    int len2 = strlen(str2); // length of str2

    for (int i = 0; i < len2 - len1 + 1; i++)
    {
        if (strncmp(str1, str2 + i, len1) == 0)
            return 1;
    }
    return 0; 
}
void print_lines(char *str)
{
    char line[LINE]; // character array to hold the input line

    while (getline_(line) > 0)
    {
        if (substring(str, line)){
            printf("%s", line); 
        }
    }
}

// func B
int getword(char w[])
{
    int c, i;

    for (i = 0; i < WORD - 1 && (c = getchar()) != EOF && c != ' ' && c != '\t' && c != '\n'; ++i)
        w[i] = c;
    // Handle empty line
    if (c == '\n' && i==0)
        w[i++] = c;
    w[i] = '\0';
    return i;
}

int similar(char *s, char *t, int n)
{
    int len_s = strlen(s); // length of s
    int len_t = strlen(t); // length of t

    if (len_s < len_t || len_t + n < len_s)
        return 0; 

    int i = 0, j = 0;
    while (i < len_s && j < len_t)
    {
        if (s[i] == t[j])
            j++; 
        i++; 
    }
    return j == len_t; 
}

void print_similar_words(char *str) {
    char word[WORD]; 
    while (getword(word) > 0) { 
        if (similar(word, str, 1)) { 
            printf("%s\n", word); 
        }   
    }
}



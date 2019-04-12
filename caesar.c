#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void key_check(string s);
void input_key(int s);
string cipher(string t, int n);
    
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        exit(1);
    }
    
    key_check(argv[1]);
    int n = atoi(argv[1]);
    input_key(n);
    string ptext = get_string("plaintext: ");
    string ctext = cipher(ptext, n);
    printf("ciphertext: %s\n", ctext);
}

void key_check(string s)
{
    for (int i=1, l = strlen(s); i < l; i++ )
    {
        if (s[i]<'0' || s[i]>'9')
        {
            printf("Usage: ./caesar key\n");
            exit(1);
        }
        else
        {
            continue;
        }
    }
}

void input_key(int k)
{
    if (k < 1)
    {
        printf("Usage: ./caesar key\n");
        exit(0);
    }
}

string cipher(string t, int n)
{
    int l = strlen(t);
    for (int i=0; i < l; i++)
    {
        int s = t[i]+n;
        if (t[i] < 'A' || (t[i] > 'Z' & t[i] < 'a') || t[i] > 'z')
        {
            continue;
        }
        else if (t[i] <= 'z' & s > 'z') 
        {
            int d = s -'z'; 
            t[i] = 'a' + d - 1;  
        }
        else if (t[i] <= 'Z' & s > 'Z')
        {
            int d = s -'Z'; 
            t[i] = 'A' + d - 1;  
        }
        else
        {
            t[i] = s;
        }
    }
    return t;
}

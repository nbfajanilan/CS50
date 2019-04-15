#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void key_check(string s);
string cipher(string p, string c);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./vigenere keyword\n");
        exit(1);
    }
    
    key_check(argv[1]);
    string ptext = get_string("plaintext: ");
    string ctext = cipher(ptext, argv[1]);
    printf("ciphertext: %s\n", ctext);
}
 
// check if inout key is valid
void key_check(string s)
{
    for (int i = 1, l = strlen(s); i < l; i++)
    {
        if (s[i] < 'A' || (s[i] > 'Z' & s[i] < 'a') || s[i] > 'z')
        {
            printf("Usage: ./vigenere keyword\n");
            exit(1);
        }
        else
        {
            continue;
        }
    }
}

//function to encrypt the text
string cipher(string p, string k)
{
    int m = strlen(k);
    int l = strlen(p);
    int count = 0;
    char c[l];
    for (int j = 0; j < l; j++)
    {
        if (j % m == 0)
        {
            c[j] = k[0];
            count = 1;
        }
        else
        {
            c[j] = k[count];
            count ++;
        }
    }
    
    int n;
    int seq = 0;
    for (int i = 0; i < l; i++)
    {
        if (p[i] < 'A' || (p[i] > 'Z' & p[i] < 'a') || p[i] > 'z')
        {
            continue;
        }
        
        if (c[seq] >= 'A' & c[seq] <= 'Z')
        {
            n = c[seq] - 'A';
        }
        else
        {
            n = c[seq] - 'a';
        }
        
        int s = p[i] + n;
        if (s > 'z') 
        {
            int d = (s - 'z') % 26;
            p[i] = 'a' + d - 1;  
            seq ++;
        }
        else if (p[i] <= 'Z' & s > 'Z')
        {
            int d = (s - 'Z') % 26; 
            p[i] = 'A' + d - 1;  
            seq ++;
        }
        else
        {
            p[i] = s;
            seq ++;
        }
    }
    return p;
}

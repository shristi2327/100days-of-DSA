#include <stdio.h>
#include <string.h>

int main() {
    char s[100005];
    if (scanf("%s", s) != 1) return 0;
    
    int count[256] = {0};
    int len = strlen(s);
    
    for (int i = 0; i < len; i++) {
        count[(unsigned char)s[i]]++;
    }
    
    char res = '$';
    for (int i = 0; i < len; i++) {
        if (count[(unsigned char)s[i]] == 1) {
            res = s[i];
            break;
        }
    }
    
    printf("%c\n", res);
    
    return 0;
}

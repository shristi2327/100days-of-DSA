#include <stdio.h>
#include <string.h>

int main() {
    char s[100005];
    if (scanf("%s", s) != 1) return 0;
    
    int count[256] = {0};
    int len = strlen(s);
    char res = -1;
    
    for (int i = 0; i < len; i++) {
        count[(unsigned char)s[i]]++;
        if (count[(unsigned char)s[i]] == 2) {
            res = s[i];
            break;
        }
    }
    
    if (res != -1) {
        printf("%c\n", res);
    } else {
        printf("-1\n");
    }
    
    return 0;
}

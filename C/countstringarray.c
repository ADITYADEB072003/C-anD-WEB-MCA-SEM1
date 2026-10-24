/*Exactly! 👍

Basically, **while the characters of the same word are being read, `count` remains the same**.

For example:

```text
Hello World C
```

### First word: `Hello`

```text
H → count = 1
e → count = 1
l → count = 1
l → count = 1
o → count = 1
```

Then a space is found:

```text
Hello_
     ↑
   space
```

The space itself **doesn't increase `count`**.

Then `W` comes after the space:

```text
_ W
  ↑
new word
```

So:

```text
W → count = 2
o → count = 2
r → count = 2
l → count = 2
d → count = 2
```

Then another space → next word starts at `C`:

```text
C → count = 3
```

So the basic idea is:

```text
Characters of word → count stays same
Space              → count stays same
First character after space → count++
```

That's why this condition works:

```c
str[i] != ' ' && str[i - 1] == ' '
```

It detects the **first character after a space**.*/
#include <stdio.h>

int main() {
    char str[60];
    int i = 0;
    int count = 0;

    printf("Enter the string:\n");
    fgets(str, sizeof(str), stdin);
/*if (current character is not space &&
    (it is the first character OR previous character is space))
{
    count the word;
}*/
int count1=0;
    while (str[i] != '\0') {
        count1++;
        if (str[i] != ' ' && (i == 0 || str[i - 1] == ' ')) {
            count++;
        }
        
        i++;
    }

    printf("Count \n = %d", count);
     printf("Count of letter  = %d", count1);

    return 0;
}

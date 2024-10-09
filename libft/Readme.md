# Libft

`libft`는 C 언어로 구현된 표준 라이브러리 함수 모음입니다. 이 라이브러리는 앞으로 42에서 만들게될 여러 프로젝트에서 쓰이게 되며, 문자열 처리, 메모리 조작, 리스트 조작 등을 포함하고 있습니다.

## 목차

1. [ft_atoi](#1-ft_atoi)
2. [ft_putchar](#2-ft_putchar)
3. [ft_strtrim](#3-ft_strtrim)
4. [ft_strdup](#4-ft_strdup)
5. [ft_memset](#5-ft_memset)
6. [ft_bzero](#6-ft_bzero)
7. [ft_strjoin](#7-ft_strjoin)
8. [ft_itoa](#8-ft_itoa)
9. [ft_split](#9-ft_split)
10. [ft_lstnew](#10-ft_lstnew)

---

## 1. ft_atoi

**Prototype:** `int ft_atoi(const char *str);`

**설명:**  
문자열을 정수로 변환하는 함수입니다. `ft_atoi`는 문자열의 앞뒤 공백을 무시하고, 첫 번째 숫자 부분을 읽어 정수로 변환하여 반환합니다.

**사용 예시:**

```c
#include "libft.h"

int main()
{
    char *str = "   -42";
    int num = ft_atoi(str);
    printf("%d\n", num);  // 출력: -42
    return 0;
}
```

## 2. ft_putchar

**Prototype:** `void ft_putchar(char c);`

**설명:**  
단일 문자를 출력하는 함수입니다. 주어진 문자를 표준 출력으로 출력합니다.

**사용 예시:**

```c
#include "libft.h"

int main()
{
    ft_putchar('A');  // 출력: A
    return 0;
}
```

## 3. ft_strtrim

**Prototype:** `char *ft_strtrim(char const *s1, char const *set);`

**설명:**  
주어진 문자열 `s1`의 앞뒤에서 특정 문자 집합 `set`에 해당하는 문자를 제거한 새로운 문자열을 반환합니다. `set`에 포함된 모든 문자는 제거되며, 주로 문자열의 앞뒤 공백이나 특정 문자를 제거할 때 유용합니다. 반환된 문자열은 동적 메모리로 할당되므로 사용 후 반드시 메모리를 해제해야 합니다.

**사용 예시:**

```c
#include "libft.h"

int main()
{
    char *str = ft_strtrim("   Hello, World!   ", " ");
    printf("%s\n", str);  // 출력: "Hello, World!"
    free(str);
    return 0;
}
```

## 4. ft_strdup

**Prototype:** `char *ft_strdup(const char *s1);`

**설명:**  
주어진 문자열 `s1`을 복제하여 새로 할당된 메모리 공간에 저장하고, 그 주소를 반환합니다. 원본 문자열과 동일한 내용을 가지는 새로운 문자열을 생성할 때 유용합니다. 이 함수는 `malloc`을 사용하여 메모리를 할당하므로, 반환된 문자열을 사용한 후에는 `free` 함수를 통해 메모리를 해제해야 합니다.

**사용 예시:**

```c
#include "libft.h"

int main()
{
    char *original = "42Seoul";
    char *duplicate = ft_strdup(original);
    printf("Original: %s\nDuplicate: %s\n", original, duplicate);  // 출력: Original: 42Seoul, Duplicate: 42Seoul
    free(duplicate);
    return 0;
}
```

## 5. ft_memset

**Prototype:** `void *ft_memset(void *b, int c, size_t len);`

**설명:**  
`ft_memset` 함수는 메모리의 특정 부분을 지정된 값 `c`로 채우는 함수입니다. 주어진 메모리 블록 `b`의 첫 번째 바이트부터 `len` 바이트까지 `c`로 설정하며, `b`의 시작 주소를 반환합니다. 주로 메모리를 초기화하거나 특정 값으로 빠르게 설정할 때 사용됩니다.

**사용 예시:**

```c
#include "libft.h"

int main()
{
    char buffer[10];
    ft_memset(buffer, '*', 9);
    buffer[9] = '\0';  // 마지막에 NULL 문자를 추가하여 문자열을 종료합니다.
    printf("%s\n", buffer);  // 출력: *********
    return 0;
}
```

## 6. ft_bzero

**Prototype:** `void ft_bzero(void *s, size_t n);`

**설명:**  
`ft_bzero` 함수는 메모리의 특정 부분을 0으로 설정하는 함수입니다. `s`로 지정된 메모리 영역의 처음 `n` 바이트를 0으로 채우며, 주로 배열이나 메모리 블록을 초기화할 때 사용됩니다.

**사용 예시:**

```c
#include "libft.h"

int main()
{
    char buffer[10];
    ft_bzero(buffer, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", buffer[i]);  // 출력: 0 0 0 0 0 0 0 0 0 0 (모든 값이 0으로 설정됨)
    }
    return 0;
}
```

## 7. ft_strjoin

**Prototype:** `char *ft_strjoin(char const *s1, char const *s2);`

**설명:**  
`ft_strjoin` 함수는 두 문자열 `s1`과 `s2`를 이어붙여 새로운 문자열을 생성하고, 그 주소를 반환합니다. 함수가 반환하는 문자열은 동적 메모리로 할당되므로, 사용 후에는 `free` 함수를 사용하여 메모리를 해제해야 합니다.

**사용 예시:**

````c
#include "libft.h"

int main()
{
    char *s1 = "Hello, ";
    char *s2 = "World!";
    char *result = ft_strjoin(s1, s2);
    printf("%s\n", result);  // 출력: Hello, World!
    free(result);
    return 0;
}

## 8. ft_itoa

**Prototype:** `char *ft_itoa(int n);`

**설명:**
`ft_itoa` 함수는 정수 `n`을 문자열로 변환하여 반환합니다. 함수가 반환하는 문자열은 동적 메모리로 할당되며, 사용 후 `free`로 메모리를 해제해야 합니다. 양수, 음수, 0을 모두 문자열로 변환할 수 있습니다.

**사용 예시:**
```c
#include "libft.h"

int main()
{
    int num = -1234;
    char *str = ft_itoa(num);
    printf("Integer: %d, String: %s\n", num, str);  // 출력: Integer: -1234, String: -1234
    free(str);
    return 0;
}


## 9. ft_split

**Prototype:** `char **ft_split(char const *s, char c);`

**설명:**
`ft_split` 함수는 문자열 `s`를 주어진 구분자 `c`를 기준으로 나누어, 각각의 문자열 조각들을 포함하는 문자열 배열을 반환합니다. 반환된 배열의 마지막 요소는 NULL로 종료되며, 각 문자열 조각은 동적 메모리로 할당됩니다. 따라서 반환된 배열과 그 내부의 문자열들을 사용한 후에는 메모리를 해제해야 합니다.

**사용 예시:**
```c
#include "libft.h"

int main()
{
    char **words = ft_split("42Seoul is awesome", ' ');
    for (int i = 0; words[i] != NULL; i++)
    {
        printf("%s\n", words[i]);  // 출력: "42Seoul", "is", "awesome"
        free(words[i]);
    }
    free(words);
    return 0;
}
````

## 10. ft_lstnew

**Prototype:** `t_list *ft_lstnew(void *content);`

**설명:**  
`ft_lstnew` 함수는 주어진 `content`를 담고 있는 새로운 리스트 노드를 생성하여 반환합니다. 새로운 노드의 `next` 포인터는 NULL로 초기화되며, 주로 연결 리스트의 첫 번째 노드를 생성할 때 사용됩니다.

**사용 예시:**

```c
#include "libft.h"

int main()
{
    t_list *node = ft_lstnew("42Seoul");
    printf("Content: %s\n", (char *)node->content);  // 출력: Content: 42Seoul
    free(node);
    return 0;
}
```

# Quiz 1

## Questions 


1. **Implement a function `my_strncpy()`**
- **Question:** Write/Implementation a function definition for a function `my_strncpy()` with the following header:

```c
char *my_strncpy(char *destination, const char *source, int n);
```
- This function copies no more than `n` characters from the string pointed to by `source` to the buffer pointed to by `destination`. If the length of the C string in `source` is less than `n`, then the destination is padded with null characters until `n` characters have been copied to it. The function returns `destination`. Note: You must use array notation in your definition.

**Answer:**

```c
char *my_strncpy(char *destination, const char *source, int n) {
    int i;
    for (i = 0; i < n && source[i] != '\0'; i++) {
        destination[i] = source[i];
    }
    for ( ; i < n; i++) {
        destination[i] = '\0';
    }
    return destination;
}
```
---

2. **Implement a function `my_strncat()`**
- **Question:** Write/Implementation a function definition for a function `my_strncaty()` with the following header:
```c
char *my_strncat(char *destination, const char *source, int n);
```
- This function appends no more than n characters from the string pointed to by source to the end of the string pointed to by destination. The null character is appended to the end of the result. If the length of the C string in source is less than n, then only the content up to the terminating null character is copied. The destination pointer is returned. Note: You must use pointer arithmetic and notation in your definition.

**Answer:**
```c
char *my_strncat(char *destination, const char *source, int n) {
    char *dest = destination;
    while (*dest) {
        dest++;
    }
    while (n-- && (*dest++ = *source++));
    if (n < 0) {
        *dest = '\0';
    }
    return destination;
}
```

---
3. **Implement a function `strlen_recursive()`**
- **Question:** Write a function `strlen_recursive()` which accepts a pointer to a string and recursively counts the number of characters in the provided string excluding the null character. This function should return the number of characters in the string.

**Answer:**
```c
int strlen_recursive(const char *str) {
    if (*str == '\0') {
        return 0;
    } else {
        return 1 + strlen_recursive(str + 1);
    }
}
```

---


<p align= "center">
  <a href="https://github.com/MarkShinozaki/CPTS122-DataStructures/tree/Quizzes/Quiz%202">Quiz 2</a>
</p>





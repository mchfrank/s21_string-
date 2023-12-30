#include <stdio.h>
#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
    int len1 = s21_strlen(str1);
    int len2 = s21_strlen(str2);
    int flag = 0;
    int flag2 = 0;
    int count = 0;

    for (int i = 0; i < len1 && flag == 0; i++) {
        for (int j = 0; j < len2 && flag == 0; j++) {
            if (str1[i] == str2[j]) {
                flag = 1;
                flag2 = 1;
            }
        }
        if (flag == 1) {
            count = i;
        }
    }
    if (flag2 == 0) {
        count = len1;
    }
    return count;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
    int a = s21_strlen(str1);
    int b = s21_strlen(str2);
    int count = 0;
    int flag = 0;
    int flag2 = 0;

    for (int i = 0; i < a && flag2 == 0; i++) {
        for (int j = 0; j < b && flag2 == 0; j++) {
            if (str1[i] == str2[j]) {
            flag = 1;
            flag2 = 1;
            } else {
                continue;}
        }
        if (flag == 1) {
                count++;
                flag2 = 0;
            } else {
                flag2 = 1;
            }
        flag = 0;
    }

    return count; }

char *s21_strpbrk(const char *str1, const char *str2) {
    int a = s21_strlen(str1);
    int b = s21_strlen(str2);
    char *result = s21_NULL;
    int flag = 0;

    for (int i = 0; i < a && flag == 0; i++) {
        for (int j = 0; j < b && flag == 0; j++) {
            if (str1[i] == str2[j]) {
                flag = 1;
                result = (char*)str1 + i;
            }
        }
    }

    return result;
}

void *s21_memchr(const void *arr, int c, s21_size_t n) {
    char *src = (char*) arr;
    char *result = s21_NULL;
    int k = 0;
    for (s21_size_t i = 0; i < n && k == 0; i++) {
        if (src[i] == c) {
            result = &src[i];
            k = 1;
        }
    }
    return result;
}

s21_size_t s21_strlen(const char *str) {
    s21_size_t n;
    for (n = 0; *(str + n) != '\0'; n++) {}
    return n;
}

int s21_memcmp(const void *arr1, const void *arr2, s21_size_t n) {
    char *src = (char*) arr1;
    char *dst = (char*) arr2;
    int res = 0;
    for (s21_size_t i = 0; i < n; i++) {
        if (src[i] != dst[i]) {
            res = src[i] - dst[i];
            break;
        }
        if (src[i] == '\0' || dst[i] == '\0') {
            res = src[i] - dst[i];
            break;
        }
    }
    return res;
}

void *s21_memcpy(void *destination, const void *source, size_t n) {
    char *src = (char*) source;
    char *dst = (char*) destination;
    for (size_t i = 0; i < n; i++) {
        dst[i] = src[i];
        if (src[i] == '\0') {
            break;
        }
    }
    return dst;
}

void *s21_memset(void *destination, int c, s21_size_t n) {
    char *res = s21_NULL;
    char *des = (char*)destination;
    char sym = c;
    for (s21_size_t i = 0; i < n; i++) {
        des[i] = sym;
    }
    res = des;
    return res;
}

char *s21_strcat(char *dest, const char *src) {
    s21_size_t n = s21_strlen(dest);
    s21_size_t m = s21_strlen(src);
    for (s21_size_t i = 0; i < m; i++)
        dest[n+i] = src[i];
    return dest;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
    s21_size_t ln = s21_strlen(dest);
    s21_size_t m = s21_strlen(src);
    if (m < n)
        n = m;
    for (s21_size_t i = 0; i < n; i++)
        dest[ln+i] = src[i];
    return dest;
}

int s21_strcmp(const char *str1, const char *str2) {
int chek = 0;
    int n;
    if (s21_strlen(str1) <= s21_strlen(str2))
        n = s21_strlen(str1);
    else
        n = s21_strlen(str2);
    for (int i = 0; i < n && chek == 0; i++) {
        if (str1[i] != str2[i])
            chek = str1[i] - str2[i];
        }
    if (chek == 0 && s21_strlen(str1) < s21_strlen(str2))
        chek = chek - str2[n];
    else if (chek == 0 && s21_strlen(str1) > s21_strlen(str2))
        chek = str1[n];
    return chek;
}

int s21_strncmp(const char* str1, const char* str2, s21_size_t n) {
  s21_size_t i;
  for (i = 0; i < n - 1; i++)
    if (str1[i] != str2[i]) break;
  return str1[i] - str2[i];
}

char *s21_strcpy(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
    for (s21_size_t i = 0; i != n; i++) {
        dest[i] = src[i];
    }
    return dest;
}

char* s21_strrchr(const char* str, int number) {
  int lenStr = s21_strlen(str) + 1;
  char* symbol = s21_NULL;

  for (int i = 0; i < lenStr; i++) {
    if (*(str + i) == number) symbol = ((char*)str + i);
  }
  return symbol;
}

char* s21_strstr(const char* str1, const char* str2) {
  int lenStr1 = s21_strlen(str1);
  int lenStr2 = s21_strlen(str2);
  char* symbol = s21_NULL;

  if (lenStr2 != 0) {
    int identicalSymbols = 0;
    for (int i = 0; i < lenStr1; i++) {
      if (identicalSymbols == lenStr2) break;

      if (*(str1 + i) == *(str2 + identicalSymbols)) {
        if (identicalSymbols == 0) symbol = ((char*)str1 + i);
        if (identicalSymbols < lenStr2) identicalSymbols++;
      } else {
        identicalSymbols = 0;
      }
    }

    if (identicalSymbols != lenStr2) symbol = s21_NULL;
  } else {
    symbol = (char*)str1;
  }

  return symbol;
}

char* s21_strchr(const char* str, int number) {
  int lenStr = s21_strlen(str) + 1;
  int iter = 0;
  char* symbol = s21_NULL;

  while (1) {
    if (iter > lenStr) break;
    if (*(str + iter) == number) {
      symbol = (char*)str + iter;
      break;
    }
    iter++;
  }
  return symbol;
}

void* s21_memmove(void* dest, const void* src, s21_size_t n) {
  char r[1000];
  for (int i = 0; i < (int)n; ++i) r[i] = *((char*)src + i);
  for (int i = 0; i < (int)n; ++i) *((char*)dest + i) = r[i];

  return (char*)dest;
}

void s21_reverse(char s[]) {
    int i, j;
    char c[2];
    for (i = 0, j = s21_strlen(s)-1; i < j; i++, j--) {
        c[1] = s[i];
        s[i] = s[j];
        s[j] = c[1];
    }
}

void s21_itoa(int n, char s[]) {
    int i, sign;
    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
     if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    s21_reverse(s);
}

char *s21_strerror(int errnum) {
    static char res[100] = {0};
    ARRAY;
    int flag = 0;
    for (int i = 0; i < ERR_MAX; i++) {
        if (errnum == i) {
            s21_strcpy(res, errlist[i]);
            flag = -1;
        }
    }
    if (flag == 0) {
        char str[100] = ERROR;
        char errnum_str[100];
        s21_itoa(errnum, errnum_str);
        char *tmp = s21_strcat(str, errnum_str);
        s21_strcpy(res, tmp);
    }
    return res;
}

char *s21_strtok(char *str, const char *delim) {
    int chek = 0;
    s21_size_t n = 0;
    static char *token = s21_NULL;
    char *result = s21_NULL;
    s21_size_t size_len = s21_strlen(delim);
    if (str != s21_NULL) {
        n = s21_strlen(str);
        token = str;
    } else  if (token != s21_NULL) {
        n = s21_strlen(token);
    }
        chek = 0;
        int sme = 0;
        for (s21_size_t i = 0; i < n && chek == 0; i++) {
            for (s21_size_t f = 0; f < size_len && chek == 0; f++) {
                if (token[i] == delim[f]) {
                    token[i] = '\0';
                     if (i == 0 || token[i-1] == '\0') {
                        sme = sme + 1;
                        continue;
                    }
                    token += sme;
                    chek = 1;
                    result = token;
                    token += i - sme;
                    token++;
                } else if (token[i+1] == '\0') {
                    token += sme;
                    chek = 1;
                    result = token;
                    token = token + i + 1;
                }
            }
        }
    return result;
}

int s21_sprintf(char *str, const char *format, ...) {
    va_list args;
    va_start(args, format);
    struct token tok;
    const char *start = str;
    char *f = (char *)format;
    while (*f != '\0') {
        if (*f != '%') {
            *str = *f;
            str++;
            f++;
        } else {
            input_flags(&tok);
            f++;
            while (*f == '-' || *f == '+' || *f == ' ' || *f == '#' ||
                    *f == '0') {
                if (*f == '-')
                    tok.flag_minus = 1;
                else if (*f == '+')
                    tok.flag_plus = 1;
                else if (*f == ' ')
                    tok.flag_space = 1;
                else if (*f == '#')
                    tok.flag_grid = 1;
                else if (*f == '0')
                    tok.flag_zero = 1;
                f++;
            }
            while ((*f >= '0' && *f <= '9') || *f == '*') {
                if (*f >= '0' && *f <= '9')
                    tok.wight = tok.wight * 10 + (*f - '0');
                else if (*f == '*')
                    tok.wight = va_arg(args, int);
                f++;
            }
            if (*f == '.') {
                tok.accur = 0;
                f++;
                while ((*f >= '0' && *f <= '9') || *f == '*') {
                    if (*f >= '0' && *f <= '9')
                        tok.accur = tok.accur * 10 + (*f - '0');
                    else if (*f == '*')
                        tok.accur = va_arg(args, int);
                    f++;
                }
            }
            if (*f == 'h' || *f == 'l' || *f == 'L') tok.lenght = *f++;
            if (*f == 'c' || *f == 'd' || *f == 'i' || *f == 'e' || *f == 'E' ||
                *f == 'f' || *f == 'g' || *f == 'G' || *f == 'o' || *f == 's' ||
                *f == 'u' || *f == 'x' || *f == 'X' || *f == 'p' || *f == 'n') {
                tok.spec = *f++;
            } else if (*f == '%') {
                *str = *f;
                str++;
                f++;
            }
            un_flags(&tok);
            if (tok.spec == 'c') {
                if (tok.lenght == 'l')
                    str = sprintf_spec_c(&tok, str, (int)va_arg(args, wchar_t));
                else
                    str = sprintf_spec_c(&tok, str, va_arg(args, int));
            } else if (tok.spec == 'd' || tok.spec == 'i') {
                if (tok.lenght == 'l')
                    str = ld_sprintf(&tok, str, va_arg(args, long int));
                else
                    str = sprintf_spec_d(&tok, str, va_arg(args, int));
            } else if (tok.spec == 's') {
                if (tok.lenght == 'l') {
                    wchar_t *y = va_arg(args, wchar_t *);
                    str = ls_sprintf(&tok, str, y);
                } else {
                    char *x = va_arg(args, char *);
                    str = sprintf_spec_s(&tok, str, x);
                }
            } else if (tok.spec == 'n') {
                sprintf_spec_n(str, start, va_arg(args, int *));
            } else if (tok.spec == 'o' || tok.spec == 'x' || tok.spec == 'X') {
                if (tok.lenght == 'l')
                    str = loxX_sprintf(&tok, str, va_arg(args, long int));
                else
                    str = oxX_sprintf(&tok, str, va_arg(args, int));
            } else if (tok.spec == 'u') {
                str = sprintf_spec_u(&tok, str, va_arg(args, s21_size_t));
            } else if (tok.spec == 'f') {
                str = sprintf_spec_f(&tok, str, va_arg(args, double));
            } else if (tok.spec == 'p') {
                str = sprintf_spec_p(str, va_arg(args, void *));
            }
        }
    }
    int result = str - start;
    va_end(args);
    return result;
}

void utoa(s21_size_t n, char *str) {
    int i = 0;
    if (n == 0) {
        str[i] = n + '0';
        i++;
    } else {
        while (n > 0) {
            str[i] = n % 10 + '0';
            i++;
            n /= 10;
        }
    }
    str[i] = '\0';
    reverse(str);
}

void ltoa(long int n, char *str, struct token *tok) {
    int i = 0;
    if (n < 0) {
        n = n * -1;
    }
    while (n > 0) {
        str[i++] = n % 10 + '0';
        n /= 10;
    }
    if (tok->negative == 1) {
        str[i++] = '-';
    }
    str[i] = '\0';
    reverse(str);
}

void flag_grid(char *c, struct token *tok, int i) {
    c[i++] = '0';
    if (tok->spec == 'x')
        c[i++] = 'x';
    else if (tok->spec == 'X')
        c[i++] = 'X';
}

void flag_minus(char *c, struct token *tok) {
    char temp[1024] = {};
    int i = 0;
    if (tok->accur > -1) {
        if (tok->flag_plus && c[0] != '-' && !tok->minus) temp[i++] = '+';
        tok->flag_plus = 0;
    }
    if (tok->flag_grid && !tok->flag_zero &&
        (tok->spec == 'o' || tok->spec == 'x' || tok->spec == 'X')) {
        int x = i;
        flag_grid(temp, tok, x);
    }
    if (tok->minus) {
        temp[i++] = '-';
        s21_strcat(temp, c);
    } else if (tok->flag_plus) {
        tok->flag_space = 0;
        temp[i++] = '+';
        s21_strcat(temp, c);
    } else if (tok->flag_space) {
        temp[i++] = ' ';
        s21_strcat(temp, c);
    } else {
        s21_strcat(temp, c);
    }
    int len = s21_strlen(temp);
    if (tok->wight < len) tok->wight = len;
    while (len < tok->wight) temp[len++] = ' ';
    temp[len] = '\0';
    s21_strcpy(c, temp);
}

void flag_plus_spase(char *c, struct token *tok) {
    char buf[1024] = {};
    int i = 0;
    if (tok->flag_grid && (tok->spec == 'o' || tok->spec == 'x' || tok->spec == 'X'))
        flag_grid(buf, tok, i);
    i = 0;
    if (tok->flag_plus) {
        tok->flag_space = 0;
        buf[i++] = '+';
    }
    if (tok->flag_space) buf[i++] = ' ';
    s21_strcat(buf, c);
    i = 0;
    while (buf[i]) *c++ = buf[i++];
    *c = '\0';
}

void accur_s(char *c, struct token *tok) {
    char buf[1024] = {};
    int len = s21_strlen(c);
    int i = 0;
    if (tok->accur < len) {
        len = tok->accur;
    }
    while (len > 0) {
        buf[i++] = *c++;
        len--;
    }
    s21_strcpy(c, buf);
    *c = '\0';
}

void accur_d(char *str, struct token *tok) {
    tok->accur_spec_d = 1;
    tok->flag_zero = 0;
    char temp_in[1024] = {};
    char *c = temp_in;
    s21_strcpy(c, str);
    int len = s21_strlen(temp_in);
    int min = 0;
    char temp[1024] = {};
    char *b = temp;
    if (c[0] == '-') {
        min = 1;
        c[0] = '0';
    }
    if (tok->accur > len) {
        int i = 0;
        if (tok->flag_grid && tok->spec == 'o') len++;
        if (min && tok->accur >= len + 1) {
            b[i++] = '-';
        }
        while (len != tok->accur) {
            b[i++] = '0';
            len++;
        }
        b[i] = '\0';
        s21_strcat(b, c);
        s21_strcpy(str, b);
    }
}

void wight(char *c, struct token *tok) {
    char buf[1024] = {};
    int len = s21_strlen(c);
    int i = 0;
    int W = tok->wight;
    if ((tok->minus || tok->flag_plus) && tok->wight <= len) {
        if (tok->minus)
            buf[i++] = '-';
        else if (tok->flag_plus)
            buf[i++] = '+';
    }
    if (tok->flag_space && !tok->minus && !tok->flag_plus) {
        buf[i++] = ' ';
        W--;
    }
    if (tok->minus && tok->flag_zero) {
        buf[i++] = '-';
        W--;
    }
    if (tok->flag_plus && !tok->minus && tok->flag_zero) {
        buf[i++] = '+';
        W--;
    }
    while (W-- > len) {
        if (tok->flag_zero && tok->spec != 'c' && tok->spec != 's' &&
            tok->spec != 'n' && tok->spec != 'p')
            buf[i++] = '0';
        else
            buf[i++] = ' ';
    }
    if (tok->minus && !tok->flag_zero) buf[i - 1] = '-';
    if (tok->flag_plus && !tok->minus && !tok->flag_zero) {
        if (tok->accur > -1 && c[0] != '-')
            buf[i - 1] = '-';
        else
            buf[i - 1] = '+';
    }
    s21_strcat(buf, c);
    i = 0;
    while (buf[i]) *c++ = buf[i++];
    *c = '\0';
}

void wight_oxX(char *c, struct token *tok) {
    char buf[1024] = {};
    int len = s21_strlen(c);
    int i = 0;
    int W = tok->wight;
    if (tok->flag_grid) {
        if (tok->spec == 'o') W--;
        if (tok->spec == 'x' || (tok->spec == 'X')) W -= 2;
    }
    if (!tok->flag_zero) {
        while (W-- > len) buf[i++] = ' ';
    }
    if (tok->flag_grid) {
        flag_grid(buf, tok, i);
        if (tok->spec == 'o')
            i += 1;
        else if (tok->spec == 'x' || tok->spec == 'X')
            i += 2;
    }
    if (tok->flag_zero) {
        while (W-- > len) buf[i++] = '0';
    }
    s21_strcat(buf, c);
    i = 0;
    while (buf[i]) *c++ = buf[i++];
}

void lenght(int x, char *str, struct token *tok) {
    if (tok->lenght == 'h') x = (short)x;
    itoa((int)x, str);
}

void format(struct token *tok, char *str) {
    if (tok->spec == 's') {
        if (tok->accur > 0) accur_s(str, tok);
        if (tok->accur == 0) *str = '\0';
    } else if (tok->accur > 0) {
        accur_d(str, tok);
    }
    if (tok->wight > 0 && !tok->flag_minus &&
        (tok->spec == 'o' || tok->spec == 'x' || tok->spec == 'X'))
        wight_oxX(str, tok);
    else if (tok->wight > 0 && !tok->flag_minus)
        wight(str, tok);
    else if (tok->flag_minus && tok->wight > 0)
        flag_minus(str, tok);
    if (!tok->wight && tok->negative == 0 && (tok->flag_plus || tok->flag_space))
        flag_plus_spase(str, tok);
    if (!tok->wight && tok->flag_grid &&
        (tok->spec == 'o' || tok->spec == 'x' || tok->spec == 'X'))
        flag_plus_spase(str, tok);
}

void format_f(struct token *tok, char *str, int num) {
    if (tok->wight > 0 && !tok->flag_minus)
        wight(str, tok);
    else if (tok->flag_minus && tok->wight > 0)
        flag_minus(str, tok);
    if (!tok->wight && num >= 0 && (tok->flag_plus || tok->flag_space))
        flag_plus_spase(str, tok);
}

char *sprintf_spec_d(struct token *tok, char *str, int num) {
    char arr[1024];
    char *c = arr;
    if (num < 0 && tok->wight && tok->accur == -1) {
        tok->minus = 1;
        num *= -1;
    }
    if (tok->lenght == 'h')
        lenght(num, arr, tok);
    else
        itoa(num, arr);
    if (tok->accur == 0 && num == 0) *c = '\0';
    format(tok, arr);
    while (*c) *str++ = *c++;
    *str = '\0';
    return str;
}

char *ld_sprintf(struct token *tok, char *str, long int num) {
    char arr[1024];
    char *c = arr;
    if (num == LLONG_MIN) {
        c = "-9223372036854775808";
    } else {
        if (num < 0) tok->negative = 1;
        ltoa(num, arr, tok);
    }
    format(tok, arr);
    while (*c) *str++ = *c++;
    *str = '\0';
    return str;
}

char *oxX_sprintf(struct token *tok, char *str, int num) {
    char arr[1024] = {};
    char *c = arr;
    if (num == 0) {
        int i = 0;
        arr[i++] = num + '0';
        tok->flag_grid = 0;
    } else if (tok->spec == 'o') {
        convert(num, 8, tok, c);
        if (num < 0 && tok->lenght == 'h') {
            c += 5;
            *c = '1';
        }
    } else if (tok->spec == 'x' || tok->spec == 'X') {
        convert(num, 16, tok, c);
        if (num < 0 && tok->lenght == 'h') c += 4;
    }
    if (tok->accur == 0 && num == 0) *c = '\0';
    format(tok, arr);
    while (*c) *str++ = *c++;
    *str = '\0';
    return str;
}

void convert(unsigned int num, int x, struct token *tok, char *str) {
    const char arr[] = "0123456789abcdef";
    const char arr1[] = "0123456789ABCDEF";
    int i = 0;
    char buf[1024] = {};
    if (tok->spec == 'x' || tok->spec == 'o') {
        while (num != 0 && x != 0) {
            buf[i++] = arr[num % x];
            num /= x;
        }
    }
    if (tok->spec == 'X') {
        while (num != 0 && x != 0) {
            buf[i++] = arr1[num % x];
            num /= x;
        }
    }
    buf[i] = '\0';
    reverse(buf);
    s21_strcat(str, buf);
}

char *loxX_sprintf(struct token *tok, char *str, long int num) {
    char arr[1024] = {};
    char *c = arr;
    if (tok->spec == 'o' && num != 0) {
        convert_f_long(num, 8, tok, c);
    } else if ((tok->spec == 'x' || tok->spec == 'X') && num != 0) {
        convert_f_long(num, 16, tok, c);
    }
    format(tok, arr);
    while (*c) *str++ = *c++;
    *str = '\0';
    return str;
}

void convert_f_long(unsigned long int num, int x, struct token *tok, char *str) {
    const char arr[] = "0123456789abcdef";
    const char arr1[] = "0123456789ABCDEF";
    int i = 0;
    char buf[1024] = {};
    if (tok->spec == 'x' || tok->spec == 'o') {
        while (num != 0 && x != 0) {
            buf[i++] = arr[num % x];
            num /= x;
        }
    }
    if (tok->spec == 'X') {
        while (num != 0 && x != 0) {
            buf[i++] = arr1[num % x];
            num /= x;
        }
    }
    buf[i] = '\0';
    reverse(buf);
    s21_strcat(str, buf);
}

char *sprintf_spec_c(struct token *tok, char *str, int C) {
    char arr[1024] = {};
    char *c = arr;
    *c = (char)C;
    if (tok->wight > 0 && !tok->flag_minus)
        wight(c, tok);
    else if (tok->flag_minus && tok->wight > 0)
        flag_minus(c, tok);
    while (*c) *str++ = *c++;
    *str = '\0';
    return str;
}

char *sprintf_spec_s(struct token *tok, char *str, char *C) {
    char arr[1024] = {};
    int i = 0;
    while (*C) arr[i++] = *C++;
    char *c = arr;
    format(tok, c);
    while (*c) *str++ = *c++;
    *str = '\0';
    return str;
}

char *ls_sprintf(struct token *tok, char *str, wchar_t *C) {
    char arr[1024] = {};
    char temp[1024] = {};
    char *c = temp;
    int i = 0;
    while (C[i] != '\0') {
        arr[i] = (char)C[i];
        i++;
    }
    int len = s21_strlen(arr);
    i = 0;
    while (len) {
        c[i] = arr[i];
        i++;
        len--;
    }
    format(tok, c);
    while (*c) *str++ = *c++;
    *str = '\0';
    return str;
}

char *sprintf_spec_u(struct token *tok, char *str, s21_size_t num) {
    if (tok->accur > tok->wight) {
        tok->wight = tok->accur;
        tok->flag_zero = 1;
    }
    char arr[1024];
    char *c = arr;
    utoa(num, arr);
    format(tok, arr);
    while (*c) *str++ = *c++;
    *str = '\0';
    return str;
}

char *p_convert(long x, int hex) {
    long num = x;
    const char arr[] = "0123456789abcdef";
    static char buffer[1024];
    char *ptr = buffer;
    while (num != 0 && hex != 0) {
        *--ptr = arr[num % hex];
        num /= hex;
    }
    return (ptr);
}

void *sprintf_spec_p(char *str, void *ptr) {
    static char string_pointer[1024] = "0x";
    char *p = string_pointer;
    long x = (long)ptr;
    char *buf = p_convert(x, 16);
    s21_strcat(string_pointer, buf);
    while (*p) *str++ = *p++;
    *str = '\0';
    return str;
}

void sprintf_spec_n(const char *str, const char *start, int *path) {
    *path = str - start;
}

void input_flags(struct token *tok) {
    tok->flag_plus = 0;
    tok->flag_minus = 0;
    tok->flag_space = 0;
    tok->flag_grid = 0;
    tok->flag_zero = 0;
    tok->wight = 0;
    tok->accur = -1;
    tok->accur_spec_d = 0;
    tok->minus = 0;
    tok->lenght = '0';
    tok->spec = '0';
    tok->negative = 0;
}

void un_flags(struct token *tok) {
    if (tok->spec == 'c') {
        tok->flag_plus = tok->flag_space = tok->flag_grid = tok->flag_zero = 0;
        tok->accur = -1;
        if (tok->lenght == 'h' || tok->lenght == 'L') tok->lenght = '0';
    } else if (tok->spec == 'd' || tok->spec == 'i') {
        tok->flag_grid = 0;
        if (tok->lenght == 'L') tok->lenght = '0';
        if (tok->flag_minus && tok->flag_zero) tok->flag_minus = tok->flag_zero = 0;
        if (tok->flag_space && tok->flag_plus) tok->flag_space = 0;
    } else if (tok->spec == 's') {
        tok->flag_plus = tok->flag_space = tok->flag_grid = tok->flag_zero = 0;
        if (tok->lenght == 'h' || tok->lenght == 'L') tok->lenght = '0';
    } else if (tok->spec == 'o' || tok->spec == 'x' || tok->spec == 'X') {
        tok->flag_plus = tok->flag_space = 0;
        if (tok->flag_minus && tok->flag_zero) tok->flag_minus = tok->flag_zero = 0;
        if (tok->lenght == 'L') tok->lenght = '0';
    } else if (tok->spec == 'u') {
        tok->flag_plus = tok->flag_grid = tok->flag_space = 0;
        if (tok->lenght == 'L') tok->lenght = '0';
    } else if (tok->spec == 'p') {
        tok->flag_plus = tok->flag_grid = tok->flag_space = tok->flag_zero = 0;
    }
}

char *sprintf_spec_f(struct token *tok, char *str, long double num) {
    if (tok->accur == -1) tok->accur = 6;
    if (num < 0 && tok->wight) {
        tok->minus = 1;
        num *= -1;
    }
    char arr[1024] = {};
    char *c = arr;
    int celoe = 0;
    celoe = !tok->accur ? (int)round(num) : (int)num;
    itoa(celoe, c);
    if (tok->flag_grid || tok->accur) s21_strcat(c, ".");
    if (tok->accur) {
        long double ostatok = num - (int)num;
        int acc = tok->accur;
        while (acc--) ostatok *= 10;
        char fl[1024] = {};
        char *f = fl;
        itoa(abs((int)round(ostatok)), f);
        int len = s21_strlen(f);
        while (len++ < tok->accur) s21_strcat(c, "0");
        s21_strcat(c, f);
    }
    format_f(tok, c, num);
    while (*c) {
        *str = *c;
        str++;
        c++;
    }
    *str = '\0';
    s21_strcat(str, c);
    return str;
}

void itoa(int n, char *str) {
    int i = 0;
    long int x = n;
    if (n < 0) x *= -1;
    if (!x) str[i++] = '0';
    while (x > 0) {
        str[i] = x % 10 + '0';
        i++;
        x /= 10;
    }
    if (n < 0) {
        str[i] = '-';
        i++;
    }
    str[i] = '\0';
    reverse(str);
}

void reverse(char *str) {
    int k, j;
    for (k = 0, j = s21_strlen(str) - 1; k < j; k++, j--) {
        char buf = str[k];
        str[k] = str[j];
        str[j] = buf;
    }
}


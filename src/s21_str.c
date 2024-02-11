#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *p = dest + s21_strlen(dest);

  for (s21_size_t i = 0; i < n; i++) {
    p[i] = src[i];
    if (src[i] == '\0') break;
    if (i == n - 1) p[n] = '\0';
  }

  return dest;
}

char *s21_strchr(const char *str, int c) {
  char *result = S21_NULL;
  char value = (char)c;

  for (s21_size_t i = 0; i <= s21_strlen(str); i++) {  // with '\0'
    if (str[i] == value) {
      result = (char *)(str + i);
      break;
    }
  }

  return result;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t length = 0;

  for (s21_size_t i = 0; i < s21_strlen(str1); i++) {
    if (s21_strchr(str2, (int)str1[i]) != S21_NULL) {
      break;
    }
    length++;
  }

  return length;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t length = 0;

  while (str[length] != '\0') {
    length += 1;
  }

  return length;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = S21_NULL;

  for (s21_size_t i = 0; i < s21_strlen(str1); i++) {
    if (s21_strchr(str2, (int)str1[i]) != S21_NULL) {
      result = (char *)(str1 + i);
      break;
    }
  }

  return result;
}

char *s21_strrchr(const char *str, int c) {
  char *result = S21_NULL;
  char value = (char)c;

  for (int i = s21_strlen(str); i >= 0; i--) {  // with '\0'
    if (str[i] == value) {
      result = (char *)(str + i);
      break;
    }
  }

  return result;
}

char *s21_strstr(const char *haystack, const char *needle) {
  const char *result = S21_NULL;

  if (*needle == '\0') {
    result = haystack;  // Пустая строка всегда найдена в любой строке
  } else {
    while (*haystack != '\0') {
      const char *h = haystack;
      const char *n = needle;

      while (*n != '\0' && *h == *n) {
        ++h;
        ++n;
      }

      if (*n == '\0') {
        result = haystack;  // Найдено вхождение
        break;
      }

      ++haystack;
    }
  }

  return (char *)result;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int result = 0;

  for (s21_size_t i = 0; i < n; i++) {
    if (str1[i] != str2[i]) {
      result = (int)(str1[i] - str2[i]);
      break;
    }
  }

  return result;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *p1 = dest;
  s21_size_t len_dest = s21_strlen(p1);
  for (s21_size_t i = 0; i < n; i++) {
    p1[i] = src[i];
  }
  if (len_dest < n) {
    p1[n] = '\0';
  }
  return dest;
}

char *s21_strtok(char *str, const char *delim) {
  static char *point = S21_NULL;
  static int count = 0;
  static int flag = 0;

  if (!flag) {point = str != S21_NULL ? str : point + count;

  while (*point != '\0' && s21_strchr(delim, *point) != S21_NULL) {
    *point = '\0';
    point++;
  } 
  if (*point == '\0') {
    point = S21_NULL;
    flag = 1;
  } else {
    for (count = 0; *(point + count) != '\0'; count++) {
      if (s21_strchr(delim, *(point + count)) != S21_NULL) {
        *(point + count) = '\0';
        count++;
        break;
      }
    }
  }}
  return point;
}

char *s21_strerror(int errnum) {
#if defined(__APPLE__)
#define MAX_ERROR_CODE 107
  const char error_out_of_list[20] = "Unknown error:";
  const char *list_errors[] = {
      "Undefined error: 0",
      "Operation not permitted",
      "No such file or directory",
      "No such process",
      "Interrupted system call",
      "Input/output error",
      "Device not configured",
      "Argument list too long",
      "Exec format error",
      "Bad file descriptor",
      "No child processes",
      "Resource deadlock avoided",
      "Cannot allocate memory",
      "Permission denied",
      "Bad address",
      "Block device required",
      "Resource busy",
      "File exists",
      "Cross-device link",
      "Operation not supported by device",
      "Not a directory",
      "Is a directory",
      "Invalid argument",
      "Too many open files in system",
      "Too many open files",
      "Inappropriate ioctl for device",
      "Text file busy",
      "File too large",
      "No space left on device",
      "Illegal seek",
      "Read-only file system",
      "Too many links",
      "Broken pipe",
      "Numerical argument out of domain",
      "Result too large",
      "Resource temporarily unavailable",
      "Operation now in progress",
      "Operation already in progress",
      "Socket operation on non-socket",
      "Destination address required",
      "Message too long",
      "Protocol wrong type for socket",
      "Protocol not available",
      "Protocol not supported",
      "Socket type not supported",
      "Operation not supported",
      "Protocol family not supported",
      "Address family not supported by protocol family",
      "Address already in use",
      "Can't assign requested address",
      "Network is down",
      "Network is unreachable",
      "Network dropped connection on reset",
      "Software caused connection abort",
      "Connection reset by peer",
      "No buffer space available",
      "Socket is already connected",
      "Socket is not connected",
      "Can't send after socket shutdown",
      "Too many references: can't splice",
      "Operation timed out",
      "Connection refused",
      "Too many levels of symbolic links",
      "File name too long",
      "Host is down",
      "No route to host",
      "Directory not empty",
      "Too many processes",
      "Too many users",
      "Disc quota exceeded",
      "Stale NFS file handle",
      "Too many levels of remote in path",
      "RPC struct is bad",
      "RPC version wrong",
      "RPC prog. not avail",
      "Program version wrong",
      "Bad procedure for program",
      "No locks available",
      "Function not implemented",
      "Inappropriate file type or format",
      "Authentication error",
      "Need authenticator",
      "Device power is off",
      "Device error",
      "Value too large to be stored in data type",
      "Bad executable (or shared library)",
      "Bad CPU type in executable",
      "Shared library version mismatch",
      "Malformed Mach-o file",
      "Operation canceled",
      "Identifier removed",
      "No message of desired type",
      "Illegal byte sequence",
      "Attribute not found",
      "Bad message",
      "EMULTIHOP (Reserved)",
      "No message available on STREAM",
      "ENOLINK (Reserved)",
      "No STREAM resources",
      "Not a STREAM",
      "Protocol error",
      "STREAM ioctl timeout",
      "Operation not supported on socket",
      "Policy not found",
      "State not recoverable",
      "Previous owner died",
      "Interface output queue is full"};
#elif defined(__linux__)
#define MAX_ERROR_CODE 134
  const char error_out_of_list[20] = "Unknown error";
  const char *list_errors[] = {
      "Success",
      "Operation not permitted",
      "No such file or directory",
      "No such process",
      "Interrupted system call",
      "Input/output error",
      "No such device or address",
      "Argument list too long",
      "Exec format error",
      "Bad file descriptor",
      "No child processes",
      "Resource temporarily unavailable",
      "Cannot allocate memory",
      "Permission denied",
      "Bad address",
      "Block device required",
      "Device or resource busy",
      "File exists",
      "Invalid cross-device link",
      "No such device",
      "Not a directory",
      "Is a directory",
      "Invalid argument",
      "Too many open files in system",
      "Too many open files",
      "Inappropriate ioctl for device",
      "Text file busy",
      "File too large",
      "No space left on device",
      "Illegal seek",
      "Read-only file system",
      "Too many links",
      "Broken pipe",
      "Numerical argument out of domain",
      "Numerical result out of range",
      "Resource deadlock avoided",
      "File name too long",
      "No locks available",
      "Function not implemented",
      "Directory not empty",
      "Too many levels of symbolic links",
      "Unknown error 41",
      "No message of desired type",
      "Identifier removed",
      "Channel number out of range",
      "Level 2 not synchronized",
      "Level 3 halted",
      "Level 3 reset",
      "Link number out of range",
      "Protocol driver not attached",
      "No CSI structure available",
      "Level 2 halted",
      "Invalid exchange",
      "Invalid request descriptor",
      "Exchange full",
      "No anode",
      "Invalid request code",
      "Invalid slot",
      "Unknown error 58",
      "Bad font file format",
      "Device not a stream",
      "No data available",
      "Timer expired",
      "Out of streams resources",
      "Machine is not on the network",
      "Package not installed",
      "Object is remote",
      "Link has been severed",
      "Advertise error",
      "Srmount error",
      "Communication error on send",
      "Protocol error",
      "Multihop attempted",
      "RFS specific error",
      "Bad message",
      "Value too large for defined data type",
      "Name not unique on network",
      "File descriptor in bad state",
      "Remote address changed",
      "Can not access a needed shared library",
      "Accessing a corrupted shared library",
      ".lib section in a.out corrupted",
      "Attempting to link in too many shared libraries",
      "Cannot exec a shared library directly",
      "Invalid or incomplete multibyte or wide character",
      "Interrupted system call should be restarted",
      "Streams pipe error",
      "Too many users",
      "Socket operation on non-socket",
      "Destination address required",
      "Message too long",
      "Protocol wrong type for socket",
      "Protocol not available",
      "Protocol not supported",
      "Socket type not supported",
      "Operation not supported",
      "Protocol family not supported",
      "Address family not supported by protocol",
      "Address already in use",
      "Cannot assign requested address",
      "Network is down",
      "Network is unreachable",
      "Network dropped connection on reset",
      "Software caused connection abort",
      "Connection reset by peer",
      "No buffer space available",
      "Transport endpoint is already connected",
      "Transport endpoint is not connected",
      "Cannot send after transport endpoint shutdown",
      "Too many references: cannot splice",
      "Connection timed out",
      "Connection refused",
      "Host is down",
      "No route to host",
      "Operation already in progress",
      "Operation now in progress",
      "Stale file handle",
      "Structure needs cleaning",
      "Not a XENIX named type file",
      "No XENIX semaphores available",
      "Is a named type file",
      "Remote I/O error",
      "Disk quota exceeded",
      "No medium found",
      "Wrong medium type",
      "Operation canceled",
      "Required key not available",
      "Key has expired",
      "Key has been revoked",
      "Key was rejected by service",
      "Owner died",
      "State not recoverable",
      "Operation not possible due to RF-kill",
      "Memory page has hardware error"};
#endif
  static char result[1024] = "\0";
  if (errnum >= 0 && errnum < MAX_ERROR_CODE) {
    // char* error = (char*)list_errors[errnum];
    // s21_sprintf(result, "%s", error);
    s21_sprintf(result, "%s", list_errors[errnum]);
  } else {
    s21_sprintf(result, "%s %d", error_out_of_list, errnum);
  }
  return result;
}

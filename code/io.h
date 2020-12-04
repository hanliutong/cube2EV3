#define _INTERNAL_BUFSIZ 4096
char _bufin[_INTERNAL_BUFSIZ];

typedef struct _iobuf {
    char *_ptr;
    int _cnt;
    char *_base;
    int _flag;
    int _file;
    int _charbuf;
    int _bufsiz;
    char *_tmpfname;
}FILE;

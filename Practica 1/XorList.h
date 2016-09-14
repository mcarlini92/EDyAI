
typedef struct _XorList{
        int data;
        struct _XorList *dir;
} XorList;

#define   dlist_data(l)   (l)->data
#define   xorlist_dir(l)  (l)->dir

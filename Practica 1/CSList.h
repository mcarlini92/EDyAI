
typedef void (*VisitorFuncInt) (int data, void *extra_data);

typedef struct _CSList{
        int    data;
        struct _CList *next;
} CSList;

#define   clist_data(l)     l->data
#define   clist_next(l)     l->next

typedef void (*VisitorFuncInt) (int data, void *extra_data);

void clist_foreach(CSList *list, VisitorFuncInt visit, void *extra_data);

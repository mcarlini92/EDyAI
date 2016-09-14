
typedef struct _DList{
        int data;
        struct _DList *next;
        struct _DList *prev;
} DList;

#define   dlist_data(l)   (l)->data
#define   dlist_next(l)   (l)->next
#define   dlist_prev(l)   (l)->prev

typedef enum {
        DLIST_TRAVERSAL_ORDER_FORWARD, // Si es 0 => Recorrido hacia la derecha (dlist_next)
		DLIST_TRAVERSAL_ORDER_REWARD // Si es 1 => Recorrido hacia la izquierda (dlist_prev)
} DListTraversalOrder;

typedef void (*VisitorFuncInt) (int data, void *extra_data);

void slist_foreach(DList *list, VisitorFuncInt visit, DListTraversalOrder sentido, void *extra_data);
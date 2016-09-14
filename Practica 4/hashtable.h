#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__



typedef unsigned int (*HashFunc)(void *, unsigned int);
typedef int (*EqualsFunc) (void *, void *);

typedef struct _Hashbucket {
  void *key;
  void *data;
  struct _Hashbucket * next;
} Hashbucket;

typedef struct _Hashtable {
  Hashbucket *table;
  int nelems, size;
  HashFunc hash;
  EqualsFunc efunc;
} Hashtable;

Hashtable *hashtable_new(int, HashFunc, EqualsFunc);
void hashtable_insert(Hashtable *, void *, void *);
void *hashtable_lookup(Hashtable *, void *);
void hashtable_delete(Hashtable *, void *);
void hashtable_delete2(Hashtable *, void *);
void hashtable_destroy(Hashtable *);
Hashtable * hashtable_resize(Hashtable *);
void hashtable_print(Hashtable);

#endif /* __HASHTABLE_H__ */

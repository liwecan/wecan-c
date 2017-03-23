typedef struct Array *Array_T;

extern Array_T Array_new(void);
extern void Array_delete(Array_T array);

extern int Array_getLength(Array_T array);
extern void *Array_getData(Array_T array, int index);
extern int Array_getIndex(Array_T array, void *pData);

extern void Array_append(Array_T array, void *pData);
extern void Array_insert(Array_T array, int index, void *pData);
extern void Array_replace(Array_T array, int index, void *pData);
extern void Array_remove(Array_T array, int index);
extern void Array_sort(Array_T array);

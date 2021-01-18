/* This file was automatically generated.  Do not edit! */
#ifndef __ARRAYLIST__H_
#define __ARRAYLIST__H_

typedef struct arraylist arraylist;
void arraylist_destroy(arraylist *l);
void arraylist_splice(arraylist *l,arraylist *source,unsigned int index);
void arraylist_join(arraylist *l,arraylist *source);
arraylist *arraylist_copy(arraylist *l);
arraylist *arraylist_slice_end(arraylist *l,unsigned int index);
arraylist *arraylist_slice(arraylist *l,unsigned int index,unsigned int length);
void arraylist_clear(arraylist *l);
void *arraylist_remove(arraylist *l,unsigned int index);
void arraylist_insert(arraylist *l,unsigned int index,void *value);
/*
*  写 指定index 的值
*  返回值 :
*           >0 : 成功 
*           =0 : index > size
*/
void* arraylist_set(arraylist *l,unsigned int index,void *value);

/*
*  读 指定index 的值
*  返回值 :
*           >0 : 元素指针 
*           =0 : index > size
*/
void *arraylist_get(arraylist *l,unsigned int index);

/*
* 弹出 尾的元素,size 减小 1
* 返回值 :
*		  >0 : 元素指针
*          0 : list 为空 
*/
void *arraylist_pop(arraylist *l);
/*
*  往尾添加一个元素
*/
void arraylist_add(arraylist *l,void *item);

/*
*  返回当前 数组大小
*/
inline unsigned int arraylist_size(arraylist *l);

/*
*  扩容
*  size: 指定 新的 容量
*  返回值: 0 : 失败   
*		   1 : 成功
*/
unsigned int  arraylist_allocate(arraylist *l,unsigned int size);

/*
* 创建 arraylist
*   capacity : 指定创建的arraylist容量 , 默认值是 4 , 
*/
arraylist *arraylist_create( unsigned int capacity );
#define arraylist_iterate(l, index, item) \
	for (index = 0, item = l->body[0]; index < l->size; item = l->body[++index])
struct arraylist {
	unsigned int size; // Count of items currently in list
	unsigned int capacity; // Allocated memory size, in items
	void** body; // Pointer to allocated memory for items (of size capacity * sizeof(void*))
};
#define INTERFACE 0

#endif

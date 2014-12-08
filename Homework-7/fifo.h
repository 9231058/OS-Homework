#ifndef FIFO_H
#define FIFO_H

#include <linux/ioctl.h> /* needed for the _IOW etc stuff used later */

/*
 * Macros to help debugging
 */

#undef PDEBUG             /* undef it, just in case */
#ifdef SCULL_DEBUG
#  ifdef __KERNEL__
/* This one if debugging is on, and kernel space */
#    define PDEBUG(fmt, args...) printk( KERN_DEBUG "scull: " fmt, ## args)
#  else
/* This one for user space */
#    define PDEBUG(fmt, args...) fprintf(stderr, fmt, ## args)
#  endif
#else
#  define PDEBUG(fmt, args...) /* not debugging: nothing */
#endif

#undef PDEBUGG
#define PDEBUGG(fmt, args...) /* nothing: it's a placeholder */

#ifndef SCULL_MAJOR
#define SCULL_MAJOR 0   /* dynamic major by default */
#endif

#ifndef SCULL_NR_DEVS
#define SCULL_NR_DEVS 4    /* scull0 through scull3 */
#endif

#ifndef SCULL_P_NR_DEVS
#define SCULL_P_NR_DEVS 4  /* scullpipe0 through scullpipe3 */
#endif

/*
 * The bare device is a variable-length region of memory.
 * Use a linked list of indirect blocks.
 *
 * "scull_dev->data" points to an array of pointers, each
 * pointer refers to a memory area of SCULL_QUANTUM bytes.
 *
 * The array (quantum-set) is SCULL_QSET long.
 */
#ifndef SCULL_QUANTUM
#define SCULL_QUANTUM 4000
#endif

#ifndef SCULL_QSET
#define SCULL_QSET    1000
#endif

/*
 * The pipe device is a simple circular buffer. Here its default size
 */
#ifndef SCULL_P_BUFFER
#define SCULL_P_BUFFER 4000
#endif
   
/*
 * Representation of scull quantum sets.
 */
struct scull_qset {
   	void **data;
   	struct scull_qset *next;
};

struct scull_dev {
	struct scull_qset *data;  /* Pointer to first quantum set */
   	int quantum;              /* the current quantum size */
   	int qset;                 /* the current array size */
   	unsigned long size;       /* amount of data stored here */
   	unsigned int access_key;  /* used by sculluid and scullpriv */
   	struct semaphore sem;     /* mutual exclusion semaphore     */
   	struct cdev cdev;         /* Char device structure              */
};

/*
 * Split minors in two parts
 */
#define TYPE(minor)     (((minor) >> 4) & 0xf)  /* high nibble */
#define NUM(minor)      ((minor) & 0xf)         /* low  nibble */


/*
 * The different configurable parameters
 */
extern int scull_major;     /* main.c */


/*
 * Prototypes for shared functions
 */


ssize_t scull_read(struct file *filp, char __user *buf, size_t count,
ssize_t scull_write(struct file *filp, const char __user *buf, size_t count,
loff_t  scull_llseek(struct file *filp, loff_t off, int whence);

#endif /* _SCULL_H_ */


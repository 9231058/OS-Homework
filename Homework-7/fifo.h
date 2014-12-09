#ifndef FIFO_H
#define FIFO_H

#ifndef FIFO_MAJOR
#define FIFO_MAJOR 0   /* dynamic major by default */
#endif

#ifndef MAX_BUFF
#define MAX_BUFF 1024
#endif

/*
 * Split minors in two parts
 */
#define TYPE(minor)     (((minor) >> 4) & 0xf)  /* high nibble */
#define NUM(minor)      ((minor) & 0xf)         /* low  nibble */


/*
 * The different configurable parameters
 */
extern int fifo_major;     /* main.c */


/*
 * Prototypes for shared functions
 */


static int fifo_open(struct inode *inode, struct file *filp);
static int fifo_release(struct inode* inode, struct file *filp);
static ssize_t fifo_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos);
static ssize_t fifo_write(struct file *filp, const char __user *buf, size_t count, loff_t *f_pos);

#endif /* _SCULL_H_ */


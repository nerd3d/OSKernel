/* sleepy.h */

/*
 * Modified by Christopher Allan
 * Class: CS 5460
 * Semester: Spring 2018
 * School: University of Utah
 */

#ifndef SLEEPY_H_1727_INCLUDED
#define SLEEPY_H_1727_INCLUDED

/* Number of devices to create (default: sleepy0 and sleepy1) */
#ifndef SLEEPY_NDEVICES
#define SLEEPY_NDEVICES 10
#endif

#include <linux/wait.h>

/* The structure to represent 'sleepy' devices. 
 *  data - data buffer;
 *  buffer_size - size of the data buffer;
 *  block_size - maximum number of bytes that can be read or written 
 *    in one call;
 *  sleepy_mutex - a mutex to protect the fields of this structure;
 *  cdev - character device structure.
 */
struct sleepy_dev {
  unsigned char *data;
  struct mutex sleepy_mutex; 
  struct cdev cdev;
  /*** ADDED by Chris Allan ***/
  wait_queue_head_t sleep_queue;
  int flag;
  /***  ***/
};
#endif /* SLEEPY_H_1727_INCLUDED */

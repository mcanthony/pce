/*****************************************************************************
 * pce                                                                       *
 *****************************************************************************/

/*****************************************************************************
 * File name:     src/devices/blkcow.h                                       *
 * Created:       2004-09-17 by Hampa Hug <hampa@hampa.ch>                   *
 * Last modified: 2004-09-17 by Hampa Hug <hampa@hampa.ch>                   *
 * Copyright:     (C) 2004 Hampa Hug <hampa@hampa.ch>                        *
 *****************************************************************************/

/*****************************************************************************
 * This program is free software. You can redistribute it and / or modify it *
 * under the terms of the GNU General Public License version 2 as  published *
 * by the Free Software Foundation.                                          *
 *                                                                           *
 * This program is distributed in the hope  that  it  will  be  useful,  but *
 * WITHOUT  ANY   WARRANTY,   without   even   the   implied   warranty   of *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU  General *
 * Public License for more details.                                          *
 *****************************************************************************/

/* $Id$ */


#ifndef PCE_DEVICES_BLKCOW_H
#define PCE_DEVICES_BLKCOW_H 1


#include <config.h>

#include <devices/disk.h>

#include <stdio.h>


typedef struct cow_hash_t {
  struct cow_hash_t *next;
  unsigned long     block;
  unsigned long     offset;
} cow_hash_t;


/*!***************************************************************************
 * @short The copy on write disk structure
 *****************************************************************************/
typedef struct {
  disk_t        dsk;

  disk_t        *orig;

  FILE          *fp;
  unsigned long offset;

  unsigned long blkcnt;

  unsigned      hash_cnt;
  cow_hash_t    **hash;
} disk_cow_t;


disk_t *dsk_cow_new (disk_t *dsk, const char *fname);


#endif
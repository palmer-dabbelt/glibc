/* Copyright (C) 1997-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by Ulrich Drepper <drepper@cygnus.com>, 1997.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#include <unistd.h>
#include <sysdep-cancel.h>

#if __WORDSIZE != 64 || defined (__ASSUME_OFF_DIFF_OFF64)

# ifndef __NR_pwrite
#  define __NR_pwrite __NR_pwrite64
# endif

ssize_t
__libc_pwrite (int fd, const void *buf, size_t count, off_t offset)
{
  return SYSCALL_CANCEL (pwrite, fd, buf, count,
			 __ALIGNMENT_ARG SYSCALL_LL (offset));
}

strong_alias (__libc_pwrite, __pwrite)
weak_alias (__libc_pwrite, pwrite)
#endif

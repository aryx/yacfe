#ifndef _LINUX_NTFS_TYPES_H
#define _LINUX_NTFS_TYPES_H

#include <linux/types.h>

typedef __le16 le16;
typedef __le32 le32;
typedef __le64 le64;
typedef __u16 __bitwise sle16;
typedef __u32 __bitwise sle32;
typedef __u64 __bitwise sle64;

/* 2-byte Unicode character type. */
typedef le16 ntfschar;
#define UCHAR_T_SIZE_BITS 1




__u8 *irlmp_hint_to_service(__u8 *hint)
{
	__u8 *service;
	int i = 0;

}

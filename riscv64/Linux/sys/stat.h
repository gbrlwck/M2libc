/* Copyright (C) 2020 Jeremiah Orians
 * Copyright (C) 2021 Andrius Štikonas
 * This file is part of M2-Planet.
 *
 * M2-Planet is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * M2-Planet is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with M2-Planet.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <sys/types.h>

#define S_IRWXU 00700
#define S_IXUSR 00100
#define S_IWUSR 00200
#define S_IRUSR 00400

#define S_ISUID 0400
#define S_ISGID 02000
#define S_IXGRP 00010
#define S_IXOTH 00001
#define S_IRGRP 00040
#define S_IROTH 00004
#define S_IWGRP 00020
#define S_IWOTH 00002
#define S_IRWXG 00070
#define S_IRWXO 00007


int chmod(char *pathname, int mode)
{
        asm("RD_A0 !-100 ADDI" /* AT_FDCWD */
	    "RD_A1 RS1_FP !-8 LD"
	    "RD_A2 RS1_FP !-16 LD"
	    "RD_A7 !53 ADDI"
	    "ECALL");
}


int fchmod(int a, mode_t b)
{
        asm("RD_A0 !-100 ADDI" /* AT_FDCWD */
	    "RD_A1 RS1_FP !-8 LD"
	    "RD_A2 RS1_FP !-16 LD"
	    "RD_A7 !52 ADDI"
	    "ECALL");
}


int mkdir(char const* a, mode_t b)
{
        asm("RD_A0 !-100 ADDI" /* AT_FDCWD */
	    "RD_A1 RS1_FP !-8 LD"
	    "RD_A2 RS1_FP !-16 LD"
	    "RD_A7 !34 ADDI"
	    "ECALL");
}


int mknod(char const* a, mode_t b, dev_t c)
{
        asm("RD_A0 !-100 ADDI" /* AT_FDCWD */
	    "RD_A1 RS1_FP !-8 LD"
	    "RD_A2 RS1_FP !-16 LD"
	    "RD_A3 RS1_FP !-24 LD"
	    "RD_A7 !33 ADDI"
	    "ECALL");
}


mode_t umask(mode_t m)
{
	asm("RD_A0 RS1_FP !-8 LD"
	    "RD_A7 !166 ADDI"
	    "ECALL");
}


int stat(const char* path, struct stat* buffer){
        asm("RD_A0 !-100 ADDI" /* AT_FDCWD */
	    "RD_A1 RS1_FP !-8 LD"
	    "RD_A2 RS1_FP !-16 LD"
	    "RD_A7 !1038 ADDI" /* SYS_STAT */
	    "ECALL");
}

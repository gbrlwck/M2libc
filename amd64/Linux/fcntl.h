/* Copyright (C) 2016 Jeremiah Orians
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

#define O_RDONLY 0
#define O_WRONLY 1
#define O_RDWR 2
#define O_CREAT 00100
#define O_EXCL 00200
#define O_TRUNC 001000
#define O_APPEND 002000

#define S_IXUSR 00100
#define S_IWUSR 00200
#define S_IRUSR 00400
#define S_IRWXU 00700


int open(char* name, int flag, int mode)
{
	asm("LOAD_EFFECTIVE_ADDRESS_rdi %24"
	    "LOAD_INTEGER_rdi"
	    "LOAD_EFFECTIVE_ADDRESS_rsi %16"
	    "LOAD_INTEGER_rsi"
	    "LOAD_EFFECTIVE_ADDRESS_rdx %8"
	    "LOAD_INTEGER_rdx"
	    "LOAD_IMMEDIATE_rax %2"
	    "SYSCALL");
}

#define STDIN_FILENO  0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

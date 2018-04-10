# Libft - @42Born2Code
![license](https://img.shields.io/github/license/mashape/apistatus.svg)
![UnitTest](https://img.shields.io/badge/42UnitTest-pass-blue.svg)

An implementation of standard C library. A basic project of school 42 which will be used extensively in other projects of the curriculum of 42.

### Contents
* [What is libft?](#what-is-libft)
* [What's in it?](#whats-in-it)
* [How to use the library?](#how-to-use-the-library)
* [Example usage](#example-usage)

### What is libft?
Libft is an elementary project at school 42. The goal of this project is to reproduce the functionality of the standard C library. This project serves as the wheel for other 42 projects.
Re-inventing the wheel is bad, but 42 uses this pedagogical method to force the students to have a solid understanding on the library they are using.

In my libft, I not only implemented the functions required in the projects but also intergreted projects(get_next_line, ft_printf) to enhance the library. 

In addition, I also added my personal data structures and functions to make this C library more powerful.

### What's in it?

As you can see below, there are 3 sections:

1.  **Libc Functions:** Some of the standard C functions required by the project with get_next_line integreted. Include libft.h for functions below.

Libc functions | Libc additional  | Libc Bonus  
:-----------| :-----------: | -----------:  
ft_memset		| ft_memalloc	| ft_lstnew		 
ft_bzero		| ft_memdel		| ft_lstdelone	 
ft_memcpy		| ft_strnew		| ft_lstdel		    
ft_memccpy		| ft_strdel		| ft_lstadd		    
ft_memmove		| ft_strclr		| ft_lstiter	    
ft_memchr		| ft_striter	| ft_lstmap
ft_memcmp		| ft_striteri	| get_next_line		
ft_strlen		| ft_strmap		|				 
ft_strdup		| ft_strmapi	|				 
ft_strcpy		| ft_strequ		|				
ft_strncpy		| ft_strnequ	|				
ft_strcat		| ft_strsub		|		
ft_strlcat		| ft_strjoin	|		
ft_strchr		| ft_strtrim	|		
ft_strrchr		| ft_strsplit	|			
ft_strstr		| ft_itoa		|				 
ft_strnstr		| ft_putchar	|				
ft_strcmp		| ft_putstr		|				
ft_strncmp		| ft_putendl	|				
ft_atoi		| ft_putnbr		|		
ft_isalpha		| ft_putchar_fd	|		
ft_isdigit		| ft_putstr_fd	|		
ft_isalnum		| ft_putendl_fd	|		
ft_isascii		| ft_putnbr_fd	|			
ft_isprint		|				|		
ft_toupper		|				|			
ft_tolower		|				|		

2.  **ft_printf:** Project ft_printf integreted into the libft library, include ft_printf.h in the source to use.

ft_printf functions
:-----------:| 
ft_printf	 	 
ft_dprintf	 
ft_asprintf	

3.  **ft_array:** My customized array, ft_array, which can grow its size automatically.
Also, I implemented basic functions on this array, including sorting algorithms.
By using this structure, I also implemented stack and queue related functions so that the array can serve as a stack or a queue.
Include ft_array.h in the source to use functions below.

ft_array functions  | stack queue functions| sorting functions  
:----------- 	| :-----------: 	| -----------:  
ft_arrnew	 	| ft_arrstack_push	| ft_arrqsort		 
ft_arrnew_size	| ft_arrstack_pop  	| ft_arrmsort
ft_arrnew_arr	| ft_arrstack_peek 	|
ft_arrappend 	| ft_arrqueue_push	|
ft_arrappend_raw| ft_arrqueue_pop	|
ft_arrinsert 	| ft_arrqueue_peek	|
ft_arrinsert_raw|					|
ft_arrswap 		|					|
ft_arrremove_at |					|
ft_arritem_at	|					|
ft_arrsub		|					|


### How to use the library?

1.  **git clone & make:** git clone the project to your directory and make.

2.  **include "xxx":** include some or all the header files in the includes directory to your source code, and then use the corresponding functions available in the header file.

3. **compile:** compile the source code using the static library in gcc or clang. 

`clang example.c -L(path to libft.a) -lft -I(path to libft/includes)`

and Voila!

## Example usage

Libft is used in projects of algorithms, Unix and graphic extensively.

* ft_printf, filler, Lem-in, Corewar
* Fdf, fract'ol
* ft_ls, 21sh



<h1 align="center"> ft_printf - @42sp </h1>

<p align="center">:information_source: A library that contains ft_printf, a function that will mimic the real printf </p>

<p align="center"><a href="https://github.com/augustobecker/ft_printf/blob/main/README-ptbr.md" target="_blank"><img src="https://img.shields.io/badge/dispon%C3%ADvel%20tamb%C3%A9m%20em-PT--BR-yellow"></a></p>

## Index
* [What is ft_printf?](#what-is-ft-printf)
* [Requirements](#requirements)
* [How does it work?](#how-does-it-work)
* [How do I use the library?](#how-do-i-use-the-library)
* [How do I test it?](#how-do-i-test-it)

<h2 align="center" id="what-is-ft-printf"> What is ft_printf? </h2>

<h2 align="center" id="requirements"> Requirements </h2>

<p  align="center"> :warning: The project must be written in accordance with the <a href="https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf" target="_blank">Norm</a> </p>
The Norm  is a programming standard that defines a set of rules to follow when writing code at 42. It applies to all C projects within the Common Core by default, and
to any project where it's specified. These are some of them:

    Each function must be maximum 25 lines, not counting the function's own curly brackets.
    
    Each line must be at most 80 columns wide, comments included.
    
    A function can take 4 named parameters maximum.
    
    You can't declare more than 5 variables per function.
    
    You're not allowed to use: for , do...while , switch , case ,  goto  ,
    ternary operators such as `?' and VLAs - Variable Length Arrays.
  The norminette (as we call the norm at 42) is in python and open source.
  
  Its repository is available at https://github.com/42School/norminette.
  

<h2 align="center" id="how-does-it-work"> How does it work? </h2>

<h2 align="center" id="how-do-i-use-the-function"> How do I use the function? </h2>

<h2 align="center" id="how-do-i-use-the-library"> How do I use the library? </h2>
It aims to create a library called libftprintf.a from the source files.

To create this library, clone the project:

    git clone https://github.com/augustobecker/ft_printf ft_printf
Enter the repository:

    cd ft_printf
Run Make (to run the Makefile that will compile the source code and create the library):

    make

You should see a libftprintf.a file and some object files (.o).

Now to clean up (removing the .o files), call make clean:

    make clean
Now you just have to add this header at your .c files and use the ft_printf function or any other from the library:

    #include "ft_printf.h"
If you try to compile your .c files with clang using "clang example.c" you will get an undefined symbol error for Libftprintf functions.

You have to tell the file where your library resides and which library it's using:

    clang example.c -L library -lftprintf

-L takes the path to your library. library in this case

-l takes the name of your library. This is the set of characters that come after lib in your library name.

That's it. Now run it using ./a.out

<h2 align="center" id="how-do-i-test-it"> How do I test it? </h2>

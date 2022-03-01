<h1 align="center"> ft_printf - @42sp </h1>

<p align="center">:information_source: A static library that contains ft_printf, a function that mimics the real printf </p>

<p align="center"><a href="https://www.42sp.org.br/" target="_blank"><img src="https://img.shields.io/static/v1?label=&message=SP&color=000&style=for-the-badge&logo=42""></a></p>
<p align="center"><a href="https://github.com/augustobecker/ft_printf/blob/main/README-ptbr.md" target="_blank"><img src="https://img.shields.io/badge/dispon%C3%ADvel%20tamb%C3%A9m%20em-PT--BR-yellow"></a></p>

## Index
* [What is ft_printf?](#what-is-ft-printf)
* [Requirements](#requirements)
* [How does it work?](#how-does-it-work)
* [How do I use the library?](#how-do-i-use-the-library)
* [How do I test it?](#how-do-i-test-it)
* [Author](#author)

<h2 align="center" id="what-is-ft-printf"> What is ft_printf? </h2>

The third project at 42 programming school. It consists of a static library that contains ft_printf - a function that mimics the real printf - and another library (<a href="https://github.com/augustobecker/Libft">Libft</a>, the first project at 42) with recoded standard functions in C to support the project's development. It's an extremely useful function that does a series of base conversions (decimal and hexadecimal) and makes the output much easier - especially when compared to its predecessor in 42 - the system call write. The function can be used in future projects.
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
  
  In addition to the Norm, the subject have other requirements, which are:
   
    Using the command libtool to create your library is forbidden.
    
    Your Makefile must compile with the flags -Wall, -Wextra and -Werror.
    
<h2 align="center" id="how-does-it-work"> How does it work? </h2>
    
<p align="center"> ✨ For this project we were introduced to the concept of variadic functions ✨ </p>

The printf function is one of the most known and used in the C language to give an output.
It takes a string as an argument, this string may contain some placeholders (like %c for characters or %s for strings) whose original values are passed as arguments. The ft_printf has variable arguments, the only one being mandatory is the string that will be printed, otherwise it depends on how many placeholders are passed in this string. The function's return is the number of characters printed or -1 for error.
    
To create with a function like this, it must be a variadic function (with variable number of arguments), which is possible to achieve using the header <stdarg.h> and parameters like va_arg for the list arguments in order of occurrence or va_start and va_end to start and end the use of the argument list.
For each conversion required by the subject, there's a function that converts the argument and returns the numer of bytes writed:
    
• <a href="https://github.com/augustobecker/ft_printf/blob/main/printf/ft_argument_c.c">%c</a> print a single character.
    
• <a href="https://github.com/augustobecker/ft_printf/blob/main/printf/ft_argument_s.c">%s </a>print a string of characters.
    
• <a href="https://github.com/augustobecker/ft_printf/blob/main/printf/ft_argument_p.c">%p </a>The void * pointer argument is printed in hexadecimal.
    
• <a href="https://github.com/augustobecker/ft_printf/blob/main/printf/ft_arguments_d_i.c">%d </a>print a decimal (base 10) number.
    
• <a href="https://github.com/augustobecker/ft_printf/blob/main/printf/ft_arguments_d_i.c">%i </a>print an integer in base 10.
    
• <a href="https://github.com/augustobecker/ft_printf/blob/main/printf/ft_argument_u.c">%u </a>print an unsigned decimal (base 10) number.
    
• <a href="https://github.com/augustobecker/ft_printf/blob/main/printf/ft_arguments_x.c">%x </a>print a number in hexadecimal (base 16).
    
• <a href="https://github.com/augustobecker/ft_printf/blob/main/printf/ft_argument_percent.c">%% </a>print a percent sign.

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

You have to tell the file which library it's using:

    clang example.c libftprintf.a

That's it. Now run it using ./a.out

<h2 align="center" id="how-do-i-test-it"> How do I test it? </h2>

To test the code we're going to be using @jgambard's Printf Tester. There are some good others but I'll only be covering this one.

To test the code in this repo
Clone this repo and cd into it:

    git clone https://github.com/augustobecker/ft_printf ft_printf
      
    cd ft_printf/
 
Now, clone @jgambard's Libft Tester
    
    git clone https://github.com/Tripouille/printfTester.git printfTester
Go into the test folder and run the mandatory test:

    cd printfTester
    make m

In case that your project or another project you are going to evaluate has a bonus, run the bonus test too:
    
    make b
    
If you did everything correctly you should see something like this:
    ![68747470733a2f2f692e696d6775722e636f6d2f556549375048612e706e67](https://user-images.githubusercontent.com/81205527/151406246-07d3bf2b-9c63-4f00-aca9-266f2ee32034.png)

<h2 align="center" id="author"> Author </h2>
<div>
    <img height="180em" src="https://user-images.githubusercontent.com/81205527/152089472-0aa06bd9-d882-4c83-adfc-8230d1e958c1.png">
    
<strong> Augusto Becker | acesar-l | 🇧🇷👨‍🚀</strong>
    
:wave: How to reach me: 
    
  <a href = "mailto:augustobecker.dev@gmail.com"><img src="https://img.shields.io/badge/augustobecker.dev@gmail.com-D14836?style=for-the-badge&logo=gmail&logoColor=white"> </a>
  <a href="https://www.linkedin.com/in/augusto-becker/" target="_blank"><img src="https://img.shields.io/badge/-Augusto Becker-%230077B5?style=for-the-badge&logo=linkedin&logoColor=white" target="_blank"></a>
  <a href="https://www.instagram.com/augusto.becker/" target="_blank"><img src="https://img.shields.io/badge/-augusto.becker-%23E4405F?style=for-the-badge&logo=instagram&logoColor=white" target="_blank"></a>
</div>

<h1 align="center"> ft_printf - @42sp </h1>

<p align="center">:information_source: A static library that contains ft_printf, a function that mimics the real printf </p>

<p  align="center"><a href="https://www.42sp.org.br/" target="_blank"><img src="https://img.shields.io/static/v1?label=&message=SP&color=000&style=for-the-badge&logo=42""></a></p>
    
<p align="center"><img src="https://user-images.githubusercontent.com/81205527/157133425-69e61e0d-9051-4733-87cb-844319544a8b.png"> </p>
<p align="center"> <strong>100/100</strong> ✅ </p>
<p align="center"><a href="https://github.com/augustobecker/ft_printf/blob/main/README-ptbr.md" target="_blank"><img src="https://img.shields.io/badge/dispon%C3%ADvel%20tamb%C3%A9m%20em-PT--BR-yellow"></a></p>

## Index
* [What is ft_printf?](#what-is-ft-printf)
* [Requirements](#requirements)
* [How does it work?](#how-does-it-work)
* [How do I use the library?](#how-do-i-use-the-library)
* [How do I test it?](#how-do-i-test-it)
* [Makefile](#makefile)
	* [Colorful Makefile](#colorful-makefile)
* [42 Cursus](#42-cursus)
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

    #include "library/ft_printf.h"
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

  <h2 align="center" id="makefile"> Makefile </h2>

<p align="center">:information_source: A handy automation tool to Run and compile your programs more efficiently.	</p>
	
A Makefile defines set of tasks to be executed, in shell script. These tasks are writed on a target in this format:
	
	target: prerequisites
	<TAB> recipe

such as:
	
	fclean:	clean
		@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"
		${REMOVE} ${NAME}
		@echo

The recipe(the commands @echo and so forth) for the target fclean will only be executed when the target clean (the prerequisite) be executed.
a target works without prerequisites too:
	
	clean:
		@echo "\n$(NAME): $(RED)object files were deleted$(RESET)"
		${REMOVE} ${OBJS} ${BONUS_OBJS}
		@echo
	
As you could see, there are a few variables inside the recipe. The variables can be assigned just as follow:
	
	GREEN		= \033[0;32m
	RED		= \033[0;31m
	RESET		= \033[0m
	CC		= clang
	FLAGS 		= -Wall -Werror -Wextra

To use the variable value, just use the $ sign with parenthesis:
	
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

Using variables makes your Makefile more readable and easily modifiable. Try it :)

It is not necessary for the target to be a file. It could be just a name for the recipe, just as above. We call these phony targets.
	
But if you have a file with the exact name of your phony target inside of your repo, things can get a little weird.
To protected your Makefile from this, just use phony and the name of all your phony targets used:
	
	.PHONY:		all clean fclean re bonus

Here at 42 school, the subject says that
>Your Makefile must at least contain the rules $(NAME), all, clean, fclean and re.
	
The rules are the target, just name some of them as $(NAME), all, clean, fclean and re.
	
The rule **$(NAME)**, in this case, should create the **$(NAME)** static library.
	
**all** is used to make the principal goal of your Makefile: create the $(NAME) static library.
	
**clean** removes the objects created to make the library.
	
**fclean** removes the objects created to make the library and the **$(NAME)**.
	
**re** just removes the objects created to make the library and the **$(NAME)**, to then recompile everything.

You can run a rule on your Makefile this way:

	make $(target_name)
	
such as:
	
	make clean
	
In the case of the target all, just type make
	
	make

<h3 align="center" id="colorful-makefile"> Colorful Makefile </h3>
	
Choose your color, add it as a variable and use in your Makefile:

	BLACK		="\[\033[0;30m\]"        
	RED		="\[\033[0;31m\]"       
	GREEN		="\[\033[0;32m\]"      
	YELLOW		="\[\033[0;33m\]"       
	BLUE		="\[\033[0;34m\]"        
	PURPLE		="\[\033[0;35m\]"     
	CYAN		="\[\033[0;36m\]"         
	WHITE		="\[\033[0;37m\]"    
	RESET		="\033[0m"

You could use it this way:
	
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"
	
So $(NAME) was deleted will be printed in red.

Cool, right?
	
Remember to reset the color when you're done, otherwise your terminal will keep with the last used colour.
 
<h2 align="center" id="42-cursus"> 42 Cursus </h2>
	
42 is a global education initiative that proposes a new way of learning technology: no teachers, no classrooms,
students learning from their fellow students (peer to peer learning),
with a methodology that develops both computing and life skills.
Not to mention that it's completely free of charge and open to all with no prerequisites.

Admissions at 42 are unlike other colleges. We use a merit-based admission process.
The final step of the admission is the Piscine - This is part of the admissions process and 
requires 4 weeks of intensive and immersive coding. No prior coding experience is necessary at all.
	
You can check more about the admission process on the 42sp website: https://www.42sp.org.br or on my github repository: <a href="https://github.com/augustobecker/42sp_Piscine">42 Piscine</a>

To see other projects developed by me at 42, click here: <a href="https://github.com/augustobecker/42cursus">42 Cursus </a>
	
<h2  align="center" id="author">Author</h2>
<div align="center">
	<div>
	<img height="222em" src="https://user-images.githubusercontent.com/81205527/174709160-f4bc029d-b667-469b-b2a7-4e036f1c5349.png">
	</div>
	<div>
		<strong> Augusto Becker | acesar-l | 🇧🇷👨‍🚀</strong>
	
:wave: How to reach me:
    	</div> 
    	<div>
  	<a href="https://www.linkedin.com/in/augusto-becker/" target="_blank"><img align="center" alt="LinkedIn" height="60" src="https://user-images.githubusercontent.com/81205527/157161849-01a9df02-bf32-45be-add4-122bc40b48cf.png"></a>
	<a href="https://www.instagram.com/augusto.becker/" target="_blank"><img align="center" alt="Instagram" height="60" src="https://user-images.githubusercontent.com/81205527/157161841-19ec3ab2-2c8f-4ec0-8b9d-3cd885256098.png"></a>
	<a href = "mailto:augustobecker.dev@gmail.com"> <img align="center" alt="Gmail - augustobecker.dev@gmail.com" height="60" src="https://user-images.githubusercontent.com/81205527/157161831-eb9dffee-404b-4ffe-b0af-34671219f7fb.png"></a>
	<a href="https://discord.gg/3kxYkBRxUy" target="_blank"><img align="center" alt="Discord - beckerzz#3614" height="60" src="https://user-images.githubusercontent.com/81205527/157161820-de88dc63-61a3-4c9f-9445-07ac98bf0bc2.png"></a>
	</div>
</div>

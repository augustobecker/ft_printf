<h1 align="center"> ft_printf - @42sp </h1>

<p align="center">:information_source: Uma biblioteca estática que contém a função ft_printf, uma re-implementação da printf real </p>

<p align="center"><a href="https://www.42sp.org.br/" target="_blank"><img src="https://img.shields.io/static/v1?label=&message=SP&color=000&style=for-the-badge&logo=42""></a></p>
<p align="center"><img src="https://user-images.githubusercontent.com/81205527/157133425-69e61e0d-9051-4733-87cb-844319544a8b.png"> </p>
<p align="center"> <strong>100/100</strong> ✅ </p>
<p align="center"><a href="https://github.com/augustobecker/ft_printf/blob/main/README.md"><img src="https://img.shields.io/badge/available%20in-EN-blue"></a></p>

## Índice

* [O que é ft_printf?](#o-que-e-ft_printf)
* [Requisitos](#requisitos)
* [Como funciona?](#como-funciona)
* [Como eu uso a Biblioteca?](#como-eu-uso-a-biblioteca)
* [Como eu testo?](#como-eu-testo)
* [Makefile](#makefile)
	* [Makefile Colorido](#makefile-colorido)
* [42 Cursus](#42-cursus)
* [Autor](#autor)

<h2 align="center" id="o-que-e-ft_printf"> O que é ft_printf? </h2>

O terceiro projeto na 42. A ft_printf é uma biblioteca estática que contém a função ft_printf e também as funções padrão da linguagem C recriadas na biblioteca Libft (o primeiro projeto da 42) - que serve de apoio pela primeira vez em outro projeto para mim. É uma função extremamente útil e pode ser usada em projetos futuros dentro da 42 - uma vez que faz uma série de conversões (para decimal e hexadecimal) além de facilitar muito o output, que antes precisava ser feito com a system call <strong>write</strong> (que torna printar um simples int uma tarefa de uns bons minutos uma vez que só consegue printar os números de 0 a 9, agora imagine printar um endereço de memória em hexadecimal que em int seria perto de 93 trilhões).

<h2 align="center" id="requisitos"> Requisitos </h2>

<p  align="center"> :warning: O projeto deve estar de acordo com a <a href="https://github.com/42School/norminette/blob/master/pdf/pt_br.norm.pdf" target="blank">Norma</a> </p>
A Norma é um padrão de programação que define um conjunto de regras a seguir ao escrever um código na 42. A norma aplica-se a todos os projetos C dentro do currículo interno por padrão, e para qualquer projeto onde é especificado. Aqui algumas das regras:

    Cada função dever ter no máximo 25 linhas, não contando suas próprias chaves '{}'.
    
    Cada linha deve ter no máximo 80 colunas de largura, comentários incluídos.
    
    Uma função pode ter no máximo 4 parâmetros definidos.
   
    Não podem ser declaradas mais que 5 variáveis por função.
    
    Não é permitido o uso de: for , do...while , switch , case ,  goto  ,
    operadores ternários como `?' e VLAs - Matrizes de comprimento variável.
  A norminette (como chamamos a norma na 42) é feita em python e é open source.
  
  O repositório está disponível em https://github.com/42School/norminette
  
  Além da norma padrão, o projeto tem alguns requisitos próprios
   
    Usar o comando libtool para criar a biblioteca é proibido.
    
    O Makefile deve compilar com as flags -Wall, -Wextra e -Werror
  
    
<h2 align="center" id="como-funciona"> Como funciona? </h2>

<p align="center"> :sparkles: <strong>Para este projeto fomos apresentados ao conceito de funções de argumentos variáveis.</strong> :sparkles:</p>

A função printf é uma das mais conhecidas e usadas na linguagem para dar um output. Ela recebe uma string como argumento, essa string pode conter alguns placeholders (como %c para caracteres ou %s para strings) cujos valores originais são passados como argumentos. A ft_printf tem argumentos variáveis, sendo o único obrigatório a string que vai ser printada, de resto depende de quantos placeholders são passados nesssa string. O retorno da função é o número de caracteres printados ou -1 para erro. Para criar com uma função desse jeito precisamos que tenha argumentos variáveis, o que é possível usando o cabeçalho <stdarg.h> e parâmetros como va_arg para os argumentos da lista em ordem de ocorrência ou va_start e va_end para iniciar e encerrar o uso da lista de argumentos.
    
Para cada uma das conversões requeridas pelo subject que a ft_printf fizesse, há uma função que converte o argumento e retorna os bytes escritos, são elas:
    
• <a href="https://github.com/augustobecker/ft_printf/blob/main/printf/ft_argument_c.c">%c</a> printa um único caracter.
    
• <a href="https://github.com/augustobecker/ft_printf/blob/main/printf/ft_argument_s.c">%s</a> printa uma string.
    
• <a href="https://github.com/augustobecker/ft_printf/blob/main/printf/ft_argument_p.c">%p</a> O argumento void * pointer é printado em hexadecimal.
    
• <a href="https://github.com/augustobecker/ft_printf/blob/main/printf/ft_arguments_d_i.c">%d</a> printa um número decimal (base 10).
    
• <a href="https://github.com/augustobecker/ft_printf/blob/main/printf/ft_arguments_d_i.c">%i</a> printa um inteiro em base 10.
    
• <a href="https://github.com/augustobecker/ft_printf/blob/main/printf/ft_argument_u.c">%u</a> printa um número decimal (base 10) unsigned.
    
• <a href="https://github.com/augustobecker/ft_printf/blob/main/printf/ft_arguments_x.c">%x</a> printa um número em hexadecimal (base 16).
    
• <a href="https://github.com/augustobecker/ft_printf/blob/main/printf/ft_argument_percent.c">%%</a> printa um sinal de porcentagem.
    
<h2 align="center" id="como-eu-uso-a-biblioteca"> Como eu uso a Biblioteca? </h2>
O objetivo é criar uma bilioteca chamada libftprintf.a feita com os arquivos fonte.

Para criar a biblioteca, clone o projeto:

    git clone https://github.com/augustobecker/ft_printf ft_printf
Entre no repositório:

    cd ft_printf
Rode o comando Make (para executar o Makefile que vai compilar o código fonte e criar a biblioteca):

    make

Você deve ver um arquivo libftprintf.a e alguns arquivos objeto (.o).

Agora, para limpar tudo (remover os arquivos .o), use make clean:

    make clean
Agora, só precisa adicionar esse cabeçalho nos seus arquivos .c e usar as funções da Libftprintf:

    #include "library/ft_printf.h"
Se tentar compilar seus arquivos com clang usando "clang exemplo.c" vai receber um erro de undefined symbol para as funções da biblioteca.

Você deve mostrar qual é a biblioteca:

    clang exemplo.c libftprintf.a

É isso, agora basta executar com ./a.out

<h2 align="center" id="como-eu-testo"> Como eu testo? </h2>

Para testar o código vamos usar um Tester para a ft_printf feito pelo @jgambard. Há vários outros bons testers mas hoje vou cobrir apenas esse.

Para testar o código desse repositório:
Clone o repositório e entre nele:

    git clone https://github.com/augustobecker/ft_printf ft_printf
      
    cd ft_print/
 
Agora, clone o Print Tester do @jgambard
    
    git clone https://github.com/Tripouille/printfTester printfTester
Entre na pasta do Tester e rode o teste mandatório:

    cd printfTester
    make m

Caso o seu projeto ou um outro que vá avaliar tenha bônus, rode o teste do bônus também:
    
    make b
    
Se você fez tudo corretamente, deve ver algo como isso:
 ![68747470733a2f2f692e696d6775722e636f6d2f556549375048612e706e67](https://user-images.githubusercontent.com/81205527/151406246-07d3bf2b-9c63-4f00-aca9-266f2ee32034.png)

    
<h2 align="center" id="makefile"> Makefile </h2>

<p align="center">:information_source: Uma ferramenta de automacão para rodar e compilar seus programas com maior eficiência.	</p>

Um Makefile define uma série de tarefas para serem executadas em shell script. Essas tarefas são escritas em um target nesse formato:
	
	target: pré-requisitos
	<TAB> receita

como em:
	
	fclean:	clean
		@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"
		${REMOVE} ${NAME}
		@echo

A receita (os comandos @echo e por ai vai) para o target fclean só vai ser executada quando o target clean (o pré-requisito) for executado.
Um target funciona sem pré-requisito também:
	
	clean:
		@echo "\n$(NAME): $(RED)object files were deleted$(RESET)"
		${REMOVE} ${OBJS} ${BONUS_OBJS}
		@echo
	
Como você pode ver, há algumas variáveis dentro da receita. As variáveis no Makefile podem ser criadas e atribuídas assim:
	
	GREEN		= \033[0;32m
	RED		= \033[0;31m
	RESET		= \033[0m
	CC		= clang
	FLAGS 		= -Wall -Werror -Wextra

Para usar o valor da variável apenas digite o nome com o sinal de $:
	
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

Usar variáveis faz o seu Makefile mais legível e facil de alterar.
	
Não é necessário que o target seja um arquivo como em $(NAME). Pode ser apenas o nome da receita, como acima. Chamamos esses targets 
de phony targets.

Se você tiver um arquivo com o exato nome da sua phony target, as coisas podem ficar um pouco estranhas
Para proteger seu Makefile disso, apenas use phony e o nome de todos os seus phony targets usados:
	
	.PHONY:		all clean fclean re bonus

Aqui na 42, o subject diz que:
>Your Makefile must at least contain the rules $(NAME), all, clean, fclean and re.
	
As regras são target, é só nomear como $(NAME), all, clean, fclean e re.

	
A regra **$(NAME)**, nesse caso, deveria criar a biblioteca estática **$(NAME)**.
	
**all** é usado para o principal objetivo do seu Makefile: criar a biblioteca estática **$(NAME)**.
	
**clean** remove os objetos criados para fazer a biblioteca.
	
**fclean** remove os objetos criados para fazer a biblioteca e a biblioteca estática **$(NAME)**.
	
**re** apenas remove os objetos criados para fazer a biblioteca e a biblioteca estática **$(NAME)**, para então recompilar tudo.

Você pode rodar uma regra do seu Makefile nesse modelo:

	make $(nome_regra)
	
Assim:
	
	make clean

No caso do target all, só digite make
	
	make

<h3 align="center" id="makefile-colorido"> Makefile Colorido </h3>

Escolha uma cor, adicone como variável e use no seu Makefile:

	BLACK		="\[\033[0;30m\]"        
	RED		="\[\033[0;31m\]"       
	GREEN		="\[\033[0;32m\]"      
	YELLOW		="\[\033[0;33m\]"       
	BLUE		="\[\033[0;34m\]"        
	PURPLE		="\[\033[0;35m\]"     
	CYAN		="\[\033[0;36m\]"         
	WHITE		="\[\033[0;37m\]"    
	RESET		="\033[0m"

Você pode usar assim:
	
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"
	
E então $(NAME) was deleted será printada em vermelho no terminal.

Maneiro, né?

Lembre de resetar a cor quando terminar de usar uma cor, de contrário o terminal ficará da cor da última cor usada.  
 
<h2 align="center" id="42-cursus"> 42 Cursus </h2>
	
A 42 é uma iniciativa educacional global que propõe uma nova forma de aprender tecnologia: sem professores, sem salas de aula,
estudantes aprendendo com seus colegas estudantes (Aprendizado peer to peer),
com uma metodologia que desenvolve habilidades de computação e da vida.
Sem mencionar que é completamente gratuita e aberta para todos, sem pré-requisitos. 
    
As admissões na 42 são diferentes de outras escolas. Usamos um processo de admissão baseado em mérito.
O passo final no processo é a Piscina - parte parte do processo seletivo que requer 4 semanas de código intenso e imersivo.
Não é necessário experiência anterior em programação.
    
Você pode conferir mais sobre o processo de admissão no site da 42sp: https://www.42sp.org.br
    
ou no meu repositório do github: <a href="https://github.com/augustobecker/42sp_Piscine">42 Piscine</a>

Para ver outros projetos da 42 desenvolvidos por mim, clique aqui: <a href="https://github.com/augustobecker/42cursus">42 Cursus </a>
	
<h2  align="center" id="autor">Autor</h2>
<div align="center">
	<div>
	<img height="222em" src="https://user-images.githubusercontent.com/81205527/174709160-f4bc029d-b667-469b-b2a7-4e036f1c5349.png">
	</div>
	<div>
		<strong> Augusto Becker | acesar-l | 🇧🇷👨‍🚀</strong>
	
:wave: Fale comigo: 
    	</div> 
    	<div>
  	<a href="https://www.linkedin.com/in/augusto-becker/" target="_blank"><img align="center" alt="LinkedIn" height="60" src="https://user-images.githubusercontent.com/81205527/157161849-01a9df02-bf32-45be-add4-122bc40b48cf.png"></a>
	<a href="https://www.instagram.com/augusto.becker/" target="_blank"><img align="center" alt="Instagram" height="60" src="https://user-images.githubusercontent.com/81205527/157161841-19ec3ab2-2c8f-4ec0-8b9d-3cd885256098.png"></a>
	<a href = "mailto:augustobecker.dev@gmail.com"> <img align="center" alt="Gmail - augustobecker.dev@gmail.com" height="60" src="https://user-images.githubusercontent.com/81205527/157161831-eb9dffee-404b-4ffe-b0af-34671219f7fb.png"></a>
	<a href="https://discord.gg/3kxYkBRxUy" target="_blank"><img align="center" alt="Discord - beckerzz#3614" height="60" src="https://user-images.githubusercontent.com/81205527/157161820-de88dc63-61a3-4c9f-9445-07ac98bf0bc2.png"></a>
	</div>
</div>    	

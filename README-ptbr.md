<h1 align="center"> ft_printf - @42sp </h1>

<p align="center">:information_source: Uma biblioteca estática que contém a função ft_printf, uma re-implementação da printf real </p>

<p align="center"><a href="https://www.42sp.org.br/" target="_blank"><img src="https://img.shields.io/static/v1?label=&message=SP&color=000&style=for-the-badge&logo=42""></a></p>
<p align="center"><img src="https://user-images.githubusercontent.com/81205527/157133425-69e61e0d-9051-4733-87cb-844319544a8b.png"> </p>
<p align="center"> <strong>100/100</strong> ✔️ </p>
<p align="center"><a href="https://github.com/augustobecker/ft_printf/blob/main/README.md"><img src="https://img.shields.io/badge/available%20in-EN-blue"></a></p>

## Índice

* [O que é ft_printf?](#o-que-e-ft_printf)
* [Requisitos](#requisitos)
* [Como funciona?](#como-funciona)
* [Como eu uso a Biblioteca?](#como-eu-uso-a-biblioteca)
* [Como eu testo?](#como-eu-testo)
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

<h2 align="center" id="autor"> Autor </h2>
<div>
    <img height="180em" src="https://user-images.githubusercontent.com/81205527/152089472-0aa06bd9-d882-4c83-adfc-8230d1e958c1.png">
    
<strong> Augusto Becker | acesar-l | 🇧🇷👨‍🚀</strong>
    
:wave: Fale comigo: 
    
  <a href = "mailto:augustobecker.dev@gmail.com"><img src="https://img.shields.io/badge/augustobecker.dev@gmail.com-D14836?style=for-the-badge&logo=gmail&logoColor=white"> </a>
  <a href="https://www.linkedin.com/in/augusto-becker/" target="_blank"><img src="https://img.shields.io/badge/-Augusto Becker-%230077B5?style=for-the-badge&logo=linkedin&logoColor=white" target="_blank"></a>
  <a href="https://www.instagram.com/augusto.becker/" target="_blank"><img src="https://img.shields.io/badge/-augusto.becker-%23E4405F?style=for-the-badge&logo=instagram&logoColor=white" target="_blank"></a>
</div>

<h1 align="center"> ft_printf - @42sp </h1>

<p align="center">:information_source: Uma biblioteca estática que contém a função ft_printf, uma re-implementação da printf real </p>

<p align="center"><a href="https://github.com/augustobecker/ft_printf/edit/main/README.md"><img src="https://img.shields.io/badge/available%20in-EN-blue"></a></p>

## Índice

* [O que é ft_printf?](#o-que-e-ft_printf)
* [Requisitos](#requisitos)
* [Como funciona?](#como-funciona)
* [Como eu uso a Biblioteca?](#como-eu-uso-a-biblioteca)
* [Como eu testo?](#como-eu-testo)

<h2 align="center" id="o-que-e-ft_printf"> O que é ft_printf? </h2>

O terceiro projeto na 42. É uma função em C que recebe uma string como argumento, essa string pode conter alguns placeholders (como %c para caracteres ou %s para strings) cujos valores originais são passados como argumentos. A ft_printf tem argumentos variáveis, sendo o único obrigatório a string que vai ser printada, de resto depende de quantos placeholders são passados nesssa string. O retorno da função é o número de caracteres printados e -1 para erro. É uma função extremamente útil e pode ser usada em projetos futuros dentro da 42 - uma vez que faz uma série de conversões(para decimal e hexadecimal) além de facilitar muito o output, que antes precisava ser feito com a system call write(que torna printar um simples int uma tarefa de uns bons minutos uma vez que só consegue printar os números de 0 a 9).

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
  
    
<h2 align="center" id="como-funciona"> Como funciona? </h2>

<p align="center"> :sparkles: <strong>Para este projeto fomos apresentados ao conceito de funções de argumentos variáveis.</strong> :sparkles:</p>

<h2 align="center" id="como-eu-uso-a-biblioteca"> Como eu uso a Biblioteca? </h2>

<h2 align="center" id="como-eu-testo"> Como eu testo? </h2>

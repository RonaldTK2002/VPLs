# Exercício de Revisão e Refatoração

O objetivo dessa atividade é praticar a parte de revisão e refatoração utilizando um sistema de controle de versão.

**Considere a seguinte descrição em alto nível da funcionalidade do código:**  
> Um streaming precisa cadastrar novas séries e filmes no seu sistema e também adicionar a nota dos usuários pertencentes a cada série e filme. Para isso é considerado em seu sistema que todo filme precisa ter duração a partir de 50 minutos, toda série precisa ter pelo menos 2 episódios e as avaliações dos usuários fiquem no intervalo de 0 a 10. Por fim, o código imprimirá todos os conteúdos presentes em seu catálogo.

O código atual pode ser compilado/executado usando os seguintes comandos:
```
g++ main.cpp -o vpl_exec
./vpl_exec < in.txt
```

Você deve criar um **Fork** desse repositório, fazer as alterações que julgar necessárias e então realizar um **Pull Request**. Você é livre para criar outros arquivos, classes, métodos, etc., desde que o main continue produzindo a mesma saída. Lembre-se que essa etapa não altera o comportamento funcional.

No **título** do seu Pull Request, informe o valor **MD5** obtido a partir da sua **matrícula**. Você pode gerar esse valor a partir de diferentes sites, um exemplo está [aqui](http://www.md5.cz/). Lembre-se de também informar seus dados no forms disponibilizado no Moodle. Na **descrição** faça uma **lista/análise detalhada** das **soluções** que você utilizou. Submissões que não seguirem essas instruções não serão avaliadas.

Lembre-se de analisar aspectos como: nomenclatura, formatação, organização, modularização, comentários, aplicação correta dos conceitos de OO, entre outros.
Dica: Utilize o catálogo para pensar em possíveis sugestões de refatoração (https://refactoring.com/catalog/).
Esse código é um simples criador de personagem de RPG. ele se baseia em 3 principais etapas:
Classe, Distribuição de status e 

Etapa 1: Seleção de classe:
Há uma matriz com os dados de todas as classes. O comando seleciona e puxa os dados da coluna que equivale a classe. No código há comentários para se basear na ordem, mas escreverei aqui. statusbaseclasse[linha][coluna]
Linhas: 
"Vida máxima",
"Mana máxima",
"Classe de Armadura"  
Colunas         
"Clérigo",
"Guerreiro",
"Bardo",
"Ladino"

Isso gera um par ordenado que cadastra no array do player os dados da classe

Etapa 2: Distribuição de status:
A distribuição de status é feita um por um, sendo For, Dex, Vig, Int, Sab e Car. A pessoa tem uma quantia x de pontos para dsitribuir e é obrigatório por, pelo menos, 1 ponto em cada. Após isso, cadastra em outro array do player

Etapa 3: Seleção de Raça
Aqui, segue o mesmo esquema de par ordenado da etapa 1, porém com 2 matrizes: uma indica o status que aumentará, identificado de 0 a 5, e em outra o valor do bônus agregado.
As colunas indicam a raça. Cada linha é um atributo diferente que é beneficiado. Ordem das colunas:
     "Sireno",
     "Polar",
     "Gatuno",
     "Harpia"

Final: Impressão de todas as características nessa ordem:
Nome:
Raça:
Classe:
"Vida máxima",
"Mana máxima",
"Classe de Armadura"
 "Força",
"Destreza",
"Vigor",
"Intelecto",
"Sabedoria",
"Carisma"

Caso queira usar o programa para algum projeto, para cada etapa recomendo que:
1:
Defina todos os #define para o seu cenário,
Escreva todas as classes e raças nas matrizes,
Defina todos os valores numéricos, seguindo a mesma sequência para todos (Ex.: Se a coluna 1 tem dados do clérigo,em todas as matrizes, a coluna 1 é do clérigo),

2:
Cheque se a distribuição e checagem está feita corretamente, caso mexa na quantia de pontos máxima
3:
A Checagem da raça é feita por um switch, então adicione um caso numérico para ser validado e, caso as raças dêem bônus em mais atributos, adicione uma linha extra de atribuição de valores extras, dessa forma: statusp[bdr[n][escr - 1]] += vbdr[n][escr - 1]; sendo n uma linha qualquer de bdr[][] e vbdr[][] que você tenha adicionado
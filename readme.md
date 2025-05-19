Esse código é um simples criador de personagem de RPG. ele se baseia em 3 principais etapas:
Escolha de classe, Distribuição de status e Escolha de raça.

Etapa 1: Seleção de classe:
Há uma struct com os dados de todas as classes, guardando de acordo com a ordem da struct, de cima para baixo. Quando você selecionar, reserverá em uma struct chamada Sheet(ficha), que é a ficha do player, e puxa os atributos de vida, mana e CA e copia para a ficha.


Etapa 2: Distribuição de status:
A distribuição de status é feita um por um, sendo For, Dex, Vig, Int, Sab e Car. A pessoa tem uma quantia x de pontos para dsitribuir e é obrigatório por, pelo menos, 1 ponto em cada. Após isso, cadastra na Sheet. Cada atributo tem um limite de quantos pontos pode por, que é definido por um #define. Se sobrarem pontos, a pessoa pode reordenar todos os pontos que colocou.

Etapa 3: Seleção de Raça:
A pessoa pode escolher a raça de seu personagem, e cada um dá um bônus de status em alguns status do player, podendo superar o limite de pontos da etapa 2. Cada raça está cadastrada em um struct, com enums indicando que status são aplicados os buffs.

Final: Impressão da ficha: 
No final, faz as somas de bonus de raça e status para os atributos (Hp, mana e CA)  e imprime a ficha do player, nessa ordem:

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
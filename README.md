O que é FDF? 
 
O projeto FdF, abreviação de "Fil de Fer" (que significa "fio de arame" em francês), 
é um dos projetos da formação da 42, focado em renderização gráfica básica em C. 
O principal objetivo do FdF é desenvolver uma visualização 3D simples de mapas de 
elevação em um plano isométrico, onde a profundidade é representada de forma a dar uma noção de perspectiva.
Isso envolve renderizar dados bidimensionais (representando altitudes) em uma projeção tridimensional. 

Principais Conceitos e Objetivos do FdF: 

Renderização e Projeção Isométrica: 

No FdF, cada ponto do mapa representa uma coordenada em uma grade (um ponto 2D) 
que é transformada em uma perspectiva 3D, criando a ilusão de profundidade. 

A projeção isométrica é usada para dar uma visão tridimensional sem precisar 
implementar uma câmera complexa, facilitando o desenho em 3D. 

Manipulação de Dados de Altitude: 

O projeto começa com a leitura de um arquivo .fdf, que contém uma matriz 
de valores numéricos representando altitudes. 

A partir desses dados, o programa cria uma imagem onde cada ponto na grade 
corresponde a uma elevação específica. Esses valores de elevação são escalados 
para destacar picos e depressões, formando "montanhas" e "vales". 

Transformações Geométricas e Efeitos de Perspectiva: 

A renderização envolve transformações geométricas, como translação, 
rotação e escalonamento, permitindo que o usuário "gire" e "mova" a 
visualização para ver o mapa de diferentes ângulos. 

Essas transformações são calculadas com operações matemáticas, 
geralmente usando trigonometria e multiplicação de matrizes, que são 
fundamentais para transformar a posição dos pontos em 3D. 

Desenvolvimento em C e Controle de Baixo Nível: 

Como o projeto é feito em C, sem uso de bibliotecas gráficas 
avançadas, os estudantes geralmente utilizam a MiniLibX, uma biblioteca 
gráfica simples que permite criar janelas, exibir pixels e capturar eventos do teclado e do mouse. 

Esse controle de baixo nível desenvolve habilidades de 
gerenciamento de memória e otimização de código. 

Interatividade e Controle: 

O projeto também envolve interatividade básica. Os usuários podem 
modificar a perspectiva e o ângulo de visualização usando comandos 
de teclado ou mouse, ajustando o zoom e a rotação do mapa. 

Desafios Técnicos do FdF: 

Implementação de cálculos matemáticos para a projeção isométrica e manipulação dos pontos. 

Otimização para exibir gráficos rapidamente, mesmo em ambientes de baixo nível. 

Controle de eventos para permitir navegação pelo mapa, incluindo zoom, translação e rotação. 

Aprendizados e Benefícios: 

O projeto FdF introduz os alunos aos fundamentos de gráficos computacionais e projeções 3D, 
familiarizando-os com transformações geométricas e manipulação de pixels. É um passo 
importante para quem pretende se aprofundar em gráficos avançados, renderização, ou simulações gráficas.

# devoir

⦁	AHIDAZAN Légia (Legia22)
⦁	DAVO KPINDE Wilfried (wilfried-oss)
⦁	ODOULAMI Christelle (christodou24)

Chargé du cours : Dr Emery ASSOGBA

ANNEE ACADEMIQUE : 2021-2022

Introduction

Le système d’exploitation (OS) définit un ensemble de programmes chargés d’établir une relation entre les différentes ressources matérielles, les applications et 
l’utilisateur. Dans un ordinateur, le système d’exploitation a plusieurs missions. Il gère entre autres le processeur et la mémoire cache, optimise l’exécution des 
applications en leur attribuant les ressources nécessaires, etc. L’OS, dans ses différentes missions, utilise des appels systèmes, qui désignent le moment où un 
programme s'interrompt pour demander au système d'exploitation de lui accomplir une certaine tâche. Nous étudierons alors dans notre projet quelques appels systèmes 
relatifs à la gestion des fichiers par l’OS, à la communication interprocessus et à la gestion de la mémoire par plusieurs processus (processus père et fils).

Question 1 :
	Dans notre programme, pour ouvrir les fichiers, nous avons préféré fopen à open à cause de quelques avantages qu’il offre. En voici quelques-uns :
	1 - fopen fournit une mise en mémoire tampon des E/S qui peut s'avérer beaucoup plus rapide qu’avec open.
	2 – fopen effectue la traduction de fin de ligne si le fichier n'est pas ouvert en mode binaire, ce qui peut être très utile si votre programme est porté sur un environnement non-Unix.
C’est pourquoi nous avons utilisé dans notre programme fclose, fgets, fputs, toutes de la même famille que fopen.
Nous avons constaté qu’en copiant caractère par caractère (fgetc et fputc), notre programme copie plusieurs formats de fichiers (images et vidéos y compris).

Question 2 :
pid_t est un type de données (une structure) en langage C.
	Le type de données pid_t représente l'identification de processus en C. L’identifiant d’un processus en cours qu’il soit père ou fils s’obtient avec la fonction getpid et celui de son père avec getppid.

Question 3 :
Les instructions du père sont exécutables avant celles du fils. Le père envoie le code secret que le fils reçoit avant de s’identifier. Le pipe (tuyau de communication) sert de tunnel entre les deux processus et la réception se fait à partir d’un buffer. A l’écriture (dans le processus père), l’extrémité de lecture (dans le processus fils) est fermée et vice versa.

Question 4 : le MD5 est une fonction de hachage.
La fonction MD5 (pour Message Digest 5) permet d’obtenir l’empreinte numérique d’un fichier. Elle n'est plus considérée comme sûre pour un usage en cryptographie à cause des collisions (deux différents fichiers ayant la même empreinte numérique).

Question 5 : 
En reprenant le programme de la question 1, nous calculons tout simplement le MD5 (en exploitant le programme de la question 4) du fichier original avant le début de la copie et celui du fichier obtenu après copie puis nous comparons. Si les deux fichiers ont le code MD5, alors ils sont identiques et cela signifie que la copie s’est bien passée.

Question 6 : Utilisation des threads.
L’idée ici est de créer 10 threads par exemple. Chacun d’eux aura comme tâche le calcul du MD5 de 100 fichiers (avec une boucle bien sûr). Cette manière de procéder va forcément accélérer le calcul.     


Conclusion
Ce projet fait dans le cours d’initiation à la théorie des systèmes d’exploitation montre l’importance du C à travers les appels systèmes. Ce langage considéré comme 
révolu est toujours d’actualité et sa bonne maîtrise est indispensable.  Ses fonctionnalités telles que le open le fork, le pipe et les threads constituent de 
précieux outils pour le programmeur système (utilisant le langage C).

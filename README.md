## Equipe de projet P-23
Projet réalisé dans le cadre de l'Université de Sherbrooke 

## GIT HELPER

Pour clone le repo
- git clone https://github.com/Poulette007/Mega-Genial.git

Git 101
- git status (voir les fichiers à commit)
- git pull (récupérer les  modifications des autres)
- git add ficherNom (**NE PAS FAIRE** . ou *)
- git commit -m "message"
- git push
- git status (voir que tout est bien commit)

GIT BRANCH (PAS DANS CE PROJET)
- git branch dev (creer une branche appelée dev)
- git checkout dev (changer de branch pour aller sur dev)
- coder tout
- git checkout master (aller sur la branche principale)
- git merge dev (ajouter dev dans master)

## WORKFLOW github
- La branch master est protégée
- Le code se fait sur la branch dev
- Des tests sont réalisés afin de vérifier :
    - Le code ne compile pas
    - Les tests unitaires ne marchent pas
    - Des print() sont présents dans le code

## Librairie a installer 
- libRobus-master  URL => https://github.com/UdeS-GRO/LibRobUS
- Grove_I2C_Color_Sensor_TCS3472-master URL => https://github.com/Seeed-Studio/Grove_I2C_Color_Sensor_TCS3472 

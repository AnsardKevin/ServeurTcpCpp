# ServeurTcpCpp
How to make a Server tcp in c++

Toute les commandes suivantes sons a faire sur un terminal(Linux ou Windows)

Ligne de commande pour compiler le serveur :
g++ TServeur.cpp -o Serveur 

Ligne de commande pour exécuter le serveur :
./Serveur

Ligne de commande pour Build votre image docker :
docker build -t serveurtcp .

Ligne de commande pour éxécuter le Serveur via Docker :  
docker run -d -p 8080:8080 serveurtcp


Tester le serveur sous une distribution Linux (ubuntu, linux, gnome, etc....) :
telnet 127.0.0.1 8080

Tester le serveur sous Windows : 
Test-NetConnection -ComputerName "127.0.0.1" -Port 8080
# ServeurTcpCpp
[![Build Status](https://travis-ci.org/joemccann/dillinger.svg?branch=master)](https://travis-ci.org/joemccann/dillinger)

<h1>How to make a Server tcp in c++</h1>

<p>Ce projet à pour but de vous montrez comment faire un serveur c++ sous docker</p>

<h2>Toute les commandes suivantes sons a faire sur un terminal(Linux ou Windows)</h2>

<p>Ligne de commande pour compiler le serveur :</p>

```sh
g++ Serveur.cpp -o Serveur
```
<p>Ligne de commande pour exécuter le serveur :</p>

```sh
./Serveur
```
<p>Ligne de commande pour Build votre image docker :</p>

```sh
docker build -t serveurtcp .
```

<p>Ligne de commande pour éxécuter le Serveur via Docker :</p>

```sh
docker run -d -p 8080:8080 serveurtcp
```

<p>Tester le serveur sous une distribution Linux (ubuntu, linux, gnome, etc....) :</p>

```sh
telnet 127.0.0.1 8080
```

<p>Tester le serveur sous Windows : </p>

```sh
Test-NetConnection -ComputerName "127.0.0.1" -Port 8080
```
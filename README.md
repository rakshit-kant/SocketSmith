# WARNING

**The Following Project only works in Linux Systems and Not in Windows due to the API differences between Windows and Linux Systems**

# SocketSmith

A kinda minimal and simple HTTP Server made in C for learning about Networking.

## Features

It just is a Simple HTTP Server. It is kinda a TCP based HTTP Server which just gets the Client Request and Shows HTML some HTML Pages (like / and /about)on the Browser Page.

## Uses of the HTTP Server

Tried to make my Own Website Server which Opens my CSS and HTML Files without the VS Code Live Server Extension, I mean I wanted to make something of my own instead of using VS Code Live Server Extension. This Project does not has Live Updating like that Extension but is still great at providing me Value. This is one of my Projects I would use instead of it being rotting in the Corner of my Projects Folder.

## Requirements

- Make
- Clang/GCC (However I think Clang is better...)

## Usage/Running

### By just cloning the Repo and doing it Simply

```bash
git clone https://github.com/rakshit-kant/SocketSmith.git
cd SocketSmith
make run
```

Then Open <http://localhost:8080> in Chrome/Firefox (Microsoft Edge Sucks!)

Note: Also try the 404, and About Pages using <http://localhost:8080/404> and <http://localhost:8080/about>

### By using the Released Executable

```bash
curl -LO https://github.com/rakshit-kant/socketsmith/releases/download/v0.1.0/socketsmith && chmod +x socketsmith && ./socketsmith
```

Then Open <http://localhost:8080> in Chrome/Firefox (Microsoft Edge Sucks!)

Note: Also try the 404, and About Pages using <http://localhost:8080/404> and <http://localhost:8080/about>

## How to use your own CSS and HTML Files

Replace the 404.html, about.html, index.html and style.css with your CSS and HTML Files

Note: The Names of your HTML Files should have the same naming as the 404.html, about.html, index.html and style.css files as this Version (v0.1.0) of SocketSmith does not support different names of HTML/CSS Files.

## LICENSE

MIT

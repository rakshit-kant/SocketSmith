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

Then Open ```http://localhost:8080``` in Chrome/Firefox (Microsoft Edge Sucks!)

## By using the Release Source Code

```bash
curl -L https://github.com/rakshit-kant/SocketSmith/archive/refs/tags/v0.1.0.tar.gz \
| tar -xz \
&& cd SocketSmith-0.1.0 \
&& make run
```

Then Open ```http://localhost:8080``` in Chrome/Firefox (Microsoft Edge Sucks!)

**Note: The Release does not have a Simple Binary because the Server needs an HTML and a CSS File to get Served.**

## LICENSE

MIT

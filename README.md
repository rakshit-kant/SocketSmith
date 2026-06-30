# SocketSmith

A kinda minimal and simple HTTP Server made in C for learning about Networking.

## Features

It just is a Simple HTTP Server. It is kinda a TCP based HTTP Server which just gets the Client Request and Pastes a Custom Text (Hardcoded in the Code) on the Browser Page.

## Requirements

- Make
- Clang/GCC (However I think Clang is better...)

## Usage/Running

```bash
git clone https://github.com/rakshit-kant/SocketSmith.git
cd SocketSmith

clang -o socketsmith src/main.c # If you want to use Clang, My favourite Compiler XD
gcc -o socketsmith src/main.c # If you want to use GCC, The OG Industry Standard
```

Then Open ```http://localhost:8080``` in Chrome/Firefox (Microsoft Edge Sucks!)

## LICENSE

MIT

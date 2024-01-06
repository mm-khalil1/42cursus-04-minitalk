<h1 align="center">Minitalk</h1>

<div align="center">
  <strong>Small communication program between server and client using UNIX signals</strong>
</div>

<br />

## 🚀 Introduction

Minitalk is a lightweight C program that enables communication between a server and client using signals (SIGUSR1 and SIGUSR2). This project demonstrates inter-process communication in a simple yet effective manner.

## 📂 Project Structure

- **Makefile**: Build script for compilation.
- **server.c**: Server implementation for receiving and displaying messages.
- **client.c**: Client implementation for sending messages to the server.
- **minitalk.h**: Header file with includes and function prototypes.
- **libft**: Library with utility functions.

## 🛠️ Build and Run

### Build the project:

```bash
make
```

This compiles the server (server) and client (client) executables.

### Run the server:
```bash
./server
```

### Run the client:
```bash
./client [SERVER_PID] "Your Message Here"
```

Replace [SERVER_PID] with the server's process ID (displayed when starting the server) and "Your Message Here" with the desired message.



minitalk Walkthrough:
https://github.com/mlanca-c/Minitalk/wiki

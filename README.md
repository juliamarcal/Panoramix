# Panoramix

## Description
**PANORAMIX** is a simulation program inspired by the legendary tales of indomitable Gauls resisting Roman invaders. In this program, you will simulate the behavior of villagers and a druid using threads, semaphores, and mutexes, while solving algorithmic challenges related to concurrency.

Find out more information about the project at [Project PDF](./B-CCP-400_panoramix.pdf)

---

## Features
- Multithreaded simulation of villagers and a druid.
- Use of **semaphores** and **mutexes** for synchronization.
- Dynamic handling of shared resources (the magic potion cooking pot).
- Graceful termination of all threads when conditions are met.

---

## Usage
Compile the project using the provided **Makefile**, then execute the program with the following command:

```bash
./panoramix <nb_villagers> <pot_size> <nb_fights> <nb_refills>

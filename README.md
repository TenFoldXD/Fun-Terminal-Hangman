# Classic Hangman, now in your terminal!

## **LINUX/MACOS ONLY UNTIL I DECIDE I WANT WINDOWS FUNCTIONALITY**
little bite sized code I made to get a feel for C and generally not coding with a hand holding instruction set like Coddy. 

Originally, I wanted to use an API to fetch an endpoint for a random word but 1. Networking sucks. 2. It's a lot more code than I can handle. 3. Supply-chain attacks are scary. 4. I'm a novice!

Also, does not support whole words, only letter by letter.

For C people: Yes I know, the character arrays are fixed sized and not dynamically allocated memory with malloc. I'm scared to create a memory leak on my computer :(. I know HOW to do it, but it's just so annnoooyyyiinnnnggggg


```
gcc hangman.c -o hangman
```

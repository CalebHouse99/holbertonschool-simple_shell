# Shell Project

## Made by Douglas Davison and Caleb House

## Introduction

The goal of this project is to create a simple shell from scratch with limited functions available to us.

## Technologies

We created many functions to make our shell work properly. We made our own versions of putchar, puts, and printf to use for this shell. We created the `env` variable which shows us our environment, which contains the PATH. We can then grab the PATH from there, and tokenize it so that we can reference it with the input from the user. We display a prompt for the user to begin typing and we can grab input from there. This input is then checked to see if there are any commands found within the PATH. If this is the case, then it will run that program.

## Examples

We are able to do many things with this shell, inlcuding but not limited to:\
`ls` - Lists the non-hidden files and directories in the current directory.\
` ` - Simply typing space and enter, or just enter, simply moves to the next line and shows the prompt again.\
`/bin/pwd` - Prints the working directory.\
`env` - Prints the current environment.\
`exit` - Exits out of the shell.\

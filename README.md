# pipex – shell pipes in C

This project is all about **reproducing the behavior of a UNIX shell pipeline**.  
It connects multiple processes together so the output of one becomes the input of the next — just like when you run:  

```bash
$ < infile cmd1 | cmd2 > outfile
```
---

## ✨ Features 

Executes two commands with input/output redirection:
```
./pipex infile "ls -l" "wc -l" outfile
```

→ Equivalent to:
```
< infile ls -l | wc -l > outfile
```

- Handles errors gracefully (invalid files, wrong commands, permissions).

- Environment PATH parsing to find and execute commands.

- Works with any valid shell command.

---

##  ✨ Technical Details

This project made me dive deep into:

- Processes with fork()

- File descriptors and redirections with dup2()

- Pipes with pipe()

- Exec family (execve()) for running commands

- Environment variable management (PATH)

---

## ✨  Example Usage
```
$ ./pipex infile "grep 42" "wc -l" outfile
```
```
$ ./pipex infile "grep error" "wc -l" outfile
```
```
$ ./pipex infile "tr ' ' '\n'" "sort | uniq -c" outfile
```

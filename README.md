# Pipez
https://cdn.intra.42.fr/pdf/pdf/47904/fr.subject.pdf

## HOW TO

### COMPILE

```
bash$ git clone git@github.com/Pixailz/Pipez.git && cd Pipez
bash$ make
```

### USE

```
bash$ ./bin/pipex "infile" "cmd1" "cmd2" ... "cmdN" "outfile"
bash$ ./bin/pipex "here_doc" "limiter" "cmd1" "cmd2" ... "cmdN" "outfile"
bash$ ./bin/pipex "here_cmd" "cmd1" "cmd2" ... "cmdN" "outfile"
```

## TODO

1. pimp Makefile :)
2. fix conditional jump whem command not found (free_pipes)
3. fix outfile when here_cmd

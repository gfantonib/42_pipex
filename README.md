# 42_pipex

<p align="center">
  <img src="https://1.bp.blogspot.com/-4R8XL3LCi1A/Xi-_FwlS1vI/AAAAAAAAQdo/RLf7eZCAWO4QOm8oR1Wn99C21nrjnxBuwCLcBGAsYHQ/s1600/images.jpeg" 
  alt="Image Description">
</p>

Conceptually, a pipe is a connection between two processes, such that the standard output from one process becomes the standard input of the other process. In UNIX Operating System, Pipes are useful for communication between related processes (inter-process communication).

This project involves creating a C program that performs a pipe operation similar to how it is done in Bash.

It must behave exactly the same as the shell command below:

``` sh
$ < file1 cmd1 | cmd2 > file2
```

# Some tests
## Mandatory
### normal_1
``` sh
./pipex file1 "ls -l" "wc -l" file2
< file1 ls -l | wc - l > file2
```
### infile dont't exist
``` sh
./pipex no_file "grep a1" "wc -w" file2
< no_file grep a1 | wc -w > file2
```
### outfile don't exist
``` sh
./pipex file1 "grep a1" "wc -w" outfile
< file1 grep a1 | wc -w > outfile
```
### error in first cmd
``` sh
./pipex file1 "grepP a1" "wc -w" file2
< file1 grepP a1 | wc -w > file2
```
### error in second cmd
``` sh
./pipex file1 "grep a1" "wcC -w" file2
< file1 grep a1 | wcC -w > file2
```

## Bonus
### big cmd line
``` sh
./pipex_bonus file1 "cat" "tr , \n" "sort" "uniq" "grep a" "tr a-z A-Z" file2
< file1 cat | tr ',' '\n' | sort | uniq | grep a | tr 'a-z' 'A-Z' > file2
```
### small cmd line
``` sh
./pipex_bonus file1 "ls -l" "wc -l" file2
< file1 | ls -l | wc -l > file2
```
### here_doc small
``` sh
./pipex_bonus here_doc limiter "cat -e" "grep melvin" file2
cat -e << limiter | grep melvin >> file2
```
### here_doc big
``` sh
./pipex_bonus here_doc limiter "cat" "tr , \n" "sort" "uniq" "grep a" "tr a-z A-Z" file2
cat << limiter | tr ',' '\n' | sort | uniq | grep a | tr 'a-z' 'A-Z' >> file2
```
### here_doc big and error in cmd 3
``` sh
./pipex_bonus here_doc limiter "cat" "tr , \n" "sortT" "uniq" "grep a" "tr a-z A-Z" file2
cat << limiter | tr ',' '\n' | sortT | uniq | grep a | tr 'a-z' 'A-Z' >> file2
```

# References
### CodeVault
https://www.youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY

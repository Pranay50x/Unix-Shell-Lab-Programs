# Some Abbrevations creedits: <a href="https://github.com/Schizoid-man/Unix_Lab-CIL37">Schizoid-Man</a>   
```
$ - variable
#- all arguments
$0 - name of the script
$1 - 1st argument
$2 - 2nd argument
$#-all arguments
-eq = equal to
-ne = not equal to
-lt = lesser than
-gt = greater than
> = output to
>> == output and then overwrite
-d = if it is a directory
-e = if it gives an error
| = feeds the output of the statemen that comes before it into the input of the statement after it 
```



# Some other Important things 

## Program 3: 
```bash
1. -e = exists
2. tr = translate, tr -s is used for squeezing the output
3. sort -n sorts numerically
4. grep ofc used for patrern searching
5. ls -Rl R is for recursive l for Long Format
6. tail -1 takes last line of the output
```


## Program 4: 
```bash
1. df is basically disk free tells us system disk usage
2. -h flag for human readable format
3. awk text processing tool 
4. (NR==2) in the script processes only second line of input
5. sed is stream edit 
6. the line ('s/%//') tells the sed to subsitute the % with nothing
7. -size +1G searches for files greater than 1 GB
8. -exec ls -lh {} \;:
For each file that matches the criteria, the `find` command executes `ls -lh {}`.
- `{}` is a placeholder that represents the current file found.
- `ls -lh` lists the file with detailed information in a human-readable format (e.g., file size in a readable unit, permissions, date, etc.).
- The `\;` signifies the end of the `-exec` command.
9. 2>/dev/null suppresses the error messages
10. $? is the exit status of the last command

11. tr -cd -c basically compliments the set of characters and -d deletes them.
12. [:punct:] is a predefined set of characters that are punctuation marks.
```



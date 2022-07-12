# PipeX
This project will let you discover in detail a UNIX mechanism that you already know by using it in your program. Create a program that works exactly like a pipe '|'.

## Mandatory :
+> Your program will be executed as follows:

	./pipex file1 cmd1 cmd2 file2

It must take 4 arguments:
• file1 and file2 are file names.
• cmd1 and cmd2 are shell commands with their parameters.
It must behave exactly the same as the shell command below:

	$> < file1 cmd1 | cmd2 > file2

### Example :

	$> ./pipex infile "ls -l" "wc -l" outfile

Should behave like:

	< infile ls -l | wc -l > outfile

## Bonus :
+> Handle multiple pipes.

	$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2

Should behave like:

	< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2

+> Support « and » when the first parameter is "here_doc".

	$> ./pipex here_doc LIMITER cmd cmd1 file

Should behave like:

	cmd << LIMITER | cmd1 >> file

## How to use :

run :

	make

![making](imgs/Screen%20Shot%202022-07-12%20at%2001.21.36.png)
in terminal to make the mandatory part or :

	make bonus

![making_bonus](imgs/Screen%20Shot%202022-07-12%20at%2001.22.17.png)
to make both mandatory and bonus parts at the same time.

## Clean the object or clean all :
clean only objects :

	make clean

clean all :

	make fclean

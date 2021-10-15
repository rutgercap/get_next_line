# get_next_line

Get_next_line is a simple function written in C. The function takes a file descriptor as input and a double char pointer, then saves the input file in the char pointer until either a newline or EOF is encountered.

## Project goals
The project is part of the [Codam](https://www.codam.nl/studying-at-codam) curriculum.

**Main project**

Main goal was to learn about reading from external files and static variables.

**Bonus**

Added functionality to read from multiple file descriptors without "forgetting" location in the file. So one can read from multiple files and pick up where you left off in the files after each swap.  

## Usage

**Prototype**

```c
int	get_next_line(int fd, char **line)
```


```c
/* prints out full file */
int main(void)
{
	int	fd;
    	int     i = 1;
	char	*line = NULL;

	fd = open("path_to_file", O_RDONLY);
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("line= %s\n", line);
		free(line);
	}
}
```

#### Return values

1: Line is read and saved in char **line

0: EOF is encountered, everything until then is read and saved in char **line
 
-1: Error is encountered whilst reading file

#### Small disclaimer

The entire project is written in accordance with the 42 Network Norm. The norm puts readability above everything and can therefore sometimes be limiting in options for writing the most optimal code.

# Intelligent Nine Men Morris Variant D

Nine Men Morris Variant D is a command line program that produces the best move for a Maximum player(White).

## Installation

Use the make utility manager [make](https://docs.oracle.com/cd/E19957-01/806-3564/Make.html) to compile MinMaxOpening.

```make
make
```

## Usage

[program name] - Program name for opening phase or midgame-endgame phase <br>
[input file] - Name of input file containing a starting board position<br>
[output file] - Name of output file that will contain the results of calculating the best move<br>
[depth limit] - Cut off depth for game tree <br>

```bash
MinMaxOpening board1.txt board2.txt 2
```

## Sample Output

```bash
Input position: xxxxxxxxxxWWxWWxBBBxxxx
Output position: xxxxxxxxWWWxWWxBBBBxxxx
Positions evaluated by static estimation: 125.
MINIMAX estimate: 9987.
```


## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)

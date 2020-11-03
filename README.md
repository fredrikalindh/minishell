# Minishell

A project for 42 recoding a `bash` like shell by [fredrikalindh](https://github.com/fredrikalindh) and [tharchen](https://github.com/Bressack). Testers by us and [solaldunckel](https://github.com/solaldunckel).

## Features

- `cd`
- `pwd`
- `echo`
- `export`
- `unset`
- `env`
- `exit`
- `CTRL-C`
- `CTRL-\`
- `CTRL-D`
- `|` pipes
- `;` semicolons
- `>` `>>` `<` redirections
- `&&` `||` operators
- local variable
- env expansions + `$?`

## Usage

```shell
# Compile the mandatory part
make

# Compile with bonus (termcaps)
make bonus

# Launch the shell
./minishell
```

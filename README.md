## 42-minishell: A mini UNIX command interpreter

The objective of this project is to create the simplest shell.

### Mandatory part functionality:
- The execution of simple command lines, no pipes, no redirections or any other advanced functions;
- the executable are those can be found in the paths indicated in the PATH variable;
- in cases where the executable can not be found, the shell has to show an error message and display the prompt again;
- the errors must be managed without using errno, by displaying a message adapted to the error output;
- the PATH and the environment (copy of system char**environ) must be correctly dealt with;
- a series of builtins must be implemented: echo, cd, setenv, unsetenv, env, exit;

#### Allowed functions for mandatory part:
- malloc, free
- access
- open, close, read, write
- opendir, readdir, closedir
- getcwd, chdir
- stat, lstat, fstat
- fork, execve
- wait, waitpid, wait3, wait4
- signal, kill
- exit

---
### Bonus functionality implemented:
- Management of signals: 'Ctrl-C', 'Ctrl+\\' (the use of global variables is allowed for this bonus);
- the separation of commands with ";";

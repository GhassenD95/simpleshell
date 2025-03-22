Simple Shell
============

A lightweight Unix-like shell implementation written in C that supports basic command execution, built-in commands, and I/O redirection.

Features
--------

*   **Command Execution**: Run external programs and commands
    
*   **Built-in Commands**:
    
    *   cd \[directory\]: Change directory (defaults to HOME if no directory specified)
        
    *   exit: Exit the shell
        
    *   help: Display available commands
        
*   **I/O Redirection**:
    
    *   Input redirection (<): Read input from a file
        
    *   Output redirection (>): Write output to a file (overwrite)
        
    *   Append redirection (>>): Append output to a file
        

How It Works
------------

The shell operates in a simple read-evaluate-print loop:

1.  Display a prompt (>)
    
2.  Read user input
    
3.  Parse the input into tokens
    
4.  Execute the command
    
5.  Repeat
    

Compilation
-----------

Plain textANTLR4BashCC#CSSCoffeeScriptCMakeDartDjangoDockerEJSErlangGitGoGraphQLGroovyHTMLJavaJavaScriptJSONJSXKotlinLaTeXLessLuaMakefileMarkdownMATLABMarkupObjective-CPerlPHPPowerShell.propertiesProtocol BuffersPythonRRubySass (Sass)Sass (Scss)SchemeSQLShellSwiftSVGTSXTypeScriptWebAssemblyYAMLXML`   gcc -o shell csh.c   `

Usage
-----

Plain textANTLR4BashCC#CSSCoffeeScriptCMakeDartDjangoDockerEJSErlangGitGoGraphQLGroovyHTMLJavaJavaScriptJSONJSXKotlinLaTeXLessLuaMakefileMarkdownMATLABMarkupObjective-CPerlPHPPowerShell.propertiesProtocol BuffersPythonRRubySass (Sass)Sass (Scss)SchemeSQLShellSwiftSVGTSXTypeScriptWebAssemblyYAMLXML`   ./csh   `

Example commands:

Plain textANTLR4BashCC#CSSCoffeeScriptCMakeDartDjangoDockerEJSErlangGitGoGraphQLGroovyHTMLJavaJavaScriptJSONJSXKotlinLaTeXLessLuaMakefileMarkdownMATLABMarkupObjective-CPerlPHPPowerShell.propertiesProtocol BuffersPythonRRubySass (Sass)Sass (Scss)SchemeSQLShellSwiftSVGTSXTypeScriptWebAssemblyYAMLXML`   > ls -la  > cd Documents  > cat file.txt > output.txt  > grep "pattern" < input.txt  > echo "append this" >> log.txt  > help  > exit   `

Implementation Details
----------------------

*   Uses standard C libraries for process creation and management
    
*   Implements file descriptor handling for I/O redirection
    
*   Maintains environment variable awareness (e.g., HOME for cd command)
    
*   Maximum input size of 1024 characters
    
*   Supports up to 64 command arguments
    

Limitations
-----------

*   Does not support pipes (|)
    
*   No command history
    
*   No tab completion
    
*   No background process execution (&)
    
*   Limited error handling for complex scenarios
    

Future Improvements
-------------------

*   Add support for pipes and command chaining
    
*   Implement command history
    
*   Add environment variable expansion
    
*   Support for wildcards and pathname expansion
    
*   Implement signal handling for better process management

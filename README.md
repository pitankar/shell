# Description
This is an implmentation of a basic shell that may be used over uart from within the microcontroller. The basic purpose is to be able to controll a shell via micro controller.

# Example
Only implementation of a simple shell skeleton that may be used to add custom commands and execute them is present. Example, on launching `./shell` you shall see a prompt `#`. Type `print` and you shall see the string `This is dummy function` printed.

`# print`

`This is dummy function`

Please see the definition of `cmd_print` and the usage of `table` for more details on how to add commands.
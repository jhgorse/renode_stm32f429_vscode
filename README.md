# renode_stm32f429_vscode
Emulated STM32429 VSCode Environment

# requires
1. arm-none-eabi-gcc, `brew install gcc-arm-embedded`
3. renode, https://github.com/renode/renode/blob/master/README.rst#installation
4. VS Code + Cortex-Debug + Cortex-Debug STMF4 svd files

# quickstart
```
cd /tmp
git clone https://github.com/jhgorse/renode_stm32f429_vscode && cd renode_stm32f429_vscode
make  # or use provided test1.elf file

# launch in console terminal
renode /tmp/renode_stm32f429_vscode/stm32f429_atollic_9.3.0.resc

# gdb terminal
arm-none-eabi-gdb test1.elf

# in gdb
target extended-remote localhost:3333
break main
monitor start
continue
```
VS Code debugging seems less forgiving. And Cortex-Debug plugin is not completely working with the macOS arm-none-eabi-gdb.

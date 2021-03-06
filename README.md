# EagleProtect
Playground for generating virtual machine protected x64 assembly.

## EagleVM
Main protection application that virtualizes code.

## EagleVMSandbox
Project for future testing on full binaries.

## EagleVMStub
This is a DLL which is used in a project that needs to be protected. The EagleVM protector application searches for the usages of the stub imports to hollow the marked code sections and create virtualized code. 

## Resources
- r0da - Inspiring this project with [VMP3 Virtulization](https://whereisr0da.github.io/blog/posts/2021-02-16-vmp-3/) analysis.
- Iizerd - Help with general understanding of code virtualization.
- _xeroxz - Detailed anaylsis of [VMP2](https://back.engineering/17/05/2021/).
- hasherezade - Creating [PE-Bear](https://github.com/hasherezade/pe-bear-releases) for help with understanding, creating, and parsing PE headers.
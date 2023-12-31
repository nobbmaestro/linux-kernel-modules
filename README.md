# Zero to Kernel Modules

A repo for containing Linux Kernel Modules intended for education purposes.

## Commands

Display module info by running following:

```sh
modinfo <module-name>.ko
```

---

Insert a module into the Linux Kernel

```sh
sudo insmod <module-name>.ko
```

---

Remove a module from the Linux Kernel

```sh
sudo rmmod <module-name>
```

---

Show the status of modules in the Linux Kernel

```sh
sudo lsmod | grep <modulo-name>
```

---

Display log generated by the module:

```sh
sudo journalctl | grep kernel
```

## Table of Content

## Sources

-   [The Linux Kernel Module Programming Guide](https://sysprog21.github.io/lkmpg/)

### Project-Phaeton
Package manager/frontend for the Heirloom SVR4 packaging tools.
This project was inspired by FreeBSD, Slackware, and CRUX.

#### Usage
##### 1) Get the ports tree 

`ports fetch`

* Downloads `ports.tar.gz` and extracts it to `/usr/ports`
* The file hierarchy is the same as on FreeBSD: `/usr/ports/category/port/`
* Each port resides in a category (i.e. x11, games, audio)
* Each port has a `mkport` which is similiar to Slackware's SlackBuilds

##### 2) Building a port

`cd /usr/ports/x11/xorg`

`./mkport`

* This will create an `xorg-$VERSION.pkg` in `/var/spool/pkg`
* You can also use `pkgbuild category/port`

`pkgbuild x11/xorg`

##### 3) Installing a port or package
* Install the created package. If the package doesn't exist, it will download it from the repo

`pkg install xorg`

##### Bugs
* `pkg install <prog>` (pkgadd) sometimes fails (can't find pkgmk) but works the third time
* BASEDIR set to certain directories will cause a package to fail to uninstall

##### TODO:
* make `mkport` files for more programs and create a repo
* create a ports.tar.gz with all programs and their `mkport` files
* implement `search`, `verify`, etc commands
* Dependency checking 
* Creating packages which install to multiple directories
* Clean up `tstpkg.c` -> might not be necessary - just use `pkg` instead
* Fork CRUX Linux and use pkg as the package manager

   

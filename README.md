### Project-Phaeton
Package manager/frontend for the Heirloom SVR4 packaging tools.
This project was inspired by FreeBSD, Slackware, and CRUX.

#### Usage
##### 1) Get the ports tree 

`ports fetch`

* Downloads `ports.tar.gz` and extracts it to `/usr/ports`
* The file hierarchy is the same as on FreeBSD: `/usr/ports/category/port/`
* Each port has a `mkport` which is similiar to Slackware's SlackBuilds or CRUX's Pkgfiles

##### 2) Building a port

`cd /usr/ports/x11/dmenu`

`./mkport`

* This will create an `dmenu-$VERSION.pkg` in `/var/spool/pkg`
* You can also use `pkgbuild category/port`

`pkgbuild x11/dmenu`

##### 3) Installing a port or package
* Install the created package. If the package doesn't exist, it will download from the repo

`pkg install dmenu`

##### TODO:
* make `mkport` files for more programs and create a repo
* create `ports.tar.gz` with all programs and their `mkport` files
* implement `search`, `build`, `update`, `sync` commands
* Dependency checking - use SVR4 `depend` file or define dependencies in `mkport` files
* Try using `pkg` as the package manager, and the `heirloom tools` as core binutils

   

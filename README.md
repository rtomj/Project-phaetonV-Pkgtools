### Project-Phaeton
Package manager/frontend for the Heirloom SVR4 packaging tools.
This project was inspired by FreeBSD, Slackware, and CRUX.

#### Usage
##### 1) Get the ports tree 

`ports fetch`

* Downloads `ports.tar.gz` and extracts it to `/usr/ports/`
* The file hierarchy is the same as on FreeBSD: `/usr/ports/category/port/`
* Each port has a `mkport` which is similiar to Slackware's SlackBuilds or CRUX's Pkgfiles

##### 2) Building a port

`cd /usr/ports/x11/dmenu`

`./mkport`

* This will create a `dmenu-$VERSION.pkg` in `/var/spool/pkg`
* You can also use `pkgbuild category/port`

`pkgbuild x11/dmenu`

##### 3) Installing a port or package
* Install the created package. 

`pkg install dmenu`

##### TODO:
* make `mkport` files for more programs and create a repo
* make `ports` download `ports.tar.gz` and extract to `/usr/ports`
* implement `search`, `build`, `update`, `sync`, etc commands
* Dependency checking - use SVR4 `depend` file or define dependencies in `mkport` files

   

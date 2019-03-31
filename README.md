### SVR4pkgtools
Package manager/frontend for the Heirloom SVR4 packaging tools.
This project was tested on CRUX 3.4 with all core, opt, and xorg ports installed.

#### Installation
* Install the [Heirloom Tools](http://heirloom.sourceforge.net/) and add to `$PATH`
* Make sure heirloom sh is installed to `/sbin/sh`
* Create the pkg directory: `mkdir -p /var/spool/pkg`
* Edit `/var/sadm/install/admin/default` and change `instance` to `instance=overwrite`
* Use `bin/pkg` or `heirloom-pkg` as a bootstrap to install `base/pkgtools`

##### Usage
##### 1) Get the ports tree 

`pkg fetch-ports`

* Downloads `ports.tar.gz` and extracts it to `/usr/ports/` [TODO]
* The file hierarchy is the same as on FreeBSD: `/usr/ports/category/port/`
* Each port has a `mkport` which is similiar to CRUX's Pkgfiles

##### 2) Creating a `mkport`
* See the sample-mkports in `bin` and `heirloom-bin`

##### 3) Building a port
* Use `makepkg` or `heirloom-makepkg`

`cd /usr/ports/category/port`

`makepkg port.mkport`

* This will create an `SVR4port-$VERSION-$ARCH.pkg` in `/var/spool/pkg`
* You can also use `pkgbuild` or `heirloom-pkgbuild` from any directory. 

`pkgbuild category/port`

##### 3) Installing a port or package
* Install the created package with `pkg`, `heirloom-pkg`, or `pkgadd -d /path/to/SVR4port-version-arch.pkg` 

`pkg -i/install [port]`

##### 4) Updating a port or package
`pkg sync`

* Downloads the latest ChangeLog.txt [TODO]

`pkg update [port]`

##### TODO:
* Write an `heirloom-makepkg` [DONE]
* Fix checksum bug in `makepkg`
* Instead of a `mkport`, use `port.mkport` 
* Write a mkport generator
* Create a SQLite `/var/db/pkg/ports.sqlite` database for ports like FreeBSD? 
* some things could probably be written better
* make `pkg fetch-ports` download `ports.tar.gz` and extract to `/usr/ports`
* implement `search`, `sync`, etc commands
* Make an `update all` command

### Project-phaetonV
Package manager/frontend for the Heirloom SVR4 packaging tools.
This project was tested on CRUX 3.4 with all core, opt, and xorg ports installed.

#### Installation
* Install the [Heirloom Tools](http://heirloom.sourceforge.net/) and add to `$PATH`
* Make sure heirloom sh is installed to /sbin/sh
* Create the pkg directory: `mkdir -p /var/spool/pkg`
* Edit `/var/sadm/install/admin/default` and change `instance` to `instance=overwrite`
* Use `bin/pkg` or `heirloom-pkg` as a bootstrap to install `base/pkgtools`

##### Usage
##### 1) Get the ports tree 

`ports fetch`

* Downloads `ports.tar.gz` and extracts it to `/usr/ports/` [TODO]
* The file hierarchy is the same as on FreeBSD: `/usr/ports/category/port/`
* Each port has a `mkport` which is similiar to Slackware's SlackBuilds or CRUX's Pkgfiles

##### 2) Creating a `mkport`
* See the sample-mkports in `bin` and `heirloom-bin`

##### 3) Building a port

`cd /usr/ports/category/port`

`./mkport`

* This will create a `port-$VERSION.pkg` in `/var/spool/pkg`
* You can also use `pkgbuild` or `heirloom-pkgbuild`. 

`pkgbuild category/port`

##### 3) Installing a port or package
* Install the created package with `pkg` or `heirloom-pkg` 

`pkg install dmenu`

##### 4) Updating a port or package
`pkg sync`

* Downloads the latest ChangeLog.txt [TODO]

`pkg update dmenu`


##### TODO:
* Create a SQLite `/var/db/pkg/ports.sqlite` database for ports like FreeBSD? 
* some things could probably be written better
* make `mkport` files for more programs and  create a repo
* make `ports` download `ports.tar.gz` and extract to `/usr/ports`
* implement `search`, `sync`, etc commands
* Make an `update all` command


   

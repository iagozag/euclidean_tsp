# euclidean_tsp

To install lemon:

1. Step into the root of the source directory.

        $ cd lemon-1.3.1

 2. Create a build subdirectory and step into it.

        $ mkdir build
        $ cd build

 3. Perform system checks and create the makefiles.

        $ cmake ..

    By default, LEMON will be installed under /usr/local (you will need root
    privileges to be able to do that). If you want to install it to
    some other location, then pass the
    -DCMAKE_INSTALL_PREFIX=DIRECTORY flag to cmake.
    
    For example:

        $ cmake -DCMAKE_INSTALL_PREFIX=/home/username/lemon'

 5. Build LEMON.

        $ make

6. Install LEMON

    If you are installing under /usr/local:

        $ sudo make install

    Else:

       $ make install


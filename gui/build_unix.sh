#
# File:  build_unix.sh
#
# Group: Isabela Apolinário
#        Raquel Azeredo
#        Filipe Barretto
#        David Britto
#        Marcelle Campos
#        Luiz Ciafrino
#        Pedro Fonini
#        Eduardo Frimer
#        Pedro Machado
#

# Instructions on how to use this script are located in the README file.

# if `qmake' won't work, we don't even try `make'
qmake-qt4 && make

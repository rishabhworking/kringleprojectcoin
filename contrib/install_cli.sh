 #!/usr/bin/env bash

 # Execute this file to install the kringleprojectcoin cli tools into your path on OS X

 CURRENT_LOC="$( cd "$(dirname "$0")" ; pwd -P )"
 LOCATION=${CURRENT_LOC%KringleProjectCoin-Qt.app*}

 # Ensure that the directory to symlink to exists
 sudo mkdir -p /usr/local/bin

 # Create symlinks to the cli tools
 sudo ln -s ${LOCATION}/KringleProjectCoin-Qt.app/Contents/MacOS/kringleprojectcoind /usr/local/bin/kringleprojectcoind
 sudo ln -s ${LOCATION}/KringleProjectCoin-Qt.app/Contents/MacOS/kringleprojectcoin-cli /usr/local/bin/kringleprojectcoin-cli
